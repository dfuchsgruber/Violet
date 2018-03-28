.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8471b0
ow_script_0x8471b0:
loadpointer 0x0 str_0x8c0eba
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c0eba

str_0x8c0eba:
    .string "Einst war Harren Bürgermeister\ndieser Stadt. Er und seine Gestein\lPokémon waren eine Berühmtheit.\pNach dem Meteoriteneinschlag aber\nübernahm sein Sohn Lester das Amt\ldes Bürgermeisters und\lArenaleiters."
        
        
.elseif LANG_EN

.endif
