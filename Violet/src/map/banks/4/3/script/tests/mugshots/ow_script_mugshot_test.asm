.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "vars.s"
.include "mugshot_character.s"
.include "mugshot_alignment.s"

.global ow_script_mugshot_test
ow_script_mugshot_test:
    lock
    faceplayer
    loadpointer 0x0 whoami
    show_mugshot MUGSHOT_HIRO,MUGSHOT_LEFT,,1
    loadpointer 0x0 no_plan
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT
    loadpointer 0x0 introduction
    show_mugshot MUGSHOT_HIRO
    loadpointer 0x0 thisisme
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT
    loadpointer 0x0 joke
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0x0 confusion
    draw_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT
    loadpointer 0x0 blaise
    callstd MSG
    loadpointer 0x0 neuer
    callstd MSG
    hide_mugshot
    loadpointer 0x0 reaction
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT MSG_KEEPOPEN
    loadpointer 0x0 question
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT MSG_YES_NO
    compare LASTRESULT 0x0
    callif EQUAL script_yes
    callif NOT_EQUAL script_no
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT
    release
    end

script_yes:
    loadpointer 0x0 yes_text
    return

script_no:
    loadpointer 0x0 no_text
    return

whoami:
    .autostring 35 2 "Weisst du, wer ich bin?"

no_plan:
    .autostring 35 2 "UffDOTS Keine Ahnung, deine Textbox ist nicht beschriftetDOTS"

introduction:
    .autostring 35 2 "Ich bin PLAYER"

thisisme:
    .autostring 35 2 "Kann nicht sein!\nIch bin doch PLAYER!"

joke:
    .autostring 35 2 "Scherz, ich bin Faun."

confusion:
    .autostring 35 2 "ÄhDOTS was!?"

blaise:
    .autostring 35 2 "Oder vielleicht bin ich auch Blaise, der dich mal eben zulabern will, oderDOTS"

neuer:
    .autostring 35 2 "Vielleicht bin ich auch Manuel Neuer!"

reaction:
    .autostring 35 2 "WTF!?"

question:
    .autostring 35 2 "Ist das Manuel Neuer!?"

yes_text:
    .autostring 35 2 "Ich war von Anfang an misstrauisch!"

no_text:
    .autostring 35 2 "Das denke ich auch."