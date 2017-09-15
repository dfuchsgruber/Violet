import agb
import pymap
import img_dump
import sys
import getopt
import os
from pymap import mapfooter, mapheader, mapevent, tileset, project, mapconnection, config
import owscript
import json
import constants
import pysetex



ROM_STD = "VIOLET"
DEFAULT_TABLE = config.MAPTABLEPTR
STDTILESETEXPORT = (lambda rom, off, proj: hex(off))
STDSCRIPTEXPORT = (lambda rom, off, path, prefix: hex(off))


def _flatten(l):
    return [item for sub in l for item in sub]

def _mkdirs(dir):
    if not os.path.exists(dir):
        os.makedirs(dir)

def main(args):
    """ Shell interface for the exporter """
    try:
        opts, args = getopt.getopt(args, "hb:m:s:t:p:c:y:o:", ["help", "deleteanim", "pedantic"])
    except getopt.GetoptError:
        sys.exit(2)
    rom = None
    bank = None
    map = None
    offset = None
    table = DEFAULT_TABLE
    tsp = None
    tss = None
    basepath = None
    symbol = None
    pedantic = False

    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print("""Usage: python pymapex.py [args] rom project
            -b {bank}\t\tMap bank to export from
            -m {map}\t\tMap number inside bank to export
            -t {table}\t\tMapbank table offset
            -s {offset}\t(Optional) export mapheader from ceratin offset (overrides -b, -m and -t)
            -p {symbol}\tSymbol of primary tileset. If not defined the tileset will be exported
            -c {symbol}\tSymbol of secondary tileset. If not defined the tileset will be exported
            -y {symbol}\tBase symbol (e.g. if symbol equals 'foo' then global symbols for mapheader, footer, etc. will be 'mapheader_foo', 'mapfooter_foo', etc.)
            --pedantic\t\tPedantic export for constants (if a constant is not defined it will abort exporting)
            """)
            return
        elif opt in ("-b"): bank = int(arg, 0)
        elif opt in ("-m"): map = int(arg, 0)
        elif opt in ("-t"): table = int(arg, 0)
        elif opt in ("-s"): offset = int(arg, 0)
        elif opt in ("-p"): tsp = arg
        elif opt in ("-c"): tss = arg
        elif opt in ("-y"): symbol = arg
        elif opt in ("-o"): basepath = arg
        elif opt in ("--pedantic"): pedantic = False


    try: rom = args[0]
    except: raise Exception("No input rom specified (see --help)")
    try: projfile = args[1]
    except: raise Exception("No project file specified (see --help)")
    if rom == ROM_STD: rom = agb.STDPATH
    rom = agb.Agbrom(path=rom) #Open rom

    if not basepath: raise Exception("No output path specified!")

    if bank == None: raise Exception("No bank specified")
    if map == None: raise Exception("No map specified")
    if offset == None:
        #Try to process the table
        if table == None: raise Exception("No table specified!")
        offset = rom.pointer(rom.pointer(rom.pointer(table) + 4 * bank) + 4 * map)

    proj = project.Project.load_project(projfile)
    header = export_map(rom, offset, tsp, tss, symbol, basepath, proj, STDSCRIPTEXPORT, STDTILESETEXPORT, pedantic=pedantic)
    proj.save_map(bank, map, header, basepath + ".pmh")
    proj.save_project()

def export_connections(rom: agb.Agbrom, offset, basepath, pedantic=False):
    """ Exports the map connections """
    count = rom.u32(offset)
    connections = [mapconnection.Mapconnection() for i in range(count)]
    base = rom.pointer(offset + 4)
    for i in range(count):
        offset = base + 12 * i
        direction = rom.u32(offset)
        connections[i].direction = constants.map_connection(direction, pedantic=pedantic)
        connections[i].displacement = rom._int(offset + 4)
        connections[i].bank = rom.u8(offset + 8)
        connections[i].mapid = rom.u8(offset + 9)
        connections[i].fieldA = rom.u8(offset + 10)
        connections[i].fieldB = rom.u8(offset + 11)
    return connections


def export_levelscript(rom: agb.Agbrom, offset, type, basepath, script_export_func, pedantic=False):
    """ Exports a levelscript structure as assembly string.
    Returns a tuple: label, assembly"""
    if type in (1,3,5,6,7):
        #No extension
        return script_export_func(rom, offset, basepath, "lscr"), ""
    elif type in (2,4):
        #Extended
        label = "lscr_" + hex(offset)
        assembly = ".align 4\n.global " + label + "\n\n" + label + ":\n"
        var = constants._dict_get(constants.var_table, rom.u16(offset), pedantic=pedantic)
        value = hex(rom.u16(offset + 2))
        script = script_export_func(rom, rom.pointer(offset + 4), basepath, "lscr")
        field_8 = hex(rom.u16(offset + 8))
        assembly += "\t.hword " + var + ", " + value + "\n"
        assembly += "\t.word " + script + "\n"
        assembly += "\t.hword " + field_8 + "\n"
        return label, assembly
    else: raise Exception("Unkown levelscript header type " + str(type))

def export_levelscripts(rom: agb.Agbrom, offset, basepath, script_export_func, pedantic=False):
    """ Exports levelscripts into a seperate folder """
    lscr = ".global lscr_" + hex(offset) + "\n\nlscr_" + hex(offset) + ":\n"
    lscr_label = "lscr_" + hex(offset)
    assemblies = []
    while True:
        type = rom.u8(offset)
        lscr += "\t.byte " + hex(type) + "\n"
        if not type: break
        label, assembly = export_levelscript(rom, rom.pointer(offset + 1), type, basepath, script_export_func, pedantic=pedantic)
        offset += 5
        lscr += ".word " + label + "\n"
        assemblies.append(assembly)
    lscr += "\n\n".join([""] + assemblies)
    filename = os.path.dirname(basepath) + "/lscr.asm"
    fd = open(filename, "w+")
    fd.write(constants.get_macro_header() + "\n\n" + lscr)
    fd.close()
    return lscr_label

        

def export_map(rom, offset, tsp, tss, symbol, basepath, proj, script_export_func, tileset_export_func, pedantic=False):
    """ Exports a map """
    header = mapheader.Mapheader()
    export_footer(header.footer, rom, rom.pointer(offset), tsp, tss, basepath, proj, tileset_export_func, pedantic=pedantic)
    event_off = rom.u32(offset + 4)
    if event_off: export_events(header, rom, rom.pointer(offset + 4), basepath, script_export_func, pedantic=pedantic)
    else: event_off = "0"
    lscr_off = rom.u32(offset + 0x8)
    if lscr_off: header.levelscript_header = export_levelscripts(rom, rom.pointer(offset + 0x8), basepath, script_export_func, pedantic=pedantic)
    else: header.levelscript_header = "0"
    if rom.u32(offset + 0xC) == 0:
        header.connections = []
    else:
        header.connections = export_connections(rom, rom.pointer(offset + 0xC), basepath, pedantic=pedantic)
    header.music = constants._dict_get(constants.music, rom.u16(offset + 0x10), pedantic=pedantic)
    header.id = rom.u16(offset + 0x12)
    header.name_bank = constants._dict_get(constants.map_namespaces, rom.u8(offset + 0x14), pedantic=pedantic)
    header.flash_type = constants.flash_type(rom.u8(offset + 0x15), pedantic=pedantic)
    header.weather = constants.map_weather(rom.u8(offset + 0x16), pedantic=pedantic)
    header.type = constants.map_type(rom.u8(offset + 0x17), pedantic=pedantic)
    header.show_name = constants._dict_get(constants.map_show_name, rom.u8(offset + 0x19), pedantic=pedantic)
    header.field_18 = rom.u8(offset + 0x18)
    header.field_1a = rom.u8(offset + 0x1A)
    header.battle_style = constants.battle_type(rom.u8(offset + 0x1B), pedantic=pedantic)
    header.symbol = symbol
    return header

def export_footer(footer: pymap.mapfooter.Mapfooter, rom: agb.Agbrom, offset, tsp, tss, basepath, proj, tileset_export_func, pedantic=False):
    """ Exports a mapfooter into a mapfooter instance"""
    footer.width = rom.u32(offset)
    footer.height = rom.u32(offset + 0x4)
    footer.border_width = rom.u8(offset + 0x18)
    footer.border_height = rom.u8(offset + 0x19)
    footer.padding = rom.u16(offset + 0x1A)
    border_off = rom.pointer(offset + 0x8)
    footer.borders = [
        [rom.u16(border_off + 2 * (y * footer.border_width + x)) for x in range(footer.border_width)]
        for y in range(footer.border_height) 
    ]
    block_off = rom.pointer(offset + 0xC)
    footer.blocks = [
        [rom.u16(block_off + 2 * (y * footer.width + x))for x in range(footer.width)]
        for y in range(footer.height)
    ]
    #Export tilesets
    if not tsp:
        #Export tsp
        tsp = tileset_export_func(rom, rom.pointer(offset + 0x10), proj)
    if not tss:
        #Export tss
        tss = tileset_export_func(rom, rom.pointer(offset + 0x14), proj)
 
    #Initialize tilesets as stubs to minimize exporting time
    footer.tsp = pymap.tileset.Tileset(True)
    footer.tsp.symbol = tsp
    footer.tss = pymap.tileset.Tileset(False)
    footer.tss.symbol = tss

def export_events(header: pymap.mapheader.Mapheader, rom: agb.Agbrom, offset, basepath, script_export_func, pedantic=False):
    """ Exports map events into a mapheader instance """
    person_cnt = rom.u8(offset)
    warp_cnt = rom.u8(offset + 1)
    trigger_cnt = rom.u8(offset + 2)
    signpost_cnt = rom.u8(offset + 3)
    person_off = rom.pointer(offset + 4)
    warp_off = rom.pointer(offset + 8)
    trigger_off = rom.pointer(offset + 0xC)
    signpost_off = rom.pointer(offset + 0x10)
    header.persons = [
        export_person(rom, person_off + 0x18 * i, basepath, script_export_func, pedantic=pedantic) for i in range(person_cnt)
        ]
    header.warps = [
        export_warp(rom, warp_off + 0x8 * i, pedantic=pedantic) for i in range(warp_cnt)
    ]
    header.triggers = [
        export_trigger(rom, trigger_off + 0x10 * i, basepath, script_export_func, pedantic=pedantic) for i in range(trigger_cnt)
    ]
    header.signposts = [
        export_sign(rom, signpost_off + 0xC * i, basepath, script_export_func, pedantic=pedantic) for i in range(signpost_cnt)
    ]

        


def export_person(rom: agb.Agbrom, offset, basepath, script_export_func, pedantic=False):
    """ Exports a person """
    person = mapevent.Map_event_person()
    person.target_index = rom.u8(offset)
    person.picture = rom.u8(offset + 1)
    person.field_2 = rom.u8(offset + 2)
    person.field_3 = rom.u8(offset + 3)
    person.x = rom.s16(offset + 4)
    person.y = rom.s16(offset + 6)
    person.level = rom.u8(offset + 8)
    person.behaviour = constants.behaviours[rom.u8(offset + 9)]
    person.behaviour_range = rom.u8(offset + 0xA)
    person.field_b = rom.u8(offset + 0xB)
    person.is_trainer = rom.u8(offset + 0xC) & 1
    person.is_trainer_padding = rom.u8(offset + 0xC) >> 1
    person.field_d = rom.u8(offset + 0xD)
    person.alert_radius = rom.u16(offset + 0xE)
    person.script = script_export_func(rom, rom.pointer(offset + 0x10), basepath, "person")
    person.flag = constants.flag(rom.u16(offset + 0x14), pedantic=pedantic)
    person.field_16 = rom.u8(offset + 0x16)
    person.field_17 = rom.u8(offset + 0x17)
    return person

def export_warp(rom: agb.Agbrom, offset, pedantic=False):
    """ Exports a warp """
    warp = mapevent.Map_event_warp()
    warp.x = rom.s16(offset)
    warp.y = rom.s16(offset + 2)
    warp.level = rom.u8(offset + 4)
    warp.target_warp = rom.u8(offset + 5)
    warp.target_map = rom.u8(offset + 6)
    warp.target_bank = rom.u8(offset + 7)
    return warp

def export_trigger(rom : agb.Agbrom, offset, basepath, script_export_func, pedantic=False):
    """ Exports a trigger """
    trigger = mapevent.Map_event_trigger()
    trigger.x = rom.s16(offset)
    trigger.y = rom.s16(offset + 2)
    trigger.level = rom.u8(offset + 4)
    trigger.field_5 = rom.u8(offset+ 5)
    trigger.variable = constants._dict_get(constants.var_table, rom.u16(offset + 6), pedantic=pedantic)
    trigger.value = rom.u16(offset + 8)
    trigger.field_a = rom.u8(offset + 0xA)
    trigger.field_b = rom.u8(offset + 0xB)
    trigger.script = script_export_func(rom, rom.pointer(offset + 0xC), basepath, "trigger")
    return trigger

def export_sign(rom: agb.Agbrom, offset, basepath, script_export_func, pedantic=False):
    """ Exports a sign """
    sign = mapevent.Map_event_sign()
    sign.x = rom.s16(offset)
    sign.y = rom.s16(offset + 2)
    sign.level = rom.u8(offset + 4)
    sign.sign_type = rom.u8(offset + 5)
    sign.field_6 = rom.u8(offset + 6)
    sign.field_7 = rom.u8(offset + 7)
    sign._struct_setup()
    if sign.structure == mapevent.SIGN_STRUCTURE_SCRIPT:
        sign.script = script_export_func(rom, rom.pointer(offset + 0x8), basepath, "sign")
    else:
        sign.item_id = constants.item(rom.u16(offset + 8), pedantic=pedantic)
        sign.hidden = rom.u8(offset + 0xA)
        sign.count = rom.u8(offset + 0xB)
    return sign


if __name__ == "__main__":
    main(sys.argv[1:])