#ifndef KARMA
#define KARMA
#define VAR_KARMA 0x50FB
#define VAR_KARMA_POINTS 0x50FA

void recalculate_karma();
u16 addkarma(u16 *value);
int modify_price_money(int price_money);
#endif