.include "battlescript.s"

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
.global bsc_recoil
.global bsc_heal
.global bsc_tollwut
.global bsc_tollwut_attack_boost
.global bsc_lucid
.global bsc_robustheit
.global bsc_harvest
.global bsc_hack
.global bsc_fluffy

bsc_wandlungskunst:
printstring 0x184
waitmessage 0x40
return

bsc_stance_change_to_attack:
printstring 0x188
waitmessage 1
animation 1 1 attack_anim_stance_change
pause 0x100
printstring 0x18b
waitmessage 0x40
return

bsc_stance_change_to_defense:
printstring 0x188
waitmessage 1
animation 1 1 attack_anim_stance_change
pause 0x100
printstring 0x18c
waitmessage 0x40
return

bsc_ap_sparer:
printstring 0x18A
waitmessage 0x40
return

bsc_life_orb:
callasm attack_done_prepeare_life_orb
orword 0x2023DD0 0x100100
graphicalhpupdate 0x1
datahpupdate 0x1
printstring 0x183
waitmessage 0x40
faintpokemon 0x1 0x0 0x8000000
return


bsc_lernfaehig:
callasm attack_done_prepeare_lernfaehig
playanimation 0x1 0x1 0x2023FD4
printstring 0x186
waitmessage 0x40
return

bsc_hochmut:
callasm attack_done_prepeare_hochmut
playanimation 0x1 0x1 0x2023FD4
printstring 0x189
waitmessage 0x40
return

bsc_lebensraeuber:
callasm attack_done_prepeare_lebensraeuber
graphicalhpupdate 0x1
datahpupdate 0x1
printstring 0x133
waitmessage 0x40
return

bsc_curator:
callasm attack_done_prepeare_curator
graphicalhpupdate 0x1
datahpupdate 0x1
printstring 0x133
waitmessage 0x40
return

bsc_extradorn:
animation 1 0 0x81cbd12
pause 0x40
callasm attack_done_prepeare_extradorn
orword 0x2023DD0 0x100100
graphicalhpupdate 0x0
datahpupdate 0x0
printstring 0x193
waitmessage 0x40
faintpokemon 0x0 0x0 0x8000000
return

bsc_kings_shield_drop:
callasm kings_shield_prepeare_drop
playanimation 0x1 0x1 0x2023FD4
printstring 0x194
waitmessage 0x40
return

bsc_hagelalarm:
pause 0x20
printstring 0x187
waitstate
playanimation 0x7 0xD 0x0
call 0x81DD572
end3

bsc_recoil:
printstring 0x182
waitmessage 0x40
orword 0x02023DD0 0x100
graphicalhpupdate 1
datahpupdate 1
end3

bsc_heal:
printstring 0x195
waitmessage 0x40
orword 0x02023DD0 0x100
graphicalhpupdate 1
datahpupdate 1
end3


bsc_tollwut:
printstring 0x196
waitmessage 0x40
callasm turn_end_tollwut_attack_boost
setbyte 0x2023FDE 0x92
call bsc_turn_end_statchange
setbyte 0x2023FDE 0x95
call bsc_turn_end_statchange
end3

bsc_turn_end_statchange:
statbuffchange 0x41 0x81DAEED
jumpifbyte 0x3 0x2023E87 0x2 bsc_turn_end_stat_change_success
jumpifbyte 0x0 0x2023E87 0x3 bsc_turn_end_stat_change_failure
printfromtable 0x83FE534
waitmessage 0x40
return

bsc_turn_end_stat_change_success:
cmd47
playanimation 0x1 0x1 0x2023FD4
printfromtable 0x83FE534
waitmessage 0x40
bsc_turn_end_stat_change_failure:
return

bsc_tollwut_attack_boost:
setbyte 0x2023FDE 0x11
call bsc_turn_end_statchange
return


bsc_lucid:
printstring 0x18E
waitmessage 0x40
setbyte 0x2023FDE 0x14
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
playanimation 0x1 0x1 0x2023FD4
printstring 0x199
waitmessage 0x40
return

