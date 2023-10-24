#!/bin/pwsh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DNO_USE_CLANG_TIDY=true

cmake --build build -- /m
