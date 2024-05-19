#!/bin/bash
# Builds Wacom Loader

INSTALL_PATH="wacom_loader"

gcc wacom_loader.c -o wacom_loader

if [[ "$1" == "install" ]]; then
	sudo cp wacom_loader /usr/local/bin
	INSTALL_PATH="/usr/local/bin/wacom_loader"
fi

sudo chown root:root $INSTALL_PATH
sudo chmod 4755 $INSTALL_PATH
