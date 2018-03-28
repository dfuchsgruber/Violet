.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95a869
ow_script_0x95a869:
loadpointer 0x0 str_0x95a873
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a873

str_0x95a873:
    .string "Das Bild zeigt eine gigantische\ngrüne Schlange, die sich flink\ldurch das Wolkenmeer windet."
        
        
.elseif LANG_EN

.endif
