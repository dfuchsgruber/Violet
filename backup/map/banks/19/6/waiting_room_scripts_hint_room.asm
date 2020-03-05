.include "overworld_script.s"
.include "specials.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_ceometria_gym_hint_room_not_negative_variant_0
.global ow_script_ceometria_gym_hint_room_not_negative_variant_1
.global ow_script_ceometria_gym_hint_room_not_negative_variant_2
.global ow_script_ceometria_gym_hint_room_not_negative_variant_3
.global ow_script_ceometria_gym_hint_room_negative_variant_0
.global ow_script_ceometria_gym_hint_room_negative_variant_1
.global ow_script_ceometria_gym_hint_room_negative_variant_2
.global ow_script_ceometria_gym_hint_room_negative_variant_3

ow_script_ceometria_gym_hint_room_not_negative_variant_0:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_not_negative_variant_0
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_not_negative_variant_1:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_not_negative_variant_1
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_not_negative_variant_2:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_not_negative_variant_2
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_not_negative_variant_3:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_not_negative_variant_3
    callstd MSG_FACE
    end

ow_script_ceometria_gym_hint_room_negative_variant_0:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_negative_variant_0
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_negative_variant_1:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_negative_variant_1
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_negative_variant_2:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_negative_variant_2
    callstd MSG_FACE
    end
ow_script_ceometria_gym_hint_room_negative_variant_3:
    special SPECIAL_CEOMETRIA_GYM_PERSON_BUFFER_TARGET_ROOM
    loadpointer 0 reveal_negative_variant_3
    callstd MSG_FACE
    end

.ifdef LANG_GER
reveal_not_negative_variant_0:
    .autostring 34 2 "Der BUFFER_1?\pOh, du kannst ganz unbesorgt sein, dort sollte dir nichts widerfahrenDOTS"
reveal_not_negative_variant_1:
    .autostring 34 2 "Ah ja, der BUFFER_1?\pIch hätte keine Angst, ihn zu betretenDOTS"
reveal_not_negative_variant_2:
    .autostring 34 2 "Oh, der BUFFER_1?\pWas soll dir da schon passieren?"
reveal_not_negative_variant_3:
    .autostring 34 2 "Hm, der BUFFER_1?\pIch denke, von ihm geht keinerlei Gefahr ausDOTS"
reveal_negative_variant_0:
    .autostring 34 2 "Der BUFFER_1?\pWenn ich du wäre, würde ich einen Bogen darum machenDOTS"
reveal_negative_variant_1:
    .autostring 34 2 "Was, der BUFFER_1?\pDort hineinzugehen, halte ich für eine dumme IdeeDOTS"
reveal_negative_variant_2:
    .autostring 34 2 "Wie, der BUFFER_1?\pIch habe da ein ganz schlechtes GefühlDOTS"
reveal_negative_variant_3:
    .autostring 34 2 "Oh, der BUFFER_1?\pNein, nein.\nDa würde ich nicht hineingehen."
.elseif LANG_EN
reveal_not_negative_variant_0:
    .autostring 34 2 "The BUFFER_1?\pOh, worried be not, little child, nothing bad should happen to you thereDOTS"
reveal_not_negative_variant_1:
    .autostring 34 2 "Ah yes, the BUFFER_1?\pI would not have any fear going in thereDOTS"
reveal_not_negative_variant_2:
    .autostring 34 2 "Oh, the BUFFER_2?\pWhat could possibly happen to you there?"
reveal_not_negative_variant_3:
    .autostring 34 2 "Hm, the BUFFER_1?\pI think there is nothing too dangerous thereDOTS"
reveal_negative_variant_0:
    .autostring 34 2 "The BUFFER_1?\pIf I was you I would avoid this roomDOTS"
reveal_negative_variant_1:
    .autostring 34 2 "What, the BUFFER_1?\pGoing there is a bad idea, I would sayDOTS"
reveal_negative_variant_2:
    .autostring 34 2 "Hu, the BUFFER_1?\pI have a bad feeling about itDOTS"
reveal_negative_variant_3:
    .autostring 34 2 "Oh, der BUFFER_1?\pNo, no.\nI wouldn't go thereDOTS"
.endif