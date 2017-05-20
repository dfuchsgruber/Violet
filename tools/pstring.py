""" Module to provide methods for conversion from and to pokehex """

class PString:

    """ Factory class for string conversion """
    def __init__(self, table, terminator = 0xFF):
        self.terminator = terminator
        self.load_table(table)

    def load_table(self, table):
        """ Parses a .tbl table file """
        fd = open(table, "r")
        table = fd.read()
        fd.close()

        self.table = {}
        self.rev_table = [None] * 256

        for line in table.split("\n"):
            tokens = line.split(" ")
            if len(tokens) == 3 and tokens[1] == "=":
                #whitespace is the delimiter, but can also be a literal
                if tokens[0] == "": tokens[0] = " "
                value = int(tokens[2], 0)
                if value > 255: raise ("Non byte value associated with literal " + tokens[0])
                self.table[tokens[0]] = value
                if not self.rev_table[value]: self.rev_table[value] = tokens[0]
                    
            
    def str2hex(self, string):
        """ Parses a string and returns a list of bytes """
        string = string[:] #Create a copy of the mutable string
        bytes = []
        while len(string):
            matched_literal = None
            for literal in self.table:
                if string.find(literal) == 0:
                    matched_literal = literal
                    break
            if not matched_literal: raise ("Could not parse first literal in " + string)
            bytes.append(self.table[matched_literal])
            string = string[len(matched_literal):]
        #Append the string terminator
        bytes.append(self.terminator)
        return bytes
    
    def hex2str(self, rom, offset, decap=False):
        """ Parses bytes at an offset into a string """
        result = ""
        while True:
            value = rom.u8(offset)
            if value == self.terminator: break
            if not self.rev_table[value]: raise Exception("No literal associated with "+hex(value))
            result += self.rev_table[value]
            offset += 1
        if decap:
            return decap_by_delimiters(result)
        else:
            return result

def recap_by_delimiter(s, delim):
    """ Splits a string by a delimiter, recapitalizes tokens and joins it back together"""
    return delim.join([token[0].capitalize() + token[1:] for token in s.split(delim)])

def decap_by_delimiters(s, delims=[" ", "_", "-"]):
    """ Splits a string by different delimiters, decapitalizes and joins it back together"""
    s = s.lower() #Decap everything at first
    for delim in delims:
        #print("splitting", s, "by", delim)
        s = recap_by_delimiter(s, delim)
        #print("done:",s)
    return s


    