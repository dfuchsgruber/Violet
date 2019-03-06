.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x800000
ow_script_0x800000:
lock
faceplayer
loadpointer 0x0 str_0x8b4962
callstd MSG
release
end


.ifdef LANG_GER
.global str_0x8b4962

str_0x8b4962:
    .string "ABILITY_NAME_PLAYER\'s Fähigkeit,\nluzid zu träumen, steigert\lseinen Sp.Angr. "
        
        
.elseif LANG_EN

.endif
