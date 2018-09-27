.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x81035a
ow_script_0x81035a:
loadpointer 0 str_police
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8c8eab
callstd MSG_FACE
special 0xF
end


.ifdef LANG_GER
str_police:
	.string "Polizist"

.global str_0x8c8eab

str_0x8c8eab:
    .autostring 35 2 "Solange sich der Anführer der Revolutionsbewegung hier rumtreibt, haben wir strikte Anordnung, niemanden vorbeizulassen.\pWir riegeln die Stadt ab!"
        
        
.elseif LANG_EN

.endif
