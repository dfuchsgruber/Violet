#ifndef H_KARMA
#define H_KARMA

int modify_item_prices(int price);
/**
 * Calculates the effective karma value based on the karma points and stores it in
 * the KARMA_VALUE var
 */
void karma_calculate();
/**
 * Adds a certian amount of karma points to the current state
 * @param value pointer to the amount to add
 * @return karma points after the adding
 */
s16 karma_add(s16 *value);
int modify_price_money(int price_money);


#endif
