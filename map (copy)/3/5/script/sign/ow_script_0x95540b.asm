.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95540b
ow_script_0x95540b:
loadpointer 0x0 str_0x9558a6
callstd MSG_SIGN
end

.global str_0x9558a6

str_0x9558a6:
    .string "Laz.Corp - Wir machen Zukunft zur\nGegenwart"
        
        