.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8dce51
ow_script_0x8dce51:
bufferstring 0x0 str_0x8dce63
setvar 0x8000 0x13b
goto ow_script_0x8d421d


.global ow_script_0x8d421d
ow_script_0x8d421d:
loadpointer 0x0 str_0x8d4251
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8d42dc
countpokemon
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x8d42d1
giveegg 0x8000
fanfare 0x13e
loadpointer 0x0 str_0x8d42b4
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
hidesprite 0x800f
end


.global ow_script_0x8d42d1
ow_script_0x8d42d1:
loadpointer 0x0 str_0x8d4280
callstd MSG_KEEPOPEN
closeonkeypress
end


.global ow_script_0x8d42dc
ow_script_0x8d42dc:
closeonkeypress
end

.global str_0x8dce63

str_0x8dce63:
    .string "Normal-"
        
        
.global str_0x8d4251

str_0x8d4251:
    .string "Dort liegt ein Ei!\nMöchtest du es aufnehmen?"
        
        
.global str_0x8d42b4

str_0x8d42b4:
    .string "PLAYER hat ein BUFFER_1-Ei\nerhalten!"
        
        
.global str_0x8d4280

str_0x8d4280:
    .string "Schade! Du hast keinen Platz mehr\nin deinem Team."
        
        