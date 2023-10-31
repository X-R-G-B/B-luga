#!/bin/pwsh

cd test

cmake -S . -B build

cmake --build build

./build/Debug/test-ecs.exe
