.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x947b32
ow_script_0x947b32:
checkflag AMONIA_RIVAL_ROOM_ITEM
gotoif EQUAL ow_script_0x89be13
loadpointer 0x0 str_0x89be1d
callstd MSG_YES_NO
compare LASTRESULT 0x1
callif EQUAL ow_script_0x85e7fa
closeonkeypress
setflag AMONIA_RIVAL_ROOM_ITEM
end


.global ow_script_0x85e7fa
ow_script_0x85e7fa:
loadpointer 0x0 str_0x89ae00
callstd MSG
setvar 0x8000 0xfd
special2 0x8000 0xc
return


.global ow_script_0x89be13
ow_script_0x89be13:
loadpointer 0x0 str_0x89be67
callstd MSG
end


.ifdef LANG_GER
.global str_0x89be1d

str_0x89be1d:
    .string "Dieser Pokeball scheint RIVAL zu\ngehören. Möchtest du ihn trotzdem\lnehmen?"
        
        
.global str_0x89ae00

str_0x89ae00:
    .string "RIVAL ist mein bester Freund...\nDas könnte ich nicht über mich\lbringen..."
        
        
.global str_0x89be67

str_0x89be67:
    .string "Dieser Pokeball gehört RIVAL."
        
        
.elseif LANG_EN

.endif
