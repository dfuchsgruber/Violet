.include "battlescript.s"

.global bsc_attack_effect_sucker_punch

bsc_attack_effect_sucker_punch:
callasm bsc_sucker_punch_cancel
goto bsc_attack_effect_hit
