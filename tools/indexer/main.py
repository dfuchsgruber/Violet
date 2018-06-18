import core, symbols
from agb import agbrom
from pymap import project
from pokestring import pstring

symtbl = symbols.parse_symbols("bld/symbols")
rom = agbrom.Agbrom("bld/violet.gba")
symbols.verify_symbols(symtbl, rom)
proj = project.Project.load_project("proj.pmp")
ps = pstring.Pstring("charmap.txt")
core.index_species(symtbl, rom, proj, ps)