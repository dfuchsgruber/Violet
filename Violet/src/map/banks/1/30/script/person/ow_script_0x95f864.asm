.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x95f864
ow_script_0x95f864:
lockall
faceplayer

loadpointer 0 str_girl
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x95fd2c
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
special 0xF
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95fe6b
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95fa47

call ow_script_0x8a1cc9
loadpointer 0x0 str_0x95f9d1
callstd MSG_KEEPOPEN
special 0x7
loadpointer 0 str_girl
setvar 0x8000 1
special 0xE
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
loadpointer 0 str_girl
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x95f8fc
callstd MSG
special 0xF
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

loadpointer 0 str_girl
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x95fa65
callstd MSG
special 0xF
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

@//Give money
loadpointer 0x0 str_0x95fc38
callstd MSG_KEEPOPEN

checksound
setvar 0x8004 0x8
special2 0x8004 0xc


loadpointer 0 str_girl
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x95fbb9
callstd MSG
special 0xF
goto ow_script_0x95fb9a


.global ow_script_0x95fcc6
ow_script_0x95fcc6:
@// not enough money
loadpointer 0x0 str_0x95fcd2
callstd MSG
releaseall
release
end


.ifdef LANG_GER

str_girl:
	.string "Mädchen"

.global str_0x95fd2c

str_0x95fd2c:
    .autostring 35 2 "Schluchz DOTS\nSchluchz DOTS\pWeißt du, diese bösen Männer von Team Violet haben mir mein Taschengeld gestohlen DOTS\p1500POKEDOLLAR sind nun weg und alles was mir nun noch bleibt ist dieses Nugget DOTS\pEs ist ein Geschenk meines Papas, aber vielleicht kann ich es verkaufen DOTS\pIch brauche das Geld wirklich sehr dringend DOTS"
        
        
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
    .autostring 35 2 "Jammerschade, heute ist nicht dein Glückstag, wie es scheint.\pImmerhin wirst du dein Nugget auch gleich los sein DOTS"
        
        
.global str_0x95f937

str_0x95f937:
    .autostring 35 2 "Waaas? Schluchz!?\nDas ist nicht dein Ernst?\pWieso sind alle so gemein zu mir!\pBuhu! Buhu!\pLass mich in Ruhe, dieses Nugget hat mein Papa mir geschenkt!"
        
        
.global str_0x95f8bc

str_0x95f8bc:
    .autostring 35 2 "Wuhäää! Bääääh!\nBitte nimm es nicht DOTS"
        
        
.global str_0x95f8fc

str_0x95f8fc:
    .autostring 35 2 "Du bist ein böser Mensch DOTS\pGuhäää! Bäh! Wääh! Schluchz DOTS"
        
        
.global str_0x95fa93

str_0x95fa93:
    .autostring 35 2  "Na, na!\nDOTS Hör doch bitte auf zu weinen!\pSei das nächste Mal einfach vorsichtiger, Mädchen DOTS"
        
        
.global str_0x95fa65

str_0x95fa65:
    .autostring 35 2  "Buhu! Schluchz!\pDu bist gemein! Baha! Buhu!"
        
        
.global str_0x95fc52

str_0x95fc52:
    .autostring 35 2 "Na, mach dir keine Sorgen.\pIch werde dir stattdessen einfach 1500POKEDOLLAR geben und Team Violet zur Rächenschaft ziehen."
        
        
.global str_0x95fc38

str_0x95fc38:
    .autostring 35 2 "PLAYER gibt dem Kind 1500POKEDOLLAR."
        
        
.global str_0x95fbb9

str_0x95fbb9:
    .autostring 35 2 "Danke! Schluchz!\pDu bist toll!\pIch hoffe wir begegnen uns einmal wieder!\pUi, ich kann mir jetzt Spielzeug kaufen!\pJuhu!"
        
        
.global str_0x95fcd2

str_0x95fcd2:
    .string "Du hast nicht genügend GeldDOTS"
        
        
.elseif LANG_EN

.endif
