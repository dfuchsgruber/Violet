.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bf66
ow_script_0x94bf66:
loadpointer 0x0 str_0x94dd5d
callstd MSG_FACE
end

.global str_0x94dd5d

str_0x94dd5d:
    .string "Findest du es etwa witzig, dass\nich als emertierte Trainerin\lmeinen Unterhalt mit dem Sammeln\lvon Pfandflaschen machen muss?"
        
        