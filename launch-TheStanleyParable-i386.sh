#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TSP_DIR="${HOME}/.steam/steam/steamapps/common/The Stanley Parable"
TSP_BIN32="${TSP_DIR}/stanley_linux"
TSP_LIB32="${TSP_DIR}/bin"

# Required by DSA
export SteamAppId="221910"
export SteamGameId="221910"
export DSA_ORIG_STEAM_API_LIB="${TSP_LIB32}/libsteam_api.so"

# Avoid crash with dbus
export DBUS_FATAL_WARNINGS=0

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching The Stanley Parable with DummySteamAPI...\033[0m"

cd "${TSP_DIR}"

export LD_LIBRARY_PATH="/usr/lib/i386-linux-gnu:${TSP_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TSP_BIN32}" -game thestanleyparable
