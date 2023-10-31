#!/bin/bash

mkdir b-luga-physics

mv ./CMakeLists.txt ./b-luga-physics
mv ./README.md ./b-luga-physics
mv ./deps/ ./b-luga-physics
mv ./include/ ./b-luga-physics

tar -cvf b-luga-physics.tar b-luga-physics
