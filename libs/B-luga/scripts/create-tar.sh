#!/bin/bash

mkdir b-luga

mv ./CMakeLists.txt ./b-luga
mv ./README.md ./b-luga
mv ./deps/ ./b-luga
mv ./include/ ./b-luga
mv ./src ./b-luga

tar -cvf b-luga.tar b-luga
