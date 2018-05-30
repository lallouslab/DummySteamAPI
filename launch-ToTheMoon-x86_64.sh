#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TTM_DIR="${HOME}/.steam/steam/steamapps/common/To the Moon"
TTM_BIN64="${TTM_DIR}/steamshim/parent.amd64"
TTM_LIB64="${TTM_DIR}/lib64"

# Required by DSA
export SteamAppId="206440"
export SteamGameId="206440"
export DSA_ORIG_STEAM_API_LIB="${TTM_DIR}/steamshim/lib64/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching To the Moon with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TTM_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TTM_BIN64}" "${TTM_DIR}/ToTheMoon.bin.x86_64"
