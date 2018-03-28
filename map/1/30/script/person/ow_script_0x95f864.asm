.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f864
ow_script_0x95f864:
lockall
faceplayer
loadpointer 0x0 str_0x95fd2c
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95fe6b
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95fa47
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95f9d1
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x9b 0x0 str_0x95f937 str_0x95f8bc ow_script_0x960424

.align 4
choice:
    .word str_aschhain_girl_choice_0, 0
    .word str_aschhain_girl_choice_1, 0
    .word str_aschhain_girl_choice_2, 0

.global ow_script_0x960424
ow_script_0x960424:
setvar 0x8004 0xffec
special2 0x8004 0xc
loadpointer 0x0 str_0x95f8fc
callstd MSG
sound 0x7
clearflag ASCHHAIN_NUGGET
showsprite 0x2
goto ow_script_0x95fb9a


.global ow_script_0x95fb9a
ow_script_0x95fb9a:
copyvar 0x8004 LASTTALKED
setvar 0x8005 0x12
setvar 0x8006 0x25
special 0x24
waitmovement 0x0
sound 0x9
hidesprite 0x800f
checksound
releaseall
end


.global ow_script_0x95fa47
ow_script_0x95fa47:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95fa93
callstd MSG_KEEPOPEN
special 0x7
loadpointer 0x0 str_0x95fa65
callstd MSG
goto ow_script_0x95fb9a


.global ow_script_0x95fe6b
ow_script_0x95fe6b:
checkmoney 0x5dc 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95fcc6
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95fc52
callstd MSG_KEEPOPEN
special 0x7
sound 0x41
loadpointer 0x0 str_0x95fc38
callstd MSG_KEEPOPEN
checksound
setvar 0x8004 0x8
special2 0x8004 0xc
loadpointer 0x0 str_0x95fbb9
callstd MSG
goto ow_script_0x95fb9a


.global ow_script_0x95fcc6
ow_script_0x95fcc6:
loadpointer 0x0 str_0x95fcd2
callstd MSG
releaseall
release
end


.ifdef LANG_GER
.global str_0x95fd2c

str_0x95fd2c:
    .string "Schluchz...\nSchluchz...\pWeißt du, diese bösen Männer von\nTeam Violet haben mir mein\lTaschengeld gestohlen...\p1500POKEDOLLAR sind nun weg und alles was\nmir nun noch bleibt ist dieses\lNugget...\pEs ist ein Geschenk meines Papas,\laber vielleicht kann ich es\nverkaufen...\pIch brauche das Geld wirklich\nsehr dringend..."
        
        
.global str_aschhain_girl_choice_0

str_aschhain_girl_choice_0:
    .string "1500POKEDOLLAR geben"
        
        
.global str_aschhain_girl_choice_1

str_aschhain_girl_choice_1:
    .string "Nichts tun"
        
        
.global str_aschhain_girl_choice_2

str_aschhain_girl_choice_2:
    .string "Nugget stehlen"
        
        
.global str_0x95f9d1

str_0x95f9d1:
    .string "Jammerschade, heute ist nicht dein\nGlückstag, wie es scheint.\lImmerhin wirst du dein Nugget auch\lgleich los sein..."
        
        
.global str_0x95f937

str_0x95f937:
    .string "Waaas? Schluchz!?\nDas ist nicht dein Ernst?\pWieso sind alle so gemein zu mir!\nBuhu! Buhu!\pLass mich in Ruhe, dieses Nugget\nhat mein Papa mir geschenkt!"
        
        
.global str_0x95f8bc

str_0x95f8bc:
    .string "Wuhäää! Bääääh!\nBitte nimm es nicht..."
        
        
.global str_0x95f8fc

str_0x95f8fc:
    .string "Du bist ein böser Mensch...\nGuhäää! Bäh! Wääh! Schluz..."
        
        
.global str_0x95fa93

str_0x95fa93:
    .string "Na... Hör doch bitte auf zu\nweinen!\lWas passiert ist, kann nicht\lwieder rückgängig gemacht werden.\pSei das nächste Mal ein bisschen\nvorsichtiger, für jetzt hast du\ldeine Lektion auf jeden Fall\lgelernt."
        
        
.global str_0x95fa65

str_0x95fa65:
    .string "Buhu! Schluchz!\nDu bist gemein! Baha! Buhu!"
        
        
.global str_0x95fc52

str_0x95fc52:
    .string "Na, mach dir keine Sorgen.\nIch werde dir stattdessen einfach\l1500POKEDOLLAR geben und Team Violet zur\lRächenschaft ziehen."
        
        
.global str_0x95fc38

str_0x95fc38:
    .string "PLAYER gibt dem Kind 1500POKEDOLLAR."
        
        
.global str_0x95fbb9

str_0x95fbb9:
    .string "Danke! Schluchz!\nDu bist toll!\lIch hoffe wir begegnen uns bald\lwieder!\lUi, ich kann mir jetzt dieses\lSpielzeug kaufen!\lJuhu!"
        
        
.global str_0x95fcd2

str_0x95fcd2:
    .string "Du hast nicht genügend Geld..."
        
        
.elseif LANG_EN

.endif
