.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"
.include "items.s"
.include "ordinals.s"

.global ow_script_kaskada_harrenfeld
.global ow_script_map_3_4_person_13
.global ow_script_map_3_4_person_26
.global ow_script_map_3_4_person_27
.global ow_script_map_3_4_person_14
.global ow_script_map_3_4_person_25
.global ow_script_map_3_4_person_19
.global ow_script_0x8f218b
.global ow_script_map_3_4_person_1
.global ow_script_map_3_4_person_4
.global ow_script_map_3_4_person_2
.global ow_script_map_3_4_person_20
.global ow_script_map_3_4_person_21
.global ow_script_map_3_4_person_22
.global ow_script_map_3_4_person_10
.global ow_script_map_3_4_person_3
.global ow_script_map_3_4_person_18
.global ow_script_0x8f185a
.global ow_script_map_3_4_person_17
.global ow_script_map_3_4_person_29
.global ow_script_map_3_4_person_24
.global ow_script_map_3_4_person_8
.global ow_script_map_3_4_person_23
.global ow_script_map_3_4_person_16
.global ow_script_map_3_4_person_15
.global ow_script_map_3_4_person_9
.global ow_script_map_3_4_person_28
.global ow_script_map_3_4_person_7
.global ow_script_map_3_4_person_0
.global ow_script_map_3_4_person_12
.global ow_script_map_3_4_person_6
.global ow_script_map_3_4_person_11
.global ow_script_map_3_4_person_5


ow_script_kaskada_harrenfeld:
    lock
    faceplayer
    loadpointer 0x0 str_harrenfeld0
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
    loadpointer 0x0 str_harrenfeld1
    show_mugshot MUGSHOT_HARRENFELD MUGSHOT_RIGHT MSG_KEEPOPEN
    fadescreen 1
    hidesprite 37
    hidesprite 1
    hidesprite 2
    fadescreen 0
    release
    end


.ifdef LANG_GER
str_harrenfeld0:
    .autostring 34 2 "Oh, hallo PLAYER!\nWir haben die Albus' Spur leider verloren, nachdem wir ihn am Küstenberg nicht fassen konnten.\pDas ist natürlich sehr ärgerlich, wer weiß, wann wir wieder eine solche Chance bekommen.\pAber weißt du, Faun und Albus sind alte Bekannte.\pUm genau zu sein, waren beide Mitgründer der Pokémon-Liga in ThetoDOTS"
str_harrenfeld1:
    .autostring 34 2 "Seitdem Lucius, der ehemalige Champion gestürzt wurde, gewinnt mehr und mehr das Chaos die Überhand.\pTheto braucht einen Champion, aber von Lucius' Nachfolger fehlt jede Spur.\pWir von der Polizei geben solange unser Bestes, sowohl die Revolution als auch Team Violet in Schach zu halten, aber ewig werden wir nicht standhalten könnenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNun, ich denke, die Abriegelung der Stadt kann aufgehoben werden.\pWir sehen uns, PLAYER!\pHalt die Ohren steif!"

.elseif LANG_EN
.endif


ow_script_map_3_4_person_1:
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8c8eab
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
str_police:
	.string "Polizist"


str_0x8c8eab:
    .autostring 35 2 "Solange sich der Anführer der Revolutionsbewegung hier rumtreibt, haben wir strikte Anordnung, niemanden vorbeizulassen.\pWir riegeln die Stadt ab!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_0:
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8c8f0d
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER

str_0x8c8f0d:
    .string "Lord Faun wird den Revolutionären\nzeigen, wie stark ein Mitglied der\lTop Vier ist!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_2:
loadpointer 0x0 str_0x8c90bc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c90bc:
    .string "Kaskada ist die einzige Stadt des\nOstens, die nicht dem Pinken Faun\luntersteht."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_3:
loadpointer 0x0 str_0x8c910d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c910d:
    .string "Ich beobachte gerne Menschen in\nihren Kanus.\pDOTS\pDas Wasser ist zweifellos das\nElement des Lebens!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_5:
loadpointer 0x0 str_0x8f13dc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f13dc:
    .string "Seit geraumer Zeit schon frage ich\nmich, was sich wohl in dieser\lHöhle befindetDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_6:
loadpointer 0x0 str_0x8f1430
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1430:
    .string "Das Wasser, das diese Stadt\numgibt, entspringt dem Küstenberg.\lViele nennen ihn auch den Berg des\lUrquells."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_4:
    loadpointer 0 str_01
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_01:
    .autostring 34 2 "Ich vermisse Lucius, den ehemaligen Champion.\pEr war so charismatischDOTS\pVom neuen Champion weiß man nicht einmal, wer es überhaupt istDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "I really miss Lucius, the former champ.\pHe was so charismaticDOTS\pAbout the new champ one doesn't even know who he isDOTS"
.endif


ow_script_map_3_4_person_8:
loadpointer 0x0 str_0x8f1665
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1665:
    .string "Das Wasser hier ist so sauber,\ndass man direkt davon trinken\lkönnte."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_7:
loadpointer 0x0 str_0x8f16ab
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f16ab:
    .string "Dieser Brunnen wurde dem schönsten\naller Pokemon erbaut, Milotic.\pEs heißt, dass eines von ihnen in\nden hiesigen Gewässern lebe."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_9:
loadpointer 0x0 str_0x8f172d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f172d:
    .string "Manche sagen, dass alle unsere\nEntscheidungen Auswirkungen\lhätten. Sie reden von Karma.\lGlaubst du an das Karma?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_10:
loadpointer 0x0 str_0x8f179f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f179f:
    .string "Schon lange frage ich mich, was\ndie Erbauer dieser Stadt mit\ldiesen marineblauen\lPflastersteinen zum Ausdruck\lbringen wolltenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_11:
lock
faceplayer
loadpointer 0x0 str_0x8f18a8
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f185a
loadpointer 0x0 str_0x8f1821
callstd MSG
release
end


ow_script_0x8f185a:
loadpointer 0x0 str_0x8f1865
callstd MSG
release
end


.ifdef LANG_GER

str_0x8f18a8:
    .string "Guten Tag!\nHast du Lust auf eine Fahrt mit\leinem unserer Kanus? Ein Tag\lkostet dich gerade einmal\pDOTS\neine MILLION POKEDOLLAR!\pWas sagst du?"



str_0x8f1821:
    .string "DOTS\pDu hast nicht genügend Geld?\nPah! Armer Schlucker!"



str_0x8f1865:
    .string "Wiebitte? Warum denn nicht?\pDer Preis?\pDOTS\pPah! Armer Schlucker!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_12:
loadpointer 0x0 str_0x8f192d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f192d:
    .string "Wenn meine Pokémon Kaskada\nbeherrschten, könnte ich mit ihnen\ldie Wasserfälle erklimmen."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_14:
loadpointer 0x0 str_0x8f1987
callstd MSG
end


.ifdef LANG_GER

str_0x8f1987:
    .string "Ich liebe es, gemeinsam mit meinem\nSchatz den Wellen zu lauschen."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_13:
loadpointer 0x0 str_0x8f19ca
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f19ca:
    .string "Meine Freundin und ich kommen oft\nhierher, um uns gemeinsam die\lWellen anzusehen."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_15:
loadpointer 0x0 str_0x8f1a1d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1a1d:
    .string "Wie ich mir eine Kanufahrt leisten\nkonnte?\pIch gehe arbeiten, wie das\nErwachsene eben so tun."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_16:
loadpointer 0x0 str_0x8f1a7c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1a7c:
    .string "Was? Ich habe dieses Kanu nicht\ngestohlen. Ich habe es mir nur auf\lunbestimmte Zeit geliehen!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_17:
loadpointer 0x0 str_0x8f1adb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1adb:
    .string "Was soll das heißen, ich kann hier\nnicht angeln?\pWas denkst du, was ich hier seit\nStunden treibe?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_18:
loadpointer 0x0 str_0x8f1b48
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1b48:
    .string "Willst du mich verurteilen, dass\nich mir mein Essen in Mülltonnen\lsuche?\pVerurteile lieber das System, das\neinem alten Mann nicht genug zu\lEssen gibt!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_19:
loadpointer 0x0 str_0x8f1bea
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1bea:
    .string "Der Küstenberg ist klein, doch\nhoch genug, um bei Sturm einen\langenehm salzigen Wind erleben zu\lkönnen."


.elseif LANG_EN

.endif


ow_script_map_3_4_person_21:
loadpointer 0x0 str_0x8f1dd4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1dd4:
    .string "Diese Frau in dem KanuDOTS\nSie ist so wunderschön! Aber ich\lkann einfach nicht genug Mut\lfinden, sie anzusprechen!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_22:
loadpointer 0x0 str_0x8f1e51
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1e51:
    .autostring 34 2 "Zwar wird dieses Gebiet offiziell vom Pinken Faun regiertDOTS\pAber in Wirklichkeit zieht der Schwarze Devin hier die FädenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_23:
checkflag KASKADA_EVOLITHE
gotoif EQUAL ow_script_0x8f218b
lock
faceplayer
loadpointer 0x0 str_0x8f1fda
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_EVOLITH
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8f1f5c
callstd MSG
setflag KASKADA_EVOLITHE
release
end



ow_script_0x8f218b:
loadpointer 0x0 str_0x8f1f5c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f1fda:
    .autostring 34 2 "Auch ein schwaches Pokémon kann stark sein.\pDiesen Ratschlag möchte ich dir ans Herz legen."



str_0x8f1f5c:
    .string "Der Evolith kann die Stärken eines scheinbar schwachen Pokémon hervorbringen, sofern es sich noch entwickeln kann."

.elseif LANG_EN

.endif


ow_script_map_3_4_person_20:
loadpointer 0x0 str_0x926c84
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926c84:
    .string "Keiner weiß warum um das Haus im\nSüden immerzu von irgendwelchem\lKisten umgeben ist. Was wohl dort\lgetrieben wird?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_26:
loadpointer 0x0 str_0x8f2194
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f2194:
    .string "Von einem Untergrundhandel weiß\nich nichtsDOTS\pWie, du hast nicht gefragt?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_25:
loadpointer 0x0 str_0x926cf8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926cf8:
    .string "Mann, ich würde zu gerne die\nParole kennen, um in dieses Haus\lzu kommen!\pOb sie geheime Tee-Klub Treffen\nabhalten?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_24:
loadpointer 0x0 str_0x926d6c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926d6c:
    .string "Die Parole? Warum sollte ich die\nParole kennen?"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_27:
loadpointer 0x0 str_0x926d9d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926d9d:
    .string "Wenn ich groß bin, möchte ich eine\nMillion POKEDOLLAR haben!\pDann kann ich mir endlich eine\nTour mit dem Kanu leisten!"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_28:
loadpointer 0x0 str_0x926e0c
callstd MSG
end


.ifdef LANG_GER

str_0x926e0c:
    .string "Ich vermisse die alten ZeitenDOTS\pVor den Top VierDOTS\pAls die Welt noch voller Abenteuer\nwarDOTS\pJetzt bleibt mir noch das Rauschen\nder WasserfälleDOTS\pUnd die ErinnerungenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_4_person_29:
	lock
	faceplayer
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG_YES_NO mask_name=1
	compare LASTRESULT 0
	gotoif EQUAL said_no
	loadpointer 0 str_2
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
	setflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
	fadescreen 0x1
	hidesprite 0x800f
	fadescreen 0x0
	release
	end

said_no:
	loadpointer 0 str_1
	show_mugshot MUGSHOT_IGVA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
	release
	end


.ifdef LANG_GER
str_0:
	.autostring 34 2 "Entschuldige bitte, falls ich dich damit überrumple.\pIch habe dich vorhin beobachtet, als du mit Albus, dem Anführer der Revolution gesprochen hast.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs muss seltsam wirken, aber ich möchte dir gerne etwas zeigen.\pWenn du Interesse hast, das wahre Gesicht dieser Region zu sehenDOTS\pNaja, was sagst du?"
str_1:
	.autostring 34 2 "OhDOTS\nNa gut, vielleicht habe ich mich getäuscht.\pWenn du es dir anders überlegst, ich werde noch eine Weile in der Gegend sein."
str_2:
	.autostring 34 2 "Ich wusste es!\nIrgendetwas hat mir gesagt, dass du die Art Mensch bist, die sich auch traut, hinter die glatte Fassade der Dinge zu sehen.\pDOTS DOTS DOTS\nIm Westen der Stadt gibt es ein Klubhaus, in das man nur mit einer Parole eintritt erhält.\pIch will nichts vorwegnehmen, aber du solltest dir dieses Klubhaus auf jeden Fall ansehen.\pWie war doch gleich dein Name?\pPLAYER?\nDOTS DOTS DOTS\pFreut mich sehr!\nIch bin übrigens Igva!\pWir sehen uns im Klubhaus, PLAYER!"
.elseif LANG_EN
.endif