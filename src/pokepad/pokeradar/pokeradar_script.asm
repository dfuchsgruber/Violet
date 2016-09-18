.include "overworld_script.s"

.global script_pokeradar
.global script_pokeradar_battle
.global script_pokeradar_alert
.global script_pokeradar_poschange
.global script_pokeradar_flee

script_pokeradar_s:
    pause 0x18
    checkflag 0x917
    gotoif 0 subscript_pokeradar_done
    fadescreen 1
    sound 0x27
    checksound
    sound 0x27
    checksound
    sound 0x27
    checksound
    compare 0x800D 1
    gotoif 1 subscript_pokeradar_empty
    compare 0x800D 3
    gotoif 1 subscript_pokeradar_no_grass
    compare 0x800D 2
    gotoif 1 subscript_pokeradar_unlucky
    copyvar 0x50EB 0x8000 //we update the species and level that was spawned
    copyvar 0x50EE 0x8001
    setvar 0x50E9 0
    hidesprite 254
    clearflag 0x917
    showsprite 254
    lockall
    fadescreen 0
    
    loadpointer 0 str_pokepad_pokeradar_found
    callstd 6
    end


subscript_pokeradar_done:
    loadpointer 0 str_pokepad_pokeradar_done
    callstd 6
    end

subscript_pokeradar_empty:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_empty
    callstd 6
    end

subscript_pokeradar_no_grass:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_no_grass
    callstd 6
    end   

subscript_pokeradar_unlucky:
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_unlucky
    callstd 6
    end   

script_pokeradar_battle:
    faceplayer
    cry 0x50EB 0
    waitcry
    special 0x13
    dowildbattle
    fadescreen 1
    hidesprite 254
    fadescreen 0
    end

script_pokeradar_alert_s:
    
    sound 0x15
    applymovement 254 script_pokeradar_movement_alert
    waitmovement 0
    loadpointer 0 str_pokepad_pokeradar_alert
    callstd 6
    fadescreen 1
    hidesprite 254
    fadescreen 0
    end

script_pokeradar_poschange_s:
    hidesprite 254
    clearflag 0x917
    showsprite 254
    random 0x4
    addvar 0x800D 0x52
    singlemovement 254 0x800D
    waitmovement 0
    singlemovement 254 0x800D
    waitmovement 0
    cry 0x50EB 0
    waitcry
    end

script_pokeradar_flee_s:
    cry 0x50EB 0
    fadescreen 1
    waitcry
    hidesprite 254
    fadescreen 0
    loadpointer 0 str_pokepad_pokeradar_flee
    callstd 6
    end

script_pokeradar_movement_alert:
    .byte 0x62, 0xFE

.align 4
script_pokeradar:
    .word script_pokeradar_s

.align 4
script_pokeradar_alert:
    .word script_pokeradar_alert_s

.align 4
script_pokeradar_poschange:
    .word script_pokeradar_poschange_s

.align 4
script_pokeradar_flee:
    .word script_pokeradar_flee_s

