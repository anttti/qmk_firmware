#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define NAVI 1
#define SYMB 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Alphas
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  NOOP  |   1  |   2  |   3  |   4  |   5  | NOOP |           | NOOP |   6  |   7  |   8  |   9  |   0  |  NOOP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | MehTab |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Ent/Cmd|
 * |--------+------+------+------+------+------|  -   |           |  =   |------+------+------+------+------+--------|
 * | (/Shift|   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | )/Shift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   \  | NOOP | NOOP | Alt  |                                       | LT2/`| NOOP | NOOP | NOOP | NOOP |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VolDn| VolUp|       | Play |ScrnSh|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | PgDn |        |      |
 *                                 | Mo(1)|Shift/|------|       |------|  Cmd/  |Space |
 *                                 |      | Tab  | Home |       | End  |  Enter |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_NO,          KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_NO,
  MEH_T(KC_TAB),  KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
  LCTL_T(KC_ESC), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
  KC_LSPO,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,
  KC_LGUI,        KC_BSLS,      KC_NO,  KC_NO,  KC_LALT,

                                               KC__VOLDOWN,         KC__VOLUP,
                                                                    KC_PGUP,
                                        MO(1), MT(MOD_LSFT, KC_TAB),KC_HOME,
  // right hand
  KC_NO,       KC_6,   KC_7,          KC_8,   KC_9,   KC_0,    KC_NO,
  KC_RBRC,     KC_Y,   KC_U,          KC_I,   KC_O,   KC_P,    KC_QUOT,
               KC_H,   KC_J,          KC_K,   KC_L,   KC_SCLN, GUI_T(KC_ENT),
  KC_EQL,      KC_N,   KC_M,          KC_COMM,KC_DOT, KC_SLSH, KC_RSPC,
                       LT(2, KC_GRV), KC_NO,  KC_NO,  KC_NO,   KC_NO,

  KC_MPLY, G(S(C(KC_4))),
  KC_PGDN,
  KC_END,  MT(MOD_LGUI, KC_ENT),KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Home | PgDn | PgUp | End  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |         |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAVI] = LAYOUT_ergodox(
  // left hand
  RESET,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
  KC_TRNS,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_TRNS,
  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
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
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                              KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
)};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     // dynamically generate these.
//     case VRSN:
//       if (record->event.pressed) {
//         SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//       }
//       return false;
//       break;
//     case RGB_SLD:
//       if (record->event.pressed) {
//         #ifdef RGBLIGHT_ENABLE
//           rgblight_mode(1);
//         #endif
//       }
//       return false;
//       break;
//   }
//   return true;
// }

// // Runs just one time when the keyboard initializes.
// void matrix_init_user(void) {

// };


// // Runs constantly in the background, in a loop.
// void matrix_scan_user(void) {

//     uint8_t layer = biton32(layer_state);

//     ergodox_right_led_1_off();
//     ergodox_right_led_2_off();
//     ergodox_right_led_3_off();
//     switch (layer) {
//       // TODO: Make this relevant to the ErgoDox EZ.
//         case 1:
//             ergodox_right_led_1_on();
//             break;
//         case 2:
//             ergodox_right_led_2_on();
//             break;
//         default:
//             // none
//             break;
//     }
// };
