#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

MFP_DIR="${HOME}/.steam/steam/steamapps/common/Machine for Pigs"
MFP_BIN64="${MFP_DIR}/Launcher.bin.x86_64"
MFP_LIB64="${MFP_DIR}/lib64"

# Required by DSA
export SteamAppId="239200"
export SteamGameId="239200"
export DSA_ORIG_STEAM_API_LIB="${MFP_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Amnesia The Dark Descent with DummySteamAPI...\033[0m"

cd "${MFP_DIR}"

export LD_LIBRARY_PATH="${MFP_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${MFP_BIN64}"
