
#ifndef HBATTLE
#define HBATTLE

#define CUSTOM_STATUS_AP_SPARER 1


#define ATTACK_MISSED 1
#define ATTACK_SUPER_EFFECTIVE 2
#define ATTACK_NOT_EFFECTIVE 4
#define ATTACK_NO_EFFECT 8
#define ATTACK_OHKO 16
#define ATTACK_FAILED 32
#define ATTACK_ENDURED 64
#define ATTACK_ENDURED_BY_FOCUS_SASH 128

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

typedef struct battler_status{
    u8 unkown[16];
}battler_status;

battler_status *battler_statuses = (battler_status*)0x02023E8C;

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
    u32 custom_status; //to apply hacks
    u32 pid;
    u32 status1;
    u32 status2;
    u32 tid;
} battler;

#define STATUS1_SLEEPING 7
#define STATUS1_POISONED 8
#define STATUS1_BURNED 16
#define STATUS1_BADLY_POISONED 0x80

#define STATUS2_ATTACK_CHARGED 0x1000

typedef struct battle_bg {
    const void *tileset;
    const void *tilemap;
    const void *anim_tileset;
    const void *anim_tilemap;
    const void *pal;
} battle_bg;

typedef struct  {
    const void *tileset;
    const void *pal;
    const void *map;
} battle_anim_bg;

battle_bg battle_bgs[29];

u16 can_mega_evolve(battler *b);


battler* battlers = (battler*) 0x02023BE4;
u8 *attack_targets = (u8*) 0x02023BD6;
u8 *attacking_battler = (u8*)0x02023D6B;
u8 *defending_battler = (u8*)0x02023D6C;
u8 *active_battler = (u8*)0x02023BC4;
u8 *battler_oams = (u8*) 0x02023D44;
u8 *battler_cnt = (u8*) 0x02023BCC;
u16 *trainer_id = (u16*) 0x020386AE;
u8 *stat_change = (u8*) 0x02023FC4;

u16 *active_attack = (u16*) 0x02023D4A;
u8 *active_attack_slot = (u8*)0x02023D48;
u32 *attack_result = (u32*)0x02023DCC;

int *damage_to_apply = (int*)0x2023D50;
int *damage_caused = (int*)0x02023D54;

u16 *battler_team_slots = (u16*) 0x02023BCE;

u32 *bsc_status_flags = (u32*)0x02023DD0;
u8 *bsc_buffers = (u8*)0x02022AB8;
u8 **bsc_offset = (u8**)0x02023D74;

u8 *attack_anim_target_index = (u8*)0x02037F1B;
u8 *attack_anim_user_index = (u8*)0x02037F1A;
u16 *attack_anim_additional_animation = (u16*)0x2037F02;
u8 *attack_anim_tasks_running = (u8*)0x02037EE2;

u8 *battler_temporary_status= (u8*)0x02023E8C;


#define BATTLE_WEATHER_RAIN 1
#define BATTLE_WEATHER_WOLKENBRUCH 2
#define BATTLE_WEATHER_RAIN_NIESEL 4
#define BATTLE_WEATHER_SANDSTORM 8
#define BATTLE_WEATHER_SANDSTORM_ABILITY 16
#define BATTLE_WEATHER_SUN 32
#define BATTLE_WEATHER_SUN_DUERRE 64
#define BATTLE_WEATHER_HAIL 128

u16 *battle_weather = (u16*) 0x02023F1C;

#define CUSTOM_TEMPORARY_STATUS_KINGS_SHIELD 1
#define CUSTOM_TEMPORARY_STATUS_KINGS_SHIELD_APPLY_DROP 2

void damage_apply_multiplier(int multiplier);

extern const unsigned short gfx_battle_bg_capturedTiles[];
extern const unsigned short gfx_battle_bg_caveTiles[];
extern const unsigned short gfx_battle_bg_cloudsTiles[];
extern const unsigned short gfx_battle_bg_desertTiles[];
extern const unsigned short gfx_battle_bg_evolutionTiles[];
extern const unsigned short gfx_battle_bg_fireTiles[];
extern const unsigned short gfx_battle_bg_grassTiles[];
extern const unsigned short gfx_battle_bg_gymTiles[];
extern const unsigned short gfx_battle_bg_millTiles[];
extern const unsigned short gfx_battle_bg_mountainTiles[];
extern const unsigned short gfx_battle_bg_museumTiles[];
extern const unsigned short gfx_battle_bg_oceanTiles[];
extern const unsigned short gfx_battle_bg_pondTiles[];
extern const unsigned short gfx_battle_bg_shoreTiles[];
extern const unsigned short gfx_battle_bg_streetTiles[];
extern const unsigned short gfx_battle_bg_watercaveTiles[];
extern const unsigned short gfx_stance_changeTiles[];

extern const unsigned short gfx_battle_bg_capturedPal[];
extern const unsigned short gfx_battle_bg_cavePal[];
extern const unsigned short gfx_battle_bg_cloudsPal[];
extern const unsigned short gfx_battle_bg_desertPal[];
extern const unsigned short gfx_battle_bg_evolutionPal[];
extern const unsigned short gfx_battle_bg_firePal[];
extern const unsigned short gfx_battle_bg_grassPal[];
extern const unsigned short gfx_battle_bg_gymPal[];
extern const unsigned short gfx_battle_bg_millPal[];
extern const unsigned short gfx_battle_bg_mountainPal[];
extern const unsigned short gfx_battle_bg_museumPal[];
extern const unsigned short gfx_battle_bg_oceanPal[];
extern const unsigned short gfx_battle_bg_pondPal[];
extern const unsigned short gfx_battle_bg_shorePal[];
extern const unsigned short gfx_battle_bg_streetPal[];
extern const unsigned short gfx_battle_bg_watercavePal[];
extern const unsigned short gfx_stance_changePal[];

extern const unsigned short gfx_battle_bg_capturedMap[];
extern const unsigned short gfx_battle_bg_caveMap[];
extern const unsigned short gfx_battle_bg_cloudsMap[];
extern const unsigned short gfx_battle_bg_desertMap[];
extern const unsigned short gfx_battle_bg_evolutionMap[];
extern const unsigned short gfx_battle_bg_fireMap[];
extern const unsigned short gfx_battle_bg_grassMap[];
extern const unsigned short gfx_battle_bg_gymMap[];
extern const unsigned short gfx_battle_bg_millMap[];
extern const unsigned short gfx_battle_bg_mountainMap[];
extern const unsigned short gfx_battle_bg_museumMap[];
extern const unsigned short gfx_battle_bg_oceanMap[];
extern const unsigned short gfx_battle_bg_pondMap[];
extern const unsigned short gfx_battle_bg_shoreMap[];
extern const unsigned short gfx_battle_bg_streetMap[];
extern const unsigned short gfx_battle_bg_watercaveMap[];
extern const unsigned short gfx_stance_changeMap[];


#endif