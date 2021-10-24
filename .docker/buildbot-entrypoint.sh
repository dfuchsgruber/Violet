#!/bin/bash
pipenv install
cp /etc/violet/gba-mus-ripper/{goldensun_synth.raw,psg_data.raw} ./Violet
pipenv run make -j$(nproc) -C Violet all
