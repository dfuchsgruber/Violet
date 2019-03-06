.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x889ff5
ow_script_0x889ff5:
loadpointer 0x0 str_0x8a062f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a062f

str_0x8a062f:
    .string "Feuer schlägt Wasser, Wasser\nschlägt Pflanze und Pflanze\lschlägt FeuerDOTS Nein, warte!DOTS"
        
        
.elseif LANG_EN

.endif
