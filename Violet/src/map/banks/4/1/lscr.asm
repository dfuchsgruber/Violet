.include "vars.s"
.include "healingplaces.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "story_states.s"
.include "levelscript_types.s"

.global map_player_bedroom_levelscripts

map_player_bedroom_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
    .word levelscript_on_warp_into_map_table
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word levelscript_on_transition
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
    .word levelscript_on_frame_table
	.byte 0x0

levelscript_on_warp_into_map_table:
	.hword AMONIA_PLAYERFACING_INTRO, 0x0
	.word ow_script_player_set_facing_down
	.hword 0x0

levelscript_on_frame_table:
	.hword STORY_PROGRESS, 0x0
	.word ow_script_dream
	.hword 0x0

ow_script_player_set_facing_down:
    spriteface 0xff 0x1
    setvar AMONIA_PLAYERFACING_INTRO 0x1
    end

levelscript_on_transition:
    setflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
    sethealingplace HEALINGPLACE_AMONIA
    compare STORY_PROGRESS 0x0
    gotoif EQUAL ow_script_stop_map_song
    end
ow_script_stop_map_song:
    playsong2 0xFFFF
    end

ow_script_dream:
    pause 64
    clearflag FLAG_FILTER_COLOR_ACTIVE
    addvar STORY_PROGRESS 0x1 
    setvar 0x8004 13
    special 0x19
    waitstate
    pause 0x80
    /** 
    loadpointer 0x0 str_after_dream
    show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0x0 str_after_dream2
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0x0 str_after_dream3
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    **/
    playsong MUS_ALABASTIA 0
    playsong2 MUS_ALABASTIA
    end

.ifdef LANG_GER
    str_after_dream:
        .autostring 34 2 "Was für ein seltsamer TraumDOTS\nEr hat sich so real angefühlt!"
    str_after_dream2:
        .autostring 34 2 "Was er wohl zu bedeuten hatte?\pIrgendeine Stimme hat zu mir gesprochen, aber ich habe sie nicht erkanntDOTS"
    str_after_dream3:
        .autostring 34 2 "Aber ich sollte mir gerade heute darüber nicht den Kopf zerbrechen!\pImmerhin steht meine Abschlussprüfung an!\pUnd ich bin vermutlich schon viel zu spät dran."
.elseif LANG_EN
    str_after_dream:
        .autostring 34 2 "What a weird dramDOTS\pIt felt so real!"
    str_after_dream2:
        .autostring 34 2 "I wonder what it meaning might have been.\pSome kind of voice seemed to be speaking to me but I didn't recognize it at all!"
    str_after_dream3:
        .autostring 34 2 "But I should not let myself get distracted by something like this now.\pMy finals are today and I am probably late already!"
.endif