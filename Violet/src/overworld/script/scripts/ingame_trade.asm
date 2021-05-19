.include "overworld_script.s"
.include "vars.s"
.include "specials.s"

.global ow_script_ingame_trade_get_species_info
.global ow_script_ingame_trade_choose_party_idx_to_trade
.global ow_script_ingame_trade_get_trade_species
.global ow_script_ingame_trade

ow_script_ingame_trade_get_species_info:
	copyvar 0x8004, 0x8008
	special2 LASTRESULT, SPECIAL_INGAME_TRADE_GET_SPECIES_INFO
	copyvar 0x8009, LASTRESULT
	return
 
ow_script_ingame_trade_choose_party_idx_to_trade:
	special SPECIAL_SELECT_PARTY_POKEMON
	waitstate
	lock
	faceplayer
	copyvar 0x800A, 0x8004
	return

ow_script_ingame_trade_get_trade_species:
	copyvar 0x8005, 0x800A
	special2 LASTRESULT, SPECIAL_PARTY_POKEMON_GET_SPECIES
	copyvar 0x800B, LASTRESULT
	return

ow_script_ingame_trade:
	copyvar 0x8004, 0x8008
	copyvar 0x8005, 0x800A
	special SPECIAL_INGAME_TRADE_POKEMON_NEW
	special SPECIAL_INGAME_TRADE
	waitstate
	lock
	faceplayer
	return
