#!/bin/bash

mkdir b-luga-steam

mv ./CMakeLists.txt ./b-luga-steam
mv ./README.md ./b-luga-steam
mv ./deps/ ./b-luga-steam
mv ./include/ ./b-luga-steam
mv ./src ./b-luga-steam

tar -cvf b-luga-steam.tar b-luga-steam
