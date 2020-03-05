.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "species.s"

.global ow_script_find_egg
ow_script_find_egg:
callasm overworld_script_egg_buffer_type

loadpointer 0x0 str_pick_up
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL dont_pickup
fanfare 0x13E
loadpointer 0 str_got_egg
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
// Try to put it into the incubator first
special2 LASTRESULT 0x4C
compare LASTRESULT 255
gotoif NOT_EQUAL in_incubator
special2 LASTRESULT 0x47
compare LASTRESULT 2
gotoif EQUAL no_place
compare LASTRESULT 1
callif EQUAL in_box
egg_obtained:
fadescreen 1
hidesprite LASTTALKED
fadescreen 0
return

in_box:
bufferboxname 0x1 0x8010
loadpointer 0 str_in_box
callstd MSG
return

no_place:
loadpointer 0 str_no_place
callstd MSG
return

in_incubator:
loadpointer 0 str_in_incubator
callstd MSG_KEEPOPEN
closeonkeypress
goto egg_obtained

dont_pickup:
closeonkeypress
return

.ifdef LANG_GER

str_pick_up:
	.autostring 35 2 "Dort liegt ein\nBUFFER_1-Ei!\pMöchtest du es aufnehmen?"

str_got_egg:
	.autostring 35 2 "PLAYER hat das\nBUFFER_1-Ei erhalten!"

str_no_place:
	.autostring 35 2 "Es scheint jedoch so, als hättest du weder im Team noch auf dem PC Platz dafür DOTS\pPLAYER lässt das\nBUFFER_1-Ei liegen DOTS"

str_in_box:
	.autostring 35 2 "Es wurde in BUFFER_2\nabgelegt."
str_in_incubator:
	.autostring 34 2 "Es wurde im Inkubator abgelegt."

.elseif LANG_EN
str_in_incubator:
	.autostring 34 2 "It was placed in the incubator."

.endif
