#include "types.h"
#include "callbacks.h"
#include "overworld/start_menu.h"
#include "overworld/map_control.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "language.h"
#include "pokepad/pokepad2.h"
#include "overworld/script.h"
#include "superstate.h"
#include "music.h"
#include "list_menu.h"
#include "debug.h"
#include "pokepad/pokedex/scanner.h"

extern const u8 ow_script_dungeon_exit[];

static bool start_menu_leave_dungeon_initialize() {
    bool result = start_menu_close();
    overworld_script_init(ow_script_dungeon_exit);
    return result;
}

static const u8 str_pokepad[] = LANGDEP(PSTRING("Poképad"), PSTRING("Poképad"));
static const u8 str_pokemon[] = LANGDEP(PSTRING("Pokémon"), PSTRING("Pokémon"));
static const u8 str_bag[] = LANGDEP(PSTRING("Beutel"), PSTRING("Bag"));
static const u8 str_player[] = LANGDEP(PSTRING("PLAYER"), PSTRING("PLAYER"));
static const u8 str_save[] = LANGDEP(PSTRING("Sichern"), PSTRING("Save"));
static const u8 str_option[] = LANGDEP(PSTRING("Option."), PSTRING("Options"));
static const u8 str_exit[] = LANGDEP(PSTRING("Beenden"), PSTRING("Exit"));
static const u8 str_retire[] = LANGDEP(PSTRING("Schluss"), PSTRING("Retire"));
static const u8 str_leave[] = LANGDEP(PSTRING("Flucht"), PSTRING("Leave"));

const start_menu_item_t start_menu_items[NUM_START_MENU_ITEMS] = {
    [START_MENU_POKEPAD] = {
        .name = str_pokepad,
        .initialize = start_menu_pokepad_initialize,
    },
    [START_MENU_POKEMON] = {
        .name = str_pokemon,
        .initialize = start_menu_pokemon_initialize,
    },
    [START_MENU_BAG] = {
        .name = str_bag,
        .initialize = start_menu_bag_initialize
    },
    [START_MENU_PLAYER] = {
        .name = str_player,
        .initialize = start_menu_trainer_card_initialize,
    },
    [START_MENU_SAVE] = {
        .name = str_save,
        .initialize = start_menu_save_initialize_and_clear_additional_box,
    },
    [START_MENU_OPTION] = {
        .name = str_option,
        .initialize = start_menu_options_initialize,
    },
    [START_MENU_EXIT] = {
        .name = str_exit,
        .initialize = start_menu_close,
    },
    [START_MENU_RETIRE] = {
        .name = str_retire,
        .initialize = start_menu_retire_initialize,
    },
    [START_MENU_PLAYER2] = {
        .name = str_player,
        .initialize = start_menu_trainer_card_initialize2,
    },
    [START_MENU_LEAVE_DUNGEON] = {
        .name = str_leave,
        .initialize = start_menu_leave_dungeon_initialize,
    },
};

static const u8 str_pokepad_description[] = LANGDEP(
    PSTRING("Benutze verschiedene Apps, die auf dem\nPoképad installiert sind."),
    PSTRING("Use different apps that are installed\non the Poképad.")
);

static const u8 str_pokemon_description[] = LANGDEP(
    PSTRING("Überprüfe und organisiere die Pokémon,\ndie sich in deinem Team befinden."),
    PSTRING("Check and organize the Pokémon that are\nin your party.")
);

static const u8 str_bag_description[] = LANGDEP(
    PSTRING("Enthält Taschen für Items, die du gekauft,\nerhalten oder gefunden hast."),
    PSTRING("Has pockets for items you have bought,\nreceived or found.")
);

static const u8 str_trainer_card_description[] = LANGDEP(
    PSTRING("Überprüfe Geldbestand und Spieldaten\nauf deinem Trainerpass."),
    PSTRING("Check money and game stats on your\ntrainer card.")
);

static const u8 str_save_description[] = LANGDEP(
    PSTRING("Sichere deinen Spielfortschritt und\nmache eine Pause."),
    PSTRING("Save your game progress and take\na break.")
);

static const u8 str_option_description[] = LANGDEP(
    PSTRING("Verändere Spieleinstellungen wie\nTexttempo, Regeln etc."),
    PSTRING("Change game settings like text speed\nrules etc.")
);

static const u8 str_exit_description[] = LANGDEP(
    PSTRING("Schließe dieses Menü."),
    PSTRING("Close this menu.")
);

static const u8 str_retire_description[] = LANGDEP(
    PSTRING("Beende das Safari-Spiel und kehre\nzum Eingang zurück."),
    PSTRING("Quit the safari game and return to\nthe entrance.")
);

static const u8 str_leave_dungeon_description[] = LANGDEP(
    PSTRING("Verlasse das Areal und kehre zum\nEingang zurück."),
    PSTRING("Leave the area and return to the\nentrance.")
);

const u8 *const start_menu_item_descriptions[NUM_START_MENU_ITEMS] = {
    [START_MENU_POKEPAD] = str_pokepad_description,
    [START_MENU_POKEMON] = str_pokemon_description,
    [START_MENU_BAG] = str_bag_description,
    [START_MENU_PLAYER] = str_trainer_card_description,
    [START_MENU_SAVE] = str_save_description,
    [START_MENU_OPTION] = str_option_description,
    [START_MENU_EXIT] = str_exit_description,
    [START_MENU_RETIRE] = str_retire_description,
    [START_MENU_PLAYER2] = str_trainer_card_description,
    [START_MENU_LEAVE_DUNGEON] = str_leave_dungeon_description,
};

void start_menu_build_dungeon() {
    start_menu_add_item(START_MENU_POKEPAD);
    start_menu_add_item(START_MENU_POKEMON);
    start_menu_add_item(START_MENU_BAG);
    start_menu_add_item(START_MENU_PLAYER);
    start_menu_add_item(START_MENU_SAVE);
    start_menu_add_item(START_MENU_OPTION);
    start_menu_add_item(START_MENU_LEAVE_DUNGEON);
}

void start_menu_build() {
    start_menu_state.number_items = 0;
    if (callback_update_link_state_is_cb0()) {
        start_menu_build_link();
    } else if (map_is_x40_x0()) {
        start_menu_build_union_room();
    } else if (safari_is_active()) {
        start_menu_build_safari();
    } else if (dungeon_get_type() && save1->bank == DG2_BANK) {
        start_menu_build_dungeon();
    } else {
        start_menu_build_std();
    }
}

bool start_menu_handle_input() {
    if (super.keys_new.keys.up) {
        play_sound(5);
        start_menu_state.cursor = gp_list_menu_move_cursor(-1);
    } else if (super.keys_new.keys.down) {
        play_sound(5);
        start_menu_state.cursor = gp_list_menu_move_cursor(1);
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        start_menu_state.callback = start_menu_items[start_menu_state.items[start_menu_state.cursor]].initialize;
        start_menu_fade_if_applicable();
    } else if (super.keys_new.keys.B || super.keys_new.keys.start) {
        start_menu_clear_additional_box();
        start_menu_delete();
        return true;
    } else if (super.keys_new_and_repeated.keys.left && start_menu_scanner_active()) {
        start_menu_scanner_move_cursor(-1);
    } else if (super.keys_new_and_repeated.keys.right && start_menu_scanner_active()) {
        start_menu_scanner_move_cursor(1);
    }
    return false;
}