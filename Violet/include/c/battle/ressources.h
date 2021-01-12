#ifndef H_BATTLE_RESOURCES
#define H_BATTLE_RESOURCES

#include "types.h"
#include "battle/ai.h"

typedef struct {
    u8 *scripts[8];
    u8 size;
} script_list_t;

typedef struct {
    void (*callbacks[8])();
    u8 size;
} battle_callback_list_t;

typedef struct {
    u32 flags[4];
} battle_resource_flags_t;

#define RESOURCE_FLAG_FLASH_FIRE 1

typedef struct {
    void *secret_base;
    battle_resource_flags_t *flags;
    script_list_t *battle_script_stack;
    battle_callback_list_t *battle_callbacks;
    void *stats_before_levelup;
    ai_thinking_state_t *ai;
    void *history;
    script_list_t *ai_scripts_stack;
} battle_ressources_t;

extern battle_ressources_t *battle_ressources;

#endif