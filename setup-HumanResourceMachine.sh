#!/bin/bash

set -e

HRM_LIB64="${HOME}/.steam/steam/steamapps/common/Human Resource Machine/lib64"

if [ ! -f "Makefile.conf" ]; then
	make defconfig
fi

make

if [ -e "${HRM_LIB64}/libsteam_api.so" -a ! -L  "${HRM_LIB64}/libsteam_api.so" ]; then
	mv "${HRM_LIB64}/libsteam_api.so" "${HRM_LIB64}/libsteam_api.so.bak"
fi

ln -sf "$(realpath out/libsteam_api.so)" "${HRM_LIB64}/libsteam_api.so"

echo -e "\033[1;92mDummy libsteam_api.so successfully installed for Human Resource Machine!\033[0m"
