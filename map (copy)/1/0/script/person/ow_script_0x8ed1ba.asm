.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ed1ba
ow_script_0x8ed1ba:
trainerbattlestd 0x0 0x48 0x0 str_0x8f448d str_0x8f4519
loadpointer 0x0 str_0x8f4519
callstd MSG_FACE
end

.global str_0x8f448d

str_0x8f448d:
    .string "Unsere Gesellschaft beutet den\nEinzelnen aus. Korruption und\lVerzweiflung sind die Folge.\lWir kreieren eine Welt, in der es\lFrieden gibt."
        
        
.global str_0x8f4519

str_0x8f4519:
    .string "Wir sind Teil des großen Plans,\nund du wirst uns nicht aufhalten!"
        
        