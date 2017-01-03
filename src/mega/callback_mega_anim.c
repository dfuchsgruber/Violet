#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "callbacks.h"
#include "battle.h"
#include "basestats.h"
#include "trainer.h"
#include "item.h"
#include "mega.h"
#include <stdbool.h>
#include "unaligned_types.h"
#include "debug.h"


static u8* react_str = (u8*) 0x88F704E;
static u8* opp_str = (u8*) 0x88F70A4; //" (Gegner)
static u8 clear_script[] = {0x10, 0x30, 0x1, //printstring 0x130
    0x12, 0x1, 0x0, //waitmessage 0x1
    0x3D //end
};
/**
static u8 pause_script[] = {
                0x39, 0x40, 0x0, //playanimation 0x0, 0x0, 0x00000000
                0x3D	//end
};
 **/

/**
static u8 charge_anim[] = {
                                                        0x0, 0xA3, 0x27, 	//buffer the gfx to use it later on 0x27A3 is solar beam particles
                                                        0xA, 0x2,			//prepeare_usr_oam
                                                        0xC, 0xC, 0x8,		//set_ablnd to 0x80C
                                                        0x3, 0xC9, 0x9C, 0x0B, 0x08, 0x2, //spawn callback
                                                                //additional params to load for cb
                                                                0x6, 0x02, 0x0, 0x01, 0x0, 0x04, 0x0, 0x0, 0x0, 0x0B, 0x0, 0xFF, 0x2F,
                                                        0x19, 0x85, 0x0, 0xC0,	//sound 0x85, modulation = -64
                                                        0xE, 0xDB, 0x27, 0x1D, 0x08, //call a subscript (0x1D27DB)
                                                        0x5,				//waitstate
                                                        0xB, 0x2,			//disables_usr_oam
                                                        0xD,				//reset ablnd
                                                        0x5,				//waitstate
                                                        0x8					//end
};

static u8 charge_anim2[] = {
	
                                                        0x0, 0xe4, 0x27,	//load gfx 0x27E4 (i hope it is the ray)
                                                        0xA, 0x2, 			//enbale usr oam
                                                        0x28, 0x0,			// ? maybe transp urs ? //
                                                        0xC, 0xC, 0x8,		//set_ablnd to 0x80C
                                                        0x2, 0x64, 0x5D, 0x3E, 0x8, 0x82, //spawn oam (hopefully the ray)
                                                                //additional anim for oam
                                                                0x1, 0x0, 0x0,
                                                        0x19, 0x85, 0x0, 0xC0,	//sound 0x85, modulation = -64
                                                        0x4, 0x22,				//pause 20
                                                        0xB, 0x2, 				//disable urs oam
                                                        0x8					//end			
	
};
 **/

/**
static u8 charge_anim3[] = {
							
                                                        0x0, 0xe3, 0x27,	//load gfx for sparkles
                                                        0x0, 0xe4, 0x27, 	//load gfx for ray
							
                                                        //callback for custom mega icon loading
                                                        0x3, 0x01, 0x65, 0x1A, 0x9, 0x2,
                                                                //additional param for callback (sprite to load)
                                                                0x1,
                                                                0x0, 0x0,
							
							
                                                        0x3, 0x81, 0x64, 0x1A, 0x9, 0x2, 0x0, //spawn callback for color_change
							
                                                        0x0a, 0x0,			//enable ?? 0 ??
                                                        0x0c, 0xc, 0x8,		//set ablnd to 0x80c
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0x0, 0x0,   //from intensity
                                                                0xA, 0x0,   //to intensity
                                                                0x0, 0x0,
                                                        0x5, //waitstate
							
                                                        //Earthquake
                                                        //0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                //0x3, 0x5, 0x0, 0xa, 0x0, 0x32, 0x0,
                                                        //0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                        //	0x3, 0x4, 0x0, 0xa, 0x0, 0x32, 0x0,	
                                                        //0x19, 0xe3, 0x0, 0x0, //sound eq								
							
							
							
                                                        0x3, 0x2D, 0xE6, 0x0A, 0x8, 0x2, //spawn callback
                                                                //additional callback params
                                                                0x4, 0x0, 0x0, 0x3c, 0x0, 0x2, 0x0, 0xc, 0x0,
								
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24	
								
                                                        0x2, 0xD4, 0x56, 0x3E, 0x8, 0x2, //spawn oam (ray)
                                                                //additional anim for oam
                                                                0x1, 0x0, 0x0,
                                                        0x04, 0x28, //pause 0x28
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
                                                        0x4, 0x1e, //pause 0x24
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
							
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0xA, 0x0,   //from intensity
                                                                0x0, 0x0,   //to intensity
                                                                0x0, 0x0,
                                                        0x4, 0xa,	//pause 0xa (wait for backfade)
							
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x00, 0x0, 0x10, 0x0, 0xFF, 0xFF,
								
                                                        0x4, 0x40, //pause 0x40
                                                        0xB, 0x0, //make sprite acessable
                                                        0x3, 0x81, 0x5f, 0x1A, 0x9, 0x2, 0x0, // change sprites through callback
                                                        0x4, 0x20, //pause 0x18
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x10, 0x0, 0x00, 0x0, 0xFF, 0xFF,
                                                        0x4, 0x28, //pause 0x28
							
                                                        0xA, 0x2,
                                                        //shake pokemon
                                                        0x3, 0xA1, 0x95, 0xB, 0x8, 0x5,
                                                                //additional callback params
                                                                0x3,
                                                                0x1, 0x0,
                                                                0x5, 0x0,
                                                                0xe, 0x0,
							
                                                        0x3, 0x81, 0x60, 0x1A, 0x9, 0x2, 0x0, //cry of pokemon through callback
                                                        0x5, //waitstate
                                                        0xb, 0x2,
							
                                                        //spawn mega symbol above the pokemon
                                                        0x2, 0x0, 0x6E, 0x1A, 0x9, 0x82, 0x0,
                                                        0x5, //waitstate
							
                                                        0x4, 0x50,
                                                        0x8 				//end
};
 **/

/**
static u8 charge_animg[] = {
							
                                                        0x0, 0xe3, 0x27,	//load gfx for sparkles
                                                        0x0, 0xe4, 0x27, 	//load gfx for ray
							
                                                        //callback for custom mega icon loading
                                                        0x3, 0x01, 0x65, 0x1A, 0x9, 0x2,
                                                                //additional param for callback (sprite to load)
                                                                0x1,
                                                                0x2, 0x0,
							
							
                                                        0x3, 0x81, 0x64, 0x1A, 0x9, 0x2, 0x0, //spawn callback for color_change
							
                                                        0x0a, 0x0,			//enable ?? 0 ??
                                                        0x0c, 0xc, 0x8,		//set ablnd to 0x80c
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0x0, 0x0,   //from intensity
                                                                0xA, 0x0,   //to intensity
                                                                0x1f, 0x6,
                                                        0x5, //waitstate
							
                                                        //Earthquake
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x5, 0x0, 0xa, 0x0, 0x32, 0x0,
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x4, 0x0, 0xa, 0x0, 0x32, 0x0,	
                                                        0x19, 0xe3, 0x0, 0x0, //sound eq								
							
							
							
                                                        0x3, 0x2D, 0xE6, 0x0A, 0x8, 0x2, //spawn callback
                                                                //additional callback params
                                                                0x4, 0x0, 0x0, 0x3c, 0x0, 0x2, 0x0, 0xc, 0x0,
								
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24	
								
                                                        0x2, 0xD4, 0x56, 0x3E, 0x8, 0x2, //spawn oam (ray)
                                                                //additional anim for oam
                                                                0x1, 0x0, 0x0,
                                                        0x04, 0x28, //pause 0x28
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
                                                        0x4, 0x1e, //pause 0x24
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
							
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0xA, 0x0,   //from intensity
                                                                0x0, 0x0,   //to intensity
                                                                0x1f, 0x6,
                                                        0x4, 0xa,	//pause 0xa (wait for backfade)
							
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x00, 0x0, 0x10, 0x0, 0xFF, 0xFF,
								
                                                        0x4, 0x40, //pause 0x40
                                                        0xB, 0x0, //make sprite acessable
                                                        0x3, 0x81, 0x5f, 0x1A, 0x9, 0x2, 0x0, // change sprites through callback
                                                        0x4, 0x20, //pause 0x18
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x10, 0x0, 0x00, 0x0, 0xFF, 0xFF,
                                                        0x4, 0x28, //pause 0x28
							
                                                        0xA, 0x2,
                                                        //shake pokemon
                                                        0x3, 0xA1, 0x95, 0xB, 0x8, 0x5,
                                                                //additional callback params
                                                                0x3,
                                                                0x1, 0x0,
                                                                0x5, 0x0,
                                                                0xe, 0x0,
							
                                                        0x3, 0x81, 0x60, 0x1A, 0x9, 0x2, 0x0, //cry of pokemon through callback
                                                        0x5, //waitstate
                                                        0xb, 0x2,
							
                                                        //spawn mega symbol above the pokemon
                                                        0x2, 0x40, 0x6E, 0x1A, 0x9, 0x82, 0x0,
                                                        0x5, //waitstate
							
                                                        0x4, 0x50,
                                                        0x8 				//end
};
 **/

/**
static u8 charge_animk[] = {
							
                                                        0x0, 0xe3, 0x27,	//load gfx for sparkles
                                                        0x0, 0xe4, 0x27, 	//load gfx for ray
							
                                                        //callback for custom mega icon loading
                                                        0x3, 0x01, 0x65, 0x1A, 0x9, 0x2,
                                                                //additional param for callback (sprite to load)
                                                                0x1,
                                                                0x1, 0x0,
							
							
                                                        0x3, 0x81, 0x64, 0x1A, 0x9, 0x2, 0x0, //spawn callback for color_change
							
                                                        0x0a, 0x0,			//enable ?? 0 ??
                                                        0x0c, 0xc, 0x8,		//set ablnd to 0x80c
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0x0, 0x0,   //from intensity
                                                                0xA, 0x0,   //to intensity
                                                                0x86, 0x6c,
                                                        0x5, //waitstate
							
                                                        //Earthquake
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x5, 0x0, 0xa, 0x0, 0x32, 0x0,
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x4, 0x0, 0xa, 0x0, 0x32, 0x0,	
                                                        0x19, 0xe3, 0x0, 0x0, //sound eq								
							
							
							
                                                        0x3, 0x2D, 0xE6, 0x0A, 0x8, 0x2, //spawn callback
                                                                //additional callback params
                                                                0x4, 0x0, 0x0, 0x3c, 0x0, 0x2, 0x0, 0xc, 0x0,
								
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24	
								
                                                        0x2, 0xD4, 0x56, 0x3E, 0x8, 0x2, //spawn oam (ray)
                                                                //additional anim for oam
                                                                0x1, 0x0, 0x0,
                                                        0x04, 0x28, //pause 0x28
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
                                                        0x4, 0x1e, //pause 0x24
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
							
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0xA, 0x0,   //from intensity
                                                                0x0, 0x0,   //to intensity
                                                                0x86, 0x6c,
                                                        0x4, 0xa,	//pause 0xa (wait for backfade)
							
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x00, 0x0, 0x10, 0x0, 0xFF, 0xFF,
								
                                                        0x4, 0x40, //pause 0x40
                                                        0xB, 0x0, //make sprite acessable
                                                        0x3, 0x81, 0x5f, 0x1A, 0x9, 0x2, 0x0, // change sprites through callback
                                                        0x4, 0x20, //pause 0x18
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x10, 0x0, 0x00, 0x0, 0xFF, 0xFF,
                                                        0x4, 0x28, //pause 0x28
							
                                                        0xA, 0x2,
                                                        //shake pokemon
                                                        0x3, 0xA1, 0x95, 0xB, 0x8, 0x5,
                                                                //additional callback params
                                                                0x3,
                                                                0x1, 0x0,
                                                                0x5, 0x0,
                                                                0xe, 0x0,
							
                                                        0x3, 0x81, 0x60, 0x1A, 0x9, 0x2, 0x0, //cry of pokemon through callback
                                                        0x5, //waitstate
                                                        0xb, 0x2,
							
                                                        //spawn mega symbol above the pokemon
                                                        0x2, 0x20, 0x6E, 0x1A, 0x9, 0x82, 0x0,
                                                        0x5, //waitstate
							
                                                        0x4, 0x50,
                                                        0x8 				//end
};
 **/
/**
static u8 charge_animr[] = {
							
                                                        0x0, 0xe3, 0x27,	//load gfx for sparkles
                                                        0x0, 0xe4, 0x27, 	//load gfx for ray
							
                                                        //callback for custom mega icon loading
                                                        0x3, 0x01, 0x65, 0x1A, 0x9, 0x2,
                                                                //additional param for callback (sprite to load)
                                                                0x1,
                                                                0x3, 0x0,
							
							
                                                        0x3, 0x81, 0x64, 0x1A, 0x9, 0x2, 0x0, //spawn callback for color_change
							
                                                        0x0a, 0x0,			//enable ?? 0 ??
                                                        0x0c, 0xc, 0x8,		//set ablnd to 0x80c
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0x0, 0x0,   //from intensity
                                                                0xA, 0x0,   //to intensity
                                                                0x2a, 0x37,
                                                        0x5, //waitstate
							
                                                        //Earthquake
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x5, 0x0, 0xa, 0x0, 0x32, 0x0,
                                                        0x03, 0xA1, 0x95, 0x0B, 0x8, 0x5, //heq
                                                                //addition param for heq
                                                                0x3, 0x4, 0x0, 0xa, 0x0, 0x32, 0x0,	
                                                        0x19, 0xe3, 0x0, 0x0, //sound eq								
							
							
							
                                                        0x3, 0x2D, 0xE6, 0x0A, 0x8, 0x2, //spawn callback
                                                                //additional callback params
                                                                0x4, 0x0, 0x0, 0x3c, 0x0, 0x2, 0x0, 0xc, 0x0,
								
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24
                                                        0x19, 0x85, 0x0, 0xC0, //sound 0x85, modulation -40
                                                        0x4, 0x24, //pause 0x24	
								
                                                        0x2, 0xD4, 0x56, 0x3E, 0x8, 0x2, //spawn oam (ray)
                                                                //additional anim for oam
                                                                0x1, 0x0, 0x0,
                                                        0x04, 0x28, //pause 0x28
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
                                                        0x4, 0x1e, //pause 0x24
                                                        0x19, 0xCe, 0x0, 0xC0, //sound 0xCE, modulation -40
							
							
                                                        //color fade
                                                        0x2, 0x24, 0x70, 0x3E, 0x8, 0x2,
                                                                //additional param for color fade oam
                                                                0x5,
                                                                0x1, 0x0,
                                                                0x1, 0x0,	//1 color change per frame
                                                                0xA, 0x0,   //from intensity
                                                                0x0, 0x0,   //to intensity
                                                                0x2a, 0x37,
                                                        0x4, 0xa,	//pause 0xa (wait for backfade)
							
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x00, 0x0, 0x10, 0x0, 0xFF, 0xFF,
								
                                                        0x4, 0x40, //pause 0x40
                                                        0xB, 0x0, //make sprite acessable
                                                        0x3, 0x81, 0x5f, 0x1A, 0x9, 0x2, 0x0, // change sprites through callback
                                                        0x4, 0x20, //pause 0x18
                                                        0x3, 0x29, 0xA9, 0xB, 0x08, 0x5, //callback for white screen
                                                                //additional callback params
                                                                0x5, 0x5, 0x0, 0x2, 0x0, 0x10, 0x0, 0x00, 0x0, 0xFF, 0xFF,
                                                        0x4, 0x28, //pause 0x28
							
                                                        0xA, 0x2,
                                                        //shake pokemon
                                                        0x3, 0xA1, 0x95, 0xB, 0x8, 0x5,
                                                                //additional callback params
                                                                0x3,
                                                                0x1, 0x0,
                                                                0x5, 0x0,
                                                                0xe, 0x0,
							
                                                        0x3, 0x81, 0x60, 0x1A, 0x9, 0x2, 0x0, //cry of pokemon through callback
                                                        0x5, //waitstate
                                                        0xb, 0x2,
							
                                                        //spawn mega symbol above the pokemon
                                                        0x2, 0x60, 0x6E, 0x1A, 0x9, 0x82, 0x0,
                                                        0x5, //waitstate
							
                                                        0x4, 0x50,
                                                        0x8 				//end
};

 **/

mega_table_entry *get_mega_if_can_mega_evolve(battler *b);

void cb_mega_anim(u8 self) {

    big_callback* cself = CALLBACK_OBJECT(self);

    //execute bsc if bsc active
    u8 battle_state = *((u8*) 0x02023BE3);
    if (battle_state == 0xC) {
        bsc_executer();
    }




    //at frame 0x0: clear the message box
    if (cself->params[0] == 0x0) {
        u8 battle_state = *((u8*) 0x02023BE3);
        cself->params[3] = battle_state;
        *((u8*) 0x02023BE3) = 0xC; //we go to state : execute bsc
        //*((u8**)0x02023D74) = (u8*)0x81DD2Ae; //test bsc
        *((u8**) 0x02023D74) = clear_script;
    }

    //at frame 0x4: print "reacts to mega"
    if (cself->params[0] == 0x4 || cself->params[0] == 540) {
        //we copy our string into the ram buffer
        u8* ram_buf = (u8*) 0x02021D18;
        u8 slot = (u8) cself->params[1];

        u8* src = (cself->params[0] == 540) ? (u8*) 0x88F70F8 : react_str;

        //searching for the mega evolution that has current species as target and is a regent evolution
        cself->params[5] = 0;
        int i = 0;
        while (megas[i].species != 0xFFFF) {
            if (megas[i].target == battlers[slot].species && megas[i].regent) {
                cself->params[5] = megas[i].species;
                src = (cself->params[0] == 540) ? (u8*) 0x88F7123 : (u8*) 0x88F70DD;
            }
            i++;
        }

        while (*src != 0xFF) {
            u8 cchar = *src++;
            if (cchar == 0xFD) {

                //buffer hit
                //for testing we just skip the buffer
                u8 buffer_id = *src++;
                switch (buffer_id) {
                    case 1:
                    {
                        //We request the mega item (depending on side)
                        u16 item = is_opponent(slot) ? *(vardecrypt(0x50E4)) : *(vardecrypt(0x50E5));
                        ram_buf = (strcpy(ram_buf, items[item].name));
                        break;
                    }
                    case 2:
                    {
                        //We request the pokemons name
                        ram_buf = (strcpy(ram_buf, battlers[slot].name));
                        if (is_opponent(slot)) {
                            ram_buf = strcpy(ram_buf, opp_str);
                        }
                        break;
                    }
                    case 3:
                    {
                        //We request the held item
                        u16 item = battlers[slot].item;
                        ram_buf = (strcpy(ram_buf, items[item].name));
                        break;
                    }
                    case 4:
                    {
                        //We request the ot-name
                        if (!is_opponent(slot)) {
                            ram_buf = (strcpy(ram_buf, (*(u8**) 0x03004F5C)));
                        } else {
                            u16 trainer_id = *((u16*) 0x020386AE);
                            //if trainerclass is of rival we load name form saveblock as well
                            if (trainers[trainer_id].trainerclass == 0x51) {
                                ram_buf = (strcpy(ram_buf, (u8*) ((*((u8**) 0x03004F58)) + 0x3A4C)));
                            } else {
                                ram_buf = (strcpy(ram_buf, trainers[trainer_id].name));
                            }
                        }
                        break;
                    }
                    case 5:
                    {
                        //We request the original species
                        u16 species = battlers[slot].species;
                        ram_buf = (strcpy(ram_buf, (u8*) (0x8245Db0 + 11 * species)));
                        break;
                    }
                }
            } else {
                *ram_buf++ = cchar;
            }
        }
        *ram_buf = 0xFF; //adding the end of string to the ram buffer
        battle_printmsg((u8*) 0x02021D18, 0x40);
    }


    //start mega animation
    if (cself->params[0] == 0x44) {
        //*((u8*)0x02023BE3) = 0xC; //we go to state : execute bsc
        //*((u8**)0x02023D74) = pause_script;
        u8 slot = (u8) cself->params[1];

        u8* canim = (u8*) attack_anim_mega;
        if (cself->params[5]) {
            //find corresponding mega
            if (cself->params[5] == 0x195) {
                canim = (u8*) attack_anim_groudon;
            } else if (cself->params[5] == 0x194) {
                canim = (u8*) attack_anim_kyogre;
            } else if (cself->params[5] == 0x196) {
                canim = (u8*) attack_anim_rayquaza;
            }
        }

        call_attack_anim_by_offset(slot, 1, canim);

        *((u8*) 0x02037F1B) = slot; //target of animation is also the user
        //call_attack_anim_from_offset(slot, 1,(void*)0x81CFC00);


    }


    if (cself->params[0] == 800) {
        *((u8*) 0x02023BE3) = (u8) (cself->params[3]);
        remove_big_callback(self);


        //we know execute ability management for battle enter
        u8 slot = (u8) cself->params[1];
        *((u8*) 0x02023D6B) = slot; //active index is current slot
        ability_management(0, slot, 0, 0, 0);


    } else {
        cself->params[0] = (u16) (cself->params[0] + 1);
    }
}