.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e221b
ow_script_0x8e221b:
loadpointer 0x0 str_0x8e66ad
callstd MSG_FACE
end

.global str_0x8e66ad

str_0x8e66ad:
    .string "Pokémon, die sich durch Tausch\nentwickeln, können ihre Evolution\lstattdessen mithilfe eines\lsimulierten Tauschs durchführen.\pEin Linkkabel wird dazu aber\nbenötigt, und man sagt sich, dass\ldiese äußert selten sind."
        
        