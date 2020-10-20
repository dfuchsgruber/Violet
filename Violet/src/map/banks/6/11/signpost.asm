.include "overworld_script.s"
.include "callstds.s"

.global ow_script_bruchfels_crypt_sign

ow_script_bruchfels_crypt_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier ruht Roman, heldenhafter Beschüter der Stadt Bruchfels.\pMöge seine Seele ewigen Frieden finden und die Stadt unter dem Schutz seines Opfers vor allem Bösen bewahrt bleiben."
.elseif LANG_EN
.endif