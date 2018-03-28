.include "overworld_script.s"

.include "std.s"

.global ow_script_0x16a9b1
ow_script_0x16a9b1:
loadpointer 0x0 str_0x194666
callstd MSG_FACE
end

.global str_0x194666

str_0x194666:
    .string "Vor vielen Jahren riefen drei\njunge Trainertalente das System\lder Top Vier ins Leben."
        
        