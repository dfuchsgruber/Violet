NAMESPACE_BASE = 88
NAMESPACES_SYMBOL = "map_namespaces"

def map_namespace_to_string(namespace, rom, proj, ps, symbols):
    """ Retrieves the name of a map by its namespace_idx 
    
    Parameters:
    namespace_idx : Index (int) of namespace 
    rom : Agbrom instance representing the rom
    proj : The pymap project to resolve the namespace constant
    ps : Pstring instance to parse bytes to string
    symbol : dict symbol -> offset for resovling symbols 
    
    Returns: string : the namespace's name """
    ns_table = symbols[NAMESPACES_SYMBOL]
    namespace_idx = proj.constants.value(namespace, "map_namespaces") - NAMESPACE_BASE
    str_offset = rom.pointer(ns_table + 4 * namespace_idx)
    return ps.hex2str(rom, str_offset)
