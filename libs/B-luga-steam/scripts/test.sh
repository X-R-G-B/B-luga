#!/bin/bash

set -ex

cd test

cmake -S . -B build

cmake --build build

./build/test-ecs
