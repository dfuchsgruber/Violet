.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86b31f
ow_script_0x86b31f:
loadpointer 0x0 str_0x87aba7
callstd MSG_SIGN
end

.global str_0x87aba7

str_0x87aba7:
    .string "!VORSICHT!\nWilde BIBOR! Bei Stichen sofort\lGEGENGift auftragen!"
        
        