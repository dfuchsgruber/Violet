.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8ca7be
ow_script_movs_0x8ca7be:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8ca6a6
ow_script_0x8ca6a6:
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8ca6c5
callstd MSG_FACE
special 0x7
applymovement 0x800f ow_script_movs_0x8ca7be
waitmovement 0x0
hidesprite 0x800f
end


.global ow_script_0x8c09e6
ow_script_0x8c09e6:
setvar 0x8000 0x0
setvar 0x8001 0xd
setvar 0x8002 0xf
special 0x6
return

.global str_0x8ca6c5

str_0x8ca6c5:
    .string "Ah, PLAYER. Du hast also zum Tempel\ngefunden.\lFrüher einmal war dieser Ort ein\lriesiges Bauwerk, doch hat die\lWelle den Tempel nahezu zerstört.\lGemeinsam mit Manus aus Meriana\lCity habe ich im Untergrund eine\lKampfarena errichtet. Wir sehen\luns dort."
        
        