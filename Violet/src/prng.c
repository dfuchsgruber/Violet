/**
 * Xorshift pseudo randon number generator
 */

#include "types.h"
#include "prng.h"
#include "math.h"
#include "agbmemory.h"
#include "debug.h"
#include "save.h"
#include "debug.h"

void rnd_init(){
    u16 timer = *(u16*)0x04000104;
    if(!timer) timer++; //Just any not zero number
    u16 *timer_cntl = (u16*)0x04000106;
    *timer_cntl = 0; //Disable timer
    rnd_main_set_seed(timer);
    u16 *malloc_magic = (u16*)0x02020000;
    *malloc_magic = timer;
}

u16 rnd16(){
    return (u16)_prng_xorshift(&_main_rnd);
}

FIXED rnd_normal() {
    return _prng_stdnormal(&_main_rnd);
}

u16 gp_rnd16() {
    return (u16)(_prng_xorshift(&fmem.gp_rng));
}

void gp_rng_seed(u32 seed) {
    fmem.gp_rng = seed;
}

FIXED gp_rnd_normal() {
    return _prng_stdnormal(&fmem.gp_rng);
}

void rnd_main_set_seed(u32 seed){
    _main_rnd = seed;
}

u32 _prng_xorshift(u32 *_seed){
    //Period of 2^32 - 1
    u32 seed = *_seed;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    *_seed = seed;
    return seed;
}

FIXED _prng_stdnormal(u32 *_seed) {
  // Sample U uniformly in [0;1]
  FIXED u = (u16)_prng_xorshift(_seed);
  // Phi^-1(U) is distributed ~ N(0, 1)
  return FIXED_PROBIT_INV(u);
}

size_t choice(u32 *p, size_t p_size, u16 (*rng)()) {
    if (rng == NULL) rng = rnd16;
    u32 sum = 0;
    for (size_t i = 0; i < p_size; i++) sum += p[i];
    u32 r = (u32)((u32)(rng() | (rng() << 16)) % sum);
    for (size_t i = 0; i < p_size; i++)
        // dprintf("Choice %d has value %x\n", i, p[i]);
    // dprintf("R value drawn: %x (upper bound = %x)\n", r, sum);
    for (size_t i = 0; i < p_size; i++) {
        if (p[i] > r) return i;
        r -= p[i];
    }
    return p_size - 1; // Should not happen...
}

// Values of exp(alpha * x) for x in range[0, 1024] and alpha a temperature parameter: (20 * 1024)
static u32 exp_lut[1025] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 15, 15, 15, 16, 16, 16, 16, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 21, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 31, 31, 32, 32, 33, 34, 34, 35, 36, 37, 37, 38, 39, 40, 40, 41, 42, 43, 44, 45, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 60, 61, 62, 64, 65, 66, 67, 69, 70, 72, 73, 74, 76, 77, 79, 81, 82, 84, 85, 87, 89, 91, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 115, 117, 119, 122, 124, 126, 129, 132, 134, 137, 139, 142, 145, 148, 151, 154, 157, 160, 163, 166, 170, 173, 176, 180, 183, 187, 191, 195, 198, 202, 206, 210, 215, 219, 223, 228, 232, 237, 241, 246, 251, 256, 261, 266, 271, 277, 282, 288, 294, 299, 305, 311, 317, 324, 330, 337, 343, 350, 357, 364, 371, 378, 386, 394, 401, 409, 417, 426, 434, 443, 451, 460, 469, 479, 488, 498, 507, 518, 528, 538, 549, 560, 571, 582, 593, 605, 617, 629, 642, 654, 667, 680, 694, 708, 722, 736, 750, 765, 780, 796, 811, 827, 844, 860, 877, 895, 912, 930, 949, 967, 986, 1006, 1026, 1046, 1067, 1088, 1109, 1131, 1153, 1176, 1199, 1223, 1247, 1272, 1297, 1322, 1348, 1375, 1402, 1430, 1458, 1487, 1516, 1546, 1577, 1608, 1639, 1672, 1705, 1738, 1773, 1808, 1843, 1880, 1917, 1954, 1993, 2032, 2072, 2113, 2155, 2198, 2241, 2285, 2330, 2376, 2423, 2471, 2520, 2569, 2620, 2672, 2724, 2778, 2833, 2889, 2946, 3004, 3063, 3124, 3185, 3248, 3312, 3377, 3444, 3512, 3581, 3652, 3724, 3797, 3872, 3949, 4027, 4106, 4187, 4270, 4354, 4440, 4527, 4616, 4708, 4800, 4895, 4992, 5090, 5191, 5293, 5397, 5504, 5612, 5723, 5836, 5951, 6068, 6188, 6310, 6435, 6562, 6691, 6823, 6958, 7095, 7235, 7377, 7523, 7671, 7823, 7977, 8134, 8295, 8458, 8625, 8795, 8969, 9146, 9326, 9510, 9698, 9889, 10084, 10283, 10486, 10692, 10903, 11118, 11338, 11561, 11789, 12022, 12259, 12501, 12747, 12999, 13255, 13517, 13783, 14055, 14332, 14615, 14903, 15197, 15497, 15803, 16114, 16432, 16756, 17087, 17424, 17768, 18118, 18475, 18840, 19211, 19590, 19977, 20371, 20772, 21182, 21600, 22026, 22460, 22903, 23355, 23816, 24286, 24765, 25253, 25751, 26259, 26777, 27305, 27844, 28393, 28953, 29524, 30106, 30700, 31305, 31923, 32553, 33195, 33849, 34517, 35198, 35892, 36600, 37322, 38058, 38808, 39574, 40354, 41150, 41962, 42790, 43634, 44494, 45372, 46267, 47179, 48110, 49059, 50026, 51013, 52019, 53045, 54091, 55158, 56246, 57355, 58487, 59640, 60817, 62016, 63239, 64486, 65758, 67055, 68378, 69727, 71102, 72504, 73934, 75392, 76879, 78396, 79942, 81519, 83127, 84766, 86438, 88143, 89881, 91654, 93462, 95305, 97185, 99102, 101056, 103049, 105082, 107154, 109268, 111423, 113621, 115862, 118147, 120477, 122853, 125276, 127747, 130267, 132836, 135456, 138128, 140852, 143630, 146463, 149352, 152297, 155301, 158364, 161488, 164673, 167921, 171233, 174610, 178054, 181566, 185147, 188798, 192522, 196319, 200191, 204140, 208166, 212272, 216458, 220728, 225081, 229521, 234047, 238664, 243371, 248171, 253066, 258057, 263147, 268337, 273629, 279026, 284529, 290141, 295864, 301699, 307650, 313718, 319905, 326215, 332649, 339210, 345900, 352722, 359679, 366773, 374007, 381384, 388906, 396576, 404398, 412374, 420507, 428801, 437259, 445883, 454677, 463645, 472789, 482114, 491623, 501320, 511207, 521290, 531571, 542056, 552747, 563649, 574766, 586102, 597662, 609450, 621470, 633727, 646227, 658972, 671969, 685223, 698738, 712519, 726572, 740903, 755516, 770417, 785612, 801107, 816907, 833019, 849449, 866203, 883287, 900708, 918473, 936589, 955061, 973898, 993107, 1012694, 1032667, 1053035, 1073804, 1094983, 1116580, 1138602, 1161059, 1183959, 1207311, 1231123, 1255404, 1280165, 1305414, 1331161, 1357416, 1384189, 1411489, 1439328, 1467717, 1496665, 1526184, 1556285, 1586980, 1618280, 1650198, 1682745, 1715935, 1749778, 1784290, 1819482, 1855368, 1891962, 1929277, 1967329, 2006131, 2045698, 2086046, 2127190, 2169145, 2211927, 2255554, 2300040, 2345405, 2391664, 2438835, 2486937, 2535987, 2586005, 2637009, 2689020, 2742056, 2796138, 2851287, 2907524, 2964870, 3023346, 3082977, 3143783, 3205788, 3269017, 3333492, 3399240, 3466284, 3534650, 3604365, 3675455, 3747946, 3821868, 3897248, 3974114, 4052496, 4132425, 4213929, 4297042, 4381793, 4468216, 4556344, 4646210, 4737848, 4831294, 4926583, 5023751, 5122836, 5223874, 5326906, 5431970, 5539106, 5648355, 5759759, 5873360, 5989202, 6107328, 6227784, 6350616, 6475871, 6603596, 6733840, 6866653, 7002086, 7140190, 7281018, 7424623, 7571060, 7720386, 7872657, 8027931, 8186268, 8347728, 8512372, 8680263, 8851466, 9026046, 9204069, 9385603, 9570717, 9759483, 9951971, 10148256, 10348413, 10552517, 10760647, 10972881, 11189302, 11409991, 11635033, 11864514, 12098520, 12337142, 12580471, 12828598, 13081620, 13339631, 13602732, 13871022, 14144603, 14423581, 14708060, 14998151, 15293963, 15595609, 15903205, 16216868, 16536717, 16862874, 17195465, 17534615, 17880454, 18233114, 18592730, 18959439, 19333381, 19714697, 20103535, 20500042, 20904369, 21316670, 21737104, 22165830, 22603012, 23048816, 23503414, 23966977, 24439683, 24921713, 25413250, 25914481, 26425598, 26946797, 27478274, 28020235, 28572885, 29136434, 29711099, 30297098, 30894655, 31503997, 32125358, 32758974, 33405086, 34063943, 34735794, 35420896, 36119511, 36831904, 37558348, 38299120, 39054503, 39824784, 40610257, 41411223, 42227986, 43060859, 43910158, 44776208, 45659340, 46559890, 47478201, 48414625, 49369518, 50343244, 51336176, 52348691, 53381176, 54434026, 55507641, 56602431, 57718814, 58857215, 60018070, 61201820, 62408918, 63639824, 64895007, 66174946, 67480130, 68811056, 70168233, 71552177, 72963417, 74402492, 75869950, 77366350, 78892265, 80448275, 82034975, 83652970, 85302877, 86985326, 88700958, 90450427, 92234402, 94053563, 95908603, 97800231, 99729168, 101696149, 103701926, 105747263, 107832941, 109959755, 112128517, 114340054, 116595209, 118894844, 121239835, 123631076, 126069481, 128555978, 131091518, 133677066, 136313610, 139002155, 141743727, 144539372, 147390155, 150297166, 153261512, 156284324, 159366756, 162509984, 165715206, 168983646, 172316549, 175715189, 179180860, 182714886, 186318614, 189993420, 193740704, 197561897, 201458457, 205431869, 209483649, 213615344, 217828529, 222124812, 226505831, 230973259, 235528798, 240174187, 244911199, 249741639, 254667352, 259690215, 264812146, 270035097, 275361062, 280792073, 286330200, 291977557, 297736298, 303608621, 309596764, 315703013, 321929697, 328279192, 334753919, 341356348, 348088999, 354954439, 361955288, 369094216, 376373948, 383797259, 391366981, 399086003, 406957269, 414983782, 423168604, 431514857, 440025725, 448704455, 457554357, 466578808, 475781251, 485165195};

size_t softmax_choice(int *logits, size_t size, int min, int max, u16 (*rng)()) {
    if (min < -512) derrf("Softmax2_Choice: Only works for minima >= -256, is %d\n", min);
    if (max > 512) derrf("Softmax2_Choice: Only works for minima >= -256, is %d\n", min);
    if (rng == NULL) rng = rnd16;
    u32 *p = malloc((size_t)(sizeof(u32) * (size_t)size));
    for (size_t i = 0; i < size; i++) {
        if (logits[i] < min) derrf("Softmax2_Choice: Logit @%d has a value %d (lower than declared minimum %d)\n", i, logits[i], min);
        if (logits[i] > max) derrf("Softmax2_Choice: Logit @%d has a value %d (larger than declared maximum %d)\n", i, logits[i], max);
        // First transform x into a range [0, 20] (the LUT is computed for these values)
        int x = logits[i] - min;
        x *= 1024;
        x /= max - min;
        p[i] = exp_lut[x];
    }
    size_t idx = choice(p, size, rng);
    free(p);
    return idx;
}

void shuffle(size_t *array, size_t size, u16 (*rng)()) {
    if (rng == NULL) rng = rnd16;
    for (size_t i = size - 1; i > 0; i--) {
        size_t j = rng() % (i + 1);
        size_t tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}