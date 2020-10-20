.include "overworld_script.s"
.include "movements.s"
.include "constants/flags.s"
.include "specials.s"

.global script_pokeradar
.global script_pokeradar_battle
.global script_pokeradar_alert
.global script_pokeradar_poschange
.global script_pokeradar_flee

script_pokeradar_s:
    lockall
    pause 0x18
    checkflag 0x917
    gotoif 0 subscript_pokeradar_done
    fadescreen 1
    sound 0x27
    checksound
    sound 0x27
    checksound
    sound 0x27
    checksound
    compare 0x800D 1
    gotoif 1 subscript_pokeradar_empty
    compare 0x800D 3
    gotoif 1 subscript_pokeradar_no_grass
    compare 0x800D 2
    gotoif 1 subscript_pokeradar_unlucky
    copyvar 0x50EB 0x8000 //we update the species and level that was spawned
    copyvar 0x50EE 0x8001
    setvar 0x50E9 0
    hidesprite 254
    clearflag 0x917
    showsprite 254
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_found
    callstd 6
    releaseall
    end


subscript_pokeradar_done:
    loadpointer 0 str_pokepad_pokeradar_done
    callstd 6
    releaseall
    end

subscript_pokeradar_empty:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_empty
    callstd 6
    releaseall
    end

subscript_pokeradar_no_grass:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_no_grass
    callstd 6
    releaseall
    end   

subscript_pokeradar_unlucky:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_unlucky
    callstd 6
    releaseall
    end   

script_pokeradar_battle:
    faceplayer
    cry 0x50EB 0
    waitcry
    special 0x13
	setflag FLAG_IN_BATTLE
	callasm battle_initialize_pokeradar
    //dowildbattle
	clearflag FLAG_IN_BATTLE
	waitstate
    fadescreen 1
    hidesprite 254
    setflag POKERADAR_POKEMON_SPAWNED
    fadescreen 0
    releaseall
    end

script_pokeradar_alert_s:
    
    sound 0x15
    setvar 0x8004 254
    special SPECIAL_NPC_DELETE_RAGE_SPRITE
    applymovement 254 script_pokeradar_movement_alert
    waitmovement 0
    loadpointer 0 str_pokepad_pokeradar_alert
    callstd 6
    fadescreen 1
    hidesprite 254
    fadescreen 0
    releaseall
    end

script_pokeradar_poschange_s:
    lockall
    hidesprite 254
    clearflag 0x917
    showsprite 254
    random 0x4
    compare 0x800D 0
    callif 1 _mov_x52
    compare 0x800D 1
    callif 1 _mov_x53
    compare 0x800D 2
    callif 1 _mov_x54
    compare 0x800D 3
    callif 1 _mov_x55
    cry 0x50EB 0
    waitcry
    releaseall
    end

_mov_x52:
    applymovement 254 mov_x52
    waitmovement 0
    return
_mov_x53:
    applymovement 254 mov_x53
    waitmovement 0
    return
_mov_x54:
    applymovement 254 mov_x54
    waitmovement 0
    return
_mov_x55:
    applymovement 254 mov_x55
    waitmovement 0
    return

mov_x52:
    .byte 0x52, 0x52, STOP

mov_x53:
    .byte 0x53, 0x53, STOP

mov_x54:
    .byte 0x54, 0x54, STOP

mov_x55:
    .byte 0x55, 0x55, STOP


script_pokeradar_flee_s:
    lockall
    cry 0x50EB 0
    fadescreen 1
    waitcry
    hidesprite 254
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_flee
    callstd 6
    setflag POKERADAR_POKEMON_SPAWNED
    releaseall
    end

script_pokeradar_movement_alert:
    .byte 0x62, 0xFE

.align 4
script_pokeradar:
    .word script_pokeradar_s

.align 4
script_pokeradar_alert:
    .word script_pokeradar_alert_s

.align 4
script_pokeradar_poschange:
    .word script_pokeradar_poschange_s

.align 4
script_pokeradar_flee:
    .word script_pokeradar_flee_s

@ // Strings
.ifdef LANG_GER

	str_pokepad_pokeradar_desc:
		.string "Finde seltene Pokémon in\nder Umgebung."

	str_pokepad_pokeradar_done:
		.string "Der Pokéradar hat bereits ein\nPokémon ausfindig gemacht."

	str_pokepad_pokeradar_empty:
		.string "Der Pokéradar kann hier nichts\nausfindig machen."

	str_pokepad_pokeradar_no_grass:
		.string "Der Pokéradar kann nur in der\nNähe von hohem Gras ein\lPokémon ausfindig machen."

	str_pokepad_pokeradar_unlucky:
		.string "Der Pokéradar hat nichts entdeckt.\nVersuche es später noch einmal."

	str_pokepad_pokeradar_alert:
		.string "Das Pokémon hat dich entdeckt!\nEs ist geflohen!"

	str_pokepad_pokeradar_flee:
		.string "Das Pokémon ist geflohen..."

	str_pokepad_pokeradar_found:
		.string "Der Pokéradar hat ein Pokémon\nentdeckt!"

.elseif LANG_EN

	str_pokepad_pokeradar_done:
		.string "The Pokéradar already traced\na Pokémon."

	str_pokepad_pokeradar_empty:
		.string "The Pokéradar can not\nfind anything in this area."

	str_pokepad_pokeradar_no_grass:
		.string "The Pokéradar can only trace\nPokémon when you are\nnear some high grass."

	str_pokepad_pokeradar_unlucky:
		.string "Seems like the Pokéradar\ncould not find anything...\pBest to try it again!"

	str_pokepad_pokeradar_alert:
		.string "The Pokémon spotted you!\nIt fled!"

	str_pokepad_pokeradar_flee:
		.string "The Pokémon fled..."

	str_pokepad_pokeradar_found:
		.string "The Pokéradar spotted a Pokémon!"

.endif

