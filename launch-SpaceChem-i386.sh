#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

SC_DIR="${HOME}/.steam/steam/steamapps/common/SpaceChem"
SC_BIN32="${SC_DIR}/spacechem-launcher.sh"
SC_LIB32="${SC_DIR}"

# Required by DSA
export SteamAppId="92800"
export SteamGameId="92800"
export DSA_ORIG_STEAM_API_LIB="${SC_LIB64}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Space Chem with DummySteamAPI...\033[0m"

cd "${SC_DIR}"

export LD_LIBRARY_PATH="${SC_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${SC_BIN32}"
