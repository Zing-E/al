#!/bin/sh

BIN="al"

build() {
	go build al.go
}

clean() {
	rm $BIN
}

usage() {
	echo "Usage: $0 [build]"
}

case "$1" in
	build) build ;;
	clean) clean ;;
	*) usage && exit 1 ;;
esac
