.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fb42c
ow_script_0x8fb42c:
trainerbattlestd 0x0 0x6e 0x0 str_0x9281cc str_0x928233
loadpointer 0x0 str_0x928233
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9281cc

str_0x9281cc:
    .string "Unser Anführer ist einer der\nmächtigsten Trainer der Region.\pEr beherrscht sogar die\nMega-Evolution."
        
        
.global str_0x928233

str_0x928233:
    .string "Du weißt nicht, was die\nMega-Evolution ist?\pKein Wunder, dass du dich nicht\nmit ihm messen kannst."
        
        
.elseif LANG_EN

.endif
