

#include "types.h"
#include "stdbool.h"
#include "pokepad/pokepad2.h"
#include "pokepad/pokedex/gui.h"
#include "pokepad/pokedex/operator.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "fading.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "language.h"
#include "io.h"
#include "flags.h"
#include "vars.h"
#include "music.h"
#include "bios.h"
#include "agbmemory.h"
#include "overworld/map_control.h"
#include "pokepad/pokedex/state.h"
#include "pokepad/pokedex/pages/flavor_text.h"
#include "dma.h"
#include "menu_indicators.h"
#include "pokemon/names.h"
#include "abilities.h"
#include "item/pokeball.h"
#include "pokemon/cry.h"

extern const u8 gfx_pokedex_formsTiles[13 * GRAPHIC_SIZE_4BPP(32, 32)];
extern const LZ77COMPRESSED gfx_pokedex_formsPal;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_flavor_text_heartTiles;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_flavor_text_heartPal;

static const sprite sprite_form = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)};
static const sprite sprite_16_16 = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)};

static const graphic graphic_heart = {
    .sprite = gfx_pokedex_entry_page_flavor_text_heartTiles, .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = POKEDEX_ENTRY_GFX_TAG_HEART
};

static const graphic graphic_pokeball = {
    .sprite = gfx_pokeball_pokeTiles, .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = POKEDEX_ENTRY_GFX_TAG_POKEBALL
};


static const graphic form_graphics[] = {
    GRAPHIC_ARRAY_4BPP(0, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(1, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(2, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(3, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(4, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(5, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(6, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(7, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(8, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(9, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(10, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(11, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(12, gfx_pokedex_formsTiles, 32, 32),
    GRAPHIC_ARRAY_4BPP(13, gfx_pokedex_formsTiles, 32, 32),
};

static const gfx_frame form_animation[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 1, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 2, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 3, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 5, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 6, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 7, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 8, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 9, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 10, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 11, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 12, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 13, .duration = 0}, {.data = GFX_ANIM_END},
};

static const gfx_frame *const form_animations[] = {
    form_animation + 0 * 2,
    form_animation + 1 * 2,
    form_animation + 2 * 2,
    form_animation + 3 * 2,
    form_animation + 4 * 2,
    form_animation + 5 * 2,
    form_animation + 6 * 2,
    form_animation + 7 * 2,
    form_animation + 8 * 2,
    form_animation + 9 * 2,
    form_animation + 10 * 2,
    form_animation + 11 * 2,
    form_animation + 12 * 2,
    form_animation + 13 * 2,
};

static const oam_template oam_template_form = {
    .tiles_tag = 0xFFFF, .pal_tag = POKEDEX_ENTRY_GFX_TAG_FORM,
    .oam = &sprite_form, .animation = form_animations, .graphics = form_graphics,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_egg = {
    .tiles_tag = POKEDEX_ENTRY_GFX_TAG_EGG, .pal_tag = POKEDEX_ENTRY_GFX_TAG_EGG,
    .oam = &sprite_form, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_pokeball = {
    .tiles_tag = POKEDEX_ENTRY_GFX_TAG_POKEBALL, .pal_tag = POKEDEX_ENTRY_GFX_TAG_POKEBALL,
    .oam = &sprite_16_16, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const oam_template oam_template_heart = {
    .tiles_tag = POKEDEX_ENTRY_GFX_TAG_HEART, .pal_tag = POKEDEX_ENTRY_GFX_TAG_HEART,
    .oam = &sprite_16_16, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};

static const tboxdata pokedex_entry_tboxes[NUM_POKEDEX_ENTRY_TBOXES + 1] = {
    [POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA] = {.bg_id = 0, .x = 9, .y = 3, .w = 21, .h = 11, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE},
    [POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT] = {.bg_id = 0, .x = 9, .y = 14, .w = 21, .h = 6, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 21 * 11},
    [NUM_POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOXES] = {.bg_id = 0xFF},
};

static const u8 str_size[] = LANGDEP(PSTRING("Größe"), PSTRING("Size"));
static const u8 str_weight[] = LANGDEP(PSTRING("Gew."), PSTRING("Weight"));
static const u8 str_color[] = LANGDEP(PSTRING("Farbe"), PSTRING("Color"));
static const u8 str_size_value[] = PSTRING("BUFFER_1,BUFFER_2m");
static const u8 str_kg_value[] = PSTRING("BUFFER_1,BUFFER_2kg");
static const u8 str_abilities[] = LANGDEP(PSTRING("Fähigkeiten"), PSTRING("Abilities"));
static const u8 str_hidden_ability[] = PSTRING("(BUFFER_1)");
static const u8 str_form[] = LANGDEP(PSTRING("Form"), PSTRING("Form"));
static const u8 str_cry[] = LANGDEP(PSTRING("KEY_STARTSKIP\x01Ruf"), PSTRING("KEY_STARTSKIP\x01Cry"));
static const u8 str_cry_not_caught[] = LANGDEP(PSTRING("Ruf ???"), PSTRING("Cry ???"));
static const u8 str_catch_rate[] = PSTRING("BUFFER_1,BUFFER_2%");
static const u8 str_male[] = PSTRING("FONT_SIZE_BIGCOLOR\x0DSHADOW\x0E♂FONT_SIZE_SMALLCOLOR\x01SHADOW\x02");
static const u8 str_female[] = PSTRING("FONT_SIZE_BIGCOLOR\x05SHADOW\x04♀FONT_SIZE_SMALLCOLOR\x01SHADOW\x02");
static const u8 str_gender_ratio[] = PSTRING("BUFFER_1SKIP\x02BUFFER_2,BUFFER_3%");
static const u8 str_gender_ratio_100_percent[] = PSTRING("BUFFER_1SKIP\x02BUFFER_2%");
static const u8 str_gender_ratio_none[] = PSTRING("BUFFER_1SKIP\x01/SKIP\x01BUFFER_2SKIP\x02--");
static const u8 str_gender_ratio_not_caught[] = PSTRING("BUFFER_1SKIP\x01/SKIP\x01BUFFER_2SKIP\x02??");
static const u8 str_unkown[] = PSTRING("???");

static const tbox_font_colormap tbox_font_colormap_white = {.background = 0, .body = 1, .edge = 2};
static const tbox_font_colormap tbox_font_colormap_black = {.background = 0, .body = 2, .edge = 3};
static const tbox_font_colormap tbox_font_colormap_green = {.background = 0, .body = 7, .edge = 6};

static void pokedex_entry_page_flavor_text_update_flavor_text() {
    tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT], 0x00);
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
    if (caught) {
        const u8 *text = pokedex_entries[pokedex_get_id(pokedex_entry_state->species)].page0;
        for (u16 lines_to_skip = pokedex_entry_state->page_flavor_text_first_line; 
                lines_to_skip > 0 && *text != 0xFF;) {
            if (*text == 0xFE)
                lines_to_skip--;
            text++;
        }
        u8 *dst = strbuf;
        size_t num_lines = 0;
        while (true) {
            if (*text == 0xFE) {
                num_lines++;
                if (num_lines < POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_NUM_VISIBLE_LINES) {
                    *dst++ = *text++;
                } else {
                    *dst++ = 0xFF;
                    break;
                }
            } else if (*text == 0xFF) {
                *dst++ = 0xFF;
                break;
            } else {
                *dst++ = *text++;
            }
        }
        tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT], 0, 3, 3, 0, 0,
            &tbox_font_colormap_black, 0, strbuf);
    } else {
        tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT], 0, 3 + 4 * 20 - 2, 3 + 16, 0, 0,
            &tbox_font_colormap_black, 0, str_unkown);
    }
}

bool pokedex_entry_page_flavor_text_setup() {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->page_flavor_text_num_lines = 1;
            pokedex_entry_state->page_flavor_text_first_line = 0;
            const u8 *str_flavor_text = pokedex_entries[pokedex_get_id(pokedex_entry_state->species)].page0;
            for (int i = 0; str_flavor_text[i] != 0xFF; i++) {
                if (str_flavor_text[i] == 0xFE)
                    pokedex_entry_state->page_flavor_text_num_lines++;
            }
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_TBOXES:
            pokedex_entry_page_initialize_tboxes(pokedex_entry_tboxes);
            tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA], 0x00);
            tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA]);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 3, 4 + 0, 0, 0, &tbox_font_colormap_white, 0xFF, str_size); 
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 3, 4 + 16, 0, 0, &tbox_font_colormap_white, 0xFF, str_weight); 
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 3, 4 + 32, 0, 0, &tbox_font_colormap_white, 0xFF, str_color);
            u16 dex_id = pokedex_get_id(pokedex_entry_state->species);
            itoa(buffer0, pokedex_entries[dex_id].height / 10, ITOA_PAD_SPACES, 3);
            itoa(buffer1, pokedex_entries[dex_id].height % 10, ITOA_PAD_SPACES, 1);
            string_decrypt(strbuf, str_size_value);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 47, 4 + 0, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_unkown);
            itoa(buffer0, pokedex_entries[dex_id].weight / 10, ITOA_PAD_SPACES, 3);
            itoa(buffer1, pokedex_entries[dex_id].weight % 10, ITOA_PAD_SPACES, 1);
            string_decrypt(strbuf, str_kg_value);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 47, 4 + 16, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_unkown);

            const u8 *str_color = caught ? pokemon_color_names[basestats[pokedex_entry_state->species].color] : str_unkown;
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, (u16)(43 + (48 - string_get_width(2, str_color, 0)) / 2),
                4 + 32, 0, 0, &tbox_font_colormap_white, 0xFF, str_color);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 96, 4 + 0, 0, 0, &tbox_font_colormap_white, 0xFF, str_abilities
                );

            // Abilities
            if (caught) {
                size_t num_abilities_displayed = 0;
                tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                    0, 96, (u16)(2 + 16 + (11 * num_abilities_displayed++)), 0, 0, 
                    &tbox_font_colormap_white, 0xFF, ability_names[basestats[pokedex_entry_state->species].ability1]);
                if (basestats[pokedex_entry_state->species].ability2 && 
                    basestats[pokedex_entry_state->species].ability1 != basestats[pokedex_entry_state->species].ability2)
                    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                        0, 96, (u16)(2 + 16 + (11 * num_abilities_displayed++)), 0, 0, 
                        &tbox_font_colormap_white, 0xFF, ability_names[basestats[pokedex_entry_state->species].ability2]);
                if (basestats[pokedex_entry_state->species].hidden_ability) {
                    strcpy(buffer0, ability_names[basestats[pokedex_entry_state->species].hidden_ability]);
                    string_decrypt(strbuf, str_hidden_ability);
                    tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                        0, 96, (u16)(2 + 16 + (11 * num_abilities_displayed++)), 0, 0, 
                        &tbox_font_colormap_green, 0xFF, strbuf);
                }
            } else {
                tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                    0, 96, (u16)(2 + 16), 0, 0, &tbox_font_colormap_white, 0xFF, str_unkown);
            }
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, 3, 56 + 0, 0, 0, &tbox_font_colormap_white, 0xFF, str_form); 
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                2, (u16)(3 + (42 - string_get_width(2, str_cry, 0)) / 2), 
                56 + 16, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? str_cry : str_cry_not_caught); 
            
            itoa(strbuf, basestats[pokedex_entry_state->species].egg_cycles * 256, ITOA_NO_PADDING, 5);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                0, 98, 56, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_unkown);
            int catch_success_promille = 1000 * basestats[pokedex_entry_state->species].catch_rate / 255 / 3;
            itoa(buffer0, catch_success_promille / 10, ITOA_NO_PADDING, 2);
            itoa(buffer1, catch_success_promille % 10, ITOA_NO_PADDING, 1);
            string_decrypt(strbuf, str_catch_rate);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                0, 98, 71, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_unkown);
            itoa(strbuf, basestats[pokedex_entry_state->species].base_happiness, ITOA_NO_PADDING, 3);
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                0, 138, 56, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_unkown);
            // Print the gender
            int prob_female = basestats[pokedex_entry_state->species].gender_value;
            switch (prob_female) {
                case POKEMON_GENDER_MALE:
                    prob_female = 0;
                    break;
                case POKEMON_GENDER_FEMALE:
                    prob_female = 256;
                    break;
            }
            if (basestats[pokedex_entry_state->species].gender_value == POKEMON_GENDER_GENDERLESS) {
                strcpy(buffer0, str_male);
                strcpy(buffer1, str_female);
                string_decrypt(strbuf, str_gender_ratio_none);
            } else {
                prob_female = 1000 * prob_female / 256;
                int prob_male = 1000 - prob_female;
                int prob = MAX(prob_male, prob_female);
                strcpy(buffer0, prob_male >= prob_female ? str_male : str_female);
                itoa(buffer1, prob / 10, ITOA_NO_PADDING, 3);
                itoa(buffer2, prob % 10, ITOA_NO_PADDING, 1);
                string_decrypt(strbuf, prob < 1000 ? str_gender_ratio : str_gender_ratio_100_percent);
                
            }
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA],
                0, 128, 71, 0, 0, &tbox_font_colormap_white, 0xFF, caught ? strbuf : str_gender_ratio_not_caught);

            tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA], TBOX_SYNC_SET);
            tbox_tilemap_draw(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT]);
            pokedex_entry_page_flavor_text_update_flavor_text();
            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_OAM:
            pal_decompress(gfx_pokedex_entry_page_flavor_text_heartPal, (u16)(256 + 16 * oam_allocate_palette(POKEDEX_ENTRY_GFX_TAG_HEART)), 16 * sizeof(color_t));
            pal_decompress(gfx_pokeball_pokePal, (u16)(256 + 16 * oam_allocate_palette(POKEDEX_ENTRY_GFX_TAG_POKEBALL)), 16 * sizeof(color_t));
            pal_copy(icon_pals[1], (u16)(256 + 16 * oam_allocate_palette(POKEDEX_ENTRY_GFX_TAG_EGG)), 16 * sizeof(color_t));
            pal_decompress(gfx_pokedex_formsPal, (u16)(256 + 16 * oam_allocate_palette(POKEDEX_ENTRY_GFX_TAG_FORM)), 16 * sizeof(color_t));
            u16 base_tile_egg = oam_vram_alloc(GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
            oam_vram_allocation_table_add(POKEDEX_ENTRY_GFX_TAG_EGG, base_tile_egg, GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
            cpuset(pokemon_icons[POKEMON_EGG], OAMCHARBASE(base_tile_egg), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 32)));
            oam_load_graphic(&graphic_heart);
            oam_load_graphic(&graphic_pokeball);
            pokedex_entry_state->page_flavor_text_form_oam_idx = oam_new_forward_search(&oam_template_form, 137, 96, 0);
            if (!caught)
                oams[pokedex_entry_state->page_flavor_text_form_oam_idx].flags |= OAM_FLAG_INVISIBLE;
            oam_gfx_anim_start_if_not_current(oams + pokedex_entry_state->page_flavor_text_form_oam_idx, (u8)basestats[pokedex_entry_state->species].form);
            pokedex_entry_state->page_flavor_text_egg_oam_idx = oam_new_forward_search(&oam_template_egg, 162, 84, 0);
            pokedex_entry_state->page_flavor_text_pokeball_oam_idx = oam_new_forward_search(&oam_template_pokeball, 162, 102, 0);
            pokedex_entry_state->page_flavor_text_heart_oam_idx = oam_new_forward_search(&oam_template_heart, 204, 88, 0);
            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            if (caught) {
                scroll_indicator_template template = {
                    .arrow0_threshold = 0, 
                    .arrow1_threshold = (u16)MAX(0, pokedex_entry_state->page_flavor_text_num_lines - POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_NUM_VISIBLE_LINES), 
                    .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
                    .arrow0_x = 156, .arrow1_x = 156,
                    .arrow0_y = 113, .arrow1_y = 157,
                    .pal_tag = 112, .tiles_tag = 112,
                };
                pokedex_entry_state->page_flavor_text_scroll_indicators_cb_idx = scroll_indicator_new(&template, &pokedex_entry_state->page_flavor_text_first_line);
            } else {
                pokedex_entry_state->page_flavor_text_scroll_indicators_cb_idx = 0xFF;
            }
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        default:
            return false;
    }
    return true;
}

void pokedex_entry_page_flavor_text_destroy() {
    pokedex_entry_page_free_tboxes();
    if (pokedex_entry_state->page_flavor_text_scroll_indicators_cb_idx != 0xFF)
        scroll_indicator_delete(pokedex_entry_state->page_flavor_text_scroll_indicators_cb_idx);
    oam_free(oams + pokedex_entry_state->page_flavor_text_egg_oam_idx);
    oam_free(oams + pokedex_entry_state->page_flavor_text_pokeball_oam_idx);
    oam_free(oams + pokedex_entry_state->page_flavor_text_heart_oam_idx);
    oam_free(oams + pokedex_entry_state->page_flavor_text_form_oam_idx);
}

static void pokedex_entry_page_flavor_text_wait_cry(u8 self) {
    if (fading_control.active || dma3_busy(-1))
        return;
    if (super.keys_new_and_repeated.keys.start) {
        // Allow to re-play the cry
        pokemon_play_cry(pokedex_entry_state->species, 0);
    }
    if (cry_has_finished()) {
        big_callback_set_function_to_continuation(self);
    }
}

bool pokedex_entry_page_flavor_text_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
    if (super.keys_new_and_repeated.keys.up && caught && pokedex_entry_state->page_flavor_text_first_line > 0) {
        pokedex_entry_state->page_flavor_text_first_line--;
        pokedex_entry_page_flavor_text_update_flavor_text();
        return true;
    } else if (super.keys_new_and_repeated.keys.down && caught &&
        pokedex_entry_state->page_flavor_text_first_line < pokedex_entry_state->page_flavor_text_num_lines - POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_NUM_VISIBLE_LINES) {
        pokedex_entry_state->page_flavor_text_first_line++;
        pokedex_entry_page_flavor_text_update_flavor_text();
        return true;
    } else if (super.keys_new.keys.start && caught) {
        pokemon_play_cry(pokedex_entry_state->species, 0);
        big_callback_set_function_and_continuation(self, pokedex_entry_page_flavor_text_wait_cry, big_callbacks[self].function);
    }
    return false;
}