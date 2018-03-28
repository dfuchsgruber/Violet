.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a0009
ow_script_0x8a0009:
loadpointer 0x0 str_0x958e8b
callstd MSG_FACE
end

.global str_0x958e8b

str_0x958e8b:
    .string "Es ist mein Traum, eines Tages\nselbst ein Fossil auszugraben und\ldamit dieses Museum zu bereichern."
        
        