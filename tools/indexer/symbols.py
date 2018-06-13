""" Parses a symbol table provided by armips's -sym option """

def parse_symbols(filepath, base=0x8000000):
    """ Parses a symbol table provided by armips's -sym option
    Returns:
    A dictionary: symbol -> offset """
    symbols = {}
    with open(filepath) as f:
        content = f.read()

    # Parse linewise
    for line in content.splitlines():
        parse_line(symbols, line, base=base)
    return symbols#

def verify_symbols(symbols, rom, verification=[1, 3, 3, 7, 4, 2, 4, 2], verification_symbol="indexer_verification"):
    """ Verifies the correctness of the symbol table by verifying the content at a certain symbol

    Parameters:
    symbols : The symbol table
    rom : An agbrom.Agbrom instance
    vericiation : The sequency expected at the offset
    verification : The symbol that refers to the verification sequence 
    
    Throws assertion errors if the sequences do not match"""
    offset = symbols[verification_symbol]
    for i in range(len(verification)):
        assert(verification[i] == rom.u8(offset + i))

def parse_line(symbols, line, base=0x9000000):
    """ Parses a single line and adds the symbol """
    tokens = line.split(" ")
    if len(tokens) < 2: return
    if tokens[1].startswith("."):
        # Ignore meta information
        return
    else:
        offset = int(tokens[0], 16) - base
        symbol = tokens[1]
        if symbol in symbols:
            print("Warning: Redefinition of symbol {0} from {1} to {2}".format(
                symbol, hex(symbols[symbol]), hex(offset)
            ))
        symbols[symbol] = offset
    