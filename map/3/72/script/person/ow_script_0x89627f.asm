.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x89627f
ow_script_0x89627f:
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d4bd
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x89d4bd

str_0x89d4bd:
    .string "PLAYER, ich werde meine Antworten\nnoch mit meinen Aufzeichnungen\lvergleichen.\pDu kannst aber ruhig schon\neinmal vorgehen!"
        
        
.elseif LANG_EN

.endif
