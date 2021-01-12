#include "types.h"
#include "stdbool.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"

void debug1(int a){
    while(true){}
    a--;
}

void debug2(int a, int b){
    while(true){}
    a--;
    b--;
}

void debug3(int a, int b, int c){
    while(true){}
    a--;
    b--;
    c--;
}

void debug4(int a, int b, int c, int d){
    while(true){}
    a--;
    b--;
    c--;
    d--;
}

void debugn(int *n){
    while(true){}
    n[0] = 0;
}

void err(int e){
    debug4(e, -1, -1, -1);
}

void err2(int e, int p){
    debug4(e, p, -1, -1);
}

void print_flags() {
    for (u16 flag = 0x900; flag < 0xb00; flag++) {
        dprintf("Flag %d: %d\n", flag, checkflag(flag));
    }
}

void print_vars() {
    for (u16 var = 0x5000; var < 0x5100; var++) {
        dprintf("Var %d: 0x%x\n", var, *var_access(var));
    }
}