#!/bin/bash

mkdir b-luga-graphics

mv ./CMakeLists.txt ./b-luga-graphics
mv ./README.md ./b-luga-graphics
mv ./deps/ ./b-luga-graphics
mv ./include/ ./b-luga-graphics
mv ./src/ ./b-luga-graphics

tar -cvf b-luga-graphics.tar b-luga-graphics
