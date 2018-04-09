#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

OIS_DIR="${HOME}/.steam/steam/steamapps/common/Orwell Ignorance is Strength"
OIS_BIN64="${OIS_DIR}/Ignorance.x86_64"
OIS_LIB64="${OIS_DIR}"

# Required by DSA
export SteamAppId="633060"
export SteamGameId="633060"
export DSA_ORIG_STEAM_API_LIB="${OIS_LIB64}/Ignorance_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Orwell: Ignorance is Strength with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${OIS_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${OIS_BIN64}"
