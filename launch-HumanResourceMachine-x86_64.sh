#!/bin/bash

set -e

DIR=$(realpath $(dirname "$0"))

HRM_BIN64="${HOME}/.steam/steam/steamapps/common/Human Resource Machine/HumanResourceMachine.bin.x86_64"

if [ ! -f "${DIR}/Makefile.conf" ]; then
	make -C "${DIR}" defconfig
fi

make -C "${DIR}"

echo -e "\033[1;92mLaunching Human Resource Machine with DummySteamAPI...\033[0m"

LD_PRELOAD="${DIR}/out/libsteam_api.so:${LD_PRELOAD}" exec "${HRM_BIN64}"
