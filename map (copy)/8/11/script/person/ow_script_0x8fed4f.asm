.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fed4f
ow_script_0x8fed4f:
loadpointer 0x0 str_0x9339fb
callstd MSG_FACE
end

.global str_0x9339fb

str_0x9339fb:
    .string "Viele Pokéstops werden durch\nsteuerfreie Ware finanziert.\pIn vielen Teilen der Region reicht\noft das Budget der Top Vier nicht\laus.\pBesonders in den Distirkten des\nPinken Faun ist das ein Problem."
        
        