.include "battlescript.s"

.global bsc_wandlungskunst
.global bsc_stance_change_to_attack
.global bsc_stance_change_to_defense

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
