#!/bin/sh

CC=cc
CFLAGS="-Wall -Wextra -O2"
BIN="al"

usage() {
	echo "Usage: $0 [build clean]" 
}

build() {
	$CC $CFLAGS al.c -o $BIN
}

clean() {
	rm $BIN
}

case "$1" in
	build) build ;;
	clean) clean ;;
	*) usage && exit 1 ;;
esac
