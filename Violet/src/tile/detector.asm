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

.ifdef LANG_GER

	str_detector:
		.string "Der Detektor schlägt aus!\nIn der Nähe muss ein Item liegen!"

	str_trainer_tipp_detektor:
		.string "Trainer-Tipp!\nDer Detektor kann in den Optionen\lausgeschaltet werden!"

.elseif LANG_EN

	str_detector:
		.string "Your detector seems to have\nfound an item nearby!"

	str_trainer_tipp_detektor:
		.string "Trainer-Tipp!\nYou can turn off the detector\lin the options!"
.endif
