#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

DTM_DIR="${HOME}/.steam/steam/steamapps/common/39 Days to Mars"
DTM_BIN32="${DTM_DIR}/39 Days to Mars.x86"
DTM_LIB32="${DTM_DIR}"

# Required by DSA
export SteamAppId="504920"
export SteamGameId="504920"
export DSA_ORIG_STEAM_API_LIB="${DTM_LIB32}/39 Days to Mars_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching 39 Days to Mars with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${DTM_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${DTM_BIN32}"
