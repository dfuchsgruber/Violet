.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x95590a
ow_script_movs_0x95590a:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x9558d3
ow_script_0x9558d3:
lockall
setvar 0x8004 0x26
special 0x1b
waitmovement 0x0
faceplayer

loadpointer 0 str_police
setvar 0x8000 1
special 0xe
loadpointer 0x0 str_0x95590d
callstd MSG
special 0xf

applymovement 0xff ow_script_movs_0x95590a
waitmovement 0x0
setvar 0x8004 0x26
setvar 0x8005 0x24
setvar 0x8006 0x2
special 0x24
waitmovement 0x0
releaseall
end


.ifdef LANG_GER

str_police:
.string "Polizist"

.global str_0x95590d

str_0x95590d:
	.autostring 35 2 "Ich bin untröstlich, aber es wurde eine Straßensperre angeordnet, um die zwei Divisionen von Team Violet, die sich derzeit im Osten Thetos aufhalten, dingfest zu machen.\pIch kann dich nicht passieren lassen!"
.elseif LANG_EN

.endif
