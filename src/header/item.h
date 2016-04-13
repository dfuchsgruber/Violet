typedef struct item {
	u8 name[14];
	u16 index;
	u16 price;
	u8 holding_effect_id;
	u8 holding_effect_param;
	u8 *description_ptr;
	u16 field_18;
	u8 pocket;
	u8 type;
	void *field_usage;
	void *battle_usage_1;
	void *battle_usage_2;
	void *field_28;
} item;

item* items = (item*)0x083DA518;