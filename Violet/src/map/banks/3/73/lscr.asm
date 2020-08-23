.include "vars.s"

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
.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_0x8e1584
.global ow_script_0x8d7f2e
.global ow_script_0x8d7b1f
.global ow_script_0x814a4c
.global ow_script_0x8e1a27
.global ow_script_0x8d9328
.global ow_script_0x8d7d8a
.global ow_script_0x8d7a10
.global ow_script_0x8d7960

ow_script_0x814a4c:
spriteinvisible 0xff 0x3 0x49
end


ow_script_movs_0x8d79c9:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP

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
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
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
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP



ow_script_0x8d7960:

loadpointer 0x0 str_0x8d79cd
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
lockall
call ow_script_0x8d7a10
sound 0x15
applymovement 0x1 ow_script_movs_0x8d79c9
applymovement 0x2 ow_script_movs_0x8d79c9
applymovement 0x3 ow_script_movs_0x8d79c9
applymovement 0x4 ow_script_movs_0x8d79c9
applymovement 0x5 ow_script_movs_0x8d79c9
waitmovement 0x0
lockall
checksound
pause 0x24
loadpointer 0x0 str_0x8d79fe
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH


setvar STORY_PROGRESS 0x14
setvar 0x8004 0x10
special 0x19
waitstate
clearflag TRANS_DISABLE

lockall
loadpointer 0x0 str_0x8d7bbb
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
special 0x113
applymovement 0x7f ow_script_movs_0x8d7ba7
waitmovement 0x0
playsong MUS_DEOXYS_ERSCHEINT 0x0
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
loadpointer 0x0 str_0x8d7b5b
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
cry POKEMON_DEOXYS 0x0
waitcry
cry POKEMON_DEOXYS 0x0
waitcry
applymovement 0x7f ow_script_movs_0x8d7e90
applymovement 0x9 ow_script_movs_0x8d7b4e
waitmovement 0x0
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
call ow_script_0x8d7b1f
call ow_script_0x8d7b1f
loadpointer 0x0 str_0x8d7ae9
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
sound 0x50
// Execute one proper fadescreen in order to flood pal_restore with correct shaders
// after anim engine with sepia effect and the modified fadescreen system this is needed tho
fadescreen 0x3
fadescreen 0x2
checksound
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x3
hidesprite 0x1
hidesprite 0x2
hidesprite 0x3
hidesprite 0x4
hidesprite 0x5
setweather 0x5
doweather
fadescreen 0x2
goto ow_script_0x8d7d8a


ow_script_movs_0x8d7e5d:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP


ow_script_movs_0x8d7e64:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
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


ow_script_0x8d7d8a:
loadpointer 0x0 str_0x8d7ed8
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
waitcry
loadpointer 0x0 str_0x8d7eab
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
applymovement 0x9 ow_script_movs_0x8d7e5d
applymovement 0x7f ow_script_movs_0x8d7e5d
waitmovement 0x0
cry POKEMON_DEOXYS 0x0
applymovement 0x9 ow_script_movs_0x8d7e64
applymovement 0x7f ow_script_movs_0x8d7e64
waitmovement 0x0
loadpointer 0x0 str_0x8d7e03
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
goto ow_script_0x8d7f2e


ow_script_movs_0x8d8111:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8d80fd:
.byte STEP_DOWN
.byte STOP


ow_script_0x8d7f2e:
hidesprite 0x6
hidesprite 0x7
hidesprite 0x8
hidesprite 0xa
applymovement 0x7f ow_script_movs_0x8d8111
waitmovement 0x0
loadpointer 0x0 str_0x8d8100
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
showsprite 0xa
applymovement 0xa ow_script_movs_0x8d80fd
waitmovement 0x0
fadesong 0
loadpointer 0x0 str_0x8d80ca
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8d803f
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
playsong MUS_SPIELHALLE_VERSION_3 0x0
loadpointer 0x0 str_0x8d7fa0
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
goto ow_script_0x8d9328





ow_script_movs_0x8dc3fb:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
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

ow_script_0x8d9328:
special 0x114
setvar 0x8004 0x11
special 0x19
waitstate
showsprite 0x13
clearflag PKMNMENU
setweather 0x5
doweather
call ow_script_0x8d7a10
loadpointer 0x0 str_0x8dc40d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
special 0x114
special 0x113
applymovement 0x7f ow_script_movs_0x8dc3fb
waitmovement 0x0
sound 0x50
fadescreen 0x3 // Force one "proper" fadescreen to copy the pal to pal_restore as well
fadescreen 0x2
loadpointer 0x0 str_0x8dc39d
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGIROCK 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0x6
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
loadpointer 0x0 str_0x8dc346
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGICE 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0xf
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
loadpointer 0x0 str_0x8dc2ea
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGISTEEL 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0x8
fadescreen 0x2
call ow_script_0x8d7a10
goto ow_script_0x8e1584


ow_script_movs_0x8e1959:
.byte 0xa4
.byte STOP


ow_script_0x8e1584:
loadpointer 0x0 str_0x8e195c
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
cry POKEMON_DEOXYS 0x0
waitcry
sound 0x80
applymovement 0x13 ow_script_movs_0x8e1959
waitmovement 0x0
call ow_script_0x8d7a10
sound 0x80
applymovement 0x6 ow_script_movs_0x8e1959
applymovement 0x8 ow_script_movs_0x8e1959
applymovement 0xf ow_script_movs_0x8e1959
waitmovement 0x0
goto ow_script_0x8e1a27


ow_script_0x8e1a27:
hidesprite 0x6
hidesprite 0x8
hidesprite 0xf
hidesprite 0x13


setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar STORY_PROGRESS 0x14
setvar 0x8004 0x12
special 0x19
waitstate
clearflag TRANS_DISABLE
pause 0x1
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
waitcry
cry POKEMON_REGISTEEL 0x0
call ow_script_0x8d7a10
waitcry
call ow_script_0x8d7a10
call ow_script_0x8d7a10
cry POKEMON_DEOXYS 0x0
waitcry
fadescreen 0x1
//callasm 0x919d791
writebytetooffset 0x0 0x2036e28
setflag AKTANIA_FLASHBACK_DONE
warpmuted 0xf 0x0 0xff 0x2e 0x2c
end


ow_script_0x8d7a10:
setvar 0x8004 0x4
setvar 0x8005 0x5
setvar 0x8006 0x14
setvar 0x8007 0x4
special 0x136
waitstate
lockall
return


ow_script_movs_0x8d7b4b:
.byte JUMP_IN_PLACE_FACE_DOWN
.byte STOP


ow_script_0x8d7b1f:
sound 0xa
applymovement 0x1 ow_script_movs_0x8d7b4b
applymovement 0x2 ow_script_movs_0x8d7b4b
applymovement 0x3 ow_script_movs_0x8d7b4b
applymovement 0x4 ow_script_movs_0x8d7b4b
applymovement 0x5 ow_script_movs_0x8d7b4b
waitmovement 0x0
checksound
return


.ifdef LANG_GER

str_0x8d79cd:
	.autostring 35 2 "DOTS DOTS DOTS\pWas geschieht hier?\pIch sehe diese Bilder vor meinem inneren Auge, aber die Vision ist klar und deutlich DOTS"



str_0x8d79fe:
    .autostring 35 2 "War das ein Erdbeben?"



str_0x8d7bbb:
    .autostring 35 2 "Da ist wieder dieser Meteorit und das Wesen, das sich auf ihm befunden hat DOTS"



str_0x8d7b5b:
    .autostring 35 2 "Ist diese Wesen ein DOTS\pDOTS DOTS DOTS\pDOTS Pokémon?"



str_0x8d7ae9:
    .autostring 35 2 "Es wirkt aggressiv DOTS"



str_0x8d7ed8:
    .autostring 35 2 "Die Menschen!\pSie sind alle verschwunden!\pDOTS DOTS DOTS\pIst dieses Pokémon dafür verantwortlich?"



str_0x8d7eab:
    .autostring 35 2 "Dieses Pokémon muss aufgehalten werden!"



str_0x8d7e03:
	.autostring 35 2 "Und diese Stadt DOTS\pSie sieht aus, wie DOTS\pDOTS DOTS DOTS\pDOTS wie Bruchfels!"



str_0x8d8100:
    .autostring 35 2 "Und das ist der Tempel!\pDas hier ist tatsächlich Bruchfels!"



str_0x8d80ca:
    .autostring 35 2 "Und auch Lester scheint im Tempel zu sein DOTS"


str_0x8d803f:
	.autostring 35 2 "Was um alles in der Welt geht hier vor sich?\pWas ist das für ein Ding?"


str_0x8d7fa0:
	.autostring 35 2 "Ich werde dir nicht erlauben, die Stadt, die bereits viele Generationen vor mir beschützt haben, zu zerstören!\pIch werde dir die antiken Kräfte, über die ich wache, entgegensetzen!\pDOTS DOTS DOTS\pIch beschwöre die Wächter Bruchfelss!"


str_0x8dc40d:
    .autostring 35 2 "DOTS Was geht hier vor? DOTS"



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