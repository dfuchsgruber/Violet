
.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "levelscript_types.s"
.include "healingplaces.s"
.include "story_states.s"

.global lscr_0x718dc8

lscr_0x718dc8:
	.byte 0x2
	.word lscr_0x71a5df
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word script_set_healingplace
	.byte 0x0


script_set_healingplace:
	// sethealingplace HEALINGPLACE_TANNS_LAB
    setworldmapflag WM_TANNS_LAB
end


.align 4
.global lscr_0x71a5df

lscr_0x71a5df:
	.hword STORY_PROGRESS, 0xe
	.word ow_script_0x8a7586
	.hword 0x0

.global ow_script_0x8ab100
.global ow_script_0x8a7586
.global ow_script_0x8a9640
.global ow_script_0x8aac32
.global ow_script_0x8a934f
.global ow_script_0x8ad21f

ow_script_movs_0x8a820e:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x8a8214:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


ow_script_movs_0x80358f:
.byte LOOK_UP
mov_exclam:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a7f34:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x8a7f2b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a794f:
.byte SAY_QUESTION
.byte STOP


ow_script_movs_0x8a792d:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8a78ed:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_0x8a7586:
applymovement 0x3 ow_script_movs_0x8a820e
applymovement 0xff ow_script_movs_0x8a8214
waitmovement 0x0
loadpointer 0x0 str_0x8a7f97
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
update_mugshot_emotion MUGSHOT_RUMINATIVE
loadpointer 0 str_0x8a7f97_2
callstd MSG
hide_mugshot
loadpointer 0 str_rival_1
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_ANGRY
loadpointer 0 str_prof_response
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_RUMINATIVE
loadpointer 0 str_rival_2
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
loadpointer 0 str_prof_response2
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE hide_mugshot=0
update_mugshot_emotion MUGSHOT_HAPPY
loadpointer 0 str_prof_response3
callstd MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_RUMINATIVE
loadpointer 0 str_prof_response4
callstd MSG
hide_mugshot
pause 16
sound 0x15
applymovement 2 mov_exclam
waitmovement 0
checksound
loadpointer 0 str_elise_silcene
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SCARED
pause 16


loadpointer 0 str_0x8a7f97_3

show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_NORMAL
sound 0x15
applymovement 0x2 ow_script_movs_0x80358f
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7f3d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
applymovement 0x2 ow_script_movs_0x8a7f34
waitmovement 0x0
sound 23
checksound
applymovement 0x2 ow_script_movs_0x8a7f2b
waitmovement 0x0
loadpointer 0x0 str_0x8a7e8d
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a7dbf
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
sound 0x15
applymovement 0xff ow_script_movs_0x8a794f
applymovement 0x3 ow_script_movs_0x8a794f
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7930
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
applymovement 0x1 ow_script_movs_0x8a792d
waitmovement 0x0
loadpointer 0x0 str_0x8a78f1
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7830
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
applymovement 0x1 ow_script_movs_0x8037d2
waitmovement 0x0
loadpointer 0x0 str_0x8a77ae
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a7789
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a776a
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
goto ow_script_0x8a934f


ow_script_movs_0x8a7761:
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_IN_PLACE_LEFT
.byte STEP_IN_PLACE_LEFT
.byte STOP


ow_script_movs_0x8a76e4:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x8a774a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x803489:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8aa36d:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP


ow_script_movs_0x8aa1b5:
.byte LOOK_LEFT
.byte STOP

mov_face_down:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a9a49:
.byte LOOK_RIGHT
.byte STOP


ow_script_0x8a934f:
fanfare 0x13e
loadpointer 0x0 str_0x8aa319
callstd MSG_KEEPOPEN
setflag POKEDEX
closeonkeypress
waitfanfare
applymovement 0x2 ow_script_movs_0x8a7761
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x8a76e4
waitmovement 0x0
loadpointer 0x0 str_0x8a7751
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8a774a
waitmovement 0x0
applymovement 0x3 ow_script_movs_0x803489
waitmovement 0x0
loadpointer 0x0 str_0x8a76ee
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aabee
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
nop
nop
loadpointer 0x0 str_0x8aa57d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
loadpointer 0x0 str_0x8aa381
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0 message_type=MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0 str_0x8aa381_2
callstd MSG
hide_mugshot
loadpointer 0x0 str_0x8aa372
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_RUMINATIVE hide_mugshot=0 message_type=MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_HAPPY
loadpointer 0 str_0x8aa372_2
callstd MSG
hide_mugshot
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
fanfare 0x13e
applymovement 0x2 ow_script_movs_0x8aa36d
loadpointer 0x0 str_0x8aa338
callstd MSG_KEEPOPEN
waitmovement 0x0
waitfanfare
loadpointer 0x0 str_0x8aa305
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0x0 str_0x8aa27f
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aa22a
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8aa1b8
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
applymovement 0x1 ow_script_movs_0x8aa1b5
waitmovement 0x0
loadpointer 0x0 str_0x8aa184
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
applymovement 0x1 mov_face_down
waitmovement 0x0
loadpointer 0x0 str_0x8a9f82
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
sound 23
checksound
loadpointer 0x0 str_0x8a9c83
callstd MSG
applymovement 0x2 ow_script_movs_0x8aa36d
call ow_script_0x8ab100
waitmovement 0x0
loadpointer 0x0 str_0x8a9a4c
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a99f1
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a9950
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_HAPPY
goto ow_script_0x8a9640


ow_script_movs_0x8ab040:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8aafce:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


ow_script_0x8aac32:
loadpointer 0x0 str_0x8ab043
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 0x2 ow_script_movs_0x8ab040
waitmovement 0x0
loadpointer 0x0 str_0x8aafd4
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT

applymovement 1 ow_script_movs_0x8aa1b5
waitmovement 0
loadpointer 0 str_tann_end
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY hide_mugshot=0 message_type=MSG_KEEPOPEN
applymovement 1 mov_face_down
waitmovement 0
loadpointer 0 str_tann_end_happy
update_mugshot_emotion MUGSHOT_HAPPY
callstd MSG
hide_mugshot

applymovement 2 ow_script_movs_0x8a9a49
waitmovement 0
loadpointer 0x0 str_elise_end
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
applymovement 1 ow_script_movs_0x8ab040
applymovement 2 ow_script_movs_0x8ab040
waitmovement 0
loadpointer 0 str_elise_end4
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL message_type=MSG
applymovement 0x2 ow_script_movs_0x8aafce
waitmovement 0x0
setflag ROUTE_2_RIVAL_INSIDE_LAB
setvar STORY_PROGRESS 0xf
setvar VAR_STORY_STATE STORY_STATE_ROUTE_2_TANN_DONE
sound 0x15
applymovement 1 mov_exclam
waitmovement 0
checksound
loadpointer 0 str_tann_transition
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL message_type=MSG
releaseall
end

ow_script_0x8a9640:
goto ow_script_0x8aac32


ow_script_0x8ab100:
fanfare 0x13e
additem ITEM_POKEBALL 0x5
loadpointer 0x0 str_0x8ad201
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
return


ow_script_movs_0x8037d2:
.byte FACE_DOWN
.byte STOP


.ifdef LANG_GER

str_0x8a7f97:
    .autostring 34 2 "PLAYER und RIVAL, mein eigener Sohn!\pGerade erst Trainer und schon helft ihr mir altem Herren aus der Klemme.\pDiese Leute von Team VioletDOTS"
str_0x8a7f97_2:	
    .autostring 34 2 "In den Nachrichten hört man in letzter Zeit öfter von ihnen.\pVielleicht werden sie hier in Theto noch zu einem echten Problem.\pAber das soll nicht eure Sorge sein.\pDie Top Vier werden die Lage schon in den Griff bekommen!\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_rival_1:
    .autostring 34 2 "Aber was wollten diese Leute denn von dir, Papa?"
str_prof_response:
    .autostring 34 2 "Na, das ist eine gute FrageDOTS\pSie wollten, dass ich ihnen verrate, wo man den Zeitstein finden kannDOTS"
str_rival_2:
    .autostring 34 2 "Huh?"
str_prof_response2:
    .autostring 34 2 "Na, das ist eine uralte Legende unter Archäologen, wenn man so will.\pFast so spannend wie die legendäre Stadt Atlantea, die vor Jahrhunderten versunken istDOTS\pAber ob dieser Zeitstein überhaupt existiertDOTS DOTS DOTS"
str_prof_response3:
    .autostring 34 2 "Na, sagen wir es so!\pEs gibt nicht viele ernsthafte Forscher, die daran glauben!"
str_prof_response4:
    .autostring 34 2 "Aber ich frage mich schon, wie diese Leute überhaupt dazu kommen, mich deswegen zu bedrängenDOTS\pGerade erst vor einigen Tagen hat sich mein Kollege, Professor Primus danach erkundigt.\pUnd jetzt tauchen diese Violet Leute aufDOTS"
str_elise_silcene:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
str_0x8a7f97_3:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pGenug davon!\nWo ihr nun schon einmal hier seid, will ich euch ganz herzlich zu eurem Abschluss gratulieren!\pIch weiß sehr wohl, dass der alte Faun nicht gerade nachsichtig istDOTS\pUnd zu diesem Anlass habe ich auch ein nettes Geschenk für euch!\pElise, würdest du bitteDOTS"
str_0x8a7f3d:
    .autostring 34 2 "Natürlich, Professor Tann.\pIch bin schon unterwegsDOTS"
str_0x8a7e8d:
	.autostring 34 2 "Darf ich vorstellen?\nDas ist Elise, ein wahres Naturtalent, wenn es um die Erforschung von Pokémon geht.\pSie arbeitet für die Laz. Corp an der Virtualisierung von Pokémon.\pDas PC-System wurde von ihr maßgeblich mitentwickelt."
str_0x8a7dbf:
	.autostring 34 2 "Freut mich außerordentlich!\pEndlich lerne ich dich einmal kennen, RIVAL!\pDein Vater hat schon so viel von dir erzählt!\pDu bist wohl ein richtiger Hitzkopf, nicht?\pGenauso wie Professor Tann, der auch nie zuhört und sein eigenes Ding macht."
str_0x8a7930:
    .autostring 34 2 "Stimmt etwas nicht?"
str_0x8a78f1:
    .autostring 34 2 "Das soll ich dir also so erzählt haben?"
str_0x8a7830:
	.autostring 34 2 "Naja, in etwa so oder so ähnlich, ebenDOTS"
str_0x8a77ae:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pNa!\nIst auch nicht so wichtig!\pDas, was ich euch beiden schenken will, ist ein Poképad.\pJeder Trainer, der etwas auf sich hält, sollte so eines besitzen!"
str_0x8a7789:
    .autostring 34 2 "Wirklich? Fantastisch, Papi!"
str_0x8a776a:
    .autostring 34 2 "Vielen Dank, Professor Tann."
str_0x8aa319:
    .autostring 34 2 "PLAYER hat das Poképad erhalten!"
str_0x8a7751:
    .autostring 34 2 "Danke, Elise!"
str_0x8a76ee:
    .autostring 34 2 "Das ganze ist allerdings mit einer Bitte verbunden."
str_0x8aabee:
    .autostring 34 2 "Och, du bist ein immer so ein Spielverderber, Papi!"
str_0x8aa57d:
    .autostring 34 2 "Du könntest ruhig etwas dankbarer seinDOTS"
str_0x8aa381:
	.autostring 34 2 "Das ist schon in Ordnung!\pIch weiß ja, wie mein Sohn so drauf ist!"
str_0x8aa381_2:
    .autostring 34 2 "Wenn es dich beruhigt, RIVALDOTS\pDiese Bitte ist viel mehr eine Aufgabe, die jeder Trainer zu bewältigen hat.\pWie ich schon erwähnt habe, forscht Elise an der Virtualisierung von Pokémon.\pDie Grundlage dafür ist eine Menge an Daten.\pUnd diese Daten müssen gesammelt werden.\pVon Pokémon-Trainern, versteht sich.\pUnd das Poképad bietet eine ideale Möglichkeit, diese Daten für Elise zu sammeln.\pDie Pokédex-App hält die interessanten Informationen über alle die Pokémon fest, die ihr im Laufe eures Abenteuers einfangt.\pIhr sollt also nicht mehr und weniger tun, als möglichst viele verschiedene Spezies einzufangen und deren Daten in der Poképad-App festzuhalten.\pGar nicht so tragisch, oder?"
str_0x8aa372:
    .autostring 34 2 "Was?\nDas ist alles?\pWir sollen Pokémon fangen?"
str_0x8aa372_2:
    .autostring 34 2 "Das geht in Ordnung, Papi!"
str_0x8aa338:
    .autostring 34 2 "Die Pokedex-App wurde auf dem Poképad installiert!"
str_0x8aa305:
    .autostring 34 2 "Dankesehr!"
str_0x8aa27f:
	.autostring 34 2 "Sehr schön!\pIch wusste, dass ich mich auf euch verlassen kann.\pIch nehme an, ihr beiden habt in der Trainerschule gelernt, wie man Pokémon fängt?"
str_0x8aa22a:
    .autostring 34 2 "Natürlich Papi!\pFaun hat uns alles beigebracht, was ein Trainer wissen muss!"
str_0x8aa1b8:
    .autostring 34 2 "Ich kann mir immer noch nicht wirklich vorstellen, dass jemand von einem solchen Kaliber wie Faun tatsächlich Kinder unterrichten sollDOTS"
str_0x8aa184:
    .autostring 34 2 "Gerade Trainer wie Faun sollten ihr Wissen an die nächste Generation weitergeben, meinst du nicht?"
str_0x8a9f82:
	.autostring 34 2 "Aber es ist gut zu hören, dass ihr wisst, wie man Pokémon einfängt.\pDann werdet ihr sicher wissen, was mit denen hier zu tun ist, nicht?"
str_0x8a9c83:
    .autostring 34 2 "RIVAL hat 5 Pokebälle erhalten!"
str_0x8a9a4c:
    .autostring 34 2 "Schön!\nIch bin wirklich stolz auf dich, RIVAL!"
str_0x8a99f1:
    .autostring 34 2 "Und versuche bitte, möglichst viele verschiedene Pokémon einzufangen!"
str_0x8a9950:
    .autostring 34 2 "Aber sicher!\nImmerhin werde ich eines Tages der größte Trainer dieser Region sein.\pDa kann man nicht nur mit zwei Pokémon durch die Weltgeschichte laufen!"
str_0x8ad201:
    .autostring 34 2 "PLAYER hat fünf\nPokébälle erhalten!"
str_0x8ab043:
    .autostring 34 2 "Und dir wünsche ich auch alles Gute, PLAYER!"
str_0x8aafd4:
	.autostring 34 2 "Und werdet bitte nicht übermütig.\pDa draußen gibt es viele gefährliche Trainer.\pUnd es ist keine Schande, einem Kampf auch einmal aus dem Weg zu gehen."
str_tann_end:
    .autostring 34 2 "Unsinn, Elise!\pWas erzählst du denn da?\pNur, wenn man große Ziele verfolgtDOTS\pZiele, die manche als verrückt bezeichnen würdenDOTS\pNur dann kann man wirklich etwas bewegen!"
str_tann_end_happy:
    .autostring 34 2 "Lasst euch auf keinen Fall von Leuten entmutigen, die euch vormachen wollen, was möglich ist und was nicht!\pHabt keine Angst, an euren Träumen feszuhalten!"
str_elise_end:
    .autostring 34 2 "Was soll man sagen, der Apfel fällt nicht weit vom StammDOTS"
str_elise_end4:
    .autostring 34 2 "Entschuldigt bitte, PLAYER und RIVAL.\pIch wollte euch nicht entmutigen.\pGebt einfach euer Bestes, ja?\pUnd wenn ihr mir ein paar interessante Pokémon-Daten beschaffen könntet, wäre ich euch sehr dankbar.\pVielen Dank euch beiden!"
str_tann_transition:
    .autostring 34 2 "Also gut, PLAYER!\pIch mache mich wieder an die Arbeit.\pHalte die Ohren steif, ja?"
.elseif LANG_EN

str_0x8a7f97:
    .autostring 34 2 "PLAYER and RIVAL, my very own son!\pYou two just became trainers and yet you are already helping me out of a pinch.\pThese people of Team VioletDOTS"
str_0x8a7f97_2:	
    .autostring 34 2 "You hear a lot about them in the news lately.\pMaybe they do become a problem here in Theto after all.\pBut that shouldn't worry you at all.\pThe Elite Four will get situation dealt with, I am sure!\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_rival_1:
    .autostring 34 2 "But what did these guys want from you, dad?"
str_prof_response:
    .autostring 34 2 "Well, that's a good question.\pThey wanted me to tell them where to find the Time StoneDOTS"
str_rival_2:
    .autostring 34 2 "Huh?"
str_prof_response2:
    .autostring 34 2 "Well, that's a very old legend archeologists tell, if you want.\pAlong the lines of the mythical city of Atlantea that sank centuries agoDOTS\pBut whether that Time Stone even existsDOTS DOTS DOTS"
str_prof_response3:
    .autostring 34 2 "Let's just say that not many archeologist actually believe in its existence!"
str_prof_response4:
    .autostring 34 2 "But I have to wonder why these people came after me in the first placeDOTS"
str_elise_silcene:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
str_0x8a7f97_3:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pEnough of that!\pNow that you are here I want to congratulate you to your degree!\pI am well aware that Faun isn't exactly a lenient kind of personDOTS\pAnd because of that I want to make you two a present!\pElise, would be so kindDOTS"
str_0x8a7f3d:
    .autostring 34 2 "Of course, Professor Fig.\pOn may wayDOTS"
str_0x8a7e8d:
    .autostring 34 2 "May I introduce to you?\pThat's Elise, a real prodigy when it comes to researching Pokémon.\pShe works for the Laz. Corp and develops the virualization of Pokémon.\pThe PC-System was partly developed by her."
str_0x8a7dbf:
    .autostring 34 2 "I am pleased to meet you!\pFinally I get to meet you in person, RIVAL!\pYour father talks about you all the time!\pYou really are a hothead, right?\pJust like Professor Fig, who also won't ever listen and just does his own thing."
str_0x8a7930:
    .autostring 34 2 "Is something wrong?"
str_0x8a78f1:
    .autostring 34 2 "And that's what I am supposed to have told you?"
str_0x8a7830:
	.autostring 34 2 "Well, something along those linesDOTS"
str_0x8a77ae:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pAnyways!\nIt doesn't matter.\pWhat I want to give to you two is a Poképad.\pEvery trainer with any repuation whatsoever should own one of these!"
str_0x8a7789:
    .autostring 34 2 "Really?\nThat's amazing, dad!"
str_0x8a776a:
    .autostring 34 2 "Thank you very much, Professor Fig!"
str_0x8aa319:
    .autostring 34 2 "PLAYER received the Poképad!"
str_0x8a7751:
    .autostring 34 2 "Thanks, Elise!"
str_0x8a76ee:
    .autostring 34 2 "The present comes with a request however!"
str_0x8aabee:
    .autostring 34 2 "Man, you really are a spoilsport, dad!"
str_0x8aa57d:
    .autostring 34 2 "You really should appreciate that your father makes you a presentDOTS"
str_0x8aa381:
	.autostring 34 2 "Haha!\nIt's fine, don't worry.\pI have known my son for quite a while now!"
str_0x8aa381_2:
    .autostring 34 2 "If it calms you down, RIVALDOTS\pThis request much more is a task that a trainer has to deal with anyway.\pAs I said, Elise is researching the virtualization of Pokémon.\pAnd the foundation of her research is a lot of data.\pData, which has to be collected.\pBy Pokémon-Trainers, that is!\pAnd the Poképad gives you the ability to get that data for Elise.\pThe Pokédex-App records all the interesting information about the Pokémon you catch throughout your adventure.\pBasically, you just have to catch many different species to record their data.\pAnd that's all!\nDoesn't sound half bad, right?"
str_0x8aa372:
    .autostring 34 2 "Really?\pThat's all?\nJust catching Pokémon?"
str_0x8aa372_2:
    .autostring 34 2 "That totally will be ok, dad!"
str_0x8aa338:
    .autostring 34 2 "Die Pokedex-App was installed on your Poképad!"
str_0x8aa305:
    .autostring 34 2 "Thank you!"
str_0x8aa27f:
    .autostring 34 2 "Very nice!\pI knew I could rely on you two!\pI suppose you have learned how to catch Pokémon in school, right?"
str_0x8aa22a:
    .autostring 34 2 "Of course, dad!\pFaun taught us everything a trainer needs to know!"
str_0x8aa1b8:
    .autostring 34 2 "I really can't get my head arround the thought that someone like Faun really is teaching children nowadaysDOTS"
str_0x8aa184:
    .autostring 34 2 "Isn't it trainers like him who should pass their knowledge down to the next generation the most?"
str_0x8a9f82:
    .autostring 34 2 "But it's good to hear that you know how to catch Pokémon.\pThen you will surely know what to do with those, eh?"
str_0x8a9c83:
    .autostring 34 2 "RIVAL received 5 Pokéballs"
str_0x8a9a4c:
    .autostring 34 2 "Nice!\pI am really proud of you, RIVAL!"
str_0x8a99f1:
    .autostring 34 2 "And please try to catch as many different Pokémon as possible!"
str_0x8a9950:
    .autostring 34 2 "I sure will!\pSince I will become the greatest trainer in this region I can't just wander arround with only two Pokémon!"
str_0x8ad201:
    .autostring 34 2 "PLAYER received\nfive Pokéballs!"
str_0x8ab043:
    .autostring 34 2 "I also wish you the very best, PLAYER!"
str_0x8aafd4:
    .autostring 34 2 "And please don't get all too overconfident.\pThere is a lot of dangerous trainers out there.\pAnd it's no shame to avoid battle sometimes."
str_tann_end:
    .autostring 34 2 "Nonesense, Elise!\pWhat are you talking about?\pOnly if you pursue ambitious goalsDOTS\pGoals some would even call crazyDOTS\pOnly then you will actually get somewhere!"
str_tann_end_happy:
    .autostring 34 2 "Don't let yourselves be discouraged by people that claim to know what's possible and what's not!\pDon't be afraid to chase after your dreams!"
str_elise_end:
    .autostring 34 2 "What can I say, the apply doesn't fall far from the trunkDOTS"
str_elise_end4:
    .autostring 34 2 "I am sorry, PLAYER and RIVAL.\pI didn't mean to discourage you.\pJust do your best, ok?\pAnd if you can get me some interesting Pokémon-data, I would be very grateful!\pGood luck to the both of you!"
str_tann_transition:
    .autostring 34 2 "PLAYER!\pI almost didn't notice!"
.endif