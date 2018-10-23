
# Transforms a gender string into an integer indicating the actual ratio
# E.g. 50% is not quite 50%, but rather 127/256
gender_to_int = {
	'50% ♂ 50% ♀' : 127,
	'—' : 255,
	'100% ♀' : 254,
	'100% ♂' : 0,
	'♂=75% ♀=25%' : 63,
	'♂=25% ♀=75%' : 191,
	'♂=87,5% ♀=12,5%' : 31
}
