.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8f1be0
ow_script_0x8f1be0:
loadpointer 0x0 str_0x8f1bea
callstd MSG_FACE
end

.global str_0x8f1bea

str_0x8f1bea:
    .string "Der Küstenberg ist klein, doch\nhoch genug, um bei Sturm einen\langenehm salzigen Wind erleben zu\lkönnen."
        
        