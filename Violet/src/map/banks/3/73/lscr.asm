.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "specials.s"
.include "person_behaviours.s"
.include "map_weathers.s"
.include "overworld/overworld_effects.s"
.include "pathfinding.s"

.macro explosion x:req y:req
	setvar 0x8004 \x
	setvar 0x8005 \y
	special SPECIAL_OVERWORLD_EFFECT_EXPLOSION
	sound 170
.endm

.global lscr_0x89f109

lscr_0x89f109:
	.byte 0x4
.word lscr_0x8f46eb
	.byte 0x2
.word lscr_0x8f4e6f
	.byte 0x0


.align 4
.global lscr_0x8f46eb

lscr_0x8f46eb:
	.hword AKTANIA_FLASHBACK_LSCR_PLAYER_INVISIBLE, 0x0
	.word ow_script_0x814a4c
	.hword 0x0


.align 4
.global lscr_0x8f4e6f

lscr_0x8f4e6f:
	.hword STORY_PROGRESS, 0x15
	.word ow_script_0x8d7960
	.hword 0x0


.global ow_script_0x8e1584
.global ow_script_0x8d7f2e
.global ow_script_0x8d7b1f
.global ow_script_0x814a4c
.global ow_script_0x8e1a27
.global ow_script_0x8d9328
.global ow_script_0x8d7d8a
.global ow_script_earthquake
.global ow_script_0x8d7960

ow_script_0x814a4c:
callasm player_npc_set_invisible
// spriteinvisible 0xff 0x3 0x49
end


ow_script_movs_0x8d79c9:
	.byte FACE_DOWN
	.byte SAY_EXCLAM
	.byte STOP

mov_cam_down1:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

ow_script_movs_0x8d7ba7:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


ow_script_movs_0x8d7e90:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x8d7b4e:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP


mov_fd:
	.byte LOOK_DOWN, STOP

mov_2u_slow:
	.byte STEP_UP_SLOW, STEP_UP_SLOW, STOP
mov_6u_slow:
	.byte STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STOP
mov_18u_slow:
	.byte STEP_UP_SLOW
mov_17u_slow:
	.byte STEP_UP_SLOW, STEP_UP_SLOW
mov_15u_slow:
	.byte STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STEP_UP_SLOW, STOP
mov_5l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP
mov_1u:
	.byte STEP_UP_SLOW, STOP
mov_4u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_1d:
	.byte STEP_DOWN, STOP
mov_rush:
	.byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STOP
mov_recoil_down:
	.byte STEP_WALK_DOWN_FACING_UP, STOP
mov_retreat:
	.byte STEP_UP, STEP_UP, LOOK_DOWN, STOP
mov_exclam:
	.byte SAY_EXCLAM, PAUSE_32, STOP
mov_1dfl:
	.byte STEP_DOWN, LOOK_LEFT, STOP
mov_fr:
	.byte LOOK_RIGHT, STOP
mov_fl:
	.byte LOOK_LEFT, STOP

ow_script_0x8d7960:

	setvar STORY_PROGRESS 0x14
	loadpointer 0x0 str_0x8d79cd
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
	applymovement 0xFF mov_cam_down1
	waitmovement 0
	loadpointer 0 str_player2
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_RUMINATIVE
	lockall
	call ow_script_earthquake
	sound 0x15
	applymovement 0x1 ow_script_movs_0x8d79c9
	applymovement 0x2 ow_script_movs_0x8d79c9
	applymovement 0x3 ow_script_movs_0x8d79c9
	applymovement 0x4 ow_script_movs_0x8d79c9
	applymovement 0x5 ow_script_movs_0x8d79c9
	applymovement 16 mov_fd
	applymovement 17 mov_fd
	waitmovement 0x0
	spritebehave 1 BEHAVIOUR_FACE_DOWN
	spritebehave 2 BEHAVIOUR_FACE_DOWN
	spritebehave 3 BEHAVIOUR_FACE_DOWN
	spritebehave 4 BEHAVIOUR_FACE_DOWN
	spritebehave 5 BEHAVIOUR_FACE_DOWN
	spritebehave 16 BEHAVIOUR_FACE_DOWN
	spritebehave 17 BEHAVIOUR_FACE_DOWN
	setweather MAP_WEATHER_EXTREME_THUNDER
	releaseall
	checksound
	pause 0x24
	loadpointer 0x0 str_0x8d79fe
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	// Meteorite Cutscene
	setvar 0x8004 0x10
	special 0x19
	waitstate
	loadpointer 0x0 str_0x8d7bbb
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	applymovement 0xFF ow_script_movs_0x8d7ba7
	waitmovement 0x0
	playsong MUS_DEOXYS_ERSCHEINT 0x0
	cry POKEMON_DEOXYS 0x0
	waitcry
	call ow_script_earthquake
	loadpointer 0x0 str_0x8d7b5b
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	cry POKEMON_DEOXYS 0x0
	waitcry
	cry POKEMON_DEOXYS 0x0
	waitcry
	applymovement 0xFF ow_script_movs_0x8d7e90
	applymovement 11 ow_script_movs_0x8d7b4e
	waitmovement 0x0
	cry POKEMON_DEOXYS 0x0
	waitcry
	call ow_script_earthquake
	call ow_script_0x8d7b1f
	call ow_script_0x8d7b1f
	loadpointer 0x0 str_0x8d7ae9
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	cry POKEMON_DEOXYS 0x0
	waitcry
	call ow_script_earthquake
	// First find all paths, and execute them at the same time.
	// Therefore: Block movements, run A* and then unblock to run all computed paths
	special SPECIAL_NPC_PATHFINDING_BLOCK_MOVEMENTS
	// Explosions to "cover" the frames needed to find all paths
	explosion 0x5 0x39
	npc_move_to 1 0x8 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	npc_move_to 2 0x9 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	explosion 0xd 0x3a
	npc_move_to 3 0x9 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	npc_move_to 4 0x9 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	explosion 0x7 0x3b
	npc_move_to 5 0x9 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	npc_move_to 17 0x9 0x32 speed=A_STAR_SPEED_FAST waitmovement=0
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	special SPECIAL_NPC_PATHFINDING_UNBLOCK_MOVEMENTS
	pause 1
	applymovement 0xFF mov_2u_slow
	applymovement 11 mov_6u_slow

	explosion 0x9 0x3a
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	explosion 0x8 0x39
	waitmovement 11
	call ow_script_earthquake
	explosion 0x6 0x34
	pause 8
	explosion 0xc 0x36
	pause 32
	cry POKEMON_DEOXYS 0
	waitcry
	call ow_script_earthquake
	loadpointer 0 str_0x8d7ed8
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	waitmovement 0
	hidesprite 1
	hidesprite 2
	hidesprite 3
	hidesprite 4
	hidesprite 5
	hidesprite 17
	applymovement 0xFF mov_18u_slow
	applymovement 11 mov_17u_slow
	explosion 0x7 0x34
	pause 64
	explosion 0xc 0x31
	pause 64
	explosion 0x5 0x30
	applymovement 12 mov_5l
	pause 32
	explosion 0x5 0x26
	pause 16
	call ow_script_earthquake
	cry POKEMON_DEOXYS 0
	waitcry

	explosion 0xc 0x28
	waitmovement 11

	npc_move_to 14 0x8 0x26
	applymovement 14 mov_fd
	waitmovement 0
	spritebehave 14 BEHAVIOUR_FACE_DOWN
	sound 10
	applymovement 14 movs_jump_fd
	waitmovement 0
	sound 10
	applymovement 14 movs_jump_fd
	waitmovement 0
	cry POKEMON_KOKOWEI 0
	waitcry
	loadpointer 0 str_0x8d7eab
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	cry POKEMON_DEOXYS 0
	call ow_script_earthquake
	explosion 0x8 0x25
	pause 8
	explosion 0x7 0x26
	pause 8
	explosion 0x8 0x24
	pause 16
	explosion 0x8 0x25
	pause 3
	explosion 0x8 0x26
	hidesprite 14
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	pause 32
	loadpointer 0 str_0x8d7e03
	show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	applymovement 11 mov_18u_slow
	applymovement 0xFF mov_18u_slow
	pause 136
	explosion 0x5 0x20
	pause 32
	explosion 0xb 0x1c
	pause 48
	cry POKEMON_DEOXYS 0
	waitcry
	pause 32
	explosion 0x7 0x18
	pause 48
	explosion 0xb 0x19 
	waitmovement 0
	call ow_script_earthquake
	applymovement 11 mov_15u_slow
	applymovement 0xFF mov_15u_slow
	pause 104
	explosion 0xb 0x17 
	pause 48
	explosion 0x7 0x13
	pause 16
	explosion 0xc 0xf
	pause 64
	waitmovement 0
	explosion 0x5 0xe
	applymovement 18 mov_5l
	waitmovement
	cry POKEMON_DEOXYS 0
	call ow_script_earthquake
	waitcry
	loadpointer 0 str_0x8d8100
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT mask_name=1
	applymovement 0xFF mov_4u
	waitmovement 0
	applymovement 10 mov_1d
	waitmovement 0
	loadpointer 0 str_0x8d80ca
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT mask_name=0
	pause 32
	setflag 11
	showsprite 20
	sound 15
	fadescreen 3
	hidesprite 20
	setflag 12
	showsprite 21
	fadescreen 2
	checksound
	cry POKEMON_RIHORNIOR 0
	waitcry
	call ow_script_earthquake
	cry POKEMON_DEOXYS 0
	waitcry
	pause 16
	applymovement 21 mov_rush
	waitmovement 0
	sound 13
	fadescreen 2
	applymovement 11 mov_recoil_down
	applymovement 0xFF mov_recoil_down
	call ow_script_earthquake
	waitmovement 0
	applymovement 21 mov_retreat
	waitmovement 0
	pause 16
	sound 9
	setflag 4
	showsprite 19
	checksound
	sound 0x15
	applymovement 19 mov_exclam
	waitmovement 0
	applymovement 19 mov_1dfl
	waitmovement 0
	loadpointer 0 str_0x8d803f
	show_mugshot MUGSHOT_LESTER_YOUNG MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	applymovement 19 mov_fd
	waitmovement 0
	cry POKEMON_DEOXYS 0
	call ow_script_earthquake
	checksound
	explosion 0x5 0xb
	call ow_script_earthquake
	explosion 0xa 0x9
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	pause 16
	loadpointer 0 str_0x8d7fa0
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	pause 16
	cry POKEMON_DEOXYS 0
	call ow_script_earthquake
	waitcry
	checksound
	explosion 0x7 0xb
	call ow_script_earthquake
	explosion 0x9 0x9
	pause 8
	explosion 0x8 0xa
	pause 6
	explosion 0x8 0x9
	hidesprite 21
	checksound
	call ow_script_earthquake
	cry POKEMON_DEOXYS 0
	waitcry
	pause 16
	loadpointer 0 str_0x8dc40d
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	fadesong 0
	pause 16
	applymovement 10 mov_fr
	applymovement 19 mov_fl
	waitmovement 0
	loadpointer 0 str_roman1
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	loadpointer 0 str_lester1
	show_mugshot MUGSHOT_LESTER_YOUNG MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	pause 16
	applymovement 19 mov_fd
	applymovement 10 mov_1d
	waitmovement 0
	loadpointer 0 str_roman2
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	loadpointer 0 str_lester2
	show_mugshot MUGSHOT_LESTER_YOUNG MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED
	pause 32
	setanimation 0 10
	setanimation 1 16
	setanimation 2 64
	doanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FLICKER
	sound 182
	checkanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FLICKER
	setanimation 0 10
	setanimation 1 16
	setanimation 2 64
	doanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FLICKER
	sound 182
	checkanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FLICKER
	loadpointer 0 str_roman3
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	applymovement 10 mov_fr
	waitmovement 0
	loadpointer 0 str_roman4
	show_mugshot MUGSHOT_ROMAN MUGSHOT_LEFT
	setanimation 0 10
	setanimation 1 0
	setanimation 2 31
	setanimation 3 62
	doanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FADE
	sound 183
	checkanimation OVERWORLD_EFFECT_NPC_TRANSPARENT_FADE
	hidesprite 10
	loadpointer 0 str_lester3
	show_mugshot MUGSHOT_LESTER_YOUNG MUGSHOT_LEFT emotion=MUGSHOT_SAD
	playsong MUS_SPIELHALLE_VERSION_3 0x0
	setvar 0x8004 0x11
	special SPECIAL_CUTSCENE_SHOW
	waitstate
	showsprite 6
	applymovement 6 mov_fly_down
	waitmovement 0 
	call ow_script_earthquake
	cry POKEMON_REGIROCK 0
	waitcry
	showsprite 7
	applymovement 7 mov_fly_down
	waitmovement 0
	call ow_script_earthquake
	cry POKEMON_REGICE 0
	waitcry
	pause 32
	call ow_script_earthquake
	cry POKEMON_REGISTEEL 0
	waitcry
	call ow_script_earthquake
	showsprite 8
	applymovement 8 mov_fly_down
	waitmovement 0
	call ow_script_earthquake
	call ow_script_earthquake
	cry POKEMON_REGISTEEL 0
	waitcry
	cry POKEMON_DEOXYS 0
	call ow_script_earthquake
	waitcry
	pause 32
	explosion 0x6 0xa
	pause 8
	explosion 0xa 0x9
	pause 4
	explosion 0x8 0xa
	pause 6
	explosion 0x8 0x9
	pause 8
	explosion 0xa 0xa
	pause 4
	explosion 0x6 0xa
	checkanimation OVERWORLD_EFFECT_EXPLOSION
	checksound
	pause 32
	loadpointer 0 str_lester4
	show_mugshot MUGSHOT_LESTER_YOUNG MUGSHOT_LEFT emotion=MUGSHOT_SAD
	call ow_script_earthquake
	cry POKEMON_REGIROCK 0
	pause 16
	cry POKEMON_REGICE 0
	waitcry
	call ow_script_earthquake
	call ow_script_earthquake
	cry POKEMON_REGISTEEL 0
	waitcry
	call ow_script_earthquake
	cry POKEMON_DEOXYS 0
	waitcry
	sound 0x80
	applymovement 11 mov_fly_up
	waitmovement 0x0
	call ow_script_earthquake
	pause 16
	sound 0x80
	applymovement 6 mov_fly_up
	applymovement 7 mov_fly_up
	applymovement 8 mov_fly_up
	waitmovement 0
	hidesprite 6
	hidesprite 7
	hidesprite 8
	hidesprite 11
	setflag TRANS_DISABLE
	clearflag TRANS_PALETTE_FETCH
	setvar STORY_PROGRESS 0x14
	setvar 0x8004 0x12
	special 0x19
	waitstate
	clearflag TRANS_DISABLE
	pause 0x1
	cry POKEMON_DEOXYS 0x0
	call ow_script_earthquake
	waitcry
	cry POKEMON_REGISTEEL 0x0
	call ow_script_earthquake
	waitcry
	call ow_script_earthquake
	call ow_script_earthquake
	cry POKEMON_DEOXYS 0x0
	waitcry
	fadescreen 0x1
	writebytetooffset 0x0 0x2036e28
	setflag AKTANIA_FLASHBACK_DONE
	warpmuted 0xf 0x0 0xff 0x2e 0x2c
	end

mov_fly_down:
	.byte 0xA5, STOP
mov_fly_up:
	.byte 0xA4, STOP

ow_script_earthquake:
	setvar 0x8004 0x4
	setvar 0x8005 0x5
	setvar 0x8006 0x14
	setvar 0x8007 0x4
	special 0x136
	waitstate
	lockall
	return


movs_jump_fd:
.byte JUMP_IN_PLACE_FACE_DOWN
.byte STOP


ow_script_0x8d7b1f:
sound 0xa
applymovement 0x1 movs_jump_fd
applymovement 0x2 movs_jump_fd
applymovement 0x3 movs_jump_fd
applymovement 0x4 movs_jump_fd
applymovement 0x5 movs_jump_fd
waitmovement 0x0
checksound
return


.ifdef LANG_GER

str_0x8d79cd:
	.autostring 35 2 "DOTS DOTS DOTS\pWas geschieht hier?\pBilde ich mir das ein?\pWo bin ich und wie bin ich hierhergekommen?"
str_player2:
	.autostring 34 2 "Dieser Ort erinnert mich an BurchfelsDOTS"
str_0x8d79fe:
    .autostring 35 2 "War das ein Erdbeben?"
str_0x8d7bbb:
    .autostring 35 2 "Das ist der Meteorit aus meinem Traum!\pIst er hier eingeschlagen?\pUnd was ist das für ein Wesen, das mit ihm gekommen ist?"
str_0x8d7b5b:
    .autostring 35 2 "Ist das einDOTS\nDOTSPokémon?"
str_0x8d7ae9:
    .autostring 35 2 "Es wirkt aggressiv DOTS"
str_0x8d7ed8:
	.autostring 34 2 "Dieses Pokémon aus dem MeteoritenDOTS\pEs läuft Amok!\nWenn das so weitergeht, wird es die gesamte Insel zerstörenDOTS"
    // .autostring 35 2 "Die Menschen!\pSie sind alle verschwunden!\pDOTS DOTS DOTS\pIst dieses Pokémon dafür verantwortlich?"
str_0x8d7eab:
	.autostring 34 2 "Ein anderes Pokémon stellt sich ihm in den Weg?"
    // .autostring 35 2 "Dieses Pokémon muss aufgehalten werden!"
str_0x8d7e03:
	.autostring 34 2 "Das andere Pokémon hatte keine ChanceDOTS"
	// .autostring 35 2 "Und diese Stadt DOTS\pSie sieht aus, wie DOTS\pDOTS DOTS DOTS\pDOTS wie Bruchfels!"
str_0x8d8100:
	.autostring 34 2 "Was geht hier vor sich?"
    //.autostring 35 2 "Und das ist der Tempel!\pDas hier ist tatsächlich Bruchfels!"
str_0x8d80ca:
	.autostring 34 2 "Als Arenaleiter von Bruchfels werde ich dir nicht erlauben, diesen Ort zu zerstören.\pWas auch immer du hier willst, ich werde es nicht zulassen.\pLos, Rihornior!"
    //.autostring 35 2 "Und auch Lester scheint im Tempel zu sein DOTS"
str_0x8d803f:
	.autostring 34 2 "Papa!\nWas geht hier vor sich?\pWoher kommen die ganzen Erdbeben?"
	//.autostring 35 2 "Was um alles in der Welt geht hier vor sich?\pWas ist das für ein Ding?"
str_0x8d7fa0:
	.autostring 34 2 "Lester!\nHier draußen ist es gefährlich!\pGeh wieder hinein in den Tempel.\pDein alter Herr wird diesem Eindringling nicht erlauben, diesen wunderschönen Ort zu zerstören."
	//.autostring 35 2 "Ich werde dir nicht erlauben, die Stadt, die bereits viele Generationen vor mir beschützt haben, zu zerstören!\pIch werde dir die antiken Kräfte, über die ich wache, entgegensetzen!\pDOTS DOTS DOTS\pIch beschwöre die Wächter Bruchfelss!"
str_0x8dc40d:
	.autostring 34 2 "Das ist nicht gutDOTS\pNicht einmal mein Rihornior konnte diesem Pokémon Einhalt gebietenDOTS\pIch bin zu schwach, um es aufzuhaltenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMir bleibt keine WahlDOTS"
    //.autostring 35 2 "DOTS Was geht hier vor? DOTS"
str_roman1:
	.autostring 34 2 "Hör mir jetzt gut zu, Lester.\pUnsere Familie bewacht diese Insel und ihren Tempel bereits seit Jahrhunderten.\pEs ist unsere Aufgabe, diesen Ort mit unserem Leben zu verteidigen.\pUnd gegen diesen Eindringling bleibt mir nur diese eine Möglichkeit, genau das zu tun."
str_lester1:
	.autostring 34 2 "W-Was soll das heißen, Papa?\nWas hast du vor?"
str_roman2:
	.autostring 34 2 "Ich flehe euch an, ihr Wächter von Bruchfels.\pDiese Insel und der euch geweihte Tempel sind in Gefahr.\pIndem ich mein eigenes Leben opfere, beschwöre ich euch, den Eindringling zu vernichten und Bruchfels zu beschützen!"
str_lester2:
	.autostring 34 2 "Dein Leben aufgeben?\pPapa!\nWas tust du da?\pBitte, hör auf damit!\pPapa!"
str_roman3:
	.autostring 34 2 "Lester, mein JungeDOTS"
str_roman4:
	.autostring 34 2 "Pass auf dich aufDOTS"
str_lester3:
	.autostring 34 2 "Papa!"
str_lester4:
	.autostring 34 2 "P-P-PaDOTS\nDOTSP-PapaDOTS!"
str_0x8dc39d:
	.autostring 35 2 "Wächter des Gesteins, ich rufe dich herbei!\pLeihe mir deine Kraft, Regirock!"
str_0x8dc346:
	.autostring 35 2 "Zeige dich, Wächter des ewigen Eises!\pLeihe mir deine Kraft, Regice!"
str_0x8dc2ea:
    .autostring 35 2 "Ich beschwöre dich, unverwüstliches Metall!\pLehe mir deine Kraft, Registeel!"
str_0x8e195c:
    .autostring 35 2 "Ihr drei Wächter dieser Stadt, die ihr schon Jahrhundertelang diesen Ort beschützt habt!\pErfüllt eure Pflicht und vertreibt den Angreifer!"
.elseif LANG_EN

.endif