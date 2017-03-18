import violet
import img_dump
import constants
import os, sys

vdata = violet.violet_open()

fsprites = violet.pointer(vdata, 0x128)
bsprites = violet.pointer(vdata, 0x12C)
npals = violet.pointer(vdata, 0x130)
spals = violet.pointer(vdata, 0x134)
icons = violet.pointer(vdata, 0x138)
icon_usage = violet.pointer(vdata, 0x13C)
icon_pals = violet.pointer(vdata, 0x8AC44)

out = "D:/temp/pokesicons"

errors = []

for i in range(0, len(constants.species_table)):
    try:
        pkname = "species_"+"{0:0=3d}".format(i)+"_"+constants.species_table[i].lower()
        outpath = out + "/"
        try: os.makedirs(outpath) 
        except: pass

        """
        #Dump the front sprite
        fsprite_off = violet.pointer(vdata, fsprites + 8 * i)
        npal_off = violet.pointer(vdata, npals + 8 * i)
        bsprite_off = violet.pointer(vdata, bsprites + 8 * i)
        spal_off = violet.pointer(vdata, spals + 8 * i)

        #Dump img files
        img_dump.dump_png(outpath+"gfx_pkmn_"+pkname+"_frontsprite.png", 
            vdata, fsprite_off, 64, 64, npal_off, 16, img_lz77=True, pal_lz77=True, depth=4)
        img_dump.dump_png(outpath+"gfx_pkmn_"+pkname+"_backsprite.png", 
            vdata, bsprite_off, 64, 64, spal_off, 16, img_lz77=True, pal_lz77=True, depth=4)

        #Dump grit files
        f = open(outpath+"gfx_pkmn_"+pkname+"_frontsprite.grit", "w+")
        f.write("-gu32 -gzl -gB 4 -gt -p -pu16 -pzl -m!")
        f.close()
        f = open(outpath+"gfx_pkmn_"+pkname+"_backsprite.grit", "w+")
        f.write("-gu32 -gzl -gB 4 -gt -p -pu16 -pzl -m!")
        f.close()
        """
        #Dump the icon
        icon_off = violet.pointer(vdata, icons + 4 * i)
        icon_pal = vdata[icon_usage + i]
        print(icon_pal)
        icon_pal_off = icon_pals + 32 * icon_pal


        #Dump img and grit
        img_dump.dump_png(outpath+"gfx_pkmn_"+pkname+"_icon.png", vdata, icon_off, 32, 64, icon_pal_off, 16)
        
        print("Dumped ", pkname)
    except Exception as e:
        errors.append("Error at "+pkname+", :"+str(e))



print(errors)


