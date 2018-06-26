#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TME_DIR="${HOME}/.steam/steam/steamapps/common/TellMeEverything"
TME_BIN32="${TME_DIR}/TellMeLinux.x86"
TME_LIB32="${TME_DIR}"

# Required by DSA
export SteamAppId="846820"
export SteamGameId="846820"
export DSA_ORIG_STEAM_API_LIB="${TME_LIB32}/TellMeLinux_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Tell Me Everything with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${TME_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TME_BIN32}"
