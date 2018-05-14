#include "types.h"
#include "overworld/npc.h"
#include "tile/block.h"
#include "tile/coordinate.h"

void npc_diag_update_pos(npc *n, oam_object *target, u8 direction) {
    n->dest_x = (s16) (n->from_x + walking_directions[direction].x);
    n->dest_y = (s16) (n->from_y + walking_directions[direction].y);
    target->private[3] = direction;
}

bool npc_anim_diag_ne_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, 0);
    npc_diag_update_pos(n, target, 8);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_nw_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, 0);
    npc_diag_update_pos(n, target, 7);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_se_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 4, 0);
    npc_diag_update_pos(n, target, 6);
    return npc_anim_walk_is_finished(n, target);
}

bool npc_anim_diag_sw_init(npc *n, oam_object *target) {
    npc_anim_init_walk(n, target, 3, 0);
    npc_diag_update_pos(n, target, 5);
    return npc_anim_walk_is_finished(n, target);
}

bool(*npc_anim_diag_no_frames[0x3])(npc *n, oam_object *target) = {
    npc_anim_diag_ne_init, npc_anim_walk_is_finished, npc_anim_stop
};

bool(*npc_anim_diag_so_frames[0x3])(npc *n, oam_object *target) = {
    npc_anim_diag_se_init, npc_anim_walk_is_finished, npc_anim_stop
};

bool(*npc_anim_diag_sw_frames[0x3])(npc *n, oam_object *target) = {
    npc_anim_diag_sw_init, npc_anim_walk_is_finished, npc_anim_stop
};

bool(*npc_anim_diag_nw_frames[0x3])(npc *n, oam_object *target) = {
    npc_anim_diag_nw_init, npc_anim_walk_is_finished, npc_anim_stop
};


bool(**npc_anims[0xAE])(npc *n, oam_object *target) = {
    (bool(**)(npc*, oam_object*)) 0x83A6728, (bool(**)(npc*, oam_object*)) 0x83A6730, (bool(**)(npc*, oam_object*)) 0x83A6738, (bool(**)(npc*, oam_object*)) 0x83A6740,
    (bool(**)(npc*, oam_object*)) 0x83A68F4, (bool(**)(npc*, oam_object*)) 0x83A68FC, (bool(**)(npc*, oam_object*)) 0x83A6904, (bool(**)(npc*, oam_object*)) 0x83A690C,
    (bool(**)(npc*, oam_object*)) 0x83A678C, (bool(**)(npc*, oam_object*)) 0x83A6798, (bool(**)(npc*, oam_object*)) 0x83A67A4, (bool(**)(npc*, oam_object*)) 0x83A67B0,
    (bool(**)(npc*, oam_object*)) 0x83A67C8, (bool(**)(npc*, oam_object*)) 0x83A67BC, (bool(**)(npc*, oam_object*)) 0x83A67D4, (bool(**)(npc*, oam_object*)) 0x83A67E0,
    (bool(**)(npc*, oam_object*)) 0x83A67EC, (bool(**)(npc*, oam_object*)) 0x83A67F8, (bool(**)(npc*, oam_object*)) 0x83A6804, (bool(**)(npc*, oam_object*)) 0x83A6810,
    (bool(**)(npc*, oam_object*)) 0x83A6828, (bool(**)(npc*, oam_object*)) 0x83A6834, (bool(**)(npc*, oam_object*)) 0x83A6840, (bool(**)(npc*, oam_object*)) 0x83A684C,
    (bool(**)(npc*, oam_object*)) 0x83A6858, (bool(**)(npc*, oam_object*)) 0x83A6864, (bool(**)(npc*, oam_object*)) 0x83A6870, (bool(**)(npc*, oam_object*)) 0x83A687C,
    (bool(**)(npc*, oam_object*)) 0x83A6888, (bool(**)(npc*, oam_object*)) 0x83A6894, (bool(**)(npc*, oam_object*)) 0x83A68A0, (bool(**)(npc*, oam_object*)) 0x83A68AC,
    (bool(**)(npc*, oam_object*)) 0x83A68B8, (bool(**)(npc*, oam_object*)) 0x83A6914, (bool(**)(npc*, oam_object*)) 0x83A6920, (bool(**)(npc*, oam_object*)) 0x83A692C,
    (bool(**)(npc*, oam_object*)) 0x83A6938, (bool(**)(npc*, oam_object*)) 0x83A6944, (bool(**)(npc*, oam_object*)) 0x83A6950, (bool(**)(npc*, oam_object*)) 0x83A695C,
    (bool(**)(npc*, oam_object*)) 0x83A6968, (bool(**)(npc*, oam_object*)) 0x83A6974, (bool(**)(npc*, oam_object*)) 0x83A6980, (bool(**)(npc*, oam_object*)) 0x83A698C,
    (bool(**)(npc*, oam_object*)) 0x83A6998, (bool(**)(npc*, oam_object*)) 0x83A69A4, (bool(**)(npc*, oam_object*)) 0x83A69B0, (bool(**)(npc*, oam_object*)) 0x83A69BC,
    (bool(**)(npc*, oam_object*)) 0x83A69C8, (bool(**)(npc*, oam_object*)) 0x83A69D4, (bool(**)(npc*, oam_object*)) 0x83A69E0, (bool(**)(npc*, oam_object*)) 0x83A69EC,
    (bool(**)(npc*, oam_object*)) 0x83A69F8, (bool(**)(npc*, oam_object*)) 0x83A6A04, (bool(**)(npc*, oam_object*)) 0x83A6A10, (bool(**)(npc*, oam_object*)) 0x83A6A1C,
    (bool(**)(npc*, oam_object*)) 0x83A6A28, (bool(**)(npc*, oam_object*)) 0x83A6A34, (bool(**)(npc*, oam_object*)) 0x83A6A40, (bool(**)(npc*, oam_object*)) 0x83A6A4C,
    (bool(**)(npc*, oam_object*)) 0x83A6A58, (bool(**)(npc*, oam_object*)) 0x83A6A64, (bool(**)(npc*, oam_object*)) 0x83A6A70, (bool(**)(npc*, oam_object*)) 0x83A6A7C,
    (bool(**)(npc*, oam_object*)) 0x83A6A88, (bool(**)(npc*, oam_object*)) 0x83A6A94, (bool(**)(npc*, oam_object*)) 0x83A6AA0, (bool(**)(npc*, oam_object*)) 0x83A6AAC,
    (bool(**)(npc*, oam_object*)) 0x83A6AB8, (bool(**)(npc*, oam_object*)) 0x83A6AC4, (bool(**)(npc*, oam_object*)) 0x83A6AD0, (bool(**)(npc*, oam_object*)) 0x83A6ADC,
    (bool(**)(npc*, oam_object*)) 0x83A6AE8, (bool(**)(npc*, oam_object*)) 0x83A6AF4, (bool(**)(npc*, oam_object*)) 0x83A6B30, (bool(**)(npc*, oam_object*)) 0x83A6B38,
    (bool(**)(npc*, oam_object*)) 0x83A6B40, (bool(**)(npc*, oam_object*)) 0x83A6B48, (bool(**)(npc*, oam_object*)) 0x83A6B50, (bool(**)(npc*, oam_object*)) 0x83A6B5C,
    (bool(**)(npc*, oam_object*)) 0x83A6B68, (bool(**)(npc*, oam_object*)) 0x83A6B74, (bool(**)(npc*, oam_object*)) 0x83A6B80, (bool(**)(npc*, oam_object*)) 0x83A6B8C,
    (bool(**)(npc*, oam_object*)) 0x83A6B98, (bool(**)(npc*, oam_object*)) 0x83A6BA4, (bool(**)(npc*, oam_object*)) 0x83A6BB0, (bool(**)(npc*, oam_object*)) 0x83A6BBC,
    (bool(**)(npc*, oam_object*)) 0x83A6BC8, (bool(**)(npc*, oam_object*)) 0x83A6BD4, (bool(**)(npc*, oam_object*)) 0x83A6BE0, (bool(**)(npc*, oam_object*)) 0x83A6BE8,
    (bool(**)(npc*, oam_object*)) 0x83A6BF4, (bool(**)(npc*, oam_object*)) 0x83A6BFC, (bool(**)(npc*, oam_object*)) 0x83A6C04, (bool(**)(npc*, oam_object*)) 0x83A6C0C,
    (bool(**)(npc*, oam_object*)) 0x83A6C14, (bool(**)(npc*, oam_object*)) 0x83A6C1C, (bool(**)(npc*, oam_object*)) 0x83A6C24, (bool(**)(npc*, oam_object*)) 0x83A6C2C,
    (bool(**)(npc*, oam_object*)) 0x83A6C34, (bool(**)(npc*, oam_object*)) 0x83A6C3C, (bool(**)(npc*, oam_object*)) 0x83A6C44, (bool(**)(npc*, oam_object*)) 0x83A6C4C,
    (bool(**)(npc*, oam_object*)) 0x83A6C58, (bool(**)(npc*, oam_object*)) 0x83A6C68, (bool(**)(npc*, oam_object*)) 0x83A6C78, (bool(**)(npc*, oam_object*)) 0x83A6C80,
    (bool(**)(npc*, oam_object*)) 0x83A6C88, (bool(**)(npc*, oam_object*)) 0x83A6C90, (bool(**)(npc*, oam_object*)) 0x83A6C98, (bool(**)(npc*, oam_object*)) 0x83A6CA4,
    (bool(**)(npc*, oam_object*)) 0x83A6CB0, (bool(**)(npc*, oam_object*)) 0x83A6CB8, (bool(**)(npc*, oam_object*)) 0x83A6CC0, (bool(**)(npc*, oam_object*)) 0x83A6CC8,
    (bool(**)(npc*, oam_object*)) 0x83A6CD0, (bool(**)(npc*, oam_object*)) 0x83A6CDC, (bool(**)(npc*, oam_object*)) 0x83A6CE8, (bool(**)(npc*, oam_object*)) 0x83A6CF4,
    (bool(**)(npc*, oam_object*)) 0x83A6D00, (bool(**)(npc*, oam_object*)) 0x83A6D0C, (bool(**)(npc*, oam_object*)) 0x83A6D18, (bool(**)(npc*, oam_object*)) 0x83A6D24,
    (bool(**)(npc*, oam_object*)) 0x83A6D60, (bool(**)(npc*, oam_object*)) 0x83A6D6C, (bool(**)(npc*, oam_object*)) 0x83A6D78, (bool(**)(npc*, oam_object*)) 0x83A6D84,
    (bool(**)(npc*, oam_object*)) 0x83A6D90, (bool(**)(npc*, oam_object*)) 0x83A6D9C, (bool(**)(npc*, oam_object*)) 0x83A6DA8, (bool(**)(npc*, oam_object*)) 0x83A6DB4,
    (bool(**)(npc*, oam_object*)) 0x83A6DC0, (bool(**)(npc*, oam_object*)) 0x83A6DCC, (bool(**)(npc*, oam_object*)) 0x83A6DD8, (bool(**)(npc*, oam_object*)) 0x83A6DE4,
    (bool(**)(npc*, oam_object*)) 0x83A6DF0, (bool(**)(npc*, oam_object*)) 0x83A6DFC, (bool(**)(npc*, oam_object*)) 0x83A6E08, (bool(**)(npc*, oam_object*)) 0x83A6E14,
    (bool(**)(npc*, oam_object*)) 0x83A6E20, (bool(**)(npc*, oam_object*)) 0x83A6E2C, (bool(**)(npc*, oam_object*)) 0x83A6E38, (bool(**)(npc*, oam_object*)) 0x83A6E44,
    (bool(**)(npc*, oam_object*)) 0x83A6E50, (bool(**)(npc*, oam_object*)) 0x83A6E5C, (bool(**)(npc*, oam_object*)) 0x83A6E68, (bool(**)(npc*, oam_object*)) 0x83A6E74,
    (bool(**)(npc*, oam_object*)) 0x83A6E80, (bool(**)(npc*, oam_object*)) 0x83A6E8C, (bool(**)(npc*, oam_object*)) 0x83A6E98, (bool(**)(npc*, oam_object*)) 0x83A6EA4,
    (bool(**)(npc*, oam_object*)) 0x83A6EB0, (bool(**)(npc*, oam_object*)) 0x83A6EB8, (bool(**)(npc*, oam_object*)) 0x83A6EC0, (bool(**)(npc*, oam_object*)) 0x83A675C,
    (bool(**)(npc*, oam_object*)) 0x83A6768, (bool(**)(npc*, oam_object*)) 0x83A6774, (bool(**)(npc*, oam_object*)) 0x83A6780, (bool(**)(npc*, oam_object*)) 0x83A6EC8,
    (bool(**)(npc*, oam_object*)) 0x83A68C4, (bool(**)(npc*, oam_object*)) 0x83A68D0, (bool(**)(npc*, oam_object*)) 0x83A68DC, (bool(**)(npc*, oam_object*)) 0x83A68E8,
    (bool(**)(npc*, oam_object*)) 0x83A6ED0, (bool(**)(npc*, oam_object*)) 0x83A6EDC, (bool(**)(npc*, oam_object*)) 0x83A6B00, (bool(**)(npc*, oam_object*)) 0x83A6B0C,
    (bool(**)(npc*, oam_object*)) 0x83A6B18, (bool(**)(npc*, oam_object*)) 0x83A6B24, npc_anim_diag_no_frames, npc_anim_diag_so_frames, npc_anim_diag_sw_frames, npc_anim_diag_nw_frames
};
