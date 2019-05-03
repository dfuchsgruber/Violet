#include "types.h"
#include "stdbool.h"
#include "transparency.h"
#include "constants/flags.h"
#include "flags.h"
#include "overworld/map_control.h"
#include "io.h"
#include "constants/specials.h"

u16 transparency_disabling_special_ids [] = {
    0xF9, 0x190, 0xFD, 0xFE, SPECIAL_SELECT_PARTY_POKEMON, 0x2B, 0x2C, SPECIAL_DAYCARE_SELECT_PARTY_POKEMON,
    SPECIAL_PARTY_POKEMON_SELECT_MOVE, SPECIAL_MOVE_TUTOR_SELECT_POKEMON, 0xFFFF};
u8 transparency_disabling_command_ids [] = {0x2, 0x97, 0x5C, 0x5D, 0xB7, 0x29, 0x8E,
    0x86, 0x39, 0x6B, 0x6C, 0xFF};

void transparency_handler(u8 *command) {
    //dprintf("Story progress is %d\n", *var_access(0x4051));
    //dprintf("Transparency handler, cmd %x @ %x\n", *command, command);
    if (*command != 0x27) { //waitstate bypasses the entire handle
        if (transparency_is_on()) {
            //We check if have a special that disables the transparency
            if (*command == 0x26 || *command == 0x25) {
                //Now we set together the param
                u16 special_id = (u16) (command[1] | (command[2] << 8));
                int i;
                for (i = 0; transparency_disabling_special_ids[i] != 0xFFFF; i++) {
                    if (transparency_disabling_special_ids[i] == special_id) {
                        transparency_off();
                        return;
                    }
                }
            } else {
                //We check if the command itself disables the transparency
                int i;
                for (i = 0; transparency_disabling_command_ids[i] != 0xFF; i++) {
                    if (transparency_disabling_command_ids[i] == *command) {
                        transparency_off();
                        return;
                    }
                }
            }
            transparency_on();
        } else {
            transparency_off();
        }
    }

}

bool transparency_load_black_pal() {
    return checkflag(TRANS_PALETTE_FETCH);
}

bool transparency_is_on() {
    //dprintf("Transparency used by weather %d, bypassed %d\n", transparency_used_by_weather(), checkflag(FLAG_BYPASS_TRANSPARENCY));
    return !checkflag(TRANS_DISABLE) && !transparency_used_by_weather();
}

bool transparency_used_by_weather() {
    u8 current_weather =  map_get_current_weather();
    return current_weather == 6 || current_weather == 8 || current_weather == 9 || current_weather == 0xA;
}

void transparency_on() {
    if (transparency_used_by_weather())
        return;
    setflag(TRANS_PALETTE_FETCH);
    io_set(0x48, 0x1F3F);
    io_set(0x50, 0x3F41);
    io_set(0x52, 0x060F);
}

void transparency_off() {
    if (!transparency_used_by_weather()) {
        io_set(0x48, 0x1F1F);
        io_set(0x50, 0x1E40);
        io_set(0x52, 0x0010);
    }
    clearflag(TRANS_PALETTE_FETCH);

}
