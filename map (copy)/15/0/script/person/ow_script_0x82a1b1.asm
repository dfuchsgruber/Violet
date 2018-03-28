.include "overworld_script.s"

.include "std.s"

.global ow_script_0x82a1b1
ow_script_0x82a1b1:
loadpointer 0x0 str_0x8bfaa5
callstd MSG_FACE
end

.global str_0x8bfaa5

str_0x8bfaa5:
    .string "Die Zucht ist eine Wissenschaft.\nWusstest du, dass Pokémon ganz\lpersönliche Gene haben, die über\lihre Fähigkeiten im Kampf\lbestimmen? Diese Gene können dann\lvon den Eltern an ihre Kinder\lvererbt werden. Sogar Angriffe\lsind genetisch bedingt.\pSpannend, nicht?"
        
        