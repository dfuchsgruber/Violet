.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "callstds.s"
.include "movements.s"
.include "species.s"
.include "specials.s"
.include "battle_results.s"
.include "items.s"
.include "songs.s"

.global ow_script_ardeal_dungeon_spiritomb

ow_script_ardeal_dungeon_spiritomb:
    checkflag FLAG_ARDEAL_SPIRITOMB
    gotoif EQUAL done
    loadpointer 0 str_0
    callstd MSG_SIGN
    checkitem ITEM_SPIRITKERN 1
    compare LASTRESULT 1
    gotoif NOT_EQUAL end_script
    // Make Spiritomb appear
    sound 0x15
    applymovement 0xFF mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_1
    callstd MSG_YES_NO
    compare LASTRESULT 0
    closeonkeypress
    gotoif EQUAL end_script
    checksound
    sound 23
    pause 64
    setvar 0x8004 1 // Darken screen cutscene
    fadesong 0
    special SPECIAL_CUTSCENE_SHOW
    waitstate
    loadpointer 0 str_2
    callstd MSG_KEEPOPEN
    special 0x188
	compare LASTRESULT 2
	gotoif EQUAL end_script
	lock
	setwildbattle POKEMON_KRYPPUK 45 0
	checksound
	cry POKEMON_KRYPPUK 2
	setvar BATTLE_SONG_OVERRIDE MUS_DARK_QUEEN_BATTLE2
	closeonkeypress
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
    special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_WON
	gotoif EQUAL event_done
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL end_script
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL end_script
event_done:
    setflag FLAG_ARDEAL_SPIRITOMB
    removeitem ITEM_SPIRITKERN 1
end_script:
    end

end_yes_no:
    closeonkeypress
    end

done:
    loadpointer 0 str_done
    callstd MSG_SIGN
    end

mov_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER
str_done:
    .autostring 34 2 "In diesem Steinhaufen wohnten einst viele böse Geister, doch nun sind sie fortDOTS"
str_0:
    .autostring 34 2 "Von diesem Steinhaufen scheint eine bösartige Energie auszugehen."
str_1:
    .autostring 34 2 "Der Spiritkern in deinem Beutel scheint auf die Präsenz zu reagieren.\pMöchest du ihn in den Steinhaufen einsetzten?"
str_2:
    .autostring 34 2 "Hunderte von Jahren war ich gefangenDOTS\pMeine wurde Herrin gestürztDOTS\pMeine wurde Existenz verbanntDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNun bin ich endlich frei!"

.elseif LANG_EN
str_done:
    .autostring 34 2 "In this pile of stones once many evil spirits lived, all of which are gone nowDOTS"
str_0:
    .autostring 34 2 "It feels like an evil energy is emitted by this pile of stones."
str_1:
    .autostring 34 2 "The odd keystone in your bag seems to react to the presence.\pDo you want to insert it into the pile of stones?"
str_2:
    .autostring 34 2 "Hundreds of years I have been imprisonedDOTS\pMy mistress was overthrown\pMy very existence was sealed awayDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pNow I am finally free!"
.endif