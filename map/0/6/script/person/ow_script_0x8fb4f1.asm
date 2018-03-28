.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb4f1
ow_script_0x8fb4f1:
loadpointer 0x0 str_0x8fef43
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fef43

str_0x8fef43:
    .string "Vorhin kam ein äußert mysteriöser\nMann hier entlang. Er erzählte von\lden Missständen in den Top Vier\lund wollte mich überzeugen, der\lRevolutionsarmee beizutreten."
        
        
.elseif LANG_EN

.endif
