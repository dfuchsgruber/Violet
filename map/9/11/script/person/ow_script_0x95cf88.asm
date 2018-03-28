.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95cf88
ow_script_0x95cf88:
loadpointer 0x0 str_0x95cf92
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95cf92

str_0x95cf92:
    .string "Dass meine Frau ihren Vater bei\nuns wohnen lässt, stört mich\lprinzipiell zwar nicht...\pAber diese schrecklichen\nLebensweisheiten, mit denen er die\lFamilie bei Langeweile hält..."
        
        
.elseif LANG_EN

.endif
