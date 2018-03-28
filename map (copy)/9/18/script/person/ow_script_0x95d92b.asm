.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95d92b
ow_script_0x95d92b:
loadpointer 0x0 str_0x95d935
callstd MSG_FACE
end

.global str_0x95d935

str_0x95d935:
    .string "Wir dicken Leute haben nicht viele\nFreunde, musst du wissen.\pBloß die kleinen Kinder verachten\nuns nicht wegen unserer Figur..."
        
        