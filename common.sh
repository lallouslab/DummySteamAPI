#!/bin/bash

if [ ! -f "${DSA_DIR}/config.sh" ]; then
	cp "${DSA_DIR}/config.sh.sample" "${DSA_DIR}/config.sh"
fi

if [ ! -f "${DSA_DIR}/Makefile.conf" ]; then
	make -C "${DSA_DIR}" defconfig
fi

make -C "${DSA_DIR}"
