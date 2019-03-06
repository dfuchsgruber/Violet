# Module to parse the symbol table of a rom
def parse_symbols(symbolspath):
    """ Parses the symbols of a rom.
    
    Paramters:
    ----------
    symbolspath : str
        Path to the symbols file.
    
    Returns:
    --------
    symbols : dict
        A dict symbol -> int containing all symbols exported globally.
    """
    symbols = {}
    with open(symbolspath) as f:
        for line in f.read().splitlines():
            if '.' in line: continue
            try:
                offset, symbol = line.split(' ')
                offset = int(offset, 16) - 0x08000000
                if offset >= 0:
                    symbols[symbol] = offset
            except: pass
        return symbols
    