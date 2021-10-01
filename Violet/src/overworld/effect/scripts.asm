.include "overworld_effect.s"

.global overworld_effect_script_explosion
.global overworld_effect_script_npc_transparent_flicker
.global overworld_effect_script_npc_transparent_fade
.global overworld_effect_script_pokeball
.global overworld_effect_script_high_grass
.global overworld_effect_script_tall_grass
.global overworld_effect_script_sound_wave
.global overworld_effect_script_whirlwind
.global overworld_effect_script_lightning

overworld_effect_script_explosion:
    loadpalwithshaders_and_callasm overworld_effect_explosion_palette overworld_effect_explosion_initialize
    end
overworld_effect_script_npc_transparent_flicker:
    callasm overworld_effect_npc_transparent_flicker_initialize
    end
overworld_effect_script_npc_transparent_fade:
    callasm overworld_effect_npc_transparent_fade_initialize
    end
overworld_effect_script_pokeball:
    callasm overworld_effect_sliding_pokeball_load_palette
    callasm overworld_effect_pokeball_initialize
    end
overworld_effect_script_sound_wave:
    loadpalwithshaders_and_callasm overworld_effect_sound_wave_palette overworld_effect_sound_wave_initialize
    end

overworld_effect_script_high_grass:
    callasm tile_any_grass_init //overworld_effect_tall_grass_init
    // loadpalwithshaders_and_callasm overworld_effect_high_grass_pal overworld_effect_high_grass_init
    end
overworld_effect_script_tall_grass:
    callasm tile_any_grass_init //overworld_effect_tall_grass_init
    //loadpalwithshaders_and_callasm overworld_effect_high_grass_pal overworld_effect_tall_grass_init
    end
overworld_effect_script_whirlwind:
    callasm overworld_effect_whirlwind_initialize
    end
overworld_effect_script_lightning:
    loadpalwithshaders_and_callasm overworld_effect_lightning_palette overworld_effect_lightning_initialize
    end
