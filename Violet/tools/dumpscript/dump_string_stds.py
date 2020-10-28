#!/usr/bin/env python3

import agb.agbrom
import pokestring.pstring

rom = agb.agbrom.Agbrom("../../bld/violet.gba")
ps = pokestring.pstring.Pstring("../../charmap.txt")
base = 0x3DFBA8
num_strs = 29

for i in range(num_strs):
    output = '.align 4\n\n.global string_stds\nstring_stds:\n\n'
    strings = ''
    for i in range(num_strs):
        off = base + 4 * i
        text = ps.hex2str(rom, rom.pointer(off))
        text = text[0] + text[1:].lower()
        output += '\t.word string_' + str(i) + '\n'
        strings += 'string_' + str(i) + ':\n\t.string "' + text + '"\n\n'

    output += '\n' + strings
    with open('string_table_' + str(i) + '.asm', 'w+') as f:
        f.write(output)

