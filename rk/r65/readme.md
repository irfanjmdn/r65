# Royal Kludge R65 (ANSI) Firmware

* **Keyboard Maintainer:** [sdk66](https://github.com/sdk66)
* **Supported Hardware:** Royal Kludge R65 (ANSI)
* **Hardware Availability:** [Royal Kludge's official website](http://www.rkgaming.com)

### Read this [guide](https://github.com/irfanjmdn/r65/tree/signalrgb#guide) before building the firmware. 

## Firmware Options

1. **SignalRGB only:**  
   `make rk/r65:srgb`  
   (SignalRGB functionality only)

2. **Incl. SOCD [Fn+V to toggle]:** 
   `make rk/r65:srgb-socd`  
   (SignalRGB with Snap Tap/SOCD)

3. **Incl. VIA:**  
   `make rk/r65:srgb-via`  
   (SignalRGB with VIA functionality)

4. **Incl. VIA & SOCD:**  
   `make rk/r65:srgb-via-socd`  
   (SignalRGB with VIA and SOCD)