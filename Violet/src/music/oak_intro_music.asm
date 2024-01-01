.include "songs.s"

.global hook_music_oak_intro

.align 2

.thumb
hook_music_oak_intro:
	ldr r0, =MUS_TANN_SPEECH
	bl _playsong
	mov r0, #1
	ldr r1, =0x0812F890 | 1
	bx r1

_playsong:
	ldr r1, =playsong2
	bx r1
