#!/bin/bash

set -ex

cd test

cmake -S . -B build

./build/test-ecs
