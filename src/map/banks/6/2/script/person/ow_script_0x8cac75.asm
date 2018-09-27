.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8cac75
ow_script_0x8cac75:
trainerbattlestd 0x0 0x12 0x0 str_0x8cac8d str_0x8cad12
loadpointer 0x0 str_0x8cad12
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8cac8d

str_0x8cac8d:
    .string "In diesem Tempel fühle ich mich\nmeinen Gestein-Pokémon sehr nahe.\lIch bin Lester dankbar für diesen\lOrt und werde ihn verteidigen!"
        
        
.global str_0x8cad12

str_0x8cad12:
    .string "Lester erwartet dich bereits. Du\nkannst es sicherlich mit ihm\laufnehmen, aber ob du gewinnen\lwirst, ist eine andere SacheDOTS"
        
        
.elseif LANG_EN

.endif
