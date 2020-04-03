.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_11_person_1
.global ow_script_map_5_11_person_0

ow_script_map_5_11_person_0:
loadpointer 0x0 str_0x8a336a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a336a:
    .string "Der Kontinent Theto wurde einst\nvom Wächter der Landmassen Groudon\lals erster Kontintent der Welt\lgeschaffen. Man nennt ihn daher\lauch Urkontinent."


.elseif LANG_EN

.endif


ow_script_map_5_11_person_1:
loadpointer 0x0 str_0x8a33ff
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a33ff:
    .string "Mein Großvater ist ein\nGeschichtsfanatiker. Er kennt\lviele Lengenden und Mythen. Dafür\lkann ich mich allerdings nicht\lbegeistern. Mich interessiert nur\ldie neuste Mode!"


.elseif LANG_EN

.endif