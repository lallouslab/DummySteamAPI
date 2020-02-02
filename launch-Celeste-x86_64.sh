#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

CEL_DIR="${HOME}/.steam/steam/steamapps/common/Celeste"
CEL_BIN64="${CEL_DIR}/Celeste.bin.x86_64"
CEL_LIB64="${CEL_DIR}/lib64"

# Required by DSA
export SteamAppId="504230"
export SteamGameId="504230"
export DSA_ORIG_STEAM_API_LIB="${CEL_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Celeste with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${CEL_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${CEL_BIN64}"
