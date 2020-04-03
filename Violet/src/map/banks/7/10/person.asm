.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_0x81b512
.global ow_script_0x81b34a
.global ow_script_map_7_10_trainer_1
.global ow_script_map_7_10_trainer_0
.global ow_script_0x81b507

ow_script_map_7_10_trainer_1:
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b34a
loadpointer 0x0 str_0x81b37f
callstd MSG_FACE
end


ow_script_0x81b34a:
loadpointer 0x0 str_0x81b354
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81b37f:
    .string "Hallo! Lass mich raten, du willst\neinige Tipps für die Arena?\lNun, diese Arena spezialisiert sich\lauf Plfanzen Pokémon. Der Leiter\lMia benutzt sie eindrucksvoll. Am\lbesten kannst du ihr mit Flug oder\lFeuer Pokémon begegnen."



str_0x81b354:
    .string "Ich wusste, dass du Mia schlagen\nkannst."


.elseif LANG_EN

.endif


ow_script_map_7_10_trainer_0:
lock
faceplayer
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b507
trainerbattlecont 0x1 0x19f 0x0 str_0x81b548 str_0x81b611 ow_script_0x81b512


ow_script_0x81b512:
loadpointer 0x0 str_0x81b6b4
callstd MSG
fanfare 0x104
loadpointer 0x0 str_0x81b747
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0x81b772
callstd MSG
copyvarifnotzero 0x8000 ITEM_TM19
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x81b828
callstd MSG
setflag FRBADGE_2
release
end


ow_script_0x81b507:
loadpointer 0x0 str_0x81b652
callstd MSG
release
end


.ifdef LANG_GER

str_0x81b548:
    .string "Oh! Ein Herausforderer! NunDOTS\nIch bin Mia, die Arenaleiterin der\lSilvania Arena. Ich habe mich auf\lPflanzenpokemon spezialisiert! Lass\lmich sehen, was du meiner Stärke\lentgegenzusetzten kannst!"



str_0x81b611:
    .string "Nett gekämpft, PLAYER! Du hast\ndir den Wiesenorden verdient!Ô BñラËÁ"



str_0x81b6b4:
    .string "Das war wirklich ein toller\nKampf! Du hast meine schönen\lPflanzen in Grund und Boden\lgestampft. Diesen Wiesenorden hast\ldu dir echt verdient!"



str_0x81b747:
    .string "PLAYER erhält den Wiesenorden von\nMia.ぁß ñ¡ÁÁ"



str_0x81b772:
    .string "Der Wiesenorden ermöglicht es dir\ndie VM Zerschneider auch außerhalb\leines Kampfes einzusetzten. Nimm\ldas hier, als Geschenk von mir, für\ldeine Glanzleistung in unserem\lKampf."



str_0x81b828:
    .string "Diese TM enthält Gigasauger. Sie\nsaugt dem Gegner KP ab und fügt sie\ldeinem eigenen hinzu. Eine famose\lAttacke für alle Pflanzenpokemon.\l"



str_0x81b652:
    .string "Dank dem Wiesenorden kannst du nun\ndie VM Zerschneider auch außerhalb\leines Kampfes benutzten.t"


.elseif LANG_EN

.endif