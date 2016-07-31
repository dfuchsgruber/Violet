overworld_table equ 0x08C80000

.org overworld_table + 4*1
    .word ow_mskate

.org overworld_table + 4*86
    .word ow_igva

.org overworld_table + 4*152
    .word ow_bbship

.org overworld_table + 4*153
    .word ow_mpirate