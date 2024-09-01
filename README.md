# Royal Kludge R65 with SignalRGB

![Royal Kludge R65 Keyboard](srgb-r65.png)

### Branches

| Branch        | Features              | Description                                             | Link                                                                                   |
|---------------|-----------------------|---------------------------------------------------------|----------------------------------------------------------------------------------------|
| Master   | QMK, VIA      | The main branch *(with optional Snap Tap feature[^1][^2])*.           | [View on Github](https://github.com/irfanjmdn/r65/tree/master)                         |
| SignalRGB | QMK, VIA + SignalRGB | Stable branch with VIA and SignalRGB support.     | **You are here**                      |
| VialRGB       | QMK, VIA, Vial + SignalRGB      | Experimental branch with Vial and SignalRGB.[^3]    | [View on GitHub](https://github.com/irfanjmdn/r65/tree/vialrgb)                                                      |
---

> [!IMPORTANT] 
> This branch only contains files for the **wired ANSI-layout** version of the Royal Kludge R65.
> Please review the full [disclaimer](DISCLAIMER.md) before using the files provided in this repository.

- ⌨ 🔌 For the **ISO layout** or other Royal Kludge keyboard variants, visit sdk66’s [QMK Firmware Repo](https://github.com/hangshengkeji/qmk_firmware/tree/master/keyboards/rk).
- ⌨ 🔨 For a more **customized** version of the firmware for the R65, visit iamdanielv's [R65 Custom Firmware Repo](https://github.com/iamdanielv/kb_rk_r65).
- ⌨ ⚡ For the **QMK/VIA only** version of this firmware, visit the [R65 QMK&VIA Repo](https://github.com/irfanjmdn/r65).

To developers who would want to contribute, any and all help would be greatly appreciated! Feel free to submit improvements, fixes, or suggestions.

> [!WARNING]
> ## Known Issues
> ### SignalRGB + VIA
> SignalRGB and VIA cannot run simultaneously. To avoid conflicts:
> - Close VIA or its browser tab before running SignalRGB.
> - Alternatively, close SignalRGB before using VIA.
> The issue arises because both use the `raw_hid_receive` solution, causing interference.

---
## Firmware Options

> [!TIP]
> Make sure to read the [guide](https://github.com/irfanjmdn/r65/tree/signalrgb#guide) before proceeding.

| **Option**                  | **Command**              | **SignalRGB** | **VIA** | **SOCD[^1]** | **Download** |
|-----------------------------|--------------------------|---------------|---------|-------------------|--------------|
| **SignalRGB Only**          | `make rk/r65:srgb`       | ✅            | ⬜      | ⬜                | [⏬Download](https://github.com/irfanjmdn/r65/blob/signalrgb/%5BFW0.1.0%20RKR65%5D%20SRGB%20only.hex) |
| **SignalRGB with SOCD**     | `make rk/r65:srgb-socd`  | ✅            | ⬜      | ✅                | [⏬Download](https://github.com/irfanjmdn/r65/blob/signalrgb/%5BFW0.1.0%20RKR65%5D%20SRGB%20with%20SOCD.hex) |
| **SignalRGB with VIA**      | `make rk/r65:srgb-via`   | ✅            | ✅      | ⬜                | [⏬Download](https://github.com/irfanjmdn/r65/blob/signalrgb/%5BFW0.1.0%20RKR65%5D%20SRGB%20with%20VIA.hex) |
| **SignalRGB with VIA & SOCD** | `make rk/r65:srgb-via-socd` | ✅      | ✅      | ✅                | [⏬Download](https://github.com/irfanjmdn/r65/blob/signalrgb/%5BFW0.1.0%20RKR65%5D%20SRGB%20with%20VIA%20%26%20SOCD.hex) |

***
## Guide

### > 🏗 Building the Firmware
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
   [Download this repository](https://minhaskamal.github.io/DownGit/#/home?url=https://github.com/irfanjmdn/r65/tree/signalrgb/rk/r65) and move the `rk/r65` folder into your `QMK/keyboards/` folder.

4. **Compile the Firmware**  
   Run the following command in QMK MSYS:  
   ```bash
   make rk/r65:srgb
   ```  
   (Available options: srgb/srgb-socd/srgb-via/srgb-via-socd).

5. **Locate the Firmware File**  
   Find the compiled `.bin` or `.hex` file in the root of the `QMK` folder.

### > ⚡ Flashing/Installing the Firmware

1. **Install QMK Toolbox**  
   Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).

2. **Load the Firmware File**  
   Open QMK Toolbox and load the `.bin` or `.hex` file.

3. **Enter Bootloader Mode**  
   Reset the keyboard into bootloader mode.

4. **Flash the Firmware**  
   Click 'Flash', then 'Exit DFU' once the flashing process is complete.

### > ⚒ Setting up SignalRGB

1. **Install SignalRGB**  
   Download and install the [SignalRGB software](https://signalrgb.com/download/).

2. **Move Plugin File**  
   After installing, copy [`SignalRGB-for-RK-R65.js`](SignalRGB%20for%20RK%20R65.js) to `%userprofile%/Documents/WhirlwindFX/plugins`.

3. **Restart SignalRGB**  
   Restart SignalRGB and enjoy.

### > 🔓 Entering Bootloader Mode

- **Option 1**: Hold the Reset switch on the PCB while connecting the USB cable.
- **Option 2**: Hold the Escape key while connecting the USB cable (this will also erase settings).
- **Option 3**: Press `Fn+Shift+Esc`.

[^1]: Snap Tap/SOCD is a feature that prioritizes the latest input between two selected keys without the need to release the previous one, allowing for faster directional changes. This can enhance gameplay in FPS games by enabling quicker counter-strafing and more responsive movements. 
[^2]: The Snap Tap/SOCD feature is available in every branch of the repository.
[^3]: You should use Vial if you have experience with QMK/VIA. If you are new to modifying keyboards, I recommend you [use VIA](https://usevia.app) instead. 
