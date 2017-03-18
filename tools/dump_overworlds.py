import violet
import img_dump
import constants
import os, sys

vdata = violet.violet_open()

ow_base = 0xC80000
ow_pals = 0x3A501C
out = "D:/temp/ow/"

anims ={
    0x083A322C : "OW_ANIM_STANDARD_NPC",
    0x083A3280 : "OW_ANIM_HO_OH ",
    0x083A3334 : "OW_ANIM_HIRO",
    0x83A3448 : "OW_ANIM_HIRO_SIT",
    0x83A34FC : "OW_ANIM_HIRO_CALL",
    0x83A352C : "OW_ANIM_HIRO_ROD",
    0x83A3500 : "OW_ANIM_HIRO_CALL2",
    0x83A3504 : "OW_ANIM_HIRO_CALL_BIKE",
    0x83A31D8 : "Ow_ANIM_NONE",
}

formations = {

    0x083A3660 : "OW_FORMATION_16_32",
    0x083A3914 : "OW_FORMATION_128_64",
    0x083A36B4 : "OW_FORMATION_32_32",
    0x083A3794 : "OW_FORMATION_64_64",
    0x83A360C : "OW_FORMATION_16_16",
}

final_oams = {

    0x083A35D4 : "OW_FINAL_OAM_16_32",
    0x083A35A4 : "OW_FINAL_OAM_128_64",
    0x083A35E4 : "OW_FINAL_OAM_64_64",
    0x083A35DC : "OW_FINAL_OAM_32_32",
    0x83A35B4 : "OW_FINAL_OAM_16_16",

}

rs = {
    0x08231BCC : "ROTSCALE_TABLE_NULL",
}


while True:
    try:
        cmd = input("Enter cmd ([ow id] [graphic_cnt] [label])").split(" ")
        ow_id = int(cmd[0])
        graphic_cnt = int(cmd[1])
        label = cmd[2]

        off = violet.pointer(vdata, ow_base + 0x4 * ow_id)

        #Extract all information

        tiles_tag = violet.read_16(vdata, off)
        pal_tag = violet.read_16(vdata, off+2)
        u = violet.read_16(vdata, off+4)
        data_size = violet.read_16(vdata, off+6)
        width = violet.read_16(vdata, off+8)
        height = violet.read_16(vdata, off+0xA)
        mirror_pal = vdata[off+0xC]
        field_d = vdata[off+0xD]
        field_e = vdata[off+0xE]
        field_f = vdata[off+0xF]
        final_oam_ptr = violet.read_32(vdata, off+0x10)
        formation_ptr = violet.read_32(vdata, off+0x14)
        animation_ptr = violet.read_32(vdata, off+0x18)
        graphic_off = violet.pointer(vdata, off+0x1C)
        rotscale_frame_ptr = violet.read_32(vdata, off+0x20)

        print(hex(tiles_tag), hex(pal_tag))

        #Find the palette
        pal = None
        for j in range (0, 18):
            tag = violet.read_16(vdata, ow_pals + j * 8 + 4)
            if tag == pal_tag:
                pal = violet.pointer(vdata, ow_pals + j * 8)
                break
        if not pal: raise Exception("No matching pal found for tag "+str(pal_tag))
        
        declarations = []
        graphic_table = []

        #Dump png and grit files
        for j in range (0, graphic_cnt):
            outgname = out+"gfx_ow_"+label+"_"+str(j)
            img_off = violet.pointer(vdata, graphic_off + j * 8)
            img_dump.dump_png(outgname+".png", vdata, img_off, width, height, pal, 16)
            gf = open(outgname+".grit", "w+")
            gf.write("-gu32 -gz! -gB 4 -gt -m! -p!")
            gf.close()
            declarations.append("extern const unsigned short gfx_ow_"+label+"_"+str(j)+"Tiles[];")
            graphic_table.append("\t{&gfx_ow_"+label+"_"+str(j)+"Tiles, "+str(hex(data_size))+", 0}")

        declarations = "\n".join(declarations)
        graphic_table = "static graphic overworld_sprite_"+label+"_sprites[] = {\n"+",\n".join(graphic_table)+"\n};"

        #Generate code
        ow_code = "overworld_sprite ow_"+label+" = {\n"
        ow_code += "\t"+str(hex(tiles_tag))+", "+str(hex(pal_tag))+", "+str(hex(u))+", "+str(hex(data_size))+",\n"
        ow_code += "\t"+str(width)+", "+str(height)+", "+str(hex(mirror_pal))+", "+str(hex(field_d))+", "+str(hex(field_e))+", "+str(hex(field_f))+",\n"
        ow_code += "\t"+final_oams[final_oam_ptr]+", "+formations[formation_ptr]+",\n"
        ow_code += "\t"+anims[animation_ptr]+", overworld_sprite_"+label+"_sprites, \n"
        ow_code += "\t"+rs[rotscale_frame_ptr]+"\n"
        ow_code += "};"

        code = "\n\n".join([declarations, graphic_table, ow_code])
        f = open(out+"gfx_ow_"+label+"code.c", "w+")
        f.write(code)
        f.close()

    except Exception as e:
        print("Error", e)
        raise e

    