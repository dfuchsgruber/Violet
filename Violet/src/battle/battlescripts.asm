.include "battlescript.s"
.include "constants/battle/battle_flags.s"

.global battlescript_trainer_battle_won

battlescript_trainer_battle_won:
    jumpifword COMMON_BITS battle_flags BATTLE_TWO_TRAINERS print_won_against_two_trainers
    printstring 0x141 // First trainer beaten
    goto after_trainer_battle_won_printstring
print_won_against_two_trainers:
    printstring 0x1A0
after_trainer_battle_won_printstring:
    trainerslidein BANK_USER
    waitstate
    printstring 0xC // Trainer defeat text
    pricemoney .+4
    printstring 0x1E
    waitmessage 0x40
    goto battlescript_payday_money_and_pickup

