.include "overworld_script.s"
.include "levelscript_types.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "callstds.s"
.include "unown_messages.s"
.include "vars.s"

.global ow_script_felsige_oednis_regirock_cave_entrance

ow_script_felsige_oednis_regirock_cave_entrance:
    lock
    checkflag FLAG_REGIROCK_CAVE_OPENED
    gotoif EQUAL opened
    setvar 0x8004 UNOWN_MESSAGE_ROCK
    special SPECIAL_UNOWN_MESSAGE_PRINT
    waitstate
    special SPECIAL_UNOWN_MESSAGE_REMOVE
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_SPELLS_UNOWN_MESSAGE
    compare LASTRESULT 0
    gotoif EQUAL end_script
    setvar 0x8004 0x2
    setvar 0x8005 0x2
    setvar 0x8006 0xA
    setvar 0x8007 0x3
    special SPECIAL_EARTHQUAKE
    pause 0x3C
    setvar 0x8004 0x3
    setvar 0x8005 0x3
    setvar 0x8006 0xC
    setvar 0x8007 0x2
    special SPECIAL_EARTHQUAKE
    pause 0x3C
    call ow_script_felsige_oednis_open_regirock_cave
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    checksound
    setflag FLAG_REGIROCK_CAVE_OPENED
    goto opened
end_script:
    release
    end

opened:
    loadpointer 0 str_0
    callstd MSG_SIGN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ein Höhleneingang ist erschienen!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "A cave entrance has appeared!"
.endif