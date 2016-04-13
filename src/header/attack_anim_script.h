#include "types.h"
#include "unaligned_types.h"


//define the attack script cmds
#define AS_LOAD_GRAPHIC(a) 0, UA_HWORD(a)
#define AS_LOAD_OAM(a, b, c) 2, UA_WORD(a), b, c
#define AS_LOAD_CB(a, b, c) 3, UA_WORD(a), b, c
#define AS_PAUSE(a) 4, a
#define AS_WAITSTATE 5
#define AS_END 8
#define AS_PLAYSOUND(a) 9, UA_HWORD(a)
#define AS_OAMS_ACESS(a) 0xA, a
#define AS_OAMS_LOCK(b) 0xB, b
#define AS_ENABLE_BLD(a) 0xC, UA_HWORD(a)
#define AS_DISABLE_BLD 0xD
#define AS_CALL(a) 0xE, UA_WORD(a)
#define AS_RETURN 0xF






