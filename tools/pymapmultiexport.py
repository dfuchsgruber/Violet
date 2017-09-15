import os
import agb
import pymapex, pysetex, owscript, script_export
from pymap import project as project, config

#Hacky module for multi export of map, tileset and wild data

MAPOUTPUT = config.MAPOUTPUT #%b will be replaced with bank and %m with map
MAPSYM = config.MAPSYM
TSOUTPUT = config.TSOUTPUT #%s will be replaced with the offset and %n with the number relative to TSTABLE
TSGRAPHIC = config.TSGRAPHIC #Can be None as well - no graphic will be exported then
TSGFXSYM = config.TSGFXSYM
TSSYM = config.TSSYM
PROJ = config.STDPROJ
MAPTABLEPTR = config.MAPTABLEPTR
TSTABLE = config.TSTABLE
PEDANTIC = config.PEDANTIC

def _mkdirs(dir):
    if not os.path.exists(dir):
        os.makedirs(dir)

def shell():
    rom = agb.Agbrom(path=config.STDROM)
    try: proj = project.Project.load_project(PROJ)
    except: 
        proj = project.Project()
        print("Project '", PROJ, "' not found. Will be created.")
    proj.save_project(path=PROJ)

    while 1:
        line = input(">>Export maps: Format {bank.map}, {bank.map}, ... {bank.map} or list:{listpath}\n")
        if line.find("list:") == 0:
            #Export from list(lines will be merged and fed into input)
            path = line.split(":")[1]
            fd = open(path, "r+")
            content = fd.read()
            fd.close()
            line = content.replace("\r\n", " ").replace("\n", " ")
            print(line)
        maps = map((lambda t: t.strip().split(".")), line.split(","))
        for bank, mapid in maps:
            #print("Exporting map", bank, id)
            bank = int(bank, 0)
            mapid = int(mapid, 0)
            export(bank, mapid, rom, proj)
            proj.save_project(path=PROJ)

def resolve(s, bank, id):
    return s.replace("%b", str(bank)).replace("%m", str(id))

def tsresolve(s, offset, num):
    return s.replace("%s", hex(offset)[2:]).replace("%n", str(num))

def export(bank, mapid, rom: agb.Agbrom, proj: project.Project):
    #Calculate offset
    print("Exporting", str(bank) +  "." + str(mapid), "...")
    offset = rom.pointer(rom.pointer(rom.pointer(MAPTABLEPTR) + 4 * bank) + 4 * mapid)
    out = resolve(MAPOUTPUT, bank, mapid)
    outdir = os.path.dirname(out)
    _mkdirs(outdir)
    mh = pymapex.export_map(rom, offset, None, None, resolve(MAPSYM, bank, mapid), out, proj, export_ow_script, export_tileset, pedantic=PEDANTIC)
    proj.save_map(bank, mapid, mh, out)
    proj.save_project(path=PROJ)
    print("Exported", str(bank) +  "." + str(mapid), "as", resolve(MAPSYM, bank, mapid), "into", out)

    """tsargs = "--pg " + PTSGRAPHIC + " --po " + PTSOUTPUT + "--py " + PTSSYM + " --px " + PTSGFXSYM + " --sg " + STSGRAPHIC + " --so " + STSOUTPUT + "--sy " + STSSYM + " --sx " + STSGFXSYM + " --deleteanim"
    command = resolve("python pymapex.py -b %b -m %m -y " + MAPSYM + " -o " + MAPOUTPUT + " " + tsargs + " VIOLET" + " \"" + PROJ + "\"", bank, id)
    print(command)
    os.system(command)"""

def export_ow_script(rom: agb.Agbrom, offset, path, prefix):
    """ Exports an overworld script by invoking command line for script_export tool"""
    if offset <= 0: return "0"
    dir = os.path.dirname(path) + "/script/" + prefix + "/"
    _mkdirs(dir)
    print("Invoked script export for", hex(offset), "into", dir)
    #Create exporting tree
    tree = owscript.Owscript_Exploration_tree(rom)
    fdpreamble = open("pymapexstdpreamble.txt", "r+")
    preamble = fdpreamble.read()
    fdpreamble.close()
    script_export.export_script(tree, script_export.OWSCRIPTLIB, offset, "ow_script", preamble, dir, recursive=True, verbose=False, libignore=False, singlefile=True)
    #os.system("python script_export.py -s " + hex(offset) + ' -o "' + dir + '" -m ow -b "' + rom.path + '" -r -p pymapexstdpreamble.txt --singlefile')
    return owscript.script_offset_to_label(offset)

def export_tileset(rom: agb.Agbrom, offset, proj: project.Project):
    """ Exports a tileset by using the pysetex module """
    num = int((offset  - TSTABLE) / 24)
    graphic = TSGRAPHIC
    if graphic != None: graphic = tsresolve(graphic, offset, num)
    sym = tsresolve(TSSYM, offset, num)
    outpath = tsresolve(TSOUTPUT, offset, num)
    gfxsym = tsresolve(TSGFXSYM, offset, num)
    _mkdirs(os.path.dirname(outpath))
    #Check if sym is in proj
    if sym in proj.tilesets: return sym
    print("Exporting tileset num", num, "at", hex(offset), "into", outpath, "as", sym, ". Graphic will be exported to", graphic, "with symbol", gfxsym)
    pysetex.export_tileset(rom, proj, offset, sym, gfxsym, export_gfx=graphic, basename=outpath, delete_anim_edit=True)
    return sym

if __name__ == "__main__":
    shell()