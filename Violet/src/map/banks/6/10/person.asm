.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_bruchfels_gym_lester

ow_script_movs_0x8ca8f6:
    .byte STEP_UP
    .byte STOP

ow_script_map_bruchfels_gym_lester:
    checkflag FRBADGE_1
    gotoif EQUAL ow_script_0x8ca829
    loadpointer 0x0 str_0x8ca8f9
    show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
    applymovement LASTTALKED ow_script_movs_0x8ca8f6
    waitmovement 0x0
    hidesprite LASTTALKED
    goto ow_script_0x8f6d7a

ow_script_0x8f6d7a:
    setvar STORY_PROGRESS 0x12
    clearflag AKTANIA_LESTER_ARENA
    warp 0x6 0x1 0x0 0x0 0x0
    end


ow_script_0x8ca829:
    loadpointer 0x0 str_0x8ca83f
    show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT MSG_FACE
    end


.ifdef LANG_GER

str_0x8ca8f9:
    .autostring 34 2 "Du musst ein Herausforder sein, nicht wahr?\pMein Name ist Lester und ich bin für diesen Tempel verantwortlich.\pSeit Generationen bewacht meine Familie diesen Ort und ich kann nicht in Kauf nehmen, dass wir hier bei unserem Kampf etwas beschädigen.\pFolge mir bitte in die Untergrund-Arena."

str_0x8ca83f:
	.autostring 34 2 "Vor einigen Jahren wurde Bruchfels in Schutt und Asche gelegt.\pMein Vater gab bei diesem Vorfall sein Leben, um die Insel zu retten.\pMit derselben Aufopferung werde ich diesen Tempel bewachen."

.elseif LANG_EN

.endif