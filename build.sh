#!/bin/sh

CC=cc
CFLAGS="-Wall -Wextra -O2"
BIN="al"

build() {
	$CC $CFLAGS al.c -o $BIN
}

clean() {
	rm $BIN
}

usage() {
	echo "Usage: $0 [build clean]" 
}

case "$1" in
	build) build ;;
	clean) clean ;;
	*) usage && exit 1 ;;
esac
