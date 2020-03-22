.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"

.global ow_script_felix_and_blaise_felsige_oednis

ow_script_felix_and_blaise_felsige_oednis:
    lockall
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
    loadpointer 0 str_1
    show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT
    loadpointer 0 str_2
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
    loadpointer 0 str_3
    show_mugshot MUGSHOT_BLAISE MUGSHOT_LEFT
    setvar 0x8004 19
    setvar 0x8005 0x1C
    setvar 0x8006 0x5
    hidesprite 19
    special SPECIAL_NPC_MOVE_TO
    loadpointer 0 str_4
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
    waitmovement 0
    closeonkeypress
    pause 32
    sound 0x15
    applymovement 18 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_5
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
    pause 32
    sound 0x15
    applymovement 18 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_6
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
    setvar 0x8004 18
    setvar 0x8005 0x1C
    setvar 0x8006 0x4
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 18
    addvar STORY_PROGRESS 1
    releaseall
    end
    


mov_exclam:
    .byte LOOK_LEFT, SAY_EXCLAM, STOP


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hör mir doch einmal zu, Blaise.\pGegen jemanden wie deinen Vater kannst du nichts ausrichten."
str_1:
    .autostring 34 2 "Das kannst du nicht wissen.\nIch bin viel stärker, als du vermutest.\pIch werde mich von niemandem aufhalten lassen.\pIch brauche weder deine Hilfe noch die von sonst irgendwem."
str_2:
    .autostring 34 2 "Merkst du nicht, in was du dich da verrennst?\pSelbst wenn du es dir gelingen sollte, deinen Vater zu stürzenDOTS\pWas hast du dann erreicht?\pWas willst du dann tun?\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_3:
    .autostring 34 2 "Was? Soll ich etwa wie du zusammen mit dem alten Spinner Faun gegen die Revolutionäre kämpfen?\pUnd du wirfst mir vor, mich in etwas zu verrennen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pLeb wohl, FelixDOTS"
str_4:
    .autostring 34 2 "Blaise, warte!"
str_5:
    .autostring 34 2 "PLAYER, was für ein Zufall!\pIch bin gerade auf dem Weg nach Kaskada, wo sich der Anführer der Revolutionsbewegung aufhalten soll.\pDiese Leute sind sehr gefährlich, denn sie versuchen, die Top Vier zu stürzen.\pOpi ist bereits auf dem Weg, den Kopf dieser Gruppe zu stellen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd ich hatte eigentlich gehofft, dass ich Blaise als ehemaligen Schüler von Opi auch für diese Sache gewinnen kann.\pAber er hält immer noch verbissen an seinem persönlichen Feldzug gegen seinen eigenen Vater fest."
str_6:
    .autostring 34 2 "Aber du bist ja auch einer von Opis ehemaligen Schülern.\pWas sagst du?\nWir beide könnten Opi doch im Kaskada unterstützen nicht?\pUnd wenn du auch mit von der Partie bist, überlegt es sich vielleicht auch Blaise noch einmal anders.\pDas wird toll!\nOpi wird von seinen ehemaligen Schülern im Kampf gegen die Revolutionsbewegung unterstützt.\pWir werden Helden, PLAYER!\pIst das nicht aufregend?\pWir sollten keine Zeit verlieren.\pWir sehen uns in Kaskada."

.elseif LANG_EN

.endif