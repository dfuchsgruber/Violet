.ifdef LANG_GER

.global str_item_walk
str_item_walk:
	.string "Laufen"

.global str_item_open
str_item_open:
	.string "Öffnen"

.global str_item_effect_oak_no_time_to_use
str_item_effect_oak_no_time_to_use:
	.autostring 35 2 "Dieses Item kann jetzt nicht verwendet werden.PAUSE_UNTIL_PRESS"

.global str_item_select
str_item_select:
	.string "Select"

.global str_item_muell
str_item_muell:
	.string "Müll"

.global str_beerentuete
str_beerentuete:
	.string "Beerentüte"

.global str_vm_tm_box
str_vm_tm_box:
	.string "Vm/Tm-Box"

.elseif LANG_EN

.global str_item_walk
str_item_walk:
	.string "Walk"

.global str_item_open
str_item_open:
	.string "Open"

.global str_item_effect_oak_no_time_to_use
str_item_effect_oak_no_time_to_use:
	.autostring 35 2 "This item can not be used now."

.global str_item_select
str_item_select:
	.string "Select"

.global str_item_muell
str_item_muell:
	.string "Trash"

.global str_beerentuete
str_beerentuete:
	.string "Berry-Bag"

.global str_vm_tm_box
str_vm_tm_box:
	.string "Hm/Tm-Box"

.endif
