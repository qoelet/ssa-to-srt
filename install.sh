#!/usr/bin/env bash

set -e
set -o pipefail

gcc run.c ssa-to-srt.c -o ssa-to-srt
install -t $HOME/.local/bin/ ssa-to-srt
rm ssa-to-srt
echo "ssa-to-srt is installed to ~/.local/bin"
