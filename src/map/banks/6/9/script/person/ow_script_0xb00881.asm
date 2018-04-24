.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0xb00881
ow_script_0xb00881:
lock
faceplayer
checkflag FRBADGE_1
gotoif EQUAL ow_script_0xb00a0f
trainerbattlecont 0x1 0x19e 0x0 str_0xb008a0 str_0xb00982 ow_script_0xb009d9


.global ow_script_0xb009d9
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


.global ow_script_0xb00a0f
ow_script_0xb00a0f:
loadpointer 0x0 str_0xb00a1a
callstd MSG
release
end


.ifdef LANG_GER
.global str_0xb008a0

str_0xb008a0:
    .string "Oh, du bist also gekommen.\nUm ehrlich zu sein, sehe ich hier\lnicht oft Trainer, weswegen ich\letwas eingerostet bin. Trotzdem\lwerde ich alles geben, um dich zu\lbesiegen! Ich werde es dir nicht\lleicht machen! Los, Kampf!"
        
        
.global str_0xb00982

str_0xb00982:
    .string "Wow! Bravo, das hast du schön\ngemacht! Den Steinorden hast du dir\lredlich verdient!"
        
        
.global str_0xb00b22

str_0xb00b22:
    .string "Das war äußerst beeindruckend.\nSchon lange habe ich niemanden mehr\lso kämpfen sehen. Tolle\lVorstellung! Diesen Orden hast du\ldir redlich verdient."
        
        
.global str_0xb00a3a

str_0xb00a3a:
    .string "PLAYERerhält den FELSORDEN von\nLESTER."
        
        
.global str_0xb00a65

str_0xb00a65:
    .string "Der FELSORDEN lässt dich die VM\nBlitz außerhalb eines Kampfes\leinsetzten. Außerdem gehorchen dir\lalle Pokémon bis Level 10.\lNimm auch noch das hier, es ist ein\lpersönliches Geschenk."
        
        
.global str_0xb00bba

str_0xb00bba:
    .string "Diese TM enthält Felsgrab. Sie\ngreift den Gegner mit Steinen an\lund senkt seine Agilität. Diese\lAttacke ist mein absoluter\lFavourit!"
        
        
.global str_0xb00a1a

str_0xb00a1a:
    .string "Du wirst es sehr weit bringen."
        
        
.elseif LANG_EN

.endif
