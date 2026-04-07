.include "specials.s"

.macro npc_face_npc person_idx:req npc_target:req
    setvar 0x8004 \person_idx
    setvar 0x8005 \npc_target
    special SPECIAL_NPC_FACE_TO_NPC
    waitmovement 0
.endm
