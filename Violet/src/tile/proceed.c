#include "overworld/npc.h"
#include "types.h"
#include "tile/coordinate.h"
#include "tile/input.h"
#include "tile/block.h"
#include "tile/interaction.h"
#include "trainer/trainer.h"
#include "map/levelscript.h"
#include "save.h"
#include "constants/sav_keys.h"
#include "flags.h"
#include "music.h"
#include "overworld/start_menu.h"
#include "pokepad/vs_seeker.h"

bool overworld_process_input(overworld_input_t *input) {
    position_t position;
    npc_and_signpost_reset();
    u8 direction = player_get_facing();
    player_get_position(&position);
    u32 block_attributes = block_get_field_by_pos(position.coordinates.x, position.coordinates.y, BDATA_ALL);
    u16 behaviour = block_get_behaviour_by_pos(position.coordinates.x, position.coordinates.y);

    overworld_input_clear(&overworld_input_record);
    overworld_input_record.dpad_direction_pressed = input->dpad_direction_pressed;

    // if (vs_seeker_new_rematches_visible()) return true;
    vs_seeker_new_rematches_visible();
    if (trigger_npc_spotting()) return true;
    if (map_init_levelscript_2_on_frame()) return true;


    if (input->took_step) {
        save_increment_key(SAV_KEY_STEPS);
        if (trigger_step_based_scripts(&position, behaviour, direction)) {
            overworld_input_record.took_step = true;
            return true;
        }
    }
    if (input->check_wild_encounter) {
        if (input->dpad_direction_pressed == 0 || input->dpad_direction_pressed == direction)
        {
            player_get_position_faced(&position);
            behaviour = block_get_behaviour_by_pos(position.coordinates.x, position.coordinates.y);
            if (signpost_overworld_script_initialize_by_collision(&position, behaviour, direction)) {
                overworld_input_record.check_wild_encounter = true;
                return true;
            }
            player_get_position(&position);
            behaviour = block_get_behaviour_by_pos(position.coordinates.x, position.coordinates.y);
        }
    }
    if (input->check_wild_encounter && trigger_wildbattle(block_attributes)) {
        overworld_input_record.check_wild_encounter = true;
        return true;
    }
    if (input->held_direction && input->dpad_direction_pressed == direction) {
        if (trigger_arrow_warp(&position, behaviour, direction)) {
            overworld_input_record.held_direction = true;
            return true;
        }
    }
    // Interactions with the block that is faced
    player_get_position_faced(&position);
    behaviour = block_get_behaviour_by_pos(position.coordinates.x, position.coordinates.y);
    if (input->held_direction && input->dpad_direction_pressed == direction) {
        if (signpost_overworld_script_initialize_by_collision(&position, behaviour, direction)) {
            overworld_input_record.held_direction = true;
            return true;
        }
    }

    if (input->a_pressed && overworld_script_initialize_by_tile_interaction(&position, behaviour, direction)){
        overworld_input_record.a_pressed = true;
        return true;
    }

    if (input->held_direction2 && input->dpad_direction_pressed == direction) {
        if (trigger_on_step_warp(&position, behaviour, direction)) {
            overworld_input_record.held_direction2 = true;
            return true;
        }
    }

    if (input->start_pressed) {
        overworld_input_record.start_pressed = true;
        setflag(FLAG_START_MENU_OPEN);
        play_sound(6);
        start_menu_show();
        return true;
    }
    if (input->select_pressed && trigger_registered_key_item()) {
        overworld_input_record.select_pressed = true;
        return true;
    }
    return false;
}