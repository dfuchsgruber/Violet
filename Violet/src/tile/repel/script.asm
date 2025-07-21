.include "overworld_script.s"

.global script_repel_wore_off

script_repel_wore_off:
    lockall
    loadpointer 0 str_repel_wore_off
    callstd 4
    setvar 0x8004 0x54
    call use_repel
    setvar 0x8004 0x53
    call use_repel
    setvar 0x8004 0x56
    call use_repel
    closeonkeypress
    releaseall
    end
    


use_repel:
    checkitem 0x8004 1
    bufferitem 0 0x8004
    compare 0x800D 0
    gotoif 1 ret_use_same
    loadpointer 0 str_repel_renew
    callstd 5
    compare 0x800D 1
    gotoif 1 use
    closeonkeypress
    releaseall
    end

    ret_use_same:
    return

use:
    removeitem 0x8004 1
    copyvar 0x800E 0x8004
    sound 0x29
    special 0x48
    loadpointer 0 str_repel_use
    callstd 3
    releaseall
    end

@ // String

.ifdef LANG_GER

	str_repel_wore_off:
		.string "Schutz wirkt nicht mehr..."

	str_repel_renew:
		.string "BUFFER_1 einsetzen?"

	str_repel_use:
		.string "PLAYER setzt\nBUFFER_1 ein."

.elseif LANG_EN

	str_repel_wore_off:
		.string "Repel’s effect wore off..."

	str_repel_renew:
		.string "Use BUFFER_1?"

	str_repel_use:
		.string "PLAYER uses\nBUFFER_1."

.endif
