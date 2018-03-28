.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e6863
ow_script_0x8e6863:
trainerbattlestd 0x0 0x39 0x0 str_0x8e687b str_0x8e6906
loadpointer 0x0 str_0x8e6906
callstd MSG_FACE
end

.global str_0x8e687b

str_0x8e687b:
    .string "Ich habe Bedenken, weiter östlich\nzu wandern, denn dort liegt eine\ltödliche Wüste. Viele Wanderer\lsollen dort bereits verschwunden\lsein."
        
        
.global str_0x8e6906

str_0x8e6906:
    .string "Vielleicht bleibe ich lieber hier,\nin der Nähe des Silvania-Waldes."
        
        