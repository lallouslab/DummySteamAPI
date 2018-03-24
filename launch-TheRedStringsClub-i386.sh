#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TRSC_DIR="${HOME}/.steam/steam/steamapps/common/The Red Strings Club"
TRSC_BIN32="${TRSC_DIR}/runner"
TRSC_LIB32="${TRSC_DIR}/lib"

# Required by DSA
export SteamAppId="589780"
export SteamGameId="589780"
export DSA_ORIG_STEAM_API_LIB="${TRSC_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching The Red Strings Club with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TRSC_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TRSC_BIN32}"
