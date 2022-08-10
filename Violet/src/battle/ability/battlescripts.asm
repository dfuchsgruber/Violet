.include "battlescript.s"
.include "constants/pokemon_stat_names.s"
.include "constants/battle/battle_statuses.s"
.include "constants/abilities.s"
.include "constants/battle/battle_communication.s"
.include "constants/battle/battle_animations.s"

.global bsc_wandlungskunst
.global bsc_stance_change_to_attack
.global bsc_stance_change_to_defense
.global bsc_ap_sparer
.global bsc_life_orb
.global bsc_lernfaehig
.global bsc_hochmut
.global bsc_lebensraeuber
.global bsc_curator
.global bsc_extradorn
.global bsc_kings_shield_drop
.global bsc_hagelalarm
.global bsc_ability_inflicts_damage
.global bsc_heal
.global bsc_tollwut
.global bsc_lucid
.global bsc_robustheit
.global bsc_harvest
.global bsc_hack
.global bsc_fluffy
.global bsc_eschat
.global bsc_gegenwind
.global bsc_gegenwind_end3
.global bsc_flinch_aura
.global bsc_flinch_raura
.global bsc_flinch_baura
.global bsc_flinch_gaura
.global bsc_tintenschuss
.global bsc_giftnebel
.global bsc_giftnebel_end3
.global bsc_letzte_glocke
.global bsc_letzte_glocke_end3


bsc_wandlungskunst:
printstring 0x184
waitmessage 0x40
return

bsc_stance_change_to_attack:
printstring 0x188
waitmessage 1
playanimation BANK_SCRIPTING BATTLE_ANIM_STANCE_CHANGE 0
printstring 0x18b
waitmessage 0x40
return

bsc_stance_change_to_defense:
printstring 0x188
waitmessage 1
playanimation BANK_SCRIPTING BATTLE_ANIM_STANCE_CHANGE 0
printstring 0x18c
waitmessage 0x40
return

bsc_ap_sparer:
printstring 0x18A
waitmessage 0x40
return


bsc_lernfaehig:
//callasm attack_done_prepeare_lernfaehig
playanimation BANK_USER, 0x1, battle_scripting + 16
printstring 0x186
waitmessage 0x40
return

bsc_hochmut:
//callasm attack_done_prepeare_hochmut
playanimation BANK_USER 0x1 battle_scripting + 16
printstring 0x189
waitmessage 0x40
return

bsc_lebensraeuber:
//callasm attack_done_prepeare_lebensraeuber
graphicalhpupdate 0x1
datahpupdate 0x1
printstring 0x133
waitmessage 0x40
return

bsc_curator:
//callasm attack_done_prepeare_curator
graphicalhpupdate 0x1
datahpupdate 0x1
printstring 0x133
waitmessage 0x40
return

bsc_extradorn:
battleanimation 0 1 0x81cbd12
pause 0x40
// callasm attack_done_prepeare_extradorn
orword bsc_status_flags 0x100100
graphicalhpupdate 0x0
datahpupdate 0x0
printstring 0x193
waitmessage 0x40
faintpokemon 0x0 0x0 0x8000000
return

bsc_kings_shield_drop:
callasm kings_shield_prepeare_drop
playanimation BANK_USER 0x1 battle_scripting + 16
printstring 0x194
waitmessage 0x40
return

bsc_hagelalarm:
pause 0x20
printstring 0x187
waitstate
playanimation 0x7 0xD 0x0
call bsc_form_changes_by_weather
end3

bsc_ability_inflicts_damage:
    printstring 0x182
    waitmessage 0x40
    orword bsc_status_flags 0x100
    graphicalhpupdate 1
    datahpupdate 1
    faintpokemon BANK_USER, 0, 0
    atk24 .+4
    end3

bsc_heal:
printstring 0x195
waitmessage 0x40
orword 0x02023DD0 0x100
graphicalhpupdate 1
datahpupdate 1
end3


bsc_tollwut:
    backup_user BACKUP_STORE
    copyarray attacking_battler BATTLE_SCRIPTING_BATTLER_IDX 1
    jumpifability BANK_USER NEUTRALTORSO tollwut_failed
    jumpifability BANK_USER PULVERRAUCH tollwut_failed
    setstatchange STAT_ATTACK 1 0
    statbuffchange STAT_BUF_CHANGE_AFFECTS_USER | STAT_BUF_IGNORE_PROTECT | STAT_BUF_CHANGE_FAILURE_CONTINUATION, tollwut_failed
    jumpifbyte GREATER_THAN battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER 1 tollwut_failed
    printstring 0x196
    setgraphicalstatchangevalues
    playanimation BANK_USER ANIMATION_STAT_CHANGE ANIMATION_ARG_0
    printfromtable bsc_string_table_stat_changes
    waitmessage 0x40
    setstatchange STAT_DEFENSE 2 1
    statbuffchange STAT_BUF_CHANGE_AFFECTS_USER | STAT_BUF_IGNORE_PROTECT | STAT_BUF_CHANGE_FAILURE_CONTINUATION, tollwut_failed
    jumpifbyte GREATER_THAN battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER 1 tollwut_lower_special_defense
    setgraphicalstatchangevalues
    playanimation BANK_USER ANIMATION_STAT_CHANGE ANIMATION_ARG_0
    printfromtable bsc_string_table_stat_changes
    waitmessage 0x40
tollwut_lower_special_defense:
    setstatchange STAT_SPECIAL_DEFENSE 2 1
    statbuffchange STAT_BUF_CHANGE_AFFECTS_USER | STAT_BUF_IGNORE_PROTECT | STAT_BUF_CHANGE_FAILURE_CONTINUATION, tollwut_failed
    jumpifbyte GREATER_THAN battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER 1 tollwut_failed
    setgraphicalstatchangevalues
    playanimation BANK_USER ANIMATION_STAT_CHANGE ANIMATION_ARG_0
    printfromtable bsc_string_table_stat_changes
    waitmessage 0x40
tollwut_failed:
    backup_user BACKUP_RESTORE
    end3

bsc_turn_end_statchange:
    statbuffchange 0x41 0x81DAEED
    jumpifbyte 0x3 0x2023E87 0x2 bsc_turn_end_stat_change_success
    jumpifbyte 0x0 0x2023E87 0x3 bsc_turn_end_stat_change_failure
    printfromtable 0x83FE534
    waitmessage 0x40
    return

bsc_turn_end_stat_change_success:
    setgraphicalstatchangevalues
    playanimation BANK_USER 0x1 battle_scripting + 16
    printfromtable 0x83FE534
    waitmessage 0x40
    bsc_turn_end_stat_change_failure:
    return

bsc_lucid:
printstring 0x18E
waitmessage 0x40
setbyte bsc_status_effect_to_apply 0x14
call bsc_turn_end_statchange
end3

bsc_robustheit:
printstring 0x18D
waitmessage 0x40
return

bsc_harvest:
recycleitem bsc_harvest_fail
printstring 0x197
waitmessage 0x40
bsc_harvest_fail:
end3

bsc_hack:
jumpifsecondarystatus 0 0x10000 bsc_hack_fail
setincreasedcriticalchance
printstring 0x198
waitmessage 0x40
bsc_hack_fail:
end3

bsc_fluffy:
    playanimation BANK_USER 0x1 battle_scripting + 16
    printstring 0x199
    waitmessage 0x40
    return

bsc_tintenschuss:
    printstring 0x1b0
    playanimation BANK_USER BATTLE_ANIM_INK_SHOT 0
    playanimation BANK_USER 0x1 battle_scripting + 16
    printstring 0x1b1
    waitmessage 0x40
    return



bsc_eschat:
printstring 0x19A
waitmessage 0x40
setstatchange STAT_ACCURACY 1 0
call bsc_turn_end_statchange
setstatchange STAT_EVASION 1 0
call bsc_turn_end_statchange
end3

bsc_gegenwind_end3:
    call bsc_gegenwind_pause
    end3
bsc_gegenwind_pause:
    pause 0x20
bsc_gegenwind:
    setbyte defending_battler 0 // Target for "Gegenwind"
    setstatchange STAT_SPEED 2 1
bsc_gegenwind_loop:
    intimidate_try_get_target bsc_gegenwind_return
    jumpifsecondarystatus BANK_TARGET STATUS2_SUBSTITUTE bsc_gegenwind_loop_increment
    jumpifability BANK_TARGET NEUTRALTORSO gegenwind_failed
    jumpifability BANK_TARGET PULVERRAUCH gegenwind_failed
    statbuffchange STAT_BUF_IGNORE_PROTECT | STAT_BUF_CHANGE_FAILURE_CONTINUATION bsc_gegenwind_loop_increment
    jumpifbyte GREATER_THAN battle_communication + BATTLE_COMMUNICATION_MULTISTRING_CHOOSER 1 bsc_gegenwind_loop_increment
    setgraphicalstatchangevalues
    playanimation BANK_TARGET ANIMATION_STAT_CHANGE ANIMATION_ARG_0
    printstring 0x19B
    waitmessage 0x40
bsc_gegenwind_loop_increment:
	addbyte defending_battler 1
	goto bsc_gegenwind_loop
bsc_gegenwind_return:
    return
gegenwind_failed:
    pause 0x20
    printstring 0xce
    waitmessage 0x40
    goto bsc_gegenwind_loop_increment

bsc_flinch_aura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x18F
    waitmessage 0x40
    goto 0x81DABDE

bsc_flinch_raura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x190
    waitmessage 0x40
    goto 0x81DABDE

bsc_flinch_baura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x191
    waitmessage 0x40
    goto 0x81DABDE

bsc_flinch_gaura:
    attackstring
    ppreduce
    pause 0x20
    printstring 0x192
    waitmessage 0x40
    goto 0x81DABDE

bsc_giftnebel_end3:
    call bsc_giftnebel_pause
    end3
bsc_giftnebel_pause:
    pause 0x20
bsc_giftnebel:
    setbyte defending_battler 0 // Target for "giftnebel"
bsc_giftnebel_loop:
    intimidate_try_get_target bsc_giftnebel_return
    jumpifsecondarystatus BANK_TARGET STATUS2_SUBSTITUTE bsc_giftnebel_loop_increment
    printstring 0x1c9
    waitmessage 0x40

    setbattleeffect BATTLE_EFFECT_POISON
    seteffectprimary
bsc_giftnebel_loop_increment:
	addbyte defending_battler 1
	goto bsc_giftnebel_loop
bsc_giftnebel_return:
    return

bsc_letzte_glocke_end3:
    call bsc_letzte_glocke_pause
    end3
bsc_letzte_glocke_pause:
    pause 0x20
bsc_letzte_glocke:
    printstring 0x1ca
    waitmessage 0x40
    playanimation BANK_SCRIPTING, BATTLE_ANIM_PERISH_BELL, 0
    printstring 254
    waitmessage 0x40
    setbyte defending_battler, 0 // Target for ability
bsc_letzte_glocke_loop:
    setperishsongnoattack bsc_letzte_glocke_unaffected
bsc_letzte_glocke_loop_increment:
    addbyte defending_battler, 1
    jumpifarraynotequal defending_battler, battler_cnt, 1 bsc_letzte_glocke_loop 
bsc_letzte_glocke_return:
    return

bsc_letzte_glocke_unaffected:
    printstring 0x1cb
    waitmessage 0x40
    goto bsc_letzte_glocke_loop_increment