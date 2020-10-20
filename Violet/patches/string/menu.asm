//beutel
.org 0x81206a8
    .word str_beutel

.org 0x83a71a0
    .word str_beutel

.org 0x83a71b0
    .word str_sichern

.org 0x83a71c0
    .word str_beenden

.org 0x83a71b8
    .word str_options

.org 0x83a71f8
    .word str_beenden_desc

.org 0x845c50c
    .word str_pokemon
.org 0x83e749b
    .word str_pokemon
.org 0x841582a
    .word str_pokemon
.org  0x80dae18
    .word str_pokemon
.org 0x8129904
    .word str_pokemon
.org 0x83ed854
    .word str_pokemon

.org 0x83a71e4
    .word str_menu_pokemon_desc
.org 0x845b6e4
    .word str_bericht
.org 0x83d2e68
    .word str_bericht
.org 0x8261df8
    .word str_bericht
.org 0x8261e08
    .word str_bericht


.org 0x83e7504
        .word str_tausch
.org 0x845b734
        .word str_tausch
.org 0x845b6ec
        .word str_tausch
.org 0x845b764
        .word str_tausch
.org 0x845b76c
        .word str_tausch
.org 0x83d2e60
        .word str_tausch
.org 0x812990c
        .word str_tausch
.org 0x8261dfc
        .word str_tausch
.org 0x8261e10
        .word str_tausch

.org 0x83ea8dc
        .word str_geben
.org 0x8453dbc
        .word str_geben
.org 0x8454e68
        .word str_geben
.org 0x845b704
        .word str_geben
.org 0x8464224
        .word str_geben
.org 0x8465450
        .word str_geben
.org 0x840223c
        .word str_geben
.org 0x83d2e84
        .word str_geben
.org 0x83d2e88
        .word str_geben

.org 0x845b70c
        .word str_nehmen
.org 0x845b71c
        .word str_nehmen
.org 0x8454e60
        .word str_nehmen
.org 0x83d2e58
        .word str_nehmen
.org 0x83d2e80
        .word str_nehmen

.org 0x83ea9fc
        .word str_wahlen
.org 0x845bcd0
        .word str_wahlen
.org 0x8457ea8
        .word str_wahlen
.org 0x845b75c
        .word str_wahlen

.org 0x845b3b4
        .word str_choose_pokemon
.org 0x845b3f0
        .word str_choose_pokemon
.org 0x8261df4
        .word str_choose_pokemon

.org 0x845b3b8
        .word str_choose_pkmn_or_back

//options

.org 0x8088630
    .word str_option_head

.org 0x8088cec
    .word str_optionen

// Utilization of L=A etc. remove
.org 0x0806F21E
    lsl r0, #0

.org 0x0806F26C
    lsl r0, #0

.org 0x0806F066
    lsl r0, #0


.org 0x83cc160
    .word str_options_text_tempo
    .word str_options_animation
    .word str_options_battle_style
    .word str_settings_color
    .word str_options_detector
    .word str_options_borders

.org 0x083CC198
        .word str_settings_color_dn
        .word str_settings_color_standard

//help menu
.org 0x083CC1A0
	.word str_detektor_nachricht
	.word str_detektor_sound
	.word str_detektor_keine
	.pool

.org 0x083cc188
        .word str_options_animation_ein
        .word str_options_animation_aus

.org 0x83cc190
        .word str_options_battle_style_wechsel
        .word str_options_battle_style_folge

.org 0x8088a50
    .word str_options_border_motive
.org 0x8088be0
    .word str_options_border_motive

.org 0x08000652
	mov r0, #0
	.pool
	
//TM-Box
.org 0x8131d88
    .word str_schliessen
.org 0x813d32c
    .word str_schliessen

.org 0x845c49c
        .word str_items
.org 0x845c4c4
        .word str_items
.org 0x845b6fc
        .word str_items
.org 0x8453be8
        .word str_items
.org 0x83dfbd0
        .word str_items

.org 0x845c4c8
    .word str_key_items
.org 0x8453bec
    .word str_key_items
.org 0x83dfbd4
    .word str_key_items

.org 0x8453bf0
    .word str_pokeball

.org 0x8108900
    .word str_close_bag

//Trainer card
.org 0x808a038
    .word str_trainer_card_name

.org 0x808a174
    .word str_trainer_card_money
.org 0x808a1d4
    .word str_trainer_card_money
.org 0x80a0090
    .word str_trainer_card_money

.org 0x845c4d4
    .word str_spielzeit
.org 0x80f3894
    .word str_spielzeit
.org 0x806fde4
    .word str_spielzeit
.org 0x808a3cc
    .word str_spielzeit
.org 0x808a4a4
    .word str_spielzeit
.org 0x800ceb8
    .word str_spielzeit


.org 0x845c4d0
    .word str_pokedex
.org 0x83e75ac
    .word str_pokedex
.org 0x806fde0
    .word str_pokedex
.org 0x808a2a4
    .word str_pokedex
.org 0x808a31c
    .word str_pokedex
.org 0x800cf40
    .word str_pokedex

.org 0x83e85d8
       .word str_ja
.org 0x812a564
        .word str_ja
.org 0x8155524
        .word str_ja
.org 0x81555e0
        .word str_ja
.org 0x83df240
        .word str_ja
.org 0x83df338
        .word str_ja
.org 0x83df378
        .word str_ja

.org 0x83e8728
        .word str_nein
.org 0x845b438
        .word str_nein
.org 0x845b440
        .word str_nein
.org 0x812a568
        .word str_nein
.org 0x8155528
        .word str_nein
.org 0x81555e4
        .word str_nein
.org 0x83df248
        .word str_nein
.org 0x83df340
        .word str_nein
.org 0x83df380
        .word str_nein

// Saving dialoge
.org 0x0806FDD0
		.word str_player
.org 0x0806FDD4
		.word str_badges
