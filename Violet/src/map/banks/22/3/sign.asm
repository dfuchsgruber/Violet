.include "overworld_script.s"
.include "callstds.s"

.global ow_script_felsige_oednis_gible_cave_sign

ow_script_felsige_oednis_gible_cave_sign:
    loadpointer 0 str_0
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Dieser Ort ist meinem treuen Freund und Partner geweiht, der im Kampf gegen den Drachen, der sie einst bewohnte, sein Leben gegeben hat.\pDein auf ewig dankbarer Freund.\n - Lucius."
.elseif LANG_EN
.endif