.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_10_12_person_0
.global ow_script_map_10_12_person_1
.global ow_script_map_10_12_person_3
.global ow_script_map_10_12_person_2

ow_script_map_10_12_person_0:
lock
faceplayer
call ow_script_0x1a9429
release
end


ow_script_map_10_12_person_2:
loadpointer 0x0 str_0x965e52
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965e52:
    .string "Wir in Inferior sind nicht\nunbedingt zufrieden mit den\lVerhältnissen.\pGrenzgebiete wie dieses sind unter\nden Top Vier sehr umkämpft und am\lEnde muss der einfache Mann dafür\lbezahlen."


.elseif LANG_EN

.endif


ow_script_map_10_12_person_1:
loadpointer 0x0 str_0x965f0a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965f0a:
    .string "Das Sortiment in den\nVerkaufsabteilungen der Pokéstops\lwird laufend erweitert.\pSo haben sich nun auch Hyperbälle\ndort eingefunden.\pEin Glück, dass diese\nhochentwickelten Pokébälle nun für\ldie Masse verfügbar sind."


.elseif LANG_EN

.endif


ow_script_map_10_12_person_3:
loadpointer 0x0 str_0x965fe1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965fe1:
    .string "Ich traue mich nicht, den Vulkan\nzu besteigenDOTS\pWas, wenn er gerade dann\nausbricht, während ich vor dem\lSchlot stehe?"


.elseif LANG_EN

.endif