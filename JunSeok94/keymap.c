#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
#    include "oled.c"
#endif

#ifdef ENCODER_ENABLE
#    include "encoder.c"
#endif

enum custom_keycodes {
    KC_GCLEFT = SAFE_RANGE,
    KC_GCRGHT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GCLEFT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_LEFT);
            }
            break;  
        case KC_GCRGHT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_mods(mod_config(MOD_LGUI));
                register_code(KC_RGHT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_mods(mod_config(MOD_LGUI));
                unregister_code(KC_RGHT);
            }
            break;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, LCTL_T(KC_F2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, LALT_T(KC_F9), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, LSFT_T(KC_HANJ), KC_PSCR, LCTL_T(KC_WSCH), LALT_T(KC_DEL), RSFT_T(KC_ENT), LT(4,KC_HAEN), KC_MPLY, RGUI(KC_L), KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGUI_T(KC_NO), RALT_T(KC_TAB), RCTL_T(KC_SPC), LT(3,KC_BSPC), KC_BTN1, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_BSPC, KC_ENT),
	[2] = LAYOUT(KC_LBRC, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT_T(KC_RBRC), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_BSLS), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_N, KC_M, KC_COMM, KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT_T(KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT(KC_F3, KC_F4, KC_GCLEFT, KC_UP, KC_GCRGHT, KC_HOME, KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_L, KC_NO, KC_NO, KC_F5, LSFT_T(KC_F6), KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_F7, KC_COMM, KC_DOT, KC_LBRC, RSFT_T(KC_RBRC), KC_PGUP, KC_BTN3, KC_WH_D, KC_F1, KC_WH_R, KC_NO, KC_NO, KC_F8, KC_NO, KC_S, KC_N, LALT(KC_F4), KC_PGDN, TO(2), TO(1), KC_BTN4, KC_BTN5, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F11, LCTL_T(KC_F12), KC_TRNS, KC_BTN2, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
	[4] = LAYOUT(KC_GRV, KC_BSLS, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_SCLN, KC_QUOT, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, RGB_VAI, KC_SLSH, KC_1, KC_2, KC_3, KC_MINS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAD, RGB_RMOD, RGB_MOD, KC_WBAK, KC_WFWD, KC_TRNS, RGB_TOG, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SPD, RGB_SPI, LCTL_T(KC_MPRV), LSFT_T(KC_MNXT), KC_BTN3, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};
