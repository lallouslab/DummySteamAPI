#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

KNL_DIR="${HOME}/.steam/steam/steamapps/common/Kingdom New Lands"
KNL_BIN32="${KNL_DIR}/Kingdom.x86"
KNL_LIB32="${KNL_DIR}"

# Required by DSA
export SteamAppId="496300"
export SteamGameId="496300"
export DSA_ORIG_STEAM_API_LIB="${KNL_LIB32}/Kingdom_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Kingdom: New Lands with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${KNL_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${KNL_BIN32}"
