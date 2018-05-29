#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TRA_DIR="${HOME}/.steam/steam/steamapps/common/Transistor"
TRA_BIN64="${TRA_DIR}/Transistor.bin.x86_64"
TRA_LIB64="${TRA_DIR}/lib64"

# Required by DSA
export SteamAppId="237930"
export SteamGameId="237930"
export DSA_ORIG_STEAM_API_LIB="${TRA_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Transistor with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TRA_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TRA_BIN64}"
