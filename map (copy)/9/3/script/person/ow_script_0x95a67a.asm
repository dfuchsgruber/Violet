.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95a67a
ow_script_0x95a67a:
loadpointer 0x0 str_0x95ab3b
callstd MSG_FACE
end

.global str_0x95ab3b

str_0x95ab3b:
    .string "Ich bewache die Rücklagen der\nOrina City Bank.\lOb ich nur ein einzelner Polizist\lbin?\pÄhm...! Nein! Natürlich nicht.\nHinter dieser Türe sind noch\lhundert weitere..."
        
        