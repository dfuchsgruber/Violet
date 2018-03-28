.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e6b2
ow_script_0x95e6b2:
loadpointer 0x0 str_0x95f573
callstd MSG_FACE
end

.global str_0x95f573

str_0x95f573:
    .string "Der Aschhain ist ein kleiner Wald\nam Fuße eines kleinen Hügels.\pAlles dreht sich um das kleine, an\ndiesem Ort..."
        
        