#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define NAVI 1
#define SYMB 2

// Left-hand home row mods
#define CTL_A  LCTL_T(KC_A)
#define ALT_R  LALT_T(KC_R)
#define GUI_S  LGUI_T(KC_S)
#define _SFT_T LSFT_T(KC_T)

// Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ortho_5x15(
        KC_NO,          KC_1,    KC_2,  KC_3,  KC_4,           KC_5,  KC_NO,         G(S(C(KC_4))), KC_NO,   KC_6,   KC_7,          KC_8,    KC_9,   KC_0,    KC_NO,
        MEH_T(KC_TAB),  KC_Q,    KC_W,  KC_F,  KC_P,           KC_B,  KC_NO,         KC_MPLY,       KC_NO,   KC_J,   KC_L,          KC_U,    KC_Y,   KC_SCLN, KC_QUOT,
        LCTL_T(KC_ESC), CTL_A,   ALT_R, GUI_S, _SFT_T,         KC_G,  KC_LBRC,       KC_VOLU,       KC_RBRC, KC_M,   SFT_N,         GUI_E,   ALT_I,  CTL_O,    KC_ENT,
        KC_LSPO,        KC_Z,    KC_X,  KC_C,  KC_D,           KC_V,  KC_MINS,       KC_VOLD,       KC_EQL,  KC_K,   KC_H,          KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
        KC_LGUI,        KC_BSLS, KC_NO, KC_NO, LALT_T(KC_ESC), MO(1), MEH_T(KC_TAB), KC_NO,         KC_ENT,  KC_SPC, LT(2, KC_GRV), KC_NO,   KC_NO,  KC_NO,   KC_NO),

	[NAVI] = LAYOUT_ortho_5x15(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS, KC_TRNS, KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_F12,
        KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS),

    [SYMB] = LAYOUT_ortho_5x15(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
