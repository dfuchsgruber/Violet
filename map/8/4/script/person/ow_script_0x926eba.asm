.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x926eba
ow_script_0x926eba:
compare KARMA_VALUE 0x7fff
callif HIGHER ow_script_0x9270b8
lock
faceplayer
loadpointer 0x0 str_0x926fde
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b1f3
loadpointer 0x0 str_0x926ee5
callstd MSG
release
end


.global ow_script_0x16b1f3
ow_script_0x16b1f3:
loadpointer 0x0 str_0x19618f
callstd MSG_KEEPOPEN
special 0x9f
waitstate
compare 0x8004 0x6
gotoif LESS ow_script_0x16b220
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x16b216
end


.global ow_script_0x16b216
ow_script_0x16b216:
loadpointer 0x0 str_0x926ee5
callstd MSG_KEEPOPEN
release
end


.global ow_script_0x16b220
ow_script_0x16b220:
special2 0x800d 0x147
compare LASTRESULT 0x19c
gotoif EQUAL ow_script_0x16b273
special 0x7c
special 0x7d
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b27d
special2 0x800d 0x150
special 0x7c
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b27d
loadpointer 0x0 str_0x1961c4
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b287
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x16b216
end


.global ow_script_0x16b287
ow_script_0x16b287:
loadpointer 0x0 str_0x19623b
callstd MSG_KEEPOPEN
call ow_script_0x9270a8
special2 0x800d 0x7b
special 0x7c
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b2b1
loadpointer 0x0 str_0x196308
callstd MSG_KEEPOPEN
release
end


.global ow_script_0x16b2b1
ow_script_0x16b2b1:
loadpointer 0x0 str_0x19626e
callstd MSG_KEEPOPEN
release
end


.global ow_script_0x9270a8
ow_script_0x9270a8:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
fadescreen 0x1
special 0x9e
waitstate
clearflag TRANS_DISABLE
return


.global ow_script_0x16b27d
ow_script_0x16b27d:
loadpointer 0x0 str_0x1963a6
callstd MSG_KEEPOPEN
release
end


.global ow_script_0x16b273
ow_script_0x16b273:
loadpointer 0x0 str_0x1963e0
callstd MSG_KEEPOPEN
release
end


.global ow_script_0x9270b8
ow_script_0x9270b8:
compare KARMA_VALUE 0xffc0
gotoif LESS_OR_EQUAL ow_script_0x926f34
return


.global ow_script_0x926f34
ow_script_0x926f34:
loadpointer 0x0 str_0x926f3e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x926fde

str_0x926fde:
    .string "Oh, hallo!\pMan sieht es mir vermutlich an,\nich bin der große Namensexperte!\pIch und alleine ich vermag über\ndie Spitznamen deiner Pokémon zu\lurteilen!\pSoll ich den Namen eines deiner\nPokémon bewerten?"
        
        
.global str_0x926ee5

str_0x926ee5:
    .string "Ich bin empört!\pDenkst du etwa, du kennst dich\nbesser mit Namen aus als ich?"
        
        
.global str_0x19618f

str_0x19618f:
    .string "Für welches Pokémon soll ich den\nNamen bewerten?"
        
        
.global str_0x1961c4

str_0x1961c4:
    .string "Der Spitzname ist BUFFER_1,\noder? Ein schöner Name!\pGefällt er dir noch immer, oder\nmöchtest du ihn ändern?"
        
        
.global str_0x19623b

str_0x19623b:
    .string "Sehr schön! Und wie soll der neue\nKosename lauten?"
        
        
.global str_0x196308

str_0x196308:
    .string "Fertig! Von nun an heißt dein\nPokémon BUFFER_1!\pEigentlich unterscheidet sich der\nName nicht von dem vorherigen und\ldoch ist er um einiges besser!\pWelch ein Glück!"
        
        
.global str_0x19626e

str_0x19626e:
    .string "Fertig! Von nun an heißt dein\nPokémon BUFFER_1!\pDas ist ein besserer Name als der\nvorherige. Welch ein Glück für\ldich!"
        
        
.global str_0x1963a6

str_0x1963a6:
    .string " in wirklich guter\nName!\pKümmere dich gut um BUFFER_1!"
        
        
.global str_0x1963e0

str_0x1963e0:
    .string "Oh, mhm...\nDas ist eigentlich ein Ei!"
        
        
.global str_0x926f3e

str_0x926f3e:
    .string "...\pDu scheinst nicht der Typ Mensch\nzu sein, der seinen Pokémon Namen\lgibt.\pSie sind nicht deine Freunde,\nsondern dienen dir bloß als\lWerkzeuge, nicht wahr?"
        
        
.elseif LANG_EN

.endif
