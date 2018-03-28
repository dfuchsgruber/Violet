.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ecd05
ow_script_0x8ecd05:
loadpointer 0x0 str_0x92816c
callstd MSG
end


.ifdef LANG_GER
.global str_0x92816c

str_0x92816c:
    .string "Die Herrschaft von Unredlichkeit\nund Geld wird mit uns ein Ende\lfinden. Albus wird uns retten."
        
        
.elseif LANG_EN

.endif
