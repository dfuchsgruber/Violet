.include "vars.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_map_1_0_trainer_0
.global ow_script_map_1_0_trainer_3
.global ow_script_map_1_0_trainer_12
.global ow_script_map_1_0_trainer_6
.global ow_script_map_1_0_trainer_16
.global ow_script_map_1_0_trainer_18
.global ow_script_map_1_0_trainer_15
.global ow_script_map_1_0_trainer_1
.global ow_script_map_1_0_person_0
.global ow_script_map_1_0_trainer_7
.global ow_script_map_1_0_trainer_19
.global ow_script_map_1_0_trainer_4
.global ow_script_map_1_0_trainer_11
.global ow_script_map_1_0_trainer_13
.global ow_script_map_1_0_trainer_5
.global ow_script_map_1_0_trainer_2
.global ow_script_map_1_0_trainer_10
.global ow_script_map_1_0_trainer_14
.global ow_script_map_1_0_trainer_8
.global ow_script_map_1_0_trainer_9
.global ow_script_map_1_0_trainer_17
.global ow_script_silvania_wald_person_28

ow_script_movs_0x8ecd19:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_1_0_trainer_5:
lock
faceplayer
applymovement 0x800f ow_script_movs_0x8ecd19
waitmovement 0x0
loadpointer 0x0 str_0x8f4305
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM46
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
lock
faceplayer
loadpointer 0x0 str_0x8ef5ca
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER

str_0x8f4305:
    .string "Du schon wieder! Du hast mich und\nmeine Pokémon in Blütenbach\lschon besiegtDOTS\lHier, nimm das und lass mich\lgefälligst in Ruhe!"



str_0x8ef5ca:
    .string "Buhu! Ich wollte doch nur etwas\nbewirkenDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_18:
loadpointer 0x0 str_0x8ef577
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef577:
    .string "Freddies Musik soll einer Legende\nnach sogar legendäre Pokémon\lvernichten können."


.elseif LANG_EN

.endif


ow_script_map_1_0_person_0:
loadpointer 0x0 str_0x8ef678
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef678:
    .string "Ich bin hierher gekommen, um dem\nlegendären Zeitpokemon zu\lbegegnen. Wo es sich wohl\lversteckt?"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_17:
trainerbattlestd 0x0 0x41 0x0 str_0x88ae2e str_0x8e6b0e
loadpointer 0x0 str_0x8e6b0e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x88ae2e:
    .string "Ich will nicht in die Schule\ngehen! Unterricht ist so öde!"



str_0x8e6b0e:
    .string "In der Schule hätte ich bestimmt\ngelernt, dich zu besiegen!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_14:
trainerbattlestd 0x0 0x42 0x0 str_0x8f2a42 str_0x8f2adf
loadpointer 0x0 str_0x8f2adf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f2a42:
    .string "Nenn mich einen Spielverderber,\naber wenn ich etwas nicht gut\lfinde, sollte es verboten werden.\lMeine Moralvorstellungen sollten\ldas Maß aller Dinge sein."



str_0x8f2adf:
    .string "Dein Kampfstil gehört verboten!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_10:
loadpointer 0x0 str_0x8f2b00
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f2b00:
    .string "Viele sind der Meinung, es gäbe\nverschiedene Zeitlinien.\lCelebi, das Zeitpokemon, soll\ljedoch über ihnen existieren und\lsie alle kennen."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_12:
loadpointer 0x0 str_0x8f384c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f384c:
    .string "Vor einiger Zeit gab es großen\nAufruhr in Theto, als ein junges\lTrainertalent den Champion\lentthront hat.\lNiemand weiß so recht, wo der\lbesiegte Champion geblieben istDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_11:
trainerbattlestd 0x0 0x43 0x0 str_0x8ef778 str_0x8ef878
loadpointer 0x0 str_0x8ef878
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef778:
    .string "Manche mögen Käferpokemon für\nschwach halten, ich aber sage, sie\lbergen riesiges Potenzial!"



str_0x8ef878:
    .string "Dein Sieg ist kein Beweis für die\nSchwäche der Käfer-Pokémon!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_13:
loadpointer 0x0 str_0x8f38f8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f38f8:
    .string "Die Revolutionsbewegung fordert\nFreiheit und ein Ende der\lKorruption.\lKeine schlechten Forderungen, wenn\lman bedenkt, wie sich die Welt\lentwickelt hatDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_19:
loadpointer 0x0 str_0x8ef978
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef978:
    .string "Team Violet rekrutiert in der\nganzen Region Mitglieder. Sie\lversprechen einem, Teil von etwas\lgroßem, bedeutendem zu sein."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_15:
loadpointer 0x0 str_0x8ecc17
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ecc17:
    .string "Der westliche Teil Thetos wird vom\nältesten der Top Vier regiert."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_16:
loadpointer 0x0 str_0x8f4254
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4254:
    .string "Wenn man immer weiter westwärts\nläuft, erreicht man irgendwann\leine Wüstenregion.\pNur einige Wegstunden entfernt\naber erreicht man Kaskada, die\lStadt der reinen Wasserquellen."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_0:
trainerbattlestd 0x0 0x44 0x0 str_0x8f2b8a str_0x8f3993
loadpointer 0x0 str_0x8f3993
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f2b8a:
    .string "Wir von Team Violet sind daran\ninteressiert, die Welt in einen\lbesseren Ort zu verwandeln.\lMit einem Krieg werden wir Frieden\lstiften!"



str_0x8f3993:
    .string "Du wirst uns nicht aufhalten\nkönnen, der ewige Frieden wird\lkommen!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_1:
trainerbattlestd 0x0 0x45 0x0 str_0x8efa78 str_0x8efb78
loadpointer 0x0 str_0x8efb78
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8efa78:
    .string "Ich muss in der Region für Ordnung\nund Sicherheit sorgen. Freiwillige\lRanger sind im Gegensatz zur\lPolizei nicht korrupt."



str_0x8efb78:
    .string "Team Violet ist sowohl der Polizei\nals auch den Rangern ein Dorn im\lAuge!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_3:
trainerbattlestd 0x0 0x46 0x0 str_0x8efc78 str_0x8f0916
loadpointer 0x0 str_0x8f0916
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8efc78:
    .string "Die Welt ist ein grauenvoller Ort.\nWir werden sie unter einen ewigen\lFrieden bringen!"



str_0x8f0916:
    .string "Niemand kann sich gegen den\nFrieden selbst wehren, auch du\lnicht!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_2:
trainerbattlestd 0x0 0x47 0x0 str_0x8f4388 str_0x8f43ce
loadpointer 0x0 str_0x8f43ce
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4388:
    .string "In diesem Wald kann man Pokémon\ndes Typs Flug exzellent\ltrainieren!"



str_0x8f43ce:
    .string "Huch, du bist ein stärkerer Gegner\nals die wilden Pokémon in diesem\lWald."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_9:
loadpointer 0x0 str_0x8f4419
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4419:
    .string "Es heißt, dass es einen Stein\ngeben soll, der das Herz der Zeit\lrepräsentiert. Seine Energie soll\lgrenzenlos sein."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_6:
trainerbattlestd 0x0 0x48 0x0 str_0x8f448d str_0x8f4519
loadpointer 0x0 str_0x8f4519
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f448d:
    .string "Unsere Gesellschaft beutet den\nEinzelnen aus. Korruption und\lVerzweiflung sind die Folge.\lWir kreieren eine Welt, in der es\lFrieden gibt."



str_0x8f4519:
    .string "Wir sind Teil des großen Plans,\nund du wirst uns nicht aufhalten!"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_4:
loadpointer 0x0 str_0x8f455c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f455c:
    .string "Ich suche hier nach Knilz, einem\nPilz-Pokémon. Ob ich es finden\lkann?"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_7:
loadpointer 0x0 str_0x8f45a3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f45a3:
    .string "Wenn eines meiner Pokémon die\nAttacke Surfer beherrschen würde,\lkönnte ich diesen Fluss nach\lKaskada hinaufschwimmen."


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_8:
trainerbattlestd 0x0 0x49 0x0 str_0x8ef8b7 str_0x8efbc3
loadpointer 0x0 str_0x8efbc3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef8b7:
    .string "Ich kämpfe für Frieden und\nOrdnung! Und mein Kampf ist nobel!"



str_0x8efbc3:
    .string "Als Herrscher der Welt bringen wir\ndie Ordnung!"


.elseif LANG_EN

.endif



ow_script_silvania_wald_person_28:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mir kommt es immer wieder vor, als würde die Zeit hier im Wald stillstehenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "From time to time I feel like the time in this forest would stand stillDOTS"
.endif