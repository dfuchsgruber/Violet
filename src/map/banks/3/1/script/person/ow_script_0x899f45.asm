.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x899f45
ow_script_0x899f45:
loadpointer 0x0 str_0x8a2a88
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a2a88

str_0x8a2a88:
    .string "Der Wundertausch ist ein\nausgefallenes System. So kann\ljeder Trainer an die\lverschiedensten Pokémon gelangen.\lSpannend, was?"
        
        
.elseif LANG_EN

.endif
