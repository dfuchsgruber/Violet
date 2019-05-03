.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_ceometria_indoor_3_person_0
.global ow_script_ceometria_indoor_3_person_1

ow_script_ceometria_indoor_3_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_ceometria_indoor_3_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Dieser Teil Thetos wird von Narzissa regiert.\pSie ist eine makellose Frau."
str_1:
    .autostring 34 2 "Mein Freund himmelt Narizssa von den Top Vier an.\pEs sind alberne Fanatsien, solchen Personen anzuhängen."
.elseif LANG_EN
str_0:
    .autostring 34 2 "This part of Theto is governed by Narcissa.\pShe is a flawless woman."
str_1:
    .autostring 34 2 "My boyfriend whorships Narcissa of the Elite Four.\pBeing attached to such people is laughable."

.endif