.include "battlescript.s"
.include "battle/battle_flags.s"
.include "battle/battle_positions.s"
.include "battle/battle_animations.s"
.include "battle/battle_communication.s"
.include "battle/battle_statuses.s"


.global bsc_life_orb

bsc_life_orb:
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x1
    datahpupdate 0x1
    printstring 0x183
    waitmessage 0x40
    faintpokemon 0x1 0x0 0x8000000
    return

.global bsc_gunpowder

bsc_gunpowder:
    printstring 0x1af
    playanimation BANK_TARGET BATTLE_ANIM_GUNPOWDER 0
    orword bsc_status_flags 0x100100
    graphicalhpupdate 0x0
    datahpupdate 0x0
    faintpokemon 0x0 0x0 0x8000000
    return