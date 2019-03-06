.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x953c85
ow_script_0x953c85:
checkflag ORINA_CITY_TM_MATSCHBOMBE
gotoif EQUAL ow_script_0x953cb2
lock
faceplayer
loadpointer 0x0 str_0x9552a7
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM36
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x955217
callstd MSG
setflag ORINA_CITY_TM_MATSCHBOMBE
release
end


.global ow_script_0x953cb2
ow_script_0x953cb2:
loadpointer 0x0 str_0x9551cc
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9552a7

str_0x9552a7:
    .string "Ich bin fertig mit der Laz.Corp.\nProfessor Primus\' Wahn von einem\linterdimensionalen Portal geht\lentschieden zu weit.\lDass er die radioaktiven Abfälle\leinfach so unverfroren entsorgtDOTS\lSo kann ich nicht arbeiten."
        
        
.global str_0x955217

str_0x955217:
    .string "Nimm diese Technische Maschine,\nsie ist das Sinnbild für die\lUmweltverschmutzung durch die\lLaz.Corp.\pIch will damit nichts mehr zu tun\nhaben."
        
        
.global str_0x9551cc

str_0x9551cc:
    .string "Matschbombe vergiftet den Gegner,\nwie die Laz.Corp die Umwelt\lvergiftet."
        
        
.elseif LANG_EN

.endif
