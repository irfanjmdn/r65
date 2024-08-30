# Royal Kludge R65 (ANSI) Firmware

* **Keyboard Maintainer:** [sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn)
* **Supported Hardware:** Royal Kludge R65 (ANSI)
* **Hardware Availability:** [Royal Kludge's official website](http://www.rkgaming.com)

### Read this [guide](https://github.com/irfanjmdn/r65#guide) before building the firmware. 

## Firmware Options

1. **Default:**  
   `qmk compile -kb rk/r65 -km default`  
   (No VIA functionality)

2. **VIA Enabled:**  
   `qmk compile -kb rk/r65 -km via`  
   (Includes VIA support)

3. **VIA with SOCD [Fn+V to toggle]:**  
   `qmk compile -kb rk/r65 -km via-socd`  
   (Includes VIA and SOCD functionality, similar to Razer's Snap Tap and Wooting's SOCD)
