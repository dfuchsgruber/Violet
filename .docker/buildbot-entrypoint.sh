#!/bin/sh
pipenv install
dos2unix $(pipenv run which pymap2s.py)
pipenv run make -j$(nproc) -C Violet all