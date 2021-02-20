#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define COLEMAK 1
#define NAVI 3
#define SYMB 2

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Colemak Left-hand home row mods
#define ALT_R LALT_T(KC_R)
#define GUI_S LGUI_T(KC_S)
#define SFT_TT LSFT_T(KC_T) // for some reason SFT_T is not a valid name

// Colemak Right-hand home row mods
#define SFT_N RSFT_T(KC_N)
#define GUI_E RGUI_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define CTL_O RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Alphas
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Sleep |   1  |   2  |   3  |   4  |   5  | Lock |           | Clmk |   6  |   7  |   8  |   9  |   0  |  NOOP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | MehTab |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|Ctrl/A| Alt/S| Cmd/D|Shft/F|   G  |------|           |------|   H  |Shft/J| Cmd/D| Alt/L|Ctrl/;| Enter  |
 * |--------+------+------+------+------+------|  -   |           |  =   |------+------+------+------+------+--------|
 * | (/Shift|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | )/Shift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   \  | NOOP | NOOP | Alt/Esc  |                                       | LT2/`| NOOP | NOOP | NOOP | NOOP |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolDn| VolUp|       | Play |ScrnSh|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       | PgDn | Cmd/ |      |
 *                                 | Mo(1)| Tab  |------|       |------| Enter|Space |
 *                                 |      |      | Home |       | End  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  C(G(S(A(KC_Z)))), KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   C(G(KC_Q)),
  MEH_T(KC_TAB),    KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
  LCTL_T(KC_ESC),   CTL_A,        ALT_S,  GUI_D,  SFT_F,  KC_G,
  KC_LSPO,          KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,
  KC_LGUI,          KC_BSLS,      KC_NO,  KC_NO,  KC_ESC,

                                               KC__VOLDOWN,   KC__VOLUP,
                                                              KC_PGUP,
                                     MO(NAVI), MEH_T(KC_TAB), KC_HOME,
  // right hand
  TG(COLEMAK), KC_6,   KC_7,          KC_8,   KC_9,   KC_0,     KC_NO,
  KC_RBRC,     KC_Y,   KC_U,          KC_I,   KC_O,   KC_P,     KC_QUOT,
               KC_H,   SFT_J,         GUI_K,  ALT_L,  CTL_SCLN, KC_ENT,
  KC_EQL,      KC_N,   KC_M,          KC_COMM,KC_DOT, KC_SLSH,  KC_RSPC,
                    LT(SYMB, KC_GRV), KC_NO,  KC_NO,  KC_NO,    KC_NO,

  KC_MPLY, G(S(C(KC_4))),
  KC_PGDN,
  KC_END,  MT(MOD_LGUI, KC_ENT),KC_SPC
),

/* Keymap 1b: Colemak alphas
 */

[COLEMAK] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_TRNS,
  KC_TRNS, CTL_A,   ALT_R,   GUI_S,   SFT_TT,  KC_G,
  KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_TRNS,

                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                     MO(NAVI), KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
           KC_M,    SFT_N,   GUI_E,   ALT_I,   CTL_O,   KC_TRNS,
  KC_TRNS, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Ctrl | Alt  | Cmd  | Shift|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Home | PgDn | PgUp | End  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |         |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  Del | Bcks |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAVI] = LAYOUT_ergodox(
  // left hand
  RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
  KC_TRNS,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
  KC_TRNS,KC_LCTL,KC_LALT,KC_LGUI,KC_LSFT,KC_TRNS,
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                  KC_TRNS,KC_TRNS,
                                          KC_TRNS,
                          KC_TRNS,KC_TRNS,KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
  KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_F12,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_DEL, KC_BSPC
),

/* Keymap 2: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |   [  |------|           |------|   ]  |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |   -  |      |           |      |   =  |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                              KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_TRNS, KC_TRNS,
            KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
)};
