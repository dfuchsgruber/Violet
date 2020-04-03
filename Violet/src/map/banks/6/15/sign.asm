.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_6_15_sign_0
.global ow_script_0x87c9f4
.global ow_script_0x87afc7
.global ow_script_0x87ca4c

ow_script_map_6_15_sign_0:
checkflag AKTANIA_GEODUDE_DONE
gotoif LESS ow_script_0x87afc7
end


ow_script_0x87afc7:
checkflag AKTANIA_GEODUDE_ACCEPTED
gotoif EQUAL ow_script_0x87c9f4
loadpointer 0x0 str_0x87cae0
callstd MSG
end


ow_script_movs_0x87cadd:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x87c9f4:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x87ca4c
loadpointer 0x0 str_0x87caba
callstd MSG
pause 0x40
sound 0x15
applymovement 0xff ow_script_movs_0x87cadd
waitmovement 0x0
loadpointer 0x0 str_0x87ca86
callstd MSG
cry POKEMON_KLEINSTEIN 0x0
loadpointer 0x0 str_0x87ca4e
callstd MSG
waitcry
setvar NEXT_POKEMON_SHINY 0x1
setwildbattle POKEMON_KLEINSTEIN 0xc ITEM_NUGGET
dowildbattle
setmaptile 0x7 0x7 0x2fc 0x0
fadescreen 0x1
special 0x8e
fadescreen 0x0
setflag AKTANIA_GEODUDE_FOUGHT
end


ow_script_0x87ca4c:
end


.ifdef LANG_GER

str_0x87cae0:
    .string "Ein seltsamer Stein, der golden\nschimmert. Ab und an wirkt es so,\lals würde er sich bewegenDOTS"



str_0x87caba:
    .string "PLAYER untersucht den Stein näherDOTS"



str_0x87ca86:
    .string "Auf einmal springt der goldene\nStein in die Höhe!"



str_0x87ca4e:
    .string "Der Stein entpuppt sich als\nKleinstein!\lEs greift an!"


.elseif LANG_EN

.endif