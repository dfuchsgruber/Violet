.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89aaba
ow_script_0x89aaba:
loadpointer 0x0 str_0x9278f8
callstd MSG_FACE
end

.global str_0x9278f8

str_0x9278f8:
    .string "Im Fernsehen laufen stets\ninteressante Dinge. Nicht zuletzt,\lweil das Programm so vielfältig\list.\pWirf doch auch das eine oder\nandere Mal einen Blick auf einen\lFernseher, vielleicht gefällt dir,\lwas du siehst."
        
        