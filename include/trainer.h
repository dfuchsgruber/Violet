#ifndef H_TRAINER
#define H_TRAINER

#include "pokemon.h"
#include "types.h"
#include "stdbool.h"


#define FLAG_IS_FRACTION_CHOSEN 0x925
#define FLAG_IS_REVOLUTION_FRACTION 0x926

#define TRAINERCLASS_REVOLUTIONARY 3
#define TRAINERCLASS_RIVAL 0x51
#define TRAINERCLASS_GYMLEADER 0x54
#define TRAINERCLASS_TEAM_VIOLET 0x55

typedef struct trainer{
	u8 struct_info;
	u8 trainerclass;
	struct encounter_and_gender{
            u8 encounter : 7;
            u8 gender : 1;
        }encounter_and_gender;
	u8 field_2;
	u8 name[8];
	u8 unkown_fields[0x1C];
	
}trainer;

typedef struct build_field{
	u8 build : 5;
	u8 ability : 1;
	u8 hability : 1;
	u8 shinyness : 1;
	
}build_field;

typedef struct build{
	u8 nature : 5;
	u8 evs[6];
	u16 prefered_item;
} build;

union union_build_field{
	u8 value;
	build_field bitfield;
};

typedef struct trainer_items{
	
	u16 items[4];
	u8 cnt;
	
}trainer_items;

typedef struct trainer_variables{
    u16 kind_of_battle;
    u16 trainer_id;
    u16 overworld_target;
    u16 padding;
    pstring *challange_text;
    pstring *defeat_text;
    u16 trainer_var_0;
    u16 trainer_var_1;
    script *script_later;
    script *script_continue;
    u16 reserved_word_xse;
    
}trainer_variables;


trainer* trainers = (trainer*)0x0823E998;
trainer_variables *trainer_vars = (trainer_variables*)0x020386AC;

void build_trainer_poke(union union_build_field field, pokemon *poke);

void load_trainer_items (trainer_items *t_items);

bool checktrainerflag(u16 trainer_id);
bool trainer_can_npc_challange_player(u16 trainer_id);
bool special_x36_check_loaded_trainerflag();
void special_prepeare_player_facing();

#endif