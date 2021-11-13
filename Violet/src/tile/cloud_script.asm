.include "overworld_script.s"
.include "flags.s"
.include "specials.s"

.global script_cloud_facings

.thumb
.align 2


script_cloud_force_down:
    special SPECIAL_SET_PLAYER_ON_CLOUD
script_face_down:
    spriteface 0xFF 1
    clearflag ROAMER_LOCATIONS_FIXED
    end

script_cloud_force_up:
    special SPECIAL_SET_PLAYER_ON_CLOUD
script_face_up:
    spriteface 0xFF 2
    clearflag ROAMER_LOCATIONS_FIXED
    end

script_cloud_force_left:
    special SPECIAL_SET_PLAYER_ON_CLOUD
script_face_left:
    spriteface 0xFF 3
    clearflag ROAMER_LOCATIONS_FIXED
    end

script_cloud_force_right:
    special SPECIAL_SET_PLAYER_ON_CLOUD
script_face_right:
    spriteface 0xFF 4
    clearflag ROAMER_LOCATIONS_FIXED
    end

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
.elseif LANG_EN
	str_cant_dismount_cloud:
		.autostring 35 2 "You can't dismount the cloud here.PAUSE_UNTIL_PRESS"
.endif