.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x961337
ow_script_0x961337:
trainerbattlestd 0x0 0x9f 0x0 str_0x962fde str_0x96313e
loadpointer 0x0 str_0x96313e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x962fde

str_0x962fde:
    .string "Ich verschicke viele meiner\ngezüchteten Pokémon im\lWundertausch, um dann auch fremde\lPokémon aufzuziehen."
        
        
.global str_0x96313e

str_0x96313e:
    .string "Willst du mir eines deiner Pokémon\nüberlassen? Sie sind stark!"
        
        
.elseif LANG_EN

.endif
