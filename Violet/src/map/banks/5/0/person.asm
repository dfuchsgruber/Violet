.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_5_0_person_0

ow_script_map_5_0_person_0:
loadpointer 0x0 str_0x89f061
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x89f061:
    .string "Vor vielen Jahren und nach\netlichen Kriegen erschuf der\lChampion ein dezentrales\lHerrschaftssystem, das von den Top\lVier geleitet wird."


.elseif LANG_EN

.endif