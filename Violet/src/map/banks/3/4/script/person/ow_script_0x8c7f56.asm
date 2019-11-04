.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8c7f56
ow_script_0x8c7f56:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
.global str_0x8f14e8
str_0:
    .autostring 34 2 "Ich vermisse Lucius, den ehemaligen Champion.\pEr war so charismatischDOTS\pVom neuen Champion weiß man nicht einmal, wer es überhaupt istDOTS"
        
.elseif LANG_EN
str_0:
    .autostring 34 2 "I really miss Lucius, the former champ.\pHe was so charismaticDOTS\pAbout the new champ one doesn't even know who he isDOTS"
.endif
