class Map_connection:
    """ Class to model a map connection """
    def __init__(self):
        self.direction = 0
        self.displacement = 0
        self.bank = 0
        self.map = 0
        self.field_a = 0
        self.field_b = 0

    def to_dict(self): return self.__dict__

def from_dict(d):
    """ Retrieves a map connection from a dict """
    m = Map_connection()
    for k, v in d.items(): m.__setattr__(k, v)
    return m