.include "overworld_script.s"
.include "mugshot.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_haweiland_may

ow_script_haweiland_may:
    lock
    faceplayer

    draw_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
    loadpointer 0 str_0
    callstd MSG_YES_NO
    compare LASTRESULT 0x0
    gotoif EQUAL no_battle
    compare STARTER_SELECTED 0
    gotoif EQUAL battle_0
    compare STARTER_SELECTED 1
    gotoif EQUAL battle_1
battle_2:
    trainerbattlecont 0x1 0x13d 0x0 str_challenge str_defeat cont
battle_0:
    trainerbattlecont 0x1 0x13d 0x0 str_challenge str_defeat cont
battle_1:
    trainerbattlecont 0x1 0x13d 0x0 str_challenge str_defeat cont
cont:
    lock
    faceplayer
    loadpointer 0 str_2
    show_mugshot MUGSHOT_MAY alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    closeonkeypress
    fadescreen 1
    hidesprite 6
    fadescreen 0
    addvar STORY_PROGRESS 1
    release
    end

no_battle:
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    hide_mugshot
    release
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "DOTS DOTS DOTS\pHallo PLAYER.\pWir haben uns eine Weile nicht gesehen was?\pWie ist es dir auf deiner Reise ergangen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas klingt so aufregend.\pFür michDOTS DOTS DOTS\pIst es nicht so toll gelaufen.\pAber bevor ich weiter erzähle, will ich erst noch einmal gegen dich kämpfen.\pWas sagst du dazu?"
str_1:
    .autostring 34 2 "DOTS DOTS DOTS\pDas ist in Ordnung.\pIch werde hier einfach darauf warten, dass du bereit bist."
str_challenge:
    .autostring 34 2 "Ich mache mir keine allzu großen Hoffnungen auf einen SiegDOTS"
str_defeat:
    .autostring 34 2 "Wie zu erwarten warDOTS"
str_2:
    .autostring 34 2 "Du bist einfach eine andere Art Trainer, PLAYER.\pWeißt du, nicht jeder in der Welt kann ein Held sein, das habe ich jetzt verstanden.\pUnd unser Kampf hat mich in meiner Entscheidung bekräftigt, einen anderen Weg zu gehen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch bin mir sicher, dass viele diesen Weg nicht wählen würdenDOTS\pAber ich habe eine wirklich beeindruckende Frau getroffen.\pWie ich steht auch sie immerzu im Schatten von anderen.\pIch konnte sofort verstehen, mit was sie zu kämpfen hat.\pUnd für die Art, wie sie der Welt entgegentritt, muss ich sie einfach bewundern.\pTrotz ihrer Probleme ist sie stark und unnachgiebig.\pSie setzt ihren Willen durch, um jeden Preis.\pUnd sie hat mir angeboten, mich ihrer Organisation anzuschließen.\pAlleine mag ich kaum etwas bewegen können.\pDaher bin ich, wie sie, Teil von etwas Größerem geworden.\pJa, PLAYER.\pZum ersten Mal seit Ewigkeiten sehe ich wieder mit einem hoffnungsvollen Blick in die Zukunft.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu solltest diese Frau unbedingt kennenlernen.\pSoweit ich weiß, müsste sie sich derzeit am Waldfriedhof, östlich von Ceometria aufhalten.\pIch weiß, dass diese Frau auch dir gefallen wird!\pWenn wir uns das nächste mal wieder begegnen, PLAYER, bist du nicht der einzige, der Dinge geschafft hat.\pDann werde auch ich etwas bewegt haben, als Teil einer Organisation, die Menschen wie mir, die sonst keinen Platz in der Welt haben, hilft, für meine Bestimmung zu kämpfen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch freue mich schon darauf!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "DOTS DOTS DOTS\pHell PLAYER.\pWe didn't see each other in a long time, eh?\pHow did you do on your joruney?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pFor meDOTS DOTS DOTS\pThings didn't go so well.\pBut before I go on complaining, I want to battle you.\pWhat do you think?"
str_1:
    .autostring 34 2 "DOTS DOTS DOTS\pThat's fine.\pI will just wait here for you to be ready."
str_challenge:
    .autostring 34 2 "I don't have any hopes to win this battleDOTS"
str_defeat:
    .autostring 34 2 "Just as I expectedDOTS"
str_2:
    .autostring 34 2 "You really are a different kind of trainer, PLAYER.\pYou know, not everyone in this world can be a hero, I finally understood that now.\pOur battle affirmed me of my decision to go down another path.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pI am sure that many wouldn't dare to go that road.\pBut I met a really impressive women.\pLike me she always suffered being in someone else's shadow.\pI immediatly could see what kind of struggels she was facing.\pAnd for how she faced the world regardless I couldn't help myself but to admire her.\pEven though she had those issues she was strong and relentless.\pShe gets her way no matter the cost.\pAnd now she offered me to join her organisation.\pOn my own I probably wouldn't be able to move anything.\pThat is, why I, like her, became part of something bigger.\pYes, PLAYER.\pFor the first time since I don't know how long I look into the future with hope in my eyes.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pYou definitely have to meet this woman.\pAs far as I know she has buisness to do at the Forest Cemetery, east of Ceometria.\pI know that this woman will also appeal to you.\pWhen we meet the next time, PLAYER, you won't be the only one who actually achieved something.\pThen, also I will have made an impact on the world as part of an organization, that helps people like me, people that otherwise wouldn't have any place in this world, to find a reason to fight.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch am already so excited about it!"
.endif