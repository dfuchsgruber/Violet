
import os, errno
import pickle

def get_chache_path():
    """ Returns the path to the standard cache.
    
    Returns:
    --------
    cache_path : str
        Path the standard chache.
    """
    #xdg_cache_home = os.environ.get('XDG_CACHE_HOME') or \
    #        os.path.join(os.path.expanduser('~'), '.cache')
    xdg_cache_home = 'pokeapi_cache'

    return os.path.join(xdg_cache_home, 'pokeapi_crawler', 'pokeapi_crawler.chache')

def get_cache(path=None):
    """ Opens the cache.
    
    Parameters:
    -----------
    path : str or None
        Path to the cache. If None the standard cache will be loaded.
    """
    if path is None:
        path = get_chache_path()
    
    if not os.path.exists(path):
        return {}
    else:
        with open(path, 'rb') as f:
            return pickle.load(f)

def save_cache(cache, path=None):
    """ Saves (updates) the cache. 
    
    Parameters:
    -----------
    cache : dict
        The cache to store.
    path : str or None
        The path to store the cache at. If None the standard cache path will be used.    
    """
    if path is None:
        path = get_chache_path()

    if not os.path.exists(os.path.dirname(path)):
        try:
            os.makedirs(os.path.dirname(path))
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

    with open(path, 'wb+') as f:
        pickle.dump(cache, f)
