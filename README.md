# Violet_Sources
This is the repository of Pokémon Violet. It can be used to build the project from source instead of applying a patch or to get an insight into how the features work. This README describes the repository rather than the project itself. Visit the project [website](http://wodkarhr.github.io/Violet_Sources/) for information about the game.

## Development
This project does not provide builds for legal reasons (we don't want big N to get angry at us, do we).  
Instead, you can build this project on your own.

For ease of accessability, setting up the development (and building) environment has been made as simple as possible.

This chapter describes how to set up the development environment and use it for building your own copy of Pokémon V.

### Tools
Following tools are necessary for the development environment:
- A Linux environment
  - A Linux operating system
  - [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/) on Windows
- [The Nix Package Manager](https://nixos.org/)
- If you'd like to use the bundled `mgba` and `pymapgui` you also need this:
  - A GL graphic card driver
  - Either of these environments which support Xorg
    - Wayland
    - X11
    - wslg (included in WSL2 on Windows 11)
    - X11 server (such as Xming or VcXsrv for Windows)
- For coding on the project
  - Any `vscode` text editor
    - [VSCodium](https://vscodium.com/)
    - [Visual Studio Code](https://code.visualstudio.com/)
  - [`direnv`](https://direnv.net/) for the seamless use of `nix` in your `vscode` editor

### Resources
- A german Pokémon Fire Red backup (download is illegal!)

### Preparation
In order to build the tool chain and additional packages for developing and building Pokémon V, run the following command in your Linux environment:

```sh
nix-shell
```

This command will build the tool chain and open up a bash terminal with all required tools available.

In order to automatically launch `nix-shell` in your `vscode`-editor, install the "direnv" extension:
  - OpenVSX: <https://open-vsx.org/extension/mkhl/direnv>
  - Visual Studio Marketplace: <https://marketplace.visualstudio.com/items?itemName=mkhl.direnv>

After installing and enabling `direnv` for this project, `nix-shell` will automatically load once you have restarted Visual Studio Code.

## Configuration
If you don't have a `.env` file in the project folder yet, run the following to create it.

```sh
make -C Violet init
```

In the newly created `.env` file, you can specify the location of your backup of the German Pokémon Fire Red ROM.

Example:

***.env:***
```sh
BASEROM=~/Documents/Dumps/Pokemon\ -\ Feuerrote\ Edition\ \(Germany\).gba
```

## Building

Make sure you are in the `nix-shell` environment either by running `nix-shell` in your console or by using your `vscode`-editor with the "direnv" extension.

Run the following command to build all assets of Pokémon V (including the ROM):

```
make -C Violet all
```

## Adding and Testing Ingame-Features
There is a map called `map_4_3_debug` where you can place scripts or npcs for entering experimental scenarios.  
You can get to the map by loading the cheat file located at `Violet/sav/Debug Mode.clt` and holding <kbd>L</kbd> + <kbd>R</kbd> and <kbd>A</kbd> while examining the console in the player's room.

<!--- References -->
[SoundFontRipper]: https://github.com/WodkaRHR/gba-mus-ripper

## Changing Python Package Versions

To change e.g. the pyagb dependency to a new commit, change the `version` field in `flake.nix` to the full commit SHA. Then replace the checksum (`sha256`) to a dummy by uncommenting the `# sha256 = pkgs.lib.fakeSha256;` line. Force a rebuild of the nix shell with:

```bash
nix develop --impure --extra-experimental-features nix-command --extra-experimental-features flakes
```
