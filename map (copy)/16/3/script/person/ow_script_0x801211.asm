.include "overworld_script.s"

.include "std.s"

.global ow_script_0x801211
ow_script_0x801211:
loadpointer 0x0 str_0x936da7
callstd MSG_FACE
end

.global str_0x936da7

str_0x936da7:
    .string "Bis vor kurzem war der\nWassertunnel eingestürzt.\pArenaleiter Manus aus Meriana City\nhat ihn wieder errichtet."
        
        