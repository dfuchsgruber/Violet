.include "overworld_script.s"
.include "vars.s"
.include "attacks.s"
.include "callstds.s"
.include "ordinals.s"

.global ow_script_surf_not_usable_stream_too_strong
ow_script_surf_not_usable_stream_too_strong:
lockall
loadpointer 0 str_stream_too_strong
callstd MSG_KEEPOPEN
releaseall
end

.global ow_script_prompt_surf
ow_script_prompt_surf:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL prompt_surfer_none
checkattack ATTACK_SURFER
compare LASTRESULT 0x6
gotoif EQUAL prompt_surfer_none
bufferpartypokemon 0x0 LASTRESULT
setanimation 0x0 LASTRESULT
lockall
loadpointer 0 str_prompt_surf
callstd MSG_YES_NO
compare LASTRESULT 0
gotoif EQUAL prompt_surfer_end
loadpointer 0 str_use_surf
callstd MSG_KEEPOPEN
doanimation 0x9
prompt_surfer_end:
releaseall
prompt_surfer_none:
end

.global ow_script_waterfall_not_available
ow_script_waterfall_not_available:
lockall
ow_script_waterfall_not_available_print_text:
loadpointer 0 str_waterfall_not_avialable
callstd MSG_KEEPOPEN
releaseall
end

.global ow_script_prompt_waterfall
ow_script_prompt_waterfall:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL prompt_waterfall_end
lockall
checkattack ATTACK_KASKADE
compare LASTRESULT 0x6
gotoif EQUAL ow_script_waterfall_not_available_print_text
bufferpartypokemon 0x0 LASTRESULT
setanimation 0x0 LASTRESULT
loadpointer 0 str_prompt_waterfall
callstd MSG_YES_NO
compare LASTRESULT 0
gotoif EQUAL prompt_waterfall_end
loadpointer 0 str_use_waterfall
callstd MSG_KEEPOPEN
doanimation 0x2B
prompt_waterfall_end:
release
end


.ifdef LANG_GER
str_stream_too_strong:
	.autostring 34 2 "Die Strömung ist zu stark!\nSurfer kann hier nicht eingesetzt werdenDOTS"
str_prompt_surf:
	.autostring 34 2 "Das Wasser ist tiefblau.\nMöchtest du Surfer einsetzen?"
str_use_surf:
	.autostring 34 2 "BUFFER_1 setzt Surfer ein."
str_waterfall_not_avialable:
	.autostring 34 2 "Das Wasser fällt steil wie eine Wand brüllend in die Tiefe."
str_prompt_waterfall:
	.autostring 34 2 "Ein riesiger Wasserfall.\nMöchtest du Kaskade einsetzten?"
str_use_waterfall:
	.autostring 34 2 "BUFFER_1 setzt Kaskade ein."

.elseif LANG_EN
str_stream_too_strong:
	.autostring 34 2 "The stream is too strong.\nSurfer can not be used hereDOTS"
str_prompt_surf:
	.autostring 34 2 "The water is deep and blue.\nDo you want to use Surf?"
str_use_surf:
	.autostring 34 2 "BUFFER_1 used Surf."
str_waterfall_not_avialable:
	.autostring 34 2 "The water is crashing down into the deep."
str_prompt_waterfall:
	.autostring 34 2 "The water is crashing down into the deep.\pDo you want to use Waterfall?"
str_use_waterfall:
	.autostring 34 2 "BUFFER_1 uses Waterfall."

.endif

