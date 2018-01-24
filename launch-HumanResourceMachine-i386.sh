#!/bin/bash

set -e

DIR=$(realpath $(dirname "$0"))

. "${DIR}/config.sh"

HRM_BIN64="${HOME}/.steam/steam/steamapps/common/Human Resource Machine/HumanResourceMachine.bin.x86"

export SteamAppId="375820"
export SteamGameId="375820"

if [ ! -f "${DIR}/Makefile.conf" ]; then
	make -C "${DIR}" defconfig CFLAGS="-m32" LDFLAGS="-m32"
fi

make -C "${DIR}" CFLAGS="-m32" LDFLAGS="-m32"

echo -e "\033[1;92mLaunching Human Resource Machine with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${DIR}/bin:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

. "${DIR}/common.sh"

exec "${HRM_BIN64}"
