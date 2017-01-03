#ifndef H_OVERWORLD_SCRIPT
#define H_OVERWORLD_SCRIPT

#include "types.h"
#include "unaligned_types.h"

#define O_SCRIPT_END 2
#define O_SCRIPT_RETURN 3
#define O_SCRIPT_LOADPOINTER(bank, data) 0xF, bank, UA_WORD(data)
#define O_SCRIPT_CALL(script) 5, UA_WORD(script)
#define O_SCRIPT_CALLSTD(id) 9, id
#define O_SCRIPT_SETVAR(var, value) 0x16, UA_HWORD(var), UA_HWORD(value)
#define O_SCRIPT_COPYVARIFNOTZERO(dest, src) 0x1A, UA_HWORD(dest), UA_HWORD(src)
#define O_SCRIPT_SPECIAL(specialid) 0x25, UA_HWORD(specialid)
#define O_SCRIPT_WAITSTATE 0x27
#define O_SCRIPT_LOCKALL 0x69


#define O_SCRIPT_MSGBOX(text, callstd) O_SCRIPT_LOADPOINTER(0, text), O_SCRIPT_CALLSTD(callstd)

#endif