#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

CEL_DIR="${HOME}/.steam/steam/steamapps/common/Celeste/"
CEL_BIN32="${CEL_DIR}/Celeste.bin.x86"
CEL_LIB32="${CEL_DIR}/lib"

# Required by DSA
export SteamAppId="504230"
export SteamGameId="504230"
export DSA_ORIG_STEAM_API_LIB="${CEL_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Celeste with DummySteamAPI...\033[0m"

cd "${CEL_DIR}"

export LD_LIBRARY_PATH="${CEL_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${CEL_BIN32}"
