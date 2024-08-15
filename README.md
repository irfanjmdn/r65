# Royal Kludge R65 Files

## Overview

This repository contains essential files for the Royal Kludge R65 (ANSI, WIRED-ONLY). For other Royal Kludge keyboard variants or all QMK-supported models, visit sdk66’s [QMK Firmware Repository](https://github.com/hangshengkeji/qmk_firmware/tree/master/keyboards/rk).

When I bought this keyboard, I was told it was open source, but finding the necessary files was challenging. After weeks of emails and follow-ups, I finally received the QMK firmware for the Royal Kludge R65. Special thanks to [sdk66](https://github.com/sdk66) for sharing these files!

Included here are all the files for the R65: firmware, keymaps, VIA json, PCB diagram, and an additional SnapTap/SOCD mod that I've added.


## Guide

### Building the Firmware

1. **Install QMK MSYS**  
   Download and install [QMK MSYS](https://msys.qmk.fm).

2. **Set Up QMK MSYS**  
   Open QMK MSYS and run the command:  
   ```bash
   qmk setup
   ```

3. **Add Keyboard Files**  
   Download and move the `rk/r65` folder into `qmk_firmware/keyboards/`.

4. **Compile the Firmware**  
   Run the following command in QMK MSYS:  
   ```bash
   qmk compile -kb rk/r65 -km via
   ```  
   (Available options: default/via/via-socd).

5. **Locate the Firmware File**  
   Find the compiled `.bin` or `.hex` file in the root of the `qmk_firmware` folder.

### Installing the Firmware

1. **Install QMK Toolbox**  
   Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Load the Firmware File**  
   Open QMK Toolbox and load the `.bin` or `.hex` file you compiled.

3. **Enter Bootloader Mode**  
   Reset the keyboard into bootloader mode.

4. **Flash the Firmware**  
   Click 'Flash', then 'Exit DFU' once the flashing process is complete.

### Entering Bootloader Mode

- **Option 1**: Hold the Reset switch on the PCB while connecting the USB cable.
- **Option 2**: Hold the Escape key while connecting the USB cable (this will also erase settings).
- **Option 3**: Press `Fn+Shift+Tab` if using the default firmware.
- **Option 4**: Press `Fn+Tab` if you’ve flashed the keyboard with a QMK keymap.
