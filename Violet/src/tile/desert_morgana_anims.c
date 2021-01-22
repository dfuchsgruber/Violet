#include "types.h"
#include "tile/fata_morgana.h"
#include "debug.h"


morgana_anim morgana_anims[NUM_FATA_MORGANA_BLOCKS] = {
    {
        {0x320, 0x322, 0x324, 0x326}, 0x0},
    {
        {0x321, 0x323, 0x325, 0x327}, 0x0},
    {
        {0x328, 0x32a, 0x32c, 0x32e}, 0xC00},
    {
        {0x329, 0x32b, 0x32d, 0x32f}, 0xC00},
    {
        {0x330, 0x332, 0x334, 0x336}, 0xC00},
    {
        {0x331, 0x333, 0x335, 0x337}, 0xC00},
    {
        {0x338, 0x33a, 0x33c, 0x33e}, 0xC00},
    {
        {0x339, 0x33b, 0x33d, 0x33f}, 0xC00},
    {
        {0x340, 0x342, 0x344, 0x346}, 0xC00},
    {
        {0x341, 0x343, 0x345, 0x347}, 0xC00},

    {
        {0x34e, 0x34c, 0x34a, 0x348}, 0x0},
    {
        {0x34f, 0x34d, 0x34b, 0x349}, 0x0},
    {
        {0x356, 0x354, 0x352, 0x350}, 0x0},
    {
        {0x357, 0x355, 0x353, 0x351}, 0x0},
    {
        {0x35e, 0x35c, 0x35a, 0x358}, 0x0},
    {
        {0x35f, 0x35d, 0x35b, 0x359}, 0x0},
    {
        {0x366, 0x364, 0x362, 0x360}, 0x0},
    {
        {0x367, 0x365, 0x363, 0x361}, 0x0},
    {
        {0x36e, 0x36c, 0x36a, 0x368}, 0xc00},
    {
        {0x36f, 0x36d, 0x36b, 0x369}, 0xc00},

    {
        {0x376, 0x374, 0x372, 0x370}, 0x0},
    {
        {0x377, 0x375, 0x373, 0x371}, 0x0},
    {
        {0x37e, 0x37c, 0x37a, 0x378}, 0x0},
    {
        {0x37f, 0x37d, 0x37b, 0x379}, 0x0},
    {
        {0x386, 0x384, 0x382, 0x380}, 0x0},
    {
        {0x387, 0x385, 0x383, 0x381}, 0x0},

    {
        {0x38e, 0x38c, 0x38a, 0x388}, 0x0},
    {
        {0x38f, 0x38d, 0x38b, 0x389}, 0x0},
    {
        {0x396, 0x394, 0x392, 0x390}, 0x0},
    {
        {0x397, 0x395, 0x393, 0x391}, 0x0},
    {
        {0x39e, 0x39c, 0x39a, 0x398}, 0x0},
    {
        {0x39f, 0x39d, 0x39b, 0x399}, 0x0},
    {
        {0x3a6, 0x3a4, 0x3a2, 0x3a0}, 0x0},
    {
        {0x3a7, 0x3a5, 0x3a3, 0x3a1}, 0x0},
    {
        {0x3ae, 0x3ac, 0x3aa, 0x3a8}, 0x0},
    {
        {0x3af, 0x3ad, 0x3ab, 0x3a9}, 0x0},
    {{0x286, 0x28e, 0x296, 0x294,}, 0xC00},
    {{0x287, 0x28f, 0x297, 0x295,}, 0xC00},
};

int fata_morgana_index_by_block(u16 block){
    switch(block){
        case 0x320:
        case 0x322:
        case 0x324:
        case 0x326:
                return 0;
        case 0x321:
        case 0x323:
        case 0x325:
        case 0x327:
                return 1;
        case 0x328:
        case 0x32a:
        case 0x32c:
        case 0x32e:
                return 2;
        case 0x329:
        case 0x32b:
        case 0x32d:
        case 0x32f:
                return 3;
        case 0x330:
        case 0x332:
        case 0x334:
        case 0x336:
                return 4;
        case 0x331:
        case 0x333:
        case 0x335:
        case 0x337:
                return 5;
        case 0x338:
        case 0x33a:
        case 0x33c:
        case 0x33e:
                return 6;
        case 0x339:
        case 0x33b:
        case 0x33d:
        case 0x33f:
                return 7;
        case 0x340:
        case 0x342:
        case 0x344:
        case 0x346:
                return 8;
        case 0x341:
        case 0x343:
        case 0x345:
        case 0x347:
                return 9;
        case 0x34e:
        case 0x34c:
        case 0x34a:
        case 0x348:
                return 10;
        case 0x34f:
        case 0x34d:
        case 0x34b:
        case 0x349:
                return 11;
        case 0x356:
        case 0x354:
        case 0x352:
        case 0x350:
                return 12;
        case 0x357:
        case 0x355:
        case 0x353:
        case 0x351:
                return 13;
        case 0x35e:
        case 0x35c:
        case 0x35a:
        case 0x358:
                return 14;
        case 0x35f:
        case 0x35d:
        case 0x35b:
        case 0x359:
                return 15;
        case 0x366:
        case 0x364:
        case 0x362:
        case 0x360:
                return 16;
        case 0x367:
        case 0x365:
        case 0x363:
        case 0x361:
                return 17;
        case 0x36e:
        case 0x36c:
        case 0x36a:
        case 0x368:
                return 18;
        case 0x36f:
        case 0x36d:
        case 0x36b:
        case 0x369:
                return 19;
        case 0x376:
        case 0x374:
        case 0x372:
        case 0x370:
                return 20;
        case 0x377:
        case 0x375:
        case 0x373:
        case 0x371:
                return 21;
        case 0x37e:
        case 0x37c:
        case 0x37a:
        case 0x378:
                return 22;
        case 0x37f:
        case 0x37d:
        case 0x37b:
        case 0x379:
                return 23;
        case 0x386:
        case 0x384:
        case 0x382:
        case 0x380:
                return 24;
        case 0x387:
        case 0x385:
        case 0x383:
        case 0x381:
                return 25;
        case 0x38e:
        case 0x38c:
        case 0x38a:
        case 0x388:
                return 26;
        case 0x38f:
        case 0x38d:
        case 0x38b:
        case 0x389:
                return 27;
        case 0x396:
        case 0x394:
        case 0x392:
        case 0x390:
                return 28;
        case 0x397:
        case 0x395:
        case 0x393:
        case 0x391:
                return 29;
        case 0x39e:
        case 0x39c:
        case 0x39a:
        case 0x398:
                return 30;
        case 0x39f:
        case 0x39d:
        case 0x39b:
        case 0x399:
                return 31;
        case 0x3a6:
        case 0x3a4:
        case 0x3a2:
        case 0x3a0:
                return 32;
        case 0x3a7:
        case 0x3a5:
        case 0x3a3:
        case 0x3a1:
                return 33;
        case 0x3ae:
        case 0x3ac:
        case 0x3aa:
        case 0x3a8:
                return 34;
        case 0x3af:
        case 0x3ad:
        case 0x3ab:
        case 0x3a9:
                return 35;
        case 0x286:
        case 0x28e:
        case 0x296:
        case 0x294:
            return 36;
        case 0x287:
        case 0x28f:
        case 0x297:
        case 0x295:
            return 37;
    }
    dprintf("No morgana anim specified for block %d\n", block);
    err(ERR_GENERIC);
    return -1;
}
