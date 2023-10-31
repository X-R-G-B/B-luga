#!/bin/bash

ERRORS=""

cd ./libs

cd ./B-luga
echo "BLUGA"
./scripts/test.sh
if [[ $? -ne 0 ]]; then
    ERRORS="$ERRORS BLUGA"
    echo "ERRORS"
fi

cd ..

cd ./B-luga-graphics
echo "BLUGA-GRAPHICS"
./scripts/test.sh
if [[ $? -ne 0 ]]; then
    ERRORS="$ERRORS BLUGA-GRAPHICS"
    echo "ERRORS"
fi

cd ..

cd ./B-luga-physics
echo "BLUGA-PHYSICS"
./scripts/test.sh
if [[ $? -ne 0 ]]; then
    ERRORS="$ERRORS BLUGA-PHYSICS"
    echo "ERRORS"
fi

echo "$ERRORS"
if [[ "$ERRORS" != "" ]]; then
    exit 1
fi
