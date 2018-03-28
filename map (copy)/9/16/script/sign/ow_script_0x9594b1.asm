.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9594b1
ow_script_0x9594b1:
checkflag ORINA_CITY_WOLKENHERZ_STOLEN
gotoif EQUAL ow_script_0x95a5a3
loadpointer 0x0 str_0x95a5b5
callstd MSG_SIGN
end


.global ow_script_0x95a5a3
ow_script_0x95a5a3:
loadpointer 0x0 str_0x95a5b5
callstd MSG_SIGN
loadpointer 0x0 str_0x959487
callstd MSG_SIGN
end

.global str_0x95a5b5

str_0x95a5b5:
    .string "QUOTEDas Wolkenherz - es glitzert in\nden Regenbogenfarben im LichtQUOTE"
        
        
