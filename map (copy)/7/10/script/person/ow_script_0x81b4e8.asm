.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b4e8
ow_script_0x81b4e8:
lock
faceplayer
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b507
trainerbattlecont 0x1 0x19f 0x0 str_0x81b548 str_0x81b611 ow_script_0x81b512


.global ow_script_0x81b512
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


.global ow_script_0x81b507
ow_script_0x81b507:
loadpointer 0x0 str_0x81b652
callstd MSG
release
end

.global str_0x81b548

str_0x81b548:
    .string "Oh! Ein Herausforderer! Nun...\nIch bin MIA, die Arenaleiterin der\lSILVANIA Arena. Ich habe mich auf\lPflanzenpokemon spezialisiert! Lass\lmich sehen, was du meiner Stärke\lentgegenzusetzten kannst!"
        
        
.global str_0x81b611

str_0x81b611:
    .string "Nett gekämpft, PLAYER! Du hast\ndir den Wiesenorden verdient!Ô BñラËÁ"
        
        
.global str_0x81b6b4

str_0x81b6b4:
    .string "Das war wirklich ein toller\nKampf! Du hast meine schönen\lPflanzen in Grund und Boden\lgestampft. Diesen Wiesenorden hast\ldu dir echt verdient!"
        
        
.global str_0x81b747

str_0x81b747:
    .string "PLAYER erhält den WIESENORDEN von\nMIA.ぁß ñ¡ÁÁ"
        
        
.global str_0x81b772

str_0x81b772:
    .string "Der WIESENORDEN ermöglicht es dir\ndie VM Zerschneider auch außerhalb\leines Kampfes einzusetzten. Nimm\ldas hier, als Geschenk von mir, für\ldeine Glanzleistung in unserem\lKampf."
        
        
.global str_0x81b828

str_0x81b828:
    .string "Diese TM enthält GIGASAUGER. Sie\nsaugt dem Gegner KP ab und fügt sie\ldeinem eigenen hinzu. Eine famose\lAttacke für alle Pflanzenpokemon.\l"
        
        
.global str_0x81b652

str_0x81b652:
    .string "Dank dem Wiesenorden kannst du nun\ndie VM Zerschneider auch außerhalb\leines Kampfes benutzten.t"
        
        