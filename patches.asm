.gba
.thumb
.open "C:/Users/Domi/Dropbox/Pokémon Violet/Pokemon Violet.gba",0x08000000

.include "patches/hooks.asm"

.org 0x091A8000
.importobj "bld/linked.o"
.close
