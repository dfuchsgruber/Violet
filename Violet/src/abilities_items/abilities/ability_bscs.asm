.include "battlescript.s"

.global bsc_flinch_aura
.global bsc_flinch_raura
.global bsc_flinch_baura
.global bsc_flinch_gaura

.align 4
bsc_flinch_aura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x18F
    waitmessage 0x40
    goto 0x81DABDE

.align 4
bsc_flinch_raura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x190
    waitmessage 0x40
    goto 0x81DABDE

.align 4
bsc_flinch_baura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x191
    waitmessage 0x40
    goto 0x81DABDE

.align 4
bsc_flinch_gaura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x192
    waitmessage 0x40
    goto 0x81DABDE

