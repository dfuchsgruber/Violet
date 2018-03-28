.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c5a6
ow_script_0x81c5a6:
getplayerpos 0x8000 0x8001
call ow_script_0x89ba6e
settrainerflag 0x3
trainerbattlecont 0x1 0x3 0x0 str_0x81c4e9 str_0x81c4e9 ow_script_0x8ecbe0


.global ow_script_0x8ecbe0
ow_script_0x8ecbe0:
goto ow_script_0x8ecbfa


.global ow_script_0x8ecbfa
ow_script_0x8ecbfa:
additem ITEM_SONDERBONBON 0x63
call ow_script_0x89ba6e
loadpointer 0x0 str_0x81c4e9
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER
.global str_0x81c4e9

str_0x81c4e9:
    .string "koo"
        
        
.elseif LANG_EN

.endif
