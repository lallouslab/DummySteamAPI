#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

SBH_DIR="${HOME}/.steam/steam/steamapps/common/7 Billion Humans"
SBH_BIN32="${SBH_DIR}/7BillionHumans.bin.x86"
SBH_LIB32="${SBH_DIR}/lib"

# Required by DSA
export SteamAppId="792100"
export SteamGameId="792100"
export DSA_ORIG_STEAM_API_LIB="${SBH_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching 7 Billion Humans with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${SBH_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${SBH_BIN32}"
