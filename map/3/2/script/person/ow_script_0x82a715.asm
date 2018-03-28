.include "overworld_script.s"

.include "std.s"

.global ow_script_0x82a715
ow_script_0x82a715:
loadpointer 0x0 str_0x8470f4
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8470f4

str_0x8470f4:
    .string "Früher einmal lebten ich und meine\nFamilie gemeinsam auf dieser\lInsel. Nachdem der Meteor jedoch\leingeschlagen hat, sind mein Sohn\lund meine Enkel nach Kaskada\lgezogen."
        
        
.elseif LANG_EN

.endif
