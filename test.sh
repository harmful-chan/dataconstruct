#!/bin/sh


rm -rf ./test core.*
echo "#include \"${1/_link.c/_def.h}\"" > ./includes/config.h

make test TEST_TARGET=$1 DEFINES=$2
./test


