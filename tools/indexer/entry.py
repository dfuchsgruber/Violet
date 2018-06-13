class IndexEntry:
    """ Class to store an index entry """

    def __init__(self, where="", how="", comment=""):
        """ 
        Parameters:
        where : Where the element can be found (namespace)
        how : The method of obtaining
        comment : Additional information """
        self.where = where
        self.how = how
        self.comment = comment