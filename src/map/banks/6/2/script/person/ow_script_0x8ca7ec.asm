.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8ca8f6
ow_script_movs_0x8ca8f6:
.byte STEP_UP
.byte STOP


.global ow_script_0x8ca7ec
ow_script_0x8ca7ec:
checkflag FRBADGE_1
gotoif EQUAL ow_script_0x8ca829
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8ca8f9
callstd MSG_FACE
special 0x7
applymovement 0x800f ow_script_movs_0x8ca8f6
waitmovement 0x0
hidesprite 0x800f
goto ow_script_0x8f6d7a


.global ow_script_0x8f6d7a
ow_script_0x8f6d7a:
setvar STORY_PROGRESS 0x12
clearflag AKTANIA_LESTER_ARENA
warp 0x6 0x1 0x0 0x0 0x0
end


.global ow_script_0x8ca829
ow_script_0x8ca829:
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8ca83f
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x8ca8f9

str_0x8ca8f9:
	.autostring 36 2 "Vor langer Zeit erbauten meine Vorfahren diesen Tempel und die Wunderwerke darin.\pIch werde dich jetzt in die Kampfarena im Untergrund führen."

        
.global str_0x8ca83f

str_0x8ca83f:
	.autostring 36 2 "Ich werde auch in Zukunft über diesen Ort wachen, wie es die Tradition meiner Familie ist.\pAuf dieses Vermächtnis bin ich äußerst stolz."
        
.elseif LANG_EN

.endif
