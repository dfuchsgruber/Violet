.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"

@ ToDo: Investigate the letter-casing

.global ow_script_0x8185e5
ow_script_0x8185e5:
loadpointer 0x0 str_0x818ef3
callstd MSG
setflag FRBADGE_2
end


.ifdef LANG_GER
.global str_0x818ef3

str_0x818ef3:
    .string "Hihi."
        
        
.elseif LANG_EN

.endif
