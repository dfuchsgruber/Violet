.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x810363
ow_script_0x810363:
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8c8f0d
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
str_police:
	.string "Polizist"

str_0x8c8f0d:
    .string "Lord Faun wird den Revolutionären\nzeigen, wie stark ein Mitglied der\lTop Vier ist!"
        
        
.elseif LANG_EN

.endif
