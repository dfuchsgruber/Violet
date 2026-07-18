#include "overworld/restaurant.h"
#include "language.h"
#include "vars.h"
#include "agbmemory.h"
#include "bg.h"
#include "text.h"
#include "list_menu.h"
#include "debug.h"
#include "callbacks.h"
#include "menu_indicators.h"
#include "overworld/script.h"
#include "constants/pokemon_types.h"
#include "save.h"
#include "music.h"
#include "superstate.h"

EWRAM restaurant_menu_state_t *restaurant_menu_state = NULL;

const restaurant_menu_t restaurant_menu = {
    .starters = (const restaurant_menu_item_t[]) {
        {
            .name = (const u8[]) LANGDEP(PSTRING("Keine Vorspeise"), PSTRING("No Starter")),
            .description = (const u8[]) LANGDEP(PSTRING("---"), PSTRING("---")),
            .price = 0,
            .effect = 0
        },{ 
            .name = (const u8[]) LANGDEP(PSTRING("Chaneira's Rührei"), PSTRING("Chansey's Scrambled Eggs")), 
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Kp Fleiß-Punkte."), PSTRING("Gain more Hp Effort Values.")), 
            .price = 1000,
            .effect = RESTAURANT_BOOST_HP_EV
        }, {
            .name = (const u8[]) LANGDEP(PSTRING("Bruta-Schuppen"), PSTRING("Salamance Scales")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Angriffs Fleiß-Punkte."), PSTRING("Gain more Attack Effort Values.")),
            .price = 1000,
            .effect = RESTAURANT_BOOST_ATTACK_EV
        }, {
            .name = (const u8[]) LANGDEP(PSTRING("Muschas-Happen"), PSTRING("Shelder Bites")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Verteidigungs Fleiß-Punkte."), PSTRING("Gain more Defense Effort Values.")),
            .price = 1000,
            .effect = RESTAURANT_BOOST_DEFENSE_EV
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Volto-Stangen"), PSTRING("Volto Sticks")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Initiative Fleiß-Punkte."), PSTRING("Gain more Speed Effort Values.")),
            .price = 1000,
            .effect = RESTAURANT_BOOST_SPEED_EV
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Glurak-Flambé"), PSTRING("Chariz-Flambé")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Sp. Angr. Fleiß-Punkte."), PSTRING("Gain more Special Attack Effort Values.")),
            .price = 1000,
            .effect = RESTAURANT_BOOST_SP_ATTACK_EV,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Kappa-Suppe"), PSTRING("Ludi Soup")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Sp. Vert. Fleiß-Punkte."), PSTRING("Gain more Special Defense Effort Values.")),
            .price = 1000,
            .effect = RESTAURANT_BOOST_SP_DEFENSE_EV,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Pikachu-Salat"), PSTRING("Pikachu Salad")),
            .description = (const u8[]) LANGDEP(PSTRING("Erhalte mehr Erfahrungs Punkte."), PSTRING("Gain more Experience Points.")),
            .price = 3000,
            .effect = RESTAURANT_BOOST_EXP,
        },
        { .name = NULL }
    },
    .mains = (const restaurant_menu_item_t[]) {
        {
            .name = (const u8[]) LANGDEP(PSTRING("Togepi-Omlette"), PSTRING("Togepi Omelette")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 5."), PSTRING("Enemies are around Level 5.")),
            .price = 500,
            .effect = RESTAURANT_LEVEL_5,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Marill-Sandwich"), PSTRING("Marill Sandwich")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 13."), PSTRING("Enemies are around Level 13.")),
            .price = 750,
            .effect = RESTAURANT_LEVEL_13,
            .flag = ROUTE_2_TANN_AND_VIOLET_GRUNTS,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Miltank-Schnitzel"), PSTRING("Miltank Cutlet")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 19."), PSTRING("Enemies are around Level 19.")),
            .price = 1000,
            .effect = RESTAURANT_LEVEL_19,
            .flag = FRBADGE_1,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Lahmus-Schweif"), PSTRING("Slowpoke Tail")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 25."), PSTRING("Enemies are around Level 25.")),
            .price = 2000,
            .effect = RESTAURANT_LEVEL_25,
            .flag = FRBADGE_2,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Relaxo-Braten"), PSTRING("Snorlax Roast")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 33."), PSTRING("Enemies are around Level 33.")),
            .price = 3000,
            .effect = RESTAURANT_LEVEL_33,
            .flag = KUSTENBERG_DONE,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Milotic-Sushi"), PSTRING("Milotic Sushi")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 41."), PSTRING("Enemies are around Level 41.")),
            .price = 4000,
            .effect = RESTAURANT_LEVEL_41,
            .flag = FRBADGE_3,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Chevrumm-Rippen"), PSTRING("Gogoat Ribs")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 49."), PSTRING("Enemies are around Level 49.")),
            .price = 5000,
            .effect = RESTAURANT_LEVEL_49,
            .flag = FRBADGE_4,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Lavados-Flügel"), PSTRING("Moltres Wings")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 57."), PSTRING("Enemies are around Level 57.")),
            .price = 6000,
            .effect = RESTAURANT_LEVEL_57,
            .flag = FRBADGE_5,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Metagross Pfanne"), PSTRING("Metagross Stew")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 65."), PSTRING("Enemies are around Level 65.")),
            .price = 7500,
            .effect = RESTAURANT_LEVEL_65,
            .flag = FRBADGE_6,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Rayquaza-Roulade"), PSTRING("Rayquaza Roulade")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 73."), PSTRING("Enemies are around Level 73.")),
            .price = 9000,
            .effect = RESTAURANT_LEVEL_73,
            .flag = FRBADGE_7,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Mewtu-Soufflé"), PSTRING("Mewtwo Soufflé")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 81."), PSTRING("Enemies are around Level 81.")),
            .price = 9000,
            .effect = RESTAURANT_LEVEL_81,
            .flag = FRBADGE_8,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Dragoran-Gourmet"), PSTRING("Dragonite Gourmet")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 89."), PSTRING("Enemies are around Level 89.")),
            .price = 9000,
            .effect = RESTAURANT_LEVEL_89,
            .flag = FRBADGE_8,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Mew-Delikatesse"), PSTRING("Mew Delicacy")),
            .description = (const u8[]) LANGDEP(PSTRING("Gegner sind ungefähr auf Level 100."), PSTRING("Enemies are around Level 100.")),
            .price = 9999,
            .effect = RESTAURANT_LEVEL_100,
            .flag = FRBADGE_8,
        },
        { .name = NULL }
    },
    .desserts = (const restaurant_menu_item_t[]) {
        {
            .name = (const u8[]) LANGDEP(PSTRING("Keine Nachspeise"), PSTRING("No Dessert")),
            .description = (const u8[]) LANGDEP(PSTRING("---"), PSTRING("---")),
            .price = 0,
            .effect = NUM_TYPES,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Normale Kekse"), PSTRING("Normal Cookies")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Normal Pokémon."), PSTRING("Fight against Normal Pokémon.")),
            .price = 1500,
            .effect = TYPE_NORMAL,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Kampf Pralinen"), PSTRING("Fighting Chocolates")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Kampf Pokémon."), PSTRING("Fight against Fighting Pokémon.")),
            .price = 1500,
            .effect = TYPE_KAMPF,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Flug Torte"), PSTRING("Flying Cake")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Flug Pokémon."), PSTRING("Fight against Flying Pokémon.")),
            .price = 1500,
            .effect = TYPE_FLUG,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Gift Muffins"), PSTRING("Poison Muffins")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Gift Pokémon."), PSTRING("Fight against Poison Pokémon.")),
            .price = 1500,
            .effect = TYPE_GIFT,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Boden Törtchen"), PSTRING("Ground Tart")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Boden Pokémon."), PSTRING("Fight against Ground Pokémon.")),
            .price = 1500,
            .effect = TYPE_BODEN,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Gestein Kuchen"), PSTRING("Rock Cake")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Gestein Pokémon."), PSTRING("Fight against Rock Pokémon.")),
            .price = 1500,
            .effect = TYPE_GESTEIN,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Käfer Eis"), PSTRING("Bug Ice Cream")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Käfer Pokémon."), PSTRING("Fight against Bug Pokémon.")),
            .price = 1500,
            .effect = TYPE_KAEFER,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Geist Donuts"), PSTRING("Ghost Donuts")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Geist Pokémon."), PSTRING("Fight against Ghost Pokémon.")),
            .price = 1500,
            .effect = TYPE_GEIST,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Stahl Pralinen"), PSTRING("Steel Chocolates")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Stahl Pokémon."), PSTRING("Fight against Steel Pokémon.")),
            .price = 1500,
            .effect = TYPE_STAHL,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Feen Brötchen"), PSTRING("Fairy Rolls")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Fee Pokémon."), PSTRING("Fight against Fairy Pokémon.")),
            .price = 1500,
            .effect = TYPE_FEE, 
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Feuer Pfannkuchen"), PSTRING("Fire Pancakes")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Feuer Pokémon."), PSTRING("Fight against Fire Pokémon.")),
            .price = 1500,
            .effect = TYPE_FEUER,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Wasser Waffeln"), PSTRING("Water Waffles")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Wasser Pokémon."), PSTRING("Fight against Water Pokémon.")),
            .price = 1500,
            .effect = TYPE_WASSER,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Pflanzen Schokolade"), PSTRING("Grass Chocolate")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Pflanze Pokémon."), PSTRING("Fight against Grass Pokémon.")),
            .price = 1500,
            .effect = TYPE_PFLANZE,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Elektro Gummies"), PSTRING("Electric Gummies")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Elektro Pokémon."), PSTRING("Fight against Electric Pokémon.")),
            .price = 1500,
            .effect = TYPE_ELEKTRO,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Psycho Früchte"), PSTRING("Psychic Fruits")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Psycho Pokémon."), PSTRING("Fight against Psychic Pokémon.")),
            .price = 1500,
            .effect = TYPE_PSYCHO,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Eis-Creme"), PSTRING("Ice Cream")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Eis Pokémon."), PSTRING("Fight against Ice Pokémon.")),
            .price = 1500,
            .effect = TYPE_EIS,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Drachen Bällchen"), PSTRING("Dragon Balls")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Drachen Pokémon."), PSTRING("Fight against Dragon Pokémon.")),
            .price = 1500,
            .effect = TYPE_DRACHE,
        },
        {
            .name = (const u8[]) LANGDEP(PSTRING("Unlicht Spicker"), PSTRING("Darkness Stick")),
            .description = (const u8[]) LANGDEP(PSTRING("Kämpfe gegen Unlicht Pokémon."), PSTRING("Fight against Dark Pokémon.")),
            .price = 1500,
            .effect = TYPE_UNLICHT,
        },
        { .name = NULL }
    }
};

void restaurant_menu_update_description(int idx) {
    tbox_flush_set(restaurant_menu_state->tbox_idx_description, 0x11);
    tbox_print_string(restaurant_menu_state->tbox_idx_description, 2, 0, 0, 0, 0,
        &((const tbox_font_colormap){1, 2, 3, 0}), 0,
        restaurant_menu_state->descriptions[idx]);
}

static void restaurant_menu_input_handler(u8 self);
static void restaurant_menu_wait_for_text(u8 self);

static void restaurant_menu_input_handler(u8 self) {
    int input = list_menu_process_input(restaurant_menu_state->list_menu_cb_idx);
    switch (input) {
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        case LIST_MENU_B_PRESSED:
            // recover the money already spent
            money_set(&save1->money, (u32)(*var_access(0x8008) + money_get(&save1->money)));
            lastresult = 0xFFFF;
            break;
        default: {
            u16 price = restaurant_menu_state->prices[input];
            if (money_get(&save1->money) < price) {
                tbox_flush_set(restaurant_menu_state->tbox_idx_description, 0x11);
                tbox_print_string(restaurant_menu_state->tbox_idx_description, 2, 0, 0, 0, 0,
                    &((const tbox_font_colormap){1, 2, 3, 0}), 0,
                    (const u8[]) LANGDEP(PSTRING("Du hast nicht genug Geld!"), PSTRING("You don't have enough money!")));
                
                big_callbacks[self].function = restaurant_menu_wait_for_text;
                return;
            } else {
                money_set(&save1->money, money_get(&save1->money) - price);
                *var_access(0x8008) = (u16)(*var_access(0x8008) + price);  // keep track of the money spent if the menu is aborted
                lastresult = restaurant_menu_state->effects[input];
            }
            break;
        }
    }
    tbox_flush_map_and_frame(restaurant_menu_state->tbox_idx_menu);
    tbox_flush_map_and_frame(restaurant_menu_state->tbox_idx_description);
    bg_virtual_sync_reqeust_push(0);
    tbox_free(restaurant_menu_state->tbox_idx_menu);
    tbox_free(restaurant_menu_state->tbox_idx_description);
    scroll_indicator_delete(restaurant_menu_state->scroll_indicator_cb_idx);
    free(restaurant_menu_state);
    big_callback_delete(self);
    overworld_script_resume();
}

static void restaurant_menu_wait_for_text(u8 self) {
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_set(restaurant_menu_state->tbox_idx_description, 0x11);
        list_menu_get_scroll_and_row(restaurant_menu_state->list_menu_cb_idx, 
            &(restaurant_menu_state->list_menu_cursor_offset), 
            &(restaurant_menu_state->list_menu_cursor_row));
        restaurant_menu_update_description(restaurant_menu_state->list_menu_cursor_row + restaurant_menu_state->list_menu_cursor_offset);
        big_callbacks[self].function = restaurant_menu_input_handler;
    }
}


void restaurant_list_menu_print_callback(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)y; (void)idx;
    if (restaurant_menu_state->prices[idx] == 0) {
        return;
    }
    itoa(strbuf, restaurant_menu_state->prices[idx], ITOA_PAD_SPACES, 4);
    strcat(strbuf, (const u8[])PSTRING("\$"));

    const tbox_font_colormap colormap = {1, 2, 3, 0};
    tbox_print_string(tbox_idx, 2, 112, y, 0, 0,
        &colormap, 0, strbuf);
}

void restaurant_list_menu_cursor_callback(int idx, UNUSED u8 on_initialize, UNUSED list_menu *list) {
    DEBUG("Cursor moved to %d\n", idx);
    restaurant_menu_update_description(idx);
    list_menu_get_scroll_and_row(restaurant_menu_state->list_menu_cb_idx, 
        &(restaurant_menu_state->list_menu_cursor_offset), 
        &(restaurant_menu_state->list_menu_cursor_row));
}

static list_menu_template restaurant_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = restaurant_list_menu_cursor_callback,
    .item_print_callback = restaurant_list_menu_print_callback,
    .item_cnt = 255, .max_items_showed = 4, .tbox_idx = 0,
    .header_x = 0, .item_x = 10, .cursor_x = 1, .up_text_y = 2, .cursor_pal = 2, .fill_value = 1,
    .cursor_shadow_color = 3, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

void restaurant_menu_new(const restaurant_menu_item_t *menu) {
    restaurant_menu_state = malloc_and_clear(sizeof(restaurant_menu_state_t));
    restaurant_menu_state->tbox_idx_menu = tbox_new_by_box(10, 0, 18, 8);
    tbox_init_frame_std_at_default_tile_and_pal(restaurant_menu_state->tbox_idx_menu, false);
    restaurant_menu_state->tbox_idx_description = tbox_new(&((const tboxdata){.bg_id = 0, .x = 1, .y = 11, .w = 28, .h = 2, .pal = 14, .start_tile = 270}));
    tbox_init_frame_std_at_default_tile_and_pal(restaurant_menu_state->tbox_idx_description, true);
    gp_list_menu_template = restaurant_list_menu_template;
    u8 num_items = 0;
    for (int i = 0; menu[i].name != NULL; i++) {
        if (menu[i].flag != 0 && !checkflag(menu[i].flag)) {
            continue;
        }
        restaurant_menu_state->menu_items[num_items].text = menu[i].name;
        restaurant_menu_state->menu_items[num_items].idx = num_items;
        restaurant_menu_state->prices[num_items] = menu[i].price;
        restaurant_menu_state->descriptions[num_items] = menu[i].description;
        restaurant_menu_state->effects[num_items] = menu[i].effect;
        num_items++;
    }
    gp_list_menu_template.item_cnt = num_items;
    gp_list_menu_template.tbox_idx = restaurant_menu_state->tbox_idx_menu;
    gp_list_menu_template.items = restaurant_menu_state->menu_items;
    restaurant_menu_state->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, 0, 0);
    big_callback_new(restaurant_menu_input_handler, 0);
    tbox_copy_to_vram(restaurant_menu_state->tbox_idx_menu, TBOX_COPY_TILESET);
    bg_virtual_sync_reqeust_push(0);
    restaurant_menu_state->scroll_indicator_cb_idx = scroll_indicator_new(&((const scroll_indicator_template){
        .arrow0_threshold = 0,
        .arrow1_threshold = (u16)MAX(0, num_items - gp_list_menu_template.max_items_showed),
        .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow0_x = 20 * 8, .arrow0_y = 8 - 4, .arrow1_x = 20 * 8, .arrow1_y = 9 * 8 + 4,
        .pal_tag = 111, .tiles_tag = 111
    }), &(restaurant_menu_state->list_menu_cursor_offset)
    );
}

void restaurant_menu_starters_new() {
    restaurant_menu_new(restaurant_menu.starters);
}

void restaurant_menu_mains_new() {
    restaurant_menu_new(restaurant_menu.mains);
}

void restaurant_menu_desserts_new() {
    restaurant_menu_new(restaurant_menu.desserts);
}