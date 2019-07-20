#!/usr/bin/env bash

set -e
set -o pipefail

gcc test-ssa-to-srt.c ssa-to-srt.c -lrt -lm -o test-ssa-to-srt
./test-ssa-to-srt
rm test-ssa-to-srt
