.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e6a0
ow_script_0x95e6a0:
loadpointer 0x0 str_0x95eb93
callstd MSG_FACE
end

.global str_0x95eb93

str_0x95eb93:
    .string "Vor vielen Jahren haben Hexen hier\nBeschwörungsrituale abgehalten.\pDie Magie der Dunklen Königin soll\nin der Lage sein, das Landmassen-\lPokémon Groudon zu binden.\pWenn du mich fragst, ist hinter\ndiesem Hokus-Pokus nichts Wahres."
        
        