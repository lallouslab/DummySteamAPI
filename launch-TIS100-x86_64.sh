#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TIS_DIR="${HOME}/.steam/steam/steamapps/common/TIS-100"
TIS_BIN64="${TIS_DIR}/tis100.x86_64"
TIS_LIB64="${TIS_DIR}"

# Required by DSA
export SteamAppId="370360"
export SteamGameId="370360"
export DSA_ORIG_STEAM_API_LIB="${TIS_LIB64}/tis100_Data/Plugins/x86_64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching TIS-100 with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TIS_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TIS_BIN64}"
