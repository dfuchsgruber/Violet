.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x8dcf8a
ow_script_movs_0x8dcf8a:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8dcf31
ow_script_movs_0x8dcf31:
.byte STEP_UP
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8dcf2e
ow_script_movs_0x8dcf2e:
.byte STEP_UP
.byte STOP


.global ow_script_0x8dce86
ow_script_0x8dce86:
lockall
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8dcf8d
callstd MSG_KEEPOPEN
special 0xF
loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8de230
callstd MSG_KEEPOPEN
special 0xF
sound 0x15
applymovement 0x28 ow_script_movs_0x8dcf8a
waitmovement 0x0
loadpointer 0 str_bewohner
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8dcf36
callstd MSG_KEEPOPEN
special 0xF
applymovement 0x28 ow_script_movs_0x8dcf31
waitmovement 0x0
setdooropened 0x2e 0x14
doorchange
applymovement 0x28 ow_script_movs_0x8dcf2e
waitmovement 0x0
hidesprite 0x28
setdoorclosed 0x2e 0x14
doorchange
loadpointer 0 str_polizist
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8dcee9
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x27
clearflag MERIANA_CITY_DUDE
fadescreen 0x0
addvar MERIANA_CITY_REVOLUTIONARY 0x1
releaseall
end


.ifdef LANG_GER

str_bewohner:
	.string "Bewohner"

str_polizist:
	.string "Polizist"

.global str_0x8dcf8d

str_0x8dcf8d:
	.autostring 36 2 "Denken Sie, dass sie damit durchkommen?\pWenn die Top Vier von Ihren schmutzigen Geschäften erfährtDOTS"
        
        
.global str_0x8de230

str_0x8de230:
	.autostring 36 2 "Sie unterstellen der Polizei hier Ungeheuerliches!\pIch könnte Sie inhaftieren lassen für solche Anschuldingen!"
        
.global str_0x8dcf36

str_0x8dcf36:
    .autostring 36 2 "Inhaftieren?\pDOTS DOTS\pSchon gut, schon gut.\nSie haben gewonnen.\pIch lasse Sie in Ruhe!"
        
        
.global str_0x8dcee9

str_0x8dcee9:
    .autostring 36 2 "Dieser KerlDOTS\pIch sollte mich vielleicht um ihn kümmernDOTS"
        
        
.elseif LANG_EN

.endif
