# ⚡ Royal Kludge R65 VIA

![Royal Kludge R65 Keyboard](via-r65.png)

### Select your branch:

| Branch        | Features              | Description                                             | Link                                                                                   |
|---------------|-----------------------|---------------------------------------------------------|----------------------------------------------------------------------------------------|
| 🔨 Master   | QMK, VIA      | The main branch *(with optional Snap Tap feature[^1][^2])*.           | **You are here**                         |
| 💡 SignalRGB | QMK, VIA + SignalRGB | Stable branch with VIA and SignalRGB support.     | [Go to branch](https://github.com/irfanjmdn/r65/tree/signalrgb)                      |
| 🧪 VialRGB       | QMK, VIA, Vial + SignalRGB      | Experimental branch with Vial and SignalRGB.[^3]    | [Go to branch](https://github.com/irfanjmdn/r65/tree/vialrgb)                                                      |

---

> [!IMPORTANT] 
> This branch only contains files for the **wired ANSI-layout** version of the Royal Kludge R65.
> Please review the full [disclaimer](DISCLAIMER.md) before using the files provided in this repository.

- ⌨ 🔌 For the **ISO layout** or other Royal Kludge keyboard variants, visit sdk66’s [QMK Firmware Repo](https://github.com/hangshengkeji/qmk_firmware/tree/master/keyboards/rk).
- ⌨ 🛠 For a more **customized** version of the firmware for the R65, visit iamdanielv's [R65 Custom Firmware Repo](https://github.com/iamdanielv/kb_rk_r65).

To developers who would want to contribute, any and all help would be greatly appreciated! Feel free to submit improvements, fixes, or suggestions.

---

## Overview

The Royal Kludge RKR65 is a 66-key RGB backlit keyboard with Chartreuse, Brown, or Blue switches. It offers a gasket structure for a soft typing experience, knob adjustment, ergonomic design, and hot-swappable keys.

When I bought this keyboard, I was told it was open source by the seller, but they never gave out the files on their website. After weeks of emails and follow-ups, I finally received the QMK firmware for the Royal Kludge R65. 

> Special thanks to @sdk66 for sharing the initial firmware files, and @iamdanielv for fixing a major portion of the code!

## Known Issues

None

---

## Guide

### > 🏗 Building the Firmware

1. **Install QMK MSYS**  
   Download and install [QMK MSYS](https://msys.qmk.fm).

2. **Set Up QMK MSYS**  
   Open QMK MSYS and run the command:  
   ```bash
   qmk setup
   ```
   A folder will be installed at `C:/Users/%USERNAME%/qmk_firmware`.

3. **Add Keyboard Files**  
   [Download this repository](https://minhaskamal.github.io/DownGit/#/home?url=https://github.com/irfanjmdn/r65/tree/master/rk/r65) and move the `rk/r65` folder into your `qmk_firmware/keyboards/` folder.

4. **Compile the Firmware**  
   Run the following command in QMK MSYS:  
   ```bash
   qmk compile -kb rk/r65 -km via
   ```  
   (Available options: default/via/via-socd).

5. **Locate the Firmware File**  
   Find the compiled `.bin` or `.hex` file in the root of the `qmk_firmware` folder.

### > ⚡ Flashing/Installing the Firmware

1. **Install QMK Toolbox**  
   Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Load the Firmware File**  
   Open QMK Toolbox and load the `.bin` or `.hex` file.

3. **Enter Bootloader Mode**  
   Reset the keyboard into bootloader mode.

4. **Flash the Firmware**  
   Click 'Flash', then 'Exit DFU' once the flashing process is complete.

### > 🔓 Entering Bootloader Mode

- **Option 1**: Hold the Reset switch on the PCB while connecting the USB cable.
- **Option 2**: Hold the Escape key while connecting the USB cable (this will also erase settings).
- **Option 3**: Press `Fn+Shift+Esc`.

[^1]: Snap Tap/SOCD is a feature that prioritizes the latest input between two selected keys without the need to release the previous one, allowing for faster directional changes. This can enhance gameplay in FPS games by enabling quicker counter-strafing and more responsive movements. 
[^2]: The Snap Tap/SOCD feature is available in every branch of the repository.
[^3]: You should use Vial if you have experience with QMK/VIA. If you are new to modifying keyboards, I recommend you [use VIA](https://usevia.app) instead. 
