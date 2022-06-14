@ TODO: reserach all the offsets and fix to symbols
.include "attacks.s"

.global pokemon_party_menu_options

.align 4

pokemon_party_menu_options:  @format : string, function pointer
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
    .word ev_menu_initialize_from_party_menu
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
    .word attack_names + ATTACK_KRAXLER * 13
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
    .word attack_names + ATTACK_GEHEIMPOWER * 13
    .word 0x81245f5

.ifdef LANG_GER

	str_fp_menu:
		.string "Fleiß-Punkte"
        
.elseif LANG_EN

	str_fp_menu:
		.string "Effort Values"


.endif
