.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e3fd
ow_script_0x94e3fd:
loadpointer 0x0 str_0x94e407
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e407

str_0x94e407:
    .string "Das kupferfarbene Gebäude im\nNorden der Stadt ist eine Bank.\pAber wenn du mich fragst, solltest\ndu dir von diesen Leuten kein Geld\lleihen..."
        
        
.elseif LANG_EN

.endif
