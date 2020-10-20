.include "overworld_script.s"
.include "movements.s"

.global mov_fd
.global mov_fu
.global mov_fr
.global mov_fl

mov_fd:
    .byte LOOK_DOWN, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fr:
    .byte LOOK_RIGHT, STOP
mov_fu:
    .byte LOOK_UP, STOP

.global mov_exclam
.global mov_question

mov_exclam:
    .byte SAY_EXCLAM, STOP
mov_question:
    .byte SAY_QUESTION, STOP

.global mov_1u
.global mov_1d
.global mov_1r
.global mov_1l

mov_1u:
	.byte STEP_UP, STOP
mov_1d:
	.byte STEP_DOWN, STOP
mov_1r:
	.byte STEP_RIGHT, STOP
mov_1l:
	.byte STEP_LEFT, STOP

.global mov_2u
.global mov_2d
.global mov_2r
.global mov_2l

mov_2u:
	.byte STEP_UP, STEP_UP, STOP
mov_2d:
	.byte STEP_DOWN, STEP_DOWN, STOP
mov_2r:
	.byte STEP_RIGHT, STEP_RIGHT, STOP
mov_2l:
	.byte STEP_LEFT, STEP_LEFT, STOP

.global mov_3u
.global mov_3d
.global mov_3r
.global mov_3l

mov_3u:
	.byte STEP_UP, STEP_UP, STEP_UP, STOP
mov_3d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_3r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_3l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_4u
.global mov_4d
.global mov_4r
.global mov_4l

mov_4u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_4d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_4r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_4l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_5u
.global mov_5d
.global mov_5r
.global mov_5l

mov_5u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_5d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_5r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_5l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_6u
.global mov_6d
.global mov_6r
.global mov_6l

mov_6u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_6d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_6r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_6l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_7u
.global mov_7d
.global mov_7r
.global mov_7l

mov_7u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_7d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_7r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_7l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_8u
.global mov_8d
.global mov_8r
.global mov_8l

mov_8u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_8d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_8r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_8l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

.global mov_9u
.global mov_9d
.global mov_9r
.global mov_9l

mov_9u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_9d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_9r:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_9l:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP