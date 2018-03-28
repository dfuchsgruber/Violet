.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94bf81
ow_script_0x94bf81:
loadpointer 0x0 str_0x94def6
callstd MSG
end

.global str_0x94def6

str_0x94def6:
    .string "Mann: Cecilia, du bist die Wärme\nund das Licht in meinem Leben.\lOhne dich herrscht Winter in\lmeinem Herzen und ich will keine\lSekunde mehr frieren müssen für\lden Rest meines Lebens.\l...\pWillst du meine Frau werden?\pFrau: Oh, das kommt ...\nüberraschend...\pMann: Was soll das heißen?"
        
        