.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "vars.s"
.include "flags.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "movements.s"

.global map_ardeal_tower_center_3_levelscripts

.align 4

map_ardeal_tower_center_3_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x3c
	.word ow_script_frame_table
	.hword 0x0

ow_script_frame_table:
    lockall
    loadpointer 0 str_0
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_LEFT message_type=MSG mask_name=0
    addvar STORY_PROGRESS 1
    releaseall
    end



.ifdef LANG_GER
str_0:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pUffDOTS\nWie konnte ichDOTS DOTS DOTS\pGerade ich verlieren!\pDOTS DOTS DOTS\nUnmöglichDOTS DOTS DOTS"
str_1:
    .autostring 34 2 "Narzissa von den Top Vier besiegt von Team Violet.\pDas ist ungeheuerlichDOTS\pAber gegen diesen Mann zu gewinnenDOTS DOTS DOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pUrghDOTS\nHow could IDOTS DOTS DOTS\pI myself lose!\pDOTS DOTS DOTS\pImpossibleDOTS DOTS DOTS"
str_1:
    .autostring 34 2 "Narcissa of the Elite Four defeated.\pThat is insaneDOTS\pBut to win against this manDOTS DOTS DOTS"
.endif