# Royal Kludge R65 (ANSI) Firmware

* **Keyboard Maintainer:** [sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn)
* **Supported Hardware:** Royal Kludge R65 (ANSI)
* **Hardware Availability:** [Royal Kludge's official website](http://www.rkgaming.com)

### Read this [guide](https://github.com/irfanjmdn/r65/tree/vialrgb#guide) before building the firmware. 

## Firmware Options

1. **Default:**  
   `make rk/r65:default`  
   (No Vial functionality)

2. **VialRGB** [⚠ Known Issues](https://github.com/irfanjmdn/r65/tree/vialrgb#known-issues)
   `make rk/r65 -kb rk/r65 -km vialrgb`
   (Vial with SignalRGB functionality)

3. **VialRGB with SOCD** [⚠ Known Issues](https://github.com/irfanjmdn/r65/tree/vialrgb#known-issues)
   `make rk/r65 -kb rk/r65 -km vialrgb-socd`
   (Vial with SignalRGB & Snap Tap/SOCD functionality)

4. **Vial only:**  
   `make rk/r65 -km vial`  
   (Includes Vial support without SignalRGB)

5. **Vial with SOCD:**  
   `make rk/r65 -km vial-socd`  
   (Vial with Snap Tap/SOCD functionality)