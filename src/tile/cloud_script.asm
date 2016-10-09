.include "overworld_script.s"

.global script_use_cloud_ref
.global script_use_cloud_back_ref
.global script_cloud_facings
.global script_cloud_none_ref

.thumb
.align 2

script_cloud_none:
    loadpointer 0 str_cloud_none
    callstd 6
    end

script_use_cloud:
    loadpointer 0 str_use_cloud
    callstd 5
    compare 0x800D 1
    gotoif 0 script_use_cloud_no
    loadpointer 0 str_cloud_used
cloud_exec:
    special 0x2B
    callstd 6
    special 0x2C
    waitstate
    end

script_use_cloud_back:
    loadpointer 0 str_use_cloud_back
    callstd 5
    loadpointer 0 str_cloud_used_back
    compare 0x800D 1
    gotoif 1 cloud_exec
script_use_cloud_no:
    closeonkeypress
    end

script_cloud_force_down:
    special 0x2B
script_face_down:
    spriteface 0xFF 1
    end

script_cloud_force_up:
    special 0x2B
script_face_up:
    spriteface 0xFF 2
    end

script_cloud_force_left:
    special 0x2B
script_face_left:
    spriteface 0xFF 3
    end

script_cloud_force_right:
    special 0x2B
script_face_right:
    spriteface 0xFF 4
    end




.align 4
script_cloud_none_ref:
    .word script_cloud_none

.align 4
script_use_cloud_ref:
    .word script_use_cloud

.align 4
script_use_cloud_back_ref:
    .word script_use_cloud_back

.align 4
script_cloud_facings:
    .word script_face_down
    .word script_face_down
    .word script_face_up
    .word script_face_left
    .word script_face_right
    .word script_cloud_force_down
    .word script_cloud_force_up
    .word script_cloud_force_left
    .word script_cloud_force_right

