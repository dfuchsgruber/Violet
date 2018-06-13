import core, symbols
from agb import agbrom
from pymap import project

symtbl = symbols.parse_symbols("bld/symbols")
rom = agbrom.Agbrom("bld/Pokemon Violet.gba")
symbols.verify_symbols(symtbl, rom)
proj = project.Project.load_project("proj.pmp")
core.index_species(symtbl, rom, proj)