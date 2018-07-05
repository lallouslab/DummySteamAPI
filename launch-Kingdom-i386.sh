#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

KNG_DIR="${HOME}/.steam/steam/steamapps/common/Kingdom"
KNG_BIN32="${KNG_DIR}/Kingdom.x86"
KNG_LIB32="${KNG_DIR}"

# Required by DSA
export SteamAppId="368230"
export SteamGameId="368230"
export DSA_ORIG_STEAM_API_LIB="${KNG_LIB32}/Kingdom_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Kingdom with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${KNG_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${KNG_BIN32}"
