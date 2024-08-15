# Royal Kludge R65 (ANSI) Firmware

* **Keyboard Maintainer:** [sdk66](https://github.com/sdk66)
* **Supported Hardware:** Royal Kludge R65 (ANSI)
* **Hardware Availability:** [Royal Kludge's official website](http://www.rkgaming.com)

**Built & tested on Windows.** For MacOS/Linux users, refer to the official [QMK docs](https://docs.qmk.fm/newbs_getting_started).

## Firmware Options

1. **Default:**  
   `qmk compile -kb rk/r65 -km default`  
   (No VIA functionality)

2. **VIA Enabled:**  
   `qmk compile -kb rk/r65 -km via`  
   (Includes VIA support)

3. **VIA & SOCD:**  
   `qmk compile -kb rk/r65 -km via-socd`  
   (Includes VIA and SOCD functionality, similar to Razer's SnapTap and Wooting's SOCD)
