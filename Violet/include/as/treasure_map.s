.equ TREASURE_MAP_FIND, 0
.equ TREASURE_MAP_OBTAIN, 1

.macro give_treasure_map treasure_map_idx:req give_type=TREASURE_MAP_FIND
    setvar 0x8004 \treasure_map_idx
    setvar 0x8005 \give_type
    call ow_script_obtain_treasure_map
.endm
