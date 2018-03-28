.include "overworld_script.s"

.include "std.s"

.global ow_script_0x813162
ow_script_0x813162:
loadpointer 0x0 str_0x81aafa
callstd MSG_FACE
end

.global str_0x81aafa

str_0x81aafa:
    .string "Ich trainere mein Pokémon um Mia\nherauszufordern."
        
        