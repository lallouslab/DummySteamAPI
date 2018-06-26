#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

KNL_DIR="${HOME}/.steam/steam/steamapps/common/Kingdom New Lands"
KNL_BIN64="${KNL_DIR}/Kingdom.x86_64"
KNL_LIB64="${KNL_DIR}"

# Required by DSA
export SteamAppId="496300"
export SteamGameId="496300"
export DSA_ORIG_STEAM_API_LIB="${KNL_LIB64}/Kingdom_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Kingdom: New Lands with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${KNL_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${KNL_BIN64}"
