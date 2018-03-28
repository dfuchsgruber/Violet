
import os
import sys
import getopt

STDLIB = "./lib/macros.py"
INCLUDE = "../include"


""" Table of certain constants """



move_tutor = 

evo_table = 

item_table = 

species_table = 

ability_table = 

type_table = 

egg_table = 

attack_table = [
		
	"ATTACK_NONE",
	"ATTACK_PFUND",
	"ATTACK_KARATESCHLAG",
	"ATTACK_DUPLEXHIEB",
	"ATTACK_KOMETENHIEB",
	"ATTACK_MEGAHIEB",
	"ATTACK_ZAHLTAG",
	"ATTACK_FEUERSCHLAG",
	"ATTACK_EISHIEB",
	"ATTACK_DONNERSCHLAG",
	"ATTACK_KRATZER",
	"ATTACK_KLAMMER",
	"ATTACK_GUILLOTINE",
	"ATTACK_KLINGENSTURM",
	"ATTACK_SCHWERTTANZ",
	"ATTACK_ZERSCHNEIDER",
	"ATTACK_WINDSTOSS",
	"ATTACK_FLUEGELSCHLAG",
	"ATTACK_WIRBELWIND",
	"ATTACK_FLIEGEN",
	"ATTACK_KLAMMERGRIFF",
	"ATTACK_SLAM",
	"ATTACK_RANKENHIEB",
	"ATTACK_STAMPFER",
	"ATTACK_DOPPELKICK",
	"ATTACK_MEGAKICK",
	"ATTACK_SPRUNGKICK",
	"ATTACK_FEGEKICK",
	"ATTACK_SANDWIRBEL",
	"ATTACK_KOPFNUSS",
	"ATTACK_HORNATTACKE",
	"ATTACK_FURIENSCHLAG",
	"ATTACK_HORNBOHRER",
	"ATTACK_TACKLE",
	"ATTACK_BODYSLAM",
	"ATTACK_WICKEL",
	"ATTACK_BODYCHECK",
	"ATTACK_FUCHTLER",
	"ATTACK_RISIKOTACKLE",
	"ATTACK_RUTENSCHLAG",
	"ATTACK_GIFTSTACHEL",
	"ATTACK_DUONADEL",
	"ATTACK_NADELRAKETE",
	"ATTACK_SILBERBLICK",
	"ATTACK_BISS",
	"ATTACK_HEULER",
	"ATTACK_BRUELLER",
	"ATTACK_GESANG",
	"ATTACK_SUPERSCHALL",
	"ATTACK_ULTRASCHALL",
	"ATTACK_AUSSETZER",
	"ATTACK_SAEURE",
	"ATTACK_GLUT",
	"ATTACK_FLAMMENWURF",
	"ATTACK_WEISSNEBEL",
	"ATTACK_AQUAKNARRE",
	"ATTACK_HYDROPUMPE",
	"ATTACK_SURFER",
	"ATTACK_EISSTRAHL",
	"ATTACK_BLIZZARD",
	"ATTACK_PSYSTRAHL",
	"ATTACK_BLUBBSTRAHL",
	"ATTACK_AURORASTRAHL",
	"ATTACK_HYPERSTRAHL",
	"ATTACK_SCHNABEL",
	"ATTACK_BOHRSCHNABEL",
	"ATTACK_UEBERROLLER",
	"ATTACK_FUSSKICK",
	"ATTACK_KONTER",
	"ATTACK_GEOWURF",
	"ATTACK_STAERKE",
	"ATTACK_ABSORBER",
	"ATTACK_MEGASAUGER",
	"ATTACK_EGELSAMEN",
	"ATTACK_WACHSTUM",
	"ATTACK_RASIERBLATT",
	"ATTACK_SOLARSTRAHL",
	"ATTACK_GIFTPUDER",
	"ATTACK_STACHELSPORE",
	"ATTACK_SCHLAFPUDER",
	"ATTACK_BLAETTERTANZ",
	"ATTACK_FADENSCHUSS",
	"ATTACK_DRACHENWUT",
	"ATTACK_FEUERWIRBEL",
	"ATTACK_DONNERSCHOCK",
	"ATTACK_DONNERBLITZ",
	"ATTACK_DONNERWELLE",
	"ATTACK_DONNER",
	"ATTACK_STEINWURF",
	"ATTACK_ERDBEBEN",
	"ATTACK_GEOFISSUR",
	"ATTACK_SCHAUFLER",
	"ATTACK_TOXIN",
	"ATTACK_KONFUSION",
	"ATTACK_PSYCHOKINESE",
	"ATTACK_HYPNOSE",
	"ATTACK_MEDITATION",
	"ATTACK_AGILITAET",
	"ATTACK_RUCKZUCKHIEB",
	"ATTACK_RASEREI",
	"ATTACK_TELEPORT",
	"ATTACK_NACHTNEBEL",
	"ATTACK_MIMIKRY",
	"ATTACK_KREIDESCHREI",
	"ATTACK_DOPPELTEAM",
	"ATTACK_GENESUNG",
	"ATTACK_HAERTNER",
	"ATTACK_KOMPRIMATOR",
	"ATTACK_RAUCHWOLKE",
	"ATTACK_KONFUSTRAHL",
	"ATTACK_PANZERSCHUTZ",
	"ATTACK_EINIGLER",
	"ATTACK_BARRIERE",
	"ATTACK_LICHTSCHILD",
	"ATTACK_DUNKELNEBEL",
	"ATTACK_REFLEKTOR",
	"ATTACK_ENERGIEFOKUS",
	"ATTACK_GEDULD",
	"ATTACK_METRONOM",
	"ATTACK_SPIEGELTRICK",
	"ATTACK_FINALE",
	"ATTACK_EIERBOMBE",
	"ATTACK_SCHLECKER",
	"ATTACK_SMOG",
	"ATTACK_SCHLAMMBAD",
	"ATTACK_KNOCHENKEULE",
	"ATTACK_FEUERSTURM",
	"ATTACK_KASKADE",
	"ATTACK_SCHNAPPER",
	"ATTACK_STERNSCHAUER",
	"ATTACK_SCHAEDELWUMME",
	"ATTACK_DORNKANONE",
	"ATTACK_UMKLAMMERUNG",
	"ATTACK_AMNESIE",
	"ATTACK_PSYKRAFT",
	"ATTACK_WEICHEI",
	"ATTACK_TURMKICK",
	"ATTACK_GIFTBLICK",
	"ATTACK_TRAUMFRESSER",
	"ATTACK_GIFTWOLKE",
	"ATTACK_STAKKATO",
	"ATTACK_BLUTSAUGER",
	"ATTACK_TODESKUSS",
	"ATTACK_HIMMELSFEGER",
	"ATTACK_WANDLER",
	"ATTACK_BLUBBER",
	"ATTACK_IRRSCHLAG",
	"ATTACK_PILZSPORE",
	"ATTACK_BLITZ",
	"ATTACK_PSYWELLE",
	"ATTACK_PLATSCHER",
	"ATTACK_SAEUREPANZER",
	"ATTACK_KRABBHAMMER",
	"ATTACK_EXPLOSION",
	"ATTACK_KRATZFURIE",
	"ATTACK_KNOCHMERANG",
	"ATTACK_ERHOLUNG",
	"ATTACK_STEINHAGEL",
	"ATTACK_HYPERZAHN",
	"ATTACK_SCHAERFER",
	"ATTACK_UMWANDLUNG",
	"ATTACK_TRIPLETTE",
	"ATTACK_SUPERZAHN",
	"ATTACK_SCHLITZER",
	"ATTACK_DELEGATOR",
	"ATTACK_VERZWEIFLER",
	"ATTACK_NACHAHMER",
	"ATTACK_DREIFACHKICK",
	"ATTACK_RAUB",
	"ATTACK_SPINNENNETZ",
	"ATTACK_WILLENSLESER",
	"ATTACK_NACHTMAHR",
	"ATTACK_FLAMMENRAD",
	"ATTACK_SCHNARCHER",
	"ATTACK_FLUCH",
	"ATTACK_DRESCHFLEGEL",
	"ATTACK_UMWANDLUNG2",
	"ATTACK_LUFTSTOSS",
	"ATTACK_BAUMWOLLSAAT",
	"ATTACK_GEGENSCHLAG",
	"ATTACK_GROLL",
	"ATTACK_PULVERSCHNEE",
	"ATTACK_SCHUTZSCHILD",
	"ATTACK_TEMPOHIEB",
	"ATTACK_GRIMASSE",
	"ATTACK_FINTE",
	"ATTACK_BITTERKUSS",
	"ATTACK_BAUCHTROMMEL",
	"ATTACK_MATSCHBOMBE",
	"ATTACK_LEHMSCHELLE",
	"ATTACK_OCTAZOOKA",
	"ATTACK_STACHLER",
	"ATTACK_BLITZKANONE",
	"ATTACK_GESICHTE",
	"ATTACK_ABGANGSBUND",
	"ATTACK_ABGESANG",
	"ATTACK_EISSTURM",
	"ATTACK_SCANNER",
	"ATTACK_KNOCHENHATZ",
	"ATTACK_ZIELSCHUSS",
	"ATTACK_WUTANFALL",
	"ATTACK_SANDSTURM",
	"ATTACK_GIGASAUGER",
	"ATTACK_AUSDAUER",
	"ATTACK_CHARME",
	"ATTACK_WALZER",
	"ATTACK_TRUGSCHLAG",
	"ATTACK_ANGEBEREI",
	"ATTACK_MILCHGETRAENK",
	"ATTACK_FUNKENSPRUNG",
	"ATTACK_ZORNKLINGE",
	"ATTACK_STAHLFLUEGEL",
	"ATTACK_HORRORBLICK",
	"ATTACK_ANZIEHUNG",
	"ATTACK_SCHLAFREDE",
	"ATTACK_VITALGLOCKE",
	"ATTACK_RUECKKEHR",
	"ATTACK_GESCHENK",
	"ATTACK_FRUSTRATION",
	"ATTACK_BODYGUARD",
	"ATTACK_LEIDTEILER",
	"ATTACK_LAEUTERFEUER",
	"ATTACK_INTENSITAET",
	"ATTACK_WUCHTSCHLAG",
	"ATTACK_VIELENDER",
	"ATTACK_FEUERODEM",
	"ATTACK_STAFETTE",
	"ATTACK_ZUGABE",
	"ATTACK_VERFOLGUNG",
	"ATTACK_TURBODREHER",
	"ATTACK_LOCKDUFT",
	"ATTACK_EISENSCHWEIF",
	"ATTACK_METALLKLAUE",
	"ATTACK_UEBERWURF",
	"ATTACK_MORGENGRAUEN",
	"ATTACK_SYNTHESE",
	"ATTACK_MONDSCHEIN",
	"ATTACK_KRAFTRESERVE",
	"ATTACK_KREUZHIEB",
	"ATTACK_WINDHOSE",
	"ATTACK_REGENTANZ",
	"ATTACK_SONNENTAG",
	"ATTACK_KNIRSCHER",
	"ATTACK_SPIEGELCAPE",
	"ATTACK_PSYCHO_PLUS",
	"ATTACK_TURBOTEMPO",
	"ATTACK_ANTIK_KRAFT",
	"ATTACK_SPUKBALL",
	"ATTACK_SEHER",
	"ATTACK_ZERTRUEMMERER",
	"ATTACK_WHIRLPOOL",
	"ATTACK_PRUEGLER",
	"ATTACK_MOGELHIEB",
	"ATTACK_AUFRUHR",
	"ATTACK_HORTER",
	"ATTACK_ENTFESSLER",
	"ATTACK_VERZEHRER",
	"ATTACK_HITZEWELLE",
	"ATTACK_HAGELSTURM",
	"ATTACK_FOLTERKNECHT",
	"ATTACK_SCHMEICHLER",
	"ATTACK_IRRLICHT",
	"ATTACK_MEMENTO_MORI",
	"ATTACK_FASSADE",
	"ATTACK_POWER_PUNCH",
	"ATTACK_RIECHSALZ",
	"ATTACK_SPOTLIGHT",
	"ATTACK_NATUR_KRAFT",
	"ATTACK_LADEVORGANG",
	"ATTACK_VERHOEHNER",
	"ATTACK_RECHTE_HAND",
	"ATTACK_TRICKBETRUG",
	"ATTACK_ROLLENTAUSCH",
	"ATTACK_WUNSCHTRAUM",
	"ATTACK_ZUSCHUSS",
	"ATTACK_VERWURZLER",
	"ATTACK_KRAFTKOLOSS",
	"ATTACK_MAGIEMANTEL",
	"ATTACK_AUFBEREITUNG",
	"ATTACK_VERGELTUNG",
	"ATTACK_DURCHBRUCH",
	"ATTACK_GAEHNER",
	"ATTACK_ABSCHLAG",
	"ATTACK_NOTSITUATION",
	"ATTACK_ERUPTION",
	"ATTACK_WERTEWECHSEL",
	"ATTACK_BEGRENZER",
	"ATTACK_HEILUNG",
	"ATTACK_NACHSPIEL",
	"ATTACK_UEBERNAHME",
	"ATTACK_GEHEIMPOWER",
	"ATTACK_TAUCHER",
	"ATTACK_ARMSTOSS",
	"ATTACK_TARNUNG",
	"ATTACK_SCHWEIFGLANZ",
	"ATTACK_SCHEINWERFER",
	"ATTACK_NEBELBALL",
	"ATTACK_DAUNENREIGEN",
	"ATTACK_TAUMELTANZ",
	"ATTACK_FEUERFEGER",
	"ATTACK_LEHMSUHLER",
	"ATTACK_FROSTBEULE",
	"ATTACK_NIETENRANKE",
	"ATTACK_TAGEDIEB",
	"ATTACK_SCHALLWELLE",
	"ATTACK_GIFTZAHN",
	"ATTACK_ZERMALMKLAUE",
	"ATTACK_LOHEKANONADE",
	"ATTACK_AQUAHAUBITZE",
	"ATTACK_STERNHIEB",
	"ATTACK_ERSTAUNER",
	"ATTACK_METEOROLOGE",
	"ATTACK_AROMAKUR",
	"ATTACK_TRUGTRAENE",
	"ATTACK_WINDSCHNITT",
	"ATTACK_HITZEKOLLER",
	"ATTACK_SCHNUEFFLER",
	"ATTACK_FELSGRAB",
	"ATTACK_SILBERHAUCH",
	"ATTACK_METALLSOUND",
	"ATTACK_GRASFLOETE",
	"ATTACK_SPASSKANONE",
	"ATTACK_KOSMIK_KRAFT",
	"ATTACK_FONTRAENEN",
	"ATTACK_AMPELLEUCHTE",
	"ATTACK_FINSTERFAUST",
	"ATTACK_SONDERSENSOR",
	"ATTACK_HIMMELHIEB",
	"ATTACK_SANDGRAB",
	"ATTACK_EISESKAELTE",
	"ATTACK_LEHMBRUEHE",
	"ATTACK_KUGELSAAT",
	"ATTACK_AERO_ASS",
	"ATTACK_EISSPEER",
	"ATTACK_EISENABWEHR",
	"ATTACK_RUECKENTZUG",
	"ATTACK_JAULER",
	"ATTACK_DRACHENKLAUE",
	"ATTACK_FLORA_STATUE",
	"ATTACK_PROTZER",
	"ATTACK_SPRUNGFEDER",
	"ATTACK_LEHMSCHUSS",
	"ATTACK_GIFTSCHWEIF",
	"ATTACK_BEZIRZER",
	"ATTACK_VOLTTACKLE",
	"ATTACK_ZAUBERBLATT",
	"ATTACK_NASSMACHER",
	"ATTACK_GEDANKENGUT",
	"ATTACK_LAUBKLINGE",
	"ATTACK_DRACHENTANZ",
	"ATTACK_FELSWURF",
	"ATTACK_SCHOCKWELLE",
	"ATTACK_AQUAWELLE",
	"ATTACK_KISMETWUNSCH",
	"ATTACK_PSYSCHUB",
	"ATTACK_FILLER",
	"ATTACK_HAMMERARM",
	"ATTACK_AURASPHAERE",
	"ATTACK_GIFTHIEB",
	"ATTACK_FOKUSSTOSS",
	"ATTACK_PATRONENHIEB",
	"ATTACK_FINSTERAURA",
	"ATTACK_FLAMMENBLITZ",
	"ATTACK_EISZAHN",
	"ATTACK_DONNERZAHN",
	"ATTACK_DUNKELKLAUE",
	"ATTACK_KREUZSCHERE",
	"ATTACK_STEINKANTE",
	"ATTACK_STURZFLUG",
	"ATTACK_STEINPOLITUR",
	"ATTACK_KRAXLER",
	"ATTACK_BLAETTERSTURM",
	"ATTACK_NAHKAMPF",
	"ATTACK_LICHTKANONE",
	"ATTACK_DRACO_METEOR",
	"ATTACK_NASSSCHWEIF",
	"ATTACK_ZEN_KOPFSTOSS",
	"ATTACK_ENERGIEBALL",
	"ATTACK_SCHATTENSTOSS",
	"ATTACK_DOPPELSCHLAG",
	"ATTACK_TIEFSCHLAG",
	"ATTACK_NACHTHIEB",
	"ATTACK_SAMENBOMBE",
	"ATTACK_ERDKRAEFTE",
	"ATTACK_DRACHENPULS",
	"ATTACK_EISSPLITTER",
	"ATTACK_FEUERZAHN",
	"ATTACK_WASSERDUESE",
	"ATTACK_ZORNFEUER",
	"ATTACK_TSUNAMI",
	"ATTACK_STAHLSTREICH",
	"ATTACK_KINESISWELLE",
	"ATTACK_SUPERNOVA",
	"ATTACK_WASSERSPALT",
	"ATTACK_SCHALLSTICH",
	"ATTACK_DIEBESKUSS",
	"ATTACK_KNUDDLER",
	"ATTACK_MONDGEWALT",
	"ATTACK_ZAUBERSCHEIN",
	"ATTACK_SAEUSELSTIMME",
	"ATTACK_BIENENSTICH",
	"ATTACK_SCHWARMSTICH",
	"ATTACK_GESANG_2",
	"ATTACK_HEISSSTEIN",
	"ATTACK_GEWITTER",
	"ATTACK_EISENSLAM",
	"ATTACK_HOLZGEWEIH",
	"ATTACK_KAEFERBISS",
	"ATTACK_FALTERREIGEN",
	"ATTACK_NITROLADUNG",
	"ATTACK_KAEFERGEBRUMM",
	"ATTACK_TORNADO",
	"ATTACK_KOENIGSSCHILD",
]

affects_whom_flags = 

attack_flags = 

attack_categories = 

pchar_dict = {
	"PCHAR_SPACE":0x0,
	"PCHAR_0":0xA1,
	"PCHAR_1":0xA2,
	"PCHAR_2":0xA3,
	"PCHAR_3":0xA4,
	"PCHAR_5":0xA6,
	"PCHAR_6":0xA7,
	"PCHAR_7":0xA8,
	"PCHAR_8":0xA9,
	"PCHAR_9":0xAA,
	"PCHAR_EXCLAM":0xAB,
	"PCHAR_QUESTION":0xAC,
	"PCHAR_DOT":0xAD,
	"PCHAR_DOTS":0xAF,
	"PCHAR_MINUS":0xAE,
	"PCHAR_COMMA":0xB8,
	"PCHAR_PLUS":0x2E,
	"PCHAR_SLASH":0xBA,
	"PCHAR_A":0xBB,
	"PCHAR_B":0xBC,
	"PCHAR_C":0xBD,
	"PCHAR_D":0xBE,
	"PCHAR_E":0xBF,
	"PCHAR_F":0xC0,
	"PCHAR_G":0xC1,
	"PCHAR_H":0xC2,
	"PCHAR_I":0xC3,
	"PCHAR_J":0xC4,
	"PCHAR_K":0xC5,
	"PCHAR_L":0xC6,
	"PCHAR_M":0xC7,
	"PCHAR_N":0xC8,
	"PCHAR_O":0xC9,
	"PCHAR_P":0xCA,
	"PCHAR_Q":0xCB,
	"PCHAR_R":0xCC,
	"PCHAR_S":0xCD,
	"PCHAR_T":0xCE,
	"PCHAR_U":0xCF,
	"PCHAR_V":0xD0,
	"PCHAR_W":0xD1,
	"PCHAR_X":0xD2,
	"PCHAR_Y":0xD3,
	"PCHAR_Z":0xD4,
	"PCHAR_a":0xD5,
	"PCHAR_b":0xD6,
	"PCHAR_c":0xD7,
	"PCHAR_d":0xD8,
	"PCHAR_e":0xD9,
	"PCHAR_f":0xDA,
	"PCHAR_g":0xDB,
	"PCHAR_h":0xDC,
	"PCHAR_i":0xDD,
	"PCHAR_j":0xDE,
	"PCHAR_k":0xDF,
	"PCHAR_l":0xE0,
	"PCHAR_m":0xE1,
	"PCHAR_n":0xE2,
	"PCHAR_o":0xE3,
	"PCHAR_p":0xE4,
	"PCHAR_q":0xE5,
	"PCHAR_r":0xE6,
	"PCHAR_s":0xE7,
	"PCHAR_t":0xE8,
	"PCHAR_u":0xE9,
	"PCHAR_v":0xEA,
	"PCHAR_w":0xEB,
	"PCHAR_x":0xEC,
	"PCHAR_y":0xED,
	"PCHAR_z":0xEE,
	"PCHAR_SHARP":0x7F,
	"PCHAR_AE":0xF1,
	"PCHAR_OE":0xF2,
	"PCHAR_UE":0xF3,
	"PCHAR_ae":0xF4,
	"PCHAR_oe":0xF5,
	"PCHAR_ue":0xF6,
	"PCHAR_WAIT":0xFC,
	"PCHAR_BUFFER":0xFD,
	"PCHAR_LINE_SCROLL":0xFA,
	"PCHAR_PARAGRAPH":0xFB,
	"PCHAR_NEW_LINE":0xFE,
	"PCHAR_POKE_E":0x1B,
	"PCHAR_PARANTHESIS_START":0x5C,
	"PCHAR_PARANTHESIS_END":0x5D,
	"PCHAR_COLON":0xF0
}

trainerclasses = 

trainer_ai = 

pockets = 

flag_table = 

var_table = 

ords = 

stds = 

moves = 

map_connections = 

music = 

behaviours = 

map_namespaces = 

map_show_name = 

flash_types = 

map_weathers = 

map_types = 

battle_types = 

			
def values(_d):
	if isinstance(_d, dict): return _d.values()
	return _d

def _dict_get(_d, key, hexstr=True, _str=True, pedantic=False):
	""" Returns a string from a dict in this module if a key is present else simply the key """
	if key in _d: return _d[key]
	elif pedantic: raise Exception("Pedantic: Value " + str(key) + " not in dict " + str(_d))
	if hexstr: return hex(key)
	if _str: return str(key)
	return key

def byte_to_pchar(byte):
	for pchar in pchar_dict:
		if pchar_dict[pchar] == byte: return pchar
	return hex(byte)

def item(id, pedantic=False):
	try: return item_table[id]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(id) + " not in item list")
		else: return hex(id)

def species(id, pedantic=False):
	try: return species_table[id]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(id) + " not in species list")
		else: return hex(id)

def flag(id, pedantic=False):
	negated = id & 0x8000
	id &= 0x7FFF
	if negated: nstr = " | 0x8000"
	else: nstr = ""
	try: return flag_table[id] + nstr
	except: 
		if pedantic and id not in range(0x100): raise Exception("Pedantic: Value " + hex(id) + " not in flag list")
		else: return hex(id) + nstr

def attack(id, pedantic=False):
	try: return attack_table[id]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(id) + " not in attack list")
		else: return hex(id)

def map_connection(val, pedantic=False):
	try: return map_connections[val]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(val) + " not in connection list")
		else: return hex(val)

def flash_type(val, pedantic=False):
	try: return flash_types[val]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(val) + " not in flash type list")
		else: return hex(val)
		
def map_weather(val, pedantic=False):
	try: return map_weathers[val]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(val) + " not in map weather list")
		else: return hex(val)

def map_type(val, pedantic=False):
	try: return map_types[val]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(val) + " not in map type list")
		else: return hex(val)

def battle_type(val, pedantic=False):
	try: return battle_types[val]
	except: 
		if pedantic: raise Exception("Pedantic: Value " + hex(val) + " not in battle type list")
		else: return hex(val)

def var(val, pedantic=False):
	try: return var_table[val]
	except:
		if pedantic and val not in range(0x8000, 0x8020) and val not in range(0, 0x1000): raise Exception("Pedantic: Value " + hex(val) + " not in var list")
		else: return hex(val)

def _mkdirs(dir):
	if not os.path.exists(dir):
		os.makedirs(dir)

def export_macros(lib, dir):
	""" Exports several macros into a directory """
	_mkdirs(dir)
	macros = [
		_export_generic_macros(lib, dir, "item", item_table),
		_export_generic_macros(lib, dir, "species", species_table),
		_export_generic_macros(lib, dir, "attack", attack_table),
		_export_generic_macros(lib, dir, "ability", ability_table),
		_export_generic_macros_from_dict(lib, dir, "flag", flag_table),
		_export_generic_macros_from_dict(lib, dir, "var", var_table),
		_export_generic_macros_from_dict(lib, dir, "ord", ords),
		_export_generic_macros_from_dict(lib, dir, "std", stds),
		_export_generic_macros_from_dict(lib, dir, "moves", moves),
		_export_generic_macros(lib, dir, "map_connections", map_connections),
		_export_generic_macros_from_dict(lib, dir, "music", music),
		_export_generic_macros(lib, dir, "behaviours", behaviours),
		_export_generic_macros_from_dict(lib, dir, "map_namespaces", map_namespaces),
		_export_generic_macros_from_dict(lib, dir, "map_showname", map_show_name),
		_export_generic_macros(lib, dir, "flash_types", flash_types),
		_export_generic_macros(lib, dir, "map_weathers", map_weathers),
		_export_generic_macros(lib, dir, "map_type", map_types),
		_export_generic_macros(lib, dir, "battle_types", battle_types)
	]
	fd = open(dir + STDPREAMBLE, "w+")
	fd.write("\n\n\n".join(macros))
	fd.close()

def _export_generic_macros(lib, dir, _generic_name, _generic_table):
	""" Export generic macros """
	_mkdirs(dir)
	macro = "@ARM Assembly macro definitions for " + _generic_name + "\n\n\n"
	macro += "\n".join([(".equ " + _generic_table[i] + ", " + hex(i)) for i in range(len(_generic_table))]) + "\n"
	path = dir + _generic_name +".s"
	return macro
	"""fd = open(path, "w+")
	fd.write(macro)
	fd.close()
	lib_update(lib, _generic_name, path)"""

def _export_generic_macros_from_dict(lib, dir, _generic_name, _generic_dict):
	""" Export generic macros """
	_mkdirs(dir)
	macro = "@ARM Assembly macro definitions for " + _generic_name + "\n\n\n"
	macro += "\n".join([(".equ " + _generic_dict[k] + ", " + hex(k)) for k in _generic_dict]) + "\n"
	path = dir + _generic_name +".s"
	return macro
	"""fd = open(path, "w+")
	fd.write(macro)
	fd.close()
	lib_update(lib, _generic_name, path)"""

def lib_update(libf, type, file):
	""" Updates a macro link in the lib for a certain type """
	fd = open(libf, "r+")
	lib = eval(fd.read())
	fd.close()
	lib[type] = os.path.relpath(file, INCLUDE)
	fd = open(libf, "w+")
	fd.write(str(lib))
	fd.close()

def get_macro_header():
	""" Returns a macro header """
	"""fd = open(rpath.path(STDLIB, from_root=from_root), "r+")
	lib = eval(fd.read())
	fd.close()"""
	#return "\n".join(('.include "' + lib[k].replace("\\", "/") + '"') for k in lib) + "\n"
	return ".include \"" + STDPREAMBLE + "\""

if __name__ == "__main__":
	try:
		opts, args = getopt.getopt(sys.argv[1:], "hl:", ["help"])
	except getopt.GetoptError:
		sys.exit(2)
	lib = STDLIB
	for opt, arg in opts:
		if opt in ("-h", "--help"):
			print("Usage: constants.py outdir (e.g.'foo/bar/')")
			sys.exit(0)
		elif opt in ("-l"): lib = arg
	dir = args[0]
	print("Exporting std macros to", dir)
	export_macros(lib, dir)