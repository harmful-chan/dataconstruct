#!/bin/sh

echo "#include \"${1/_link.c/_def.h}\"" > ./includes/config.h
make test TEST_TARGET=$1 DEFINES=$2
./test
rm -rf ./test


