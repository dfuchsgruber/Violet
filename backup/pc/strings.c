#include "types.h"
#include "language.h"
#include "pc.h"

static u8 str_cancel[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));
static u8 str_store[] = LANGDEP(PSTRING("Ablegen"), PSTRING("Store"));
static u8 str_withdraw[] = LANGDEP(PSTRING("Nehmen"), PSTRING("Withdraw"));
static u8 str_move[] = LANGDEP(PSTRING("Bewegen"), PSTRING("Move"));
static u8 str_shift[] = LANGDEP(PSTRING("Tausch"), PSTRING("Shift"));
static u8 str_place[] = LANGDEP(PSTRING("Absetzen"), PSTRING("Place"));
static u8 str_summary[] = LANGDEP(PSTRING("Bericht"), PSTRING("Summary"));
static u8 str_release[] = LANGDEP(PSTRING("Entlassen"), PSTRING("Release"));
static u8 str_mark[] = LANGDEP(PSTRING("Markieren"), PSTRING("Mark"));
static u8 str_jump[] = LANGDEP(PSTRING("Wechseln"), PSTRING("Jump"));
static u8 str_wallpaper[] = LANGDEP(PSTRING("Motiv"), PSTRING("Wallpaper"));
static u8 str_name[] = LANGDEP(PSTRING("Bennenen"), PSTRING("Name"));
static u8 str_take[] = LANGDEP(PSTRING("Nehmen"), PSTRING("Take"));
static u8 str_give[] = LANGDEP(PSTRING("Geben"), PSTRING("Give"));
static u8 str_give2[] = LANGDEP(PSTRING("Geben"), PSTRING("Give2"));
static u8 str_switch[] = LANGDEP(PSTRING("Tauschen"), PSTRING("Switch"));
static u8 str_bag[] = LANGDEP(PSTRING("Beutel"), PSTRING("Bag"));
static u8 str_info[] = LANGDEP(PSTRING("Info"), PSTRING("Info"));
static u8 str_scenery1[] = LANGDEP(PSTRING("Liste 1"), PSTRING("Scenery 1"));
static u8 str_scenery2[] = LANGDEP(PSTRING("Liste 2"), PSTRING("Scenery 2"));
static u8 str_scenery3[] = LANGDEP(PSTRING("Liste 3"), PSTRING("Scenery 3"));
static u8 str_etcetera[] = LANGDEP(PSTRING("Sonstiges"), PSTRING("Etcetera"));
static u8 str_forest[] = LANGDEP(PSTRING("Wald"), PSTRING("Forest"));
static u8 str_city[] = LANGDEP(PSTRING("Mauer"), PSTRING("City"));
static u8 str_desert[] = LANGDEP(PSTRING("Wüste"), PSTRING("Desert"));
static u8 str_savanna[] = LANGDEP(PSTRING("Steppe"), PSTRING("Savanna"));
static u8 str_crag[] = LANGDEP(PSTRING("Geröll"), PSTRING("Crag"));
static u8 str_volcano[] = LANGDEP(PSTRING("Vulkan"), PSTRING("Volcano"));
static u8 str_snow[] = LANGDEP(PSTRING("Schnee"), PSTRING("Snow"));
static u8 str_cave[] = LANGDEP(PSTRING("Höhle"), PSTRING("Cave"));
static u8 str_beach[] = LANGDEP(PSTRING("Strand"), PSTRING("Beach"));
static u8 str_seafloor[] = LANGDEP(PSTRING("Tiefsee"), PSTRING("Seafloor"));
static u8 str_river[] = LANGDEP(PSTRING("Fluss"), PSTRING("River"));
static u8 str_sky[] = LANGDEP(PSTRING("Himmel"), PSTRING("Sky"));
static u8 str_polka_dot[] = LANGDEP(PSTRING("Sterne"), PSTRING("Polka Dot"));
static u8 str_pokecenter[] = LANGDEP(PSTRING("Pokéstop"), PSTRING("Pokecenter"));
static u8 str_machine[] = LANGDEP(PSTRING("Fliese"), PSTRING("Machine"));
static u8 str_simple[] = LANGDEP(PSTRING("Weiß"), PSTRING("Simple"));
static u8 str_select[] = LANGDEP(PSTRING("Auswählen"), PSTRING("Select"));

u8 *pc_context_menu_item_strings[] = {
    [PC_CONTEXT_MENU_ITEM_CANCEL] = str_cancel,
    [PC_CONTEXT_MENU_ITEM_STORE] = str_store,
    [PC_CONTEXT_MENU_ITEM_WITHDRAW] = str_withdraw,
    [PC_CONTEXT_MENU_ITEM_MOVE] = str_move,
    [PC_CONTEXT_MENU_ITEM_SHIFT] = str_shift,
    [PC_CONTEXT_MENU_ITEM_PLACE] = str_place,
    [PC_CONTEXT_MENU_ITEM_SUMMARY] = str_summary,
    [PC_CONTEXT_MENU_ITEM_RELEASE] = str_release,
    [PC_CONTEXT_MENU_ITEM_MARK] = str_mark,
    [PC_CONTEXT_MENU_ITEM_JUMP] = str_jump,
    [PC_CONTEXT_MENU_ITEM_WALLPAPER] = str_wallpaper,
    [PC_CONTEXT_MENU_ITEM_NAME] = str_name,
    [PC_CONTEXT_MENU_ITEM_TAKE] = str_take,
    [PC_CONTEXT_MENU_ITEM_GIVE] = str_give,
    [PC_CONTEXT_MENU_ITEM_GIVE2] = str_give2,
    [PC_CONTEXT_MENU_ITEM_SWITCH] = str_switch,
    [PC_CONTEXT_MENU_ITEM_BAG] = str_bag,
    [PC_CONTEXT_MENU_ITEM_INFO] = str_info,
    [PC_CONTEXT_MENU_ITEM_SCENERY1] = str_scenery1,
    [PC_CONTEXT_MENU_ITEM_SCENERY2] = str_scenery2,
    [PC_CONTEXT_MENU_ITEM_SCENERY3] = str_scenery3,
    [PC_CONTEXT_MENU_ITEM_ETCETERA] = str_etcetera,
    [PC_CONTEXT_MENU_ITEM_FOREST] = str_forest,
    [PC_CONTEXT_MENU_ITEM_CITY] = str_city,
    [PC_CONTEXT_MENU_ITEM_DESERT] = str_desert,
    [PC_CONTEXT_MENU_ITEM_SAVANNA] = str_savanna,
    [PC_CONTEXT_MENU_ITEM_CRAG] = str_crag,
    [PC_CONTEXT_MENU_ITEM_VOLCANO] = str_volcano,
    [PC_CONTEXT_MENU_ITEM_SNOW] = str_snow,
    [PC_CONTEXT_MENU_ITEM_CAVE] = str_cave,
    [PC_CONTEXT_MENU_ITEM_BEACH] = str_beach,
    [PC_CONTEXT_MENU_ITEM_SEAFLOOR] = str_seafloor,
    [PC_CONTEXT_MENU_ITEM_RIVER] = str_river,
    [PC_CONTEXT_MENU_ITEM_SKY] = str_sky,
    [PC_CONTEXT_MENU_ITEM_POLKA_DOT] = str_polka_dot,
    [PC_CONTEXT_MENU_ITEM_POKECENTER] = str_pokecenter,
    [PC_CONTEXT_MENU_ITEM_MACHINE] = str_machine,
    [PC_CONTEXT_MENU_ITEM_SIMPLE] = str_simple,
    [PC_CONTEXT_MENU_ITEM_SELECT] = str_select,
};

static u8 str_exit_box[] = LANGDEP(PSTRING("Die Box verlassen?"), PSTRING("Exit from the BOX."));
static u8 str_what_you_do[] = LANGDEP(PSTRING("Was möchtest du tun?"), PSTRING("What do you want to do?"));
static u8 str_pick_a_theme[] = LANGDEP(PSTRING("Wähle eine Motivsammlung."), PSTRING("Please pick a theme."));
static u8 str_pick_a_wallpaper[] = LANGDEP(PSTRING("Wähle einen Hintergrund."), PSTRING("Pick the wallpaper."));
static u8 str_is_selected[] = LANGDEP(PSTRING("Ausgewählt: BOX_SELECTED_PKMN "), PSTRING("BOX_SELECTED_PKMN  is selected."));
static u8 str_jump_to_which_box[] = LANGDEP(PSTRING("Zu welcher Box wechseln?"), PSTRING("Jump to which BOX?"));
static u8 str_deposit_in_which_box[] = LANGDEP(PSTRING("In welche Box ablegen?"), PSTRING("Deposit in which BOX?"));
static u8 str_was_deposited[] = LANGDEP(PSTRING("Abgelegt: BOX_SELECTED_PKMN "), PSTRING("BOX_SELECTED_PKMN  was deposited."));
static u8 str_box_is_full[] = LANGDEP(PSTRING("Die Box ist voll."), PSTRING("The BOX is full."));
static u8 str_release_poke[] = LANGDEP(PSTRING("Dieses Pokémon freilassen?"), PSTRING("Release this POKéMON?"));
static u8 str_was_released[] = LANGDEP(PSTRING("BOX_SELECTED_PKMN  ist frei."), PSTRING("BOX_SELECTED_PKMN  was released."));
static u8 str_bye_bye[] = LANGDEP(PSTRING("Tschüss, BOX_SELECTED_PKMN !"), PSTRING("Bye-bye, BOX_SELECTED_PKMN !"));
static u8 str_mark_poke[] = LANGDEP(PSTRING("Markiere dein Pokémon."), PSTRING("Mark your POKéMON."));
static u8 str_last_poke[] = LANGDEP(PSTRING("Dein letztes Pokémon!"), PSTRING("That's your last POKéMON!"));
static u8 str_party_full[] = LANGDEP(PSTRING("Dein Team ist voll!"), PSTRING("Your party's full!"));
static u8 str_holding_poke[] = LANGDEP(PSTRING("Du hältst ein Pokémon!"), PSTRING("You're holding a POKéMON!"));
static u8 str_which_one_will_take[] = LANGDEP(PSTRING("Welches wählst du aus?"), PSTRING("Which one will you take?"));
static u8 str_cant_release_egg[] = LANGDEP(PSTRING("Ei-Freilassung unmöglich!"), PSTRING("You can't release an EGG."));
static u8 str_continue_box[] = LANGDEP(PSTRING("Box weiter bearbeiten?"), PSTRING("Continue BOX operations?"));
static u8 str_came_back[] = LANGDEP(PSTRING("BOX_SELECTED_PKMN  kam zurück!"), PSTRING("BOX_SELECTED_PKMN  came back!"));
static u8 str_worried[] = LANGDEP(PSTRING("War es in Sorge um dich?"), PSTRING("Was it worried about you?"));
static u8 str_surprise[] = LANGDEP(PSTRING("... ... ... ... ...!"), PSTRING("DOTS DOTS DOTS DOTS DOTS!"));
static u8 str_please_remove_mail[] = LANGDEP(PSTRING("Bitte Brief entfernen."), PSTRING("Please remove the MAIL."));
static u8 str_is_selected2[] = LANGDEP(PSTRING("Ausgewählt: BOX_SELECTED_PKMN "), PSTRING("BOX_SELECTED_PKMN  is selected."));
static u8 str_give_to_mon[] = LANGDEP(PSTRING("Einem Pokémon geben?"), PSTRING("GIVE to a POKéMON?"));
static u8 str_placed_in_bag[] = LANGDEP(PSTRING("Item im Beutel verstaut."), PSTRING("Placed item in the BAG."));
static u8 str_bag_full[] = LANGDEP(PSTRING("Der Beutel ist voll."), PSTRING("The BAG is full."));
static u8 str_put_in_bag[] = LANGDEP(PSTRING("Item in den Beutel legen?"), PSTRING("Put this item in the BAG?"));
static u8 str_item_is_held[] = LANGDEP(PSTRING("Gehalten: BOX_SELECTED_PKMN "), PSTRING("BOX_SELECTED_PKMN  is now held."));
static u8 str_changed_to_item[] = LANGDEP(PSTRING("Geändert in BOX_SELECTED_PKMN ."), PSTRING("Changed to BOX_SELECTED_PKMN ."));
static u8 str_cant_store_mail[] = LANGDEP(PSTRING("Brief-Lagerung unmöglich!"), PSTRING("MAIL can't be stored!"));
static u8 str_select_this_one[] = LANGDEP(PSTRING("BOX_SELECTED_PKMN  auswählen?"), PSTRING("Choose BOX_SELECTED_PKMN?"));
static u8 str_select_egg[] = LANGDEP(PSTRING("Wähle ein Ei!"), PSTRING("Choose an egg!"));
static u8 str_cant_trade_eggs[] = LANGDEP(PSTRING("Das ist ein Ei!"), PSTRING("That is an egg!"));
static u8 str_cant_trade_hm_user[] = LANGDEP(PSTRING("Kennt eine Vm!"), PSTRING("Knows an Hm move!"));


pc_context_text_t pc_context_texts[] = {
    [PC_CONTEXT_TEXT_EXIT_BOX] = {.text = str_exit_box, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_WHAT_YOU_DO] = {.text = str_what_you_do, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PICK_A_THEME] = {.text = str_pick_a_theme, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PICK_A_WALLPAPER] = {.text = str_pick_a_wallpaper, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_IS_SELECTED] = {.text = str_is_selected, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_0},
    [PC_CONTEXT_TEXT_JUMP_TO_WHICH_BOX] = {.text = str_jump_to_which_box, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_DEPOSIT_IN_WHICH_BOX] = {.text = str_deposit_in_which_box, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_WAS_DEPOSITED] = {.text = str_was_deposited, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_0},
    [PC_CONTEXT_TEXT_BOX_IS_FULL] = {.text = str_box_is_full, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_RELEASE_POKE] = {.text = str_release_poke, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_WAS_RELEASED] = {.text = str_was_released, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_3},
    [PC_CONTEXT_TEXT_BYE_BYE] = {.text = str_bye_bye, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_5},
    [PC_CONTEXT_TEXT_MARK_POKE] = {.text = str_mark_poke, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_LAST_POKE] = {.text = str_last_poke, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PARTY_FULL] = {.text = str_party_full, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_HOLDING_POKE] = {.text = str_holding_poke, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_WHICH_ONE_WILL_TAKE] = {.text = str_which_one_will_take, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_CANT_RELEASE_EGG] = {.text = str_cant_release_egg, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_CONTINUE_BOX] = {.text = str_continue_box, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_CAME_BACK] = {.text = str_came_back, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_0},
    [PC_CONTEXT_TEXT_WORRIED] = {.text = str_worried, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_SURPRISE] = {.text = str_surprise, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PLEASE_REMOVE_MAIL] = {.text = str_please_remove_mail, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_IS_SELECTED2] = {.text = str_is_selected2, .format = PC_CONTEXT_TEXT_FORMAT_ITEM},
    [PC_CONTEXT_TEXT_GIVE_TO_MON] = {.text = str_give_to_mon, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PLACED_IN_BAG] = {.text = str_placed_in_bag, .format = PC_CONTEXT_TEXT_FORMAT_ITEM},
    [PC_CONTEXT_TEXT_BAG_FULL] = {.text = str_bag_full, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_PUT_IN_BAG] = {.text = str_put_in_bag, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_ITEM_IS_HELD] = {.text = str_item_is_held, .format = PC_CONTEXT_TEXT_FORMAT_ITEM},
    [PC_CONTEXT_TEXT_CHANGED_TO_ITEM] = {.text = str_changed_to_item, .format = PC_CONTEXT_TEXT_FORMAT_ITEM},
    [PC_CONTEXT_TEXT_CANT_STORE_MAIL] = {.text = str_cant_store_mail, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_SELECT_THIS_ONE] = {.text = str_select_this_one, .format = PC_CONTEXT_TEXT_FORMAT_POKEMON_0},
    [PC_CONTEXT_TEXT_SELECT_EGG] = {.text = str_select_egg, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_CANT_TRADE_EGGS] = {.text = str_cant_trade_eggs, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
    [PC_CONTEXT_TEXT_CANT_TRADE_HM_USER] = {.text = str_cant_trade_hm_user, .format = PC_CONTEXT_TEXT_FORMAT_NORMAL},
};