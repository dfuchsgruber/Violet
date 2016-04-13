AS=@arm-none-eabi-as
LD=@arm-none-eabi-ld
OBJCOPY=arm-none-eabi-objcopy
GRIT=@grit
CC=@arm-none-eabi-gcc
NM=@arm-none-eabi-nm
ARS=@armipsd

ASFLAGS=-mthumb
CFLAGS=-mthumb -mno-thumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -O3 -std=gnu99
CFLAGS2=-c -Os -mthumb -mno-thumb-interwork
CFLAGS3=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2
CFLAGS4=-c -std=gnu11 -mthumb -mthumb-interwork -mcpu=arm7tdmi -fno-inline -mlong-calls -march=armv4t -Wall -Wextra -Wconversion -O2 -x assembler
LDFLAGS=-z muldefs

all: clean attack_split abilities_items fp_menu wild_pokemon evolutions mega tm tile misc trainer transparency
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/linked.o" "build/attack_split.o" "build/abit.o" "build/fpmenu.o" "build/wp.o" "build/evo.o" "build/mega.o" "build/tm.o" "build/tile.o" "build/misc.o" "build/trainer.o" "build/trans.o"
	$(ARS) patches.asm
	$(NM) "build/linked.o" -n -g --defined-only
	
attack_split:
	$(AS) "src/attack_split/physisch_speziell.asm" -o "build/physisch_speziell.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/attack_split.o" "build/physisch_speziell.o"

abilities_items: choice_items hidden_abilities
	$(AS) "src/abilities_items/end_of_turn_abilities.asm" -o "build/abit_eot_abilities.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/abit.o" "build/abit_eot_abilities.o" "build/choice_item.o" "build/abit_hidab.o"
	
hidden_abilities:
	$(CC) $(CFLAGS3) "src/abilities_items/hidden_ability/get_pokemons_ability.c" -o "build/abit_hidab_getpokeab.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/abit_hidab.o" "build/abit_hidab_getpokeab.o"


choice_items:
	$(AS) "src/abilities_items/choice_item/raise_init.asm" -o "build/scarf_raise_init.o"
	$(AS) "src/abilities_items/choice_item/choice_band_on_0.asm" -o "build/scarf_cb0.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/choice_item.o" "build/scarf_raise_init.o" "build/scarf_cb0.o"	
	
fp_menu:
	$(CC) $(CFLAGS3) "src/fpmenu.c" -o "build/fpmenu_raw.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/fpmenu.o" "build/fpmenu_raw.o"
	
wild_pokemon:
	$(AS) "src/wild_pokemon/less_shinies.asm" -o "build/wp_less_shinies.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/wp.o" "build/wp_less_shinies.o"
	
evolutions:
	$(AS) "src/evolutions/get_pokemons_basis_stage.asm" -o "build/evo_get_basis.o"
	$(AS) "src/evolutions/evee.asm" -o "build/evo_eveelutions.o"
	$(AS) "src/evolutions/evolution_method_map.asm" -o "build/evo_em_map.o"
	$(AS) "src/evolutions/evolution_method_knowing_move.asm" -o "build/evo_em_move.o"
	$(AS) "src/evolutions/evolution_method_holding_item.asm" -o "build/evo_em_hitem.o"
	$(AS) "src/evolutions/evolution_method_item_while_holding_item.asm" -o "build/evo_em_litem.o"
	$(AS) "src/evolutions/evolution_stone_remove_held_item.asm" -o "build/evo_es_remove_i.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/evo.o" "build/evo_get_basis.o" "build/evo_eveelutions.o" "build/evo_em_map.o" "build/evo_em_move.o" "build/evo_em_hitem.o" "build/evo_em_litem.o" "build/evo_es_remove_i.o"

tm:
	$(CC) $(CFLAGS4) "src/tms/tm_sale.asm" -o "build/tm_sale.o"
	$(CC) $(CFLAGS4) "src/tms/count_arrows.asm" -o "build/tm_carrows.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/tm.o" "build/tm_sale.o" "build/tm_carrows.o"
	
mega:
	$(CC) $(CFLAGS3) "src/mega/show_icon.c" -o "build/mega_show_icon.o"
	$(CC) $(CFLAGS3) "src/mega/battle_func_execute_megas.c" -o "build/mega_bf_exec_mega.o"
	$(CC) $(CFLAGS4) "src/mega/hook_show_icon.asm" -o "build/mega_hshow_icon.o"
	$(CC) $(CFLAGS4) "src/mega/hook_hide_icon.asm" -o "build/mega_hhide_icon.o"
	# Animation
	$(CC) $(CFLAGS4) "src/mega/attack_animation.asm" -o "build/mega_aanim.o"
	$(CC) $(CFLAGS4) "src/mega/anim_task/anim_task_cry.asm" -o "build/mega_at_cry.o"
	$(CC) $(CFLAGS4) "src/mega/anim_task/anim_task_spriteupdate.asm" -o "build/mega_at_spriteup.o"
	$(CC) $(CFLAGS4) "src/mega/anim_task/anim_task_load_symbol.asm" -o "build/mega_at_loadsym.o"
	$(CC) $(CFLAGS4) "src/mega/anim_task/anim_task_load_custom_pals.asm" -o "build/mega_at_loadcpals.o"
	$(CC) $(CFLAGS3) "src/mega/callback_mega_anim.c" -o "build/mega_cb_manim.o"
	# Animation scripts
	$(CC) $(CFLAGS4) "src/mega/script/anim_mega.asm" -o "build/mega_script_amega.o"
	$(CC) $(CFLAGS4) "src/mega/script/anim_groudon.asm" -o "build/mega_script_agroudon.o"
	$(CC) $(CFLAGS4) "src/mega/script/anim_kyogre.asm" -o "build/mega_script_akyogre.o"
	$(CC) $(CFLAGS4) "src/mega/script/anim_rayquaza.asm" -o "build/mega_script_arayquaza.o"
	
	$(CC) $(CFLAGS3) "src/mega/symbol/spawn_symbols.c" -o "build/mega_sym_spawnsym.o"
	$(CC) $(CFLAGS4) "src/mega/symbol/hook_spawn_symbols.asm" -o "build/mega_sym_hspawnsym.o"
	
	$(CC) $(CFLAGS4) "src/mega/trigger/despawn_trigger_cbs.asm" -o "build/mega_trigger_despawn.o"
	$(CC) $(CFLAGS4) "src/mega/trigger/trigger_reset.asm" -o "build/mega_trigger_reset.o"
	$(CC) $(CFLAGS4) "src/mega/trigger/trigger_cntrl.asm" -o "build/mega_trigger_cntrl.o"
	$(CC) $(CFLAGS4) "src/mega/trigger/hook_bag_destroy_trigger.asm" -o "build/mega_trigger_bdtrigger.o"
	$(CC) $(CFLAGS4) "src/mega/trigger/hook_pokemon_destroy_trigger.asm" -o "build/mega_trigger_pdtrigger.o"
	
	$(CC) $(CFLAGS4) "src/mega/mega_items/hook_item_swap.asm" -o "build/mega_item_hitemswap.o"
	$(CC) $(CFLAGS4) "src/mega/mega_items/hook_knock_off.asm" -o "build/mega_item_hknockoff.o"
	$(CC) $(CFLAGS4) "src/mega/mega_items/hook_thief.asm" -o "build/mega_item_hthief.o"
	
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/mega.o" "build/mega_show_icon.o" "build/mega_hshow_icon.o" "build/mega_bf_exec_mega.o" "build/mega_hhide_icon.o" "build/mega_cb_manim.o" "build/mega_aanim.o" "build/mega_at_cry.o" "build/mega_script_amega.o" "build/mega_at_spriteup.o" "build/mega_at_loadsym.o" "build/mega_at_loadcpals.o" "build/mega_script_agroudon.o" "build/mega_script_akyogre.o" "build/mega_script_arayquaza.o" "build/mega_sym_spawnsym.o" "build/mega_sym_hspawnsym.o" "build/mega_trigger_despawn.o" "build/mega_trigger_reset.o" "build/mega_item_hitemswap.o" "build/mega_item_hknockoff.o" "build/mega_item_hthief.o" "build/mega_trigger_cntrl.o" "build/mega_trigger_bdtrigger.o" "build/mega_trigger_pdtrigger.o"

trainer:
	$(CC) $(CFLAGS4) "src/trainer/hook_build_trainer_poke.asm" -o "build/trainer_hbuild_t.o"
	$(CC) $(CFLAGS3) "src/trainer/build_trainer_poke.c" -o "build/trainer_build_t.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/trainer.o" "build/trainer_hbuild_t.o" "build/trainer_build_t.o"
	
tile:
	$(CC) $(CFLAGS3) "src/tile/desert_morgana.c" -o "build/tile_dmorgana.o"
	$(CC) $(CFLAGS4) "src/tile/step.asm" -o "build/tile_step.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/tile.o" "build/tile_step.o" "build/tile_dmorgana.o"

misc:
	$(CC) $(CFLAGS4) "src/misc/flash.asm" -o "build/misc_flash.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/misc.o" "build/misc_flash.o"

transparency:
	$(CC) $(CFLAGS4) "src/transparency/script_handler.asm" -o "build/trans_shandler.o"
	$(LD) $(LDFLAGS) -T linker.ld -T bprd.sym --relocatable -o "build/trans.o" "build/trans_shandler.o" 
	
clean:
	rm -f build/*.*