.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_6_9_sign_0
.global ow_script_0x16a62f

ow_script_map_6_9_sign_0:
lockall
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x16a62f
loadpointer 0x0 str_0x193a74
callstd MSG_KEEPOPEN
releaseall
end


ow_script_0x16a62f:
loadpointer 0x0 str_0x193aaf
callstd MSG_KEEPOPEN
releaseall
end


.ifdef LANG_GER

str_0x193a74:
    .string "Marmoria  Rocko\pBisherige Sieger:\nRIVAL"



str_0x193aaf:
    .string "Marmoria  Rocko\pBisherige Sieger:\nRIVAL, PLAYER"


.elseif LANG_EN

.endif