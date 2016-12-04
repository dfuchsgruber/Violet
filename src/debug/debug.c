#include "types.h"
#include "stdbool.h"
#include "debug.h"

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
