#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

HK_DIR="${HOME}/.steam/steam/steamapps/common/Hollow Knight"
HK_BIN64="${HK_DIR}/hollow_knight.x86_64"
HK_LIB64="${HK_DIR}"

# Required by DSA
export SteamAppId="367520"
export SteamGameId="367520"
export DSA_ORIG_STEAM_API_LIB="${HK_LIB64}/hollow_knight_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Hollow Knight with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${HK_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${HK_BIN64}"
