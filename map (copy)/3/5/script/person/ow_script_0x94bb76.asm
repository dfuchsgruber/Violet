.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bb76
ow_script_0x94bb76:
loadpointer 0x0 str_0x94dbda
callstd MSG_FACE
end

.global str_0x94dbda

str_0x94dbda:
    .string "Orina City ist die größte Stadt\nThetos.\pAußerdem ist sie der westlichste\nBereich, der Fauns Kontrolle\lunterliegt."
        
        