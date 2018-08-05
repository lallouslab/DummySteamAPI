#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TER_DIR="${HOME}/.steam/steam/steamapps/common/Terraria"
TER_BIN64="${TER_DIR}/Terraria"
TER_LIB64="${TER_DIR}/lib64"

# Required by DSA
export SteamAppId="105600"
export SteamGameId="105600"
export DSA_ORIG_STEAM_API_LIB="${TER_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Terraria with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TER_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

export TERM=xterm

exec "${TER_BIN64}" -x64
