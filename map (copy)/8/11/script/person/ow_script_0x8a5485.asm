.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a5485
ow_script_0x8a5485:
goto ow_script_0x8fadb7


.global ow_script_0x8fadb7
ow_script_0x8fadb7:
compare WONDERTRADE_STEPS_TO_ENABLE 0xfa
gotoif LESS ow_script_0x8f71d9
goto ow_script_0x8f6d95


.global ow_script_0x8f6d95
ow_script_0x8f6d95:
fadescreen 0x1
callasm 0x9198441
sound 0x2
checksound
loadpointer 0x0 str_0x8a5bb9
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8d059f
closeonkeypress
fadescreen 0x1
callasm 0x9198781
special 0xb
end


.global ow_script_0x8d059f
ow_script_0x8d059f:
closeonkeypress
fadescreen 0x1
callasm 0x919d791
special 0x9f
waitstate
clearflag MAP_BGN_AUTO_ALIGN_OFF
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x8a5444
copyvar 0x8005 0x8004
special 0x11
special 0xfe
waitstate
goto ow_script_0x8fadcc


.global ow_script_0x8fadcc
ow_script_0x8fadcc:
callasm 0x9198781
setvar WONDERTRADE_STEPS_TO_ENABLE 0x0
end


.global ow_script_0x8a5444
ow_script_0x8a5444:
end


.global ow_script_0x8f71d9
ow_script_0x8f71d9:
buffernumber 0x0 0x50e2
loadpointer 0x0 str_0x8fad70
callstd MSG
end

.global str_0x8a5bb9

str_0x8a5bb9:
    .string "Die Wundertausch-App wurde\naktiviert.\pMöchtest du einen Wundertausch\ndurchführen?"
        
        
.global str_0x8fad70

str_0x8fad70:
    .string "Die Batterie des Wundertauschs\nbeträgt BUFFER_1/250.\pHab noch etwas Geduld!"
        
        