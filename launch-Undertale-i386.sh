#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

UDT_DIR="${HOME}/.steam/steam/steamapps/common/Undertale"
UDT_BIN32="${UDT_DIR}/runner"
UDT_LIB32="${UDT_DIR}/lib"

# Required by DSA
export SteamAppId="391540"
export SteamGameId="391540"
export DSA_ORIG_STEAM_API_LIB="${UDT_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Undertale with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${UDT_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${UDT_BIN32}"
