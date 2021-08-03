.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "pathfinding.s"

.global ow_script_route_6_person_ash_gift
.global ow_script_route_6_person_0
.global ow_script_route_6_person_1
.global ow_script_route_6_person_2
.global ow_script_route_6_person_3
.global ow_script_route_6_person_4
.global ow_script_route_6_person_5
.global ow_script_route_6_person_6
.global ow_script_route_6_person_7
.global ow_script_route_6_person_8
.global ow_script_route_6_igva_mistral_event

ow_script_route_6_igva_mistral_event:
    lockall
    pause 32
    loadpointer 0 str_igva_0
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD
    loadpointer 0 str_igva_1
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
    loadpointer 0 str_igva_2
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
    loadpointer 0 str_igva_3
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_igva_4
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_5
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_6
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    hide_mugshot
    loadpointer 0 str_igva_7
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD
    loadpointer 0 str_igva_8
    show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT emotion=MUGSHOT_ANGRY hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_igva_9
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    npc_move_to 33 0x1f 0x19
    hidesprite 33
    pause 24
    loadpointer 0 str_igva_10
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_SAD
    pause 16
    sound 0x15
    applymovement 11 mov_fu
    waitmovement 0
    applymovement 11 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_igva_11
    show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT emotion=MUGSHOT_NORMAL hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_igva_12
    update_mugshot_emotion MUGSHOT_SAD
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_13
    update_mugshot_emotion MUGSHOT_SAD
loop_asking:
    callstd MSG_KEEPOPEN
    yesnobox 20 6
    compare LASTRESULT 1
    gotoif 1 said_yes
    loadpointer 0 str_igva_14
    goto loop_asking
said_yes:
    loadpointer 0 str_igva_15
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    loadpointer 0 str_igva_16
    update_mugshot_emotion MUGSHOT_ANGRY
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    npc_move_to 11 0x1f 0x19
    hidesprite 11
    releaseall
    end

.ifdef LANG_GER
str_igva_0:
    .autostring 34 2 "A-Aber was hast du denn davon, jetzt bei diesen Team Violet Leuten mitzumachen?"
str_igva_1:
    .autostring 34 2 "Was hat es mir gebracht, für die Revolutionäre zu kämpfen?\pDieses irrsinnige Vorhaben von Albus die Pokémon-Liga zu stürzenDOTS\pIch kämpfe nicht für eine verlorene SacheDOTS"
str_igva_2:
    .autostring 34 2 "Was soll das heißen?\pAlbus setzt sich für die Menschen in dieser Region ein.\pUnd gerade, weil diese Sache so aussichtslos scheint, braucht es Menschen, die für sie kämpfen!\pTeam Violet dagegen ist eine Verbrecherbande!\pMacht es dir denn überhaupt nichts aus, unschuldigen Menschen Leid zu bereiten?"
str_igva_3:
    .autostring 34 2 "Jetzt halt mal die Luft an, Igva!"
str_igva_4:
    .autostring 34 2 "Siehst du denn überhaupt nicht, dass die Revolution genauso gewaltsam gegen die vorgeht, die ihnen im Weg steht?\pAlbus hat euch wirklich eine ordentliche Gehirnwäsche verpasstDOTS\pUnd wenn ich ganz ehrlich sein sollDOTS"
str_igva_5:
    .autostring 34 2 "Mich interessieren die Unschuldigen nicht im GeringstenDOTS"
str_igva_6:
    .autostring 34 2 "Ich habe mich Team Violet angeschlossen, weil ich glaube, dass sie mir zu großer Macht verhelfen können.\pWas meinst du, warum ich der Revolution damals überhaupt beigetreten bin?"
str_igva_7:
    .autostring 34 2 "D-Das ist nicht wahr, Mistral.\pI-Ich weiß, dass du so nicht bistDOTS"
str_igva_8:
    .autostring 34 2 "Wach auf, Igva!"
str_igva_9:
    .autostring 34 2 "Du hast dich in mir getäuscht.\pUnd bei Albus liegst du genauso falsch.\pIch kenne Menschen wie ihn.\pEr konnte es schlicht nicht verkraften, selbst nicht an der Spitze der Pokémon-Liga zu stehen.\pUnd jetzt fordert er gewaltsam das ein, was ihm zusteht.\pEr strebt wie ich bloß nach Macht.\pNicht mehrDOTS\pDOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG\pIch habe keine Zeit für diesen Unsinn.\pKomm mir nicht in die Quere, Igva!"
str_igva_10:
    .autostring 34 2 "DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG"
str_igva_11:
    .autostring 34 2 "Oh!\nHallo PLAYER!\pWir haben uns lange nicht mehr gesehen, was?"
str_igva_12:
    .autostring 34 2 "Hör mal, PLAYERDOTS\pIch weiß nicht, wie viel du gerade eben gesehen hastDOTS\pAber ich könnte deine Hilfe gebrauchen!\pDieser Junge, mit dem ich eben gesprochen habeDOTS\pEr war einmal ein sehr enger Freund von mirDOTS\pAber irgendwie ist er auf die schiefe Bahn geraten und kämpft jetzt für Team Violet."
str_igva_13:
    .autostring 34 2 "Ich weiß nicht genau, was er im Schilde führtDOTS\pAber ich muss ihn aufhalten.\pImmerhin ist es ja auch meine Aufgabe, die Menschen in dieser Gegend zu beschützen, oder?\pWas sagst du?\nKannst du mir unter die Arme greifen?"
str_igva_14:
    .autostring 34 2 "Ich weiß, dass das nicht wirklich dein Problem ist, PLAYER.\pAber ich weiß nicht, ob ich meinen alten Freund alleine aufhalten kann.\pIch brauche deine Hilfe wirklich dringend, PLAYER!\pKannst du mir diesen Gefallen tun?"
str_igva_15:
    .autostring 34 2 "Ich wusste, dass ich mich auf dich verlassen kann, PLAYER!\pDu bist wirklich toll!"
str_igva_16:
    .autostring 34 2 "Wir sollten keine Zeit verlieren!"
.elseif LANG_EN
.endif

ow_script_route_6_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end
ow_script_route_6_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end
ow_script_route_6_person_2:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end
ow_script_route_6_person_3:
    loadpointer 0x0 str_3
    callstd MSG_FACE
    end
ow_script_route_6_person_4:
    loadpointer 0x0 str_4
    callstd MSG_FACE
    end
ow_script_route_6_person_5:
    loadpointer 0x0 str_5
    callstd MSG_FACE
    end
ow_script_route_6_person_6:
    loadpointer 0x0 str_6
    callstd MSG_FACE
    end
ow_script_route_6_person_7:
    loadpointer 0x0 str_7
    callstd MSG_FACE
    end
ow_script_route_6_person_8:
    loadpointer 0x0 str_8
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_0:
    .autostring 34 2 "Ich bin auf der Suche nach dem Pokémon Panzaeron.\pEs heißt, dass es hier sehr selten ist und scheu obendrein!\pEs mag es wohl, sich in den von Asche bedeckten Gräsern zu versteckenDOTS"
str_1:
    .autostring 34 2 "Im Aschhain lebt jemand, der aus Asche Glasflöten herstellen kann.\pEr ist der beste Glasbläser der Region, erzählt man sich."
str_2:
    .autostring 34 2 "Der Boden hier am Fuße eines Vulkans ist besonders nährstoffreich.\pDeswegen kommen auch schon seit Jahrhunderten Menschen und Pokémon hierher zum Leben, ungeachtet der offensichtlichen Gefahr eines Ausbruchs."
str_3:
    .autostring 34 2 "Es ist doch wirklich beeindrucken, dass das Pokéradar selbst unter solch widrigen Bedingungen noch einwandfrei funktioniert, oder?"
str_4:
    .autostring 34 2 "Hui!\nSchau mal!\pWenn ich so laufe, wirble ich ganz viel Asche auf!\pJuhu!\nHui hui!"
str_5:
    .autostring 34 2 "Vor vielen Jahren haben hier Hexen Beschwörungsrituale abgehalten.\pDie Festung der Dunklen Königen, Ardeal, ist gar nicht weit von hier im Süden.\pVon dort aus soll die Dunkle Königin ein legendäres Pokémon kontrolliert haben, das in der Lage gewesen sein soll, Landmassen zu formen.\pWenn du mich fragst, ist diese Geschichte etwas unglaubwürdig, findest du nicht?"
str_6:
    .autostring 34 2 "Seit unser Champion Lucius verschwunden ist, gilt Inferior als eine Hochburg der Revolutionsbewegung.\pSicherlich steckt die Arenaleiterin Igva da auch mit drinnenDOTS"
str_7:
    .autostring 34 2 "Ich werde einmal der stärkste Feuer-Pokémon Trainer aller Zeiten werden.\pDafür muss ich aber noch hart arbeiten, bis ich einmal in der Lage bin, Igva zu schlagen."
str_8:
    .autostring 34 2 "Einer Legende nach, soll im Volcano ein legendäres Pokémon schlummern.\pDas klingt doch wirklich furchteinflößend, oder?"
.elseif LANG_EN
.endif


ow_script_route_6_person_ash_gift:
    checkflag ROUTE_6_ASH_PRESENT
    gotoif EQUAL ow_script_0x963590
    checkflag ASHBAG_RECEIVED
    gotoif LESS ow_script_0x963483
    lock
    faceplayer
    loadpointer 0x0 str_0x9633f9
    callstd MSG_KEEPOPEN
    compare ASH 0xc15c
    gotoif HIGHER ow_script_0x96334b
    fanfare 0x13e
    loadpointer 0x0 str_0x96332e
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag ROUTE_6_ASH_PRESENT
    addvar ASH 0x1f4
    goto ow_script_0x963590
ow_script_0x963590:
    loadpointer 0x0 str_0x96359a
    callstd MSG_FACE
    end
ow_script_0x96334b:
    loadpointer 0x0 str_0x963356
    callstd MSG
    release
    end
ow_script_0x963483:
    loadpointer 0x0 str_0x96348d
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x9633f9:
    .string "Hui! Asche sammeln macht Spaß!\nUnd weißt du, was noch mehr Spaß\lmacht?\pDie gesammelte Asche zu teilen.\nIch werde dir etwas Asche geben!"
str_0x96332e:
    .string "PLAYER hat 500 Asche erhalten."
str_0x96359a:
    .string "Der nette Mann im Aschhain stellt\nheilsame Flöten aus Asche her.\pDu solltest ihm deine Asche\nbringen."
str_0x963356:
    .string "Oh! Deine Aschetasche scheint ja\nganz schön voll zu sein!\pAm besten gibst du dem netten Mann\nim Aschhain etwas davon, dann kann\ler dir eine Flöte daraus machen!"
str_0x96348d:
    .string "Findest du nicht, dass das Asche\nsammeln Spaß macht?\pAber du scheinst ja gar keine\nAschetasche zu besitzen, wie\lwillst du denn dann Asche sammeln?\pBesuch doch den netten Mann im\nAschhain und seinen Sohn.\lDort wird man dir sicherlich eine\lAschetasche geben."
.elseif LANG_EN

.endif