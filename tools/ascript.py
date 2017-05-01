""" Module for interpreting a script """
import agb
import json

class Command: 
    def __init__(self, name, id, params, ends_section=False):
        self.name = name
        self.id = id
        self.params = params
        self.ends_section = ends_section

    def get_ends_section(self):
        return self.ends_section
        
    def to_assembly_macro(self):
        macro = ".macro " + self.name + " " + " ".join([param.name for param in self.params]) + "\n"
        macro += ".byte " + hex(self.id) + "\n"
        macro += "\n".join([param.to_assembly_macro() for param in self.params])+"\n"
        macro += ".endm\n"
        return macro

    def export(self, tree, rom, offset):
        exported_params = []
        offset += 1
        for param in self.params:
            exported_params.append(param.export(tree, rom, offset))
            offset += param.size(rom, offset)
        return self.name + " " + " ".join(exported_params)

    def size(self, rom, offset):
        size = 1
        for param in self.params:
            size += param.size(rom, offset + size)
        return size

class Param:
    def __init__(self, name, type, note=None):
        self.name = name
        self.type = type
        self.note = note

    def to_assembly_macro(self):
        return "." + self.type.datatype + " \\"+self.name

    def export(self, tree, rom, offset):
        return self.type.consume(tree, rom, offset)

    def size(self, rom, offset):
        return self.type.size(rom, offset)

class Byte:
    def __init__(self):
        self.datatype = "byte"
    def consume(self, tree, rom, offset):
        return hex(rom.u8(offset))
    def size(self, rom, offset):
        return 1

class Halfword:
    def __init__(self):
        self.datatype = "hword"
    def consume(self, tree, rom, offset):
        return hex(rom.u16(offset))
    def size(self, rom, offset):
        return 2

class Word:
    def __init__(self):
        self.datatype = "word"
    def consume(self, tree, rom, offset):
        return hex(rom.u32(offset))
    def size(self, rom, offset):
        return 4

class List:
    def __init__(self):
        self.datatype = "byte"
    def consume(self, tree, rom, offset):
        size = rom.u8(offset)
        array = [hex(rom.u16(offset + 1 + i * 2)) for i in range(0,size)]
        if size:
            return hex(size) + "\n.hword " + ", ".join(array)
        else:
            return hex(size)
    def size(self, rom, offset):
        return 1 + rom.u8(offset) * 2

class ScriptReference:
    def __init__(self):
        self.datatype = "word"
    def consume(self, tree, rom, offset):
        ref = rom.pointer(offset)
        if tree.recursive: tree.offsets.append(ref)
        return script_offset_to_label(ref)
    def size(self, rom, offset):
        return 4
        
def script_offset_to_label(offset):
    return "attack_script_" + hex(offset)
        
commands = [
    Command("loadgraphic", 0, [Param("id", Halfword())]),
	Command("cmd1", 1, [Param("param0", Halfword())]),
	Command("loadoam", 2, [Param("oam", Word()), Param("unkown", Byte()), Param("additional", List())]),
	Command("loadcallback", 3, [Param("function", Word()), Param("priority", Byte()), Param("additional", List())]),
	Command("pause", 4, [Param("frames", Byte())]),
	Command("waitstate", 5, []),
	Command("nop", 6, []),
	Command("nop2", 7, []),
	Command("end", 8, [], ends_section=True),
	Command("playsound", 9, [Param("sound", Halfword())]),
	Command("enable_oam_as_target", 10, [Param("slot", Byte())]),
	Command("disable_oam_as_target", 11, [Param("slot", Byte())]),
	Command("enablebld", 12, [Param("bld", Halfword())]),
	Command("resetbld", 13, []),
	Command("call", 14, [Param("subscript", ScriptReference())]),
	Command("return", 15, [], ends_section=True),
	Command("setadditional", 16, [Param("id", Byte()), Param("value", Halfword())]),
	Command("goto_if_charging_state_bit_0", 17, [Param("subscript_not_set", ScriptReference()), Param("subscript_set", ScriptReference())]),
	Command("goto_if_charging_state_equals", 18, [Param("value", Byte()), Param("subscript", ScriptReference())]),
	Command("jump", 19, [Param("subscript", ScriptReference())]),
	Command("fade_into_background", 20, [Param("id", Byte())]),
	Command("fade_into_battle_background", 21, []),
	Command("wait", 22, []),
	Command("force_end_frame", 23, []),
	Command("display_background", 24, [Param("id", Byte())]),
	Command("playsound_modulation_user_target_based", 25, [Param("sound", Halfword()), Param("modulation", Byte())]),
	Command("sound_apply_modulation_user_target_based", 26, [Param("modulation", Byte())]),
	Command("sound_modulation", 27, [Param("param4", Halfword()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte())]),
	Command("playsound4", 28, [Param("sound", Halfword()), Param("modulation", Byte()), Param("param3", Byte()), Param("param3", Byte())]),
	Command("playsound5", 29, [Param("sound", Halfword()), Param("modulation", Byte()), Param("param2", Byte())]),
	Command("setbld", 30, [Param("value", Halfword())]),
    Command("loadcallback_and_execute_and_endframe", 31, [Param("function", Word()), Param("additional", List())]),
	Command("cmd20", 32, []),
	Command("goto_if_additional_equals", 33, [Param("id", Byte()), Param("value", Halfword()), Param("param3", ScriptReference())]),
	Command("something_with_poke_oam", 34, [Param("slot", Byte())]),
	Command("something_with_poke_oam_on_user", 35, [Param("slot", Byte())]),
	Command("nop3", 36, [Param("unused", ScriptReference())]),
	Command("fade_into_background_target_based", 37, [Param("id_target_is_opponent", Byte()), Param("id_target_is_not_opponent", Byte()), Param("unused", Byte())]),
	Command("playsound2", 38, [Param("sound", Halfword()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte())]),
	Command("cmd27", 39, [Param("param4", Halfword()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte())]),
	Command("cmd28", 40, [Param("param0", Byte())]),
	Command("cmd29", 41, []),
	Command("cmd2A", 42, [Param("param0", Byte())]),
	Command("cmd2B", 43, [Param("param0", Byte())]),
	Command("cmd2C", 44, [Param("param0", Byte())]),
	Command("cmd2D", 45, []),
	Command("cmd2E", 46, [Param("param0", Byte())]),
	Command("cmd2F", 47, []),

]

for i in range(0, len(commands)):
    if commands[i].id != i: raise Exception(hex(i))

class Ascript_exploration_tree:
    """ Class to explore a script offset """

    def __init__(self, rom):
        self.rom = rom
        self.offsets = []
        self.explored_offsets = [] #No offset must be encountered twice (prevent infinite loops)
        self.assemblies = []
        self.recursive = True
    
    def explore(self, offset, verbose=False, recursive=True):
        """ Explores an offset of a script tree """
        self.offsets.append(offset)
        self.recursive = recursive
        while len(self.offsets):
            #Explore this offset
            offset = self.offsets.pop()
            if verbose: print("Exploring offset", hex(offset))
            if offset not in self.explored_offsets:
                initial_offset = offset
                label = script_offset_to_label(offset)
                assembly = ".include \"attack_anim.s\"\n.global " + label + "\n" + label + ":\n" 
                while True:
                    cmd = commands[self.rom.u8(offset)]
                    if verbose: print("@", hex(offset), ":", cmd.__dict__)
                    assembly += cmd.export(self, self.rom, offset) + "\n"
                    #cmd.callback(self, self.rom, offset)
                    if cmd.get_ends_section(): break #Only if the command ends a section
                    if verbose: print("Command did not end secion.")
                    offset += cmd.size(self.rom, offset)
                self.explored_offsets.append(initial_offset) #We worked through this offset
                self.assemblies.append((initial_offset, assembly)) #Append the assembly

    def load_lib(self, libpath):
        """ Loads a json list of so far explored offset"""
        fd = open(libpath)
        lib = fd.read()
        fd.close()
        self.explored_offsets = json.loads(lib)

    def store_lib(self, libpath):
        """ Stores a json list of so far explored offsets"""
        fd = open(libpath, "w+")
        fd.write(json.dumps(self.explored_offsets))
        fd.close()

def to_assembly_macro(commands):
    return "\n\n".join([command.to_assembly_macro() for command in commands])

#open("D:/temp/ascriptmacros.s", "w+").write(to_assembly_macro(commands))

#testtree = Ascript_exploration_tree(agb.Agbrom())
