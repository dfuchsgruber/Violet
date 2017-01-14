.include "overworld_script.s"

.global script_detector_alert_only
.global script_detector_all

trainer_tipp:
checkflag 0x964
gotoif 1 ret_trainer_tipp
sound 366
loadpointer 0 str_trainer_tipp_detektor
callstd 4
checksound
setflag 0x964
ret_trainer_tipp:
return

script_detector_alert_only:
setvar 0x8004 0
goto script_detector

script_detector_all:
setvar 0x8004 1
goto script_detector

script_detector:
lockall
call trainer_tipp
sound 0x30
applymovement 0xFF exclam
waitmovement 0
checksound
sound 0x30
checksound
sound 0x30
checksound
compare 0x8004 0
gotoif 0x1 ret_script_detector
loadpointer 0 str_detector
callstd 6
ret_script_detector:
releaseall
end

exclam:
.byte 0x62
.byte 0xFE

