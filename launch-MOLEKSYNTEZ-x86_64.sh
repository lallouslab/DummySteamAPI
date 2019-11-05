#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

MS_DIR="${HOME}/.steam/steam/steamapps/common/MOLEK-SYNTEZ"
MS_BIN64="${MS_DIR}/MOLEK-SYNTEZ.bin.x86_64"
MS_LIB64="${MS_DIR}/lib64"

# Required by DSA
export SteamAppId="1168880"
export SteamGameId="1168880"
export DSA_ORIG_STEAM_API_LIB="${MS_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching MOLEK-SYNTEZ with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${MS_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${MS_BIN64}"
