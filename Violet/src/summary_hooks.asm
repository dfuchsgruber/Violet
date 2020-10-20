.global summary_selected_party_idx_apply_delta_consider_tag_battles_hook

.align 2
.thumb 

.thumb_func
summary_selected_party_idx_apply_delta_consider_tag_battles_hook:
    lsl r0, r5, #0x18
    asr r0, #0x18
    bl summary_selected_party_idx_apply_delta_consider_tag_battles
    ldr r1, =0x0813b268 | 1
    bx r1
