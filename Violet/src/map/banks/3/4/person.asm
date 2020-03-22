.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"

.global ow_script_kaskada_harrenfeld

ow_script_kaskada_harrenfeld:
    lock
    faceplayer
    loadpointer 0x0 str_0
    show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG_KEEPOPEN
    //callstd MSG
    fadesong PROFESSOR_EICHS_LABOR
    setvar 0x8004 0
    special SPECIAL_CUTSCENE_SHOW
    lock
    waitstate
    lock
    faceplayer
    pause 64
    loadpointer 0x0 str_1
    show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG_KEEPOPEN
    fadescreen 1
    hidesprite 37
    hidesprite 1
    hidesprite 2
    fadescreen 0
    release
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Oh, hallo PLAYER!\nWir haben die Albus' Spur leider verloren, nachdem wir ihn am Küstenberg nicht fassen konnten.\pDas ist natürlich sehr ärgerlich, wer weiß, wann wir wieder eine solche Chance bekommen.\pAber weißt du, Faun und Albus sind alte Bekannte.\pUm genau zu sein, waren beide Mitgründer der Pokémon-Liga in ThetoDOTS"
str_1:
    .autostring 34 2 "Seitdem Lucius, der ehemalige Champion gestürzt wurde, gewinnt mehr und mehr das Chaos die Überhand.\pTheto braucht einen Champion, aber von Lucius' Nachfolger fehlt jede Spur.\pWir von der Polizei geben solange unser Bestes, sowohl die Revolution als auch Team Violet in Schach zu halten, aber ewig werden wir nicht standhalten könnenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNun, ich denke, die Abriegelung der Stadt kann aufgehoben werden.\pWir sehen uns, PLAYER!\pHalt die Ohren steif!"

.elseif LANG_EN
.endif