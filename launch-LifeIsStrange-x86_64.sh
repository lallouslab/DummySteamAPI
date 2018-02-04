#!/bin/bash

set -e

DIR=$(realpath $(dirname "$0"))

. "${DIR}/config.sh"

LIS_DIR="${HOME}/.steam/steam/steamapps/common/Life Is Strange"
LIS_BIN64="${LIS_DIR}/bin/LifeIsStrange"
LIS_LIB64="${LIS_DIR}/lib/x86_64"

# Required by DSA
export SteamAppId="319630"
export SteamGameId="319630"
export DSA_ORIG_STEAM_API_LIB="${LIS_LIB64}/libsteam_api.so"

if [ ! -f "${DIR}/Makefile.conf" ]; then
	make -C "${DIR}" defconfig
fi

make -C "${DIR}"

echo -e "\033[1;92mLaunching Life Is Strange with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${LIS_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

. "${DIR}/common.sh"

cd "${LIS_DIR}/bin"

exec "${LIS_BIN64}"
