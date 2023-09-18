#include "types.h"
#include "trainerschool_test.h"
#include "language.h"

const u8 str_trainerschool_test_question_0[] = LANGDEP(
    PSTRING("Welches ist das\nGrößte aller\nPokémon?"),
    PSTRING("Which is the\nbiggest of all\nPokémon?"));
const u8 str_trainerschool_test_question_0_answer_0[] = LANGDEP(
    PSTRING("Groudon"), PSTRING("Groudon"));
const u8 str_trainerschool_test_question_0_answer_1[] = LANGDEP(
    PSTRING("Stahlos"), PSTRING("Steelix"));
const u8 str_trainerschool_test_question_0_answer_2[] = LANGDEP(
    PSTRING("Wailord"), PSTRING("Wailord"));
const u8 str_trainerschool_test_question_0_answer_3[] = LANGDEP(
    PSTRING("Garados"), PSTRING("Gyrados")
    );

const u8 *const str_trainerschool_test_question_0_answers[] = {
    str_trainerschool_test_question_0_answer_0,
    str_trainerschool_test_question_0_answer_1,
    str_trainerschool_test_question_0_answer_2,
    str_trainerschool_test_question_0_answer_3
};

const u8 str_trainerschool_test_question_1[] = LANGDEP(
    PSTRING("Wie viele AP\nverliert das Ziel\ndurch die Attacke\nGroll?"),
    PSTRING("How many PP\nwill be lost\nwhen hit by\nSpite?"));
const u8 str_trainerschool_test_question_1_answer_0[] = LANGDEP(
    PSTRING("Vier"), PSTRING("Four"));
const u8 str_trainerschool_test_question_1_answer_1[] = LANGDEP(
    PSTRING("Hälfte"), PSTRING("Half")
    );
const u8 str_trainerschool_test_question_1_answer_2[] = LANGDEP(
    PSTRING("Alle"), PSTRING("All"));
const u8 str_trainerschool_test_question_1_answer_3[] = LANGDEP(
    PSTRING("Fünf"), PSTRING("Five"));

const u8 *const str_trainerschool_test_question_1_answers[] = {
    str_trainerschool_test_question_1_answer_0,
    str_trainerschool_test_question_1_answer_1,
    str_trainerschool_test_question_1_answer_2,
    str_trainerschool_test_question_1_answer_3
};

const u8 str_trainerschool_test_question_2[] = LANGDEP(
    PSTRING("Welcher Angriff\nwird von Relaxo\nerlernt?"),
    PSTRING("Which of these\nattacks does\nSnorlax learn?"));
const u8 str_trainerschool_test_question_2_answer_0[] = LANGDEP(
    PSTRING("Brüller"), PSTRING("Roar"));
const u8 str_trainerschool_test_question_2_answer_1[] = LANGDEP(
    PSTRING("Slam"), PSTRING("Slam"));
const u8 str_trainerschool_test_question_2_answer_2[] = LANGDEP(
    PSTRING("Bezirzer"), PSTRING("Covet"));

const u8 *const str_trainerschool_test_question_2_answers[] = {
    str_trainerschool_test_question_2_answer_0,
    str_trainerschool_test_question_2_answer_1,
    str_trainerschool_test_question_2_answer_2
};

const u8 str_trainerschool_test_question_3[] = LANGDEP(
    PSTRING("Welches dieser\nItems hat den\nhöchsten Wert?"),
    PSTRING("Which of these\nitems is the\nmost valuable?"));
const u8 str_trainerschool_test_question_3_answer_0[] = LANGDEP(
    PSTRING("Maronbeere"), PSTRING("Chesto Berry"));
const u8 str_trainerschool_test_question_3_answer_1[] = LANGDEP(
    PSTRING("Abysszahn"), PSTRING("Deep Sea Tooth"));
const u8 str_trainerschool_test_question_3_answer_2[] = LANGDEP(
    PSTRING("Sanftglocke"), PSTRING("Sooth Bell"));
const u8 str_trainerschool_test_question_3_answer_3[] = LANGDEP(
    PSTRING("Laxrauch"), PSTRING("Lax Incense"));
const u8 str_trainerschool_test_question_3_answer_4[] = LANGDEP(
    PSTRING("Donnerstein"), PSTRING("Thunder Stone"));

const u8 *const str_trainerschool_test_question_3_answers[] = {
    str_trainerschool_test_question_3_answer_0,
    str_trainerschool_test_question_3_answer_1,
    str_trainerschool_test_question_3_answer_2,
    str_trainerschool_test_question_3_answer_3,
    str_trainerschool_test_question_3_answer_4
};


const u8 str_trainerschool_test_question_4[] = LANGDEP(
    PSTRING("Welches dieser\nPokémon besitzt\nden höchsten\nBasis-Angriff?"),
    PSTRING("Which of these\nPokémon has the\nhighest Base-\nAttack?")
);
const u8 str_trainerschool_test_question_4_answer_0[] = LANGDEP(
    PSTRING("Flamara"), PSTRING("Flareon"));
const u8 str_trainerschool_test_question_4_answer_1[] = LANGDEP(
    PSTRING("Glaziola"), PSTRING("Glazeon"));
const u8 str_trainerschool_test_question_4_answer_2[] = LANGDEP(
    PSTRING("Nachtara"), PSTRING("Umbreon"));
const u8 str_trainerschool_test_question_4_answer_3[] = LANGDEP(
    PSTRING("Aquana"), PSTRING("Vaporeon"));

const u8 *const str_trainerschool_test_question_4_answers[] = {
    str_trainerschool_test_question_4_answer_0,
    str_trainerschool_test_question_4_answer_1,
    str_trainerschool_test_question_4_answer_2,
    str_trainerschool_test_question_4_answer_3
};

const u8 str_trainerschool_test_question_5[] = LANGDEP(
    PSTRING("Wie viele\nStunden benötigt\nDragoran zur\nWeltumrundung?"),
    PSTRING("How many\nhours does it\ntake Dargonite\nto circle the world?")
    );
const u8 str_trainerschool_test_question_5_answer_0[] = LANGDEP(
    PSTRING("Sechzehn"), PSTRING("Sixteen"));
const u8 str_trainerschool_test_question_5_answer_1[] = LANGDEP(
    PSTRING("Achtzehn"), PSTRING("Eighteen"));
const u8 str_trainerschool_test_question_5_answer_2[] = LANGDEP(
    PSTRING("Fünfzehn"), PSTRING("Fifteen"));
const u8 str_trainerschool_test_question_5_answer_3[] = LANGDEP(
    PSTRING("Zwanzig"), PSTRING("Twenty"));
const u8 str_trainerschool_test_question_5_answer_4[] = LANGDEP(
    PSTRING("Einundzwanzig"), PSTRING("Twenty-one"));

const u8 *const str_trainerschool_test_question_5_answers[] = {
    str_trainerschool_test_question_5_answer_0,
    str_trainerschool_test_question_5_answer_1,
    str_trainerschool_test_question_5_answer_2,
    str_trainerschool_test_question_5_answer_3,
    str_trainerschool_test_question_5_answer_4
};

const u8 str_trainerschool_test_question_6[] = LANGDEP(
    PSTRING("Was ist Fauns\nLieblingsfarbe?"),
    PSTRING("Name Faun's\nfavourite color!"));
const u8 str_trainerschool_test_question_6_answer_0[] = LANGDEP(
    PSTRING("Pink"), PSTRING("Pink"));
const u8 str_trainerschool_test_question_6_answer_1[] = LANGDEP(
    PSTRING("Braun"), PSTRING("Brown"));
const u8 str_trainerschool_test_question_6_answer_2[] = LANGDEP(
    PSTRING("Zitrusgelb"), PSTRING("Citrus Yellow"));

const u8 *const str_trainerschool_test_question_6_answers[] = {
    str_trainerschool_test_question_6_answer_0,
    str_trainerschool_test_question_6_answer_1,
    str_trainerschool_test_question_6_answer_2,
};

const u8 str_trainerschool_test_question_7[] = LANGDEP(
    PSTRING("Welcher dieser\nAngriffe\nverursacht den\nmeisten Schaden?"),
    PSTRING("Which of these\nattacks causes\nthe most\ndamage?"));
const u8 str_trainerschool_test_question_7_answer_0[] = LANGDEP(
    PSTRING("Giftzahn"), PSTRING("Poison Fang"));
const u8 str_trainerschool_test_question_7_answer_1[] = LANGDEP(
    PSTRING("Antik-Kraft"), PSTRING("Ancient Power"));
const u8 str_trainerschool_test_question_7_answer_2[] = LANGDEP(
    PSTRING("Aurorastrahl"), PSTRING("Aurora Beam"));
const u8 str_trainerschool_test_question_7_answer_3[] = LANGDEP(
    PSTRING("Ampelleuchte"), PSTRING("Signal Beam"));

const u8 *const str_trainerschool_test_question_7_answers[] = {
    str_trainerschool_test_question_7_answer_0,
    str_trainerschool_test_question_7_answer_1,
    str_trainerschool_test_question_7_answer_2,
    str_trainerschool_test_question_7_answer_3,
};

const u8 str_trainerschool_test_question_8[] = LANGDEP(
    PSTRING("Welches dieser\nPokémon benötigt\nam längsten\nzum Schlüpfen?"),
    PSTRING("Which of these\nPokémon takes\nthe longsest\nto hatch?"));
const u8 str_trainerschool_test_question_8_answer_0[] = LANGDEP(
    PSTRING("Shuppet"), PSTRING("Shuppet"));
const u8 str_trainerschool_test_question_8_answer_1[] = LANGDEP(
    PSTRING("Wailmer"), PSTRING("Wailmer"));
const u8 str_trainerschool_test_question_8_answer_2[] = LANGDEP(
    PSTRING("Kabuto"), PSTRING("Kabuto"));
const u8 str_trainerschool_test_question_8_answer_3[] = LANGDEP(
    PSTRING("Seeper"), PSTRING("Horsea"));

const u8 *const str_trainerschool_test_question_8_answers[] = {
    str_trainerschool_test_question_8_answer_0,
    str_trainerschool_test_question_8_answer_1,
    str_trainerschool_test_question_8_answer_2,
    str_trainerschool_test_question_8_answer_3,
};

const u8 str_trainerschool_test_question_9[] = LANGDEP(
    PSTRING("Welche dieser\nPaare besitzen\ndas gleiche\nGewicht?"),
    PSTRING("Which of these\npairs share\nthe same\nweight?"));
const u8 str_trainerschool_test_question_9_answer_0[] = LANGDEP(
    PSTRING("Larvitar, Bronzel"), ("Larvitar", "Bronzor"));
const u8 str_trainerschool_test_question_9_answer_1[] = LANGDEP(
    PSTRING("Vipitis, Perlu"), PSTRING("Seviper, Clamperl"));
const u8 str_trainerschool_test_question_9_answer_2[] = LANGDEP(
    PSTRING("Pudox, Reptain"), PSTRING("Dustox,Grovyle"));
const u8 str_trainerschool_test_question_9_answer_3[] = LANGDEP(
    PSTRING("Voltenso, Kadabra"), PSTRING("Manectric, Kadabra"));

const u8 *const str_trainerschool_test_question_9_answers[] = {
    str_trainerschool_test_question_9_answer_0,
    str_trainerschool_test_question_9_answer_1,
    str_trainerschool_test_question_9_answer_2,
    str_trainerschool_test_question_9_answer_3,
};

const trainerschool_test_question trainerschool_test_questions [] = {
    {
        4, 2, str_trainerschool_test_question_0, 
                str_trainerschool_test_question_0_answers
    },{
        4, 0, str_trainerschool_test_question_1, 
                str_trainerschool_test_question_1_answers
    },{
        3, 2, str_trainerschool_test_question_2, 
                str_trainerschool_test_question_2_answers
    },{
        5, 3, str_trainerschool_test_question_3, 
                str_trainerschool_test_question_3_answers
    },{
        4, 0, str_trainerschool_test_question_4, 
                str_trainerschool_test_question_4_answers
    },{
        5, 0, str_trainerschool_test_question_5, 
                str_trainerschool_test_question_5_answers
    },{
        3, 0, str_trainerschool_test_question_6, 
                str_trainerschool_test_question_6_answers
    },{
        4, 3, str_trainerschool_test_question_7, 
                str_trainerschool_test_question_7_answers
    },{
        4, 1, str_trainerschool_test_question_8, 
                str_trainerschool_test_question_8_answers
    },{
        4, 1, str_trainerschool_test_question_9, 
                str_trainerschool_test_question_9_answers
    }
};


