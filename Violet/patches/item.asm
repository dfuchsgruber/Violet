
item_resource equ 0x083D3BE8

.org 0x0815F914 + (0x88*4)
    .word script_cmd_x88_pokemart3 | 1

.org item_resource + 0x34 * 8
    .word gfx_item_magmaisiererTiles
    .word gfx_item_magmaisiererPal

.org item_resource + 0x3A * 8
    .word gfx_item_leben_orbTiles
    .word gfx_item_leben_orbPal

.org item_resource + 0x3B * 8
    .word gfx_item_evolithTiles
    .word gfx_item_evolithPal

.org item_resource + 0x48 * 8
    .word gfx_item_goldbonbonTiles
    .word gfx_item_goldbonbonPal

.org item_resource + 0x52 * 8
    .word gfx_item_suessbonbonTiles
    .word gfx_item_suessbonbonPal

.org item_resource + 0x64 * 8
    .word gfx_item_finstersteinTiles
    .word gfx_item_finstersteinPal

.org item_resource + 0x65 * 8
    .word gfx_item_leuchtsteinTiles
    .word gfx_item_leuchtsteinPal

.org item_resource + 0x66 * 8
    .word gfx_item_funkelsteinTiles
    .word gfx_item_funkelsteinPal

.org item_resource + 0xE2 * 8
    .word gfx_item_bisaflornitTiles
    .word gfx_item_bisaflornitPal

.org item_resource + 0xE3 * 8
    .word gfx_item_gluraknitTiles
    .word gfx_item_gluraknitPal

.org item_resource + 0xE4 * 8
    .word gfx_item_turtoknitTiles
    .word gfx_item_turtoknitPal

.org item_resource + 0xEB * 8
    .word gfx_item_ampharosnitTiles
    .word gfx_item_ampharosnitPal

.org item_resource + 0xEC * 8
    .word gfx_item_gengarnitTiles
    .word gfx_item_gengarnitPal

.org item_resource + 0xED * 8
    .word gfx_item_bibornitTiles
    .word gfx_item_bibornitPal

.org item_resource + 0xF8 * 8
    .word gfx_item_lahmrauchTiles
    .word gfx_item_lahmrauchPal

.org item_resource + 0xF9 * 8
	.word gfx_item_eisbrockenTiles
	.word gfx_item_eisbrockenPal

.org item_resource + 0xFA * 8
	.word gfx_item_nassbrockenTiles
	.word gfx_item_nassbrockenPal

.org item_resource + 0xFB * 8
	.word gfx_item_glattbrockenTiles
	.word gfx_item_glattbrockenPal

.org item_resource + 0xFC * 8
	.word gfx_item_heissbrockenTiles
	.word gfx_item_heissbrockenPal

.org item_resource + 0xFD * 8
	.word gfx_item_lichtlehmTiles
	.word gfx_item_lichtlehmPal

.org item_resource + 0xFE * 8
    .word gfx_item_steinrauchTiles
    .word gfx_item_steinrauchPal

.org item_resource + 0xFF * 8
    .word gfx_item_scheuchrauchTiles
    .word gfx_item_scheuchrauchPal

.org item_resource + 0x100 * 8
    .word gfx_item_gluecksrauchTiles
    .word gfx_item_gluecksrauchPal

.org item_resource + 0x10B * 8
    .word gfx_item_wolkenherzTiles
    .word gfx_item_wolkenherzPal

.org item_resource + 0x114 * 8
    .word gfx_item_spiritkernTiles
    .word gfx_item_spiritkernPal

.org item_resource + 0x15D * 8
    .word gfx_item_zugangskarteTiles
    .word gfx_item_zugangskartePal

.org item_resource + 0x168 * 8
    .word gfx_item_wolkeTiles
    .word gfx_item_wolkePal

.org item_resource + 0x3C * 8
    .word gfx_item_scharfzahnTiles
    .word gfx_item_scharfzahnPal

.org item_resource + 0x63 * 8
    .word gfx_item_linkkabelTiles
    .word gfx_item_linkkabelPal

.org item_resource + 0x3d * 8
    .word gfx_item_ovaler_steinTiles
    .word gfx_item_ovaler_steinPal


//@Bike sound := 195
.org 0x080A1402
    mov r0, #195


//item table
.org 0x80001c8
	.word items


.org 0x809a9bc
	.word items


.org 0x809a9e0
	.word items


.org 0x809aa04
	.word items


.org 0x809aa28
	.word items


.org 0x809aa4c
	.word items


.org 0x809aa70
	.word items


.org 0x809aa94
	.word items


.org 0x809aab8
	.word items


.org 0x809aadc
	.word items


.org 0x809ab00
	.word items


.org 0x809ab24
	.word items


.org 0x809ab48
	.word items


.org 0x809ab6c
	.word items


.org 0x809ab90
	.word items
    
.org 0x803a1b0
	.word item_effects


.org 0x8041448
	.word item_effects


.org 0x8042424
	.word item_effects


.org 0x8042b30
	.word item_effects


.org 0x8042d3c
	.word item_effects


.org 0x812509c
	.word item_effects


.org 0x812579c
	.word item_effects


.org 0x8126d14
	.word item_effects


// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x080412e4
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_apply | 1
    bx r0
    .pool

    
// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x08042314
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_unapplicable | 1
    bx r0
    .pool


.org 0x08042b08
    ldr r3, =_item_effect_get_hp_healed_offset | 1
    bx r3
    .pool

.org 0x08126cb8
    ldr r1, = item_get_effect_type | 1
    bx r1
    .pool

.org 0x081250a8
    ldr r1, = item_effect_print_result | 1
    bx r1
    .pool

.org 0x08125adc
	.word tm_hm_to_attack

.org 0x08125afc
	.word tm_hm_to_attack

.org 0x080A13A4
	.word str_cant_dismount_cloud

// Prevent the player form dismounting the clound on underwater maps
.org 0x080A133E
	ldr r1, =cloud_not_dismountable | 1
	bl _bxr1
	ldr r1, =0x080A137E | 1
	bx r1
_bxr1:
	bx r1
	.pool
