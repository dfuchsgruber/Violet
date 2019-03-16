.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "vars.s"
.include "mugshot.s"
.include "mugshot_alignment.s"

.global ow_script_mugshot_test
ow_script_mugshot_test:
    lock
    faceplayer
    loadpointer 0x0 text1
    show_mugshot MUGSHOT_HIRO
    loadpointer 0x0 text2
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT
    loadpointer 0x0 text3
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0x0 text4
    draw_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT
    loadpointer 0x0 text5
    callstd MSG
    loadpointer 0x0 text6
    callstd MSG
    hide_mugshot
    loadpointer 0x0 text7
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT MSG_KEEPOPEN
    loadpointer 0x0 text8
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT MSG_YES_NO
    compare LASTRESULT 0x0
    callif EQUAL script_yes
    callif NOT_EQUAL script_no
    show_mugshot MUGSHOT_HIRO MUGSHOT_RIGHT
    release
    end

script_yes:
    loadpointer 0x0 text9
    return

script_no:
    loadpointer 0x0 text10
    return

text1:
    .autostring 35 2 "Hallo, ich bin PLAYER"

text2:
    .autostring 35 2 "Kann nicht sein!\nIch bin doch PLAYER!"

text3:
    .autostring 35 2 "Scherz, ich bin Faun."

text4:
    .autostring 35 2 "ÄhDOTS was!?"

text5:
    .autostring 35 2 "Oder vielleicht bin ich auch Blaise, der dich mal eben zulabern will, oderDOTS"

text6:
    .autostring 35 2 "Vielleicht bin ich auch Manuel Neuer!"

text7:
    .autostring 35 2 "WTF!?"

text8:
    .autostring 35 2 "Ist das Manuel Neuer!?"

text9:
    .autostring 35 2 "Ich war von Anfang an misstrauisch!"

text10:
    .autostring 35 2 "Das denke ich auch."