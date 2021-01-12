.include "battlescript.s"
.include "constants/battle/battle_communication.s"
.include "constants/battle/battle_flags.s"

.global attack_effects
.global bsc_roar_success_force_out
.global bsc_roar_sucess_end_battle

.align 4
    attack_effects:
    .word bsc_attack_effect_hit @0x0
    .word 0x81dabfd @0x1
    .word 0x81dac6c @0x2
    .word 0x81dac77 @0x3
    .word 0x81dace5 @0x4
    .word 0x81dacf0 @0x5
    .word 0x81dacfb @0x6
    .word 0x81dad06 @0x7
    .word 0x81dad86 @0x8
    .word 0x81dadef @0x9
    .word 0x81dae07 @0xa
    .word 0x81dae12 @0xb
    .word bsc_attack_effect_hit @0xc
    .word 0x81dae1d @0xd
    .word bsc_attack_effect_hit @0xe
    .word bsc_attack_effect_hit @0xf
    .word 0x81dae28 @0x10
    .word bsc_attack_effect_hit @0x11
    .word 0x81dae71 @0x12
    .word 0x81dae7c @0x13
    .word 0x81dae87 @0x14
    .word bsc_attack_effect_hit @0x15
    .word bsc_attack_effect_hit @0x16
    .word 0x81dae92 @0x17
    .word 0x81dae9d @0x18
    .word 0x81daf02 @0x19
    .word 0x81daf13 @0x1a
    .word 0x81daf27 @0x1b
    .word bsc_attack_effect_roar //0x81daf41 @0x1c
    .word 0x81daf69 @0x1d
    .word 0x81db02d @0x1e
    .word 0x81db042 @0x1f
    .word 0x81db04d @0x20
    .word 0x81db070 @0x21
    .word 0x81db0f9 @0x22
    .word 0x81db104 @0x23
    .word 0x81db10d @0x24
    .word 0x81db118 @0x25
    .word 0x81db160 @0x26
    .word 0x81db191 @0x27
    .word 0x81db212 @0x28
    .word 0x81db229 @0x29
    .word 0x81db258 @0x2a
    .word bsc_attack_effect_hit @0x2b
    .word 0x81db289 @0x2c
    .word 0x81db2a1 @0x2d
    .word 0x81db2f2 @0x2e
    .word 0x81db305 @0x2f
    .word 0x81db322 @0x30
    .word 0x81db33b @0x31
    .word 0x81db388 @0x32
    .word 0x81db393 @0x33
    .word 0x81db39e @0x34
    .word 0x81db3a9 @0x35
    .word 0x81db3b4 @0x36
    .word bsc_attack_effect_hit @0x37
    .word bsc_attack_effect_hit @0x38
    .word 0x81db3bf @0x39
    .word 0x81db3d2 @0x3a
    .word 0x81db3dd @0x3b
    .word 0x81db3e8 @0x3c
    .word bsc_attack_effect_hit @0x3d
    .word 0x81db3f3 @0x3e
    .word bsc_attack_effect_hit @0x3f
    .word bsc_attack_effect_hit @0x40
    .word 0x81db3fe @0x41
    .word 0x81db411 @0x42
    .word 0x81db472 @0x43
    .word 0x81db4ef @0x44
    .word 0x81db4fa @0x45
    .word 0x81db505 @0x46
    .word 0x81db510 @0x47
    .word 0x81db51b @0x48
    .word 0x81db526 @0x49
    .word bsc_attack_effect_hit @0x4a
    .word 0x81db531 @0x4b
    .word 0x81db559 @0x4c
    .word 0x81db564 @0x4d
    .word bsc_attack_effect_hit @0x4e
    .word 0x81db57c @0x4f
    .word 0x81db5bf @0x50
    .word 0x81db5dd @0x51
    .word 0x81db604 @0x52
    .word 0x81db62a @0x53
    .word 0x81db63e @0x54
    .word 0x81db665 @0x55
    .word 0x81db677 @0x56
    .word 0x81db693 @0x57
    .word 0x81db6ab @0x58
    .word 0x81db6c3 @0x59
    .word 0x81db6d9 @0x5a
    .word 0x81db6f5 @0x5b
    .word 0x81db72c @0x5c
    .word 0x81db766 @0x5d
    .word 0x81db77b @0x5e
    .word 0x81db79d @0x5f
    .word bsc_attack_effect_hit @0x60
    .word 0x81db7bc @0x61
    .word 0x81db7fe @0x62
    .word 0x81db80f @0x63
    .word 0x81db815 @0x64
    .word bsc_attack_effect_hit @0x65
    .word 0x81db831 @0x66
    .word bsc_attack_effect_hit @0x67
    .word 0x81db876 @0x68
    .word 0x81db959 @0x69
    .word 0x81db964 @0x6a
    .word 0x81db996 @0x6b
    .word 0x81db9d0 @0x6c
    .word 0x81db9dd @0x6d
    .word bsc_attack_effect_hit @0x6e
    .word 0x81dbaa6 @0x6f
    .word 0x81dbab9 @0x70
    .word 0x81dbace @0x71
    .word 0x81dbae6 @0x72
    .word 0x81dbb27 @0x73
    .word 0x81dbaa6 @0x74
    .word 0x81dbb30 @0x75
    .word 0x81dbb4b @0x76
    .word 0x81dbba9 @0x77
    .word 0x81dbbc8 @0x78
    .word 0x81dbbe4 @0x79
    .word 0x81dbbf2 @0x7a
    .word 0x81dbbe4 @0x7b
    .word 0x81dbbfe @0x7c
    .word 0x81dbc07 @0x7d
    .word 0x81dbc12 @0x7e
    .word 0x81dbc25 @0x7f
    .word bsc_attack_effect_hit @0x80
    .word 0x81dbc52 @0x81
    .word 0x81dbc5d @0x82
    .word bsc_attack_effect_hit @0x83
    .word 0x81dbc8c @0x84
    .word 0x81dbc8c @0x85
    .word 0x81dbc8c @0x86
    .word 0x81dbc99 @0x87
    .word 0x81dbca0 @0x88
    .word 0x81dbcb8 @0x89
    .word 0x81dbcc1 @0x8a
    .word 0x81dbccc @0x8b
    .word 0x81dbcd7 @0x8c
    .word bsc_attack_effect_hit @0x8d
    .word 0x81dbce2 @0x8e
    .word 0x81dbd04 @0x8f
    .word 0x81dbd19 @0x90
    .word 0x81dbd2f @0x91
    .word 0x81dbd7e @0x92
    .word 0x81dbda3 @0x93
    .word 0x81dbe27 @0x94
    .word 0x81dbe3e @0x95
    .word 0x81dbe5d @0x96
    .word 0x81dbe73 @0x97
    .word 0x81dbec9 @0x98
    .word bsc_attack_effect_teleport //0x81dbedd @0x99
    .word 0x81dbf1a @0x9a
    .word 0x81dbf71 @0x9b
    .word 0x81dc01c @0x9c
    .word 0x81dc03e @0x9d
    .word 0x81dc06f @0x9e
    .word 0x81dc0a6 @0x9f
    .word 0x81dc0c6 @0xa0
    .word 0x81dc0d9 @0xa1
    .word 0x81dc11b @0xa2
    .word bsc_attack_effect_hit @0xa3
    .word 0x81dc138 @0xa4
    .word 0x81dc141 @0xa5
    .word 0x81dc15d @0xa6
    .word 0x81dc1bb @0xa7
    .word 0x81dc22f @0xa8
    .word 0x81dc2d2 @0xa9
    .word 0x81dc2ec @0xaa
    .word 0x81dc2fe @0xab
    .word 0x81dc328 @0xac
    .word 0x81dc339 @0xad
    .word 0x81dc346 @0xae
    .word 0x81dc357 @0xaf
    .word 0x81dc373 @0xb0
    .word 0x81dc388 @0xb1
    .word 0x81dc3b6 @0xb2
    .word 0x81dc3d2 @0xb3
    .word 0x81dc3e2 @0xb4
    .word 0x81dc3f9 @0xb5
    .word 0x81dc40e @0xb6
    .word 0x81dc419 @0xb7
    .word 0x81dc42e @0xb8
    .word 0x81dc443 @0xb9
    .word 0x81dc449 @0xba
    .word 0x81dc49a @0xbb
    .word 0x81dc4f3 @0xbc
    .word 0x81dc4fe @0xbd
    .word 0x81dc539 @0xbe
    .word 0x81dc53f @0xbf
    .word 0x81dc55b @0xc0
    .word 0x81dc570 @0xc1
    .word 0x81dc587 @0xc2
    .word 0x81dc59c @0xc3
    .word 0x81dc5b4 @0xc4
    .word 0x81dc5c4 @0xc5
    .word 0x81dc5ca @0xc6
    .word 0x81dc5d5 @0xc7
    .word 0x81dace5 @0xc8
    .word 0x81dc689 @0xc9
    .word 0x81dc6a0 @0xca
    .word 0x81dc6ab @0xcb
    .word 0x81dc6b1 @0xcc
    .word 0x81dc6bc @0xcd
    .word 0x81dc743 @0xce
    .word 0x81dc7a7 @0xcf
    .word 0x81dc7b5 @0xd0
    .word 0x81dac6c @0xd1
    .word 0x81dc689 @0xd2
    .word 0x81dc819 @0xd3
    .word 0x81dc891 @0xd4
    .word bsc_attack_effect_xd5 @0xd5, Tarnung??
    .word bsc_attack_effect_xd6 @0xd6
    .word bsc_attack_effect_xd7 @0xd7
    .word bsc_attack_effect_xd8 @0xd8
    .word bsc_attack_effect_xd9 @0xd9
    .word bsc_attack_effect_xda @0xda
    .word bsc_attack_effect_xdb @0xdb
    .word bsc_attack_effect_fire_fang @0xdc
    .word bsc_attack_effect_xdd @0xdd
    .word bsc_attack_effect_xde @0xde
    .word bsc_attack_effect_xdf @0xdf
    .word bsc_attack_effect_xe0 @0xe0
    .word bsc_attack_effect_xe1 @0xe1
    .word bsc_attack_effect_xe2 @0xe2
    .word 0x81dbaa6 @0xe3 kings shield
    .word bsc_attack_effect_sucker_punch @0xe4
    .word bsc_attack_effect_glyph_match @0xe5


bsc_attack_effect_xd5:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x58
    goto bsc_attack_effect_hit

bsc_attack_effect_xd6:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x59
    goto bsc_attack_effect_hit

bsc_attack_effect_xd7:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0xE6
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x3
    seteffectwithchancetarget
    faintpokemon 0x0 0x0 0x0
    attack_end ATTACK_END_MODE_ALL first_case=0
    end

bsc_attack_effect_xd8:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x57
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x5A
    seteffectwithchancetarget
    goto bsc_attack_effect_hit

bsc_attack_effect_xd9:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0xE6
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x3
    seteffectwithchancetarget
    goto bsc_faint_pokemon

bsc_attack_effect_xda:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x4
    goto bsc_effect_and_flinch

bsc_effect_and_flinch:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x8
    seteffectwithchancetarget
    goto bsc_faint_pokemon

bsc_attack_effect_xdb:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x5
    goto bsc_effect_and_flinch

bsc_attack_effect_fire_fang:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x3
    goto bsc_effect_and_flinch

bsc_attack_effect_xdd:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    jumpifbyte 0x4 attack_result 0x29 bsc_faint_pokemon
    jumpifstat 0x1 0x0 0x3 0x0 bsc_faint_pokemon
    setbyte 0x2023FDF 0x0
    playstatchangeanimation 0x1 0x8 0x9
    setbyte 0x2023FDE 0x93
    statbuffchange 0xC1 bsc_faint_pokemon
    printfromtable bsc_failure_strings
    waitmessage 0x40
    goto bsc_faint_pokemon

bsc_attack_effect_xde:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0xD7
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0xDA
    seteffectwithchancetarget
    goto bsc_faint_pokemon

bsc_attack_effect_xdf:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x45
    goto bsc_attack_effect_hit

bsc_attack_effect_xe0:
    jumpifhalfword 0x1 0x2023D4A 0x39 bsc_attack_effect_xe0_cont
    jumpifstatus3 0x0 0x40000 0x1 bsc_attack_effect_xe0_cont
    orword bsc_status_flags 0x40000
    setbyte 0x2023FD2 0x2
bsc_attack_effect_xe0_cont:
    attackcanceler
    accuracycheck bsc_miss_pp_reduce 0x0
    attackstring
    ppreduce
    calculatedamage
    attackanimation
    waitanimation
    missmessage
    hitanimation BANK_TARGET
    waitstate
    graphicalhpupdate 0x0
    datahpupdate 0x0
    critmessage
    waitmessage 0x40
    resultmessage
    waitmessage 0x40
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x4F
    seteffectwithchancetarget
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x50
    seteffectwithchancetarget
    faintpokemon 0x0 0x0 0x8000000
    attack_end ATTACK_END_MODE_ALL first_case=0
    end

bsc_attack_effect_xe1:
    attackcanceler
    attackstring
    ppreduce
    jumpifstat 0x1 0x3 0x4 0xC bsc_attack_effect_xe1_cont0
    jumpifstat 0x1 0x3 0x5 0xC bsc_attack_effect_xe1_cont0
    jumpifstat 0x1 0x0 0x3 0xC 0x81DC87D
bsc_attack_effect_xe1_cont0:
    attackanimation
    waitanimation
    setbyte 0x2023FDF 0x0
    playstatchangeanimation 0x0 0x38 0x0
    setbyte 0x2023FDE 0x14
    statbuffchange 0x41 bsc_attack_effect_xe1_cont1
    jumpifbyte 0x0 0x2023E87 0x2 bsc_attack_effect_xe1_cont1
    printfromtable bsc_failure_strings
    waitmessage 0x40
bsc_attack_effect_xe1_cont1:
    setbyte 0x2023FDE 0x15
    statbuffchange 0x41 bsc_attack_effect_xe1_cont2
    jumpifbyte 0x0 0x2023E87 0x2 bsc_attack_effect_xe1_cont2
    printfromtable bsc_failure_strings
    waitmessage 0x40
bsc_attack_effect_xe1_cont2:
    setbyte 0x2023FDE 0x13
    statbuffchange 0x41 0x81DABDE
    jumpifbyte 0x0 0x2023E87 0x2 0x81DABDE
    printfromtable bsc_failure_strings
    waitmessage 0x40
    goto bsc_miss_pp_reduce

bsc_attack_effect_xe2:
    setbyte battle_communication + BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE, 0x51
    goto bsc_attack_effect_hit

bsc_attack_effect_glyph_match:
    accuracycheck bsc_miss_pp_reduce 0x0
    callasm attack_calculate_damage_from_target_name
    goto bsc_attack_effect_after_accuracy_check

bsc_attack_effect_teleport:
    attackcanceler
    attackstring
    ppreduce
    jumpifword COMMON_BITS, battle_flags, (BATTLE_TRAINER), battlescript_attack_failed_no_pp_reduce
    getifcantrunfrombattle BANK_USER
    jumpifbyte EQUAL, battle_communication, 1, battlescript_attack_failed_no_pp_reduce
    jumpifbyte EQUAL, battle_communication, 2, battlescript_prevented_by_ability
    attackanimation
    waitanimation
    printstring 0xA0
    waitmessage 0x40
    callasm bsc_teleport_set_outcome
    goto battlescript_attack_end


bsc_attack_effect_roar:
	attackcanceler
	attackstring
	ppreduce
    callasm bsc_roar_failure
    goto 0x081daf44 // continue in the original script

bsc_roar_success_force_out:
    call bsc_roar_animation
    getswitchedmondata BANK_TARGET
    switchindataupdate BANK_TARGET
    switchinanim BANK_TARGET, 0
    waitstate
    printstring 0x154
    switchineffects BANK_TARGET
    goto battlescript_attack_end

bsc_roar_sucess_end_battle:
    call bsc_roar_animation
    callasm bsc_teleport_set_outcome
    finishaction

bsc_roar_animation:
    attackanimation
    waitanimation
    switchoutabilities BANK_TARGET
    returntoball BANK_TARGET
    waitstate
    return