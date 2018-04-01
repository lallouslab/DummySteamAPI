#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

PTL_DIR="${HOME}/.steam/steam/steamapps/common/Portal"
PTL_BIN32="${PTL_DIR}/hl2_linux"
PTL_LIB32="${PTL_DIR}/bin"

# Required by DSA
export SteamAppId="400"
export SteamGameId="400"
export DSA_ORIG_STEAM_API_LIB="${PTL_LIB32}/libsteam_api.so"

# Avoid crash with dbus
export DBUS_FATAL_WARNINGS=0

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Portal with DummySteamAPI...\033[0m"

cd "${PTL_DIR}"

export LD_LIBRARY_PATH="/usr/lib/i386-linux-gnu:${PTL_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${PTL_BIN32}" -game portal
