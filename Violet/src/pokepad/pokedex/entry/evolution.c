

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
#include "pokepad/pokedex/pages/evolution.h"
#include "dma.h"
#include "menu_indicators.h"
#include "pokemon/names.h"
#include "abilities.h"
#include "item/pokeball.h"
#include "pokemon/cry.h"
#include "constants/egg_groups.h"
#include "pokemon/evolution.h"
#include "constants/evolution_methods.h"
#include "mega.h"
#include "pokemon/breeding.h"
#include "item/item.h"
#include "attack.h"
#include "map/namespace.h"

extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_ui_tboxTiles;
extern const bg_tile gfx_pokedex_entry_page_evolution_ui_tboxMap[7];

enum {
    TBOX_UPPER_LEFT = 0,
    TBOX_UPPER,
    TBOX_UPPER_RIGHT,
    TBOX_CENTER_RIGHT,
    TBOX_CENTER,
    TBOX_LOWER_LEFT,
    TBOX_LOWER_RIGHT,
    TBOX_OUTSIDE,
};



static void pokedex_entry_page_evolution_dfs(size_t depth, u16 species) {
    DEBUG("Species %d, depth %d\n", species, depth);
    if (depth > 4)
        ERROR("Evolution tree depth exceeded at species %d with depth %d\n", species, depth);
    const pokemon_evolution *evolutions = pokemon_evolutions[species];
    if (evolutions) {
        for (int i = 0; evolutions[i].method != EVOLUTION_METHOD_NONE; i++) {
            pokedex_entry_state->evolution_tree[pokedex_entry_state->evolution_tree_size++] = (pokedex_entry_evolution_tree_node_t) {
                .species = evolutions[i].target,
                .argument = evolutions[i].condition,
                .method = evolutions[i].method,
                .indent = (u8)((depth) & 0xF),
            };
            pokedex_entry_page_evolution_dfs(depth + 1, evolutions[i].target);
        }
    }
    // Record mega evolutions also as an evolution
    const mega_evolution_t *mega = mega_evolution_get_by_species(species);
    if (mega) {
        pokedex_entry_state->evolution_tree[pokedex_entry_state->evolution_tree_size++] = (pokedex_entry_evolution_tree_node_t) {
            .species = mega->mega_species,
            .argument = mega->mega_item,
            .indent = (u8)((depth) & 0xF),
            .is_mega = true,
        };
    }
}

static void pokedex_entry_page_evolution_tree_setup() {
    pokedex_entry_state->evolution_tree_size = 0;
    u16 root = pokemon_get_basis_stage(pokedex_entry_state->species);
    u16 egg_group_species = root;
    u16 breeding_item = 0;
    for (size_t i = 0; baby_pokemon[i].baby_species != 0xFFFF; i++) {
        if (baby_pokemon[i].baby_species == root) {
            egg_group_species = baby_pokemon[i].parent_species;
            breeding_item = baby_pokemon[i].breeding_item;
            break;
        }
    }
    DEBUG("Root: %d, egg group species: %d, breeding item: %d\n", root, egg_group_species, breeding_item);
    u8 egg_group_1 = basestats[egg_group_species].egg_group_1;
    u8 egg_group_2 = basestats[egg_group_species].egg_group_2;
    DEBUG("Egg group 1: %d, egg group 2: %d\n", egg_group_1, egg_group_2);
    bool hatches_from_egg = (egg_group_1 != EGG_GROUP_NONE && egg_group_1 != EGG_GROUP_UNBEKANNT) || 
        (egg_group_2 != EGG_GROUP_NONE && egg_group_2 != EGG_GROUP_UNBEKANNT);
    if (hatches_from_egg) {
        pokedex_entry_state->evolution_tree[pokedex_entry_state->evolution_tree_size++] = (pokedex_entry_evolution_tree_node_t) {
            .species = egg_group_species,
            .is_egg = true
        };
    }
    pokedex_entry_state->evolution_tree[pokedex_entry_state->evolution_tree_size++] = (pokedex_entry_evolution_tree_node_t) {
        .species = root,
        .argument = breeding_item,
        .method = EVOLUTION_METHOD_NONE,
        .hatches_from_egg = hatches_from_egg,
    };
    pokedex_entry_page_evolution_dfs(1, root);
    pokedex_entry_state->evolution_tree_any_caught = false;
    for (size_t i = 0; i < pokedex_entry_state->evolution_tree_size; i++) {
        if (pokedex_entry_state->evolution_tree[i].is_egg)
            continue;
        if (pokedex_operator(pokedex_entry_state->evolution_tree[i].species, POKEDEX_GET | POKEDEX_CAUGHT, true)) {
            pokedex_entry_state->evolution_tree_any_caught = true;
            break;
        }
    }
}

static inline void pokedex_entry_page_evolution_clear_box(u8 layer, int y) {
    for (int i = 0; i < 4; i++) {
        for (int x = 9; x < 30; x++) {
            pokedex_entry_state->bg_maps[2 + layer][y + i][x] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_OUTSIDE);
        }
    }
}

static inline void pokedex_entry_page_evolution_draw_box(u8 layer, int y, int indent) {
    for (int x = 9; x < 9 + indent; x++)
        for (int j = 0; j < 4; j++)
            pokedex_entry_state->bg_maps[2 + layer][y + j][x] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_OUTSIDE);
    pokedex_entry_state->bg_maps[2 + layer][y][9 + indent] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_UPPER_LEFT);
    for (int x = 9 + indent + 1; x < 30 - 1; x++)
        pokedex_entry_state->bg_maps[2 + layer][y][x] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_UPPER);
    pokedex_entry_state->bg_maps[2 + layer][y][30 - 1] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_UPPER_RIGHT);
    for (int j = 0; j < 2; j++) {
        for (int x = 9 + indent; x < 30 - 1; x++)
            pokedex_entry_state->bg_maps[2 + layer][y + 1 + j][x] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_CENTER);
        pokedex_entry_state->bg_maps[2 + layer][y + 1 + j][30 - 1] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_CENTER_RIGHT);
    }
    pokedex_entry_state->bg_maps[2 + layer][y + 3][9 + indent] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_LOWER_LEFT);
    for (int x = 9 + indent + 1; x < 30 - 1; x++)
        pokedex_entry_state->bg_maps[2 + layer][y + 3][x] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_CENTER);
    pokedex_entry_state->bg_maps[2 + layer][y + 3][30 - 1] = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer, TBOX_LOWER_RIGHT);
}

static void pokedex_entry_page_evolution_draw_boxes(u8 layer) {
    for (int idx = 0; idx < 4; idx++) {
        int line = pokedex_entry_state->evolution_tree_cursor + idx;
        if (line < pokedex_entry_state->evolution_tree_size) {
            pokedex_entry_page_evolution_draw_box(layer, 3 + 4 * idx, pokedex_entry_state->evolution_tree[line].indent);
        } else {
            pokedex_entry_page_evolution_clear_box(layer, 3 + 4 * idx);
        }
    }
    bg_virtual_sync_reqeust_push((u8)(2 + pokedex_entry_state->page_layer));
}

void pokedex_entry_page_evolution_setup_bg(u8 layer) {
    lz77uncompvram(gfx_pokedex_entry_page_evolution_uiTiles, CHARBASE_PLUS_OFFSET_4BPP(1, POKEDEX_ENTRY_PAGE_EVOLUTION_BASE_TILE_UI(layer)));
    lz77uncompvram(gfx_pokedex_entry_page_evolution_ui_tboxTiles, CHARBASE_PLUS_OFFSET_4BPP(1, POKEDEX_ENTRY_PAGE_EVOLUTION_BASE_TILE_TBOX(layer)));
    lz77uncompwram(gfx_pokedex_entry_page_evolution_uiMap, pokedex_entry_state->bg_maps[2 + layer]);
    pal_decompress(gfx_pokedex_entry_page_evolution_uiPal, (u16)(16 * (2 + POKEDEX_ENTRY_PAGE_NUM_PALS * layer)), 16 * sizeof(color_t));
    // Shift the palette and tile indices of the map
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 30; x++) {
            bg_tile tile = pokedex_entry_state->bg_maps[2 + layer][y][x];
            tile.text.tile_number = (u16)((tile.text.tile_number + layer * POKEDEX_ENTRY_PAGE_NUM_TILES) & 0x3FF);
            tile.text.palette = (u16)((2 + layer * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF);
            pokedex_entry_state->bg_maps[2 + layer][y][x] = tile;
        }
    }
    // Building the tree here is a bit hacky, but the background requies it to be built correctly
    pokedex_entry_page_evolution_tree_setup();
    pokedex_entry_page_evolution_draw_boxes(layer);
}

static const sprite sprite_icon = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(0)};

static const gfx_frame gfx_animation_icon[] = {
    {.data = 0, .duration = 0}, 
    {.data = 0 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 32,},
    {.data = 1 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32), .duration = 32,},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static const gfx_frame *const gfx_animations_icon[] = {gfx_animation_icon};

static void pokedex_entry_page_evolution_update_icons() {
    for (size_t idx = 0; idx < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_oam_idxs); idx++) {
        size_t line = pokedex_entry_state->evolution_tree_cursor + idx;
        if (line < pokedex_entry_state->evolution_tree_size) {
            pokedex_entry_evolution_tree_node_t *node = &pokedex_entry_state->evolution_tree[line];
            bool caught;
            if (node->is_egg) {
                caught = true;
            } else if (node->is_mega) {
                const mega_evolution_t *mega = mega_evolution_get_by_mega_species(node->species);
                if (!mega)
                    ERROR("Could not find the mega entry of mega species %d\n", node->species);
                caught = pokedex_operator(mega->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
            } else {
                caught = pokedex_operator(node->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
            }
            u16 species = node->is_egg ? POKEMON_EGG : node->species;
            oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[idx]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            cpuset(pokemon_icons[species], OAMCHARBASE(pokedex_entry_state->evolution_tree_icon_base_tiles[idx]),
                CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(32, 32) * 2));
            oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[idx]].x = (s16)(8 * (11 + node->indent));
            u8 pal_idx = pokedex_entry_state->evolution_tree_icon_pal_idxs[caught ? pokemon_icon_usage[species] : 3];
            if (!pokedex_entry_state->evolution_tree_any_caught)
                pal_idx = pokedex_entry_state->evolution_tree_icon_pal_idxs[3];
            oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[idx]].final_oam.attr2 = (u16)(
                (oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[idx]].final_oam.attr2 & 0xFFF) | (pal_idx << 12)
            );
        } else {
            oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[idx]].flags |= OAM_FLAG_INVISIBLE;
        }
    }
}

static const tbox_font_colormap tbox_fontcolmap_white = {.background = 0, .body = 1, .edge = 2};
static const u8 str_question_mark[] = PSTRING("?????");
static const u8 str_pokemon_egg[] = LANGDEP(PSTRING("Pokémon-Ei"), PSTRING("Pokémon Egg"));
static const u8 str_mega[] = LANGDEP(PSTRING("Mega-BUFFER_1"), PSTRING("Mega BUFFER_1"));
static const u8 str_egg_groups[] = LANGDEP(PSTRING("Gruppe: "), PSTRING("Group: "));
static const u8 str_egg_group_comma[] = PSTRING(", ");
static const u8 str_number_unknown[] = PSTRING("???");
static const u8 str_name_with_number[] = PSTRING("FONT_SIZE_SMALLNr.BUFFER_1 FONT_SIZE_BIGBUFFER_2");
static const u8 str_hatches_from_egg[] = LANGDEP(PSTRING("Schlüpft aus Ei."), PSTRING("Hatches from Egg."));
static const u8 str_hatches_from_egg_with_item[] = LANGDEP(PSTRING("Zucht mit BUFFER_1."), PSTRING("Breeding with BUFFER_1."));
static const u8 str_mega_evolves[] = LANGDEP(PSTRING("Mit BUFFER_1."), PSTRING("With BUFFER_1."));
static const u8 str_evolution_method_none[] = PSTRING("???");
static const u8 str_evolution_method_friendship[] = LANGDEP(PSTRING("Zuneigung."), PSTRING("By Friendship."));
static const u8 str_evolution_method_friendship_day[] = LANGDEP(PSTRING("Zuneigung am Tag."), PSTRING("By Friendship at day."));
static const u8 str_evolution_method_friendship_night[] = LANGDEP(PSTRING("Zuneigung bei Nacht."), PSTRING("By Friendship at night."));
static const u8 str_evolution_method_level_up[] = LANGDEP(PSTRING("Auf Level BUFFER_1."), PSTRING("On level BUFFER_1."));
static const u8 str_evolution_method_item[] = LANGDEP(PSTRING("Mit BUFFER_1."), PSTRING("With BUFFER_1."));
static const u8 str_evolution_method_atk_gt_def[] = LANGDEP(PSTRING("Level BUFFER_1 & Angr. hoch."), PSTRING("Level BUFFER_1 & Atk. gt. Def."));
static const u8 str_evolution_method_def_gt_atk[] = LANGDEP(PSTRING("Level BUFFER_1 & Vert. hoch."), PSTRING("Level BUFFER_1 & Def. gt. Atk."));
static const u8 str_evolution_method_atk_eq_def[] = LANGDEP(PSTRING("Level BUFFER_1 & Angr. = Def."), PSTRING("Level BUFFER_1 & Atk. eq. Def."));
static const u8 str_evolution_method_pid[] = LANGDEP(PSTRING("Auf Level BUFFER_1 (50%)."), PSTRING("On level BUFFER_1, (50%)."));
static const u8 str_evolution_method_spawn_second[] = LANGDEP(PSTRING("Wenn Pokéball im Beutel."), PSTRING("If Pokéball in bag."));
static const u8 str_evolution_method_beauty[] = LANGDEP(PSTRING("Level-Up & Schönheit"), PSTRING("Level-Up & Beauty"));
static const u8 str_evolution_method_on_map[] = LANGDEP(PSTRING("Ort: BUFFER_1"), PSTRING("At: BUFFER_1"));
static const u8 str_evolution_method_hold_item[] = LANGDEP(PSTRING("BUFFER_1 (Tragen)."), PSTRING("BUFFER_1 (held)."));
static const u8 str_evolution_method_know_move[] = LANGDEP(PSTRING("BUFFER_1 kennen."), PSTRING("Know BUFFER_1."));
static const u8 str_evolution_method_link_cable_and_item[] = LANGDEP(PSTRING("BUFFER_1 & BUFFER_2."), PSTRING("BUFFER_1 & BUFFER_2."));
static const u8 str_evolution_method_male_and_stone[] = LANGDEP(PSTRING("♂ & BUFFER_1."), PSTRING("♂ & BUFFER_1."));
static const u8 str_evolution_method_hold_item_and_night[] = LANGDEP(PSTRING("Nacht & BUFFER_1"), PSTRING("Night & BUFFER_1"));
static const u8 str_evolution_method_female_and_stone[] = LANGDEP(PSTRING("♀ & BUFFER_1."), PSTRING("♀ & BUFFER_1."));
static const u8 str_evolution_method_hold_item_and_day[] = LANGDEP(PSTRING("Tag & BUFFER_1"), PSTRING("Day & BUFFER_1"));
static const u8 str_evolution_method_know_move_type[] = LANGDEP(PSTRING("BUFFER_1-Angriff kennen."), PSTRING("Know BUFFER_1 move."));
static const u8 str_evolution_method_female_and_level_up[] = LANGDEP(PSTRING("♀ & Level-Up"), PSTRING("♀ & Level-Up"));

static void pokedex_entry_page_evolution_update_method_text_evolution_none(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, str_evolution_method_none);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_friendship(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, str_evolution_method_friendship);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_friendship_day(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, str_evolution_method_friendship_day);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_friendship_night(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, str_evolution_method_friendship_night);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_item(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_item);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_atk_gt_def(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    itoa(buffer0, node->argument, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_evolution_method_atk_gt_def);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_def_gt_atk(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    itoa(buffer0, node->argument, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_evolution_method_def_gt_atk);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_atk_eq_def(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    itoa(buffer0, node->argument, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_evolution_method_atk_eq_def);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_pid(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    itoa(buffer0, node->argument, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_evolution_method_pid);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_level_up(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    itoa(buffer0, node->argument, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_evolution_method_level_up);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_spawn_second(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, str_evolution_method_spawn_second);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_beauty(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, str_evolution_method_beauty);
}
static void pokedex_entry_page_evolution_update_method_text_evolution_on_map(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    u8 bank = (u8)(node->argument & 0xFF);
    u8 map_idx = (u8)((node->argument >> 8) & 0xFF);
    const map_header_t *header = get_mapheader(bank, map_idx);
    if (!header)
        return;
    strcpy(buffer0, map_namespaces[MAP_NAMESPACE_TO_IDX(header->map_namespace)]);
    string_decrypt(strbuf, str_evolution_method_on_map);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_hold_item(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_hold_item);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_know_move(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, attack_names[node->argument]);
    string_decrypt(strbuf, str_evolution_method_know_move);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_link_cable_and_item(u8 tbox_idx ,pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[ITEM_LINKKABEL].name);
    strcpy(buffer1, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_link_cable_and_item);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_male_and_stone(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_male_and_stone);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_hold_item_and_night(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_hold_item_and_night);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_text_female_and_stone(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_female_and_stone);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_hold_item_and_day(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, items[node->argument].name);
    string_decrypt(strbuf, str_evolution_method_hold_item_and_day);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_update_method_know_move_type(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    strcpy(buffer0, str_pokemon_type_names[node->argument]);
    string_decrypt(strbuf, str_evolution_method_know_move_type);
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, strbuf);
}
static void pokedex_entry_page_evolution_female_and_level_up(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 1, &tbox_fontcolmap_white, 0, str_evolution_method_female_and_level_up);
}

static void (*const pokedex_entry_page_evolution_update_method_text_evolution[NUM_EVOLUTION_METHODS])(u8, pokedex_entry_evolution_tree_node_t *) = {
    [EVOLUTION_METHOD_NONE] = pokedex_entry_page_evolution_update_method_text_evolution_none,
    [EVOLUTION_METHOD_FRIENDSHIP] = pokedex_entry_page_evolution_update_method_text_evolution_friendship,
    [EVOLUTION_METHOD_FRIENDSHIP_DAY] = pokedex_entry_page_evolution_update_method_text_evolution_friendship_day,
    [EVOLUTION_METHOD_FRIENDSHIP_NIGHT] = pokedex_entry_page_evolution_update_method_text_evolution_friendship_night,
    [EVOLUTION_METHOD_LEVEL_UP] = pokedex_entry_page_evolution_update_method_text_evolution_level_up,
    [EVOLUTION_METHOD_STONE] = pokedex_entry_page_evolution_update_method_text_evolution_item,
    [EVOLUTION_METHOD_ATK_GT_DEF] = pokedex_entry_page_evolution_update_method_text_evolution_atk_gt_def,
    [EVOLUTION_METHOD_ATK_LT_DEF] = pokedex_entry_page_evolution_update_method_text_evolution_def_gt_atk,
    [EVOLUTION_METHOD_ATK_EQ_DEF] = pokedex_entry_page_evolution_update_method_text_evolution_atk_eq_def,
    [EVOLUTION_METHOD_PID_EVEN] = pokedex_entry_page_evolution_update_method_text_evolution_pid,
    [EVOLUTION_METHOD_PID_ODD] = pokedex_entry_page_evolution_update_method_text_evolution_pid,
    [EVOLUTION_METHOD_SPAWN_SECOND] = pokedex_entry_page_evolution_update_method_text_evolution_spawn_second,
    [EVOLUTION_METHOD_CREATE_SPAWN] = pokedex_entry_page_evolution_update_method_text_evolution_level_up,
    [EVOLUTION_METHOD_BEAUTY] = pokedex_entry_page_evolution_update_method_text_evolution_beauty,
    [EVOLUTION_METHOD_ON_MAP] = pokedex_entry_page_evolution_update_method_text_evolution_on_map,
    [EVOLUTION_METHOD_HOLD_ITEM] = pokedex_entry_page_evolution_update_method_text_hold_item,
    [EVOLUTION_METHOD_KNOW_MOVE] = pokedex_entry_page_evolution_update_method_text_know_move,
    [EVOLUTION_METHOD_LINK_CABLE_AND_ITEM] = pokedex_entry_page_evolution_update_method_text_link_cable_and_item,
    [EVOLUTION_METHOD_MALE_AND_STONE] = pokedex_entry_page_evolution_update_method_text_male_and_stone,
    [EVOLUTION_METHOD_HOLD_ITEM_AND_NIGHT] = pokedex_entry_page_evolution_update_method_text_hold_item_and_night,
    [EVOLUTION_METHOD_FEMALE_AND_STONE] = pokedex_entry_page_evolution_update_method_text_female_and_stone,
    [EVOLUTION_METHOD_HOLD_ITEM_AND_DAY] = pokedex_entry_page_evolution_update_method_hold_item_and_day,
    [EVOLUTION_METHOD_KNOW_MOVE_TYPE] = pokedex_entry_page_evolution_update_method_know_move_type,
    [EVOLUTION_METHOD_FEMALE_AND_LEVEL_UP] = pokedex_entry_page_evolution_female_and_level_up,
};

static void pokedex_entry_page_evolution_update_method_text(u8 tbox_idx, pokedex_entry_evolution_tree_node_t *node) {
    if (!pokedex_entry_state->evolution_tree_any_caught) {

    } else if (node->is_egg) {
        (void)pokedex_entry_page_evolution_update_method_text_evolution_pid;
        strbuf[0] = 0xFF;
        strcat(strbuf, str_egg_groups);
        u8 egg_group_1 = basestats[node->species].egg_group_1;
        u8 egg_group_2 = basestats[node->species].egg_group_2;
        if (egg_group_1 != EGG_GROUP_NONE && egg_group_1 != EGG_GROUP_UNBEKANNT) {
            strcat(strbuf, egg_group_names[egg_group_1]);
        }
        if (egg_group_2 != EGG_GROUP_NONE && egg_group_2 != EGG_GROUP_UNBEKANNT && egg_group_2 != egg_group_1) {
            strcat(strbuf, str_egg_group_comma);
            strcat(strbuf, egg_group_names[egg_group_2]);
        }
        tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf);    
    } else if (node->hatches_from_egg) {
        u16 breeding_item = node->argument;
        const u8 *str;
        if (breeding_item == 0) {
            str = str_hatches_from_egg;
        } else {
            strcpy(buffer0, items[breeding_item].name);
            string_decrypt(strbuf, str_hatches_from_egg_with_item);
            str = strbuf;
        }
        tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, str);  
    } else if (node->is_mega) {
        u16 mega_item = node->argument;
        strcpy(buffer0, items[mega_item].name);
        string_decrypt(strbuf, str_mega_evolves);
        tbox_print_string(tbox_idx, 0, (u16)(8 * node->indent), 16, 0, 0, &tbox_fontcolmap_white, 0, strbuf); 
    } else {
        if (pokedex_entry_page_evolution_update_method_text_evolution[node->method])
            pokedex_entry_page_evolution_update_method_text_evolution[node->method](tbox_idx, node);
    }
}


static void pokedex_entry_page_evolution_update_text() {
for (size_t idx = 0; idx < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_oam_idxs); idx++) {
        size_t line = pokedex_entry_state->evolution_tree_cursor + idx;
        tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + idx], 0x00);
        if (line < pokedex_entry_state->evolution_tree_size) {
           pokedex_entry_evolution_tree_node_t *node = &pokedex_entry_state->evolution_tree[line];
            bool caught, seen;
            u16 species;
            const u8 *str_name = str_question_mark;
            if (node->is_egg) {
                seen = true;
                caught = true;
                species = POKEMON_EGG;
                str_name = str_pokemon_egg;
            } else if (node->is_mega) {
                const mega_evolution_t *mega = mega_evolution_get_by_mega_species(node->species);
                if (!mega)
                    ERROR("Could not find the mega entry of mega species %d\n", node->species);
                seen = pokedex_operator(mega->species, POKEDEX_GET | POKEDEX_SEEN, true);
                caught = pokedex_operator(mega->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
                if (seen) {
                    strcpy(buffer0, pokemon_names[mega->species]);
                    string_decrypt(strbuf, str_mega);
                    str_name = strbuf;
                }
            } else {
                seen = pokedex_operator(node->species, POKEDEX_GET | POKEDEX_SEEN, true);
                caught = pokedex_operator(node->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
                species = node->species;
                if (seen) {
                    strcpy(buffer1, pokemon_names[species]);
                    itoa(buffer0, pokedex_get_id(species), ITOA_PAD_ZEROS, 3);
                    string_decrypt(strbuf, str_name_with_number);
                    str_name = strbuf;
                } else {
                    strcpy(buffer0, str_number_unknown);
                }
                    

            }
            (void)seen; (void)caught;
            tbox_print_string(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + idx], 
                2, (u16)(8 * node->indent), 4, 0, 0, &tbox_fontcolmap_white, 0, str_name);
            pokedex_entry_page_evolution_update_method_text(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + idx], node);
        } else {
            tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + idx], TBOX_SYNC_SET);
        }
    }

}

static void pokedex_entry_page_evolution_update() {
    u8 layer = pokedex_entry_state->page_layer;
    pokedex_entry_page_evolution_update_icons();
    pokedex_entry_page_evolution_update_text();
    pokedex_entry_page_evolution_draw_boxes(layer);
}

static const color_t pal_black[16] = {0};

static const tboxdata pokedex_entry_page_evolution_tboxes[NUM_POKEDEX_ENTRY_PAGE_EVOLUTION_TBOXES + 1] = {
    [POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + 0] = {.bg_id = 0, .x = 13, .y = 3, .w = 17, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 0 * 17 * 4},
    [POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + 1] = {.bg_id = 0, .x = 13, .y = 7, .w = 17, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 1 * 17 * 4},
    [POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + 2] = {.bg_id = 0, .x = 13, .y = 11, .w = 17, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 2 * 17 * 4},
    [POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + 3] = {.bg_id = 0, .x = 13, .y = 15, .w = 17, .h = 4, .pal = 13, .start_tile = POKEDEX_ENTRY_PAGE_START_TILE + 3 * 17 * 4},
    [NUM_POKEDEX_ENTRY_PAGE_EVOLUTION_TBOXES] = {.bg_id = 0xFF},
};

bool pokedex_entry_page_evolution_setup() {
    bool caught = pokedex_operator(pokedex_entry_state->species, POKEDEX_GET | POKEDEX_CAUGHT, true);
    (void) caught;
    switch (pokedex_entry_state->page_initialization_state) {
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_DATA_SETUP: {
            pokedex_entry_state->page_initialization_state++;
            FALL_THROUGH;
        }
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_TBOXES:
            pokedex_entry_page_initialize_tboxes(pokedex_entry_page_evolution_tboxes);
            for (size_t i = 0; i < POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES; i++) {
                u8 tbox_idx = pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + i];
                tbox_tilemap_draw(tbox_idx);
                tbox_flush_set(tbox_idx, 0x00);
            }
            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_OAM:
            for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_oam_idxs); i++) {
                u16 tile = oam_vram_alloc(2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
                oam_vram_allocation_table_add((u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i),
                    tile, 2 * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(32, 32));
                pokedex_entry_state->evolution_tree_icon_base_tiles[i] = tile;
                oam_template template = {
                    .tiles_tag = (u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i),
                    .pal_tag = (u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i),
                    .oam = &sprite_icon,
                    .rotscale = oam_rotscale_anim_table_null,
                    .callback = oam_null_callback,
                    .animation = gfx_animations_icon,
                };
                pokedex_entry_state->evolution_tree_icon_oam_idxs[i] = oam_new_forward_search(&template,
                    0, (s16)(8 * (5 + 4 * i)), 0);
                oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[i]].flags |= OAM_FLAG_INVISIBLE;
            }
            for (size_t i = 0; i < 4; i++) {
                pokedex_entry_state->evolution_tree_icon_pal_idxs[i] = oam_allocate_palette((u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i));
                if (i < 3)
                    pal_copy(icon_pals[i], 
                        (u16)(256 + 16 * pokedex_entry_state->evolution_tree_icon_pal_idxs[i]), 16 * sizeof(color_t));
                else
                    pal_copy(pal_black, 
                        (u16)(256 + 16 * pokedex_entry_state->evolution_tree_icon_pal_idxs[i]), 16 * sizeof(color_t));
            }

            pokedex_entry_state->page_initialization_state++;
            break;
        case POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS: {
            scroll_indicator_template template = {
                .arrow0_threshold = 0, 
                .arrow1_threshold = (u16)MAX(0, pokedex_entry_state->evolution_tree_size - POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES), 
                .arrow0_type = SCROLL_ARROW_UP, .arrow1_type = SCROLL_ARROW_DOWN,
                .arrow0_x = 156, .arrow1_x = 156,
                .arrow0_y = 20, .arrow1_y = 154,
                .pal_tag = 112, .tiles_tag = 112,
            };
            pokedex_entry_state->evolution_tree_scroll_indicators_cb_idx = scroll_indicator_new(&template, &pokedex_entry_state->evolution_tree_cursor);
            pokedex_entry_state->page_initialization_state++;
            break;
        }
        default:
            pokedex_entry_page_evolution_update();
            return false;
    }
    return true;
}

void pokedex_entry_page_evolution_destroy() {
    pokedex_entry_page_free_tboxes();
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_oam_idxs); i++) {
        oam_free(&oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[i]]);
    }
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_base_tiles); i++) {
        oam_free_vram_by_tag((u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i));
    }
    for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_pal_idxs); i++) {
        oam_palette_free((u16)(GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE + i));
    }
    if (pokedex_entry_state->evolution_tree_scroll_indicators_cb_idx != 0xFF) {
        scroll_indicator_delete(pokedex_entry_state->evolution_tree_scroll_indicators_cb_idx);
        pokedex_entry_state->evolution_tree_scroll_indicators_cb_idx = 0xFF;
    }
}

static void pokedex_entry_page_evolution_callback_update(u8 self) {
    u16 *state = &big_callbacks[self].params[0];
    switch (*state) {
        case 0: {
            // One frame to hide oams
            (*state)++;
            break;
        }
        case 1: {
            pokedex_entry_page_evolution_update();
            for (size_t i = 0; i < ARRAY_COUNT(pokedex_entry_state->evolution_tree_icon_oam_idxs); i++) {
                oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
            }
            (*state)++;
            FALL_THROUGH;
        }
        case 2: {
            big_callback_set_function_to_continuation(self);
            (*state)++;
            break;
        }
    }
}

static void pokedex_entry_page_evolution_redraw(u8 cb_idx) {
    // Tbox flush
    for (size_t i = 0; i < POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES; i++) {
        tbox_flush_set(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + i], 0x00);
        tbox_sync(pokedex_entry_state->page_tbox_idxs[POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + i], TBOX_SYNC_SET);
        oams[pokedex_entry_state->evolution_tree_icon_oam_idxs[i]].flags |= OAM_FLAG_INVISIBLE;
    }
    big_callback_set_function_and_continuation(cb_idx, pokedex_entry_page_evolution_callback_update, 
        big_callbacks[cb_idx].function);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].function(cb_idx);
}

bool pokedex_entry_page_evolution_handle_inputs(u8 self) {
    if (fading_control.active || dma3_busy(-1)) {
        return false;
    }
    if (super.keys_new.keys.down && pokedex_entry_state->evolution_tree_cursor < pokedex_entry_state->evolution_tree_size - POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES) {
        pokedex_entry_state->evolution_tree_cursor++;
        pokedex_entry_page_evolution_redraw(self);
        return true;
    } else if (super.keys_new.keys.up && pokedex_entry_state->evolution_tree_cursor > 0) {
        pokedex_entry_state->evolution_tree_cursor--;
        pokedex_entry_page_evolution_redraw(self);
        return true;
    }
    (void)self;
    return false;
}