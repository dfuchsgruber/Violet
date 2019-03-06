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

.global str_cant_dismount_cloud

.ifdef LANG_GER

	str_cant_dismount_cloud:
		.autostring 35 2 "Du kannst hier nicht von der Wolke absteigen.PAUSE_UNTIL_PRESS"

	str_use_cloud:
		.string "Die Wolken scheinen hier tief zu\nschweben.\pMöchtest du auf deine Wolke\nsteigen?"

	str_cloud_used:
		.string "Die Wolke trägt dich empor!"

	str_use_cloud_back:
		.string "Die Wolken sind hier durchlässig.\nMöchtest du zum Boden zurückkehren?"

	str_cloud_used_back:
		.string "Die Wolke trägt dich hinab!"

	str_cloud_none:
		.string "Die Wolken scheinen hier tief zu\nschweben..."

.elseif LANG_EN

	str_cant_dismount_cloud:
		.autostring 35 2 "You can't dismount the cloud here.PAUSE_UNTIL_PRESS"

	str_use_cloud:
		.string "The clouds seem to be floating\nnear the ground.\npDo you want to ascend\nby using your cloud?"

	str_cloud_used:
		.string "The cloud carries you\nupwards!"

	str_use_cloud_back:
		.string "The clouds seem not to be\nvery dense at this spot.\nDou you want to return\nto the ground?"

	str_cloud_used_back:
		.string "The cloud returns you\nto the ground."

	str_cloud_none:
		.string "The clouds seem to be floating\nnear the ground..."

.endif
