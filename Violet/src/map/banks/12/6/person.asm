.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "specials.s"
.include "pokemon_types.s"
.include "items.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_laubdorf_inside_3_person_0

ow_script_laubdorf_inside_3_person_0:
    checkflag FLAG_LAUBDORF_STAERKE
    gotoif EQUAL done
    lock
    faceplayer
    loadpointer 0 str_0
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_VM01
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    setflag FLAG_LAUBDORF_STAERKE
done:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

/* 
    checkflag FLAG_LAUBDORF_STAERKE
    gotoif EQUAL done
    lockall
    faceplayer
    loadpointer 0 str_0
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif 1 select
dont_show:
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    release
    end

select:
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_PARTY_POKEMON
    waitstate
    lockall
    faceplayer
    compare 0x8004 6
    gotoif HIGHER_OR_EQUAL dont_show
    setvar 0x8005 TYPE_KAMPF
    special2 LASTRESULT SPECIAL_PARTY_POKEMON_HAS_TYPE
    compare LASTRESULT 1
    gotoif EQUAL obtain_strength
    loadpointer 0 str_wrong_type
    callstd MSG_KEEPOPEN
    release
    end

obtain_strength:
    loadpointer 0 str_obtain_strength
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_VM04
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    setflag FLAG_LAUBDORF_STAERKE
    loadpointer 0 str_obtained
    callstd MSG_KEEPOPEN
done:
    loadpointer 0 str_done
    callstd MSG_FACE
    end
*/
.ifdef LANG_GER
str_0:
    .autostring 34 2 "In Fachkreisen nennt man mich den Zerschneider.\pEs gibt nichts auf dieser schönen weiten Welt, das ich nicht im Handumdrehen zerschneiden könnte.\pDu glaubst mir nicht?\pProbier es doch einfach selbst aus!"

str_1:
    .autostring 34 2 "Mit dieser VM kannst auch du alles zerschneiden, was sich dir in den Weg stellt!"

.elseif LANG_EN
.endif