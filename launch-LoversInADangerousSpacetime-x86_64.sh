#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

LDS_DIR="${HOME}/.steam/steam/steamapps/common/Lovers in a Dangerous Spacetime"
LDS_BIN64="${LDS_DIR}/LoversInADangerousSpacetime.x86_64"
LDS_LIB64="${LDS_DIR}"

# Required by DSA
export SteamAppId="252110"
export SteamGameId="252110"
export DSA_ORIG_STEAM_API_LIB="${LDS_LIB64}/LoversInADangerousSpacetime_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Lovers in a Dangerous Spacetime with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${LDS_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${LDS_BIN64}"
