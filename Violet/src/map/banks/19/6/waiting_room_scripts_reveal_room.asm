.include "overworld_script.s"
.include "specials.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_ceometria_gym_reveal_room_nothing
.global ow_script_ceometria_gym_reveal_room_trainer
.global ow_script_ceometria_gym_reveal_room_poison
.global ow_script_ceometria_gym_reveal_room_sleep
.global ow_script_ceometria_gym_reveal_room_paralysis
.global ow_script_ceometria_gym_reveal_room_burn
.global ow_script_ceometria_gym_reveal_room_frozen
.global ow_script_ceometria_gym_reveal_room_healing
.global ow_script_ceometria_gym_reveal_room_reduce_any

ow_script_ceometria_gym_reveal_room_nothing:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_nothing
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_trainer:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_trainer
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_poison:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_bad_poison
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_paralysis:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_paralysis
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_sleep:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_sleep
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_burn:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_burn
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_frozen:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_frozen
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_healing:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_healing
    callstd MSG_FACE
    end
ow_script_ceometria_gym_reveal_room_reduce_any:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_reduce_any
    callstd MSG_FACE
    end

.ifdef LANG_GER
reveal_nothing:
    .autostring 34 2 "Es ist der BUFFER_1DOTS\pIch spüre keinerlei Präsenz von Leben in diesem RaumDOTS"
reveal_trainer:
    .autostring 34 2 "Der BUFFER_1DOTS\nDOTSeine wahrhaft kämpferische Aura verbirgt sich dortDOTS"
reveal_bad_poison:
    .autostring 34 2 "Dieser?\nDer BUFFER_1?\pEr fühlt sich an wie das Gift einer SchlangeDOTS"
reveal_sleep:
    .autostring 34 2 "Dieser?\nDer BUFFER_1?\pAllein bei dem Gedanken an ihn, wird mir schläfrig zumuteDOTS"
reveal_paralysis:
    .autostring 34 2 "Dieser?\nDer BUFFER_1?\pMir zucken alle Glieder beim Gedanken daranDOTS"
reveal_burn:
    .autostring 34 2 "Dieser?\nDer BUFFER_1?\pEine beständige Hitze dringt darausDOTS"
reveal_frozen:
    .autostring 34 2 "Dieser?\nDer BUFFER_1?\pMir klappern die Zähne, wenn ich daran denkeDOTS"
reveal_healing:
    .autostring 34 2 "Der BUFFER_1 scheint eine überaus positive Aura zu beherbergenDOTS"
reveal_reduce_any:
    .autostring 34 2 "Der BUFFER_1DOTS\nEin Fluch scheint über dem Raum zu liegenDOTS"

.elseif LANG_EN
reveal_nothing:
    .autostring 34 2 "It's the BUFFER_1DOTS\pI can't feel any presence of life in this roomDOTS"
reveal_trainer:
    .autostring 34 2 "The BUFFER_1DOTS\nDOTSa truly fighting aura hides in thereDOTS"
reveal_bad_poison:
    .autostring 34 2 "This one?\nThe BUFFER_1?\pIt feels like the poison of a viperDOTS"
reveal_sleep:
    .autostring 34 2 "This one?\nThe BUFFER_1?\pThe thought alone makes me so sleepyDOTS"
reveal_paralysis:
    .autostring 34 2 "This one?\nThe BUFFER_1?\pA shock gets hold of me just thinking about itDOTS"
reveal_burn:
    .autostring 34 2 "This one?\nThe BUFFER_1?\pA constant heat is coming out of itDOTS"
reveal_frozen:
    .autostring 34 2 "This one?\nThe BUFFER_1?\pA shiver goes through my limbs when thinking about itDOTS"
reveal_healing:
    .autostring 34 2 "The BUFFER_1 seems to harbour a distinctively positive auraDOTS"
reveal_reduce_any:
    .autostring 34 2 "The BUFFER_1DOTS\nA curse seems to lie upon this roomDOTS"

.endif


