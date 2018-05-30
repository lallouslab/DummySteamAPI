#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TTM_DIR="${HOME}/.steam/steam/steamapps/common/To the Moon"
TTM_BIN32="${TTM_DIR}/steamshim/parent.x86"
TTM_LIB32="${TTM_DIR}/lib"

# Required by DSA
export SteamAppId="206440"
export SteamGameId="206440"
export DSA_ORIG_STEAM_API_LIB="${TTM_DIR}/steamshim/lib/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching To the Moon with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TTM_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TTM_BIN32}" "${TTM_DIR}/ToTheMoon.bin.x86"
