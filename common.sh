#!/bin/bash

if [ -n "${SILENT}" -a "${SILENT}" != "0" ]; then
	exec >/dev/null 2>&1
fi 
