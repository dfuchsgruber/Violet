.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a89ae
ow_script_0x8a89ae:
trainerbattlestd 0x0 0xe 0x0 str_0x8aa83e str_0x8aa8fb
loadpointer 0x0 str_0x8aa8fb
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8aa83e

str_0x8aa83e:
    .string "Ich trainiere sehr hart, um eines\nTages Mitglied in Manus Arena\lwerden zu können. Meine Schläge\lmussen schnell und stark sein,\lmeine Tritte brauchen Wucht!\pIch zeige dir, wie man kämpft!"
        
        
.global str_0x8aa8fb

str_0x8aa8fb:
    .string "Großartige Kampftechnik! Hast du\nschonmal darüber nachgedacht, dich\lselbst dafür zu bewerben?"
        
        
.elseif LANG_EN

.endif
