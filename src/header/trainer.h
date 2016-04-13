typedef struct trainer{
	u8 field_0;
	u8 trainerclass;
	u8 field_1;
	u8 field_2;
	u8 name[8];
	u8 unkown_fields[0x1C];
	
}trainer;

trainer* trainers = (trainer*)0x0823E998;