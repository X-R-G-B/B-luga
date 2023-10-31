#!/bin/pwsh

cd ./libs

cd ./B-luga
echo "BLUGA"
./scripts/test.ps1

cd ..

cd ./B-luga-graphics
echo "BLUGA-GRAPHICS"
./scripts/test.ps1

cd ..

cd ./B-luga-physics
echo "BLUGA-PHYSICS"
./scripts/test.ps1
