.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_7_trainer_0
.global ow_script_route_7_trainer_1
.global ow_script_route_7_trainer_2
.global ow_script_route_7_north_couple
.global ow_script_route_7_north_cook

ow_script_route_7_trainer_0:
    trainerbattlestd 0x0 0x13f 0 str_before_0 str_after_0
    loadpointer 0x0 str_later_0
    callstd MSG_FACE
    end
ow_script_route_7_trainer_1:
    trainerbattlestd 0x0 0x140 0 str_before_1 str_after_1
    loadpointer 0x0 str_later_1
    callstd MSG_FACE
    end
ow_script_route_7_trainer_2:
    trainerbattlestd 0x0 0x141 0 str_before_2 str_after_2
    loadpointer 0x0 str_later_2
    callstd MSG_FACE
    end
 ow_script_route_7_north_couple:
    trainerbattledouble 4 0x1de 0 str_before_3 str_after_3 str_cant_battle_3
    loadpointer 0 str_later_3
    callstd MSG_FACE
    end
ow_script_route_7_north_cook:
    lock
    faceplayer
    loadpointer 0 str_cook_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif NOT_EQUAL cook_battle
    loadpointer 0 str_cook_dont_battle
    callstd MSG_KEEPOPEN
    release
    end
cook_battle:
    trainerbattlecont 1 0x1df 0 str_cook_before str_cook_after cook_after
cook_after:
    lock
    loadpointer 0 str_cook_give
    callstd MSG_KEEPOPEN
    fanfare 258
    loadpointer 0 str_got_recipe
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_after_recipe
    callstd MSG_KEEPOPEN
    closeonkeypress
    fadescreen 1
    hidesprite LASTTALKED
    fadescreen 0
    release
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Mein Kopf raucht!\pZur Abkühlung, brauche ich jetzt einen Kampf!"
str_after_0:
    .autostring 34 2 "Ja, das ist schon besser!\pMein Blut ist etwas abgekühltDOTS"
str_later_0:
    .autostring 34 2 "So eine Niederlage kühlt den Körper ganz schon herunterDOTS\pSo ein Jammer!"
str_before_1:
    .autostring 34 2 "Ich bin durch den ganzen Kontinent gewandert.\pAber nichts hat mich so geschlaucht, wie diese ekelhafte Hitze!"
str_after_1:
    .autostring 34 2 "Wie soll ich denn bei solchen Temperaturen mithalten?"
str_later_1:
    .autostring 34 2 "Ich bin froh, wenn ich nicht mehr in dieser Hitze wandern mussDOTS"
str_before_2:
    .autostring 34 2 "Mein Beruf bringt mich an die verschiedensten Orte.\pIch treffe allerlei Menschen.\pMal sehen, ob du meiner Weltgewandheit gewachsen bist!"
str_after_2:
    .autostring 34 2 "Jetzt muss ich erst einmal meine Pokémon reparieren."
str_later_2:
    .autostring 34 2 "Oh manDOTS\pMeine Pokémon sind ganz schön angeschlagen.\pDa braucht es eine ordentliche Grundsanierung, wenn du verstehstDOTS"
str_before_3:
    .autostring 34 2 "Die Lava hier mag heiß sein, aber nicht so heiß wie unsere Liebe!"
str_after_3:
    .autostring 34 2 "M-Moment!\nUnsere Liebe war nicht heiß genug?"
str_later_3:
    .autostring 34 2 "Unfassbar!\nSelbst unsere heiße Liebe hat dich nicht zum Schmelzen gebracht?\pHast du überhaupt ein Herz, Kindchen?"
str_cant_battle_3:
    .autostring 34 2 "Wir kämpfen nur als Team!\pNicht dass wir in der Hitze des Gefechts nicht aufeinander Acht geben können."
str_cook_ask:
    .autostring 34 2 "Dir schmeckt die Asche nicht, die vom Vulcano herabrieselt?\pWas wenn ich dir sage, dass sie sich hervorragend für ein Rezept eignet?\pDu glaubst mir nicht?\pIch kann es dir in einem Kampf beweisen, wenn du dich traust!"
str_cook_before:
    .autostring 34 2 "Mit meinen Rezepten habe ich nützliche Items hergestellt.\pDu hast praktisch keine Chance!"
str_cook_after:
    .autostring 34 2 "Wiebitte?\nIch habe trotz meiner Rezepte verloren?"
str_cook_dont_battle:
    .autostring 34 2 "Meine Rezepte sind ohnehin eine Nummer zu heiß für dich, was?"
str_cook_give:
    .autostring 34 2 "D-Das überrascht mich jetzt.\pDabei habe ich so viel Asche gesammelt, um Items herzustellen.\pVielleicht weißt du ja besser, wie man sie im Kampf einsetzt."
str_got_recipe:
    .autostring 34 2 "PLAYER hat ein Rezept erhalten!"
str_after_recipe:
    .autostring 34 2 "Mit diesen Rezepten kannst du Juwelen herstellen.\pSie verstärken einmalig den Angriff eines bestimmten Attacken-Typen.\pAber um sie herzustellen, brauchst du Asche.\pGanz viel Asche, um genau zu sein.\pAsche zu sammeln macht mir ungeheuer Spaß, musst du wissen.\pIch werde mich gleich wieder an die Arbeit machen."


.elseif LANG_EN
str_before_0:
    .autostring 34 2 "My head is smoking hot!\pI need a battle to cool down!"
str_after_0:
    .autostring 34 2 "Yes, that is better!\pMy blood cooled down somewhatDOTS"
str_before_1:
    .autostring 34 2 "I wandered the entire continent.\pBut nothing bothered me as much as this terrible heat!"
str_after_1:
    .autostring 34 2 "How am I supposed to keep up with that temperatures?"
str_before_2:
    .autostring 34 2 "My job brings me to various places.\pI meet the most different kinds of people.\pLet's see if you are any match for my experience!"
str_after_2:
    .autostring 34 2 "Now I have to fix my Pokémon."

.endif
