#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TIS_DIR="${HOME}/.steam/steam/steamapps/common/TIS-100"
TIS_BIN32="${TIS_DIR}/tis100.x86"
TIS_LIB32="${TIS_DIR}"

# Required by DSA
export SteamAppId="370360"
export SteamGameId="370360"
export DSA_ORIG_STEAM_API_LIB="${TIS_LIB32}/tis100_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching TIS-100 with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TIS_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TIS_BIN32}"
