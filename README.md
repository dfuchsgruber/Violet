# Violet_Sources

This is the repository of Pokémon Violet. It can be used to build the project from source instead of applying a patch or to get an insight into how the features work. This README describes the repository rather than the project itself. Visit the project [website](http://wodkarhr.github.io/Violet_Sources/) for information about the game.

## Requirements

The build process of this repository requires you to have installed:

### Tools
- [devkitPro](https://sourceforge.net/projects/devkitpro/)
- [armips](https://github.com/Kingcom/armips)
- [python 3.X](https://www.python.org/)
- [Midi2Agb](https://github.com/ipatix/midi2agb) - not currently but at some point
- [soundFontRipper](https://github.com/WodkaRHR/gba-mus-ripper)
### Python
- [pyagb](https://github.com/WodkaRHR/pyagb)
### Rom
- A german firered rom (download is illegal!)

## Configuration

After fulfilling the requirements place the rom file at `base/bprd.gba`. Adjust the commands in the `makefile` to execute the binaries above.

## Building

Simply run the makefile:
```
$ make all
```




