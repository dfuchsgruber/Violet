.include "overworld_script.s"
.include "callstds.s"

.global ow_script_silvania_wald_clouds_person_0
.global ow_script_silvania_wald_clouds_person_1

ow_script_silvania_wald_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_silvania_wald_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier hat einst ein monumentales Bauwerk gestanden.\pEs muss sich um eine Art Tempel gehandelt habenDOTS\pWem die Ziviliastion, die ihn erbaut hat, wohl huldigte?"
str_1:
    .autostring 34 2 "Der Zeitwald ist ein magischer Ort.\pSelbst hier, weit darüber, kann man seine Aura noch spürenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Once a monumental building must have been at this very place.\pIt must have been a temple of some sortDOTS\pI wonder whom the ancient civilization that built it must have woreshipedDOTS"
str_1:
    .autostring 34 2 "The time forest is a magical place.\pEven here, way above it, you can feel its auraDOTS"

.endif