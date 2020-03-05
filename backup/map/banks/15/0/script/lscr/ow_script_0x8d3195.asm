.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x8d3195
ow_script_0x8d3195:
checkflag AKTANIA_FLASHBACK_DONE
gotoif EQUAL ow_script_0x8de677
goto ow_script_0x92eadc


.global ow_script_0x92eadc
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


.global ow_script_0x8de677
ow_script_0x8de677:
loadpointer 0x0 str_0x92eb38
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
addvar STORY_PROGRESS 0x2
releaseall
end


.ifdef LANG_GER
.global str_0x92ec17

str_0x92ec17:
	.autostring 35 2 "Was ist das für ein seltsames Gefühl?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMir wird schwarz DOTS DOTS DOTS\nvor den AugenDOTS DOTS DOTS"
.global str_0x92eb38

str_0x92eb38:
    .autostring 35 2 "Was bei Arceus war das denn?\pEs hat sich so ähnlich angefühlt, wie mein Traum vor KurzemDOTS\pOb da ein Zusammenhang besteht?\pUnd was ich da gesehen habeDOTS DOTS DOTS\pWar das die Katastrophe, die für die Zerstörung Aktanias verantwortlich ist?\pWas war das für ein seltsames Pokémon?\pUnd ist es mit dem Meteoriten hierher gelangt?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pZu viele FragenDOTS DOTS DOTS\pIch kann mir noch keinen Reim darauf machenDOTS DOTS DOTS"
        
.elseif LANG_EN

.endif
