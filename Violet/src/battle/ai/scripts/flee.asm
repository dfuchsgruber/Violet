.include "battle_ai_scripts.s"
.include "constants/abilities.s"
.include "constants/item_hold_effects.s"
.include "constants/attacks.s"
.include "constants/attack_effects.s"
.include "constants/pokemon_types.s"
.include "constants/battle/battle_statuses.s"

.global battle_ai_script_consider_fleeing

battle_ai_script_consider_fleeing:
	if_status2 AI_USER, STATUS2_WRAPPED, battle_ai_script_consider_fleeing_end
	if_status2 AI_USER, STATUS2_ESCAPE_PREVENTATION, battle_ai_script_consider_fleeing_end
	get_ability AI_TARGET
	if_equal WEGSPERRE, battle_ai_script_consider_fleeing_end
	get_ability AI_USER
	if_equal SCHWEBE, battle_ai_script_consider_fleeing_flee
	get_ability AI_TARGET
	if_equal AUSWEGSLOS, battle_ai_script_consider_fleeing_end
    jump_if_fleeing_chosen battle_ai_script_consider_fleeing_flee
battle_ai_script_consider_fleeing_end:
    end
battle_ai_script_consider_fleeing_flee:
    flee
