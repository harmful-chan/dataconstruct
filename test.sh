#!/bin/sh

file=$1
shift

rm -rf ./test core.*
echo "#include \"${file/_link.c/_def.h}\"" > ./includes/config.h

make test TEST_TARGET=${file} DEFINES=$@
./test


