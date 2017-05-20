import agb
import constants

violet = agb.Agbrom()
frd = agb.Agbrom(agb.FRDPATH)

item_effect_table = 0x2527E0
for i in range(0, len(constants.item_table)-13):
    vptr = violet.pointer(item_effect_table + i * 4)
    fptr = frd.pointer(item_effect_table + i * 4)
    if vptr != fptr:
        try:
            vdata = violet.array(vptr, 7) if vptr > 0 else None
            fdata = frd.array(fptr, 7) if fptr > 0 else None
            print("Dif at", i+13, "=", constants.item_table[i+13], "\n\tViolet at", hex(vptr), ":", vdata, "\n\tFrd at", hex(fptr), ":", fdata)
        except Exception as e:
            print(e, "at", hex(i), hex(vptr), hex(fptr))