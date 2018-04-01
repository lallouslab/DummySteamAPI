#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

PT2_DIR="${HOME}/.steam/steam/steamapps/common/Portal 2"
PT2_BIN32="${PT2_DIR}/portal2_linux"
PT2_LIB32="${PT2_DIR}/bin"

# Required by DSA
export SteamAppId="620"
export SteamGameId="620"
export DSA_ORIG_STEAM_API_LIB="${PT2_LIB32}/libsteam_api.so"

# Avoid crash with dbus
export DBUS_FATAL_WARNINGS=0

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching Portal 2 with DummySteamAPI...\033[0m"

cd "${PT2_DIR}"

export LD_LIBRARY_PATH="/usr/lib/i386-linux-gnu:${PT2_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${PT2_BIN32}" -game portal2
