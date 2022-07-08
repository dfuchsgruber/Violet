.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "unown_messages.s"
.include "vars.s"
.include "pathfinding.s"

.global ow_script_route_5_clouds_unown_message
.global ow_script_route_5_clouds_setmaptile_open_aerodactyl_cave

ow_script_route_5_clouds_unown_message:
    lock
    checkflag FLAG_ROUTE_5_CLOUDS_CAVE_OPEN
    gotoif EQUAL opened
    setvar 0x8004 UNOWN_MESSAGE_AERO
    special SPECIAL_UNOWN_MESSAGE_PRINT
    waitstate
    special SPECIAL_UNOWN_MESSAGE_REMOVE
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_SPELLS_UNOWN_MESSAGE
    compare LASTRESULT 0
    gotoif EQUAL end_script
@ // Open the cave
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0x1a
    setvar 0x8005 0x29
    setvar 0x8006, A_STAR_SPEED_NORMAL
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
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
    call ow_script_route_5_clouds_setmaptile_open_aerodactyl_cave
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 0x21
    checksound
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    setvar 0x8004 0xFF
    special SPECIAL_PERSON_GET_POSITION
    setvar 0x8006, A_STAR_SPEED_NORMAL
    special SPECIAL_OVERWORLD_VIEWPOINT_MOVE_TO
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    setflag FLAG_ROUTE_5_CLOUDS_CAVE_OPEN
opened:
    loadpointer 0 str_opened
    callstd MSG_SIGN
end_script:
    release
    end

.equ AERODACTYL_CAVE_ENTRANCE__X, 0x19
.equ AERODACTYL_CAVE_ENTRANCE__Y, 0x28

ow_script_route_5_clouds_setmaptile_open_aerodactyl_cave:
    setmaptile AERODACTYL_CAVE_ENTRANCE__X + 0, AERODACTYL_CAVE_ENTRANCE__Y + 0, 0x210, 0x1
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 1, AERODACTYL_CAVE_ENTRANCE__Y + 0,  0x211, 0x1
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 2, AERODACTYL_CAVE_ENTRANCE__Y + 0,  0x212, 0x1
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 0, AERODACTYL_CAVE_ENTRANCE__Y + 1,  0x218, 0x1
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 1, AERODACTYL_CAVE_ENTRANCE__Y + 1,  0x204, 0x0
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 2, AERODACTYL_CAVE_ENTRANCE__Y + 1,  0x21a, 0x1
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 0, AERODACTYL_CAVE_ENTRANCE__Y + 2,  0x20b, 0x0
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 1, AERODACTYL_CAVE_ENTRANCE__Y + 2,  0x20c, 0x0
	setmaptile AERODACTYL_CAVE_ENTRANCE__X + 2, AERODACTYL_CAVE_ENTRANCE__Y + 2,  0x20d, 0x0
	return

.ifdef LANG_GER
str_opened:
    .autostring 34 2 "Die Tafel hat auf die Icognito in deinem Team reagiert!"
.elseif LANG_EN
.endif