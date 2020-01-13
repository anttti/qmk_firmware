#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN 1
#define _SYMBOLS 2
#define _HARDWARE 3
#define _MISC 4

enum custom_keycodes {
    LOWERCASE_AE = SAFE_RANGE,
    UPPERCASE_AE,
    LOWERCASE_OE,
    UPPERCASE_OE,
};

/* Custom macros for outputting äöÄÖ */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWERCASE_AE:
            if (record->event.pressed) {
                SEND_STRING("test test foo bar");
            }
            break;
        case UPPERCASE_AE:
            if (record->event.pressed) {
                SEND_STRING("Ä");
            }
            break;
        case LOWERCASE_OE:
            if (record->event.pressed) {
                SEND_STRING("ö");
            }
            break;
        case UPPERCASE_OE:
            if (record->event.pressed) {
                SEND_STRING("Ö");
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .----------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC      | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | MEH(TAB) | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTL_ESC | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT   | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |----------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LGUI     | LCTRL  | MO(3)  | LALT   | MO(1)  | BACKSP | LEFT   | DOWN   | RIGHT  | ENTER  | MO(2)  | RALT   | MO(4)  | RCTRL  | RGUI   |
     * '----------------------------------------------------------------------------------------------------------------------------------------'
    */


    /* QWERTY
     * .----------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC      | 1      | 2      | 3      | 4      | 5      | _      | `      | +      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | MEH(TAB) | Q      | W      | E      | R      | T      | -      | \      | =      | Y      | U      | I      | O      | P      | '      |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTL_ESC | A      | S      | D      | F      | G      | [      | PG_UP  | ]      | H      | J      | K      | L      | ;      | ENTER  |
     * |----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT   | Z      | X      | C      | V      | B      | {      | PG_DN  | }      | N      | M      | ,      | .      | /      | RSHIFT |
     * |----------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LGUI     | LCTRL  | MO(3)  | LALT   | MO(1)  | BACKSP | HOME   | DEL    | END    | ENTER  | MO(2)  | LEFT   | DOWN   | UP     | RIGHT  |
     * '----------------------------------------------------------------------------------------------------------------------------------------'
    */

	[_QWERTY] = LAYOUT_ortho_5x15(
        KC_ESC,         KC_1,    KC_2,  KC_3,    KC_4,    KC_5,  KC_UNDS, KC_GRV,  KC_PLUS, KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_BSPC,
        MEH_T(KC_TAB),  KC_Q,    KC_W,  KC_E,    KC_R,    KC_T,  KC_MINS, KC_BSLS, KC_EQL,  KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_QUOT,
        LCTL_T(KC_ESC), KC_A,    KC_S,  KC_D,    KC_F,    KC_G,  KC_LBRC, KC_PGUP, KC_RBRC, KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSFT,        KC_Z,    KC_X,  KC_C,    KC_V,    KC_B,  KC_LCBR, KC_PGDN, KC_RCBR, KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LGUI,        KC_LCTL, MO(3), KC_LALT, KC_BSPC, MO(1), KC_HOME, KC_DEL,  KC_END,  KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT),

	[_FN] = LAYOUT_ortho_5x15(
        KC_MUTE, KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,  KC_NO,   KC_NO,   KC_NO,   KC_F6,         KC_F7,   KC_F8,   KC_F9,          KC_F10,  KC_F11,
        KC_TAB,  KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   LALT(KC_LEFT), KC_NO,   KC_NO,   LALT(KC_RIGHT), KC_NO,   KC_F12,
        KC_ESC,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_LEFT,       KC_DOWN, KC_UP,   KC_RGHT,        KC_NO,   KC_ENT,
        KC_LSFT, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_VOLU, KC_NO,   KC_NO,         KC_NO,   KC_NO,   KC_NO,          KC_NO,   KC_RSFT,
        KC_LGUI, KC_LCTL, KC_NO, KC_LALT, KC_TRNS, KC_DEL, KC_MPRV, KC_VOLD, KC_MNXT, KC_SPC,        KC_NO,   KC_LCTL, KC_NO,          KC_RCTL, KC_RGUI),

	[_SYMBOLS] = LAYOUT_ortho_5x15(
        KC_NO, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS, KC_TILD, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_NO, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_MINS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_LT,   KC_LCBR, KC_RCBR, KC_GT,   KC_COLN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DQUO, KC_EQL,  KC_PLUS, KC_UNDS, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_DOT,  KC_SCLN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO),

	[_HARDWARE] = LAYOUT_ortho_5x15(
        RGB_TOG, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, RESET,
        BL_TOGG, BL_INC,  BL_DEC,   BL_BRTG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRIU, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_TRNS,  KC_NO,   KC_NO,   KC_BTN2, KC_NO,   KC_BRID, KC_NO, KC_BTN1, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO),

	[_MISC] = LAYOUT_ortho_5x15(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LOWERCASE_OE,   KC_NO, KC_NO,
        KC_NO, LOWERCASE_AE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO)
};
