.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_4_2_person_0

ow_script_map_4_2_person_0:
loadpointer 0x0 str_0x881901
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x881901:
    .autostring 34 2 "Oh, hallo PLAYER!\pWie geht es dir heute?\pDas ist gut zu hören!\nGrüß doch bitte deine Mutter von mir."
.elseif LANG_EN
str_0x881901:
    .autostring 32 2 "Oh, hello there, PLAYER!\pHow are you today?\pThat's great to hear!"
.endif