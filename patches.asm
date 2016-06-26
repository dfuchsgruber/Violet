.gba
.thumb
.open "C:/Users/Domi/Dropbox/Pokémon Violet/Pokemon Violet.gba",0x08000000

.include "patches/hooks.asm"
.include "patches/music.asm"
.include "patches/overworld.asm"

.org 0x09680000
.importobj "bld/linked.o"
.close
