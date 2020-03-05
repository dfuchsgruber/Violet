.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x9594c3
ow_script_0x9594c3:
loadpointer 0x0 str_0x95a74c
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a74c

str_0x95a74c:
    .string "Ein weißes, hirschähnliches Wesen,\ndas von einer transzendenten Anmut\lgezeichnet ist, gleitet vor dem\lLicht der Sonne.\pEs wirkt fast wie eine Gottheit."
        
        
.elseif LANG_EN

.endif
