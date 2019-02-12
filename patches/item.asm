
item_resource equ 0x083D3BE8
item_effects equ 0x082527E0

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

.org item_resource + 0x10B * 8
    .word gfx_item_wolkenherzTiles
    .word gfx_item_wolkenherzPal

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

//item effects (only used for evo stones so far)
.org item_effects + 4 * (99 - 13)
        .word item_effect_evolution_stone //Link Cable
        .word item_effect_evolution_stone //Dark Stone
        .word item_effect_evolution_stone //Sparkle Stone
        .word item_effect_evolution_stone //Light Stone

.org 0x08125adc
	.word tm_hm_to_attack

.org 0x08125afc
	.word tm_hm_to_attack

.org 0x080A13A4
	.word str_cant_dismount_cloud

// Prevent the player form dismounting the clound on underwater maps
.org 0x080A133E
	ldr r1, =map_is_cloud | 1
	bl _bxr1
	ldr r1, =0x080A137E | 1
	bx r1
_bxr1:
	bx r1
	.pool
