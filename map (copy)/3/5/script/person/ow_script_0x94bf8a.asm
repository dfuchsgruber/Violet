.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bf8a
ow_script_0x94bf8a:
loadpointer 0x0 str_0x94e011
callstd MSG_FACE
end

.global str_0x94e011

str_0x94e011:
    .string "Ich bin Teil einer berüchtigten\nMotorrad Gang, den den\lGiratina-Bikern!"
        
        