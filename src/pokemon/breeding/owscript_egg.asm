.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"

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
giveegg 0x8000 @// 0x8010 holds the box, 0x8011 the id in box
compare LASTRESULT 2
gotoif EQUAL no_place
compare LASTRESULT 1
callif EQUAL in_box
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

.elseif LANG_EN

.endif
