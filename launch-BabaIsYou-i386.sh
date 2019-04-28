#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

BIY_DIR="${HOME}/.steam/steam/steamapps/common/Baba Is You"
BIY_BIN32="${BIY_DIR}/bin32/Chowdren"
BIY_LIB32="${BIY_DIR}/bin32"

# Required by DSA
export SteamAppId="736260"
export SteamGameId="736260"
export DSA_ORIG_STEAM_API_LIB="${BIY_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Baba Is You with DummySteamAPI...\033[0m"

cd "${BIY_DIR}"

export LD_LIBRARY_PATH="${BIY_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${BIY_BIN32}"
