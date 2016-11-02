
#ifndef HBATTLE
#define HBATTLE

typedef struct battle_flag {
    u32 double_battle : 1;
    u32 link_battle : 1;
    u32 wild_battle : 1;
    u32 trainer_battle : 1;
    u32 oak_battle : 1;
    u32 flag_5 : 1;
    u32 multi_battle : 1;
    u32 safari_battle : 1;
    u32 items_prohibited : 1;
    u32 catch_tutorial : 1;
    u32 flag_A : 1;
    u32 items_prohibited2 : 1;
    u32 flag_C : 1;
    u32 flag_D : 1;
    u32 unkown : 18;
} battle_flag;

battle_flag *battle_flags = (battle_flag*) 0x02022B4C;

typedef struct battler {
    u16 species;
    u16 stats[5];
    u16 moves[4];
    u32 ivs;
    u8 stat_changes[8];
    u8 ability;
    u8 type1;
    u8 type2;
    u8 field_23;
    u8 current_pp[4];
    u16 current_hp;
    u8 level;
    u8 happiness;
    u16 max_hp;
    u16 item;
    u8 name[11];
    u8 trigger;
    u8 ot[8];
    u32 padding3;
    u32 pid;
    u32 status1;
    u32 field_50;
    u32 tid;
} battler;

typedef struct battle_bg {
    const void *tileset;
    const void *tilemap;
    const void *anim_tileset;
    const void *anim_tilemap;
    const void *pal;
} battle_bg;

battle_bg battle_bgs[29];

u16 can_mega_evolve(battler *b);

battler* battlers = (battler*) 0x02023BE4;
u8 *attack_targets = (u8*) 0x02023BD6;
u8 *battler_oams = (u8*) 0x02023D44;
u8 *battler_cnt = (u8*) 0x02023BCC;
u16 *trainer_id = (u16*) 0x020386AE;

#endif