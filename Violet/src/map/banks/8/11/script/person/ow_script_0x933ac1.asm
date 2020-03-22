.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"

.global ow_script_black_market_igva_final

ow_script_black_market_igva_final:
	checkflag KASKADA_BLACKMARKET_PRIMUS
	gotoif LESS not_done
	checkflag KASKADA_BLACKMARKET_BLAISE
	gotoif LESS not_done
	checkflag KASKADA_BLACKMARET_BB_SHIP
	gotoif LESS not_done
	lock
	faceplayer
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	clearflag PKMNMENU
	showsprite 29
	showsprite 30
	showsprite 31
	applymovement 29 mov_6u
	applymovement 30 mov_6u
	applymovement 31 mov_6u
	loadpointer 0 str_1
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	waitmovement 0
	sound 0x15
	applymovement 31 mov_exclam
	waitmovement 0
	checksound
	pause 16
	loadpointer 0 str_2
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_3
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_4
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_5
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_6
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_7
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_8
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	applymovement 29 mov_6d
	applymovement 30 mov_6d
	applymovement 31 mov_6d
	waitmovement 0
	hidesprite 29
	hidesprite 30
	hidesprite 31
	loadpointer 0 str_9
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	fadescreen 1
	hidesprite 32
	fadescreen 0
	release
	end

not_done:
	loadpointer 0 str_not_done
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG_FACE
	end


.ifdef LANG_GER
str_not_done:
	.autostring 34 2 "PLAYER, du solltest dich hier noch ein wenig umsehen."
str_0:
	.autostring 34 2 "Es ist erschreckend, welche Dinge im Untergrund von Theto vor sich gehen, nicht?\pDie Pokémon-Liga ist längst ein Teil dieser verbrecherischen Welt geworden.\pUnd genau deshalbDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTSist es die Pflicht eines jeden Menschen, sich dagegen aufzulehnen.\pPLAYER, falls du es noch nicht bemerkt hast, ich bin ein Mitglied der Revolutionsbewegung.\pUnd irgendetwas sagt mir, dass du gut in unsere Reihen passen würdest.\pWas sagst du, willst du dich unserer Sache anschließen?"
str_1:
	.autostring 34 2 "Igva, wir brechen aufDOTS"
str_2:
	.autostring 34 2 "PLAYER, was treibst du an einem solchen Ort?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs war wohl Igva, die dich hierher geführt hat, nicht?"
str_3:
	.autostring 34 2 "PLAYER soll sich ein Bild von den Verhältnissen in dieser Region machen."
str_4:
	.autostring 34 2 "Igva, ich freue mich über deine Leidenschaft für unsere Sache.\pAber PLAYER sollte sich Zeit nehmen, sich zu entscheiden, auf wessen Seite er stehen möchte.\pDas letzte Mal, als du jemanden mit so viel Engagement angeworben hastDOTS\pDu weißt ja, wie das ausgegangen ist."
str_5:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
str_6:
	.autostring 34 2 "PLAYER.\nJetzt, wo du diesen Ort gesehen hast, ist dir vielleicht ein Stück klarer geworden, weshalb ich mich dazu entschlossen habe, die Pokémon-Liga zu zerschlagen.\pAber ich bleibe dabei, dich nicht zu einer Entscheidung zwingen zu wollen.\pDu bist noch jung und gerade erst ein Trainer geworden.\pDie Welt ist viel größer, beeindruckender und, ja, auch beängstigender, als du es dir jetzt noch vorstellen kannst.\pLass dich nicht von deinem Weg abbringen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIgva, wir ziehen weiter."
str_7:
	.autostring 34 2 "Gib mir noch einen Moment mit PLAYER, bitte."
str_8:
	.autostring 34 2 "Ganz wie du möchtestDOTS"
str_9:
	.autostring 34 2 "PLAYER, ich will ganz offen zu dir sein.\pVor einiger Zeit traf ich jemanden, den ich wie dich für die Revolution gewinnen wollte.\pVielleicht bin ich in der Hinsicht etwas zu eifrigDOTS\pLetztlich muss wohl der Antrieb, sich dieser Sache anzuschließen, von einem selbst kommen.\pSolltest du also je das ehrliche Bedürfnis verspüren, etwas an den bestehenden Verhältnissen zu ändernDOTS\pDann werde ich dich jederzeit mit offenen Armen empfangen, PLAYER.\pIch will, dass du das weißt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch hoffe, dass wir uns eines Tages wiedersehen, PLAYER!"

.elseif LANG_EN

.endif

mov_6u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_6d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

mov_exclam:
	.byte SAY_EXCLAM, STOP
