import constants
import agb

verbose = True

class CommandTrainerbattleFactory:
    """ Explicit class for trainerbattle cmd """
    def __init__(self):
        pass
    
    def make_command(self, rom, offset):
        type = rom.u8(offset + 1)
        if type in (0,5):
            return Command("trainerbattlestd", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_challange", STRING), Param("str_defeat", STRING)])
        elif type in (1,2):
            return Command("trainerbattlecont", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_challange", STRING), Param("str_defeat", STRING)],
            Param("continuation", SCRIPT_REFERENCE))
        elif type in (4,7):
            return Command("trainerbattledouble", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_challange", STRING), Param("str_defeat", STRING),
            Param("continuation_one_poke", SCRIPT_REFERENCE)])
        elif type == 3:
            return Command("trainerbattlenotinterrupting", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_defeat", STRING)])
        elif type == 9:
            return Command("trainerbattlelosable", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_defeat", STRING), Param("str_loss", STRING)])
        elif type in (6,8):
            return Command("trainerbattle6", [Param("kind", BYTE), Param("trainer", HWORD),
            Param("people", HWORD), Param("str_challange", STRING), Param("str_defeat", STRING),
            Param("str_var1", WORD), Param("continuation", SCRIPT_REFERENCE)])
        
    def size(self, rom, offset):
        return self.make_command(rom, offset).size(rom, offset)

    def export(self, rom, offset):
        return self.make_command(rom, offset).export(rom, offset)

class Command:
    """ Class to store a command """
    def __init__(self, name, params, callback=lambda tree, rom, offset : None, ends_section = False):
        self.name = name
        self.params = params
        self.callback = callback
        self.ends_section = ends_section

    def size(self, rom, offset):
        size = 1
        for param in self.params:
            size += param.type.size
        return size

    def export(self, rom, offset):
        tokens = [self.name]
        for param in self.params:
            tokens.append(param.type.export(rom, offset+1))
            offset += param.type.size
        return " ".join(tokens)

    def get_ends_section(self, rom, offset): return self.ends_section

class Param:
    """ Class to hold params """
    def __init__(self, name, type):
        self.name = name
        self.type = type

class ParamType:
    """ Class to hold a param type
    export func is a function rom, offset -> string to consume data and retrieve an assembly string """
    def __init__(self, size, export_func):
        self.size = size
        self.export_func = export_func

    def export(self, rom, offset):
        return self.export_func(rom, offset)

class Exploration_tree:
    """ Class to explore a script offset """

    def __init__(self, rom):
        self.rom = rom
        self.offsets = []
        self.done_offsets = set() #No offset must be encountered twice (prevent infinite loops)
        self.assemblies = []
    
    def explore(self, offset):
        self.offsets.append(offset)
        while len(self.offsets):
            #Explore this offset
            offset = self.offsets.pop()
            if verbose: print("Exploring offset", hex(offset))
            if offset not in self.done_offsets:
                label = script_offset_to_label(offset)
                assembly = ".global " + label + "\n" + label + ":\n" 
                while True:
                    cmd = owscript_cmds[self.rom.u8(offset)]
                    assembly += cmd.export(self.rom, offset) + "\n"
                    cmd.callback(self, self.rom, offset)
                    if cmd.get_ends_section(self.rom, offset): break #Only if the command ends a section
                    offset += cmd.size(self.rom, offset)
                self.done_offsets.add(offset) #We worked through this offset
                self.assemblies.append(assembly) #Append the assembly

    def load_lib(self, libpath):
        pass

def script_offset_to_label(offset): return "ow_script_" + "{0:#0{1}x}".format(offset, 6)
def movement_offset_to_label(offset): return "ow_script_movs_" + "{0:#0{1}x}".format(offset, 6)
def string_offset_to_label(offset): return "str_ow_script_" + "{0:#0{1}x}".format(offset, 6)
def mart_offset_to_label(offset): return "ow_script_mart" + "{0:#0{1}x}".format(offset, 6)

BYTE = ParamType(1, lambda rom, offset : str(hex(rom.u8(offset))))
HWORD = ParamType(2, lambda rom, offset : str(hex(rom.u16(offset))))
WORD =  ParamType(4, lambda rom, offset : str(hex(rom.u32(offset))))
SCRIPT_REFERENCE = ParamType(4, lambda rom, offset : script_offset_to_label(rom.pointer(offset)))
ITEM = ParamType(2, lambda rom, offset : str(hex(rom.u16(offset))))
FLAG = ParamType(2, lambda rom, offset : str(hex(rom.u16(offset))))
MOVEMENT_LIST = ParamType(4, lambda rom, offset : movement_offset_to_label(rom.pointer(offset)))
STRING = ParamType(4, lambda rom, offset : string_offset_to_label(rom.pointer(offset)))
POKEMON = ParamType(2, lambda rom, offset : str(hex(rom.u16(offset))))
ATTACK = ParamType(2, lambda rom, offset : str(hex(rom.u16(offset))))
MART = ParamType(4, lambda rom, offset : mart_offset_to_label(rom.pointer(offset)))

owscript_cmds = [
    #0x00
    Command("nop", []),
    Command("nop1", []),
    Command("end", [], ends_section = True),
    Command("return", [], ends_section = True),
    Command("call", [Param("subscript", SCRIPT_REFERENCE)], callback = lambda tree, rom, offset : tree.offsets.append(rom.pointer(offset+1))),
    Command("goto", [Param("script", SCRIPT_REFERENCE)], ends_section = True, callback = lambda tree, rom, offset : tree.offsets.append(rom.pointer(offset+1))),
    Command("callif", [Param("condition", BYTE), Param("script", SCRIPT_REFERENCE)]),
    Command("gotoif", [Param("condition", BYTE), Param("subscript", SCRIPT_REFERENCE)], ends_section = True),
    #0x08
    Command("gotostd", [Param("std", BYTE)], ends_section = True),
    Command("callstd", [Param("std", BYTE)]),
    Command("gotostdif", [Param("condition", BYTE), Param("std", BYTE)]),
    Command("callstdif", [Param("condition", BYTE), Param("std", BYTE)]),
    Command("jumpram", []),
    Command("killscript", []),
    Command("set_x203AA3C", [Param("value", BYTE)]),
    Command("loadpointer", [Param("bank", BYTE), Param("pointer", WORD)]),
    #0x10
    Command("set_intern_bank", [Param("bank", BYTE), Param("value", BYTE)]),
    Command("writebytetooffset", [Param("value", BYTE), Param("offset", WORD)]),
    Command("loadbytefrompointer", [Param("bank", BYTE), Param("offset", WORD)]),
    Command("setbyte", [Param("bank", BYTE), Param("offset", WORD)]),
    Command("copyscriptbanks", [Param("dst_bank", BYTE), Param("src_bank", BYTE)]),
    Command("copybyte", [Param("dst", WORD), Param("src", WORD)]),
    Command("setvar", [Param("var", HWORD), Param("value", HWORD)]),
    Command("addvar", [Param("var", HWORD), Param("value", HWORD)]),
    #0x18
   Command("subvar", [Param("var", HWORD), Param("value", HWORD)]),
   Command("copyvar", [Param("dst", HWORD), Param("src", HWORD)]),
   Command("copyvarifnotzero", [Param("dst", HWORD), Param("src", HWORD)]),
   Command("comparebanks", [Param("bank1", HWORD), Param("bank2", HWORD)]),
   Command("comparebanktobyte", [Param("bank", BYTE), Param("value", BYTE)]),
   Command("comparebanktofarbyte", [Param("bank", BYTE), Param("offset", WORD)]),
   Command("comparefarbytetobank", [Param("offset", WORD), Param("bank", BYTE)]),
   Command("comparefarbytetobyte", [Param("offset", WORD), Param("value", BYTE)]),
   #0x20
   Command("comparefarbytes", [Param("offset1", WORD), Param("offset2", WORD)]),
   Command("compare", [Param("var", HWORD), Param("value", HWORD)]),
   Command("comparevars", [Param("var1", HWORD), Param("var2", HWORD)]),
   Command("callasm", [Param("function", WORD)]),
   Command("callasmandwaitstate", [Param("function", WORD)]),
   Command("special", [Param("special_id", HWORD)]),
   Command("special2", [Param("varresult", HWORD), Param("speical_id", HWORD)]),
   Command("waitstate", []),
   #0x28
   Command("pause", [Param("frames", HWORD)]),
   Command("setflag", [Param("flag", FLAG)]),
   Command("clearflag", [Param("flag", FLAG)]),
   Command("checkflag", [Param("flag", FLAG)]),
   Command("cmd2c", []),
   Command("cmd2d", []),
   Command("resetvolatilevars", []),
   Command("sound", [Param("sound", HWORD)]),
   #0x30
   Command("checksound", []),
   Command("fanfare", [Param("fanfare", HWORD)]),
   Command("waitfanfare", []),
   Command("playsong", [Param("song", HWORD), Param("feature", BYTE)]),
   Command("playsong2", [Param("song", HWORD)]),
   Command("songfadedefault", []),
   Command("fadesong", [Param("song", HWORD)]),
   Command("fadeout", [Param("speed", BYTE)]),
   #0x38
   Command("fadein", [Param("speed", BYTE)]),
   Command("warp", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warpmuted", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warpwalk", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warphole", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warpteleport", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warp3", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("setwarpplace", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   #0x40
   Command("warp4", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("warp5", [Param("bank", BYTE), Param("map", BYTE), Param("exit", BYTE), Param("x", HWORD), Param("y", HWORD)]),
   Command("getplayerpos", [Param("varx", HWORD), Param("vary", HWORD)]),
   Command("countpokemon", []),
   Command("additem", [Param("item", ITEM), Param("quantity", HWORD)]),
   Command("removeitem", [Param("item", ITEM), Param("quantity", HWORD)]),
   Command("checkitemroom", [Param("item", ITEM), Param("quantity", HWORD)]),
   Command("checkitem", [Param("item", ITEM), Param("quantity", HWORD)]),
   #0x48
   Command("checkitemtype", [Param("item", ITEM)]),
   Command("addpcitem", [Param("item", ITEM), Param("quantity", HWORD)]),
   Command("checkpcitem", [Param("item", ITEM), Param("quantity", HWORD)]),
   Command("cmd4b", [Param("unused", HWORD)]),
   Command("cmd4c", [Param("unused", HWORD)]),
   Command("cmd4d", [Param("unused", HWORD)]),
   Command("cmd4e", [Param("unused", HWORD)]),
   Command("applymovement", [Param("people", HWORD), Param("movement", MOVEMENT_LIST)]),
   #0x50
   Command("applymovementonmap", [Param("people", HWORD), Param("movement", MOVEMENT_LIST), Param("bank", BYTE), Param("map", BYTE)]),
   Command("waitmovement", [Param("num_people", HWORD)]),
   Command("waitmovementonmap", [Param("num_people", HWORD), Param("bank", BYTE), Param("map", BYTE)]),
   Command("hidesprite", [Param("people", HWORD)]),
   Command("hidespriteonmap", [Param("people", HWORD), Param("bank", BYTE), Param("map", BYTE)]),
   Command("showsprite", [Param("people", HWORD)]),
   Command("showspriteonmap", [Param("people", HWORD), Param("bank", BYTE), Param("map", BYTE)]),
   Command("movesprite", [Param("people", HWORD), Param("x", HWORD), Param("y", HWORD)]),
   #0x58
   Command("spritevisible", [Param("people", HWORD), Param("bank", BYTE), Param("map", BYTE)]),
   Command("spriteinvisible", [Param("people", HWORD), Param("bank", BYTE), Param("map", BYTE)]),
   Command("faceplayer", []),
   Command("spriteface", [Param("people", HWORD), Param("facing", BYTE)]),
   CommandTrainerbattleFactory(),
   Command("repeattrainerbattle",[]),
   Command("endtrainerbattle",[]),
   Command("endtrainerbattle2",[]),
   #0x60
   Command("checktrainerflag", [Param("id", HWORD)]),
   Command("cleartrainerflag", [Param("id", HWORD)]),
   Command("settrainerflag", [Param("id", HWORD)]),
   Command("movesprite2", [Param("people", HWORD), Param("x", HWORD), Param("y", HWORD)]),
   Command("moveoffscreen", [Param("people", HWORD)]),
   Command("spritebehave", [Param("people", HWORD), Param("behaviour", BYTE)]),
   Command("waitmsg", []),
   Command("preparemsg", [Param("str", STRING)]),
   #0x68
   Command("closeonkeypress", []),
   Command("lockall", []),
   Command("lock", []),
   Command("releaseall", []),
   Command("release", []),
   Command("waitkeypress", []),
   Command("yesnobox", [Param("tilex", BYTE), Param("tiley", BYTE)]),
   Command("multichoice", [Param("tilex", BYTE), Param("tiley", BYTE), Param("id", BYTE), Param("not_escapable", BYTE)]),
   #0x70
   Command("multichoice", [Param("tilex", BYTE), Param("tiley", BYTE), Param("id", BYTE), Param("default", BYTE), Param("not_escapable", BYTE)]),
   Command("multichoice", [Param("tilex", BYTE), Param("tiley", BYTE), Param("id", BYTE), Param("num_per_row", BYTE), Param("not_escapable", BYTE)]),
   Command("showbox", [Param("tilex", BYTE), Param("tiley", BYTE), Param("tilew", BYTE), Param("tileh", BYTE)]),
   Command("hidebox", [Param("tilex", BYTE), Param("tiley", BYTE), Param("tilew", BYTE), Param("tileh", BYTE)]),
   Command("clearbox", [Param("tilex", BYTE), Param("tiley", BYTE), Param("tilew", BYTE), Param("tileh", BYTE)]),
   Command("showpokepic", [Param("species", POKEMON), Param("tilex", BYTE), Param("tiley", BYTE)]),
   Command("hidepokepic", []),
   Command("cmd77", []),
   #0x78
   Command("braille", [Param("brialledata", STRING)]),
   Command("givepokemon", [Param("species", POKEMON), Param("level", BYTE), Param("item", ITEM),
   Param("filler1", WORD), Param("filler2", WORD), Param("filler3", BYTE)]),
   Command("giveegg", [Param("species", POKEMON)]),
   Command("setpokemonpp", [Param("teamslot", BYTE), Param("attackslot", BYTE), Param("pp", HWORD)]),
   Command("checkattack", [Param("move", ATTACK)]),
   Command("bufferpokemon", [Param("buffer", BYTE), Param("species", POKEMON)]),
   Command("bufferfirstpokemon", [Param("buffer", BYTE)]),
   Command("bufferpartypokemon", [Param("buffer", BYTE), Param("teamsplot", HWORD)]),
   #0x80
   Command("bufferitem", [Param("buffer", BYTE), Param("item", ITEM)]),
   Command("cmdx81", [Param("buffer", BYTE), Param("deco", HWORD)]),
   Command("bufferattack", [Param("buffer", BYTE), Param("move", ATTACK)]),
   Command("buffernumber", [Param("buffer", BYTE), Param("var", HWORD)]),
   Command("bufferstd", [Param("buffer", BYTE), Param("std", HWORD)]),
   Command("bufferstring", [Param("buffer", BYTE), Param("str", STRING)]),
   Command("pokemart", [Param("mart", MART)]),
   Command("pokemart2", [Param("mart", MART)]),
   #0x88
   Command("pokemart3", [Param("mart", MART)]),
   Command("pokecasino", [Param("var", HWORD)]),
   Command("cmd8a", [Param("param1", BYTE), Param("param2", BYTE)], Param("param3", BYTE)),
   Command("cmd8b", []),
   Command("cmd8c", []),
   Command("cmd8d", []),
   Command("cmd8e", []),
   Command("random", [Param("module", HWORD)]),



   
   


]

test_tree = Exploration_tree(agb.Agbrom(path="D:/temp/tst.gba"))

test_tree.explore(0)
print(test_tree.assemblies)