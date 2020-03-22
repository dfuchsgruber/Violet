.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x916cb3
ow_script_0x916cb3:
trainerbattledouble 0x4 0x16b 0 str_challange str_defeat str_one_poke
loadpointer 0x0 str_defeat
callstd MSG_FACE
end


.ifdef LANG_GER
str_challange:
    .autostring 34 2 "Mein Liebling und ich werden dich mit der Kraft unserer Liebe besiegen!"
str_defeat:
    .autostring 34 2 "Was, das kann nicht sein?\pNichts ist stärker als unsere Liebe!"
str_one_poke:
    .autostring 34 2 "Du willst allein gegen ein Liebespaar antreten?\pDas würde ich mir an deiner Stelle überlegen."      

.elseif LANG_EN

.endif
