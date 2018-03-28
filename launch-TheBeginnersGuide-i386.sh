#!/bin/bash

set -e

DSA_DIR=$(realpath $(dirname "$0"))

TBG_DIR="${HOME}/.steam/steam/steamapps/common/The Beginners Guide"
TBG_BIN32="${TBG_DIR}/beginnersguide.bin"
TBG_LIB32="${TBG_DIR}/bin"

# Required by DSA
export SteamAppId="303210"
export SteamGameId="303210"
export DSA_ORIG_STEAM_API_LIB="${TBG_LIB32}/libsteam_api.so"

# Avoid crash with dbus
export DBUS_FATAL_WARNINGS=0

export CFLAGS="-m32"
export LDFLAGS="-m32"

. "${DSA_DIR}/common.sh"
. "${DSA_DIR}/config.sh"

echo -e "\033[1;92mLaunching The Beginners Guide with DummySteamAPI...\033[0m"

cd "${TBG_DIR}"

export LD_LIBRARY_PATH="/usr/lib/i386-linux-gnu:${TBG_LIB32}:${LD_LIBRARY_PATH}"
export LD_PRELOAD="${DSA_DIR}/bin/libsteam_api.so:${LD_PRELOAD}"

exec "${TBG_BIN32}" -game beginnersguide
