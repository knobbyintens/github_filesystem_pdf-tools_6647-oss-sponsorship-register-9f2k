#!/usr/bin/env bash
set -euo pipefail

PORT="${1:-/dev/ttyUSB0}"
SKETCH="firmware/word_clock.ino"

arduino-cli compile --fqbn esp32:esp32:esp32s2 "$SKETCH"
arduino-cli upload -p "$PORT" --fqbn esp32:esp32:esp32s2 "$SKETCH"
echo "flashed word clock firmware to $PORT"
