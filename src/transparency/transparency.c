#include "types.h"
#include "romfuncs.h"
#include "transparency.h"
#include "stdbool.h"
#include "map.h"

u16 transparency_disabling_special_ids [] = {0xF9, 0x190, 0xFD, 0xFE, 0x9F, 0x2B, 0x2C, 0xFFFF};
u8 transparency_disabling_command_ids [] = {0x2, 0x97, 0x5C, 0x5D, 0xB7, 0x29, 0x8E,
                      0x86, 0x39, 0xFF};


void transparency_handler(u8 *command){
    if (*command != 0x27){ //waitstate bypasses the entire handle
        if (transparency_is_on()){
            //We check if have a special that disables the transparency
            if (*command == 0x26 || *command == 0x25){
                //Now we set together the param
                u16 special_id = (u16)(command[1] || (command[2] << 8));
                int i;
                for(i = 0; transparency_disabling_special_ids[i] != 0xFFFF; i++){
                    if (transparency_disabling_special_ids[i] == special_id){
                        transparency_off();
                        return;
                    }
                }
            }else{
                //We check if the command itself disables the transparency
                int i;
                for (i = 0; transparency_disabling_command_ids[i] != 0xFF; i++){
                    if(transparency_disabling_command_ids[i] == *command){
                        transparency_off();
                        return;
                    }
                }
            }
            transparency_on();
        }else{
            transparency_off();
        }
    }
    
}

bool transparency_load_black_pal(){
    return checkflag(FLAG_TRANSPARENCY_ON);
}

bool transparency_is_on(){
    return !checkflag(FLAG_BYPASS_TRANSPARENCY) && !transparency_used_by_weather();
}

bool transparency_used_by_weather(){
    u8 current_weather = *((u8*)0x0202555A);
    return current_weather == 6 || current_weather == 8 || current_weather == 9 || current_weather == 0xA;
}

void transparency_on(){
    if (transparency_used_by_weather())
        return;
    setflag(FLAG_TRANSPARENCY_ON);
    set_io(0x48, 0x1F3F);
    set_io(0x50, 0x3F41);
    set_io(0x52, 0x060F);
}

void transparency_off(){
    if (!transparency_used_by_weather()){
        set_io(0x48, 0x1F1F);
        set_io(0x50, 0x1E40);
        set_io(0x52, 0x0010);
    }
    clearflag(FLAG_TRANSPARENCY_ON);
    
}