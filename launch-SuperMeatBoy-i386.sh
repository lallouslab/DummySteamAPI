#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

SMB_DIR="${HOME}/.steam/steam/steamapps/common/Super Meat Boy/"
SMB_BIN32="${SMB_DIR}/x86/SuperMeatBoy"
SMB_LIB32="${SMB_DIR}/x86"

# Required by DSA
export SteamAppId="40800"
export SteamGameId="40800"
export DSA_ORIG_STEAM_API_LIB="${SMB_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Super Meat Boy with DummySteamAPI...\033[0m"

cd "${SMB_DIR}"

export LD_LIBRARY_PATH="${SMB_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${SMB_BIN32}"
