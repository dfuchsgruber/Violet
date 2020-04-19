.include "vars.s"
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

.global ow_script_blackbeard_ship_cells_trigger

ow_script_blackbeard_ship_cells_trigger:
    lockall
    applymovement 1 mov_towall
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    sound 0x15
    applymovement 0xFF mov_player_question
    applymovement 0x7F mov_4r
    waitmovement 0
    loadpointer 0 str_1
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
    loadpointer 0 str_2
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_4
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_5
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    pause 16
    applymovement 0x7F mov_4l
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK

    addvar STORY_PROGRESS 1
    releaseall
    end

mov_towall:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_LEFT, STOP
mov_player_question:
    .byte LOOK_RIGHT, SAY_QUESTION, STOP
mov_4l:
    .byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP
mov_4r:
    .byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Psst!\nHey Kindchen!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pHier drüben, neben dir."
str_1:
    .autostring 34 2 "Keine Angst, Kindchen!\pIch kann dir von hier drüben aus nichts tun.\pEndlich bist du wach.\pDu hast bestimmt einige Stunden einfach nur so dagelegen.\pTut mir leid, dir das sagen zu müssen, aber du kommst hier nicht raus.\pHat gar keinen Zweck es zu versuchen."
str_2:
    .autostring 34 2 "Wer bist du?\pUnd wo sind wir hier?"
str_3:
    .autostring 34 2 "Nenn mich einfach Lucky, das tun alle.\pUnd ich fürchte, du bist ein Gefangener auf der Schattenflut, dem Schiff von Blackbeard.\pGenauso wie ich, falls du es nicht bemerkt hast."
str_4:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
str_5:
    .autostring 34 2 "Allerdings hast du wohl wie man so schön sagt Glück im Unglück, Kindchen.\pDie Piraten, die bei Blackbeard anheuern sind nicht die hellsten Köpfchen.\pUnd als man dich hierher gebracht hat, meine ich, ein Klirren gehört zu haben.\pSo als wäre etwas auf den Boden gefallenDOTS\pEin Schlüssel zum Beispiel!\pSchau dich doch einmal genauer um, ob er hier irgendwo herumliegt?"


.elseif LANG_EN
.endif