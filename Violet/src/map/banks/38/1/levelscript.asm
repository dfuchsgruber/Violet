
.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"

.global lscr_sun_moon_tower_bridge

lscr_sun_moon_tower_bridge:
	.byte LEVELSCRIPT_TYPE_ON_LOAD
	.word lsrc_setmaptile
	.byte 0x0

lsrc_setmaptile:
	checkflag FLAG_MEGA_LUNATONITE_CHOSEN
	callif EQUAL bridge_broken
    checkflag FLAG_MEGA_SOLROCKNITE_CHOSEN
    callif EQUAL bridge_broken
    end 

bridge_broken:
    setmaptile 15 7 0x2F3 1
    setmaptile 16 7 0x329 1
    setmaptile 17 7 0x2F4 1
    return
