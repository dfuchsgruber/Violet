#!/bin/sh
pipenv install
pipenv run make -j$(nproc) -C Violet all