#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

HRM_DIR="${HOME}/.steam/steam/steamapps/common/Human Resource Machine"
HRM_BIN64="${HRM_DIR}/HumanResourceMachine.bin.x86_64"
HRM_LIB64="${HRM_DIR}/lib64"

# Required by DSA
export SteamAppId="375820"
export SteamGameId="375820"
export DSA_ORIG_STEAM_API_LIB="${HRM_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Human Resource Machine with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${HRM_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${HRM_BIN64}"
