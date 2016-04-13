typedef struct saveblock1 {
	
	s16 x;
	s16 y;
	u8 bank;
	u8 map;
	u8 unkown[0x2A];
	u8 flash_circle_siize;
	//TODO
	
	
}saveblock1;


saveblock1 **save1 = (saveblock1**)0x03004F58;