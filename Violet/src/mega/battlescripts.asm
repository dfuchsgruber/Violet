.include "battlescript.s"
.include "constants/battle/battle_animations.s"

.global battlescript_mega_evolution 
.global battlescript_regent_evolution 

battlescript_mega_evolution:
    printstring 0x19C
    waitmessage 0x40
    playanimation BANK_SCRIPTING BATTLE_ANIM_MEGA_EVOLUTION 0
    // battleanimation 0 0 battle_animation_mega_evolution
    // waitbattleanimation
    printstring 0x19D
    waitmessage 0x40
    end3

battlescript_regent_evolution:
    printstring 0x19E
    waitmessage 0x40
    playanimation BANK_SCRIPTING BATTLE_ANIM_REGENT_EVOLUTION 0
    // battleanimation 0 0 battle_animation_regent_evolution
    // waitbattleanimation
    printstring 0x19F
    waitmessage 0x40
    end3