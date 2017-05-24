import violet
import img_dump
import constants
import os, sys

output_devices = {
    0 : "DirectSound",
    1 : "SquareWave1",
    2 : "SquareWave2",
    3 : "ProgWave",
    4 : "ProgNoise",
    8 : "DirectSoundFix",
    0x10 : "DirectComp",
    0x30 : "ReverseComp"
}

table_type = {
    0x40 : "KeySplit",
    0x80 : "DrumTable"
}

wave_patterns = {
    0x3 : "WaveDuty75",
    0x2 : "WaveDuty50",
    0x1 : "WaveDuty25",
    0x0 : "WaveDuty12",

}


noise_patterns = {
    0x0 : "FineNoise",
    0x1 : "RoughNoise"
}


keys = {
    
	"CnM2" : 0,
	"CsM2" : 1,
	"DnM2" : 2,
	"DsM2" : 3,
	"EnM2" : 4,
	"FnM2" : 5,
	"FsM2" : 6,
	"GnM2" : 7,
	"GsM2" : 8,
	"AnM2" : 9,
	"AsM2" : 10,
	"BnM2" : 11,
	"CnM1" : 12,
	"CsM1" : 13,
	"DnM1" : 14,
	"DsM1" : 15,
	"EnM1" : 16,
	"FnM1" : 17,
	"FsM1" : 18,
	"GnM1" : 19,
	"GsM1" : 20,
	"AnM1" : 21,
	"AsM1" : 22,
	"BnM1" : 23,
	"Cn0" : 24,
	"Cs0" : 25,
	"Dn0" : 26,
	"Ds0" : 27,
	"En0" : 28,
	"Fn0" : 29,
	"Fs0" : 30,
	"Gn0" : 31,
	"Gs0" : 32,
	"An0" : 33,
	"As0" : 34,
	"Bn0" : 35,
	"Cn1" : 36,
	"Cs1" : 37,
	"Dn1" : 38,
	"Ds1" : 39,
	"En1" : 40,
	"Fn1" : 41,
	"Fs1" : 42,
	"Gn1" : 43,
	"Gs1" : 44,
	"An1" : 45,
	"As1" : 46,
	"Bn1" : 47,
	"Cn2" : 48,
	"Cs2" : 49,
	"Dn2" : 50,
	"Ds2" : 51,
	"En2" : 52,
	"Fn2" : 53,
	"Fs2" : 54,
	"Gn2" : 55,
	"Gs2" : 56,
	"An2" : 57,
	"As2" : 58,
	"Bn2" : 59,
	"Cn3" : 60,
	"Cs3" : 61,
	"Dn3" : 62,
	"Ds3" : 63,
	"En3" : 64,
	"Fn3" : 65,
	"Fs3" : 66,
	"Gn3" : 67,
	"Gs3" : 68,
	"An3" : 69, #440 Hz "Kammerton"
	"As3" : 70,
	"Bn3" : 71,
	"Cn4" : 72,
	"Cs4" : 73,
	"Dn4" : 74,
	"Ds4" : 75,
	"En4" : 76,
	"Fn4" : 77,
	"Fs4" : 78,
	"Gn4" : 79,
	"Gs4" : 80,
	"An4" : 81,
	"As4" : 82,
	"Bn4" : 83,
	"Cn5" : 84,
	"Cs5" : 85,
	"Dn5" : 86,
	"Ds5" : 87,
	"En5" : 88,
	"Fn5" : 89,
	"Fs5" : 90,
	"Gn5" : 91,
	"Gs5" : 92,
	"An5" : 93,
	"As5" : 94,
	"Bn5" : 95,
	"Cn6" : 96,
	"Cs6" : 97,
	"Dn6" : 98,
	"Ds6" : 99,
	"En6" : 100,
	"Fn6" : 101,
	"Fs6" : 102,
	"Gn6" : 103,
	"Gs6" : 104,
	"An6" : 105,
	"As6" : 106,
	"Bn6" : 107,
	"Cn7" : 108,
	"Cs7" : 109,
	"Dn7" : 110,
	"Ds7" : 111,
	"En7" : 112,
	"Fn7" : 113,
	"Fs7" : 114,
	"Gn7" : 115,
	"Gs7" : 116,
	"An7" : 117,
	"As7" : 118,
	"Bn7" : 119,
	"Cn8" : 120,
	"Cs8" : 121,
	"Dn8" : 122,
	"Ds8" : 123,
	"En8" : 124,
	"Fn8" : 125,
	"Fs8" : 126,
	"Gn8" : 127
}

c_v = 0xC0 #Center of PAN

vdata = violet.violet_open()

vcg0 = 0x16928E0
drumset0 = 0x488598

content = ""

def key_to_num(key):
    for k in keys:
        if keys[k] == key: return k
    print("Warning: Undefined key", hex(key))
    return str(hex(key))

for i in range(0,128):
    print("Dumping instrumenet",i)
    content += "\n\n@**************** Voice "+"{0:0=3d}".format(i)+" ****************@\n\n"
    vcg_off = drumset0 + 12 * i

    #Output Device
    output_device = vdata[vcg_off]
    if output_device in output_devices:
        content += "\t\t.byte\t"+output_devices[output_device]+"\n"
        content += "\t\t.byte\t"+key_to_num(vdata[vcg_off+1])+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+2]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+3]))+"\n"
        content += "\t\t.word\t"+str(hex(violet.read_32(vdata, vcg_off+4)))+"\n"
    elif output_device in table_type:
        content += "\t\t.byte\t"+table_type[output_device]+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+1]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+2]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+3]))+"\n"
        content += "\t\t.word\t"+str(hex(violet.read_32(vdata, vcg_off+4)))+"\n"
        if output_device == 0x40: #Key Split, interpret last as pointer
            content += "\t\t.word\t"+str(hex(violet.read_32(vdata, vcg_off+8)))+"\n"
            continue
    else:
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+1]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+2]))+"\n"
        content += "\t\t.byte\t"+str(hex(vdata[vcg_off+3]))+"\n"
        content += "\t\t.word\t"+str(hex(violet.read_32(vdata, vcg_off+4)))+"\n"

    content += "\t\t.byte\t"+",".join([str(n) for n in vdata[vcg_off+8:vcg_off+12]])+"\n"

open("D:/temp/instr0ds.s", "w+").write(content)
    


