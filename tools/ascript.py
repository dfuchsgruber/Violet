""" Module for interpreting a script """



class Command: 
    def __init__(self, name, id, params):
        self.name = name
        self.id = id
        self.params = params

class Param:
    def __init__(self, name, type, note=None):
        self.name = name
        self.type = type
        self.note = note

class Byte:
    def __init__(self): pass
    def consume(self, rom, offset):
        return rom.u8(offset)
    def size(self, rom, offset):
        return 1

class Halfword:
    def __init__(self): pass
    def consume(self, rom, offset):
        return rom.u16(offset)
    def size(self, rom, offset):
        return 2

class Word:
    def __init__(self): pass
    def consume(self, rom, offset):
        return rom.u32(offset)
    def size(self, rom, offset):
        return 4

class List:
    def __init__(self): pass
    def consume(self, rom, offset):
        size = rom.u8(offset)
        return [rom.u16(offset + 1 + i * 2) for i in range(0,size)]
    def size(self, rom, offset):
        1 + rom.u8(offset) * 2

class ScriptReference:
    def __init__(self): pass
    def consume(self, rom, offset):
        return rom.u32(offset)
    def size(self, rom, offset):
        return 4
        
commands = [
    Command("loadgraphic", 0, [Param("id", Halfword)]),
	Command("cmd1", 1, [Param("param0", Halfword)]),
	Command("loadoam", 2, [Param("oam", Word), Param("additional", List)]),
	Command("loadcallback", 3, [Param("function", Word), Param("additional", List)]),
	Command("pause", 4, [Param("frames", Byte)]),
	Command("waitstate", 5, []),
	Command("nop", 6, []),
	Command("nop", 7, []),
	Command("end", 8, []),
	Command("playsound", 9, [Param("sound", Halfword)]),
	Command("enable_oam_as_target", 10, [Param("slot", Byte)]),
	Command("disable_oam_as_target", 11, [Param("slot", Byte)]),
	Command("enablebld", 12, [Param("bld", Halfword)]),
	Command("resetbld", 13, []),
	Command("call", 14, [Param("subscript", ScriptReference)]),
	Command("return", 15, []),
	Command("setadditional", 16, [Param("id", Byte), Param("value", Halfword)]),
	Command("goto_if_charging_state_bit_0", 17, [Param("subscript", ScriptReference)]),
	Command("goto_if_charging_state_equals", 18, [Param("value", Byte), Param("subscript", ScriptReference)]),
	Command("jump", 19, [Param("subscript", ScriptReference)]),
	Command("fade_into_background", 20, [Param("id", Byte)]),
	Command("fade_into_battle_background", 21, []),
	Command("wait", 22, []),
	Command("force_end_frame", 23, []),
	Command("display_background", 24, [Param("id", Byte)]),
	Command("playsound_modulation_user_target_based", 25, [Param("sound", Halfword), Param("modulation", Byte)]),
	Command("sound_apply_modulation_user_target_based", 26, [Param("modulation", Byte)]),
	Command("sound_modulation", 27, [Param("param4", Halfword), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte)]),
	Command("playsound4", 28, [Param("sound", Halfword), Param("modulation", Byte), Param("param3", Byte), Param("param3", Byte)]),
	Command("playsound5", 29, [Param("sound", Halfword), Param("modulation", Byte), Param("param2", Byte)]),
	Command("setbld", 31, [Param("param0", Halfword)]),
	Command("cmd20", 32, []),
	Command("goto_if_additional_equals", 33, [Param("id", Byte), Param("value", Halfword), Param("param3", ScriptReference)]),
	Command("something_with_poke_oam", 34, [Param("slot", Byte)]),
	Command("something_with_poke_oam_on_user", 35, [Param("slot", Byte)]),
	Command("nop", 36, [Param("unused", ScriptReference)]),
	Command("cmd25", 37, [Param("param2", Byte), Param("param2", Byte), Param("param2", Byte)]),
	Command("playsound", 38, [Param("param4", Halfword), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte)]),
	Command("cmd27", 39, [Param("param4", Halfword), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte), Param("param4", Byte)]),
	Command("cmd28", 40, [Param("param0", Byte)]),
	Command("cmd29", 41, []),
	Command("cmd2A", 42, [Param("param0", Byte)]),
	Command("cmd2B", 43, [Param("param0", Byte)]),
	Command("cmd2C", 44, [Param("param0", Byte)]),
	Command("cmd2E", 46, [Param("param0", Byte)]),
	Command("cmd2F", 47, []),

]

text = """loadgraphic 0x0 hword
cmd1 0x1 hword
loadoam 0x2 pointer:oam byte additional
loadcallback 0x3 word byte additional
pause 0x4 byte
waitstate 0x5
nop 0x6
nop 0x7
end 0x8
playsound 0x9 hword
cmdA 0xA byte
cmdB 0xB byte
enablebld 0xC hword
resetbld 0xD
call 0xE pointer:script
return 0xF
cmd10 0x10 byte hword
jumpifbitset 0x11 pointer:script pointer:script
jumpifbyte 0x12 byte pointer:script
jump 0x13 pointer:script
cmd14 0x14 byte
cmd15 0x15
halt1 0x16
halt2 0x17
loadbackground 0x18 byte
playsound2 0x19 hword byte
playsound3 0x1A byte
cmd1B 0x1B hword byte byte byte byte
playsound4 0x1C hword byte byte byte
cmd1D 0x1D hword byte byte
setbld 0x1F hword
cmd20 0x20
jumpifside 0x21 byte byte byte pointer:script
cmd22 0x22 byte
cmd23 0x23 byte
call2 0x24 pointer:script
cmd25 0x25 byte byte byte
playsound 0x26 hword byte byte byte byte
cmd27 0x27 hword byte byte byte byte
cmd28 0x28 byte
cmd29 0x29
cmd2A 0x2A byte
cmd2B 0x2B byte
cmd2C 0x2C byte
cmd2E 0x2E byte
cmd2F 0x2F
""".split("\n")

o = ""
for line in text:
    if line:
        tokens = line.split(" ")
        name = tokens[0]
        id = int(tokens[1], 0)
        params = []
        for i in range(2, len(tokens)):
            if tokens[i] == "byte":
                params.append("Byte")
            elif tokens[i] == "hword":
                params.append("Halfword")
            elif tokens[i] == "word":
                params.append("Word")
            elif tokens[i] == "additonal":
                params.append("ListTail")
            elif tokens[i] == "pointer:script":
                params.append("ScriptReference")
            else:
                params.append(tokens[i])
        o += "\tCommand(\"" + name + "\", " + str(id) + ", " + "[" + ", ".join(["Param(\"param" +str(i-2)+"\", " + param + ")" for param in params]) + "]),\n"
open("D:/temp/attackscript.txt", "w+").write(o)


