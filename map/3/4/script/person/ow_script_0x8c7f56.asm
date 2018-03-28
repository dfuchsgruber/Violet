.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7f56
ow_script_0x8c7f56:
compare KARMA_VALUE 0x7fff
gotoif HIGHER ow_script_0x8f154f
compare KARMA_VALUE 0x60
gotoif LESS_OR_EQUAL ow_script_0x8f1564
loadpointer 0x0 str_0x8f14e8
callstd MSG_FACE
end


.global ow_script_0x8f1564
ow_script_0x8f1564:
loadpointer 0x0 str_0x8f156e
callstd MSG_FACE
end


.global ow_script_0x8f154f
ow_script_0x8f154f:
compare KARMA_VALUE 0xffa0
gotoif HIGHER_OR_EQUAL ow_script_0x8f1564
loadpointer 0x0 str_0x8f15df
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f14e8

str_0x8f14e8:
    .string "Der Pfad für den du dich\nentschieden hast...\pDu hast ein reines Herz...\pEs wird dich weit bringen..."
        
        
.global str_0x8f156e

str_0x8f156e:
    .string "Mir scheint, du bist dir deiner\nSelbst noch nicht sicher. Folge\ldeinem Herzen, lass es für dich\lentscheiden..."
        
        
.global str_0x8f15df

str_0x8f15df:
    .string "Ich sehe deine Entschlossenheit...\pDu würdest alles tun, um deinen\nWillen durchzusetzten...\pNoch ist es nicht zu spät,\numzukehren..."
        
        
.elseif LANG_EN

.endif
