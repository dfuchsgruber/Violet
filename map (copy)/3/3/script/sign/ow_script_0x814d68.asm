.include "overworld_script.s"

.include "std.s"

.global ow_script_0x814d68
ow_script_0x814d68:
loadpointer 0x0 str_0x8deaae
callstd MSG_SIGN
end

.global str_0x8deaae

str_0x8deaae:
    .string "Arena von Silvania\pTyp: Pflanze\nLeiter: Mia"
        
        