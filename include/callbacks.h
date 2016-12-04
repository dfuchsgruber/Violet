#ifndef H_CALLBACK
#define H_CALLBACK

#define CALLBACK_OBJECT(x) ((big_callback*)((x*sizeof(big_callback))+0x03004FE0))

void nullsub();

typedef struct {
    void (*function)(u8 self);
    u8 active_state;
    u8 u1;
    u8 u2;
    u8 u3;
    u16 params [0x10];
} big_callback;

big_callback *big_callbacks = (big_callback*) 0x03004FE0;

#endif
