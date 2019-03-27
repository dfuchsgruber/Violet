//repoint of all pokemon

//basestats
.org 0x80001bc
	.word basestats

.org 0x80126d8
	.word basestats

.org 0x8012f2c
	.word basestats

.org 0x80131b4
	.word basestats

.org 0x80169e4
	.word basestats

.org 0x801ef8c
	.word basestats

.org 0x8021bac
	.word basestats

.org 0x8024038
	.word basestats

.org 0x802ba54
	.word basestats

.org 0x802ce28
	.word basestats

.org 0x802d4d4
	.word basestats

.org 0x802febc
	.word basestats

.org 0x802ffe8
	.word basestats

.org 0x80300f8
	.word basestats

.org 0x8039458
	.word basestats

.org 0x80398bc
	.word basestats

.org 0x8039968
	.word basestats

.org 0x8039ee8
	.word basestats

.org 0x803dbc4
	.word basestats

.org 0x803dc94
	.word basestats

.org 0x803e634
	.word basestats

.org 0x803e72c
	.word basestats

.org 0x803e798
	.word basestats

.org 0x803f680
	.word basestats

.org 0x803f6c8
	.word basestats

.org 0x8040c68
	.word basestats

.org 0x8040c78
	.word basestats

.org 0x80412b8
	.word basestats

.org 0x80418a0
	.word basestats

.org 0x8043814
	.word basestats

.org 0x8043828
	.word basestats

.org 0x804383c
	.word basestats

.org 0x8043850
	.word basestats

.org 0x8043864
	.word basestats

.org 0x80438a4
	.word basestats

.org 0x8043a8c
	.word basestats

.org 0x8043b10
	.word basestats

.org 0x8044108
	.word basestats

.org 0x8044358
	.word basestats

.org 0x8046504
	.word basestats

.org 0x8049f6c
	.word basestats

.org 0x804fca8
	.word basestats

.org 0x80c8698
	.word basestats

.org 0x80caa08
	.word basestats

.org 0x80e8138
	.word basestats

.org 0x80e8264
	.word basestats

.org 0x80e8374
	.word basestats

.org 0x8103d18
	.word basestats

.org 0x8106730
	.word basestats

.org 0x811af20
	.word basestats

.org 0x8136294
	.word basestats

.org 0x8136830
	.word basestats

.org 0x813ab7c
	.word basestats

.org 0x81566b8
	.word basestats

.org 0x81567e4
	.word basestats

.org 0x81568f4
	.word basestats

.org 0x8046108
	.word basestats + 17

.org 0x80461ac
	.word basestats + 17

//Pokenames

.org 0x8000144
	.word pokemon_names

.org 0x80113d4
	.word pokemon_names

.org 0x8011490
	.word pokemon_names

.org 0x8011528
	.word pokemon_names

.org 0x8011640
	.word pokemon_names

.org 0x8034c80
	.word pokemon_names

.org 0x8040eec
	.word pokemon_names

.org 0x80434dc
	.word pokemon_names

.org 0x8049788
	.word pokemon_names

.org 0x8053afc
	.word pokemon_names

.org 0x8053b64
	.word pokemon_names

.org 0x806bc84
	.word pokemon_names

.org 0x806bcd0
	.word pokemon_names

.org 0x8093fa4
	.word pokemon_names

.org 0x809f64c
	.word pokemon_names

.org 0x80a09ec
	.word pokemon_names

.org 0x80bd90c
	.word pokemon_names

.org 0x80cb2d8
	.word pokemon_names

.org 0x80cc064
	.word pokemon_names

.org 0x80ce254
	.word pokemon_names

.org 0x80ce858
	.word pokemon_names

.org 0x80cea70
	.word pokemon_names

.org 0x80e6740
	.word pokemon_names

.org 0x80f35ac
	.word pokemon_names

.org 0x8103814
	.word pokemon_names

.org 0x81038ec
	.word pokemon_names

.org 0x810398c
	.word pokemon_names

.org 0x8103a24
	.word pokemon_names

.org 0x8103ac0
	.word pokemon_names

.org 0x8103b20
	.word pokemon_names

.org 0x810511c
	.word pokemon_names

.org 0x810605c
	.word pokemon_names

.org 0x810672c
	.word pokemon_names

.org 0x8113fc0
	.word pokemon_names

.org 0x8119530
	.word pokemon_names

.org 0x811ad78
	.word pokemon_names

.org 0x811b0cc
	.word pokemon_names

.org 0x811b120
	.word pokemon_names

.org 0x8121944
	.word pokemon_names

.org 0x81363b4
	.word pokemon_names

.org 0x91a5b80
	.word pokemon_names

.org 0x91a689c
	.word pokemon_names

.org 0x91ad1d0
	.word pokemon_names


.org 0x08040EDA //remove the name limit
    mov r0, #0x7F
    lsl r0, #18


//Pokemoves

.org 0x803e97c
	.word pokemon_moves

.org 0x803ea10
	.word pokemon_moves

.org 0x803ea84
	.word pokemon_moves

.org 0x8043cc8
	.word pokemon_moves

.org 0x8043d20
	.word pokemon_moves

.org 0x8043e84
	.word pokemon_moves

//Frontsprites

.org 0x8000128
	.word pokemon_frontsprites

.org 0x800ec2c
	.word pokemon_frontsprites

.org 0x800ec70
	.word pokemon_frontsprites

.org 0x800ecec
	.word pokemon_frontsprites

.org 0x800ed04
	.word pokemon_frontsprites

.org 0x800f07c
	.word pokemon_frontsprites

.org 0x800f0b4
	.word pokemon_frontsprites

.org 0x800f130
	.word pokemon_frontsprites

.org 0x800f148
	.word pokemon_frontsprites

.org 0x80342c4
	.word pokemon_frontsprites

.org 0x8034c60
	.word pokemon_frontsprites

.org 0x8034f7c
	.word pokemon_frontsprites

.org 0x8046e68
	.word pokemon_frontsprites

.org 0x8050094
	.word pokemon_frontsprites

.org 0x80500dc
	.word pokemon_frontsprites

.org 0x8052088
	.word pokemon_frontsprites

.org 0x80534e4
	.word pokemon_frontsprites

.org 0x8076924
	.word pokemon_frontsprites

.org 0x8076948
	.word pokemon_frontsprites

.org 0x808f588
	.word pokemon_frontsprites

.org 0x80ce258
	.word pokemon_frontsprites

.org 0x80ce458
	.word pokemon_frontsprites

.org 0x80ce5f4
	.word pokemon_frontsprites

.org 0x80ce864
	.word pokemon_frontsprites

.org 0x810bc64
	.word pokemon_frontsprites

.org 0x810bc70
	.word pokemon_frontsprites

.org 0x811d934
	.word pokemon_frontsprites

.org 0x814ab9c
	.word pokemon_frontsprites


.org 0x0800ECF0
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x0800EC18
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x0800F134
        mov r0, #0x7F
        lsl r0, #0x18

//prevent deoxys second front/backsprite frame to be loaded (the att form frame)
.org 0x0800ED3C
    mov r1, #0

//backsprites

.org 0x800012c
	.word pokemon_backsprites

.org 0x800ecdc
	.word pokemon_backsprites

.org 0x800f120
	.word pokemon_backsprites

.org 0x8034440
	.word pokemon_backsprites

.org 0x8034484
	.word pokemon_backsprites

.org 0x8034e04
	.word pokemon_backsprites

.org 0x80769bc
	.word pokemon_backsprites

.org 0x8076a2c
	.word pokemon_backsprites

.org 0x810bc8c
	.word pokemon_backsprites

.org 0x810bca4
	.word pokemon_backsprites

.org 0x0800ECC2
        mov r2, #103
        lsl r2, #2

// Normal Pals

.org 0x8000130
	.word pokemon_pals

.org 0x804400c
	.word pokemon_pals

.org 0x8044030
	.word pokemon_pals

.org 0x80440a4
	.word pokemon_pals

.org 0x8083924
	.word pokemon_pals

.org 0x08043FFE
        mov r0, #0x7F
        lsl r0, #0x18

//shiny pals

.org 0x8000134
	.word pokemon_shiny_pals

.org 0x8044044
	.word pokemon_shiny_pals

.org 0x80440b4
	.word pokemon_shiny_pals

// Icons

.org 0x8000138
	.word pokemon_icons

.org 0x8097168
	.word pokemon_icons

.org 0x83d3964
	.word pokemon_icons

.org 0x800013c
	.word pokemon_icon_usage

.org 0x80914ac
	.word pokemon_icon_usage

.org 0x8096fd8
	.word pokemon_icon_usage

.org 0x8097068
	.word pokemon_icon_usage

.org 0x80971f0
	.word pokemon_icon_usage

.org 0x8097224
	.word pokemon_icon_usage

.org 0x8097278
	.word pokemon_icon_usage

.org 0x809729c
	.word pokemon_icon_usage

.org 0x809730c
	.word pokemon_icon_usage

.org 0x809732c
	.word pokemon_icon_usage

.org 0x809733c
	.word pokemon_icon_usage

//prevent deoxys second (att) frame icon to be loaded
.org 0x0809715C
        mov r0, #0

.org 0x0809709E
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x080971BE
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x08096F8A
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x08097256
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x080972EA
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x08097316
        mov r0, #0x7F
        lsl r0, #0x18

//Backsprites Y Displacement

.org 0x8074598
	.word pokemon_player_y

.org 0x80745c8
	.word pokemon_player_y

.org 0x80745d4
	.word pokemon_player_y

.org 0x80764c8
	.word pokemon_player_y

.org 0x8076a80
	.word pokemon_player_y

.org 0x8076b4c
	.word pokemon_player_y

.org 0x8076b5c
	.word pokemon_player_y

.org 0x8076b68
	.word pokemon_player_y

//Frontsprite Y Displacement

.org 0x8011ed0
	.word pokemon_enemy_y

.org 0x8011f04
	.word pokemon_enemy_y

.org 0x8011f30
	.word pokemon_enemy_y

.org 0x80476e4
	.word pokemon_enemy_y

.org 0x8051430
	.word pokemon_enemy_y

.org 0x8052140
	.word pokemon_enemy_y

.org 0x8052820
	.word pokemon_enemy_y

.org 0x805359c
	.word pokemon_enemy_y

.org 0x8074664
	.word pokemon_enemy_y

.org 0x8074698
	.word pokemon_enemy_y

.org 0x80746ac
	.word pokemon_enemy_y

.org 0x807650c
	.word pokemon_enemy_y

.org 0x8076a3c
	.word pokemon_enemy_y

.org 0x8076c38
	.word pokemon_enemy_y

.org 0x8076c54
	.word pokemon_enemy_y

.org 0x814a5fc
	.word pokemon_enemy_y

//Pokemon Altitude

.org 0x80355f8
	.word pokemon_altitude

.org 0x803565c
	.word pokemon_altitude

.org 0x80746f8
	.word pokemon_altitude

.org 0x807470c
	.word pokemon_altitude




.org 0x080746EC
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x0807468C
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x080745BC
        mov r0, #0x7F
        lsl r0, #0x18

.org 0x8043b68
	.word pokemon_tm_compatibility

.org 0x8043b80
	.word pokemon_tm_compatibility

//Evolution table

.org 0x8042e6c
	.word pokemon_evolutions

.org 0x8042ebc
	.word pokemon_evolutions

.org 0x8043038
	.word pokemon_evolutions

.org 0x80458a0
	.word pokemon_evolutions

.org 0x80cea64
	.word pokemon_evolutions

.org 0x919a680
	.word pokemon_evolutions

.org 0x919ac5c
	.word pokemon_evolutions

.org 0x812eb30
	.word pokemon_item_animations

.org 0x08072028
        ldr r0, =pokemon_play_cry_hook | 1
        bx r0
        .pool

.org 0x08043E90
        ldr r1, =pokemon_get_display_number | 1
        bx r1
        .pool

.org 0x08045874
        ldr r1, =pokemon_get_basis_stage | 1
        bx r1
        .pool

.org 0x08043100
        ldr r3, =pokedex_get_species_by_dex_id | 1
        bx r3
        .pool

.org 0x8106904
	.word pokedex_habitats

.org 0x8106944
	.word pokedex_habitats

.org 0x8106a0c
	.word pokedex_habitats

.org 0x8106a74
	.word pokedex_habitats

.org 0x8106b14
	.word pokedex_habitats

.org 0x8088f18
	.word pokedex_entries

.org 0x8088f40
	.word pokedex_entries

.org 0x8088f54
	.word pokedex_entries

.org 0x8105b0c
	.word pokedex_entries

.org 0x8105b94
	.word pokedex_entries

.org 0x8105be0
	.word pokedex_entries

.org 0x8105db8
	.word pokedex_entries

.org 0x8106744
	.word pokedex_entries

//footprint disable

.org 0x08105E0E
        ldr r0, =0x084400C0 //unown footprint offset
.org 0x8105E88
        .pool
        
//move tutor
.org 0x08120BDC
    ldr r1, =move_tutor_get_attack | 1
    bx r1
    .pool

.org 0x08120C1C
    ldr r2, =move_tutor_is_compatible | 1
    bx r2
    .pool

//move tutor limiter
.org 0x08127874
    lsl r0, #0
    lsl r0, #0 //overwrite the limiting check

.org 0x0811F48A
    lsl r0, #0
    lsl r0, #0

    
//Remove the strucutre encryption and pid usage
.org 0x0803E2E8
    ldr r1, =pokemon_calculate_checksum | 1
    bx r1
    .pool

.org 0x0803F81C
    //decrypt substructure
    bx lr

.org 0x0803F7F8
    //encrypt substructure  
    bx lr

.org 0x0803F84E
    //order of substruct partitions is always ABCD
    mov r0, #0
    mov r0, #0

.org 0x8042D9C
    ldr r1, =pokemon_get_nature | 1
    bx r1
    .pool

.org 0x8042DB4
    ldr r1, =pokemon_nature_by_pid | 1
    bx r1
    .pool

//shinyness
.org 0x0804439C
    ldr r2, =pokemon_is_shiny | 1
    bx r2
    .pool

.org 0x08043FF4
    ldr r3, =pokemon_get_pal | 1
    bx r3
    .pool

.org 0x08044080
    ldr r3, =pokemon_get_pal_struct | 1
    bx r3
    .pool

.org 0x080F19EE
    ldr r7, =0xFFFF
    mov r1, r4
    ldr r2, =pokemon_is_shiny | 1
    bl blxr2
    mov r8, r0
    b pshinysparkledone
    .pool
blxr2:
    bx r2
pshinysparkledone:
    
//This pid is plugged into pokedex
.org 0x08104C20
    ldr r1, =pokedex_get_pid | 1
    bx r1
    .pool


.org 0x080838DC
    //pokepic pid generation must not be shiny
    mov r3, #0

//evaluate contest stats as ev/4

//these 6 patches prevent the division by 4

.org 0x0803E3AE
    mov r1, #0x16 //hp -> coolness

.org 0x0803E47C
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

.org 0x0803E3C6
    mov r1, #0x17 //atk -> beauty

.org 0x0803E4C8
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

.org 0x0803E3DE
    mov r1, #0x18 //def -> cuteness

.org 0x0803E50E
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

.org 0x0803E3F6
    mov r1, #0x21 //init -> smartness

.org 0x0803E554
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

.org 0x0803E40E
    mov r1, #0x2F //satk -> toughness

.org 0x0803E59A
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

.org 0x0803E426
    mov r1, #0x30 //sdef -> sheen

.org 0x0803E5E0
lsl r0, #0
lsl r0, #0
lsl r0, #0x1A
lsr r0, #0x1A

//disable the 512 ev limit (due to the fact that 255 can be earned on every single ev)
.org 0x0804392A
    lsl r0, #0
    
.org 0x080438E6
    lsl r0, #0
    lsl r0, #0
    lsl r0, #0
    lsl r0, #0
    lsl r0, #0

// Breeding
.org 0x08045B2C
    ldr r0, =_pokemon_get_egg_moves_stub | 1
    bx r0
    .pool


// Nature names (decap)
.org 0x08464F24
	.word str_nature_robust
	.word str_nature_solo
	.word str_nature_hart
	.word str_nature_frech
	.word str_nature_mutig
	.word str_nature_kuehn
	.word str_nature_sanft
	.word str_nature_pfiffig
	.word str_nature_lasch
	.word str_nature_locker
	.word str_nature_maessig
	.word str_nature_mild
	.word str_nature_zaghaft
	.word str_nature_hitzig
	.word str_nature_ruhig
	.word str_nature_still
	.word str_nature_zart
	.word str_nature_sacht
	.word str_nature_kauzig
	.word str_nature_forsch
	.word str_nature_scheu
	.word str_nature_hastig
	.word str_nature_froh
	.word str_nature_naiv
	.word str_nature_ernst

// Stats like Angriff, Vert., Init., Lv., ...
.org 0x812b6e0
	.word pokemon_stat_names
.org 0x812b79c
	.word pokemon_stat_names
.org 0x812bedc
	.word pokemon_stat_names

// Stats for battle increase
.org 0x083FD470
	.word str_kp, str_angriff, str_vert, str_init, str_sp_ang
	.word str_sp_ver, str_accuracy, str_flight_value

.org 0x0803DA00
	ldr r0, = pokemon_new_pid_hook | 1
	bx r0
	.pool

// Breeding
.org 0x08045EA4
	ldr r2, =breeding_alter_egg_species | 1
	bx r2
	.pool

.org 0x080459C4
	ldr r2, =breeding_inherit_ivs | 1
	bx r2
	.pool

.org 0x08046054
	ldr r3, =breeding_pokemon_new | 1
	bx r3
	.pool

.org 0x080458F4
	ldr r1, =breeding_spawn_egg | 1
	bx r1
	.pool

.org 0x08045924
	ldr r1, =breeding_spawn_male_egg | 1
	bx r1
	.pool

.org 0x08045F04
	ldr r2, =breeding_get_egg_species_and_parents | 1
	bx r2
	.pool

.org 0x08046B00
	ldr r2, =egg_hatched_pokemon_new | 1
	bx r2
	.pool

.org 0x0806D680
	.word ow_script_egg_hatch

.org 0x080461C8
	ldr r1, =daycare_proceed | 1
	bx r1
	.pool

.org 0x08046104
	.word str_egg

.org 0x080461a8
	.word str_egg

.org 0x080465c8
	.word compatibility_strings

.org 0x08045bd4
	ldr r3, =breeding_egg_create_moves | 1
	bx r3
	.pool

// Summary

.org 0x08137A0C
	ldr r0, =summary_print_egg_memo | 1
	bx r0
	.pool


.org 0x08464F88
	.word str_summary_egg_memo_duration_very_long
	.word str_summary_egg_memo_duration_long
	.word str_summary_egg_memo_duration_soon
	.word str_summary_egg_memo_duration_very_soon
