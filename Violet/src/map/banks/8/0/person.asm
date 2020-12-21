.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_0_person_1
.global ow_script_map_8_0_person_3
.global ow_script_map_8_0_person_2


ow_script_map_8_0_person_3:
loadpointer 0x0 str_0x195c7a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x195c7a:
    .autostring 34 2 "Kaskada gilt als das Herz der Region.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNaja, das stimmt vielleicht nicht ganz, aber für mich ist es die Wahrheit!"
.elseif LANG_EN

.endif


ow_script_map_8_0_person_2:
loadpointer 0x0 str_0x71cdbe
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x71cdbe:
    .autostring 34 2 "Als keines Kind habe ich an den Wasserfällen immer versucht, Staudämme zu bauen.\pDas ist natürlich Kinderkram!\pJetzt interessiere ich mich nur noch für das Kämpfen!"
.elseif LANG_EN

.endif


ow_script_map_8_0_person_1:
loadpointer 0x0 str_0x95aaa5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95aaa5:
    .autostring 34 2 "Nirgendwo in Theto wirst du saubereres Wasser finden als hier in Kaskada.\pDarauf gebe ich dir mein Wort."


.elseif LANG_EN

.endif