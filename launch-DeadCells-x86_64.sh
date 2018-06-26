#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

DC_DIR="${HOME}/.steam/steam/steamapps/common/Dead Cells"
DC_BIN64="${DC_DIR}/deadcells"
DC_LIB64="${DC_DIR}"

# Required by DSA
export SteamAppId="588650"
export SteamGameId="588650"
export DSA_ORIG_STEAM_API_LIB="${DC_LIB64}/libsteam_api.so"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Dead Cells with DummySteamAPI...\033[0m"

cd "${DC_DIR}"

export LD_LIBRARY_PATH="${DC_LIB64}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${DC_BIN64}"
