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
.include "ordinals.s"
.include "movements.s"

.global map_blackbeard_ship_cells_levelscripts

.align 4

map_blackbeard_ship_cells_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x3e
	.word ow_script_frame_table
	.hword 0x0


ow_script_frame_table:
    lockall
    pause 64
    loadpointer 0 str_0
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    playsong MUS_BBSHIP 0
    addvar STORY_PROGRESS 1
    setvar SONG_OVERRIDE 0
    releaseall
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "ArghDOTS\nMein Kopf dröhntDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWo bin ich hier?\pDas letzte woran ich mich erinnern kann, ist, dass Lucius mich vom Turm gestoßen hatDOTS"

.elseif LANG_EN

.endif
