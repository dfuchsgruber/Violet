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

.global map_ardeal_entrance_levelscripts

.align 4

map_ardeal_entrance_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x3b
	.word ow_script_frame_table
	.hword 0x0

ow_script_frame_table:
    lockall
    loadpointer 0 str_0
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    loadpointer 0 str_police
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_1
    callstd MSG
    special SPECIAL_NAME_DELETE
    applymovement 6 mov_away
    waitmovement 0
    hidesprite 6
    applymovement 7 mov_away
    applymovement 8 mov_away
    applymovement 9 mov_away
    applymovement 10 mov_away
    waitmovement 0
    hidesprite 7
    hidesprite 8
    hidesprite 9
    hidesprite 10
    pause 32
    sound 21
    applymovement 5 mov_notice
    waitmovement 5
    checksound
    loadpointer 0 str_2
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    setvar 0x8004 5
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_HARRENFELD alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 5 mov_away
    waitmovement 0
    hidesprite 5
    addvar STORY_PROGRESS 1
    releaseall
    end

mov_away:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_notice:
    .byte LOOK_DOWN, SAY_EXCLAM, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Also gut, dann wollen wir die Sache einmal über die Bühne bringen.\pDer Kommandant der ersten Division von Team Violet hat sich wohl hier verschanzt.\pWenn wir ihn hier stellen, hat dieser ganze Team Violet Spuk hoffentlich ein Ende.\pGegen meine Fähgkeiten wird er sich nicht zur Wehr setzten können."
str_police:
    .string "Polizisten"
str_1:
    .autostring 34 2 "Jawohl!"
str_2:
    .autostring 34 2 "PLAYER!\nGutes Timing!"
str_3:
    .autostring 34 2 "Ich bin ja so aufgeregt.\pWir haben Informationen erhalten, dass sich der Kommandant der ersten Division von Team Violet hier aufhält.\pEigentlich heißt es, dass diese Person unfassbar mächtig sein soll, aberDOTS\pDOTSmit Narcissa von den Top Vier als Verstärkung, kann eigentlich nichts schief gehen.\pVielleicht stellen wir heute den Drahtzieher hinter dieser ganzen verbrecherischen Organistaion!\pUnd du hast das Glück, das alles hautnah miterleben zu dürfen!\pVerliern wir am besten keine Zeit!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "Fine then, let's get this thing over with.\pThe commander of the first division of Team Violet is supposed to hide in this castle.\pIf we get him now, this entire Team Violet affair hopefully is over for good.\pAgaist my skills he won't have the slightest chance."
str_police:
    .string "Policemen"
str_1:
    .autostring 34 2 "Yes, ma'am!"
str_2:
    .autostring 34 2 "PLAYER!\nGreat Timing!"
str_3:
    .autostring 34 2 "I am so excited!\pWe got intel that the commander of the first division of Team Violet hides at this place.\pActually, people say that he is extremely strong, butDOTS\pDOTStogether with Narcissa of the Elite Four I am convinced that nothing can go wrong.\pMaybe we will finally expose the mastermind behind this entire Team Violet organistaion.\pAnd you are lucky enough to see all of this with your very own eyes!\pLet's not waste any more time!"
.endif