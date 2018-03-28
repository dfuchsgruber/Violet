.include "overworld_script.s"

.include "std.s"

.global ow_script_0x858de3
ow_script_0x858de3:
loadpointer 0x0 str_0x966059
callstd MSG_FACE
end

.global str_0x966059

str_0x966059:
    .string "Kann man das, was sie im Fernsehen\nzeigen, überhaupt noch als Sendung\lbezeichnen?\pIch habe viel mehr das Gefühl,\npermament der Werbung ausgesetzt\lzu sein."
        
        