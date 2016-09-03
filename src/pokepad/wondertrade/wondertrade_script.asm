.include "overworld_script.s"

.global script_wondertrade_failure

script_wondertrade_failure_s:
    loadpointer 0 str_wondertrade_not_possible_script
    callstd 6
    end


.align 4
script_wondertrade_failure:
    .word script_wondertrade_failure_s
