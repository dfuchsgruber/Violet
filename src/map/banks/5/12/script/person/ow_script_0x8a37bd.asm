.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8a37bd
ow_script_0x8a37bd:
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


.global ow_script_0x8a3829
ow_script_0x8a3829:
release
end


.ifdef LANG_GER
.global str_0x8a4832

str_0x8a4832:
    .string "Ich bin ein weltweit angesehener\nHistoriker und habe die Urpsrünge\lsowohl der Menschen als auch der\lPokémon erforscht. Möchtest du\letwas darüber wissen? Doch sei\lgewarnt, es ist keine kurze\lGeschichteDOTS"
        
        
.global str_0x8a4537

str_0x8a4537:
    .string "Am Anfang war alles nichts bis auf\neinen Punkt vereinigte Energie,\ldie sich ausgedehnt hat. In Person\leines Pokémons trat die\lursprüngliche Macht, wie ich sie\lnenne, die alles erschaffen hat,\lin unsere Welt. Die Legende\lspricht von einem Ei, aus dem es\lgeschlüft ist. Wie dem auch sei,\lerschuf es mit seiner Willenkraft\ldie Raumzeit, die die Entstehung\lvon räumlicher Materie eintlang\leiner Zeit ermöglichte. Zudem\lschuf es die Welt, jenseits der\lUnseren, gewissermaßen eine Welt,\ldie die unsere instande hält und\lkatalyisert, die Zerrwelt. In\lunserer Welt aber schuf es dann\ldas Pokémon, von dem alle anderen\labstammen, Mew. Mit dem Schaffen\lder Planeten und Sonnen gelang es\lMew, einen Planeten mit Menschen\lund Pokémon zu besiedeln.\lMöchtest du mehr wissen?"
        
        
.global str_0x8a382c

str_0x8a382c:
    .string "Die ersten Pokémon, die Mew ins\nLeben gerufen hatte, waren Wächter\lder Raumzeit, Palkia und Dialga,\lsowie Giratina, den Rebellen.\lWährend Palkia die Integrität des\lRaumes wahrte, sicherte Dialga die\lder Zeit. Giratina hingegen wurde\ldamit beauftragt, die beiden\lGebilde ineinander zu verwinden,\lsodass sie nunmehr zusammenwachsen\lkonnten.\lFolgend schuf man den Landformer\lGroudon, den Meeresformer Kyogre\lund deren Wächter, den Luftformer\lRayquaza. Mit ihnen brach der\lerste Krieg auf dieser Welt aus,\lein Krieg, dessen Resultat die\lVersiegelung der Land und\lWasserformer, sowie die Entstehung\lvon Kontinenten und Meeren war.\lDer Luftformer allerdings streift\lnoch immer durch die Wolken,\lwartend auf die Rückkehr der\lbeiden anderen.\lMöchtest du mehr hören?"
        
        
.global str_0x8a3f1e

str_0x8a3f1e:
    .string "Der zweite Krieg ließ nicht\nlange auf sich warten. Nachdem Mew\letwaige andere Pokémon geschaffen\lhatte, brach die erste Finsternis\lüber die Welt herin. Darkrai, der\lNeumond stiftete Giratina an, die\lHerrschaft über Dialga und Palkia,\lalso die Raumzeit anzufordern. Ein\lschrecklicher, schrecklicher Krieg\lentbrannte und drohte die Welt zu\lvernichten, da der Schöpfer aus\ldem Ei, Arceus, sich abermals in\lseine Welt begab und Giratina in\ldie Zerrwelt verbannte.\lMöchtest du mehr hören?"
        
        
.global str_0x8a4108

str_0x8a4108:
    .string "Darkrai jedoch hatte Arceus\nverschont. So wie die Welt Licht\lbrauchte, so war Finsternis nötig,\lum das Gleichgewicht zu wahren.\lCresselia der Vollmond trat als\lDarkrais Rivale auf und stellte\labermals den Frieden in der Welt\lsicher. Bald aber erkannte die\lanfangs unterlegene Rasse der\lMenschen, mit welcher Macht die\lPokémon gesegnet waren und\lbegannen, diese für ihre Zwecke\lauszunutzen. Sie fanden bald eine\lMöglichkeit, die Wesen zu\lbeherrschen und formten große\lArmeen, nötigten die Pokémon\lgegeneinander zu kämpfen. Ein\ldritter Krieg brach aus.\lMöchtest du mehr hören?"
        
        
.global str_0x8a4349

str_0x8a4349:
    .string "Tausend Leben sowohl von Menschen\nund Pokémon forderte der dritte\lgroße Krieg ein, die Sieger nahmen\lsich das Recht, legendäre Pokémon\lan sich zu fesseln und gaben\lsich selbst den Titel Götter. Sie\lzogen fort und wurden von da an\lnie wieder gesehenDOTS\lEinen vierten Krieg gab es\lbisweilen nicht, denn viel zu\lgroß, war das Leid, dass der\ldritte Krieg heraufbeschworen\lhatte. Mensch und Pokémon leben\lSeite an Seite in Frieden und man\lkann nur hoffen, dass das so\lbleibt, findest du nicht?"
        
        
.elseif LANG_EN

.endif
