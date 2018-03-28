.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86c22d
ow_script_0x86c22d:
loadpointer 0x0 str_0x926aaa
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x926aaa

str_0x926aaa:
    .string "Interessant sind die goldenen\nKakteen in dieser Wüstenregion. In\lihnen leben manchmal Pokémon."
        
        
.elseif LANG_EN

.endif
