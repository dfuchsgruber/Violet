.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_map_5_12_person_5
.global ow_script_0x8a3829
.global ow_script_map_5_12_person_4
.global ow_script_map_5_12_person_0
.global ow_script_map_5_12_person_2
.global ow_script_map_5_12_person_1
.global ow_script_map_5_12_person_3

ow_script_map_5_12_person_1:
loadpointer 0x0 str_0x8a3523
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a3523:
    .string "Wir leben hier zusammen mit den\nEltern meines Mannes. Eine große\lFamilie um sich zu haben ist doch\letwas tolles, nicht?"


.elseif LANG_EN

.endif


ow_script_map_5_12_person_0:
loadpointer 0x0 str_0x8a359d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a359d:
    .string "Mein Vater hat die Mythologie der\nPokémon Welt studiert. Sein Werk\lträgt den Titel QUOTE_STARTUnsere Welt - vom\lEi zum PokémonQUOTE_END und ist weltweit\lein Bestseller. Ich bin sehr stolz\ldeswegen."


.elseif LANG_EN

.endif


ow_script_map_5_12_person_4:
loadpointer 0x0 str_0x8a3651
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a3651:
    .string "Opi kennt so viele tolle\nGeschichten. Und Omi hat die ganze\lWelt bereist, erzählt sie immer!"


.elseif LANG_EN

.endif


ow_script_map_5_12_person_5:
loadpointer 0x0 str_0x8a36af
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a36af:
    .string "Hunger! Ich habe Hunger! Mami soll\nendlich Essen machen! Hunger!"


.elseif LANG_EN

.endif


ow_script_map_5_12_person_3:
loadpointer 0x0 str_0x8a36f1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a36f1:
    .string "Als Forscherin habe ich die ganze\nWelt bereist und meinen Beitrag\lzur Entdeckung der Mega-Evolution\lgeleistetDOTS Guten Gewissens haben\lich, mein Mann und unsere Kinder\lund Enkel uns hier niedergelassen."


.elseif LANG_EN

.endif


ow_script_map_5_12_person_2:
lock
faceplayer
loadpointer 0x0 str_0x8a4832
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4537
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a382c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a3f1e
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4108
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4349
callstd MSG_FACE
release
end


ow_script_0x8a3829:
release
end


.ifdef LANG_GER

str_0x8a4832:
    .string "Ich bin ein weltweit angesehener\nHistoriker und habe die Urpsrünge\lsowohl der Menschen als auch der\lPokémon erforscht. Möchtest du\letwas darüber wissen? Doch sei\lgewarnt, es ist keine kurze\lGeschichteDOTS"



str_0x8a4537:
    .string "Am Anfang war alles nichts bis auf\neinen Punkt vereinigte Energie,\lder sich ausgedehnt hat. In Form\leines Pokémons trat die\lursprüngliche Macht, wie ich sie\lnenne, die alles erschaffen hat,\lin unsere Welt. Die Legende\lspricht von einem Ei, aus dem es\lgeschlüft ist. Wie dem auch sei,\lerschuf es mit seiner Willenskraft\ldie Raumzeit, die die Entstehung\lvon räumlicher Materie entlang\leiner Zeit ermöglichte. Zudem\lschuf es die Welt, jenseits der\lunseren, gewissermaßen eine Welt,\ldie die unsere instande hält und\lkatalyisert: Die Zerrwelt. In\lunserer Welt aber schuf es dann\ldas Pokémon, von dem alle anderen\labstammen: Mew. Mit dem Schaffen\lder Planeten und Sonnen gelang es\lMew, einen Planeten mit Menschen\lund Pokémon zu besiedeln.\lMöchtest du mehr wissen?"



str_0x8a382c:
    .string "Die ersten Pokémon, die Mew ins\nLeben gerufen hatte, waren Wächter\lder Raumzeit: Palkia und Dialga,\lsowie Giratina, den Rebellen.\lWährend Palkia die Integrität des\lRaumes wahrte, sicherte Dialga die\lder Zeit. Giratina hingegen wurde\ldamit beauftragt, die beiden\lGebilde ineinander zu verwinden,\lsodass sie nunmehr zusammenwachsen\lkonnten.\lFolgend schuf man den Landformer\lGroudon, den Meeresformer Kyogre\lund deren Wächter, den Luftformer\lRayquaza. Mit ihnen brach der\lerste Krieg auf dieser Welt aus,\lein Krieg, dessen Resultat die\lVersiegelung der Land und\lWasserformer, sowie die Entstehung\lvon Kontinenten und Meeren war.\lDer Luftformer allerdings streift\lnoch immer durch die Wolken,\lwartend auf die Rückkehr der\lbeiden anderen.\lMöchtest du mehr hören?"



str_0x8a3f1e:
    .string "Der zweite Krieg ließ nicht\nlange auf sich warten. Nachdem Mew\letwaige andere Pokémon geschaffen\lhatte, brach die erste Finsternis\lüber die Welt herein. Darkrai, der\lNeumond, stiftete Giratina an, die\lHerrschaft über Dialga und Palkia,\lalso die Raumzeit, anzufordern. Ein\lschrecklicher, schrecklicher Krieg\lentbrannte und drohte, die Welt zu\lvernichten, da der Schöpfer aus\ldem Ei, Arceus, sich abermals in\lseine Welt begab und Giratina in\ldie Zerrwelt verbannte.\lMöchtest du mehr hören?"



str_0x8a4108:
    .string "Darkrai, jedoch, hatte Arceus\nverschont. So wie die Welt Licht\lbrauchte, so war Finsternis nötig,\lum das Gleichgewicht zu wahren.\lCresselia, der Vollmond, trat als\lDarkrais Rivale auf und stellte\labermals den Frieden in der Welt\lsicher. Bald aber erkannte die\lanfangs unterlegene Rasse der\lMenschen, mit welcher Macht die\lPokémon gesegnet waren und\lbegannen, diese für ihre Zwecke\lauszunutzen. Sie fanden bald eine\lMöglichkeit, die Wesen zu\lbeherrschen und formten große\lArmeen, nötigten die Pokémon dazu,\lgegeneinander zu kämpfen. Ein\ldritter Krieg brach aus.\lMöchtest du mehr hören?"



str_0x8a4349:
    .string "Tausend Leben, sowohl von Menschen\nals auch von Pokémon, forderte\lder dritte große Krieg ein,\ldie Sieger nahmen sich das Recht,\llegendäre Pokémon an sich zu fesseln\lund gaben sich selbst den Titel\lGötter. Sie zogen fort und wurden von\lda an nie wieder gesehenDOTS\lEinen vierten Krieg gab es\lbisweilen nicht, denn viel zu\lgroß, war das Leid, das der\ldritte Krieg heraufbeschworen\lhatte. Mensch und Pokémon leben\lSeite an Seite in Frieden und man\lkann nur hoffen, dass das so\lbleibt, findest du nicht?"


.elseif LANG_EN

.endif