.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_0xb00a0f
.global ow_script_0xb00881
.global ow_script_0xb009d9

ow_script_0xb00881:
lock
faceplayer
checkflag FRBADGE_1
gotoif EQUAL ow_script_0xb00a0f
trainerbattlecont 0x1 0x19e 0x0 str_0xb008a0 str_0xb00982 ow_script_0xb009d9


ow_script_0xb009d9:
loadpointer 0x0 str_0xb00b22
callstd MSG
fanfare 0x104
loadpointer 0x0 str_0xb00a3a
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0xb00a65
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM39
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
loadpointer 0x0 str_0xb00bba
callstd MSG
setflag FRBADGE_1
release
end


ow_script_0xb00a0f:
loadpointer 0x0 str_0xb00a1a
callstd MSG
release
end


.ifdef LANG_GER

str_0xb008a0:
    .string "Oh, du bist also gekommen.\nUm ehrlich zu sein, sehe ich hier\lnicht oft Trainer, weswegen ich\letwas eingerostet bin. Trotzdem\lwerde ich alles geben, um dich zu\lbesiegen! Ich werde es dir nicht\lleicht machen! Los, Kampf!"



str_0xb00982:
    .string "Wow! Bravo, das hast du schön\ngemacht! Den Steinorden hast du dir\lredlich verdient!"



str_0xb00b22:
    .string "Das war äußerst beeindruckend.\nSchon lange habe ich niemanden mehr\lso kämpfen sehen. Tolle\lVorstellung! Diesen Orden hast du\ldir redlich verdient."



str_0xb00a3a:
    .string "PLAYERerhält den Felsorden von\nLester."



str_0xb00a65:
    .string "Der Felsorden lässt dich die VM\nBlitz außerhalb eines Kampfes\leinsetzten. Außerdem gehorchen dir\lalle Pokémon bis Level 10.\lNimm auch noch das hier, es ist ein\lpersönliches Geschenk."



str_0xb00bba:
    .string "Diese TM enthält Felsgrab. Sie\ngreift den Gegner mit Steinen an\lund senkt seine Agilität. Diese\lAttacke ist mein absoluter\lFavourit!"



str_0xb00a1a:
    .string "Du wirst es sehr weit bringen."


.elseif LANG_EN

.endif