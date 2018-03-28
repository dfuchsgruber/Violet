.include "overworld_script.s"

.include "std.s"

.global ow_script_0x858dc8
ow_script_0x858dc8:
loadpointer 0x0 str_0x965e52
callstd MSG_FACE
end

.global str_0x965e52

str_0x965e52:
    .string "Wir in Inferior sind nicht\nunbedingt zufrieden mit den\lVerhältnissen.\pGrenzgebiete wie dieses sind unter\nden Top Vier sehr umkämpft und am\lEnde muss der einfache Mann dafür\lbezahlen."
        
        