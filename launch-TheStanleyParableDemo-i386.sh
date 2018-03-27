#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TSPD_DIR="${HOME}/.steam/steam/steamapps/common/The Stanley Parable Demo"
TSPD_BIN32="${TSPD_DIR}/stanley_linux"
TSPD_LIB32="${TSPD_DIR}/bin"

# Required by DSA
export SteamAppId="247750"
export SteamGameId="247750"
export DSA_ORIG_STEAM_API_LIB="${TSPD_LIB32}/libsteam_api.so"

# Avoid crash with dbus
export DBUS_FATAL_WARNINGS=0

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching The Stanley Parable Demo with DummySteamAPI...\033[0m"

cd "${TSPD_DIR}"

export LD_LIBRARY_PATH="/usr/lib/i386-linux-gnu:${TSPD_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TSPD_BIN32}" -game thestanleyparabledemo
