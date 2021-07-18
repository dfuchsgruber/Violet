.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"

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