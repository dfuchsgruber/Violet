.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e685
ow_script_0x94e685:
loadpointer 0x0 str_0x94e68f
callstd MSG_FACE
end

.global str_0x94e68f

str_0x94e68f:
    .string "Professor Primus ist der genialste\nKopf des Landes.\pMit seinen Abhandlungen über\ninterstellares Reisen hat er unser\lWeltbild im Bezug auf das All\lentscheidend verändert."
        
        