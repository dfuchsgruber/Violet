.include "battlescript.s"

.global bsc_wandlungskunst
.global bsc_stance_change

bsc_wandlungskunst:
animation 0 1 animk
pause 0x80
printstring 0x184
waitmessage 0x40
return
return

bsc_stance_change:
animation 0 1 animk
pause 0x80
return
