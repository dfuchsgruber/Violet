typedef struct basestats {
	u8 base_hp;
	u8 base_atk;
	u8 base_def;
	u8 base_speed;
	u8 base_satk;
	u8 base_sdef;
	u8 type1;
	u8 type2;
	u8 catch_rate;
	u8 exp_yield;
	u16 ev_yield;
	u16 common_item;
	u16 rare_item;
	u8 gender_value;
	u8 egg_cycles;
	u8 base_happiness;
	u8 level_up_type;
	u8 egg_group_1;
	u8 egg_group_2;
	u8 ability1;
	u8 ability2;
	u8 safari_rate;
	u8 color_flip_field;
	u8 hidden_ability;
	u8 field_1B;
} basestats;

basestats* bstats = (basestats*)0x082546A8;
