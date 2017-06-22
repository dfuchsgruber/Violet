import json
from . import tileset


class Mapfooter:
    """ Class to model a mapfooter """
    def __init__(self):
        self.width, self.height = 1, 1
        self.borders = [[0]]
        self.tsp = None
        self.tss = None
        self.border_width, self.border_height = 1, 1
        self.blocks = [[0]]
        
    def to_dict(self):
        """ Returns a json exportable dict for all attributes """
        d = {}
        d["size"] = self.width, self.height
        d["borders"] = self.borders
        d["tsp"] = None if not self.tsp else self.tsp.path
        d["tss"] = None if not self.tss else self.tss.path
        d["border_size"] = self.border_width, self.border_height
        d["blocks"] = self.blocks
        return d
    

def from_dict(d):
    """ Initializes an instance of Mapfooter from a dict d"""
    m = Mapfooter()
    m.width, m.height = d["size"]
    m.borders = d["borders"]
    m.blocks = d["blocks"]
    if d["tsp"]: m.tsp = tileset.from_file(d["tsp"])
    if d["tss"]: m.tss = tileset.from_file(d["tss"])
    m.border_width, m.border_height = d["border_size"]
    return m