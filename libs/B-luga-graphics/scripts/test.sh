#!/bin/bash

set -ex

cd test

cmake -S . -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5

cmake --build build

./build/test-ecs
