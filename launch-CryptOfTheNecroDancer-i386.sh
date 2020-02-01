#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

COTND_DIR="${HOME}/.steam/steam/steamapps/common/Crypt of the NecroDancer"
COTND_BIN32="${COTND_DIR}/NecroDancer"
COTND_LIB32="${COTND_DIR}"

# Required by DSA
export SteamAppId="247080"
export SteamGameId="247080"
export DSA_ORIG_STEAM_API_LIB="${COTND_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Crypt of the NecroDancer with DummySteamAPI...\033[0m"

cd "${COTND_DIR}"

export LD_LIBRARY_PATH="${COTND_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${COTND_BIN32}"
