.include "battle_ai_scripts.s"
.include "constants/abilities.s"
.include "constants/item_hold_effects.s"

.global battle_ai_script_check_viability_trick
.global battle_ai_choice_effects

battle_ai_script_check_viability_trick:
	get_hold_effect AI_USER
	if_in_bytes battle_ai_choice_effects, is_choice_item
	if_in_bytes battle_ai_held_item_effects_to_give_opponent, is_effect_to_swap
    jump_if_item_bad_for_battler AI_USER, AI_USER, user_item_hurts_user

trick_score_minus_3:
	score -3
	goto trick_end

is_choice_item:
	get_hold_effect AI_TARGET
	if_in_bytes battle_ai_choice_effects, trick_score_minus_3
trick_score_plus_5:
	score +5
	goto trick_end

user_item_hurts_user:
    jump_if_item_bad_for_battler AI_TARGET, AI_USER, trick_score_minus_3 // the target item would also hurt the user
    jump_if_item_bad_for_battler AI_USER, AI_TARGET, trick_score_plus_5 // the user item hurts the target
    goto trick_score_minus_3 // the user item doesn't hurt the target

is_effect_to_swap:
	get_hold_effect AI_TARGET
	if_in_bytes battle_ai_held_item_effects_to_give_opponent, trick_score_minus_3
	if_random_less_than 50, trick_end
	score +2

trick_end:
	end

battle_ai_held_item_effects_to_give_opponent:
	.byte HOLD_EFFECT_CONFUSE_SPICY
	.byte HOLD_EFFECT_CONFUSE_DRY
	.byte HOLD_EFFECT_CONFUSE_SWEET
	.byte HOLD_EFFECT_CONFUSE_BITTER
	.byte HOLD_EFFECT_CONFUSE_SOUR
	.byte HOLD_EFFECT_MACHO_BRACE
	.byte HOLD_EFFECT_CHOICE_ITEM
	.byte -1

battle_ai_choice_effects:
    .byte HOLD_EFFECT_CHOICE_ITEM
    .byte -1