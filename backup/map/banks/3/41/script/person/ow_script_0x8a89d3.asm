.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a89d3
ow_script_0x8a89d3:
trainerbattlestd 0x0 0xf 0x0 str_0x8aaad4 str_0x8aab7f
loadpointer 0x0 str_0x8aab7f
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8aaad4

str_0x8aaad4:
    .string "Als Ranger muss man stets den\nÜberblick behalten. Wir trainieren\ldie verschiedensten Pokémon, um\lfür jede Situation gewappnet zu\lsein. In der Vielfalt liegt die\lStärke!"
        
        
.global str_0x8aab7f

str_0x8aab7f:
    .string "Achte darauf, möglichst viele\nverschiedene Typen in deinem\lPokémon-Team unterzubringen."
        
        
.elseif LANG_EN

.endif
