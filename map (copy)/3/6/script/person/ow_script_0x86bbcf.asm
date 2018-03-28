.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbcf
ow_script_0x86bbcf:
loadpointer 0x0 str_0x9659b6
callstd MSG_FACE
end

.global str_0x9659b6

str_0x9659b6:
    .string "Igva ist wirklich eine wahnsinns\nFrau!\pIch bin wohl nicht der einzige\nHitzkopf, der ein Auge auf dieses\lentflammte Mädchen geworfen hat!"
        
        