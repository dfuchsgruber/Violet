
def get_symbol(name):
	return str(hex(symbols[name]-0x08000000 + 0x10))

symbol_file = open("bld/__symbols.sym", "r")
symbol_content = symbol_file.read()
symbol_file.close()
lines = symbol_content.split("\r\n")
symbols = {}
for line in lines:
	tokens = line.split(" ")
	if len(tokens) == 2:
		if tokens[1] in symbols:
			print ("Warning: Redifintion of symbol "+tokens[1])
		symbols[tokens[1]] = int(tokens[0], 0)
	else:
		pass
		#print("Warning : Line does not contain two tokens : "+str(line))
		
#Create AV Series.ini
avini = "GameCode=BPRD\r\nFrontSpriteTable="+get_symbol("pokemon_frontsprites")+ \
"\r\nBackSpriteTable="+get_symbol("pokemon_backsprites")+"\r\nFrontPaletteTable="+ \
get_symbol("pokemon_pals")+"\r\nBackPaletteTable="+get_symbol("pokemon_shiny_pals")+\
"\r\nEnemyYTable="+get_symbol("pokemon_enemy_y")+"\r\nPlayerYTable="+get_symbol("pokemon_player_y")+\
"\r\nEnemyAltitudeTable="+get_symbol("pokemon_altitude")+"\r\nIconSpriteTable="+\
get_symbol("pokemon_icons")+"\r\nIconPaletteTable="+get_symbol("pokemon_icon_usage")+\
"\r\nIconPalettes=0x3D3054\r\nSpeciesNames="+get_symbol("pokemon_names")+"\r\nTotalSpecies=441"

ini = open("D:\Hacking\Programme\Advanced series\INIs\Feuerrot (D).ini", "w+")
ini.write(avini)
ini.close()