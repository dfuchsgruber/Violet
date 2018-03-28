.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8ecd19
ow_script_movs_0x8ecd19:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x780a53
ow_script_0x780a53:
lock
faceplayer
applymovement 0x800f ow_script_movs_0x8ecd19
waitmovement 0x0
loadpointer 0x0 str_0x8f4305
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM46
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
lock
faceplayer
loadpointer 0x0 str_0x8ef5ca
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER
.global str_0x8f4305

str_0x8f4305:
    .string "Du schon wieder! Du hast mich und\nmeine Pokémon in Meriana City\lschon besiegt...\lHier, nimm das und lass mich\lgefälligst in Ruhe!"
        
        
.global str_0x8ef5ca

str_0x8ef5ca:
    .string "Buhu! Ich wollte doch nur etwas\nbewirken..."
        
        
.elseif LANG_EN

.endif
