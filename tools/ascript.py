""" Module for interpreting a script """



class Command: 
    def __init__(self, name, id, params):
        self.name = name
        self.id = id
        self.params = params
        
    def to_assembly_macro(self):
        macro = ".macro " + self.name + " " + " ".join([param.name for param in self.params]) + "\n"
        macro += ".byte " + hex(self.id) + "\n"
        macro += "\n".join([param.to_assembly_macro() for param in self.params])+"\n"
        macro += ".endm\n"
        return macro

class Param:
    def __init__(self, name, type, note=None):
        self.name = name
        self.type = type
        self.note = note

    def to_assembly_macro(self):
        return "." + self.type.datatype + " \\"+self.name

class Byte:
    def __init__(self):
        self.datatype = "byte"
    def consume(self, rom, offset):
        return rom.u8(offset)
    def size(self, rom, offset):
        return 1

class Halfword:
    def __init__(self):
        self.datatype = "hword"
    def consume(self, rom, offset):
        return rom.u16(offset)
    def size(self, rom, offset):
        return 2

class Word:
    def __init__(self):
        self.datatype = "word"
    def consume(self, rom, offset):
        return rom.u32(offset)
    def size(self, rom, offset):
        return 4

class List:
    def __init__(self):
        self.datatype = "byte"
    def consume(self, rom, offset):
        size = rom.u8(offset)
        return [rom.u16(offset + 1 + i * 2) for i in range(0,size)]
    def size(self, rom, offset):
        1 + rom.u8(offset) * 2

class ScriptReference:
    def __init__(self):
        self.datatype = "word"
    def consume(self, rom, offset):
        return rom.u32(offset)
    def size(self, rom, offset):
        return 4
        
        
commands = [
    Command("loadgraphic", 0, [Param("id", Halfword())]),
	Command("cmd1", 1, [Param("param0", Halfword())]),
	Command("loadoam", 2, [Param("oam", Word()), Param("additional", List())]),
	Command("loadcallback", 3, [Param("function", Word()), Param("additional", List())]),
	Command("pause", 4, [Param("frames", Byte())]),
	Command("waitstate", 5, []),
	Command("nop", 6, []),
	Command("nop2", 7, []),
	Command("end", 8, []),
	Command("playsound", 9, [Param("sound", Halfword())]),
	Command("enable_oam_as_target", 10, [Param("slot", Byte())]),
	Command("disable_oam_as_target", 11, [Param("slot", Byte())]),
	Command("enablebld", 12, [Param("bld", Halfword())]),
	Command("resetbld", 13, []),
	Command("call", 14, [Param("subscript", ScriptReference())]),
	Command("return", 15, []),
	Command("setadditional", 16, [Param("id", Byte()), Param("value", Halfword())]),
	Command("goto_if_charging_state_bit_0", 17, [Param("subscript", ScriptReference())]),
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
	Command("setbld", 31, [Param("param0", Halfword())]),
	Command("cmd20", 32, []),
	Command("goto_if_additional_equals", 33, [Param("id", Byte()), Param("value", Halfword()), Param("param3", ScriptReference())]),
	Command("something_with_poke_oam", 34, [Param("slot", Byte())]),
	Command("something_with_poke_oam_on_user", 35, [Param("slot", Byte())]),
	Command("nop3", 36, [Param("unused", ScriptReference())]),
	Command("fade_into_background_target_based", 37, [Param("id_target_is_opponent", Byte()), Param("id_target_is_not_opponent", Byte()), Param("unused", Byte())]),
	Command("playsound", 38, [Param("sound", Halfword()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte())]),
	Command("cmd27", 39, [Param("param4", Halfword()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte()), Param("param4", Byte())]),
	Command("cmd28", 40, [Param("param0", Byte())]),
	Command("cmd29", 41, []),
	Command("cmd2A", 42, [Param("param0", Byte())]),
	Command("cmd2B", 43, [Param("param0", Byte())]),
	Command("cmd2C", 44, [Param("param0", Byte())]),
	Command("cmd2E", 46, [Param("param0", Byte())]),
	Command("cmd2F", 47, []),

]


def to_assembly_macro(commands):
    return "\n\n".join([command.to_assembly_macro() for command in commands])

open("D:/temp/ascriptmacros.s", "w+").write(to_assembly_macro(commands))

