@// Tables pasted from the ROM
.include "attacks.s"

.global pokemon_party_menu_opts

.align 4
@Limit for field moves is 0xC which is currently located at 
pokemon_party_menu_opts:  @format : string, function pointer
    .word str_bericht
    .word 0x8122d85
    .word str_tausch
    .word 0x8122e39
    .word str_zuruck
    .word 0x8123691
    .word str_items
    .word 0x81236f1
    .word str_geben
    .word 0x8123755
    .word str_nehmen
    .word 0x8123c89
    .word str_fp_menu
    .word fp_menu_init + 1
    .word 0x84167f2 @//brief nehmen (deprecated)
    .word 0x8123e5d
    .word 0x84167f9 @//brief lesen
    .word 0x8123da9
    .word str_zuruck @//brief zuruck
    .word 0x81240b5
    .word str_tausch @//str tausch (1)
    .word 0x8124145
    .word str_aussenden
    .word 0x8124145
    .word str_eintragen
    .word 0x81241a5
    .word str_austragen
    .word 0x81242c9
    .word str_nehmen
    .word 0x81243a5
    .word str_wahlen
    .word 0x81243d5
    .word str_tausch
    .word 0x81244e1
    .word str_tausch
    .word 0x81245f1
    .word attack_names + ATTACK_BLITZ * 13
    .word 0x81245f5
    .word attack_names + ATTACK_ZERSCHNEIDER * 13
    .word 0x81245f5
    .word attack_names + ATTACK_FLIEGEN * 13
    .word 0x81245f5
    .word attack_names + ATTACK_STAERKE * 13
    .word 0x81245f5
    .word attack_names + ATTACK_SURFER * 13
    .word 0x81245f5
    .word attack_names + ATTACK_ZERTRUEMMERER * 13
    .word 0x81245f5
    .word attack_names + ATTACK_KASKADE * 13
    .word 0x81245f5
    .word attack_names + ATTACK_TELEPORT * 13
    .word 0x81245f5
    .word attack_names + ATTACK_SCHAUFLER * 13
    .word 0x81245f5
    .word attack_names + ATTACK_MILCHGETRAENK * 13
    .word 0x81245f5
    .word attack_names + ATTACK_WEICHEI * 13
    .word 0x81245f5
    .word attack_names + ATTACK_LOCKDUFT * 13
    .word 0x81245f5






.global field_moves

.align 4
field_moves:
    .hword 0x94
    .hword 0xf
    .hword 0x13
    .hword 0x46
    .hword 0x39
    .hword 0xf9
    .hword 0x7f
    .hword 0x64
    .hword 0x5b
    .hword 0xd0
    .hword 0x87
    .hword 0xe6
    .hword 0xFFFF

.global field_move_descriptions

.align 4

field_move_descriptions:
.word 0x84174f2
.word 0x8417493
.word 0x84174ab
.word 0x84174db
.word 0x84174c5
.word 0x8417508
.word 0x8417522
.word 0x8417573
.word 0x8417543
.word 0x8417569
.word 0x8417569
.word 0x8417554

.global field_move_initalizers

.align 4

field_move_initalizers:
.word 0x80c9ce5
.word 0xd
.word 0x80979b1
.word 0x7
.word 0x8124add
.word 0xd
.word 0x80d0995
.word 0xd
.word 0x81249e9
.word 0x8
.word 0x80c9b91
.word 0xd
.word 0x8124b49
.word 0xd
.word 0x80f6985
.word 0xd
.word 0x80c9c31
.word 0xd
.word 0x80e58a9
.word 0x10
.word 0x80e58a9
.word 0x10
.word 0x80de2ed
.word 0xd
@.word 0x80f6985 @
@.word 0xd

@ // String
.ifdef LANG_GER

	str_fp_menu:
		.string "Fleiß-Punkte"

.elseif LANG_EN

	str_fp_menu:
		.string "Effort Values"

.endif

