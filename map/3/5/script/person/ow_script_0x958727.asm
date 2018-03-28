.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958727
ow_script_0x958727:
loadpointer 0x0 str_0x958731
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x958731

str_0x958731:
    .string "Wir gehören zur zweiten Division\nvon Team Violet.\pUnser Anführer ist noch viel\ngefährlicher als Rin."
        
        
.elseif LANG_EN

.endif
