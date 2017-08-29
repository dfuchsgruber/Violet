import agb

STDPROJ = "../map/proj.pmp"
MAPOUTPUT = "../map/%b/%m/map_%b_%m.pmh" #%b will be replaced with bank and %m with map
MAPSYM = "map_%b_%m"
TSOUTPUT = "../map/tileset/tileset%n/maptileset%n" #%s will be replaced with the offset and %n with the number relative to TSTABLE
TSGRAPHIC = "../map/tileset/tileset%n/gfx_maptileset%n.png" #Can be None as well - no graphic will be exported then
TSGFXSYM = "gfx_maptileset%nTiles"
TSSYM = "maptileset%n"
STDROM = agb.VIOLETPATH