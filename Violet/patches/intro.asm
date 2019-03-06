

.org 0x8131278
    .word gfx_intro_hiro_malePal
    .word gfx_intro_hiro_maleTiles

.org 0x08131350
    .word gfx_intro_profPal
    .word gfx_intro_profTiles

.org 0x081312B0
    .word gfx_intro_rivalPal
    .word gfx_intro_rivalTiles

.org 0x08131290
    .word gfx_intro_hiro_femPal
    .word gfx_intro_hiro_femTiles

.org 0x08463FF0
    .word gfx_intro_groundPal

.org 0x0812ED88
    .word gfx_intro_bgPal

.org 0x08130E1C
    .word gfx_intro_bgPal

// Professor's Pokemon
.org 0x08130F90
    mov r2, #190 //@ Species = Griffel (190)

.org 0x08130F9C
    mov r0, #190

.org 0x08130FF0
    .word pokemon_frontsprites + 8 * 190
    .word pokemon_pals + 8 * 190

.org 0x812FB88
    mov r0, #190

.org 0x08463FBC
    .word str_intro_board_0
    .word str_intro_board_1
    .word str_intro_board_2

.org 0x0812F940
    .word str_intro_prof_0
.org 0x0812F9E4
    .word str_intro_prof_1
.org 0x0812FB58
    .word str_intro_prof_2
.org 0x0812FBEC
    .word str_intro_prof_3
.org 0x0812FD74
    .word str_intro_prof_4
.org 0x0813015C
    .word str_intro_prof_5
.org 0x08130500
    .word str_intro_prof_6
.org 0x081307C4
    .word str_intro_prof_7
.org 0x0813064C
    .word str_intro_prof_8
.org 0x08130914
    .word str_intro_prof_9

.org 0x0812FFE8
    .word str_intro_prof_boy
    .word str_intro_prof_girl

//.org 0x0812F094
//    .word player_std_names
.org 0x08464140
    .word 0x81C99E5,0x81C9A38,0x81C9A73,0x81C9AA0,0x81C9AC6,0x81C9AFB,str_player_std_name_1,str_player_std_name_2
    .word str_player_std_name_6,str_player_std_name_7,str_player_std_name_8,str_player_std_name_9,str_player_std_name_10,str_player_std_name_11,str_player_std_name_12,str_player_std_name_13
    .word str_player_std_name_14,str_player_std_name_15,str_player_std_name_16,str_player_std_name_17,str_player_std_name_18,str_player_std_name_19,str_player_std_name_20,str_player_std_name_21
    .word str_player_std_name_22,str_player_std_name_1,str_player_std_name_2,str_player_std_name_23,str_player_std_name_24,str_player_std_name_25,str_player_std_name_26,str_player_std_name_27
    .word str_player_std_name_28,str_player_std_name_29,str_player_std_name_30,str_player_std_name_31,str_player_std_name_32,str_player_std_name_33,str_player_std_name_34,str_player_std_name_35
    .word str_player_std_name_36,str_player_std_name_37,str_player_std_name_38,str_player_std_name_39,str_player_std_name_0,str_player_std_name_3,str_player_std_name_4,str_player_std_name_5

.org 0x08131734
    .word str_player_std_new_name
