from . import mapfooter, mapconnection, mapevent
import json
import os

PATH_UNSAFED = "Unsafed map"

def block_data(block):
    """ Returns a block id and level data"""
    return block & 0x3FF, ((block >> 10) & 0x3F)

class Mapheader:
    """ Class to model a mapheader """
    def __init__(self):
        self.footer = mapfooter.Mapfooter()
        self.persons = []
        self.warps = []
        self.signposts = []
        self.triggers = []
        self.levelscript_header = "0"
        self.connections = []
        self.music = 0
        self.id = 0
        self.name_bank = 0
        self.flash_type = 0
        self.weather = 0
        self.type = 0
        self.field_18 = 0
        self.show_name = 0
        self.battle_style = 0
        self.key = PATH_UNSAFED

    def save(self, path):
        """ Serialization method for the mapheader """
        self.key = os.path.relpath(path)
        d = self.__dict__.copy()
        d["footer"] = self.footer.to_dict()
        d["persons"] = [p.to_dict() for p in self.persons]
        d["warps"] = [w.to_dict() for w in self.warps]
        d["signposts"] = [s.to_dict() for s in self.signposts]
        d["triggers"] = [t.to_dict() for t in self.triggers]
        d["connections"] = [c.to_dict() for c in self.connections]
        fd = open(path, "w+")
        json.dump(d, fd)
        fd.close()

def load(path):
    """ Instanciates a mapheader from a json file"""
    m = Mapheader()
    fd = open(path, "r+")
    d = json.load(fd)
    fd.close()
    for k, v in d.items(): m.__setattr__(k, v)
    m.footer = mapfooter.from_dict(m.footer)
    m.persons = [mapevent.from_dict(pd) for pd in m.persons]
    m.warps = [mapevent.from_dict(wd) for wd in m.warps]
    m.signposts = [mapevent.from_dict(sd) for sd in m.signposts]
    m.triggers = [mapevent.from_dict(td) for td in m.triggers]
    m.connections = [mapconnection.from_dict(cd) for cd in m.connections]
    #print(d, m.footer)
    return m
