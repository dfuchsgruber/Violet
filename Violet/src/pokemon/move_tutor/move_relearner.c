#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/moves.h"
#include "pokemon/move_relearner.h"
#include "vars.h"
#include "constants/pokemon_types.h"
#include "attack.h"
#include "language.h"
#include "debug.h"
#include "transparency.h"
#include "io.h"
#include "oam.h"
#include "flags.h"

extern const color_t gfx_text_std_borderPal[16];

u8 pokemon_get_accesible_learnable_moves(const pokemon *p, u16 *moves, u8 type) {
    u16 species = (u16)pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    const u16 *accesible = pokemon_accessible_moves[species];
    if (!accesible)
        return 0;
    u16 current_moves[4];
    for (int i = 0; i < 4; i++)
        current_moves[i] = (u16) pokemon_get_attribute(p, (u8)(ATTRIBUTE_ATTACK1 + i), 0);
    u8 num_moves = 0;
    for (int i = 0; accesible[i] != 0xFFFF; i++) {
        if (attacks[accesible[i]].type != type)
            continue;
        bool add_to_list = true;
        for (int j = 0; j < 4; j++) {
            if (current_moves[j] == accesible[i]) {
                add_to_list = false;
                break;
            }
        }
        for (int j = 0; j < num_moves; j++) {
            if (moves[j] == accesible[i]) {
                add_to_list = false;
                break;
            }
        }
        if (add_to_list) {
            moves[num_moves++] = accesible[i];
        }
    }
    return num_moves;
}

void pokemon_get_number_of_accessible_moves_in_lastresult() {
    u16 moves[32];
    int type = *var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE) - 1;
    pokemon *p = player_pokemon + *var_access(0x8004);
    u8 nickname[11];
    pokemon_get_attribute(p, ATTRIBUTE_NICKNAME, nickname);
    pokemon_copy_nickname(buffer0, nickname);
    *var_access(LASTRESULT) = pokemon_get_accesible_learnable_moves(player_pokemon + *var_access(0x8004), moves, (u8)type);
}

void accessible_move_tutor_set_flag() {
    setflag((u16)(FLAG_TUTOR_CRYSTAL_BASE + *var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE) - 1));
}

void move_tutor_set_flag() {
    setflag((u16)(FLAG_MOVE_TUTOR_BASE + *var_access(0x8004)));

}

static const u8 str_back[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

void move_relearner_initialize_list_menu() {
    u8 nickname[11]; 
    pokemon *p = player_pokemon + move_relearner_state->party_idx;
    int type = *var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE);
    DEBUG("Relearner with type %d\n", type);
    if (type == 0) {
        move_relearner_state->num_learnable_moves = move_relearner_get_moves(p, move_relearner_state->learnable_moves);
    } else {
        move_relearner_state->num_learnable_moves = pokemon_get_accesible_learnable_moves(p, move_relearner_state->learnable_moves, (u8)(type - 1));
    }
    u8 count = move_relearner_state->num_learnable_moves;
    for (int i = 0; i < count; i++) {
        const u8 *attack_name = attack_names[move_relearner_state->learnable_moves[i]];
        strcpy(move_relearner_state->learnable_move_strings[i], attack_name);
    }
    pokemon_get_attribute(p, ATTRIBUTE_NICKNAME, nickname);
    pokemon_copy_nickname(buffer0, nickname);
    strcpy(move_relearner_state->learnable_move_strings[count], str_back);
    move_relearner_state->num_learnable_moves++;
    for (int i = 0; i < count; i++) {
        move_relearner_state->list_menu_items[i].text = move_relearner_state->learnable_move_strings[i];
        move_relearner_state->list_menu_items[i].idx = i;
    }
    move_relearner_state->list_menu_items[count].text = str_back;
    move_relearner_state->list_menu_items[count].idx = 0xFE;
    gp_list_menu_template = move_relearner_list_menu_template;
    gp_list_menu_template.items = move_relearner_state->list_menu_items;
    gp_list_menu_template.item_cnt = (u16)(count + 1);
    DEBUG("Num learnable moves is %d\n", move_relearner_state->num_learnable_moves);

    // A bit whack to put this here, but w/e
    // Turns off alpha blending effect
    io_set(IO_WININ, 0x1F1F);
    io_set(IO_BLDCNT, 0x1E40);
    io_set(IO_BLDALPHA, 0x0010);

    // Load standard tbox pal
    pal_copy(gfx_text_std_borderPal, 15 * 16, 16 * sizeof(color_t));
}

static const u8 str_three_hyphens[] = PSTRING("---");
// static const u8 str_nop[] = PSTRING("");
extern const u8 gfx_attack_classesTiles[];

void move_relearner_update_move_info(u16 move) {
    u8 buffer[50];
    tbox_blit_move_info_icon(2, (u8)(attacks[move].type + 1), 1, 4);
    if (attacks[move].base_power < 2) {
        move_relearner_print_string(3, str_three_hyphens, 1, 4, 0, 0);
    } else {
        itoa(buffer, attacks[move].base_power, ITOA_PAD_SPACES, 3);
        move_relearner_print_string(3, buffer, 1, 4, 0, 0);
    }
    if (attacks[move].accuracy == 0) {
        move_relearner_print_string(3, str_three_hyphens, 1, 18, 0, 1);
    } else {
        itoa(buffer, attacks[move].accuracy, ITOA_PAD_SPACES, 3);
        move_relearner_print_string(3, buffer, 1, 18, 0, 1);
    }
    itoa(buffer, attacks[move].pp, ITOA_NO_PADDING, 2);
    move_relearner_print_string(4, buffer, 2, 2, 0, 0);
    move_relearner_print_string(5, attack_descriptions[move - 1], 1, 0, 0, 0);

    tbox_tilemap_draw(8);
    // move_relearner_print_string(8, str_nop, 0, 0, 0, 0);
    tbox_blit(8, gfx_attack_classesTiles + GRAPHIC_SIZE_4BPP(32, 16) * attacks[move].category, 0, 0, 32, 16, 0, 0, 32, 16);
    tbox_copy_to_vram(8, TBOX_COPY_TILESET);
}

void move_relearner_copy_to_vram_or_clear() {
    if (move_relearner_state->move_idx != 0xFE) {
        move_relearner_update_move_info(move_relearner_state->learnable_moves[move_relearner_state->move_idx]);
    } else {
        for (u8 i = 2; i < 6; i++) {
            tbox_flush_set(i, 0);
            tbox_copy_to_vram(i, TBOX_COPY_TILESET);
        }
        tbox_flush_set(8, 0);
        tbox_copy_to_vram(8, TBOX_COPY_TILESET);
    }
    tbox_copy_to_vram(3, TBOX_COPY_TILESET);
    tbox_copy_to_vram(4, TBOX_COPY_TILESET);
    tbox_copy_to_vram(2, TBOX_COPY_TILESET);
    tbox_copy_to_vram(5, TBOX_COPY_TILESET);
    tbox_copy_to_vram(7, TBOX_COPY_TILESET | TBOX_COPY_TILEMAP);
}

const tboxdata move_relearner_tboxes[10] = {
    {
        .bg_id = 0,
        .x = 0,
        .y = 0,
        .w = 6,
        .h = 7,
        .pal = 0x0d,
        .start_tile = 0x014
    },
    {
        .bg_id = 0,
        .x = 10,
        .y = 0,
        .w = 5,
        .h = 5,
        .pal = 0x0d,
        .start_tile = 0x03e
    },
    {
        .bg_id = 0,
        .x = 5,
        .y = 0,
        .w = 5,
        .h = 2,
        .pal = 0x0d,
        .start_tile = 0x057
    },
    {
        .bg_id = 0,
        .x = 15,
        .y = 0,
        .w = 3,
        .h = 5,
        .pal = 0x0f,
        .start_tile = 0x061
    },
    {
        .bg_id = 0,
        .x = 5,
        .y = 2,
        .w = 3,
        .h = 3,
        .pal = 0x0f,
        .start_tile = 0x070
    },
    {
        .bg_id = 0,
        .x = 2,
        .y = 6,
        .w = 15,
        .h = 8,
        .pal = 0x0f,
        .start_tile = 0x079
    },
    {
        .bg_id = 0,
        .x = 19,
        .y = 1,
        .w = 10,
        .h = 12,
        .pal = 0x0f,
        .start_tile = 0x0f1
    },
    {
        .bg_id = 0,
        .x = 2,
        .y = 15,
        .w = 26,
        .h = 4,
        .pal = 0x0f,
        .start_tile = 0x169
    },
    {
        .bg_id = 0,
        .x = 5,
        .y = 4,
        .w = 4,
        .h = 2,
        .pal = 0x0d,
        .start_tile = 0x1d1 + 24
    }, {
        .bg_id = 0xFF,
    }
};