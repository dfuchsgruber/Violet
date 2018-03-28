.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95fb87
ow_script_0x95fb87:
loadpointer 0x0 str_0x962d54
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x962d54

str_0x962d54:
    .string "Seit vielen Jahren ist dieses\nGebiet unter den Top Vier\lumkämpft.\pDer Schwarze Devin und der Rosa\nFaun haben einst einen Wettkampf\lüber die Herrschaft in diesem\lGebiet abgehalten.\pZwar ist der Schwarze Devin ein\nSchüler Fauns gewesen, doch konnte\ler seinen Meister nicht bezwingen.\pDa sieht man einmal wieder, dass\nman nicht zu überheblich werden\lsollte."
        
        
.elseif LANG_EN

.endif
