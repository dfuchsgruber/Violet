.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8a51f4
ow_script_movs_0x8a51f4:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a51e0
ow_script_movs_0x8a51e0:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a519e
ow_script_movs_0x8a519e:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a50f7
ow_script_movs_0x8a50f7:
.byte STEP_IN_PLACE_RIGHT
.byte STEP_IN_PLACE_RIGHT
.byte STOP


.global ow_script_movs_0x8a5098
ow_script_movs_0x8a5098:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a4e6a
ow_script_movs_0x8a4e6a:
.byte STEP_RIGHT
.byte LOOK_RIGHT
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8a4f18
ow_script_movs_0x8a4f18:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a4f35
ow_script_movs_0x8a4f35:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a4f09
ow_script_movs_0x8a4f09:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


.global ow_script_movs_0x8a4f0e
ow_script_movs_0x8a4f0e:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


.global ow_script_movs_0x8a4e67
ow_script_movs_0x8a4e67:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a4d38
ow_script_0x8a4d38:
lockall
playsong MUS_VIOLET_ENCOUNTER 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8a51f4
waitmovement 0x0
loadpointer 0x0 str_0x8a51f8
callstd MSG
getplayerpos 0x8000 0x8001
compare 0x8000 0x14
callif EQUAL ow_script_0x8a51e5
applymovement 0xff ow_script_movs_0x8a51e0
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a51a2
callstd MSG
special 0x7
sound 0x15
applymovement 0x7 ow_script_movs_0x8a519e
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a50fb
callstd MSG
applymovement 0xa ow_script_movs_0x8a50f7
loadpointer 0x0 str_0x8a509b
callstd MSG
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8a5098
waitmovement 0x0
loadpointer 0x0 str_0x8a5043
callstd MSG
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a5008
callstd MSG
special 0x7
sound 0x15
applymovement 0x7 ow_script_movs_0x8a519e
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a4fc6
callstd MSG
applymovement 0x7 ow_script_movs_0x8a4e6a
waitmovement 0x0
loadpointer 0x0 str_0x8a4f60
callstd MSG
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a4f3a
callstd MSG
special 0x7
sound 0x15
applymovement 0x7 ow_script_movs_0x8a4f18
waitmovement 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x8a4f35
waitmovement 0x0
applymovement 0xa ow_script_movs_0x8a4f09
waitmovement 0x0
showsprite 0x6
sound 0x17
applymovement 0xa ow_script_movs_0x8a4f0e
loadpointer 0x0 str_0x8a4f1c
callstd MSG
call ow_script_0x8a91aa
waitmovement 0x0
special 0x114
applymovement 0x7 ow_script_movs_0x8a4e67
waitmovement 0x0
setflag PKMNMENU
clearflag ROUTE_2_CAVE_GIRL_AND_GRUNT
setvar LASTTALKED 7
trainerbattlecont 0x1 0x6 0x0 str_0x8a4e71 str_0x8a4ed1 ow_script_0x8a5ac7


.global ow_script_movs_0x8fbb8f
ow_script_movs_0x8fbb8f:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a6578
ow_script_movs_0x8a6578:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8a7822
ow_script_movs_0x8a7822:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a63fe
ow_script_movs_0x8a63fe:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8a5fc5
ow_script_movs_0x8a5fc5:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a5ac7
ow_script_0x8a5ac7:
loadpointer 0x0 str_0x8a658d
callstd MSG
applymovement 0x7 ow_script_movs_0x8fbb8f
waitmovement 0x0
hidesprite 0x7
showsprite 0x8
showsprite 0x9
applymovement 0x9 ow_script_movs_0x8a6578
applymovement 0x8 ow_script_movs_0x8a7822
waitmovement 0x0
call ow_script_0x8a65f8
loadpointer 0x0 str_0x8a64ec
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x8a6402
callstd MSG_FACE
special 0x7
sound 0x15
applymovement 0xff ow_script_movs_0x8a63fe
waitmovement 0x0
checksound
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a636b
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0x0 str_0x8a62df
callstd MSG_FACE
special 0x7
applymovement 0xff ow_script_movs_0x8a5fc5
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8a5fb6
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
closeonkeypress
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a5e0c
special 0x7
setvar 0x8000 0x5
special2 0x8000 0xc
call ow_script_0x8a5f59
call ow_script_0x89e33c
loadpointer 0x0 str_0x8a5d7e
callstd MSG_FACE
special 0x7
call ow_script_0x8a5e76
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a5ce8
callstd MSG
special 0x7
call ow_script_0x8a5e85
goto ow_script_0x8a5e6f

.align 4
choice:
    .word str_route_2_cave_choice_1, 0
    .word str_route_2_cave_choice_0, 0


.global ow_script_0x8a5e6f
ow_script_0x8a5e6f:
setvar STORY_PROGRESS 0xd
end


.global ow_script_movs_0x8a919f
ow_script_movs_0x8a919f:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a5e85
ow_script_0x8a5e85:
applymovement 0x8 ow_script_movs_0x8a919f
waitmovement 0x0
hidesprite 0x8
return


.global ow_script_movs_0x8a5e9f
ow_script_movs_0x8a5e9f:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a5e76
ow_script_0x8a5e76:
applymovement 0x9 ow_script_movs_0x8a5e9f
waitmovement 0x0
hidesprite 0x9
return


.global ow_script_movs_0x8a5e05
ow_script_movs_0x8a5e05:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8a5dfe
ow_script_movs_0x8a5dfe:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a5f59
ow_script_0x8a5f59:
applymovement 0xff ow_script_movs_0x8a5e05
waitmovement 0x0
hidesprite 0x6
sound 0x17
applymovement 0xff ow_script_movs_0x8a5dfe
waitmovement 0x0
return


.global ow_script_0x8a5e0c
ow_script_0x8a5e0c:
special 0x7
setvar 0x8000 0xfb
special2 0x8000 0xc
setflag ROUTE_2_GIRL_WITH_LOST_ITEM
applymovement 0xff ow_script_movs_0x8a5e05
waitmovement 0x0
hidesprite 0x6
call ow_script_0x8a6efe
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a5f23
callstd MSG
special 0x7
call ow_script_0x8a5e85
call ow_script_0x89e33c
loadpointer 0x0 str_0x8a5eb1
callstd MSG_FACE
special 0x7
call ow_script_0x8a7da4
goto ow_script_0x8a5e6f


.global ow_script_movs_0x8a89d1
ow_script_movs_0x8a89d1:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8a7da4
ow_script_0x8a7da4:
applymovement 0x9 ow_script_movs_0x8a89d1
waitmovement 0x9
applymovement 0x9 ow_script_movs_0x8a919f
waitmovement 0x9
hidesprite 0x9
return


.global ow_script_0x8a6efe
ow_script_0x8a6efe:
copyvarifnotzero 0x8000 ITEM_GEGENGIFT
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
closeonkeypress
applymovement 0xff ow_script_movs_0x8a5dfe
waitmovement 0x0
return


.global ow_script_movs_0x8a685a
ow_script_movs_0x8a685a:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x8a65f8
ow_script_0x8a65f8:
applymovement 0xff ow_script_movs_0x8a685a
waitmovement 0x0
call ow_script_0x89e1fc
return


.global ow_script_movs_0x8a4f04
ow_script_movs_0x8a4f04:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8a91aa
ow_script_0x8a91aa:
waitmovement 0x0
hidesprite 0xa
applymovement 0x7f ow_script_movs_0x8a4f04
return


.global ow_script_movs_0x8a51f1
ow_script_movs_0x8a51f1:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8a51e5
ow_script_0x8a51e5:
applymovement 0xff ow_script_movs_0x8a51f1
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8a51f8

str_0x8a51f8:
    .string "Team Violet Rüpel: So du dummes\nGör! Gib mir schon deine Pokémon.\lMit ihnen habe ich viel bessere\lChancen, den dummen Professor Tann\lzu besiegen. Los! Wird\s bald!"
        
        
.global str_0x8a51a2

str_0x8a51a2:
    .string "Hey, du da! Hör sofort auf, dem\nkleinen Mädchen zuzusetzen!"
        
        
.global str_0x8a50fb

str_0x8a50fb:
    .string "Team Violet Rüpel: Na sieh einer\nan, wen haben wir denn da? Den\lJungen, der meinen Kollegen\lgeschlagen hat. Haben wir dich\lnicht gewarnt, uns in Ruhe zu\llassen?"
        
        
.global str_0x8a509b

str_0x8a509b:
    .string "Mädchen: Bitte, bitte! Hilf mir!\nDiese böse Frau will mir mein\lkleines Voltilamm stehlen!"
        
        
.global str_0x8a5043

str_0x8a5043:
    .string "Team Violet Rüpel: Schweig! Dieses\nPokémon ist in meinen Händen\lbesser aufgehoben."
        
        
.global str_0x8a5008

str_0x8a5008:
    .string "Ich sage es nicht noch einmal!\nLass das Mädchen in Ruhe!"
        
        
.global str_0x8a4fc6

str_0x8a4fc6:
    .string "Team Violet Rüpel: Oder was?\nDenkst du, ich habe Angst vor dir?"
        
        
.global str_0x8a4f60

str_0x8a4f60:
    .string "Dich mit uns von Team Violet\nanzulegen, ist keine gute Idee,\ldummes Kind. Lass dir das gesagt\lsein!"
        
        
.global str_0x8a4f3a

str_0x8a4f3a:
    .string "Jetzt! Lauf davon, Kleine!\nSchnell!"
        
        
.global str_0x8a4f1c

str_0x8a4f1c:
    .string "Mädchen: Ohje! Waaaah!"
        
        
.global str_0x8a4e71

str_0x8a4e71:
    .string "Team Violet Rüpel: Du Idiot! Du\nhast mich um ein Pokémon gebracht!\lDafür wirst du bezahlen!"
        
        
.global str_0x8a4ed1

str_0x8a4ed1:
    .string "Völlig ausgeschlossen! Wie konnte\nich verlieren?"
        
        
.global str_0x8a658d

str_0x8a658d:
    .string "Verdammt! Wenn ich mehr Zeit\nhätte, mich mit dir\lherumzuschlagen... aber ich muss\llos! Vergiss uns nicht!"
        
        
.global str_0x8a64ec

str_0x8a64ec:
    .string "PLAYER. Schön zu sehen, dass du\ndiesem kleinen Mädchen in Not\lgeholfen hast. Du hast keine\lFurcht gezeigt, sehr\lbewundernswert."
        
        
.global str_0x8a6402

str_0x8a6402:
    .string "Hmpf... In der Tat hast du\nziemlich gut gekämpft. Du könntest\lein ernstzunehmender Gegner\lwerden. Aber dennoch scheint sich\ldie Sache mit dem Kind gelohnt zu\lhaben. Sieh nur, es hat ein Item\lfallen lassen, als es weggelaufen\list..."
        
        
.global str_0x8a636b

str_0x8a636b:
    .string "Tatsächlich! Das arme Ding! Erst\nwird es von dieser Frau bedroht\lund dann verliert es auch noch\lsein Item. Du solltest es ihm\lzurückbringen, PLAYER!"
        
        
.global str_0x8a62df

str_0x8a62df:
    .string "Unsinn. Das Balg hat das Item\nverloren, also gehört es ihm nicht\llänger. Du hast die Frau besiegt,\lalso kannst du es auch an dich\lnehmen."
        
        
.global str_0x8a5fb6

str_0x8a5fb6:
    .string "Ich werde..."
        
        
.global str_route_2_cave_choice_0

str_route_2_cave_choice_0:
    .string "Zurückbringen"
        
        
.global str_route_2_cave_choice_1

str_route_2_cave_choice_1:
    .string "Behalten"
        
        
.global str_0x8a5d7e

str_0x8a5d7e:
    .string "... Wie dumm von dir... ....\naber das ist deine Sache... auf\ldiese Weise wirst du niemals\lErfolg haben, das garantiere\lich..."
        
        
.global str_0x8a5ce8

str_0x8a5ce8:
    .string "Gut gemacht, PLAYER. Das Mädchen\nsolltest du irgendo jenseits der\lHöhle auf Route 2 finden. Übergib\lihr das Item am Besten schnell.\lIch zähle auf dich!"
        
        
.global str_0x8a5f23

str_0x8a5f23:
    .string "Ich bin enttäuscht von dir,\nPLAYER... Das arme Mädchen."
        
        
.global str_0x8a5eb1

str_0x8a5eb1:
    .string "Eine kluge Entscheidung... Du\nwirst einmal ein guter Trainer\lwerden, das habe ich im Gefühl...\lWir sehen uns..."
        
        
.elseif LANG_EN

.endif
