.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x87f98b
ow_script_0x87f98b:
checkflag SILVANIA_BERRY_JUICE
gotoif EQUAL ow_script_0x8deb07
lock
faceplayer
loadpointer 0x0 str_0x8dee30
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8deafd
loadpointer 0x0 str_0x8deadb
callstd MSG
copyvarifnotzero 0x8000 ITEM_BEERENSAFT
copyvarifnotzero 0x8001 ITEM_TOP_BELEBER
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8dec8a
callstd MSG
setflag SILVANIA_BERRY_JUICE
release
end


.global ow_script_0x8deafd
ow_script_0x8deafd:
loadpointer 0x0 str_0x8decc8
callstd MSG_FACE
end


.global ow_script_0x8deb07
ow_script_0x8deb07:
loadpointer 0x0 str_0x8dec8a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8dee30

str_0x8dee30:
    .string "Beeren sind auf viele Arten\nnützlich. Während einige von ihnen\lbei Statusproblemen helfen, kann\lman aus anderen Beerensaft\lgewinnen.\pFindest du Beeren nicht auch\neinfach toll?"
        
        
.global str_0x8deadb

str_0x8deadb:
    .string "Gut geantwortet! Nimm das hier!"
        
        
.global str_0x8dec8a

str_0x8dec8a:
    .string "Beerensaft füllt die Kraftpunkte\neines Pokémons wieder auf."
        
        
.global str_0x8decc8

str_0x8decc8:
    .string "Das ist ein Jammer! Jeder Trainer\nsollte das Potenzial einer Beere\lzu schätzen wissen."
        
        
.elseif LANG_EN

.endif
