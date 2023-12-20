.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x16b2b1
.global ow_script_0x16b220
.global ow_script_0x16b287
.global ow_script_0x16b1f3
.global ow_script_0x16b273
.global ow_script_0x9270a8
.global ow_script_0x16b27d
.global ow_script_map_8_4_person_0
.global ow_script_0x16b216

ow_script_map_8_4_person_0:
lock
faceplayer
setflag FLAG_NICKNAME_RATER
loadpointer 0x0 str_0x926fde
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x16b1f3
loadpointer 0x0 str_0x926ee5
callstd MSG
release
end


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


ow_script_0x16b216:
loadpointer 0x0 str_0x926ee5
callstd MSG_KEEPOPEN
release
end


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


ow_script_0x16b2b1:
loadpointer 0x0 str_0x19626e
callstd MSG_KEEPOPEN
release
end


ow_script_0x9270a8:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
fadescreen 0x1
special 0x9e
waitstate
clearflag TRANS_DISABLE
return


ow_script_0x16b27d:
loadpointer 0x0 str_0x1963a6
callstd MSG_KEEPOPEN
release
end


ow_script_0x16b273:
loadpointer 0x0 str_0x1963e0
callstd MSG_KEEPOPEN
release
end


.ifdef LANG_GER

str_0x926fde:
    .string "Oh, hallo!\pMan sieht es mir vermutlich an,\nich bin der große Namensexperte!\pIch und alleine ich vermag über\ndie Spitznamen deiner Pokémon zu\lurteilen!\pSoll ich den Namen eines deiner\nPokémon bewerten?"



str_0x926ee5:
    .string "Ich bin empört!\pDenkst du etwa, du kennst dich\nbesser mit Namen aus als ich?"



str_0x19618f:
    .string "Für welches Pokémon soll ich den\nNamen bewerten?"



str_0x1961c4:
    .string "Der Spitzname ist BUFFER_1,\noder? Ein schöner Name!\pGefällt er dir noch immer, oder\nmöchtest du ihn ändern?"



str_0x19623b:
    .string "Sehr schön! Und wie soll der neue\nKosename lauten?"



str_0x196308:
    .string "Fertig! Von nun an heißt dein\nPokémon BUFFER_1!\pEigentlich unterscheidet sich der\nName nicht von dem vorherigen und\ldoch ist er um einiges besser!\pWelch ein Glück!"



str_0x19626e:
    .string "Fertig! Von nun an heißt dein\nPokémon BUFFER_1!\pDas ist ein besserer Name als der\nvorherige. Welch ein Glück für\ldich!"



str_0x1963a6:
    .autostring 35 2 "Das ist ein wirklich guter Name!\pKümmere dich gut um BUFFER_1!"



str_0x1963e0:
    .string "Oh, mhmDOTS\nDas ist eigentlich ein Ei!"



.elseif LANG_EN

.endif