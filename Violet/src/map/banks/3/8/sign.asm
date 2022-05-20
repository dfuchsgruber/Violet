.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_8_sign_0
.global ow_script_route_8_sign_1

ow_script_route_8_sign_0:
	loadpointer 0 str_sign_0
	callstd MSG_SIGN
	end
ow_script_route_8_sign_1:
	loadpointer 0 str_sign_1
	callstd MSG_SIGN
	end

.ifdef LANG_GER
str_sign_0:
	.autostring 34 2 "Route 8\nUP_ARROWLaubkind-Dorf\lDOWN_ARROWKranzwald"
str_sign_1:
	.autostring 34 2 "Hügel der Gelassenheit"

.elseif LANG_EN
str_sign_0:
	.autostring 34 2 "Route 8\nUP_ARROWLeafvillage\lDOWN_ARROWKranzdorf-Forest"
str_sign_1:
	.autostring 34 2 "Placid Hill"

.endif
