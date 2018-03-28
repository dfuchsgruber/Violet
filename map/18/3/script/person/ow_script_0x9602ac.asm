.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x9602ac
ow_script_0x9602ac:
loadpointer 0x0 str_0x963601
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x963601

str_0x963601:
    .string "Der Volcano soll laut der Legende\ndie Heimat eines legendären\lPokémon sein."
        
        
.elseif LANG_EN

.endif
