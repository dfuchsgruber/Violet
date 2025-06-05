{
  description = "Flake for developing Pokémon V";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=b833ff01a0d694b910daca6e2ff4a3f26dee478c";
    nixgl.url = "github:nix-community/nixGL?ref=310f8e49a149e4c9ea52f1adf70cdc768ec53f8a";
    flake-utils.url = "github:numtide/flake-utils?ref=b1d9ab70662946ef0850d488da1c9019f3a9752a";
  };

  outputs = { self, nixpkgs, nixgl, flake-utils }:
    flake-utils.lib.eachDefaultSystem
      (system:
        let
          pkgs = import nixpkgs {
            inherit system;

            overlays = [
              nixgl.overlay
            ];

            config = {
              permittedInsecurePackages = [
                "freeimage-unstable-2021-11-01"
              ];
            };
          };

          python3 = pkgs.python312;

          # Build `pyclibrary`
          pyclibrary = (
            python3.pkgs.buildPythonPackage rec {
              pname = "pyclibrary";
              version = "0.2.2";

              src = pkgs.fetchPypi {
                inherit pname version;
                sha256 = "mQL//jYbuG9Xq2KqQZXsTdOCtjxcaJK+bZeE7Ao1dfc=";
              };

              nativeBuildInputs =
                with python3.pkgs;
                [
                  pip
                ];

              propagatedBuildInputs =
                with python3.pkgs;
                [
                  pyparsing
                ];

              setuptoolsCheckPhase = "true";
            });

          # Build most recent supported version of `pyagb`
          pyagb = python3.pkgs.buildPythonPackage rec {
            pname = "pyagb";
            version = "4f9a983080a8c03410eca3a333b02621e124b3cf";
            pyproject = true;

            src = pkgs.fetchFromGitHub {
              owner = "dfuchsgruber";
              repo = pname;
              rev = version;
              sha256 = "sha256-1mEriP/o8/mxVdDEVONGqjcawaTks+sx5JdvsXCSM7c=";
            };

            nativeBuildInputs =
              with python3.pkgs;
              [
                setuptools
              ];

            propagatedBuildInputs =
              with python3.pkgs;
                [
                  appdirs
                  colormath
                  pillow
                  pyclibrary
                  pypng
                  pyqtgraph
                  pyside6
                  scikit-image
                  scipy
                  typing-extensions
                ];

            postInstall = ''
              binName="pymap"
              pymap="$(mktemp -d --tmpdir="$out")/$binName"
              mv "$out/bin/$binName" "$pymap"
              makeWrapper "${pkgs.nixgl.nixGLIntel}/bin/nixGLIntel" "$out/bin/$binName" \
                --run "[ ! -f .env ] || { set -o allexport; source ./.env; set +o allexport; }" \
                --add-flags "$pymap"
            '';
          };

          # Build `grit`
          grit = pkgs.stdenv.mkDerivation (
            with pkgs;
            rec {
              pname = "grit";
              version = "0.8.17";

              src = fetchFromGitHub {
                owner = "devKitPro";
                repo = pname;
                rev = "v${version}";
                sha256 = "dIF59akcVaRH5/y7ZQ2FlGIOD8q3RS4bt1k5cEVqtUw=";
              };

              buildInputs = [
                autoreconfHook
                freeimage
              ];
            });

          # Build `wav2agb`
          wav2agb = pkgs.stdenv.mkDerivation (
            with pkgs;
            rec {
              pname = "wav2agb";
              version = "b461c20e1da68a95b4084456bf5fe651eb10a17f";

              src = fetchFromGitHub {
                owner = "ipatix";
                repo = pname;
                rev = version;
                sha256 = "fHK/pgZLj1sMhS+JZ5gi2lP+Jn47h0Au1dPXWfqDZ6M=";
              };

              nativeBuildInputs = [
                gcc12
              ];

              installPhase = ''
                runHook preInstall
                mkdir -p "$out/bin"
                cp wav2agb "$out/bin"
                runHook postInstall
              '';
            });

          # Build `midi2agb`
          midi2agb = pkgs.stdenv.mkDerivation rec {
            pname = "midi2agb";
            version = "ff820bf5453a0e2b6a4612da2cd1d5fc8c220b20";

            src = pkgs.fetchFromGitHub {
              owner = "ipatix";
              repo = pname;
              rev = version;
              fetchSubmodules = true;
              sha256 = "6MO4LLVP4SACEbY/rNmZOIAs896jVSKUr6wFtr1cFE4=";
            };

            installPhase = ''
              runHook preInstall
              mkdir -p "$out/bin"
              cp midi2agb "$out/bin"
              runHook postInstall
            '';
          };

          # Build `armips`
          armips = pkgs.stdenv.mkDerivation (
            with pkgs;
            rec {
              pname = "armips";
              version = "0febea0aecee2e2186529f0bbd180b06ce7e275c";

              src = fetchFromGitHub {
                owner = "Kingcom";
                repo = pname;
                rev = version;
                fetchSubmodules = true;
                sha256 = "3E9WYjoCBh/032HWw8YgPuARxSaBp5uW1nlX6CJTGCE=";
              };

              buildInputs = [
                cmake
              ];

              installPhase = ''
                runHook preInstall
                mkdir -p "$out/bin"
                cp armips "$out/bin"
                runHook postInstall
              '';
            });

            # Build `gba-mus-ripper`
            gba-mus-ripper = pkgs.stdenv.mkDerivation (
              with pkgs;
              rec {
                pname = "gba-mus-ripper";
                version = "1211a9b8426fa79d2e29e394fa900c8ad56865b5";

                src = fetchFromGitHub {
                  owner = "dfuchsgruber";
                  repo = pname;
                  rev = version;
                  sha256 = "DMAHsiYurMufqQGdllhh2Yk2Qm8jOxAiwx56y8mhp08=";
                };

                preBuild = ''
                  sed -i -e  "s/^FLAGS=/\0 -Wno-format-security /" Makefile
                '';

                installPhase = ''
                  runHook preInstall
                  mkdir -p "$out/bin"
                  cp out/* "$out/bin"
                  cp {goldensun_synth,psg_data}.raw "$out"
                  runHook postInstall
                '';

                nativeBuildInputs = [
                  glibc.static
                  gcc12
                ];
              });

            # Patch `mgba` to work with nixGL
            mgba-wrapper = pkgs.runCommand "mgba-wrapper" {
              buildInputs = [
                pkgs.makeWrapper
              ];
            } ''
              mkdir "$out"

              # Link all files from original `mgba`
              ln -s "${pkgs.mgba}"/* "$out"

              # Create `bin` folder with symlinks to the contents of `mgba`s `bin` folder
              rm "$out/bin"
              mkdir "$out/bin"
              ln -s "${pkgs.mgba}"/bin/* "$out/bin"

              # Replace `mgba` and `mgba-qt` with `nixGL` call
              for file in mgba mgba-qt
              do
                rm "$out/bin/$file";
                makeWrapper "${pkgs.nixgl.nixGLIntel}/bin/nixGLIntel" "$out/bin/$file" --add-flags "${pkgs.mgba}/bin/$file"
              done
            '';
        in
        rec {
          packages = {
            inherit
              pyclibrary
              armips
              gba-mus-ripper
              grit
              mgba-wrapper
              midi2agb
              pyagb
              wav2agb
            ;
          };

          devShells.default = pkgs.mkShellNoCC (
            with pkgs;
            {
              packages = [
                armips
                bc
                gba-mus-ripper
                gcc-arm-embedded
                grit
                mgba-wrapper
                midi2agb
                pkgs.nixgl.nixGLIntel
                pyagb
                pyclibrary
                python3
                wav2agb
              ] ++ (
                with python3.pkgs;
                [
                  ipykernel
                  pyaml
                ]
              );

              # Dependencies for running `pymapgui`
              nativeBuildInputs =
              with pkgs;
              [
                  qt6.qtbase
                  qt6.wrapQtAppsHook
                  makeWrapper
                  openssl
              ];

              # Propagate location of Golden Sun synth using environment variables
              PSG_DATA = "${packages.gba-mus-ripper}/psg_data.raw";
              GOLDENSUN_SYNTH = "${packages.gba-mus-ripper}/goldensun_synth.raw";

              # Force using Xorg over Wayland (Wayland does not seem to work with nixGL)
              QT_QPA_PLATFORM = "xcb";
              QT_XCB_GL_INTEGRATION = "xcb_egl";

              # Allow using Qt5 in nix shell
              shellHook = ''
                set -o allexport; \
                [ ! -f ".env" ] || source ".env"; \
                set +o allexport; \
                setQtEnvironment=$(mktemp)
                random=$(openssl rand -base64 20 | sed "s/[^a-zA-Z0-9]//g")
                makeWrapper "$(type -p sh)" "$setQtEnvironment" "''${qtWrapperArgs[@]}" --argv0 "$random"
                sed "/$random/d" -i "$setQtEnvironment"
                source "$setQtEnvironment"
              '';
            });
        }
      );
}
