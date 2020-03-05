.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95b718
ow_script_0x95b718:
loadpointer 0x0 str_0x95c90e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95c90e

str_0x95c90e:
    .string "Die Laz.Corp investiert Unsummen\nin völlig abstruse Forschungen.\pProfessor Primus forscht an einer\ntransdimensionalen Portaltechnik.\pEr träumt davon, zu fremden\nGalaxien reisen zu können."
        
        
.elseif LANG_EN

.endif
