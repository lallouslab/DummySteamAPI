#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

VA11_DIR="${HOME}/.steam/steam/steamapps/common/VA-11 HALL-A"
VA11_BIN32="${VA11_DIR}/runner"
VA11_LIB32="${VA11_DIR}/lib"

# Required by DSA
export SteamAppId="447530"
export SteamGameId="447530"
export DSA_ORIG_STEAM_API_LIB="${VA11_LIB32}/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching VA-11 HALL-A with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${VA11_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${VA11_BIN32}"
