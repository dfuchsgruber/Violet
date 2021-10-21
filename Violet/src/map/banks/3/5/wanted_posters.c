
#include "agbmemory.h"
#include "bg.h"
#include "bios.h"
#include "callbacks.h"
#include "constants/pokemon_attributes.h"
#include "constants/vars.h"
#include "data_structures.h"
#include "debug.h"
#include "dma.h"
#include "fading.h"
#include "flags.h"
#include "io.h"
#include "language.h"
#include "list_menu.h"
#include "map/orina_city_wanted_posters.h"
#include "math.h"
#include "menu_indicators.h"
#include "mugshot.h"
#include "music.h"
#include "oam.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/script.h"
#include "pokemon/basestat.h"
#include "pokemon/sprites.h"
#include "pokemon/virtual.h"
#include "pokepad/incubator.h"
#include "save.h"
#include "superstate.h"
#include "text.h"
#include "types.h"
#include "vars.h"

static u8 str_rin_description[] = LANGDEP(
    PSTRING("Team Violet\nKommandant.\nGesucht wegen\nEntführung\nvon Prof.\nPrimus. Sehr gefährlich!"),
    PSTRING("Team Violet Commander.\nWanted for kidnapping of\nProfessor Primus.\nCaution! She is said to be\nvery violent."));

static u8 str_mistral_description[] = LANGDEP(
    PSTRING("Team Violet\nKommandant.\nEhem. Mitglied\nder Revolu-\ntionsbewegung.\nGesucht wegen Diebstahl."),
    PSTRING("Team Violet Commander.\nFormer member of the revolutionary\nmovement.\nWanted for theft and\nsubversive activities."));

static u8 str_lucius_description[] = LANGDEP(
    PSTRING("Team Violet\nKommandant.\nRanghöchster\nKommandant\nder Gruppe.\nIdentität ungeklärt."),
    PSTRING("Team Violet Commander.\nHighest ranked commandant\nwithin the team. Any\nhints concering their\nidentity must be forwared\nto the local police office."));

static u8 str_lucky_description[] = LANGDEP(
    PSTRING("Revolutionär.\nEhem. Mitglied\nder Black-\nbeard Pi-\nraten. Ge-\nsucht wegen Piraterie."),
    PSTRING("Revolutionary.\nFormer member of the Blackbeard\npirates. Wanted for\npiracy and conspiracy against\nthe Elite Four."));

static u8 str_albus_description[] = LANGDEP(
    PSTRING("Anführer der\nRevolution.\nGefährlichster\nMann der\nRegion.\nJeden Kontakt vermeiden!"),
    PSTRING("Leader of revolution.\nClassified as the most\ndangerous man in the region.\nAvoid contact to this\nperson at any cost!"));

static u8 str_blackbeard_description[] = LANGDEP(
    PSTRING("Kapitän der\nBlackbeard\nPiraten.\nGesucht für\nPiraterie\nund Pokémon-Diebstahl."),
    PSTRING("Captain of the Blackbeard\npirates. Wanted for\npiracy and Pokémon-\ntheft."));

static u8 str_rin[] = LANGDEP(PSTRING("Rin"), PSTRING("Rin"));
static u8 str_mistral[] = LANGDEP(PSTRING("Mistral"), PSTRING("Mistral"));
static u8 str_lucius[] = LANGDEP(PSTRING("Lucius"), PSTRING("Lucius"));
static u8 str_lucky[] = LANGDEP(PSTRING("Lucky"), PSTRING("Lucky"));
static u8 str_albus[] = LANGDEP(PSTRING("Albus"), PSTRING("Albus"));
static u8 str_blackbeard[] = LANGDEP(PSTRING("Blackbeard"), PSTRING("Blackbeard"));

static wanted_poster_t wanted_posters[] = {
    {.name = str_rin,
     .description = str_rin_description,
     .tiles = gfx_mug_rinTiles,
     .palette = gfx_mug_rinPal},
    {.name = str_mistral,
     .description = str_mistral_description,
     .tiles = gfx_mug_mistralTiles,
     .palette = gfx_mug_mistralPal},
    {
        .name = str_lucius,
        .description = str_lucius_description,
        .tiles = gfx_mug_luciusTiles,
        .palette = gfx_mug_luciusPal,
        .flag = 0xFFFF,
    },
    {.name = str_lucky,
     .description = str_lucky_description,
     .tiles = gfx_mug_luckyTiles,
     .palette = gfx_mug_luckyPal},
    {.name = str_albus,
     .description = str_albus_description,
     .tiles = gfx_mug_albusTiles,
     .palette = gfx_mug_albusPal},
    {.name = str_blackbeard,
     .description = str_blackbeard_description,
     .tiles = gfx_mug_blackbeardTiles,
     .palette = gfx_mug_blackbeardPal},
};

static sprite mugshot_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(0)};

static oam_template mugshot_template = {
    .tiles_tag = OAM_TAG_WANTED_POSTER,
    .pal_tag = OAM_TAG_WANTED_POSTER,
    .graphics = NULL,
    .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
    .oam = &mugshot_sprite,
};

static void wanted_posters_item_print_callback(u8 tbox_idx, int idx, u8 y) {
    (void)(tbox_idx);
    (void)(idx);
    (void)y;
}

static list_menu_template wanted_posters_list_menu_template = {
    .items = NULL,
    .cursor_moved_callback = list_menu_generic_cursor_callback,
    .item_print_callback = wanted_posters_item_print_callback,
    .item_cnt = 255,
    .max_items_showed = 255,
    .tbox_idx = 255,
    .header_x = 0,
    .item_x = 8,
    .cursor_x = 0,
    .up_text_y = 0,
    .cursor_pal = 2,
    .fill_value = 1,
    .cursor_shadow_color = 3,
    .letter_spacing = 1,
    .item_vertical_padding = 2,
    .scroll_multiple = 0,
    .font = 2};

#define t_list_menu_tbox_idx params[0]
#define t_list_menu_cb_idx params[1]
#define t_list_menu_items params[2]
#define t_list_menu_items_2 params[3]
#define t_list_current_idx params[4]
#define t_description_tbox_idx params[5]
#define t_mugshot_oam_idx params[6]
#define t_scroll_indicator_cb_idx params[7]
#define t_list_cursor_position params[8]

static tbox_font_colormap description_fontcolmap = {0, 2, 1, 0};

static void mugshot_oam_callback_update(oam_object *self) {
    u16 idx = self->private[1];
    switch (self->private[0]) {
        case 0: {
            self->flags |= OAM_FLAG_INVISIBLE;
            break;
            case 1: {
                u16 flag = wanted_posters[idx].flag;
                if (flag == 0xFFFF || (flag && !checkflag(flag))) {
                    memset(pals + 256 + 16 * oam_palette_get_index(OAM_TAG_WANTED_POSTER), 0, 16 * sizeof(color_t));
                    memset(pal_restore + 256 + 16 * oam_palette_get_index(OAM_TAG_WANTED_POSTER), 0, 16 * sizeof(color_t));
                } else {
                    pal_decompress(wanted_posters[idx].palette, (u16)(256 + 16 * oam_palette_get_index(OAM_TAG_WANTED_POSTER)), 16 * sizeof(color_t));
                }
                lz77uncompwram(wanted_posters[idx].tiles, gp_tmp_buf);
                cpufastset(gp_tmp_buf, OAMCHARBASE(oam_vram_get_tile(OAM_TAG_WANTED_POSTER)), CPUFASTSET_COPY | CPUFASTSET_SIZE(GRAPHIC_SIZE_4BPP(64, 64)));
                break;
            }
            case 2:
                break;
            case 3:
                self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
                self->callback = oam_null_callback;
                return;
        }
    }
    self->private[0]++;
}

static void wanted_posters_callback(u8 self) {
    (void)self;
    u8 list_menu_cb_idx = (u8)big_callbacks[self].t_list_menu_cb_idx;
    int pressed_item = list_menu_process_input(list_menu_cb_idx);
    u16 scroll = 0;
    u16 above = 0;
    if (pressed_item == LIST_MENU_B_PRESSED) {
        play_sound(5);
        list_menu_remove(list_menu_cb_idx, &scroll, &above);
        tbox_flush_set((u8)big_callbacks[self].t_description_tbox_idx, 0x0);
        tbox_flush_map((u8)big_callbacks[self].t_description_tbox_idx);
        tbox_flush_set((u8)big_callbacks[self].t_list_menu_tbox_idx, 0x0);
        tbox_flush_map((u8)big_callbacks[self].t_list_menu_tbox_idx);
        bg_virtual_sync(0);
        scroll_indicator_delete((u8)big_callbacks[self].t_scroll_indicator_cb_idx);
        oam_free(oams + big_callbacks[self].t_mugshot_oam_idx);
        overworld_script_resume();
        big_callback_delete(self);
    } else {
        list_menu_get_scroll_and_row(list_menu_cb_idx, &scroll, &above);
        big_callbacks[self].t_list_cursor_position = (u16)(scroll);
        list_menu_item *items = (list_menu_item *)big_callback_get_int(self, 2);
        int idx = items[scroll + above].idx - 1;
        if (big_callbacks[self].t_list_current_idx != idx) {
            big_callbacks[self].t_list_current_idx = (u16)idx;
            u8 tbox_idx_description = (u8)big_callbacks[self].t_description_tbox_idx;
            tbox_flush_set(tbox_idx_description, 0x11);
            tbox_print_string(tbox_idx_description, 2, 4, 6, 0, 0, &description_fontcolmap, 0, wanted_posters[idx].description);
            oam_object *mugshot_oam = oams + big_callbacks[self].t_mugshot_oam_idx;
            mugshot_oam->private[0] = 0;
            mugshot_oam->private[1] = (u16)idx;
            mugshot_oam->callback = mugshot_oam_callback_update;
        }
    }
}

static tboxdata description_boxdata = {
    .bg_id = 0,
    .x = 11,
    .y = 1,
    .w = 18,
    .h = 12,
    .pal = 15,
    .start_tile = 176,
};

static u8 str_unknown[] = PSTRING("?????");

void map_orina_city_wanted_posters() {
    overworld_script_halt();
    gp_list_menu_template = wanted_posters_list_menu_template;
    gp_list_menu_template.item_cnt = ARRAY_COUNT(wanted_posters);
    gp_list_menu_template.max_items_showed = 6;
    list_menu_item *items = malloc_and_clear(ARRAY_COUNT(wanted_posters) * sizeof(list_menu_item));
    for (u8 i = 0; i < ARRAY_COUNT(wanted_posters); i++) {
        u16 flag = wanted_posters[i].flag;
        if (flag == 0xFFFF || (flag & !checkflag(flag))) {
            items[i].text = str_unknown;
        } else {
            items[i].text = wanted_posters[i].name;
        }
        items[i].idx = i + 1;
    }
    gp_list_menu_template.items = items;
    u8 tbox_idx_list = tbox_new_by_box(0, 0, 9, (u8)(2 * gp_list_menu_template.max_items_showed));
    u8 tbox_idx_description = tbox_new(&description_boxdata);
    tbox_tilemap_draw(tbox_idx_description);
    gp_list_menu_template.tbox_idx = tbox_idx_list;
    tbox_tilemap_draw(tbox_idx_list);
    u8 list_menu_cb_idx = list_menu_new(&gp_list_menu_template, 0, 0);
    bg_virtual_sync(0);

    oam_allocate_palette(OAM_TAG_WANTED_POSTER);
    oam_vram_allocation_table_add(OAM_TAG_WANTED_POSTER, oam_vram_alloc(64), 64);

    u8 cb_idx = big_callback_new(wanted_posters_callback, 0);
    big_callbacks[cb_idx].t_list_menu_tbox_idx = tbox_idx_list;
    big_callbacks[cb_idx].t_list_menu_cb_idx = list_menu_cb_idx;
    big_callback_set_int(cb_idx, 2, (int)items);
    big_callbacks[cb_idx].t_list_current_idx = 0xff;
    big_callbacks[cb_idx].t_description_tbox_idx = tbox_idx_description;
    big_callbacks[cb_idx].t_mugshot_oam_idx = oam_new_forward_search(&mugshot_template, 196, 44, 0);
    oams[big_callbacks[cb_idx].t_mugshot_oam_idx].flags |= OAM_FLAG_INVISIBLE;

    scroll_indicator_template indicator_template = {
        .arrow0_type = SCROLL_ARROW_UP,
        .arrow0_x = 8 + (9 * 8 / 2),
        .arrow0_y = 8,
        .arrow1_type = SCROLL_ARROW_DOWN,
        .arrow1_x = 8 + (9 * 8 / 2),
        .arrow1_y = (u8)(8 + 16 * gp_list_menu_template.max_items_showed),
        .arrow0_threshold = 0,
        .arrow1_threshold = (u16)MAX(0, ((int)ARRAY_COUNT(wanted_posters) -
                                         gp_list_menu_template.max_items_showed)),
        .tiles_tag = 111,
        .pal_tag = 111,
    };
    big_callbacks[cb_idx].t_scroll_indicator_cb_idx = scroll_indicator_new(&indicator_template,
                                                                           &big_callbacks[cb_idx].t_list_cursor_position);
}
