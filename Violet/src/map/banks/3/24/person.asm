.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_24_person_0
.global ow_script_map_3_24_person_1

ow_script_map_3_24_person_0:
loadpointer 0x0 str_0x95ee37
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ee37:
    .string "Ich würde mir gut überlegen, ob\nich weiter nach Westen geheDOTS\pEs heißt, dass die Hitze des\nVulcano einem das Hirn versengtDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_24_person_1:
loadpointer 0x0 str_0x95eec1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95eec1:
    .string "Einer Legende nach lebt im Volcano\nein gruseliges Dämonenpokémon.\pEs spuckt Feuer und sein Atem\nentzündet Wälder."


.elseif LANG_EN

.endif