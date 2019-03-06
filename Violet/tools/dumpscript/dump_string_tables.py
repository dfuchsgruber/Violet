#!/usr/bin/python3
import agb.agbrom
import pokestring.pstring

rom = agb.agbrom.Agbrom("../../base/bprd.gba")
ps = pokestring.pstring.Pstring("../../charmap.txt")
str_tables_off = 0x3EC72C
num_str_tables = 22

for i in range(num_str_tables):
    if i == 0: continue # The first one isnt really a table...
    table_off = str_tables_off + 8 * i
    entries = rom.pointer(table_off)
    size = rom.u16(table_off + 4)
    
    output = '.align 4\n\n'
    output += '.global string_table_' + str(i) + '\n'
    output += 'string_table_' + str(i) + ':\n'
    output += '\t.word entries\n'
    output += '\t.hword ' + str(size) + ', ' + str(rom.u16(table_off + 6)) + '\n\n'

    output += 'entires:\n'
    strings = ''

    # Dump the table itself
    for j in range(size):
        entry_off = entries + 12 * j
        text = rom.pointer(entry_off)
        width = rom.pointer(entry_off + 4)
        height = rom.pointer(entry_off + 8)
        output += '.word ' + ','.join(('string_' + str(j), str(width), str(height))) + '\n'
        strings += 'string_' + str(j) + ':'
        strings += '\t.string "' + ps.hex2str(rom, text) + '"\n\n'

    output += '\n' + strings
    with open('string_table_' + str(i) + '.asm', 'w+') as f:
        f.write(output)


