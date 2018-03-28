.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a218c
ow_script_0x8a218c:
loadpointer 0x0 str_0x8a336a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a336a

str_0x8a336a:
    .string "Der Kontinent Theto wurde einst\nvom Wächter der Landmassen Groudon\lals erster Kontintent der Welt\lgeschaffen. Man nennt ihn daher\lauch Urkontinent."
        
        
.elseif LANG_EN

.endif
