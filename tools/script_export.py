import sys
import getopt
import agb
import owscript
import ascript
import constants

OWSCRIPTLIB = "lib/owscript.py"
ASCRIPTLIB = "lib/ascript.py"

def shell(argv):
    """ Shell method for this tool """
    try:
        opts, args = getopt.getopt(argv, "vrhs:o:l:r:m:b:p:", ["help","verbose", "recursive", "libignore", "singlefile"])
    except getopt.GetoptError:
        sys.exit(2)
    mode = None
    offset = None
    outpath = None
    libpath = None
    rompath = agb.VIOLETPATH
    verbose = False
    recursive = False
    libignore = False
    singlefile = False
    preamble = ""

    derive_offset_from_attack = None
    for opt, arg in opts:
        if opt in ("-h", "--help"):
            print("usage: python script_export.py -s offset -o outdir -m mode {a,attack,ow,overworld} [-l libfile=lib/XXscript.json] [-b romfile=VIOLETPATH] [-p preamble path to file that is prepended] [--verbose] [--recursive] [--libignore] [--singlefile]")
            sys.exit(0)
        if opt == "-s":
            try:    
                offset = int(arg, 0)
            except:
                derive_offset_from_attack = arg
        elif opt == "-o":
            outpath = arg
        elif opt == "-l":
            libpath = arg
        elif opt == "-b":
            rompath = arg
        elif opt == "-m":
            mode = arg
        elif opt == "-p":
            fd = open(arg, "r+")
            preamble = fd.read()
            fd.close()
        elif opt in ("-v", "--verbose"):
            verbose = True
        elif opt in ("-r", "--recursive"):
            recursive = True
        elif opt in ("--libignore"):
            libignore = True
        elif opt in ("--singlefile"):
            singlefile = True

    rom = agb.Agbrom(path=rompath)
    if verbose: print("Rom loaded sucessfully.")

    if derive_offset_from_attack:
        for i in range(0, len(constants.attack_table)):
            if constants.attack_table[i] == derive_offset_from_attack:
                offset = rom.pointer(rom.pointer(0x72534) + i * 4)
                break

    
    if offset == None: raise Exception("No offset to export specified")
    if not outpath: raise Exception("No output file specified")
    

    if mode in ("a", "attack", "attack_script"):
        #Dump as attack script
        file_prefix = "attack_script"
        if not libpath: libpath = ASCRIPTLIB
        tree = ascript.Ascript_exploration_tree(rom)

    elif mode in ("o", "ow", "owscript", "ow_script"):
        #Dump as overworld script
        file_prefix = "ow_script"
        if not libpath: libpath = OWSCRIPTLIB
        tree = owscript.Owscript_Exploration_tree(rom)

    else:
        raise Exception("Unkown script mode "+mode)
    export_script(tree, libpath, offset, file_prefix, preamble, outpath, recursive=recursive, verbose=verbose, libignore=libignore, singlefile=singlefile)

def export_script(tree, libpath, offset, file_prefix, preamble, outpath, recursive=True, verbose=False, libignore=False, singlefile=True):
    if not libignore: tree.load_lib(libpath)
    if verbose: print("Lib ", libpath, "loaded sucessfully.")
    tree.explore(offset, verbose=verbose, recursive=recursive)
    if verbose: print("Script decompiled sucessfully.")
    if not libignore: tree.store_lib(libpath)
    if verbose: print("Lib", libpath, "updated sucessfully.")
    if len(tree.assemblies):
        #Dump assemblies
        if singlefile:
            #Dump the script output
            output = preamble + "\n" + constants.get_macro_header() + "\n\n".join([""] + [assembly for _, assembly in tree.assemblies])
            fd = open(outpath + "/" + file_prefix + "_" + hex(offset) + ".asm", "w+")
            fd.write(output)
            fd.close()

        else:
            #Dump the script output
            for assembly_offset, assembly in tree.assemblies:
                
                fd = open(outpath + "/" + file_prefix + "_" + hex(assembly_offset) + ".asm", "w+")
                fd.write(assembly)
                fd.close()
                if verbose: print("Exported script at", hex(assembly_offset), "sucessfully.")

    #Dump the string output
    if len(tree.strings):
        output = "\n\n".join([".string " + label + " GER\n\t=" + content + "\n.end\n" for label, content in tree.strings])
        fd = open(outpath + "/" + file_prefix + "_" + hex(offset) + "_strings.txt", "w+")
        fd.write(output)
        fd.close()


if __name__ == "__main__":
    #call from main with shell "owscript -s offset -o outpath -l libfile"
    shell(sys.argv[1:])