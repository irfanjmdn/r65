# Royal Kludge R65 (ANSI) Firmware

* **Keyboard Maintainer:** [sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn)
* **Supported Hardware:** Royal Kludge R65 (ANSI)
* **Hardware Availability:** [Royal Kludge's official website](http://www.rkgaming.com)

### Read this [guide](https://github.com/irfanjmdn/royalkludge-r65#guide) before building the firmware. 

## Firmware Options

1. **SignalRGB**  
   `qmk compile -kb rk/r65 -km srgb`  
   (Plain SignalRGB, without added features)

1. **SignalRGB & SOCD**  
   `qmk compile -kb rk/r65 -km srgb-socd`  
   (SignalRGB with SOCD functionality, recommended for gamers)

2. **`[NOT RECOMMENDED]` SRGB + VIA**  
   `qmk compile -kb rk/r65 -km srgb-via`
   (Includes SignalRGB + VIA support)

3. **`[NOT RECOMMENDED]` SRGB + VIA + SOCD**  
   `qmk compile -kb rk/r65 -km via-socd`  
   (Includes SignalRGB + VIA + SOCD support)
