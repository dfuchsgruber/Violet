.include "overworld_script.s"

.include "std.s"

.global ow_script_0x949d92
ow_script_0x949d92:
lockall
fadesong MUS_0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x94d7a4
callstd MSG
special 0x7
playsong MUS_ROUTE_3_10_AND_ROUTE_16_22 0x0
addvar STORY_PROGRESS 0x1
releaseall
end

.global str_0x94d7a4

str_0x94d7a4:
    .string "Ich hatte erneut eine Vision, wie\nich sie auch von der Zerstörung\lAktanias hatte...\pNur war etwas anders...\nFaun und Larissa, sie haben beide\lso anders gewirkt...\pÄlter... Gezeichnet von etwas\nSchrecklichem!\p... ... ...\nWäre es möglich, dass diese Bilder\lder Zukunft entstammen?\lWo ich doch die Vergangenheit\lsehen konnte...\pWenn ich mit meiner Vermutung\nRecht habe, schwebt diese Welt in\lgroßer Gefahr.\pIch muss herausfinden, was es mit\nall dem auf sich hat."
        
        