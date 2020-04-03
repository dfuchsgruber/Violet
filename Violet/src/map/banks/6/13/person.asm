.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_6_13_person_1
.global ow_script_map_6_13_person_0

ow_script_map_6_13_person_0:
loadpointer 0x0 str_0x8cb4a1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cb4a1:
    .string "Das Leben an einem trostlosen Ort\nist trübselig.\pAber Lester unternimmt jeden\nVersuch etwas Leben auf diese\lInsel zu bringen. Er ist ein guter\lJunge, wirklich."


.elseif LANG_EN

.endif


ow_script_map_6_13_person_1:
loadpointer 0x0 str_0x8cb542
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8cb542:
    .string "Ben? Bist du es? Bist du mein\nkleiner Ben? Oh Ben! Warst du mit\ldeinen kleinen Freunden am Strand\lspielen?"


.elseif LANG_EN

.endif