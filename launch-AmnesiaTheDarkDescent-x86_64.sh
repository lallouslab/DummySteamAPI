#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

ATDD_DIR="${HOME}/.steam/steam/steamapps/common/Amnesia The Dark Descent"
ATDD_BIN64="${ATDD_DIR}/Launcher.bin.x86_64"
ATDD_LIB64="${ATDD_DIR}/lib64"

# Required by DSA
export SteamAppId="57300"
export SteamGameId="57300"
export DSA_ORIG_STEAM_API_LIB="${ATDD_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Amnesia The Dark Descent with DummySteamAPI...\033[0m"

cd "${ATDD_DIR}"

export LD_LIBRARY_PATH="${ATDD_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${ATDD_BIN64}"
