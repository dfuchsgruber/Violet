.include "overworld_script.s"
.include "callstds.s"
.include "movements.s"
.include "vars.s"
.include "ordinals.s"
.include "pokemon_statuses.s"
.include "specials.s"

.global ow_script_ceometria_gym_punishment_nothing
.global ow_script_ceometria_gym_punishment_healing
.global ow_script_ceometria_gym_punishment_bad_poison
.global ow_script_ceometria_gym_punishment_poison
.global ow_script_ceometria_gym_punishment_burn
.global ow_script_ceometria_gym_punishment_sleep
.global ow_script_ceometria_gym_punishment_freeze
.global ow_script_ceometria_gym_punishment_paralysis
.global ow_script_ceometria_gym_punishment_trainer
.global ow_script_ceometria_gym_punishment_reduce_hp
.global ow_script_ceometria_gym_punishment_reduce_pp
.global ow_script_ceometria_gym_punishment_room_npc_move_away


ow_script_ceometria_gym_punishment_trainer:
    trainerbattlecont 0 0xFB 0 str_before_0 str_after_0 ow_script_ceometria_gym_punishment_room_npc_move_away
    end

ow_script_ceometria_gym_punishment_healing:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL cant_heal
    loadpointer 0 str_healing
    callstd MSG
    fadescreen 0x1
    fanfare 0x100
    waitfanfare
    callasm ceometria_gym_punishment_apply
    fadescreen 0x0
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

cant_heal:
    loadpointer 0 str_cant_heal
    callstd MSG
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

ow_script_ceometria_gym_punishment_bad_poison:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_bad_poison
    callstd MSG
    sound 0x8D
    checksound
    sound 0x8D
    checksound
    sound 0x8D
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

ow_script_ceometria_gym_punishment_poison:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_poison
    callstd MSG
    sound 0x8D
    checksound
    sound 0x8D
    checksound
    sound 0x8D
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

ow_script_ceometria_gym_punishment_burn:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_burn
    callstd MSG
    sound 0x8f
    checksound
    sound 0x8f
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

ow_script_ceometria_gym_punishment_sleep:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_sleep
    callstd MSG
    sound 0xa5
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away 

ow_script_ceometria_gym_punishment_freeze:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_freeze
    callstd MSG
    sound 0xaf
    checksound
    sound 0xb0
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away 

ow_script_ceometria_gym_punishment_paralysis:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_paralysis
    callstd MSG
    sound 0x70
    checksound
    sound 0x70
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away 

ow_script_ceometria_gym_punishment_reduce_hp:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_reduce_hp
    callstd MSG
    sound 0x72
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

ow_script_ceometria_gym_punishment_reduce_pp:
    special2 0x8004 SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_ELIGIBLE_INDEX
    compare 0x8004 0xFFFF
    gotoif EQUAL spare
    callasm ceometria_gym_punishment_apply
    loadpointer 0 str_reduce_pp
    callstd MSG
    sound 0x72
    checksound
    goto ow_script_ceometria_gym_punishment_room_npc_move_away

spare:
    loadpointer 0 str_spare
    callstd MSG
ow_script_ceometria_gym_punishment_room_npc_move_away:
    applymovement 1 mov_away
    waitmovement 0
    hidesprite 1
ow_script_ceometria_gym_punishment_nothing:
    callasm ceometria_gym_update_scores
    setvar CEOMETRIA_GYM_PUNISHMENT_ROOM_TRIGGER 1
    releaseall
    end


mov_away:
    .byte STEP_LEFT, STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

.ifdef LANG_GER
str_cant_heal:
    .autostring 34 2 "Wie mir scheint, bist du ein vom Glück gesegneter junger Trainer.\pAuf deinem Weg kann dir nichts widerfahren!"
str_healing:
    .autostring 34 2 "Du bist vom Glück gesegnet, junger Trainer!\pIch werde eines deiner Pokémon wieder auf Vordermann bringen."
str_spare:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pMan hat mich geschickt, dir zu schaden, aber dein Team ist bereits so mitgenommenDOTS\pIch werde dich verschonenDOTS\pDanke dem Schicksal für mein MitleidDOTS"
str_poison:
    .autostring 34 2 "Ich liebe alles was giftig ist!\pUnd auch deine Pokémon werden davon eine Kostprobe erhalten!"
str_bad_poison:
    .autostring 34 2 "Ach, du unglückliches Kind!\nIch bin der GiftmischerDOTS\pUnd eines deiner Pokémon erliegt nun meinem bösartigen TrankDOTS"
str_burn:
    .autostring 34 2 "Hehe!\nIch bin der Zündler!\pUnd ich werde eines deiner Pokémon in Brand stetzen!"
str_sleep:
    .autostring 34 2 "Ich bin ein Hypnotiseur!\pIm Handumdrehen werde ich eines deiner Pokémon schläfrig machenDOTS"
str_freeze:
    .autostring 34 2 "Mir DOTS ist DOTS so DOTS kalt DOTS\pUnd DOTS auch DOTS dein DOTS Pokémon DOTS friert DOTS nun DOTS"
str_paralysis:
    .autostring 34 2 "Kannst du die Statik in der Luft spüren?\pSie hat nun von einem deiner Pokémon Besitz ergriffen!"
str_reduce_hp:
    .autostring 34 2 "Der Fluch, den ich über deine Pokémon spreche, wird sie aller Lebenskraft berauben!"
str_reduce_pp:
    .autostring 34 2 "Ich kenne allerlei üble Flüche, und dieser hier wird deinen Pokémon die Kraft nehmen, anzugreifen!"
str_before_0:
    .autostring 34 2 "Ich bin der Arena-Aufseher.\pMich zu anzutreffen, war dein Pech, jetzt musst du gegen mich kämpfen."
str_after_0:
    .autostring 34 2 "Wohlan.\nDu darfst voranschreiten."

.elseif LANG_EN

str_cant_heal:
    .autostring 34 2 "You are blessed by luck as it seems, young trainer.\pOn your way nothing can ever happen to you."
str_healing:
    .autostring 34 2 "You are blessed, young trainer!\pI will heal one of your pokémon very quickly."
str_spare:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pI was sent to harm you, but your team is already that damagedDOTS\pI will spare youDOTS\pYou should thank destiny itself for my pityDOTS"
str_poison:
    .autostring 34 2 "I love all that is venomous.\pAnd your pokémon will suffer from that as well!"
str_bad_poison:
    .autostring 34 2 "Oh, you unlucky child!\nI am the poison mixerDOTS\pAnd one of your pokémon will suffer my malevolent elixirDOTS"
str_burn:
    .autostring 34 2 "Hehe!\nI am the arsonist!\pAnd I will set one of your pokémon on fire!"
str_sleep:
    .autostring 34 2 "I am a hypnotist!\pOne of your pokémon will be asleep faster than you can yawnDOTS"
str_freeze:
    .autostring 34 2 "I DOTS am DOTS so DOTS cold DOTS\pAnd DOTS also DOTS one DOTS of DOTS your DOTS pokémon DOTS is DOTS freezing DOTS now DOTS"
str_paralysis:
    .autostring 34 2 "Can you feel the electricity in the air?\pIt got hold of one of your pokémon now!"
str_reduce_hp:
    .autostring 34 2 "The curse I will do over your pokémon will empty their vessels and they will be robbed of life power!"
str_reduce_pp:
    .autostring 34 2 "I know all kinds of spells, and this one will take away your pokémon's ability to attack!"
str_before_0:
    .autostring 34 2 "I am the gym supervisor.\pTo meet me here was not lucky of you, for now you have to fight me."
str_after_0:
    .autostring 34 2 "Very well.\nYou may proceed."

.endif