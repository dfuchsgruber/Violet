#include "types.h"
#include "romfuncs.h"
#include "karma.h"
#include "constants/vars.h"

int modify_price_money(int price_money) {

    int new_price_money = price_money;

    //Applying difficulty
    switch (*var_access(DIFFICULTY)) {

        case 4:
            new_price_money /= 3;
            break;
        case 3:
            new_price_money >>= 1;
            break;
        case 1:
            new_price_money += (new_price_money >> 1);
            break;
        case 0:
            new_price_money <<= 1;
            break;
    }

    //Applying karma
    int factor = 0x100 - ((s16) (*var_access(KARMA_VALUE)));
    new_price_money *= factor;
    new_price_money >>= 8;

    u16 *credit = var_access(BANK_CREDIT);
    if (*credit) {
        int to_pay = new_price_money - (new_price_money >> 2);
        if (to_pay > *credit) {
            to_pay = *credit;
        }
        *credit = (u16) (*credit - to_pay);
        new_price_money -= to_pay;
    }

    return new_price_money;
}
