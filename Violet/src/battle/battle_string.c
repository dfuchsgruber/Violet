#include "types.h"
#include "text.h"
#include "battle/battle_string.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "language.h"
#include "trainer/trainer.h"
#include "save.h"
#include "vars.h"
#include "debug.h"
#include "constants/battle/battle_results.h"
#include "mega.h"
#include "item/item.h"
#include "pokemon/names.h"
#include "battle/link.h"
#include "battle/controller.h"

static u8 str_multi_link_intro[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME und BSC_LINK_OPPONENT2_NAME\nmöchten kämpfen!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME and BSC_LINK_OPPONENT2_NAME\nwant to battle!")
);

static u8 str_link_intro[] = LANGDEP(
    PSTRING("Eine Herausforderung von\nBSC_LINK_OPPONENT1_NAME!"),
    PSTRING("You are challanged by\nBSC_LINK_OPPONENT1_NAME!")
);

static u8 str_single_trainer_intro[] = LANGDEP(
    PSTRING("Eine Herausforderung von\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!\p"),
    PSTRING("You are challanged by\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!\p")
);

static u8 str_single_double_trainer_intro[] = LANGDEP(
    PSTRING("Eine Herausforderung von\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME und\lBSC_TRAINER2_CLASS BSC_TRAINER2_NAME!\p"),
    PSTRING("You are challanged by\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME and\lBSC_TRAINER2_CLASS BSC_TRAINER2_NAME!\p")
);

static u8 str_wild_intro[] = LANGDEP(
    PSTRING("Ein wildes BSC_OPPONENT_POKEMON1_NAME erscheint!\p"),
    PSTRING("A wild BSC_OPPONENT_POKEMON1_NAME appears!\p")
);

static u8 str_wild_double_intro[] = LANGDEP(
    PSTRING("Ein wildes BSC_OPPONENT_POKEMON1_NAME und\nBSC_OPPONENT_POKEMON2_NAME erscheinen!\p"),
    PSTRING("A wild BSC_OPPONENT_POKEMON1_NAME and\nBSC_OPPONENT_POKEMON2_NAME appear!\p")
);

static u8 str_player_send_out_single[] = LANGDEP(
    PSTRING("Los! BSC_PLAYER_POKEMON1_NAME!"),
    PSTRING("Go! BSC_PLAYER_POKEMON1_NAME!")
);

static u8 str_player_send_out_double[] = LANGDEP(
    PSTRING("Los! BSC_PLAYER_POKEMON1_NAME und\nBSC_PLAYER_POKEMON2_NAME!"),
    PSTRING("Go! BSC_PLAYER_POKEMON1_NAME and\nBSC_PLAYER_POKEMON2_NAME!")
);

static u8 str_player_and_link_partner_send_out[] = LANGDEP(
    PSTRING("BSC_LINK_PARTNER_NAME schickt\nBSC_LINK_PLAYER_POKEMON2_NAME! Los! BSC_LINK_PLAYER_POKEMON1_NAME!"),
    PSTRING("BSC_LINK_PARTNER_NAME sends out\nBSC_LINK_PLAYER_POKEMON2_NAME! Go! BSC_LINK_PLAYER_POKEMON1_NAME!")
);

static u8 str_player_and_partner_send_out[] = LANGDEP(
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME schickt\nBSC_PLAYER_POKEMON2_NAME!\pLos! BSC_PLAYER_POKEMON1_NAME!"),
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME sends out\nBSC_PLAYER_POKEMON2_NAME!\pGo! BSC_PLAYER_POKEMON1_NAME!")
);

static u8 str_link_opponent_send_out_single[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME schickt\nBSC_OPPONENT_POKEMON1_NAME in den Kampf!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME sends out\nBSC_OPPONENT_POKEMON1_NAME into battle!")
);

static u8 str_trainer_sends_out_single[] = LANGDEP(
    PSTRING("BSC_TRAINER1_CLASS BSC_TRAINER1_NAME schickt\nBSC_OPPONENT_POKEMON1_NAME in den Kampf!PAUSE\x3C"),
    PSTRING("BSC_TRAINER1_CLASS BSC_TRAINER1_NAME sends out\nBSC_OPPONENT_POKEMON1_NAME into battle!PAUSE\x3C")
);

static u8 str_multi_sends_out[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME schickt\nBSC_LINK_OPPONENT_POKEMON1_NAME in den Kampf!\pBSC_LINK_OPPONENT2_NAME schickt\nBSC_LINK_OPPONENT_POKEMON2_NAME in den Kampf!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME sends out\nBSC_LINK_OPPONENT_POKEMON1_NAME into battle!\pBSC_LINK_OPPONENT2_NAME sends out\nBSC_LINK_OPPONENT_POKEMON2_NAME into battle!")
);

static u8 str_double_trainer_sends_out[] = LANGDEP(
    PSTRING("BSC_TRAINER1_CLASS BSC_TRAINER1_NAME schickt\nBSC_OPPONENT_POKEMON1_NAME in den Kampf!\pBSC_TRAINER2_CLASS BSC_TRAINER2_NAME schickt\nBSC_OPPONENT_POKEMON2_NAME in den Kampf!PAUSE\x3C"),
    PSTRING("BSC_TRAINER1_CLASS BSC_TRAINER1_NAME sends out\nBSC_OPPONENT_POKEMON1_NAME into battle!\pBSC_TRAINER2_CLASS BSC_TRAINER2_NAME sends out\nBSC_OPPONENT_POKEMON2_NAME into battle!PAUSE\x3C")
);

static u8 str_link_opponent_sends_out_double[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME schickt\nBSC_OPPONENT_POKEMON1_NAME und BSC_OPPONENT_POKEMON2_NAME!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME sends out\nBSC_OPPONENT_POKEMON1_NAME and BSC_OPPONENT_POKEMON2_NAME!")
);

static u8 str_single_trainer_sends_out_two[] = LANGDEP(
    PSTRING("BSC_OPPONENT_POKEMON1_NAME und BSC_OPPONENT_POKEMON2_NAME\nwerden von\pBSC_TRAINER1_CLASS BSC_TRAINER1_NAME\nin den Kampf geschickt!PAUSE\x3C"),
    PSTRING("BSC_OPPONENT_POKEMON1_NAME and BSC_OPPONENT_POKEMON2_NAME\nare sent out by\pBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!PAUSE\x3C")
);

static u8 str_partner_switch_in[] = LANGDEP(
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME schickt\nBSC_BUF0 in den Kampf!"),
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME sends\nBSC_BUF0 into battle!")
);

static u8 str_player_switch_in_hp_scale_0[] = LANGDEP(
    PSTRING("Los! BSC_BUF0!"),
    PSTRING("Go! BSC_BUF0!")
);

static u8 str_player_switch_in_hp_scale_1[] = LANGDEP(
    PSTRING("Du schaffst es! BSC_BUF0!"),
    PSTRING("You can do it! BSC_BUF0!")
);

static u8 str_player_switch_in_hp_scale_2[] = LANGDEP(
    PSTRING("Streng dich an, BSC_BUF0!"),
    PSTRING("Hang in there, BSC_BUF0!")
);

static u8 str_player_switch_in_hp_scale_x[] = LANGDEP(
    PSTRING("Mach es fertig!\nLos, BSC_BUF0!"),
    PSTRING("Your foe is weak!\pGet 'em, BSC_BUF0!")
);

static u8 str_multi_opponent_switch_in[] = LANGDEP(
    PSTRING("BSC_LINK_SCR_TRAINER_NAME schickt\nBSC_BUF0!"),
    PSTRING("BSC_LINK_SCR_TRAINER_NAME sends in\nBSC_BUF0!")
);

static u8 str_link_opponent_switch_in[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME schickt\nBSC_BUF0!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME sends in\nBSC_BUF0!")
);

static u8 str_opponent_single_switch_in[] = LANGDEP(
    PSTRING("BSC_BUF0 wird von\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME\lin den Kampf geschickt!"),
    PSTRING("BSC_BUF0 is sent by\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME\linto battle!")
);

static u8 str_second_opponent_switch_in[] = LANGDEP(
    PSTRING("BSC_BUF0 wird von\nBSC_TRAINER2_CLASS BSC_TRAINER2_NAME\lin den Kampf geschickt!"),
    PSTRING("BSC_BUF0 is sent by\nBSC_TRAINER2_CLASS BSC_TRAINER2_NAME\linto battle!")
);

static u8 str_multi_lost[] = LANGDEP(
    PSTRING("Spieler verliert gegen\nBSC_LINK_OPPONENT2_NAME und BSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Player loses against\nBSC_LINK_OPPONENT2_NAME and BSC_LINK_OPPONENT1_NAME!")
);

static u8 str_multi_won[] = LANGDEP(
    PSTRING("Spieler besiegt\nBSC_LINK_OPPONENT2_NAME und BSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Spieler defeats\nBSC_LINK_OPPONENT2_NAME and BSC_LINK_OPPONENT1_NAME!")
);

static u8 str_multi_drew[] = LANGDEP(
    PSTRING("Patt zwischen Spieler, BSC_LINK_OPPONENT2_NAME\nund BSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Draw between Spieler, BSC_LINK_OPPONENT2_NAME\nand BSC_LINK_OPPONENT1_NAME!")
);

static u8 str_single_trainer_won[] = LANGDEP(
    PSTRING("Spieler besiegt\nBSC_LINK_OPPONENT1_NAME"),
    PSTRING("Player defeats\nBSC_LINK_OPPONENT1_NAME")
);

static u8 str_single_trainer_lost[] = LANGDEP(
    PSTRING("Spieler verlor gegen\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!"),
    PSTRING("Player lost against\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!")
);

static u8 str_single_trainer_draw[] = LANGDEP(
    PSTRING("Patt zwischen Spieler und\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!"),
    PSTRING("Draw between player and\nBSC_TRAINER1_CLASS BSC_TRAINER1_NAME!")
);

static u8 str_link_trainer_lost[] = LANGDEP(
    PSTRING("Spieler verliert gegen\nBSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Player lost against\nBSC_LINK_OPPONENT1_NAME!")
);

static u8 str_link_trainer_won[] = LANGDEP(
    PSTRING("Spieler besiegt\nBSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Player defeated\nBSC_LINK_OPPONENT1_NAME!")
);

static u8 str_link_trainer_draw[] = LANGDEP(
    PSTRING("Patt zwischen Spieler und\nBSC_LINK_OPPONENT1_NAME!"),
    PSTRING("Draw between player and\nBSC_LINK_OPPONENT1_NAME!")
);

static u8 str_escaped[] = LANGDEP(
    PSTRING("PLAY_SE\x11 Du bist entkommen!\p"),
    PSTRING("PLAY_SE\x11 You got away safely!\p")
);

static u8 str_multi_flee[] = LANGDEP(
    PSTRING("PLAY_SE\x11 BSC_LINK_OPPONENT1_NAME und\nBSC_LINK_OPPONENT2_NAME fliehen!"),
    PSTRING("PLAY_SE\x11 BSC_LINK_OPPONENT1_NAME and\nBSC_LINK_OPPONENT2_NAME flee!")
);

static u8 str_trainer_flee[] = LANGDEP(
    PSTRING("PLAY_SE\x11 BSC_TRAINER1_CLASS BSC_TRAINER1_NAME floh!"),
    PSTRING("PLAY_SE\x11 BSC_TRAINER1_CLASS BSC_TRAINER1_NAME fled!")
);

static u8 str_link_flee[] = LANGDEP(
    PSTRING("PLAY_SE\x11 BSC_LINK_OPPONENT1_NAME flieht!"),
    PSTRING("PLAY_SE\x11 BSC_LINK_OPPONENT1_NAME flees!")
);

static u8 str_return_hp_scale_0[] = LANGDEP(
    PSTRING("BSC_BUF0, genug!\nKomm zurück!"),
    PSTRING("BSC_BUF0, enough!\nCome back!")
);

static u8 str_return_hp_scale_1[] = LANGDEP(
    PSTRING("BSC_BUF0, komm zurück!"),
    PSTRING("BSC_BUF0, come back!")
);

static u8 str_return_hp_scale_2[] = LANGDEP(
    PSTRING("BSC_BUF0, O.K.!\nKomm zurück!"),
    PSTRING("BSC_BUF0, O.K.!\nCome back!")
);

static u8 str_return_hp_scale_3[] = LANGDEP(
    PSTRING("BSC_BUF0, gut!\nKomm zurück!"),
    PSTRING("BSC_BUF0, good!\nCome back!")
);

static u8 str_return_ally[] = LANGDEP(
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME ruft\nBSC_BUF0 zurück!"),
    PSTRING("BSC_PARTNER_CLASS BSC_PARTNER_NAME withdrew\nBSC_BUF0 back!")
);

static u8 str_return_link_trainer[] = LANGDEP(
    PSTRING("BSC_LINK_OPPONENT1_NAME ruft\nBSC_BUF0 zurück!"),
    PSTRING("BSC_LINK_OPPONENT1_NAME withdrew\nBSC_BUF0!")
);

static u8 str_return_multi_trainer[] = LANGDEP(
    PSTRING("BSC_LINK_SCR_TRAINER_NAME ruft\nBSC_BUF0 zurück!"),
    PSTRING("BSC_LINK_SCR_TRAINER_NAME withdrew\nBSC_BUF0!")
);

static u8 str_return_trainer[] = LANGDEP(
    PSTRING("BSC_BUF0 wurde\nvon BSC_TRAINER1_CLASS BSC_TRAINER1_NAME\lzurückgerufen!"),
    PSTRING("BSC_TRAINER1_CLASS BSC_TRAINER1_NAME\nwithdrew BSC_BUF0!")
);

static u8 str_return_second_trainer[] = LANGDEP(
    PSTRING("BSC_BUF0 wurde\nvon BSC_TRAINER2_CLASS BSC_TRAINER2_NAME\lzurückgerufen!"),
    PSTRING("BSC_TRAINER2_CLASS BSC_TRAINER2_NAME\nwithdrew BSC_BUF0!")
);

u8 *battle_intro_buffer_message() {
    if (battle_flags & BATTLE_TRAINER) {
        if (battle_flags & BATTLE_LINK) {
           if (battle_flags & BATTLE_MULTI) return str_multi_link_intro;
           else return str_link_intro;
        } else {
            if (battle_flags & BATTLE_TWO_TRAINERS) return str_single_double_trainer_intro;
            else return str_single_trainer_intro;
        }
    } else {
        if (battle_flags & BATTLE_DOUBLE)
            return str_wild_double_intro;
        else
            return str_wild_intro; // Cut on the GHOST battle stuff...
    }
}

u8 *battle_send_out_buffer_message() {
    if (battler_is_opponent(active_battler)) {
        if (battle_flags & BATTLE_DOUBLE) {
            if (battle_flags & BATTLE_MULTI) return str_multi_sends_out;
            else if (battle_flags & BATTLE_TWO_TRAINERS) return str_double_trainer_sends_out;
            else if (battle_flags & BATTLE_LINK) return str_link_opponent_sends_out_double;
            else return str_single_trainer_sends_out_two;
        } else {
            if (battle_flags & BATTLE_LINK) return str_link_opponent_send_out_single;
            else return str_trainer_sends_out_single;
        }
    } else {
        if (battle_flags & BATTLE_DOUBLE) {
            if (battle_flags & BATTLE_MULTI) return str_player_and_link_partner_send_out;
            else if (battle_flags & BATTLE_ALLY) return str_player_and_partner_send_out;
            else return str_player_send_out_double;
        } else return str_player_send_out_single;
    } 
}

u8 *battle_string_return_pokemon_buffer_message() {
    if (battler_is_opponent(active_battler)) {
        if (trainer_vars.trainer_id == 0x800) {
            if (battle_flags & BATTLE_MULTI) return str_return_multi_trainer;
            else return str_return_link_trainer;
        } else if ((battle_flags & BATTLE_DOUBLE) && (battle_flags & BATTLE_TWO_TRAINERS) &&
            battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) return str_return_second_trainer;
        else return str_return_trainer;
    } else {
        if (battle_flags & BATTLE_ALLY) return str_return_ally;
        else if (battle_state->hp_scale == 0) return str_return_hp_scale_0;
        else if (battle_state->hp_scale == 1 || (battle_flags & BATTLE_DOUBLE)) return str_return_hp_scale_1;
        else if (battle_state->hp_scale == 2) return str_return_hp_scale_2;
        return str_return_hp_scale_3;
    }
}

u8 *battle_switch_in_buffer_message() {
    if (battler_is_opponent(battle_scripting.battler_idx)) {
        if (battle_flags & BATTLE_LINK) {
            if (battle_flags & BATTLE_MULTI) return str_multi_opponent_switch_in;
            else return str_link_opponent_switch_in;
        } else if ((battle_flags & BATTLE_DOUBLE) && (battle_flags & BATTLE_TWO_TRAINERS) && 
            battle_scripting.battler_idx == BATTLE_POSITION_OPPONENT_RIGHT) return str_second_opponent_switch_in;
        else return str_opponent_single_switch_in;
    } else {
        if ((battle_flags & BATTLE_ALLY) && (battle_flags & BATTLE_DOUBLE) && 
            battler_get_position(battle_scripting.battler_idx) == BATTLE_POSITION_PLAYER_RIGHT)
                return str_partner_switch_in;
        if ((battle_flags & BATTLE_DOUBLE) || battle_state->hp_scale == 0) return str_player_switch_in_hp_scale_0;
        else if (battle_state->hp_scale == 1) return str_player_switch_in_hp_scale_1;
        else if (battle_state->hp_scale == 2) return str_player_switch_in_hp_scale_2;
        else return str_player_switch_in_hp_scale_x;
    }
}


u8 *battle_end_battle_buffer_message() {
    if (bsc_string_buffer0[0] & BATTLE_RESULT_LINK_BATTLE_OPPONENT_RAN) {
        bsc_string_buffer0[0] &= (u8)(~BATTLE_RESULT_LINK_BATTLE_OPPONENT_RAN);
        if (battler_is_opponent(active_battler) && bsc_string_buffer0[0] != BATTLE_RESULT_DRAW)
            bsc_string_buffer0[0] ^= BATTLE_RESULT_WON | BATTLE_RESULT_LOST; // The player's outcome is complementary to the foe's (of course...)
        if (bsc_string_buffer0[0] == BATTLE_RESULT_LOST || bsc_string_buffer0[0] == BATTLE_RESULT_DRAW) return str_escaped;
        else if (battle_flags & BATTLE_MULTI) return str_multi_flee;
        else if (trainer_vars.trainer_id == 0xC00) return str_trainer_flee; // ??
        else return str_link_flee;

    } else {
        if (battler_is_opponent(active_battler) && bsc_string_buffer0[0] != BATTLE_RESULT_DRAW)
            bsc_string_buffer0[0] ^= BATTLE_RESULT_WON | BATTLE_RESULT_LOST; // The player's outcome is complementary to the foe's (of course...)
        if (battle_flags & BATTLE_MULTI) {
            if (bsc_string_buffer0[0] == BATTLE_RESULT_LOST) return str_multi_lost;
            else if (bsc_string_buffer0[0] == BATTLE_RESULT_WON) return str_multi_won;
            else return str_multi_drew;
        } else {
            if (trainer_vars.trainer_id == 0xC00) { // ??
                if (bsc_string_buffer0[0] == BATTLE_RESULT_WON) return str_single_trainer_won;
                else if (bsc_string_buffer0[0] == BATTLE_RESULT_LOST) return str_single_trainer_lost;
                else return str_single_trainer_draw;
            } else {
                if (bsc_string_buffer0[0] == BATTLE_RESULT_WON) return str_link_trainer_won;
                else if (bsc_string_buffer0[0] == BATTLE_RESULT_LOST) return str_link_trainer_lost;
                else return str_link_trainer_draw;
            }
        }
    }

}

u16 trainer_idx_by_owner(u8 owner) {
    if (battle_flags & BATTLE_TRAINER) {
        switch (owner) {
            case OWNER_TRAINER_A: return trainer_vars.trainer_id;
            case OWNER_TRAINER_B: return fmem.trainer_varsB.trainer_id;
            case OWNER_ALLY: return fmem.ally_trainer_idx;
        }
    }
    return 0;
}

u16 trainer_idx_by_battler_idx(u8 battler_idx) {
    return trainer_idx_by_owner(battler_get_owner(battler_idx));
}

u8 *trainer_get_name(u16 trainer_idx) {
        DEBUG("Return dynamic trainer name.\n");
    if (trainers[trainer_idx].trainerclass == TRAINERCLASS_RIVALE || trainers[trainer_idx].trainerclass == TRAINERCLASS_RIVALE2) {
        return string_get_placeholder(6);
    } else if (trainer_idx >= 0x1e0 && trainer_idx < 0x1e4) {
        DEBUG("Return dynamic trainer name.\n");
        return fmem.dynamic_trainer_name;
    }
    else
        return trainers[trainer_idx].name;
}

u8 *battle_string_decrypt_additional_buffers(u8 buffer_idx) {
    switch(buffer_idx) {
        case 0x1D: // Trainer1 name
            return trainer_get_name(trainer_vars.trainer_id);
        case 0x31:  // Trainer2 Class
            return trainer_class_names[trainers[fmem.trainer_varsB.trainer_id].trainerclass];
        case 0x32 : // Trainer2 Name
            return trainer_get_name(fmem.trainer_varsB.trainer_id);
        case 0x2E: // Trainer2 Lose Text
            return fmem.trainer_varsB.defeat_text; // Cut on trainer tower stuff...
        case 0x2F: // Trainer2 Win Text
            return fmem.trainer_varsB.victory_text; // Cut on trainer tower stuff...
        case 0x33: // Ally class
            return trainer_class_names[trainers[*var_access(VAR_ALLY)].trainerclass];
        case 0x34: // Ally name
            return trainer_get_name(*var_access(VAR_ALLY));
        case 0x35: // Mega-Idx keystone
            return items[battler_get_keystone(battle_scripting.battler_idx)].name;
        case 0x36: // Mega Species
            return pokemon_names[mega_evolution_get_by_mega_species(battlers[battle_scripting.battler_idx].species)->species];
        case 0x37: // Attacker trainer class name
            return trainer_class_names[trainers[trainer_idx_by_battler_idx(attacking_battler)].trainerclass];
        case 0x38:
            if (battler_get_owner(attacking_battler) == OWNER_PLAYER)
                return save2->player_name;
            else
                return trainer_get_name(trainer_idx_by_battler_idx(attacking_battler));
        case 0x39: {
            return battlers[defending_battler].name;
            
        }
        default:
            return NULL;
    }
}

static u8 str_partner_unknown[] = PSTRING("?????");

u8 *battle_get_partner_name() {
    if (battle_flags & BATTLE_ALLY) {
        return trainer_get_name(*var_access(VAR_ALLY));
    } else if (battle_flags & (BATTLE_MULTI)) {
        return link_players[PARTNER(link_players[multiplayer_get_idx()].battler_idx)].name;
    }
    return str_partner_unknown;
}