.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x89a12b
ow_script_0x89a12b:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x89a168
lockall
setvar 0x8004 0x20
special 0x17d
setvar 0x8004 0x1
special 0xd6
sound 0x4
loadpointer 0x0 str_0x1a8124
callstd MSG
special 0xf9
waitstate
special 0x120
clearflag TRANS_DISABLE
releaseall
end


.global ow_script_0x89a168
ow_script_0x89a168:
clearflag TRANS_DISABLE
release
end


.ifdef LANG_GER
.global str_0x1a8124

str_0x1a8124:
    .string "PLAYER schaltet den PC ein."
        
        
.elseif LANG_EN

.endif
