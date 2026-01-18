#!/bin/bash

cd ./libs/


cd ./B-luga
./scripts/create-tar.sh

cd ..

cd ./B-luga-graphics
./scripts/create-tar.sh

cd ..

cd ./B-luga-physics
./scripts/create-tar.sh

cd ..

cd ./B-luga-steam
./scripts/create-tar.sh

cd ..

cd ..
