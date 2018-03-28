.include "overworld_script.s"

.include "std.s"

.global ow_script_0x959462
ow_script_0x959462:
checkflag ORINA_CITY_VIOLET_GRUNTS
gotoif EQUAL ow_script_0x959475
loadpointer 0x0 str_0x95a56d
callstd MSG_SIGN
end


.global ow_script_0x959475
ow_script_0x959475:
loadpointer 0x0 str_0x95a56d
callstd MSG_SIGN
loadpointer 0x0 str_0x959487
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x95a56d

str_0x95a56d:
    .string "QUOTEDas Magmaherz - die Essenz der\nErde und LandmassenQUOTE"
        
        
.global str_0x959487

str_0x959487:
    .string "... Das Schild wurde\ndurchgestrichen ..."
        
        
.elseif LANG_EN

.endif
