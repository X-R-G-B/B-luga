#!/bin/bash

cd ./libs

cd ./B-luga
echo "BLUGA"
./scripts/test.sh

cd ..

cd ./B-luga-graphics
echo "BLUGA-GRAPHICS"
./scripts/test.sh

cd ..

cd ./B-luga-physics
echo "BLUGA-PHYSICS"
./scripts/test.sh
