.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "items.s"
.include "attacks.s"
.include "ordinals.s"
.include "species.s"
.include "roamers.s"
.include "specials.s"
.include "movements.s"


.global ow_script_test
.global ow_script_trainer1
.global ow_script_trainer2


ow_script_trainer1:
	trainerbattlestd 0x0 0x15f 0 str_beforea str_aftera
	end
ow_script_trainer2:
	trainerbattlestd 0x0 0x160 0 str_beforeb str_afterb
	end

str_beforea:
	.string "Before A"
str_aftera:
	.string "After A"
str_beforeb:
	.string "Before B"
str_afterb:
	.string "After B"

ow_script_test:

trainerbattleallytwotrainers 0x15f 0x160 0x140 0 str_beforea str_aftera str_afterb cont
cont:
loadpointer 0 str_a
callstd MSG
end

trainerbattlecont 0x1 0x160 0x0 str_a str_0x96f156 cont
setflag PLAYER_ABLE_TO_MEGA_EVOLVE
givepokemon POKEMON_TROPIUS 80 ITEM_TROPIUSNIT 0 0 0
end

str_a:
	.string "KEY_L KEY_R"

special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
callasm test_overworld_viewport_set_position
pause 120
applymovement 0x7F movs
waitmovement 0
end

applymovement 0x7F movs
waitmovement 0
special SPECIAL_OVERWORLD_VIEWPORT_LOCK
end

movs:
    .byte STEP_UP, STEP_UP, STOP 


callasm special_initialize_pc_for_selection
waitstate 
end


special 60
waitstate
end


givepokemon POKEMON_ICOGNITO 12 0 0 0 0
end

lock
setvar 0x8004 2
special2 0x800D SPECIAL_PLAYER_PARTY_SPELLS_UNOWN_MESSAGE
special SPECIAL_UNOWN_MESSAGE_PRINT
waitstate
special SPECIAL_UNOWN_MESSAGE_REMOVE
release
end


sound 0xd1
setanimation 0x0 0x47
setanimation 0x1 0x1d
setanimation 0x2 0x0
doanimation 0x36
checkanimation 0x36
setvar 0x8004 0x6
setflag TRANS_DISABLE
special 0x19
waitstate
settrainerflag 0xaa
trainerbattlecont 0x1 0xaa 0x0 str_0x96f0ee str_0x96f156 ow_script_0x96fbaa
end


warp 3 17 255 0x1e 0x15
waitstate
end

braille braille1
waitkeypress
waitmsg
closeonkeypress
end

braille1:
.autostring 34 2 "BRAILLE_HBRAILLE_CBRAILLE_KBRAILLE_,"


setvar 0x8000 ITEM_KUESTENSALZ
loop:
	additem 0x8000 10
	addvar 0x8000 1
	compare 0x8000 ITEM_ENIGMABEERE
	gotoif 0 loop
end


additem ITEM_SONDERBONBON 99
additem ITEM_GOLDBONBON 99
additem ITEM_SUESSBONBON 99
end
warp 11 2 255 0x1a 0
waitstate
end

setvar 0x8004 ROAMER_LAVADOS
special SPECIAL_ROAMER_RESET_AND_INITIALIZE
setflag POKEDEX_FEATURE_0
end

clearflag FLAG_FOREST_CEMETERY_DONE
setvar STORY_PROGRESS 0x37
end

setflag TRANS_DISABLE
callasm river_puzzle_initialize
end

setflag TRANS_DISABLE
callasm incubator_initialize
waitstate
end
settrainerflag 0xb7
trainerbattlecont 0x1 0xb7 0x0 str_0x83114c str_0x8311a8 ow_script_0x83108d
setvar 0x8004 6
special 0x19
waitstate
cont_end:
end

givepokemon POKEMON_LEDYBA 12 0 0 0 0
additem ITEM_LICHTLEHM 1
end
givepokemon POKEMON_KECLEON_PURPLE 35 0 0 0 0
end
setflag PLAYER_CAN_ENTER_DUNGEONS
setflag FRBADGE_5
setflag FRBADGE_6
setflag FRBADGE_7
additem ITEM_VM03 1
additem ITEM_TM43 1
additem ITEM_VM08 1
setflag FRBADGE_8
callasm debug_vars
callasm debug_flags
@ goto ow_script_dungeon2_enter_ocean
end