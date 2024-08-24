# Royal Kludge R65 with SignalRGB

![Royal Kludge R65 Keyboard](srgb-r65.png)

**⚡ SignalRGB version | [QMK+VIA version](https://github.com/irfanjmdn/r65/tree/master)**
---

Here you'll find everything you need for the RK65:

- Firmware
- Keymaps
- SignalRGB Plugin
- PCB Diagram
- Snap Tap/SOCD Mod

## DISCLAIMER

**This branch only contains files for the WIRED version of the Royal Kludge R65 (ANSI layout). For the ISO layout or other Royal Kludge keyboard variants, visit sdk66’s [QMK Firmware Repository](https://github.com/hangshengkeji/qmk_firmware/tree/master/keyboards/rk).**

To developers who would want to contribute, any and all help would be greatly appreciated! Feel free to submit improvements, fixes, or suggestions.

---

## Known Issues

### SignalRGB + VIA

Please note that SignalRGB and VIA can not run simultaneously. To avoid conflicts:

- Close VIA or its browser tab before running SignalRGB.
- Alternatively, close SignalRGB before using VIA.

The issue arises because both use the `raw_hid_receive` solution, causing interference.

### Caps Lock Indicator

- The Caps Lock indicator light doesn't turn on. 

This issue is very likely fixable, but I’m not experienced enough to handle it.

---
## Guide

### Building the Firmware
For more information, visit [SignalRGB/building-firmware-from-source](https://docs.signalrgb.com/qmk/building-firmware-from-source).

1. **Install QMK MSYS**  
   Download and install [QMK MSYS](https://msys.qmk.fm).

2. **Set Up QMK MSYS**  
   Open QMK MSYS and run these commands:  
   ```bash
   mkdir SignalRGB
   cd SignalRGB
   git clone https://github.com/SRGBmods/QMK.git
   cd QMK
   ```
   A folder will be installed at `C:/Users/%USERNAME%/SignalRGB/QMK`.

3. **Add Keyboard Files**  
   Download this repository and move the `rk/r65` folder into your `QMK/keyboards/` folder.

4. **Compile the Firmware**  
   Run the following command in QMK MSYS:  
   ```bash
   make rk/r65:srgb
   ```  
   (Available options: srgb/srgb-socd/srgb-via/srgb-via-socd).

5. **Locate the Firmware File**  
   Find the compiled `.bin` or `.hex` file in the root of the `QMK` folder.

### Flashing/Installing the Firmware

1. **Install QMK Toolbox**  
   Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Load the Firmware File**  
   Open QMK Toolbox and load the `.bin` or `.hex` file.

3. **Enter Bootloader Mode**  
   Reset the keyboard into bootloader mode.

4. **Flash the Firmware**  
   Click 'Flash', then 'Exit DFU' once the flashing process is complete.

### Setting up SignalRGB

1. **Install SignalRGB**  
   Download and install the [SignalRGB software](https://signalrgb.com/download/).

2. **Move Plugin File**  
   After installing, copy [`SignalRGB-for-RK-R65.js`](SignalRGB%20for%20RK%20R65.js) to `%userprofile%/Documents/WhirlwindFX/plugins`.

3. **Restart SignalRGB**  
   Restart SignalRGB and enjoy.

### Entering Bootloader Mode

- **Option 1**: Hold the Reset switch on the PCB while connecting the USB cable.
- **Option 2**: Hold the Escape key while connecting the USB cable (this will also erase settings).
- **Option 3**: Press `Fn+Shift+Esc`.

