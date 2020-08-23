.include "vars.s"

.global lscr_0x8f5100

lscr_0x8f5100:
	.byte 0x3
.word ow_script_0x8112fd
	.byte 0x2
.word lscr_0x719b77
	.byte 0x0




.align 4
.global lscr_0x719b77

lscr_0x719b77:
	.hword STORY_PROGRESS, 0x14
	.word ow_script_0x8d3195
	.hword 0x0
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x8d3195
.global ow_script_0x92eadc
.global ow_script_0x8de677
.global ow_script_0x8caf33
.global ow_script_0x8112fd

ow_script_0x8112fd:
checkflag FRBADGE_1
callif EQUAL ow_script_0x8caf33
end


ow_script_0x8caf33:
movesprite2 0x6 0x1c 0x31
spritebehave 0x6 0x2
movesprite2 0x2f 0x25 0x34
spritebehave 0x2f 0x2
movesprite2 0x23 0x23 0x2b
movesprite2 0x24 0x27 0x29
movesprite2 0x25 0x2c 0x26
movesprite2 0x26 0x34 0x29
movesprite2 0x27 0x36 0x2e
movesprite2 0x28 0x35 0x32
movesprite2 0x29 0x38 0x34
movesprite2 0x2a 0x1f 0x2e
return


ow_script_0x8d3195:
checkflag AKTANIA_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8de677
goto ow_script_0x92eadc


ow_script_0x92eadc:
lockall
fadesong 0
loadpointer 0x0 str_0x92ec17
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
fadescreen 0x1
sound 0x64
checksound
callasm cmdx2D_force_pals_to_black
clearflag PKMNMENU
setvar STORY_PROGRESS 0x15
writebytetooffset 0x2 0x2036e28
warpmuted 0x3 0x49 0xff 0x23 0x24
end


ow_script_0x8de677:
loadpointer 0x0 str_0x92eb38
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
addvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER

str_0x92ec17:
	.autostring 35 2 "Was ist das für ein seltsames Gefühl?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMir wird schwarz DOTS DOTS DOTS\nvor den AugenDOTS DOTS DOTS"

str_0x92eb38:
    .autostring 35 2 "Was bei Arceus war das denn?\pEs hat sich so ähnlich angefühlt, wie mein Traum vor KurzemDOTS\pOb da ein Zusammenhang besteht?\pUnd was ich da gesehen habeDOTS DOTS DOTS\pWar das die Katastrophe, die für die Zerstörung Bruchfelss verantwortlich ist?\pWas war das für ein seltsames Pokémon?\pUnd ist es mit dem Meteoriten hierher gelangt?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pZu viele FragenDOTS DOTS DOTS\pIch kann mir noch keinen Reim darauf machenDOTS DOTS DOTS"

.elseif LANG_EN

.endif