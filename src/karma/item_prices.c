#include "types.h"
#include "romfuncs.h"
#include "karma.h"

int modify_item_prices(int price) {

    int price_new = price;

    switch (*vardecrypt(0x50F9)) {

        case 0:
            price_new >>= 1; //0.5
            break;
        case 1:
            price_new -= (price_new >> 2); //0.75
            break;
        case 3:
            price_new += (price_new << 1); //1.5
            break;
        case 4:
            price_new <<= 1; //2.0
            break;
    }

    //We use karma as a factor from 0.5 to 1.5
    int factor = 0x100 + ((s16) (*vardecrypt(VAR_KARMA)));
    price_new *= factor;
    price_new >>= 8;

    //Now we make sure our price is a multiple of 10
    int d = price_new / 10;
    if (d * 10 != price_new) {
        d++;
    }
    return d * 10;
}