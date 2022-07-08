.include "overworld_script.s"
.include "callstds.s"

.global ow_script_basis_trockentag_trainer_cryptic_0

ow_script_basis_trockentag_trainer_cryptic_0:
    trainerbattlestd 0 0x1fd 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "W-Was machst du hier?\pIch habe diese Ruinen vor dir gefunden!"
str_after_0:
    .autostring 34 2 "So ein Mist!\pIch hatte die Schrift auf dem Stein fast entschlüsseltDOTS"
str_later_0:
    .autostring 34 2 "Diese SchriftzeichenDOTS\pIch habe mein ganzes Leben dafür gelernt, sie entziffern zu können.\pAber jetzt hilft mir das auch nicht weiter."
.elseif LANG_EN
.endif