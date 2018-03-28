.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87eb37
ow_script_0x87eb37:
loadpointer 0x0 str_0x87fba3
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x87fba3

str_0x87fba3:
    .string "Seit einigen Monaten sehe ich hier\nimmer öfter Revolutionäre in ihren\lsmaragdgrünen Roben.\pWas sie wohl hier wollen?"
        
        
.elseif LANG_EN

.endif
