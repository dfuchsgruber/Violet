.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81b337
ow_script_0x81b337:
checkflag FRBADGE_2
gotoif EQUAL ow_script_0x81b34a
loadpointer 0x0 str_0x81b37f
callstd MSG_FACE
end


.global ow_script_0x81b34a
ow_script_0x81b34a:
loadpointer 0x0 str_0x81b354
callstd MSG_FACE
end

.global str_0x81b37f

str_0x81b37f:
    .string "Hallo! Lass mich raten, du willst\neinige Tipps für die Arena?\lNun, diese Arena spezialisiert sich\lauf Plfanzen Pokémon. Der Leiter\lMIA benutzt sie eindrucksvoll. Am\lbesten kannst du ihr mit Flug oder\lFeuer Pokémon begegnen."
        
        
.global str_0x81b354

str_0x81b354:
    .string "Ich wusste, dass du MIA schlagen\nkannst."
        
        