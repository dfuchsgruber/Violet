.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9270c4
ow_script_0x9270c4:
checkflag ROUTE_2_LINKCABLE
gotoif EQUAL ow_script_0x8aaf95
lock
faceplayer
loadpointer 0x0 str_0x8abe1c
callstd MSG
copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8ab77f
callstd MSG
setflag ROUTE_2_LINKCABLE
release
end


.global ow_script_0x8aaf95
ow_script_0x8aaf95:
loadpointer 0x0 str_0x8ab6bf
callstd MSG_FACE
end

.global str_0x8abe1c

str_0x8abe1c:
    .string "Acht lange Jahre habe ich für die\nLaz.Corp geschuftet. Acht lange\lJahre habe ich mich der\lEntwicklung von Software gewidmet.\lAcht lange Jahre habe ich\lkaltherzig Pokémon ausgebeutet,\lnur des Fortschritt wegens.\lJetzt endlich habe ich meine\lFehler eingesehen. Es ist falsch,\lPokémon für kommerzielle Zwecke\lauszunutzen.\lHier, nimm das. Ich habe dafür\lkeine Verwendung mehr."
        
        
.global str_0x8ab77f

str_0x8ab77f:
    .string "Das Linkkabel simuliert einen\nechten Pokémon Tausch, sodass\ljene, die sich erst im Tausch\lentwickeln, auf diese Weise zu\lihrer Evolution gelangen können.\lIst es nicht grotesk, wozu unsere\lTechnik fähig ist? Pokémon zur\lEvolution zwingen? ...\lAber nicht mit mir... Soll die\lLaz.Corp doch machen, was sie für\lrichtig hält. Ich halte mich da ab\ljetzt raus!"
        
        
.global str_0x8ab6bf

str_0x8ab6bf:
    .string "Mein Boss wollte, dass ich ein\nRaum-Zeit-Portal konstruiere, dass\ldie Lebensenergie von Pokémon als\lEnergiequelle nutzt... Ab diesem\lPunkt war mir klar, dass es so\lnicht weitergehen kann..."
        
        