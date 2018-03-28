.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c22d
ow_script_0x86c22d:
loadpointer 0x0 str_0x926aaa
callstd MSG_FACE
end

.global str_0x926aaa

str_0x926aaa:
    .string "Interessant sind die goldenen\nKakteen in dieser Wüstenregion. In\lihnen leben manchmal Pokémon."
        
        