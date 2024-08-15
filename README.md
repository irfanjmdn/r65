# Royal Kludge R65
Files for the Royal Kludge R65 (ANSI, WIRED-ONLY)

### Building the Firmware:

1. Install [QMK MSYS](https://msys.qmk.fm).
2. Open QMK MSYS and run `qmk setup`.
3. Download and move the `rk/r65` folder into `qmk_firmware/keyboards/`.
4. In QMK MSYS, run: `qmk compile -kb rk/r65 -km via` (Options: default/via/via-socd).
5. Find the `.bin`/`.hex` file in the root `qmk_firmware` folder.

### Installing the Firmware:

1. Install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).
2. Open QMK Toolbox and load the `.bin`/`.hex` file.
3. Reset the keyboard into bootloader mode.
4. Click 'Flash', then 'Exit DFU' when done.

### Entering Bootloader Mode:

- Hold the Reset switch on the PCB while connecting the USB cable.
- Hold the Escape key while connecting the USB cable (also erases settings).
- Press Fn+Shift+Tab if using default firmware.
- Press Fn+Tab if already flashed with QMK keymap.
