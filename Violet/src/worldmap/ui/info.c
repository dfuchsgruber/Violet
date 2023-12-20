#include "types.h"
#include "worldmap.h"
#include "io.h"
#include "language.h"
#include "map/namespace.h"
#include "debug.h"
#include "fading.h"
#include "callbacks.h"
#include "agbmemory.h"
#include "dma.h"
#include "music.h"
#include "overworld/map_control.h"
#include "bios.h"
#include "pokemon/move_relearner.h"
#include "pokemon/moves.h"
#include "attack.h"
#include "pokemon/basestat.h"
#include "constants/flags.h"
#include "flags.h"
#include "gym.h"
#include "menu_indicators.h"

extern const LZ77COMPRESSED gfx_worldmap_ui_info_frameTiles;
extern const LZ77COMPRESSED gfx_worldmap_ui_info_frameMap;
extern const color_t gfx_worldmap_ui_info_framePal[16];
extern const u8 gfx_worldmap_ui_info_headerTiles[GRAPHIC_SIZE_4BPP(64, 16)];
extern const color_t gfx_worldmap_ui_info_headerPal[16];

static void worldmap_ui_info_update_namespace_by_cursor_position(bool print_if_namespace_not_changed);
static void worldmap_ui_info_update_info();
static void worldmap_ui_handle_inputs_info(u8 self);
static void worldmap_ui_search_dialoge_handle_inputs_category(u8 self);

static const worldmap_person_t worldmap_persons[NUM_WORLDMAP_PERSONS] = {
    [WORLDMAP_PERSON_MOVE_DELETER] = {
        .person = {.bank = 19, .map_idx = 2, .person_idx = 1},
        .name = LANGDEP(PSTRING("Att.-Verl."), PSTRING("Move Deleter")),
        .flag = FLAG_MOVE_DELETER},
    [WORLDMAP_PERSON_NICKNAME_RATER] = {
        .person = {.bank = 8, .map_idx = 4, .person_idx = 1}, 
        .name = LANGDEP(PSTRING("Namensbew."), PSTRING("Name Rater")),
        .flag = FLAG_NICKNAME_RATER},
    [WORLDMAP_PERSON_MOVE_REMINDER] = {
        .person = {.bank = 9, .map_idx = 18, .person_idx = 1},
        .name = LANGDEP(PSTRING("Att.-Errin."), PSTRING("Move Remind.")), 
        .flag = FLAG_MOVE_REMINDER},
};  

static const worldmap_institution_t worldmap_institutions[NUM_WORLDMAP_INSTIUTIONS] = {
    [WORLDMAP_INSTITUTION_PLAYER_HOUSE] = {
        .bank = 3, .map_idx = 0, .warp_idx = 0, .institution_type = WORLDMAP_INSTITUTION_TYPE_HOUSE,
        .name = LANGDEP(PSTRING("PLAYER"), PSTRING("PLAYER")), .flag = WM_AMONIA,
    },
    [WORLDMAP_INSTITUTION_RIVAL_HOUSE] = {
        .bank = 3, .map_idx = 0, .warp_idx = 1, .institution_type = WORLDMAP_INSTITUTION_TYPE_HOUSE,
        .name = LANGDEP(PSTRING("RIVAL"), PSTRING("RIVAL")), .flag = WM_AMONIA,
    },
    [WORLDMAP_INSTITUTION_TANNS_LAB] = {
        .bank = 3, .map_idx = 25, .warp_idx = 1, .flag = WM_TANNS_LAB,
        .name = LANGDEP(PSTRING("Tanns Labor"), PSTRING("Fig's Lab")),
    },
    [WORLDMAP_INSTITUTION_GYM_BASE + 0] = {
        .bank = 3, .map_idx = 2, .warp_idx = 10, .institution_type = WORLDMAP_INSTITUTION_TYPE_GYM,
        .name = LANGDEP(PSTRING("Antikarena"), PSTRING("Relic Gym")), .flag = WM_AKTANIA,
    },
    [WORLDMAP_INSTITUTION_GYM_BASE + 1] = {
        .bank = 3, .map_idx = 3, .warp_idx = 8, .institution_type = WORLDMAP_INSTITUTION_TYPE_GYM,
        .name = LANGDEP(PSTRING("Waldarena"), PSTRING("Forest Gym")), .flag = WM_SILVANIA,
    },
    [WORLDMAP_INSTITUTION_GYM_BASE + 2] = {
        .bank = 3, .map_idx = 1, .warp_idx = 2, .institution_type = WORLDMAP_INSTITUTION_TYPE_GYM,
        .name = LANGDEP(PSTRING("Lotusarena"), PSTRING("Lotus Gym")), .flag = WM_MERIANA_CITY,
    },
    [WORLDMAP_INSTITUTION_GYM_BASE + 3] = {
        .bank = 3, .map_idx = 6, .warp_idx = 0, .institution_type = WORLDMAP_INSTITUTION_TYPE_GYM,
        .name = LANGDEP(PSTRING("Magmaarena"), PSTRING("Magma Gym")), .flag = WM_INFERIOR,
    },
    [WORLDMAP_INSTITUTION_GYM_BASE + 4] = {
        .bank = 3, .map_idx = 13, .warp_idx = 4, .institution_type = WORLDMAP_INSTITUTION_TYPE_GYM,
        .name = LANGDEP(PSTRING("Ruhearena"), PSTRING("Calm Gym")), .flag = WM_CEOMETRIA,
    },
    [WORLDMAP_INSTITUTION_LAZ_CORP] = {
        .bank = 3, .map_idx = 5, .warp_idx = 0,
        .name = LANGDEP(PSTRING("Laz. Corp."), PSTRING("Laz. Corp.")), .flag = WM_ORINA_CITY,
    },
    [WORLDMAP_INSTITUTION_LESTER_HOUSE] = {
        .bank = 3, .map_idx = 2, .warp_idx = 2, .institution_type = WORLDMAP_INSTITUTION_TYPE_HOUSE,
        .name = LANGDEP(PSTRING("Lester"), PSTRING("Lester")), .flag = FLAG_LESTERS_HOUSE,
    },
    [WORLDMAP_INSTITUTION_ROSALIE_HOUSE] = {
        .bank = 3, .map_idx = 3, .warp_idx = 6, .institution_type = WORLDMAP_INSTITUTION_TYPE_HOUSE,
        .name = LANGDEP(PSTRING("Rosalie"), PSTRING("Rosalie")), .flag = SILVANIA_FAUN_AND_MIA,
    },
    [WORLDMAP_INSTITUTION_CELEBI_SHRINE] = {
        .bank = 1, .map_idx = 0, .warp_idx = 8, .flag = SILVANIA_FOREST_RIN,
        .name = LANGDEP(PSTRING("Zeitschrein"), PSTRING("Time Shrine")),
    },
    [WORLDMAP_INSTITUTION_TEAHS_HOUSE] = {
        .bank = 3, .map_idx = 14, .warp_idx = 0, .institution_type = WORLDMAP_INSTITUTION_TYPE_HOUSE,
        .name = LANGDEP(PSTRING("Teahs Haus"), PSTRING("Teah's House")), .flag = FLAG_TEAHS_HOUSE,
    },
};

static const tboxdata worldmap_ui_info_tboxes[NUM_WORLDMAP_UI_INFO_TBOXES + 1] = {
    [WORLDMAP_UI_TBOX_IDX_NAMESPACE] = {.bg_id = 2, .x = 8, .y = 2, .w = 17, .h = 2, .pal = 15, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES},
    [WORLDMAP_UI_INFO_TBOX_HEADER] = {.bg_id = 0, .x = 13, .y = 0, .w = 13, .h = 2, .pal = 15, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2},
    [WORLDMAP_UI_INFO_TBOX_FOOTER] = {.bg_id = 0, .x = 8, .y = 18, .w = 22, .h = 2, .pal = 14, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2},
    [WORLDMAP_UI_INFO_TBOX_HEADER_INFO] = {.bg_id = 0, .x = 0, .y = 0, .w = 8, .h = 2, .pal = 14, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2 + 22 * 2},
    [WORLDMAP_UI_INFO_TBOX_INFO] = {.bg_id = 0, .x = 0, .y = 2, .w = 8, .h = 18, .pal = 12, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2 + 22 * 2 + 8 * 2},
    [WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY] = {.bg_id = 0, .x = 9, .y = 3, .w = 8, .h = NUM_WORLDMAP_CATEGORIES * 2, .pal = 11, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2 + 22 * 2 + 8 * 2 + 18 * 8},
    [WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS] = {.bg_id = 0, .x = 19, .y = 3, .w = 10, .h = WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN * 2, .pal = 11, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2 + 22 * 2 + 8 * 2 + 18 * 8 + 8 * NUM_WORLDMAP_CATEGORIES * 2},
    [WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE] = {.bg_id = 0, .x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_HABITAT, .y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_HABITAT, .w = WORLDMAP_SWITCH_MAPS_DIALOGE_WIDTH, .h = WORLDMAP_SWITCH_MAPS_DIALOGE_HEIGHT, .pal = 13, 
        .start_tile = 2 + TBOX_FRAME_SET_STYLE_NUM_TILES + 17 * 2 + 13 * 2 + 22 * 2 + 8 * 2 + 18 * 8},
    [NUM_WORLDMAP_UI_INFO_TBOXES] = {.bg_id = 0xFF},
};

static void list_menu_print_callback_null(u8 tbox_idx, int idx, u8 y) {
    (void)tbox_idx; (void)idx; (void)y;
} 

static void list_menu_print_institution_callback(u8 tbox_idx, int idx, u8 y) {
    const worldmap_institution_t *institution = worldmap_institutions + idx;
    switch (institution->institution_type) {
        case WORLDMAP_INSTITUTION_TYPE_HOUSE: {
            if (institution->flag == 0 || checkflag(institution->flag)) {
                tbox_blit(tbox_idx, gfx_worldmap_ui_info_headerTiles, 
                    WORLDMAP_INFO_ICON_HOUSE_X, WORLDMAP_INFO_ICON_HOUSE_Y, 64, 32, 
                    10, (u16)(y + 3), WORLDMAP_INFO_ICON_HOUSE_WIDTH, WORLDMAP_INFO_ICON_HOUSE_HEIGHT);
            }
            break;
        }
        case WORLDMAP_INSTITUTION_TYPE_GYM: {
            if (institution->flag == 0 || checkflag(institution->flag)) {
                tbox_blit(tbox_idx, gfx_worldmap_ui_info_headerTiles, 
                    WORLDMAP_INFO_ICON_POKEBALL_X, WORLDMAP_INFO_ICON_POKEBALL_Y, 64, 32, 
                    10, (u16)(y + 3), WORLDMAP_INFO_ICON_POKEBALL_WIDTH, WORLDMAP_INFO_ICON_POKEBALL_HEIGHT);
            }
            break;
        }
    }
}


static void list_menu_print_tutor_crystal_callback(u8 tbox_idx, int idx, u8 y) {
    if (accessible_move_tutor_check_flag((u8)idx)) {
        tbox_blit_move_info_icon(tbox_idx, (u8)(MOVE_INFO_TYPE_BASE + idx), 
            10, (u16)(y + 0));
    }
}

static void worldmap_ui_info_cursor_moved(UNUSED u8 self) {
    worldmap_ui_info_update_namespace_by_cursor_position(false);
    worldmap_ui_info_update_info();
}

static void worldmap_ui_info_cursor_starts_moving(UNUSED u8 self) {}

static const bg_config worldmap_ui_bg_configs[] = {
    [0] = { // Text layer on UI
        .bg_id = 0, .char_base = 0, .map_base = 28, .priority = 0, .size = 0,
    },
    [1] = { // Frame layer
        .bg_id = 1, .char_base = 2, .map_base = 29, .priority = 1, .size = 0,
    },
    [2] = { // Text layer for namespace label and info over
        .bg_id = 2, .char_base = 0, .map_base = 30, .priority = 2, .size = 0,
    },
    [3] = { // Worldmap layer
        .bg_id = 3, .char_base = 1, .map_base = 31, .priority = 3, .size = 0, .color_mode = 1,

    },
};

static const tbox_font_colormap font_colormap_transparent = {.background = 0, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_non_transparent = {.background = 1, .body = 2, .edge = 0};
static const tbox_font_colormap font_colormap_info = {.background = 0, .body = 14, .edge = 10};
static const tbox_font_colormap font_colormap_info_header = {.background = 0, .body = 1, .edge = 2};
static const tbox_font_colormap font_colormap_info_category = {.background = 0, .body = 10, .edge = 9};

static const u8 str_footer[] = LANGDEP(
    PSTRING("TEXT_SET_FG\x02KEY_STARTSKIP\x02TEXT_SET_FG\x01SuchenSKIP\x02KEY_SELECTSKIP\x02Wechseln"),
    PSTRING("KEY_STARTSKIP\x02SearchSKIP\x02KEY_SELECTSKIP\x02Switch")
);

static const u8 str_header[] = LANGDEP(
    PSTRING("Karte"),
    PSTRING("Town Map")
);

static const u8 str_namespace_switch_maps[] = LANGDEP(
    PSTRING("Karte wechseln"),
    PSTRING("Switch maps")
);

static const u8 str_info_header[] = LANGDEP(
    PSTRING("Info"),
    PSTRING("Info")
);

static const u8 str_info_tutor[] = LANGDEP(
    PSTRING("Tutoren"),
    PSTRING("Tutors")
);

static const u8 str_info_tutor_crystal[] = LANGDEP(
    PSTRING("Kristalle"),
    PSTRING("Crystals")
);

static const u8 str_info_person[] = LANGDEP(
    PSTRING("Personen"),
    PSTRING("People")
);

static const u8 str_info_institutions[] = LANGDEP(
    PSTRING("Orte"),
    PSTRING("Locations")
);

static const u8 str_not_visited[] = PSTRING("???");

static bool worldmap_ui_person_get_position(u8 bank, u8 map_idx, u8 person_idx, u8 *x, u8 *y, u8 *layer, u8 *worldmap_idx) {
    const map_event_person *person = map_get_person(person_idx, map_idx, bank);
    if (person) {
        return map_coordinates_to_worldmap_position(bank, map_idx, person->x, person->y, 
            x, y, worldmap_idx, layer);
    }
    return false;
}

static bool worldmap_ui_warp_get_position(u8 bank, u8 map_idx, u8 warp_idx, u8 *x, u8 *y, u8 *layer, u8 *worldmap_idx) {
    const map_header_t *header = get_mapheader(bank, map_idx);
    if (header && header->events) {
        if (warp_idx < header->events->warp_cnt && header->events->warps) {
            const map_event_warp *warp = header->events->warps + warp_idx;
            return map_coordinates_to_worldmap_position(bank, map_idx, warp->x, warp->y, 
            x, y, worldmap_idx, layer);
        }
    }
    return false;
}

static bool worldmap_ui_info_tutor_get_position(const move_tutor_t *tutor, u8 *x, u8 *y) {
    if (tutor->bank == 0xFF) 
        return false;
    u8 layer, worldmap_idx;
    return worldmap_ui_person_get_position(tutor->bank, tutor->map_idx, tutor->person_idx, x, y, &layer, &worldmap_idx);
}

static bool worldmap_ui_info_is_tutor_at_cursor(const move_tutor_t *tutor) {
    if (tutor->bank == 0xFF) 
        return false;
    const worldmap_position_t *position = worldmap_positions[tutor->bank] + tutor->map_idx;
    if (position->worldmap_idx == worldmap_ui_state->cursor.idx &&
        position->layer == worldmap_ui_state->cursor.layer &&
        worldmap_ui_state->cursor.x >= position->x && worldmap_ui_state->cursor.x < position->x + position->width &&
        worldmap_ui_state->cursor.y >= position->y && worldmap_ui_state->cursor.y < position->y + position->height
        ) {
        u8 tutor_x, tutor_y;
        if (worldmap_ui_info_tutor_get_position(tutor, &tutor_x, &tutor_y)) {
            return tutor_x == worldmap_ui_state->cursor.x && tutor_y == worldmap_ui_state->cursor.y;
        }
    }
    return false;
}

static bool worldmap_ui_info_is_institution_at_cursor(const worldmap_institution_t *institution) {
    const worldmap_position_t *position = worldmap_positions[institution->bank] + institution->map_idx;
    if (position->worldmap_idx == worldmap_ui_state->cursor.idx &&
        position->layer == worldmap_ui_state->cursor.layer &&
        worldmap_ui_state->cursor.x >= position->x && worldmap_ui_state->cursor.x < position->x + position->width &&
        worldmap_ui_state->cursor.y >= position->y && worldmap_ui_state->cursor.y < position->y + position->height
        ) {
        u8 x, y, layer, worldmap_idx;
        if (worldmap_ui_warp_get_position(institution->bank, institution->map_idx,
            institution->warp_idx, &x, &y, &layer, &worldmap_idx)) {
            return x == worldmap_ui_state->cursor.x && y == worldmap_ui_state->cursor.y;
        }
    }
    return false;
}

static void worldmap_ui_info_print_header(u8 y, const u8 *str) {
    tbox_blit(WORLDMAP_UI_INFO_TBOX_INFO, gfx_worldmap_ui_info_headerTiles, 0, 0, 64, 16, 2, (u16)(y + 1), 60, 16);
    tbox_print_string(WORLDMAP_UI_INFO_TBOX_INFO, 2, 
        4, y, 0, 0, &font_colormap_info_category, 0xFF, str);
}

static void worldmap_ui_info_print_tutors(u8 *y) {
    // Check if any tutor is on the current position
    bool tutor_at_position = false;
    for (u8 i = 0; i < ARRAY_COUNT(move_tutors); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(move_tutors + i)) {
            tutor_at_position = true;
            break;
        }
    }
    if (!tutor_at_position)
        return;
    worldmap_ui_info_print_header(*y, str_info_tutor);
    *y = (u8)(*y + 16);
    for (u8 i = 0; i < ARRAY_COUNT(move_tutors); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(move_tutors + i)) {
            u16 attack = move_tutor_get_attack(i);
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_INFO, 0, 3, 
                *y, 0, 0, &font_colormap_info, 0xFF, 
                move_tutor_check_flag(i) ? attack_names[attack] : str_not_visited);
            *y = (u8)(*y + 12);
        }
    }
    *y = (u8)(*y + 2);
}



static void worldmap_ui_info_print_tutor_crystals(u8 *y) {
    // Check if any tutor is on the current position
    bool tutor_at_position = false;
    for (u8 i = 0; i < ARRAY_COUNT(move_tutor_crystals); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(move_tutor_crystals + i)) {
            tutor_at_position = true;
            break;
        }
    }
    if (!tutor_at_position)
        return;
    worldmap_ui_info_print_header(*y, str_info_tutor_crystal);
    *y = (u8)(*y + 16);
    for (u8 i = 0; i < ARRAY_COUNT(move_tutor_crystals); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(move_tutor_crystals + i)) {
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_INFO, 0, 3, 
                *y, 0, 0, &font_colormap_info, 0xFF, 
                accessible_move_tutor_check_flag(i) ? str_pokemon_type_names[i] : str_not_visited);
            *y = (u8)(*y + 12);
        }
    }
    *y = (u8)(*y + 2);
}

static void worldmap_ui_info_print_persons(u8 *y) {
    // Check if any person is at this position
    bool person_at_position = false;
    for (u8 i = 0; i < ARRAY_COUNT(worldmap_persons); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(&worldmap_persons[i].person)) {
            person_at_position = true;
            break;
        }
    }
    if (!person_at_position)
        return;
    worldmap_ui_info_print_header(*y, str_info_person);
    *y = (u8)(*y + 16);
    for (u8 i = 0; i < ARRAY_COUNT(move_tutor_crystals); i++) {
        if (worldmap_ui_info_is_tutor_at_cursor(&worldmap_persons[i].person)) {
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_INFO, 0, 3, 
                *y, 0, 0, &font_colormap_info, 0xFF, 
                checkflag(worldmap_persons[i].flag) ? worldmap_persons[i].name : str_not_visited);
            *y = (u8)(*y + 12);
        }
    }
    *y = (u8)(*y + 2);
}

static void worldmap_ui_info_print_institutions(u8 *y) {
    // Check if any institution is at this position
    bool institution_at_position = false;
    for (u8 i = 0; i < ARRAY_COUNT(worldmap_institutions); i++) {
        if (worldmap_ui_info_is_institution_at_cursor(worldmap_institutions + i)) {
            DEBUG("Instiution at position %d\n", i);
            institution_at_position = true;
            break;
        }
    }
    if (!institution_at_position)
        return;
    worldmap_ui_info_print_header(*y, str_info_institutions);
    *y = (u8)(*y + 16);
    for (u8 i = 0; i < ARRAY_COUNT(move_tutor_crystals); i++) {
        if (worldmap_ui_info_is_institution_at_cursor(worldmap_institutions + i)) {
            u16 x = 3;
            if ((worldmap_institutions[i].flag == 0 || checkflag(worldmap_institutions[i].flag))) {
                string_decrypt(strbuf, worldmap_institutions[i].name);
                switch (worldmap_institutions[i].institution_type) {
                    case WORLDMAP_INSTITUTION_TYPE_HOUSE: {
                        tbox_blit(WORLDMAP_UI_INFO_TBOX_INFO, gfx_worldmap_ui_info_headerTiles, 
                            WORLDMAP_INFO_ICON_HOUSE_X, WORLDMAP_INFO_ICON_HOUSE_Y, 64, 32, 
                            x, (u16)(*y + 3), WORLDMAP_INFO_ICON_HOUSE_WIDTH, WORLDMAP_INFO_ICON_HOUSE_HEIGHT);
                        x = (u16)(x + 10);
                        break;
                    }
                    case WORLDMAP_INSTITUTION_TYPE_GYM: {
                        tbox_blit(WORLDMAP_UI_INFO_TBOX_INFO, gfx_worldmap_ui_info_headerTiles, 
                            WORLDMAP_INFO_ICON_POKEBALL_X, WORLDMAP_INFO_ICON_POKEBALL_Y, 64, 32, 
                            x, (u16)(*y + 3), WORLDMAP_INFO_ICON_POKEBALL_WIDTH, WORLDMAP_INFO_ICON_POKEBALL_HEIGHT);
                        x = (u16)(x + 10);

                    }
                }
            } else {
                string_decrypt(strbuf, str_not_visited);
            }
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_INFO, 0, x, 
                *y, 0, 0, &font_colormap_info, 0xFF, strbuf);
            *y = (u8)(*y + 12);
        }
    }
    *y = (u8)(*y + 2);
}


static void worldmap_ui_info_update_info() {
    tbox_flush_set(WORLDMAP_UI_INFO_TBOX_INFO, 0x00);
    u8 y = 2;
    worldmap_ui_info_print_persons(&y);
    worldmap_ui_info_print_institutions(&y);
    worldmap_ui_info_print_tutors(&y);
    worldmap_ui_info_print_tutor_crystals(&y);
    tbox_sync(WORLDMAP_UI_INFO_TBOX_INFO, TBOX_SYNC_SET);
}


static void worldmap_ui_info_update_namespace_by_cursor_position(bool print_if_namespace_not_changed) {
    const u8 *str = NULL;
    if (worldmap_ui_state->cursor.x == worldmap_ui_state->icon_switch_maps_x &&
        worldmap_ui_state->cursor.y == worldmap_ui_state->icon_switch_maps_y) {
        str = str_namespace_switch_maps;
    } else {
        u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
            worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
        if ((namespace_idx != worldmap_ui_state->current_namespace || print_if_namespace_not_changed) 
                && namespace_idx != MAP_NAMESPACE_NONE) {
            worldmap_ui_state->current_namespace = namespace_idx;
            str = map_namespaces[MAP_NAMESPACE_TO_IDX(namespace_idx)];
        }
    }
    if (str) {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x11);
        tbox_print_string(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 2, 4, 0, 0, 0, &font_colormap_non_transparent, 0, str);
    } else {
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x00);
        tbox_sync(WORLDMAP_UI_TBOX_IDX_NAMESPACE, TBOX_SYNC_SET);
    }
}

static void worldmap_ui_info_free() {
    tbox_free_all();
    free(worldmap_ui_state->bg0_map);
    free(worldmap_ui_state->bg1_map);
    free(worldmap_ui_state->bg2_map);
    free(worldmap_ui_state->bg3_map);
    worldmap_ui_free_base();
}

static void worldmap_ui_exit(u8 self) {
    if (!fading_control.active) {
        callback1_set(worldmap_ui_state->continuation);
        worldmap_ui_info_free();
        big_callback_delete(self);
    }
}

static void worldmap_ui_update_worldmap(u8 self) {
    if (fading_control.active)
        return;
    worldmap_ui_state->cursor = worldmap_ui_state->cursor_switch_maps;
    worldmap_ui_info_update_namespace_by_cursor_position(true);
    worldmap_ui_info_update_info();
    worldmap_ui_update_worldmap_gfx(worldmap_ui_state->cursor.idx, 
                worldmap_ui_state->cursor.layer, worldmap_ui_state->worldmap_tile_x, worldmap_ui_state->worldmap_tile_y);
    worldmap_ui_update_player_head_oam();
    worldmap_ui_update_cursor_oam();
    fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
    bg_virtual_sync_reqeust_push(2);
    bg_virtual_sync_reqeust_push(3);
    big_callbacks[self].function = worldmap_ui_handle_inputs_info;
}

static void worldmap_ui_handle_inputs_switch_maps_info(u8 self) {
    if (worldmap_ui_switch_maps_dialoge_process_input(self))
        return;
    else if (super.keys_new.keys.B || (super.keys_new.keys.A && worldmap_ui_state->cursor_switch_maps.idx == worldmap_ui_state->cursor.idx &&
            worldmap_ui_state->cursor_switch_maps.layer == worldmap_ui_state->cursor.layer)) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_delete();
        big_callbacks[self].function = worldmap_ui_handle_inputs_info;
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_delete();
        tbox_flush_set(WORLDMAP_UI_TBOX_IDX_NAMESPACE, 0x00);
        tbox_sync(WORLDMAP_UI_TBOX_IDX_NAMESPACE, TBOX_SYNC_SET);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = worldmap_ui_update_worldmap;
    }
}

static const u8 str_category_persons[] = LANGDEP(PSTRING("Personen"), PSTRING("People"));
static const u8 str_category_institutions[] = LANGDEP(PSTRING("Orte"), PSTRING("Locations"));
static const u8 str_category_tutors[] = LANGDEP(PSTRING("Tutoren"), PSTRING("Tutors"));
static const u8 str_category_tutor_crystals[] = LANGDEP(PSTRING("Kristalle"), PSTRING("Crystals"));

static const list_menu_item list_menu_items_search_category[NUM_WORLDMAP_CATEGORIES] = {
    {.idx = WORLDMAP_CATEGORY_PERSON, .text = str_category_persons},
    {.idx = WORLDMAP_CATEGORY_INSTITUTION, .text = str_category_institutions},
    {.idx = WORLDMAP_CATEGORY_TUTOR, .text = str_category_tutors},
    {.idx = WORLDMAP_CATEGORY_TUTOR_CRYSTAL, .text = str_category_tutor_crystals},
};

static const list_menu_template list_menu_search_category = {
    .items = list_menu_items_search_category,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = list_menu_print_callback_null,
    .item_cnt = NUM_WORLDMAP_CATEGORIES, .max_items_showed = NUM_WORLDMAP_CATEGORIES, .tbox_idx = WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY,
    .header_x = 0, .item_x = 10, .cursor_x = 2, .up_text_y = 2, .cursor_pal = 14, .fill_value = 15,
    .cursor_shadow_color = 10, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static void worldmap_ui_search_dialoge_items_delete() {
    list_menu_remove(worldmap_ui_state->list_menu_search_items_cb_idx,
        &worldmap_ui_state->search_items_cursor[worldmap_ui_state->search_category], 
        &worldmap_ui_state->search_items_items_above[worldmap_ui_state->search_category]);
    tbox_flush_map_and_frame(WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS);
    scroll_indicator_delete(worldmap_ui_state->scroll_indicator_search_items_cb_idx);
    bg_virtual_sync_reqeust_push(0);
}

static void worldmap_ui_search_dialoge_category_delete() {
    list_menu_remove(worldmap_ui_state->list_menu_search_cb_idx,
        &worldmap_ui_state->search_category_cursor, &worldmap_ui_state->search_category_items_above);
    tbox_flush_map_and_frame(WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY);
    bg_virtual_sync_reqeust_push(0);
}


static void worldmap_ui_search_dialoge_handle_inputs_items(UNUSED u8 self) {
    if (dma3_busy(-1) || fading_control.active)
        return;
    int input = list_menu_process_input(worldmap_ui_state->list_menu_search_items_cb_idx);
    list_menu_get_scroll_and_row(worldmap_ui_state->list_menu_search_items_cb_idx, 
        &worldmap_ui_state->search_items_cursor[worldmap_ui_state->search_category], 
        &worldmap_ui_state->search_items_items_above[worldmap_ui_state->search_category]);
    switch (input) {
        case LIST_MENU_B_PRESSED: {
            play_sound(5);
            worldmap_ui_search_dialoge_items_delete();
            big_callbacks[self].function = worldmap_ui_search_dialoge_handle_inputs_category;
            break;
        }
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        default:
            list_menu_get_scroll_and_row(worldmap_ui_state->list_menu_search_items_cb_idx, 
                &worldmap_ui_state->search_items_cursor[worldmap_ui_state->search_category], 
                &worldmap_ui_state->search_items_items_above[worldmap_ui_state->search_category]);
            switch (worldmap_ui_state->search_category) {
                case WORLDMAP_CATEGORY_PERSON: {
                    const worldmap_person_t *person = worldmap_persons + input;
                    if (person->flag == 0 || checkflag(person->flag)) {
                        worldmap_ui_person_get_position(person->person.bank, person->person.map_idx, person->person.person_idx, 
                            &worldmap_ui_state->cursor_switch_maps.x, &worldmap_ui_state->cursor_switch_maps.y, 
                            &worldmap_ui_state->cursor_switch_maps.layer, &worldmap_ui_state->cursor_switch_maps.idx);
                    } else {
                        return;
                    }
                    break;
                }
                case WORLDMAP_CATEGORY_INSTITUTION: {
                    const worldmap_institution_t *institution = worldmap_institutions + input;
                    if (institution->flag == 0 || checkflag(institution->flag)) {
                        worldmap_ui_warp_get_position(institution->bank, institution->map_idx, institution->warp_idx, 
                            &worldmap_ui_state->cursor_switch_maps.x, &worldmap_ui_state->cursor_switch_maps.y, 
                            &worldmap_ui_state->cursor_switch_maps.layer, &worldmap_ui_state->cursor_switch_maps.idx);
                    } else {
                        return;
                    }
                    break;
                }
                case WORLDMAP_CATEGORY_TUTOR: {
                    const move_tutor_t *tutor = move_tutors + input;
                    if (tutor->bank == 0xFF) 
                        return;
                    worldmap_ui_person_get_position(tutor->bank, tutor->map_idx, tutor->person_idx, 
                        &worldmap_ui_state->cursor_switch_maps.x, &worldmap_ui_state->cursor_switch_maps.y, 
                        &worldmap_ui_state->cursor_switch_maps.layer, &worldmap_ui_state->cursor_switch_maps.idx);
                    break;
                }
                case WORLDMAP_CATEGORY_TUTOR_CRYSTAL: {
                    const move_tutor_t *tutor = move_tutor_crystals + input;
                    if (tutor->bank == 0xFF) 
                        return;
                    worldmap_ui_person_get_position(tutor->bank, tutor->map_idx, tutor->person_idx, 
                        &worldmap_ui_state->cursor_switch_maps.x, &worldmap_ui_state->cursor_switch_maps.y, 
                        &worldmap_ui_state->cursor_switch_maps.layer,  &worldmap_ui_state->cursor_switch_maps.idx);
                    break;
                }
            }
            DEBUG("Change to cursor %d %d layer %d idx %d\n", worldmap_ui_state->cursor_switch_maps.x, worldmap_ui_state->cursor_switch_maps.y, 
                worldmap_ui_state->cursor_switch_maps.layer, worldmap_ui_state->cursor_switch_maps.idx);
            worldmap_ui_search_dialoge_items_delete();
            worldmap_ui_search_dialoge_category_delete();
            fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
            big_callbacks[self].function = worldmap_ui_update_worldmap;
            play_sound(5);
            break;
    }
}

static const list_menu_template list_menu_template_items = {
    .items = NULL, .item_cnt = 0,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = list_menu_print_callback_null,
    .max_items_showed = WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN, 
    .tbox_idx = WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS,
    .header_x = 0, .item_x = 10, .cursor_x = 2, .up_text_y = 2, .cursor_pal = 14, .fill_value = 15,
    .cursor_shadow_color = 10, .letter_spacing = 1, .item_vertical_padding = 2, .scroll_multiple = 0,
    .font = 2
};

static void list_menu_items_build_persons(list_menu_template *template) {
    for (size_t i = 0; i < ARRAY_COUNT(worldmap_persons); i++) {
        worldmap_ui_state->search_items.persons[i] = (list_menu_item){.idx = (int)i, 
            .text = (worldmap_persons[i].flag == 0 || checkflag(worldmap_persons[i].flag)) ? worldmap_persons[i].name : str_not_visited};
    }
    template->items = worldmap_ui_state->search_items.persons;
    template->item_cnt = (u16)(ARRAY_COUNT(worldmap_persons));
    template->max_items_showed = (u16)MIN(WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN, template->item_cnt);
}


static void list_menu_items_build_tutors(list_menu_template *template) {
    for (u8 i = 0; i < NUM_MOVE_TUTORS; i++) {
        u16 attack = move_tutor_get_attack(i);
        worldmap_ui_state->search_items.tutors[i] = (list_menu_item){.idx = (int)i, 
            .text = move_tutor_check_flag(i) ? attack_names[attack] : str_not_visited};
    }
    template->items = worldmap_ui_state->search_items.tutors;
    template->item_cnt = NUM_MOVE_TUTORS;
    template->max_items_showed = (u16)MIN(WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN, NUM_MOVE_TUTORS);
}

static const u8 str_none[] = PSTRING("");

static void list_menu_items_build_tutor_crystals(list_menu_template *template) {
    for (u8 i = 0; i < NUM_TYPES; i++) {
        worldmap_ui_state->search_items.tutor_crystals[i] = (list_menu_item){.idx = (int)i, 
            .text = (accessible_move_tutor_check_flag(i)) ? str_none : str_not_visited};
    }
    template->item_print_callback = list_menu_print_tutor_crystal_callback;
    template->items = worldmap_ui_state->search_items.tutor_crystals;
    template->item_cnt = NUM_TYPES;
    template->max_items_showed = (u16)MIN(WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN, NUM_TYPES);
}

static const u8 str_clear_x0A_and_buffer0[] = PSTRING("CLEAR_TO\x0ABUFFER_1");

static void list_menu_items_build_institutions(list_menu_template *template) {
    for (u16 i = 0; i < ARRAY_COUNT(worldmap_institutions); i++) {
        switch (worldmap_institutions[i].institution_type) {
            case WORLDMAP_INSTITUTION_TYPE_GYM:
            case WORLDMAP_INSTITUTION_TYPE_HOUSE: {
                strcpy(buffer0, worldmap_institutions[i].name);
                string_decrypt(worldmap_ui_state->search_item_strs.institutions[i], str_clear_x0A_and_buffer0);
                break;
            }
            default: {
                string_decrypt(worldmap_ui_state->search_item_strs.institutions[i], worldmap_institutions[i].name);
                break;
            }
        }
        worldmap_ui_state->search_items.institutions[i] = (list_menu_item){.idx = (int)i, 
            .text = (worldmap_institutions[i].flag == 0 || checkflag(worldmap_institutions[i].flag)) ? \
                worldmap_ui_state->search_item_strs.institutions[i] : str_not_visited};
    }
    template->items = worldmap_ui_state->search_items.institutions;
    template->item_cnt = (u16)ARRAY_COUNT(worldmap_institutions);
    template->max_items_showed = (u16)MIN(WORLDMAP_INFO_SEARCH_MAX_ITEMS_SHOWN, ARRAY_COUNT(worldmap_institutions));
    template->item_print_callback = list_menu_print_institution_callback;
}

static void (*const list_menu_items_build[NUM_WORLDMAP_CATEGORIES])(list_menu_template*) = {
    [WORLDMAP_CATEGORY_PERSON] = list_menu_items_build_persons,
    [WORLDMAP_CATEGORY_INSTITUTION] = list_menu_items_build_institutions,
    [WORLDMAP_CATEGORY_TUTOR] = list_menu_items_build_tutors,
    [WORLDMAP_CATEGORY_TUTOR_CRYSTAL] = list_menu_items_build_tutor_crystals,
};


static void worldmap_ui_search_dialoge_items_new(u8 self, int which) {
    worldmap_ui_state->search_category = (u8)which;
    gp_list_menu_template = list_menu_template_items;
    list_menu_items_build[which](&gp_list_menu_template);
    scroll_indicator_template indicator_template = {
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16)MAX(0, gp_list_menu_template.item_cnt - gp_list_menu_template.max_items_showed), 
        .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow0_x = 192, .arrow1_x = 192,
        .arrow0_y = 16, .arrow1_y = 140,
        .pal_tag = 112, .tiles_tag = 112,
    };
    worldmap_ui_state->scroll_indicator_search_items_cb_idx = scroll_indicator_new(&indicator_template,
        &worldmap_ui_state->search_items_cursor[which]);
    tbox_flush_set(WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS, 0x11);
    tbox_tilemap_draw(WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS);
    tbox_frame_draw_outer(WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS, 2, 13);
    worldmap_ui_state->list_menu_search_items_cb_idx = list_menu_new(&gp_list_menu_template,
        worldmap_ui_state->search_items_cursor[which], worldmap_ui_state->search_items_items_above[which]);
    bg_virtual_sync_reqeust_push(0);
    big_callbacks[self].function = worldmap_ui_search_dialoge_handle_inputs_items;
}


static void worldmap_ui_search_dialoge_handle_inputs_category(u8 self) {
    if (dma3_busy(-1) || fading_control.active)
        return;
    int input = list_menu_process_input(worldmap_ui_state->list_menu_search_cb_idx);
    switch (input) {
        case LIST_MENU_B_PRESSED: {
            play_sound(5);
            worldmap_ui_search_dialoge_category_delete();
            big_callbacks[self].function = worldmap_ui_handle_inputs_info;
            break;
        }
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        default:
            list_menu_get_scroll_and_row(worldmap_ui_state->list_menu_search_cb_idx, 
                &worldmap_ui_state->search_category_cursor, &worldmap_ui_state->search_category_items_above);
            play_sound(5);
            worldmap_ui_search_dialoge_items_new(self, input);
            break;
    }
}

static void worldmap_ui_search_dialoge_new(u8 self) {
    tbox_flush_set(WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY, 0x11);
    tbox_tilemap_draw(WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY);
    tbox_frame_draw_outer(WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY, 2, 13);
    worldmap_ui_state->list_menu_search_cb_idx = list_menu_new(&list_menu_search_category, 
        worldmap_ui_state->search_category_cursor, worldmap_ui_state->search_category_items_above);
    bg_virtual_sync_reqeust_push(0);
    big_callbacks[self].function = worldmap_ui_search_dialoge_handle_inputs_category;
}


static void worldmap_ui_handle_inputs_info(u8 self) {
    if (dma3_busy(-1) || fading_control.active)
        return;
    if (worldmap_ui_handle_inputs_move_cursor(self))
        return;
    else if (super.keys_new.keys.select ||
        (super.keys_new.keys.A && worldmap_ui_state->cursor.x == worldmap_ui_state->icon_switch_maps_x &&
            worldmap_ui_state->cursor.y == worldmap_ui_state->icon_switch_maps_y)) {
        play_sound(5);
        worldmap_ui_switch_maps_dialoge_new(self, worldmap_ui_handle_inputs_switch_maps_info);
        return;
    } else if (super.keys_new.keys.start) {
        play_sound(5);
        worldmap_ui_search_dialoge_new(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
        big_callbacks[self].function = worldmap_ui_exit;
    }
}

void worldmap_ui_callback_initialize_info() {
    if (!worldmap_ui_callback_initialize_base())
        return;
    switch (worldmap_ui_state->initialization_state) {
        case WORLDMAP_UI_INITIALIZATION_STATE_DATA_SETUP: {
            worldmap_ui_state->initialization_state++;
            worldmap_ui_state->callback_cursor_moved = worldmap_ui_info_cursor_moved;
            worldmap_ui_state->callback_cursor_starts_moving = worldmap_ui_info_cursor_starts_moving;
            worldmap_ui_state->worldmap_tile_x = WORLDMAP_X_OFFSET_INFO;
            worldmap_ui_state->worldmap_tile_y = WORLDMAP_Y_OFFSET_INFO;
            worldmap_ui_state->icon_switch_maps_x = WORLDMAP_BUTTON_SWITCH_MAPS_INFO_X;
            worldmap_ui_state->icon_switch_maps_y = WORLDMAP_BUTTON_SWITCH_MAPS_INFO_Y;
            worldmap_ui_state->switch_map_dialoge_x = WORLDMAP_SWITCH_MAPS_DIALOGE_X_INFO;
            worldmap_ui_state->switch_map_dialoge_y = WORLDMAP_SWITCH_MAPS_DIALOGE_Y_INFO;
            worldmap_ui_state->switch_maps_allowed = true;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_RESET: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_BGS: {
            bg_reset(0);
            bg_reset_control_and_displacement();
            bg_setup(0, worldmap_ui_bg_configs, ARRAY_COUNT(worldmap_ui_bg_configs));
            worldmap_ui_state->bg0_map = malloc_and_clear(0x800);
            bg_set_tilemap(0, worldmap_ui_state->bg0_map);
            worldmap_ui_state->bg1_map = malloc_and_clear(0x800);
            bg_set_tilemap(1, worldmap_ui_state->bg1_map);
            worldmap_ui_state->bg2_map = malloc_and_clear(0x800);
            bg_set_tilemap(2, worldmap_ui_state->bg2_map);
            worldmap_ui_state->bg3_map = malloc_and_clear(0x800);
            bg_set_tilemap(3, worldmap_ui_state->bg3_map);
            bg_display_sync();
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            io_set(IO_WININ, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) |
                IO_WININOUT_BG(1, 0) | IO_WININOUT_BG(1, 1) | IO_WININOUT_BG(1, 2) | IO_WININOUT_BG(1, 3) | IO_WININOUT_FX(0) |
                IO_WININOUT_FX(1) | IO_WININOUT_OBJ(0) | IO_WININOUT_OBJ(1));
            io_set(IO_DISPCNT, IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL | IO_DISPCNT_OBJ | IO_DISPCNT_WIN0);
            io_set(IO_BLDCNT, IO_BLDCNT_NONE);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_SCANLINE: {
            dma0_reset_callback();
            io_set(IO_BLDCNT, IO_BLDCNT_BG2_FIRST | IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG0_SECOND |
                    IO_BLDCNT_BG1_SECOND | IO_BLDCNT_BG2_SECOND | IO_BLDCNT_BG3_SECOND | IO_BLDCNT_OBJ_SECOND |
                    IO_BLDCNT_BACKDROP_SECOND); 
            for (int i = 0; i < 32; i++) {
                dma0_scanline_frames[0][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
                dma0_scanline_frames[1][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(10);
            }
            for (int i = 32; i < 160 - 16; i++) {
                dma0_scanline_frames[0][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(0);
                dma0_scanline_frames[1][i] = IO_BLDALPHA_EVA(15) | IO_BLDALPHA_EVB(0);
            }
            dma0_scanline_flipflop_t flipflop = {.bytes = {.flipflop_cntrl = 1, .defaults_field_16_17 = 0}};
            dma0_init_scanline((void*)(IO_ADDRESS + IO_BLDALPHA),
                    DMA_ENABLE | DMA_TIMING_HBLANK | DMA_REPEAT | DMA_SRC_INCREMENT | DMA_DST_RELOAD |
                    DMA_SIZE(1),
                    flipflop);
                    worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SETUP_TBOXES: {
            tbox_free_all();
            tbox_sync_with_virtual_bg_and_init_all(worldmap_ui_info_tboxes);
            tbox_init_frame_set_style(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, 2, 13 * 16);
            for (u8 i = 0; worldmap_ui_info_tboxes[i].bg_id != 0xFF; i++) {
                if (i == WORLDMAP_UI_INFO_TBOX_SEARCH_CATEGORY || i == WORLDMAP_UI_INFO_TBOX_SEARCH_ITEMS
                    || i == WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE)
                    continue;
                tbox_flush_set(i, 0x00);
                tbox_flush_map(i);
                tbox_tilemap_draw(i);
                bg_virtual_sync_reqeust_push(worldmap_ui_info_tboxes[i].bg_id);
            }
            tbox_sync(WORLDMAP_UI_TBOX_IDX_SWITCH_MAPS_DIALOGE, TBOX_SYNC_SET);
            strcpy(buffer0, worldmap_names[worldmap_ui_state->cursor.idx]);
            string_decrypt(strbuf, str_header);
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_HEADER, 2, 
                (u16)((worldmap_ui_info_tboxes[WORLDMAP_UI_INFO_TBOX_HEADER].w * 8 - string_get_width(2, strbuf, 0)) / 2), 
                1, 0, 0, &font_colormap_transparent, 0, strbuf);
            tbox_sync(WORLDMAP_UI_INFO_TBOX_HEADER, TBOX_SYNC_SET);
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_FOOTER, 2, 2, 1, 0, 0, &font_colormap_transparent, 0, str_footer);
            tbox_print_string(WORLDMAP_UI_INFO_TBOX_HEADER_INFO, 2, 
                CENTERED_STR_X(str_info_header, 2, 8 * worldmap_ui_info_tboxes[WORLDMAP_UI_INFO_TBOX_HEADER_INFO].w, 0),
                1, 0, 0, &font_colormap_info_header, 0, str_info_header);
            tbox_sync(WORLDMAP_UI_INFO_TBOX_INFO, TBOX_SYNC_SET);
            u8 namespace_idx = worldmap_get_namespace_by_pos(worldmap_ui_state->cursor.idx, worldmap_ui_state->cursor.layer,
                worldmap_ui_state->cursor.x, worldmap_ui_state->cursor.y);
            worldmap_ui_info_update_namespace_by_cursor_position(true);
            worldmap_ui_info_update_info();
            worldmap_ui_state->current_namespace = namespace_idx;
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_BG_GFX: {
            pal_copy(gfx_worldmap_ui_info_framePal, 80, sizeof(gfx_worldmap_ui_info_framePal));
            pal_copy(typechart_icon_pal, 11 * 16, sizeof(typechart_icon_pal));
            pal_copy(gfx_worldmap_ui_info_headerPal, 12 * 16, sizeof(gfx_worldmap_ui_info_headerPal));
            lz77uncompvram(gfx_worldmap_ui_info_frameTiles, CHARBASE(2));
            lz77uncompwram(gfx_worldmap_ui_info_frameMap, worldmap_ui_state->bg1_map);
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_LOAD_OAM_GFX: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        case WORLDMAP_UI_INITIALIZATION_STATE_SHOW: {
            worldmap_ui_state->initialization_state++;
            break;
        }
        default: {
            fading_control.buffer_transfer_disabled = false;
            worldmap_ui_state->cb_idx_handle_inputs = big_callback_new(worldmap_ui_handle_inputs_info, 10);
            callback1_set(worldmap_ui_cb1);
            vblank_handler_set(worldmap_ui_vblank_callback);
            fadescreen(0xFFFFFFFF, 0, 16, 0, 0);
            break;
        }
    }
}

void worldmap_ui_info_new(void (*continuation)()) {
    worldmap_ui_state = malloc_and_clear(sizeof(worldmap_ui_state_t));
    worldmap_ui_state->continuation = continuation;
    callback1_set(worldmap_ui_callback_initialize_info);
}