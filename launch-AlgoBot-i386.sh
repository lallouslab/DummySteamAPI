#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

AB_DIR="${HOME}/.steam/steam/steamapps/common/AlgoBot"
AB_BIN32="${AB_DIR}/Algobot.x86"
AB_LIB32="${AB_DIR}"

# Required by DSA
export SteamAppId="286300"
export SteamGameId="286300"
export DSA_ORIG_STEAM_API_LIB="${AB_LIB32}/Algobot_Data/Plugins/x86/libsteam_api.so"

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Algo Bot with DummySteamAPI...\033[0m"

export LD_LIBRARY_PATH="${AB_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${AB_BIN32}"
