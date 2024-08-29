// @sdk66, @iamdanielv & @irfanjmdn

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,       // 0
    _BASE_FN,    // 1
    _MAC,        // 2
    _MAC_FN,     // 3
    _ALT_A,      // 4
    _ALT_A_FN,   // 5
	_ALT_B,		 // 6
	_ALT_B_FN,	 // 7
	_BOOT		 // 8
};

enum custom_keycodes {
    SWITCH_FN = SAFE_RANGE
};

bool fn_mode = false;

const uint16_t number_to_function[] PROGMEM = {
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SWITCH_FN) {
        if (record->event.pressed) {
            fn_mode = !fn_mode;
        }
        return false;
    }

    if (fn_mode) {
        if ( ( keycode >= KC_1 && keycode <= KC_0 ) || keycode == KC_MINS || keycode == KC_EQL ) {
            uint8_t index = keycode - KC_1;
			
            if (keycode == KC_MINS) { index = 10;}
            else if (keycode == KC_EQL) { index = 11;}

            if (record->event.pressed) {
                register_code(pgm_read_word(&number_to_function[index]));
            } else {
                unregister_code(pgm_read_word(&number_to_function[index]));
            }
            return false;
        }
    }

    return true;
}

void housekeeping_task_user(void) {
    if (IS_LAYER_ON(_MAC) || IS_LAYER_ON(_MAC_FN)) {
      gpio_write_pin_low(LED_MAC_PIN);
    } else {
      gpio_write_pin_high(LED_MAC_PIN);
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
 KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
 ),

 [_BASE_FN] = LAYOUT(
 KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
 _______, TO(0), TO(2), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
 SWITCH_FN, GU_TOGG, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
 ),
		
 [_MAC] = LAYOUT(
 KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(3), KC_LEFT, KC_DOWN, KC_RGHT
 ),
 
 [_MAC_FN] = LAYOUT(
 KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
 _______, TO(0), TO(2), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
 SWITCH_FN, _______, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
 ),
 
 [_ALT_A] = LAYOUT(
 KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(5), KC_LEFT, KC_DOWN, KC_RGHT
 ),
 
 [_ALT_A_FN] = LAYOUT(
 KC_GRV, KC_MYCM, KC_HOME, KC_MAIL, KC_CALC, KC_SLCT, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
 _______, TO(4), TO(6), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
 SWITCH_FN, GU_TOGG, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
 ),
 
 [_ALT_B] = LAYOUT(
 KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
 KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP, 
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(7), KC_LEFT, KC_DOWN, KC_RGHT
 ),
 
 [_ALT_B_FN] = LAYOUT(
 KC_GRV, KC_BRMD, KC_BRMU, KC_F3, KC_F4, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(8), _______, KC_HOME, KC_SCRL, RGB_MOD, KC_INS,
 _______, TO(4), TO(6), _______, _______, _______, _______, _______, _______, MO(8), _______, KC_PSCR, _______, KC_PAUSE,
 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, RGB_HUI, _______, _______, MO(8), RGB_VAI, KC_END,
 SWITCH_FN, _______, _______, EE_CLR, _______, _______, RGB_SPD, RGB_VAD, RGB_SPI
 ),
 
 [_BOOT] = LAYOUT(
 QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_BASE_FN]  = {ENCODER_CCW_CW(_______, _______)},
    [_MAC]      = {ENCODER_CCW_CW(_______, _______)},
    [_MAC_FN]   = {ENCODER_CCW_CW(_______, _______)},
    [_ALT_A]    = {ENCODER_CCW_CW(_______, _______)},
	[_ALT_A_FN] = {ENCODER_CCW_CW(_______, _______)},
	[_ALT_B]    = {ENCODER_CCW_CW(_______, _______)},
	[_ALT_B_FN] = {ENCODER_CCW_CW(_______, _______)},
    [_BOOT]     = {ENCODER_CCW_CW(_______, _______)}
};
#endif