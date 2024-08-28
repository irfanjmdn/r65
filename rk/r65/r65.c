//#include "quantum.h"

#include QMK_KEYBOARD_H

#define LED_ENABLE_PIN A5

void keyboard_pre_init_kb(void) {
    gpio_set_pin_output(LED_ENABLE_PIN);
    gpio_write_pin_high(LED_ENABLE_PIN);

    gpio_set_pin_output(LED_WIN_LOCK_PIN);
    gpio_write_pin_high(LED_WIN_LOCK_PIN);

    gpio_set_pin_output(LED_MAC_PIN);
    gpio_write_pin_high(LED_MAC_PIN);

    keyboard_pre_init_user();
}

void housekeeping_task_kb(void){

    if(keymap_config.no_gui)
    {
        gpio_write_pin_low(LED_WIN_LOCK_PIN);
    } else {
        gpio_write_pin_high(LED_WIN_LOCK_PIN);
    }
}