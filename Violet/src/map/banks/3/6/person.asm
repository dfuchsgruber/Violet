.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_map_3_6_person_8
.global ow_script_map_3_6_person_9
.global ow_script_map_3_6_person_0
.global ow_script_map_3_6_person_2
.global ow_script_map_3_6_person_6
.global ow_script_map_3_6_person_3
.global ow_script_map_3_6_person_5
.global ow_script_map_3_6_person_4
.global ow_script_map_3_6_person_1
.global ow_script_0x86bcdf
.global ow_script_0x86f083
.global ow_script_0x9638fb
.global ow_script_map_3_6_person_7

ow_script_map_3_6_person_0:
loadpointer 0x0 str_0x860241
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x860241:
    .string "Mistral wird das Fragment des\nZeitsteins sicherstellen.\pSolange er beschäftigt ist, halten\nwir die Stadt in Schach."


.elseif LANG_EN

.endif


ow_script_map_3_6_person_1:
loadpointer 0x0 str_0x86bd85
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86bd85:
    .string "Mistrals Division in Team Violet\nüberragt die von Rin bei weitem.\pWir sind eine gefährliche Macht,\ndie alles niederstampft!"


.elseif LANG_EN

.endif


ow_script_map_3_6_person_2:
loadpointer 0x0 str_0x86ef43
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86ef43:
    .string "Du bist der doch der Junge aus dem\nOrina City Museum.\pHat dich Mistral nicht gewarnt,\nihm fernzubleiben?"


.elseif LANG_EN

.endif


ow_script_map_3_6_person_4:
loadpointer 0x0 str_0x965932
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965932:
    .string "Inferior wurde am Fuß des Volcanos\nerbaut.\pDie Legende besagt, dass hier die\nKönigin der Nacht die Pforten zur\lHölle geöffnet hat."


.elseif LANG_EN

.endif


ow_script_map_3_6_person_5:
loadpointer 0x0 str_0x9659b6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9659b6:
    .string "Igva ist wirklich eine wahnsinns\nFrau!\pIch bin wohl nicht der einzige\nHitzkopf, der ein Auge auf dieses\lentflammte Mädchen geworfen hat!"


.elseif LANG_EN

.endif


ow_script_map_3_6_person_6:
loadpointer 0x0 str_0x965a40
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965a40:
    .string "Viele alte Menschen besuchen\nInferior der heißen Quellen wegen.\pDas Wasser soll eine reinigende\nWirkung auf Seele und Körper\lhaben."


.elseif LANG_EN

.endif


ow_script_map_3_6_person_7:
loadpointer 0x0 str_0x965ac5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965ac5:
    .string "Ich komme nur wegen der schönen\nDamen, die sich hier in den\lThermen tummeln!\pHehe! Aber das erzählst du\nnatürlich niemandem, oder?"


.elseif LANG_EN

.endif


ow_script_map_3_6_person_8:
loadpointer 0x0 str_0x86eed0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86eed0:
    .string "Ich habe gehört, dass man in den\nThermen besonders gut Pokémon-Eier\lausbrüten kann."


.elseif LANG_EN

.endif


ow_script_map_3_6_person_9:
loadpointer 0x0 str_0x86f08d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86f08d:
    .string "Ob wir Angst vor einem\nVulkanausbruch haben?\pFürchten sich die Leute an der\nKüste vor einem Tsunami?"


.elseif LANG_EN

.endif


ow_script_map_3_6_person_3:
checkflag INFERIOR_EGG
gotoif EQUAL ow_script_0x86bcdf
lock
faceplayer
loadpointer 0x0 str_0x965895
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x9638fb
countpokemon
compare LASTRESULT 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x86f083
giveegg POKEMON_RABAUZ
fanfare 0x13e
loadpointer 0x0 str_0x86f069
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0x86efce
callstd MSG_KEEPOPEN
closeonkeypress
release
setflag INFERIOR_EGG
end


ow_script_0x86f083:
loadpointer 0x0 str_0x963869
callstd MSG
release
end


ow_script_0x9638fb:
loadpointer 0x0 str_0x963906
callstd MSG
release
end


ow_script_0x86bcdf:
loadpointer 0x0 str_0x86efce
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x965895:
    .string "Wenn du Eier in den heißen Quellen\nausbrütest, schlüpfen sie\lschneller.\pIch komme oft hierher, um Eier\nauszubrüten.\pWas sagst du, möchtest du ein Ei\nhaben?"



str_0x86f069:
    .string "PLAYER hat ein Ei erhalten!"



str_0x86efce:
    .string "Wenn du dich in den heißen Quellen\naufgehalten hast, hält die Wärme\lauch an, nachdem du sie schon\lverlassen hast.\pDeine Eier schlüpfen so schneller\naus!"



str_0x963869:
    .string "Oh, was für ein Pech!\nEs sieht aus, als hättest du\lkeinen Platz mehr in deinem Team.\pKomm wieder, wenn du Platz in\ndeinem Team geschaffen hast."



str_0x963906:
    .string "Wie überaus schade!\pIch werde hier warten, solltest du\nes dir doch anders überlegen."


.elseif LANG_EN

.endif


ow_script_person_test:
    givepokemon POKEMON_FORMEO 20 0 0 0 0
    @//setflag FLAG_POKEDEX_SCANNER
    end