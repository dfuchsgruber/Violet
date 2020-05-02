.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "vars.s"
.include "levelscript_types.s"
.include "specials.s"
.include "battle/battle_handicaps.s"

.global levelscripts_ceometria_gym_arena

levelscripts_ceometria_gym_arena:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_battle
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
.word lscr_facing
	.byte 0x0

lscr_battle:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_ceometria_gym_battle
	.hword 0x0

lscr_facing:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x801080
	.hword 0x0


.global ow_script_ceometria_gym_battle
ow_script_ceometria_gym_battle:
lockall
pause 0x10
special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
applymovement 0x7f mov_camera
waitmovement 0x0
pause 0x10
applymovement 0x1 mov_referee_down
waitmovement 0x0
loadpointer 0x0 str_referee
callstd MSG
applymovement 0x2 mov_teah
applymovement 0xff mov_player
waitmovement 0x0
special SPECIAL_OVERWORLD_VIEWPORT_LOCK
draw_mugshot MUGSHOT_TEAH MUGSHOT_LEFT
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_TERRIFYING_ATMOSPHERE
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattlecont 0x1 0x13E 0x0 str_challange str_defeat ow_script_after_battle
ow_script_after_battle:

setvar 0x8004 4
setvar 0x8005 2
special SPECIAL_BUFFER_BADGE_NAME
loadpointer 0 str_after_battle
show_mugshot MUGSHOT_TEAH MUGSHOT_LEFT
loadpointer 0x0 str_receive_badge
fanfare 0x104
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag FRBADGE_5
loadpointer 0 str_tm
show_mugshot MUGSHOT_TEAH MUGSHOT_LEFT
copyvarifnotzero 0x8000 ITEM_TM30
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0 str_leave
show_mugshot MUGSHOT_TEAH MUGSHOT_LEFT
warpmuted 3 13 4 0 0
waitstate
releaseall
end

mov_camera:
    .byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

mov_referee_down:
    .byte STEP_DOWN, STOP

mov_teah:
    .byte STEP_RIGHT, STOP

mov_player:
    .byte STEP_LEFT, STOP

.ifdef LANG_GER
str_referee:
    .autostring 34 2 "Es tritt nun PLAYER gegen Teah, die Arenaleiterin von Ceometria an.\pWird der Herausforder gegen Teah, die in Zukunft sieht, bestehen können?"
str_challange:
    .autostring 34 2 "Seit einer Ewigkeit habe ich nicht mehr gegen jemanden gekämpft, der mir so ein Rätsel war.\pIch kann mich kaum zurückhalten!\pZeig mir, ob du deinem Ruf gerecht wirst, PLAYER!"
str_defeat:
    .autostring 34 2 "Beeindruckend!\pIch begreife langsam, wieso du dich selbst dem Schicksal widersetzten kannst."
str_after_battle:
    .autostring 34 2 "Es überrascht mich jetzt nicht mehr so sehr, dass ich deine Zukunft nicht vorhersehen kann.\pDeine Unbeugsamkeit ist überwältigend.\pSo einen spannenden Kampf hatte ich schon lange nicht mehr.\pDen BUFFER_3 hast du dir redlich verdient."
str_tm:
    .autostring 34 2 "Damit kannst du die Vm Stärke außerhalb des Kampfes benutzen.\pPokémon werden dir nun bis Level 70 gehorchen.\pAußerdem will ich mich persönlich dir gegenüber noch erkenntlich zeigen."
str_leave:
    .autostring 34 2 "Diese Tm enthält Spukball.\pDieser mächtige Angriff kann die Spezial Verteidigung des Gegners verringern, was bei einem weiteren Treffer umso mehr Schaden verursacht.\pFür Geist-Pokémon gibt es keinen nützlicheren Angriff.\pDu wirst jede Hilfe brauchen, wenn du bis ganz nach oben kommen willst.\pEs gibt noch viel, dass du nicht weißt.\pAber ich bin zuversichtlich, dass du die Herausforderungen, die vor dir liegen, bewältigen kannst.\pUnd hab ein Auge auf diese insesible Frau von Team Violet, die meinen wunderbaren Friedhof entweihen wollte.\pSolchen Leuten sollte man nicht zu viel Nachsicht zuteil werden lassen."
str_receive_badge:
    .autostring 34 2 "PLAYER hat den Ruheorden erhalten."

.elseif LANG_EN
str_referee:
    .autostring 34 2 "PLAYER will now challange Teah, the gym leader of Ceometria.\pWill the challanger be able to withstand Teah, who has the ability to see into the future?"
str_challange:
    .autostring 34 2 "For an enternity I haven't battled someone which has been this much of an enigma to me.\pI am already so excited!\pShow me if you can live up to your reputation, PLAYER!"
str_defeat:
    .autostring 34 2 "Impressive!\pSlowly I begin to realize why you can withstand destiny."
str_after_battle:
    .autostring 34 2 "Somehow it doesn't suprise me anymore that I couldn't forsee your future.\pYour stubborness is overwhelming.\pI haven't done such an intense battle in a long time.\pYou definitely earned yourself the BUFFER_3."
str_tm:
    .autostring 34 2 "With this you can use the Hm Strength outside a battle.\pPokémon up until level 70 will be obedient to you now.\pIn addition to that I want to give you something as a personal gift."
str_leave:
    .autostring 34 2 "This Tm contains Shadow Ball.\pIt can lower the special defense of your foes which makes your successive hits even more devastating.\pThere is no attack more useful to ghost Pokémon.\pYou will need every help you can get if you want to climb the ladder.\pThere is yet a lot to learn.\pBut I am positive that you will be able to deal with the challanges that await you.\pAnd please, keep an eye on this indecent woman of Team Violet, which wanted to desecrate my precious graveyard.\pYou can't cut people like this to slack."
str_receive_badge:
    .autostring 34 2 "PLAYER received the Piece Badge."

.endif