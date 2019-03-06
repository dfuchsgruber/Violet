.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x916cb3
ow_script_0x916cb3:
trainerbattlestd 0x0 0x75 0x0 str_0x935cc0 str_0x935d50
loadpointer 0x0 str_0x935d50
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x935cc0

str_0x935cc0:
    .string "Ich trainiere, um den Arenaorden\nvon Manus zu erringen.\pDann kann ich endlich die\nVersteckte Maschine Fliegen\laußerhalb des Kampfes benutzen!"
        
        
.global str_0x935d50

str_0x935d50:
    .string "Ich muss stärker werden!\nManus, mach dich gefasst!"
        
        
.elseif LANG_EN

.endif
