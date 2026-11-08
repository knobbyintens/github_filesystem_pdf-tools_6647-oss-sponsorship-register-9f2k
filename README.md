# Word Clock No. 7

Firmware, hardware sources and fabrication data for the Word Clock No. 7.

The build uses an ESP32-S2 with a DS3231 real-time clock and four WS2812B
strips. `firmware/word_clock.ino` owns the display timing; the carrier board in
`hardware/` regulates the 5 V rail and exposes the UART header.

## Contents

- `firmware/word_clock.ino` — display driver, RTC handling and configuration page
- `hardware/word_clock.kicad_sch` — KiCad schematic for the carrier board
- `hardware/bom.csv` — bill of materials with supplier part numbers
- `scripts/flash.sh` — flashing helper used on the workshop bench
- `docs/assembly.md` — mechanical assembly and calibration notes
