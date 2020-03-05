.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x93d59c
ow_script_0x93d59c:
lock
faceplayer
buffernumber 0 WONDERTRADE_CNT
draw_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x949632
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x949573
setvar BATTLE_SONG_OVERRIDE 0x165
trainerbattlecont 0x1 0x84 0x0 str_0x94948c str_0x949515 ow_script_0x93d5e1


.global ow_script_0x93d5e1
ow_script_0x93d5e1:
loadpointer 0x0 str_0x94918c
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x800f
setflag ROUTE_5_VIOLET_GRUNTS
fadescreen 0x0
release
end


.global ow_script_0x949573
ow_script_0x949573:
loadpointer 0x0 str_0x949581
callstd MSG
hide_mugshot
release
end


.ifdef LANG_GER
.global str_0x949632

str_0x949632:
	.autostring 35 2 "Oh, hallo PLAYER!\nEntschuldige, ich wollte dich nicht überrumpeln.\pBenutzt du auch die Wundertausch-App?\pIch sehe, du hast ihn bereits BUFFER_1 mal verwendet.\pDas freut mich!\pIch habe mich zuletzt selbst auch am Kämpfen versucht.\pNa was sagst du, hättest du Lust auf einen Kampf?"
        
        
.global str_0x94948c

str_0x94948c:
	.autostring 35 2 "Meine Pokémon habe ich allesamt aus dem Wundertausch erhalten.\pWollen wir doch einmal sehen, wie ich mich so schlage."
        
.global str_0x949515

str_0x949515:
    .autostring 35 2 "Das überrascht mich nicht.\nMir hätte eigentlich klar sein sollen, dass ein Anfänger wie ich keine Chance hat."
        
        
.global str_0x94918c

str_0x94918c:
	.autostring 35 2 "Du kämpfst wirklich auserordentlich gut, PLAYER.\pWas meinst du, wie habe ich mich geschlagen?\pVielleicht wird das Kämpfen ja zu meinem neuen Hobby.\pDie viele Forschung kann schon auch einmal recht trocken werden DOTS\pWo wir gerade beim Thema sind.\pDie Laz.Corp, das Unternehmen, bei dem ich beschäftigt bin, hat ein komplett virtuelles Pokémon erschaffen.\pDas dürfte dich interessieren, nicht?\pEs wird auch für deine Pokédex-App interessante Daten liefern.\pDer Hauptsitz der Laz.Corp liegt in Orina City, westlich von Route 2, wo das Labor von Professor Tann ist.\pKomm mich doch dort einmal besuchen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pVon mir hast du das mit dem virtuellen Pokémon aber nicht erfahren, ja?"

        
.global str_0x949581

str_0x949581:
	.autostring 35 2 "Oh, ich verstehe schon.\pDu willst deinen erschöpften Pokémon sicherlich eine Pause gönnen.\pAber ein nein akzeptiere ich als Antwort nicht!\pKomm wieder, wenn du dich erholt hast.\pSolltest du mich schlagen, verrate ich dir auch ein interessantes Geheimnis!"
        
        
.elseif LANG_EN

.endif
