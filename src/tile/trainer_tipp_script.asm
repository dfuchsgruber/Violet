.include "overworld_script.s"

.global script_trainer_tipp_fp_menu
.global script_trainer_tipp_wondertrade
.global script_trainer_tipp_pokeradar
.global script_trainer_tipp_habitat
.global script_trainer_tipp_dns
.global script_trainer_tipp_cloud


script_trainer_tipp_cloud:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_cloud
    callstd 3
    releaseall
    end

script_trainer_tipp_wondertrade:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_wondertrade
    callstd 3
    releaseall
    end
    

script_trainer_tipp_fp_menu:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_fp_menu
    callstd 3
    releaseall
    end

script_trainer_tipp_pokeradar:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_pokeradar
    callstd 3
    releaseall
    end

script_trainer_tipp_habitat:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_habitat
    callstd 3
    releaseall
    end

script_trainer_tipp_dns:
    lockall
    sound 366
    loadpointer 0 str_trainer_tipp_dns
    callstd 3
    releaseall
    end

