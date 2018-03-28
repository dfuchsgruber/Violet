.include "overworld_script.s"

.include "std.s"

.global ow_script_0x829b64
ow_script_0x829b64:
compare STORY_PROGRESS 0x12
gotoif HIGHER ow_script_0x829b7e
loadpointer 0x0 str_0x8bf98a
callstd MSG_FACE
singlemovement 0x2f 0x2
end


.global ow_script_0x829b7e
ow_script_0x829b7e:
loadpointer 0x0 str_0x8bf8d8
callstd MSG_FACE
end

.global str_0x8bf98a

str_0x8bf98a:
    .string "Es wird wohl sicher noch eine\nWeile dauern, bis wir diese ganzen\lVoltilamm wieder eingezäunt haben."
        
        
.global str_0x8bf8d8

str_0x8bf8d8:
    .string "Wir züchten alle Arten von\nPokémon. Allen voran Vögel und\lVoltilamm. Wenn wie sie scheren,\lkönnen wir die Wolle teuer\lverkaufen. Und Elektrizität\lstellen sie auch noch bereit."
        
        