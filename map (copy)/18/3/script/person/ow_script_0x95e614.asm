.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e614
ow_script_0x95e614:
loadpointer 0x0 str_0x95e61e
callstd MSG_FACE
end

.global str_0x95e61e

str_0x95e61e:
    .string "Es ist schon faszinierend, dass\ndas Pokéradar selbst unter den\lwidrigen Bedingungen hier noch\leinwandfrei funktioniert."
        
        