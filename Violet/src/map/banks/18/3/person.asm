.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_map_18_3_trainer_16
.global ow_script_map_18_3_trainer_0
.global ow_script_map_18_3_trainer_2
.global ow_script_0x95edfb
.global ow_script_map_18_3_trainer_4
.global ow_script_map_18_3_trainer_12
.global ow_script_map_18_3_trainer_11
.global ow_script_map_18_3_trainer_19
.global ow_script_0x96334b
.global ow_script_map_18_3_trainer_9
.global ow_script_map_18_3_trainer_6
.global ow_script_map_18_3_trainer_10
.global ow_script_map_18_3_trainer_1
.global ow_script_map_18_3_trainer_7
.global ow_script_map_18_3_trainer_17
.global ow_script_map_18_3_trainer_5
.global ow_script_map_18_3_trainer_8
.global ow_script_map_18_3_trainer_14
.global ow_script_map_18_3_trainer_15
.global ow_script_map_18_3_trainer_13
.global ow_script_0x963590
.global ow_script_0x963483
.global ow_script_map_18_3_trainer_18
.global ow_script_map_18_3_trainer_3

ow_script_map_18_3_trainer_0:
trainerbattlestd 0x0 0x93 0x0 str_0x95e1ca str_0x95e223
loadpointer 0x0 str_0x95e223
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e1ca:
    .string "Von Zeit zu Zeit fliegt ein\nbrennendes Pokémon über diese\lGegend.\pIch werde es fangen!"



str_0x95e223:
    .string "Wenn du ein brennendes\nFlug-Pokémon findest, sag mir\lbescheid, ja?"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_1:
loadpointer 0x0 str_0x95e271
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e271:
    .string "Ich suche das Pokémon Panzaeron!\nEs heißt, dass es sehr selten ist\lund sich deswegen in den von Asche\lbedeckten Gräsern verstecktDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_2:
trainerbattlestd 0x0 0x94 0x0 str_0x95e31f str_0x95e369
loadpointer 0x0 str_0x95e369
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e31f:
    .string "Das einzige, was noch heißer ist,\nals dieser Ort, wäre meine\lWenigkeit!"



str_0x95e369:
    .string "Wie kannst du meine Schönheit so\ndreist misachten?"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_3:
loadpointer 0x0 str_0x95e3a7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e3a7:
    .string "In Hoenn gibt es eine Person, die\naus Asche Flöten herstellen kann.\pDie Klänge sollen Pokémon bei der\nGenesung helfen."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_4:
trainerbattlestd 0x0 0x95 0x0 str_0x95e437 str_0x95e496
loadpointer 0x0 str_0x95e496
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e437:
    .string "Was hat mich nur geritten, einen\nCampingsauflug in diese\lweltgewordene Hölle zu\lunternehmen?"



str_0x95e496:
    .string "Überall nur Asche und FeuerDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_5:
loadpointer 0x0 str_0x95e4c0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e4c0:
    .string "Es mag zwar nicht so aussehen,\naber der Boden in der Nähe eines\lVulkans ist sehr nährstoffhaltig.\pPokémon und Menschen siedeln seit\nJahrhunderten an diesen Orten."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_6:
trainerbattlestd 0x0 0x96 0x0 str_0x95e57c str_0x95e5cf
loadpointer 0x0 str_0x95e5cf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e57c:
    .string "Ich bin nicht begeistert von\ndiesem Ort, aber mein Pokémon\lliebt ihn über alles."



str_0x95e5cf:
    .string "Mit einem Hundemon am\nHöllenschlund spazieren gehenDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_7:
loadpointer 0x0 str_0x95e61e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95e61e:
    .string "Es ist schon faszinierend, dass\ndas Pokéradar selbst unter den\lwidrigen Bedingungen hier noch\leinwandfrei funktioniert."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_8:
loadpointer 0x0 str_0x95eb56
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95eb56:
    .string "Hui! Schau mal, ich wirble Asche\nauf, indem ich renne! Hui!"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_9:
loadpointer 0x0 str_0x95eb93
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95eb93:
    .string "Vor vielen Jahren haben Hexen hier\nBeschwörungsrituale abgehalten.\pDie Magie der Dunklen Königin soll\nin der Lage sein, das Landmassen-\lPokémon Groudon zu binden.\pWenn du mich fragst, ist hinter\ndiesem Hokus-Pokus nichts Wahres."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_11:
loadpointer 0x0 str_0x95ed28
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ed28:
    .string "Inferior ist lange umkämpft\ngewesen unter den Top Vier.\pNun, da der Champion Lucius fort\nist, weiß man nie genau, ob der\lSchwarze Devin erneut einen\lVersuch unternimmt, dieses Gebiet\lzu unterwerfenDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_10:
trainerbattlestd 0x0 0x97 0x0 str_0x95ec91 str_0x95ecf7
loadpointer 0x0 str_0x95ecf7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ec91:
    .string "Hitze hat erstaunliche Einflüsse\nauf bestimmte Arten von Pokémon.\pLass mich dir diese Kraft zeigen!"



str_0x95ecf7:
    .string "Was? Du hast der Kraft des Feuers\nwiderstanden?"


.elseif LANG_EN

.endif

ow_script_0x95edfb:
setvar 0x8000 POKEMON_FEURIGEL
call ow_script_find_egg
end


ow_script_map_18_3_trainer_12:
trainerbattlestd 0x0 0x98 0x0 str_0x95f49e str_0x95f53d
loadpointer 0x0 str_0x95f53d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f49e:
    .string "Wir Ranger sind eine von den Top\nVier unabhängige Gruppe, die sich\lum das Wohl Thetos sorgt.\lBesonders in gefährlichen Gebieten\lmüssen wir auf der Hut sein!"



str_0x95f53d:
    .string "Du scheinst recht zäh zu sein,\nverbrenn\' dich nicht."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_15:
loadpointer 0x0 str_0x9631de
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9631de:
    .string "Ich werde mein ganzes Team aus\nFeuer-Pokémon zusammenstellen.\pDann werde ich der nächste\nArenaleiter von Inferior!"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_18:
loadpointer 0x0 str_0x963601
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x963601:
    .string "Der Volcano soll laut der Legende\ndie Heimat eines legendären\lPokémon sein."


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_13:
trainerbattlestd 0x0 0x9f 0x0 str_0x962fde str_0x96313e
loadpointer 0x0 str_0x96313e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x962fde:
    .string "Ich verschicke viele meiner\ngezüchteten Pokémon im\lWundertausch, um dann auch fremde\lPokémon aufzuziehen."



str_0x96313e:
    .string "Willst du mir eines deiner Pokémon\nüberlassen? Sie sind stark!"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_14:
trainerbattlestd 0x0 0xa0 0x0 str_0x96317e str_0x9631b1
loadpointer 0x0 str_0x9631b1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x96317e:
    .string "Wanderschaft trainiert den Körper\nausgezeichnet."



str_0x9631b1:
    .string "Oh, du bist wohl auch recht viel\nunterwegs?"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_16:
trainerbattlestd 0x0 0xa1 0x0 str_0x963252 str_0x9632aa
loadpointer 0x0 str_0x9632aa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x963252:
    .string "Manche würden behaupten, dass es\nnicht klug ist, im Aschegras ein\lPicknick zu halten."



str_0x9632aa:
    .string "Ich aber sage nurDOTS\nHust, hustDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_19:
trainerbattlestd 0x0 0xa2 0x0 str_0x96364e str_0x96368c
loadpointer 0x0 str_0x96368c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x96364e:
    .string "Meine Pokémon speien Flammen und\nwir werden dich versengen!"



str_0x96368c:
    .string "Wuah! Dein Feuer war heißer als\ndas meineDOTS"


.elseif LANG_EN

.endif


ow_script_map_18_3_trainer_17:
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