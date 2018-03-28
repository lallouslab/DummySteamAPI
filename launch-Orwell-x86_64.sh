#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

ORW_DIR="${HOME}/.steam/steam/steamapps/common/Orwell"
ORW_BIN64="${ORW_DIR}/Orwell.x86_64"
ORW_LIB64="${ORW_DIR}"

# Required by DSA
export SteamAppId="491950"
export SteamGameId="491950"
export DSA_ORIG_STEAM_API_LIB="${ORW_LIB64}/Orwell_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Orwell with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${ORW_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${ORW_BIN64}"
