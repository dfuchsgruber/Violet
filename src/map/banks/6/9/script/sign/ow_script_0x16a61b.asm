.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x16a61b
ow_script_0x16a61b:
lockall
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x16a62f
loadpointer 0x0 str_0x193a74
callstd MSG_KEEPOPEN
releaseall
end


.global ow_script_0x16a62f
ow_script_0x16a62f:
loadpointer 0x0 str_0x193aaf
callstd MSG_KEEPOPEN
releaseall
end


.ifdef LANG_GER
.global str_0x193a74

str_0x193a74:
    .string "MARMORIA  ROCKO\pBISHERIGE SIEGER:\nRIVAL"
        
        
.global str_0x193aaf

str_0x193aaf:
    .string "MARMORIA  ROCKO\pBISHERIGE SIEGER:\nRIVAL, PLAYER"
        
        
.elseif LANG_EN

.endif
