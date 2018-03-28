.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8000a5
ow_script_0x8000a5:
lock
faceplayer
loadpointer 0x0 str_0x8000b2
callstd MSG
release
end

.global str_0x8000b2

str_0x8000b2:
    .string "Das sieht aus wie ein Shooter. Ich\nlasse besser die Finger davon, da\lSpiele ab 18 nicht für mich\lgeeignet sind. Ich würde sonst\lAmokläufer werden, denn das lässt\lsich nicht vermeiden, bei\lShooterspielen ab 18!"
        
        