.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8ecd0e
ow_script_0x8ecd0e:
loadpointer 0x0 str_0x92d0bb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x92d0bb

str_0x92d0bb:
    .string "Der Küstenberg ist seither bekannt\nfür seine reinen Quellen, die den\lganzen Kontinent mit Wasser\lversorgen.\pDas Meerwasser wird im Laufe der\nJahrtausende vom Gestein\lgesäubert."
        
        
.elseif LANG_EN

.endif
