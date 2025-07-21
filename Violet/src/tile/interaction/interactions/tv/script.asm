.include "overworld_script.s"
.include "callstds.s"

.global ow_script_tv

ow_script_tv:
    callasm load_tv_text
    callstd MSG_SIGN
    end