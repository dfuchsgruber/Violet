.include "overworld_script.s"



.global access_card_element_names

.align 4
access_card_element_names:
    .word access_card_element_names_r

.align 4
access_card_element_names_r:
    .word str_access_card_cyber
    .word str_access_card_fossil
    .word str_access_card_atrium


