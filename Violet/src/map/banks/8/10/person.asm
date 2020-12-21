.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_10_person_1
.global ow_script_map_8_10_person_0

ow_script_map_8_10_person_1:
loadpointer 0x0 str_0x9277cd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9277cd:
    .autostring 34 2 "Als ein Pflanzen-Pokémon Liebhaber würde ich am Liebsten in Kranzdorf wohnen.\pMeine Frau allerdings ist von der Milotic-Legende um Kaskada ganz begeistert.\pAlso haben wir uns für einen Kompromiss entschiedenDOTS\pDOTSund sind hierher nach Kaskada gezogenDOTS"
.elseif LANG_EN

.endif


ow_script_map_8_10_person_0:
loadpointer 0x0 str_0x9278f8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9278f8:
    .autostring 34 2 "Bist du auch angereist, um das legendäre Milotic zu Gesicht zu bekommen?\pDa muss ich dich enttäuschen!\pIch kenne niemanden, der es bislang gesehen hat."
.elseif LANG_EN

.endif