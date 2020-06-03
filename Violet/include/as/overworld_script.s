.macro nop 
.byte 0x0
.endm

.macro nop1 
.byte 0x1
.endm

.macro end 
.byte 0x2
.endm

.macro return 
.byte 0x3
.endm

.macro call subscript
.byte 0x4
.word \subscript
.endm

.macro goto script
.byte 0x5
.word \script
.endm

.macro gotoif condition subscript
.byte 0x6
.byte \condition
.word \subscript
.endm

.macro callif condition script
.byte 0x7
.byte \condition
.word \script
.endm


.macro gotostd std
.byte 0x8
.byte \std
.endm

.macro callstd std
.byte 0x9
.byte \std
.endm

.macro gotostdif condition std
.byte 0xa
.byte \condition
.byte \std
.endm

.macro callstdif condition std
.byte 0xb
.byte \condition
.byte \std
.endm

.macro jumpram 
.byte 0xc
.endm

.macro killscript 
.byte 0xd
.endm

.macro set_x203AA3C value
.byte 0xe
.byte \value
.endm

.macro loadpointer bank pointer
.byte 0xf
.byte \bank
.word \pointer
.endm

.macro set_intern_bank bank value
.byte 0x10
.byte \bank
.byte \value
.endm

.macro writebytetooffset value offset
.byte 0x11
.byte \value
.word \offset
.endm

.macro loadbytefrompointer bank offset
.byte 0x12
.byte \bank
.word \offset
.endm

.macro setbyte bank offset
.byte 0x13
.byte \bank
.word \offset
.endm

.macro copyscriptbanks dst_bank src_bank
.byte 0x14
.byte \dst_bank
.byte \src_bank
.endm

.macro copybyte dst src
.byte 0x15
.word \dst
.word \src
.endm

.macro setvar var value
.byte 0x16
.hword \var
.hword \value
.endm

.macro addvar var value
.byte 0x17
.hword \var
.hword \value
.endm

.macro subvar var value
.byte 0x18
.hword \var
.hword \value
.endm

.macro copyvar dst src
.byte 0x19
.hword \dst
.hword \src
.endm

.macro copyvarifnotzero dst src
.byte 0x1a
.hword \dst
.hword \src
.endm

.macro comparebanks bank1 bank2
.byte 0x1b
.hword \bank1
.hword \bank2
.endm

.macro comparebanktobyte bank value
.byte 0x1c
.byte \bank
.byte \value
.endm

.macro comparebanktofarbyte bank offset
.byte 0x1d
.byte \bank
.word \offset
.endm

.macro comparefarbytetobank offset bank
.byte 0x1e
.word \offset
.byte \bank
.endm

.macro comparefarbytetobyte offset value
.byte 0x1f
.word \offset
.byte \value
.endm

.macro comparefarbytes offset1 offset2
.byte 0x20
.word \offset1
.word \offset2
.endm

.macro compare var value
.byte 0x21
.hword \var
.hword \value
.endm

.macro comparevars var1 var2
.byte 0x22
.hword \var1
.hword \var2
.endm

.macro callasm function
.byte 0x23
.word \function
.endm

.macro callasmandwaitstate function
.byte 0x24
.word \function
.endm

.macro special special_id
.byte 0x25
.hword \special_id
.endm

.macro special2 varresult speical_id
.byte 0x26
.hword \varresult
.hword \speical_id
.endm

.macro waitstate 
.byte 0x27
.endm

.macro pause frames
.byte 0x28
.hword \frames
.endm

.macro setflag flag
.byte 0x29
.hword \flag
.endm

.macro clearflag flag
.byte 0x2a
.hword \flag
.endm

.macro checkflag flag
.byte 0x2b
.hword \flag
.endm

.macro cmd2c 
.byte 0x2c
.endm

.macro cmd2d 
.byte 0x2d
.endm

.macro resetvolatilevars 
.byte 0x2e
.endm

.macro sound sound
.byte 0x2f
.hword \sound
.endm

.macro checksound 
.byte 0x30
.endm

.macro fanfare fanfare
.byte 0x31
.hword \fanfare
.endm

.macro waitfanfare 
.byte 0x32
.endm

.macro playsong song feature
.byte 0x33
.hword \song
.byte \feature
.endm

.macro playsong2 song
.byte 0x34
.hword \song
.endm

.macro songfadedefault 
.byte 0x35
.endm

.macro fadesong song
.byte 0x36
.hword \song
.endm

.macro fadeout speed
.byte 0x37
.byte \speed
.endm

.macro fadein speed
.byte 0x38
.byte \speed
.endm

.macro warp bank map exit x y
.byte 0x39
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warpmuted bank map exit x y
.byte 0x3a
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warpwalk bank map exit x y
.byte 0x3b
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warphole bank map exit x y
.byte 0x3c
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warpteleport bank map exit x y
.byte 0x3d
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warp3 bank map exit x y
.byte 0x3e
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro setwarpplace bank map exit x y
.byte 0x3f
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warp4 bank map exit x y
.byte 0x40
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro warp5 bank map exit x y
.byte 0x41
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro getplayerpos varx vary
.byte 0x42
.hword \varx
.hword \vary
.endm

.macro countpokemon 
.byte 0x43
.endm

.macro additem item quantity
.byte 0x44
.hword \item
.hword \quantity
.endm

.macro removeitem item quantity
.byte 0x45
.hword \item
.hword \quantity
.endm

.macro checkitemroom item quantity
.byte 0x46
.hword \item
.hword \quantity
.endm

.macro checkitem item quantity
.byte 0x47
.hword \item
.hword \quantity
.endm

.macro checkitemtype item
.byte 0x48
.hword \item
.endm

.macro addpcitem item quantity
.byte 0x49
.hword \item
.hword \quantity
.endm

.macro checkpcitem item quantity
.byte 0x4a
.hword \item
.hword \quantity
.endm

.macro cmd4b unused
.byte 0x4b
.hword \unused
.endm

.macro cmd4c unused
.byte 0x4c
.hword \unused
.endm

.macro cmd4d unused
.byte 0x4d
.hword \unused
.endm

.macro cmd4e unused
.byte 0x4e
.hword \unused
.endm

.macro applymovement people movement
.byte 0x4f
.hword \people
.word \movement
.endm

.macro applymovementonmap people movement bank map
.byte 0x50
.hword \people
.word \movement
.byte \bank
.byte \map
.endm

.macro waitmovement num_people
.byte 0x51
.hword \num_people
.endm

.macro waitmovementonmap num_people bank map
.byte 0x52
.hword \num_people
.byte \bank
.byte \map
.endm

.macro hidesprite people
.byte 0x53
.hword \people
.endm

.macro hidespriteonmap people bank map
.byte 0x54
.hword \people
.byte \bank
.byte \map
.endm

.macro showsprite people
.byte 0x55
.hword \people
.endm

.macro showspriteonmap people bank map
.byte 0x56
.hword \people
.byte \bank
.byte \map
.endm

.macro movesprite people x y
.byte 0x57
.hword \people
.hword \x
.hword \y
.endm

.macro spritevisible people bank map
.byte 0x58
.hword \people
.byte \bank
.byte \map
.endm

.macro spriteinvisible people bank map
.byte 0x59
.hword \people
.byte \bank
.byte \map
.endm

.macro faceplayer 
.byte 0x5a
.endm

.macro spriteface people facing
.byte 0x5b
.hword \people
.byte \facing
.endm

.macro trainerbattlestd kind trainer people str_challange str_defeat
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_challange
.word \str_defeat
.endm

.macro trainerbattlenointrotext trainer:req people:req str_defeat
.byte 0x5c
.byte 0x3 // kind
.hword \trainer
.hword \people
.word \str_defeat
.endm

.macro trainerbattlecont kind trainer people str_challange str_defeat continuation
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_challange
.word \str_defeat
.word \continuation
.endm

.macro trainerbattlenotinterrupting kind trainer people str_defeat
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_defeat
.endm

.macro trainerbattledouble kind trainer people str_challange str_defeat continuation_one_poke
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_challange
.word \str_defeat
.word \continuation_one_poke
.endm

.macro trainerbattle6 kind trainer people str_challange str_defeat str_var1 continuation
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_challange
.word \str_defeat
.word \str_var1
.word \continuation
.endm

.macro trainerbattlelosable kind trainer people str_defeat str_loss
.byte 0x5c
.byte \kind
.hword \trainer
.hword \people
.word \str_defeat
.word \str_loss
.endm

.macro trainerbattletwotrainers trainerA:req trainerB:req people:req str_challange:req str_defeatA:req str_defeatB:req continuation:req
.byte 0x5C
.byte 10
.hword \trainerA
.hword \trainerB
.hword \people
.word \str_challange
.word \str_defeatA
.word \str_defeatB
.word \continuation
.endm

.macro trainerbattleally trainer:req ally:req people:req backsprite:req party_preview:req str_challange:req str_defeat:req continuation:req
.byte 0x5C
.byte 11
.hword \trainer
.hword \ally
.hword \people
.byte \backsprite
.byte \party_preview
.word \str_challange
.word \str_defeat
.word \continuation
.endm


.macro trainerbattleallytwotrainers trainerA:req trainerB:req ally:req people:req backsprite:req party_preview:req str_challange:req str_defeatA:req str_defeatB:req continuation:req
.byte 0x5C
.byte 12
.hword \trainerA
.hword \trainerB
.hword \ally
.hword \people
.byte \backsprite
.byte \party_preview
.word \str_challange
.word \str_defeatA
.word \str_defeatB
.word \continuation
.endm

.macro repeattrainerbattle 
.byte 0x5d
.endm

.macro endtrainerbattle 
.byte 0x5e
.endm

.macro endtrainerbattle2 
.byte 0x5f
.endm

.macro checktrainerflag id
.byte 0x60
.hword \id
.endm

.macro cleartrainerflag id
.byte 0x61
.hword \id
.endm

.macro settrainerflag id
.byte 0x62
.hword \id
.endm

.macro movesprite2 people x y
.byte 0x63
.hword \people
.hword \x
.hword \y
.endm

.macro moveoffscreen people
.byte 0x64
.hword \people
.endm

.macro spritebehave people behaviour
.byte 0x65
.hword \people
.byte \behaviour
.endm

.macro waitmsg 
.byte 0x66
.endm

.macro preparemsg str
.byte 0x67
.word \str
.endm

.macro closeonkeypress 
.byte 0x68
.endm

.macro lockall 
.byte 0x69
.endm

.macro lock 
.byte 0x6a
.endm

.macro releaseall 
.byte 0x6b
.endm

.macro release 
.byte 0x6c
.endm

.macro waitkeypress 
.byte 0x6d
.endm

.macro yesnobox tilex tiley
.byte 0x6e
.byte \tilex
.byte \tiley
.endm

.macro multichoice tilex tiley id not_escapable
.byte 0x6f
.byte \tilex
.byte \tiley
.byte \id
.byte \not_escapable
.endm

.macro multichoice2 tilex tiley id default not_escapable
.byte 0x70
.byte \tilex
.byte \tiley
.byte \id
.byte \default
.byte \not_escapable
.endm

.macro multichoice3 tilex tiley id num_per_row not_escapable
.byte 0x71
.byte \tilex
.byte \tiley
.byte \id
.byte \num_per_row
.byte \not_escapable
.endm

.macro showbox tilex tiley tilew tileh
.byte 0x72
.byte \tilex
.byte \tiley
.byte \tilew
.byte \tileh
.endm

.macro hidebox tilex tiley tilew tileh
.byte 0x73
.byte \tilex
.byte \tiley
.byte \tilew
.byte \tileh
.endm

.macro clearbox tilex tiley tilew tileh
.byte 0x74
.byte \tilex
.byte \tiley
.byte \tilew
.byte \tileh
.endm

.macro showpokepic species tilex tiley
.byte 0x75
.hword \species
.byte \tilex
.byte \tiley
.endm

.macro hidepokepic 
.byte 0x76
.endm

.macro braille_close 
.byte 0x77
.endm

.macro braille brialledata
.byte 0x78
.word \brialledata
.endm

.macro givepokemon species level item filler1 filler2 filler3
.byte 0x79
.hword \species
.byte \level
.hword \item
.word \filler1
.word \filler2
.byte \filler3
.endm

.macro giveegg species
.byte 0x7a
.hword \species
.endm

.macro setpokemonpp teamslot attackslot pp
.byte 0x7b
.byte \teamslot
.byte \attackslot
.hword \pp
.endm

.macro checkattack move
.byte 0x7c
.hword \move
.endm

.macro bufferpokemon buffer species
.byte 0x7d
.byte \buffer
.hword \species
.endm

.macro bufferfirstpokemon buffer
.byte 0x7e
.byte \buffer
.endm

.macro bufferpartypokemon buffer teamsplot
.byte 0x7f
.byte \buffer
.hword \teamsplot
.endm

.macro bufferitem buffer item
.byte 0x80
.byte \buffer
.hword \item
.endm

.macro cmd81 buffer deco
.byte 0x81
.byte \buffer
.hword \deco
.endm

.macro bufferattack buffer move
.byte 0x82
.byte \buffer
.hword \move
.endm

.macro buffernumber buffer var
.byte 0x83
.byte \buffer
.hword \var
.endm

.macro bufferstd buffer std
.byte 0x84
.byte \buffer
.hword \std
.endm

.macro bufferstring buffer str
.byte 0x85
.byte \buffer
.word \str
.endm

.macro pokemart mart
.byte 0x86
.word \mart
.endm

.macro pokemart2 mart
.byte 0x87
.word \mart
.endm

.macro pokemart3 mart sell_default_items=1
.byte 0x88
.word \mart
.byte \sell_default_items
.endm

.macro pokecasino var
.byte 0x89
.hword \var
.endm

.macro cmd8a param1 param2
.byte 0x8a
.byte \param1
.byte \param2
.endm

.macro cmd8b 
.byte 0x8b
.endm

.macro cmd8c 
.byte 0x8c
.endm

.macro cmd8d 
.byte 0x8d
.endm

.macro cmd8e 
.byte 0x8e
.endm

.macro random module
.byte 0x8f
.hword \module
.endm

.macro givemoney amount execbank
.byte 0x90
.word \amount
.byte \execbank
.endm

.macro paymoney amount execbank
.byte 0x91
.word \amount
.byte \execbank
.endm

.macro checkmoney amount execbank
.byte 0x92
.word \amount
.byte \execbank
.endm

.macro showmoney tilex tiley execbank
.byte 0x93
.byte \tilex
.byte \tiley
.byte \execbank
.endm

.macro hidemoney tilex tiley
.byte 0x94
.byte \tilex
.byte \tiley
.endm

.macro updatemoney tilex tiley execbank
.byte 0x95
.byte \tilex
.byte \tiley
.byte \execbank
.endm

.macro cmd96 param1
.byte 0x96
.hword \param1
.endm

.macro fadescreen effect
.byte 0x97
.byte \effect
.endm

.macro fadescreenspeed effect speed
.byte 0x98
.byte \effect
.byte \speed
.endm

.macro darken flashradius
.byte 0x99
.hword \flashradius
.endm

.macro lighten flashradius
.byte 0x9a
.hword \flashradius
.endm

.macro preparemsg2 str
.byte 0x9b
.word \str
.endm

.macro doanimation animid
.byte 0x9c
.hword \animid
.endm

.macro setanimation animid var
.byte 0x9d
.byte \animid
.hword \var
.endm

.macro checkanimation animid
.byte 0x9e
.hword \animid
.endm

.macro sethealingplace id
.byte 0x9f
.hword \id
.endm

.macro checkgender 
.byte 0xa0
.endm

.macro cry species effect
.byte 0xa1
.hword \species
.hword \effect
.endm

.macro setmaptile x y block attribute level=0
.byte 0xa2
.hword \x
.hword \y
.hword (\block | (\level << 10))
.hword \attribute
.endm

.macro resetweather 
.byte 0xa3
.endm

.macro setweather weather
.byte 0xa4
.hword \weather
.endm

.macro doweather 
.byte 0xa5
.endm

.macro cmda6 param1
.byte 0xa6
.byte \param1
.endm

.macro setmapfooter footer
.byte 0xa7
.hword \footer
.endm

.macro spritelevelup people bank map oamfield43
.byte 0xa8
.hword \people
.byte \bank
.byte \map
.byte \oamfield43
.endm

.macro restorespritelevel people bank map
.byte 0xa9
.hword \people
.byte \bank
.byte \map
.endm

.macro createsprite picture id x y behaviour behaviour_range
.byte 0xaa
.byte \picture
.byte \id
.hword \x
.hword \y
.byte \behaviour
.byte \behaviour_range
.endm

.macro spriteface2 people facing
.byte 0xab
.byte \people
.byte \facing
.endm

.macro setdooropened x y
.byte 0xac
.hword \x
.hword \y
.endm

.macro setdoorclosed x y
.byte 0xad
.hword \x
.hword \y
.endm

.macro doorchange 
.byte 0xae
.endm

.macro setdooropened2 x y
.byte 0xaf
.hword \x
.hword \y
.endm

.macro setdoorclosed2 x y
.byte 0xb0
.hword \x
.hword \y
.endm

.macro nop2 
.byte 0xb1
.endm

.macro nop3 
.byte 0xb2
.endm

.macro getcoins var
.byte 0xb3
.hword \var
.endm

.macro givecoins amount
.byte 0xb4
.hword \amount
.endm

.macro removecoins amount
.byte 0xb5
.hword \amount
.endm

.macro setwildbattle species level item
.byte 0xb6
.hword \species
.byte \level
.hword \item
.endm

.macro dowildbattle 
.byte 0xb7
.endm

.macro setvirtualscriptdisplacement offset
.byte 0xb8
.word \offset
.endm

.macro virtualgoto scriptplusdispl
.byte 0xb9
.word \scriptplusdispl
.endm

.macro virtualcall scriptplusdispl
.byte 0xba
.word \scriptplusdispl
.endm

.macro virtualgotoif condition scriptplusdispl
.byte 0xbb
.byte \condition
.word \scriptplusdispl
.endm

.macro virutalcallif condition scriptplusdispl
.byte 0xbc
.byte \condition
.word \scriptplusdispl
.endm

.macro virtualmsgbox str
.byte 0xbd
.word \str
.endm

.macro virtualloadpointer str
.byte 0xbe
.word \str
.endm

.macro virtualbuffer buffer str
.byte 0xbf
.byte \buffer
.word \str
.endm

.macro showcoins tilex tiley
.byte 0xc0
.byte \tilex
.byte \tiley
.endm

.macro hidecoins tilex tiley
.byte 0xc1
.byte \tilex
.byte \tiley
.endm

.macro updatecoins tilex tiley
.byte 0xc2
.byte \tilex
.byte \tiley
.endm

.macro savincrementkey key
.byte 0xc3
.byte \key
.endm

.macro warp6 bank map exit x y
.byte 0xc4
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro waitcry 
.byte 0xc5
.endm

.macro bufferboxname buffer box
.byte 0xc6
.byte \buffer
.hword \box
.endm

.macro textcolor color
.byte 0xc7
.byte \color
.endm

.macro menucreate menu
.byte 0xc8
.word \menu
.endm

.macro menuflush 
.byte 0xc9
.endm

.macro signmsg 
.byte 0xca
.endm

.macro normalmsg 
.byte 0xcb
.endm

.macro savcomparekey key value
.byte 0xcc
.byte \key
.word \value
.endm

.macro setobedience teamslot
.byte 0xcd
.hword \teamslot
.endm

.macro checkobedience teamslot
.byte 0xce
.hword \teamslot
.endm

.macro executeram 
.byte 0xcf
.endm

.macro setworldmapflag flag
.byte 0xd0
.hword \flag
.endm

.macro warpteleport2 bank map exit x y
.byte 0xd1
.byte \bank
.byte \map
.byte \exit
.hword \x
.hword \y
.endm

.macro setcatchlocation teamslot namespace
.byte 0xd2
.hword \teamslot
.byte \namespace
.endm

.macro braille2 brailledata
.byte 0xd3
.word \brailledata
.endm

.macro bufferitems buffer item quantity
.byte 0xd4
.byte \buffer
.hword \item
.hword \quantity
.endm

.macro singlemovement persid movement
.byte 0xD5
.hword \persid
.hword \movement
.endm
