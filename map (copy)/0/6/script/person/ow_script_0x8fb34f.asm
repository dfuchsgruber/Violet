.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb34f
ow_script_0x8fb34f:
loadpointer 0x0 str_0x8fb359
callstd MSG_FACE
end

.global str_0x8fb359

str_0x8fb359:
    .string "Da warme Luft aufsteigt, ist es\nhier in der unteren Ebene der\lHöhle angenehm kühl."
        
        