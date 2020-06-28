.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_4_4_person_1
.global ow_script_map_4_4_person_0

ow_script_map_4_4_person_0:
loadpointer 0x0 str_0x8a08b0
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8a08b0:
    .autostring 34 2 "Ich war mal ein sehr berühmter Trainer!\pIch habe sogar einmal den großen Lucius selbst herausgefordert!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu glaubst mir nicht?\pKann ich dir nicht verübeln, immerhin bin ich jetzt ein alter MannDOTS"
.elseif LANG_EN
str_0x8a08b0:
    .autostring 34 2 "I used to be a very famous trainer!\pI once even fought the famous Lucius himself.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pCan't blame you since I am an old man now."
.endif


ow_script_map_4_4_person_1:
loadpointer 0x0 str_0x8a0909
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8a0909:
    .autostring 34 2 "Findest du nicht auch, dass Anemonia der perfekte Ort für einen Trainer ist, sich zur Ruhe zu setzen?"
.elseif LANG_EN
str_0x8a0909:
    .autostring 34 2 "Don't you also think Anemonia is the perfect place for a trainer to retire?"
.endif