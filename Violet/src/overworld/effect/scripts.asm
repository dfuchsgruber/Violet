.include "overworld_effect.s"

.global overworld_effect_script_explosion
.global overworld_effect_script_npc_transparent_flicker
.global overworld_effect_script_npc_transparent_fade
.global overworld_effect_script_pokeball

overworld_effect_script_explosion:
    loadpalwithshaders_and_callasm overworld_effect_explosion_palette overworld_effect_explosion
    end
overworld_effect_script_npc_transparent_flicker:
    callasm overworld_effect_npc_transparent_flicker
    end
overworld_effect_script_npc_transparent_fade:
    callasm overworld_effect_npc_transparent_fade
    end
overworld_effect_script_pokeball:
    callasm overworld_effect_sliding_pokeball_load_palette
    callasm overworld_effect_pokeball
    end