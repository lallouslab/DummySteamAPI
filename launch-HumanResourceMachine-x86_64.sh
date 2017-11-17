#!/bin/bash

set -e

DIR=$(realpath $(dirname "$0"))

HRM_BIN64="${HOME}/.steam/steam/steamapps/common/Human Resource Machine/HumanResourceMachine.bin.x86_64"

if [ ! -f "Makefile.conf" ]; then
	make defconfig
fi

make

echo -e "\033[1;92mLaunching Human Resource Machine with DummySteamAPI...\033[0m"

LD_PRELOAD="${DIR}/out/libsteam_api.so:${LD_PRELOAD}" "${HRM_BIN64}"
