.include "overworld_effect.s"

.global overworld_effect_script_explosion

overworld_effect_script_explosion:
    loadpalwithshaders_and_callasm overworld_effect_explosion_palette overworld_effect_explosion
    end