.include "overworld_script.s"

.include "std.s"

.global ow_script_0x862410
ow_script_0x862410:
loadpointer 0x0 str_0x8f384c
callstd MSG_FACE
end

.global str_0x8f384c

str_0x8f384c:
    .string "Vor einiger Zeit gab es großen\nAufruhr in Theto, als ein junges\lTrainertalent den Champion\lentthront hat.\lNiemand weiß so recht, wo der\lbesiegte Champion geblieben ist..."
        
        