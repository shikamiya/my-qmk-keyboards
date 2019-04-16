/* Copyright 2019 %YOUR_NAME%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

enum layers {
  _MODS,
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _FN,
  _CONFIG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _MODS
 * ,-----------------------------------------. ,-----------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   | |  6   |  7   |  8   |  9   |  0   | BSPC |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | TAB  |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * | SPC  |      |      |      |      |      | |      |      |      |      |      | ENT  |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      | SPC  | LALT | LGUI | | RGUI | RALT | ENT  |
 *                      |------+------+------| |------+------+------|
 *                      |MO(_FN| LCTL | LSFT | | RSFT | RCTL |MO(_FN|
 *                      `--------------------' `--------------------'
 */

    [_MODS] = LAYOUT(
 KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
 KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
 KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
                           KC_SPC,  KC_LALT, KC_LGUI, KC_RGUI, KC_RALT, KC_ENT,
                           MO(_FN), KC_LCTL, KC_LSFT, KC_RSFT, KC_RCTL, MO(_FN)
 ),

/* _QWERTY
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  Q   |  W   |  E   |  R   |  T   | |  Y   |  U   |  I   |  O   |  P   | MINS |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  A   |  S   |  D   |  F   |  G   | |  H   |  J   |  K   |  L   | SCLN | QUOT |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   | |  N   |  M   | COMM | DOT  | SLSH |      |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      |      |      |      | |      |      |      |
 *                      |------+------+------| |------+------+------|
 *                      |      |      |      | |      |      |      |
 *                      `--------------------' `--------------------'
 */

    [_QWERTY] = LAYOUT(
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
 _______, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
 _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______
                                  ),

/* _COLEMAK
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  Q   |  W   |  F   |  P   |  G   | |  J   |  L   |  U   |  Y   | SCLN | MINS |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  A   |  R   |  S   |  T   |  D   | |  H   |  N   |  E   |  I   |  O   | QUOT |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   | |  K   |  M   | COMM | DOT  | SLSH |      |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      |      |      |      | |      |      |      |
 *                      |------+------+------| |------+------+------|
 *                      |      |      |      | |      |      |      |
 *                      `--------------------' `--------------------'
 */

    [_COLEMAK] = LAYOUT(
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_MINS,
 _______, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
 _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______
 ),

/* _DVORAK
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | QUOT | COMM | DOT  |  P   |  Y   | |  F   |  G   |  C   |  R   |  L   | SLSH |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  A   |  O   |  E   |  U   |  I   | |  D   |  H   |  T   |  N   |  S   | MINS |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | SCLN |  Q   |  J   |  K   |  X   | |  B   |  M   |  W   |  V   |  Z   |      |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      |      |      |      | |      |      |      |
 *                      |------+------+------| |------+------+------|
 *                      |      |      |      | |      |      |      |
 *                      `--------------------' `--------------------'
 */

    [_DVORAK] = LAYOUT(
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
 _______, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
 _______, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______
 ),

/* _FN
 * ,-----------------------------------------. ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | EQL  |  7   |  8   |  9   | DOT  | | PSCR | LBRC | RBRC | LCBR | RCBR | DEL  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | PLUS |  4   |  5   |  6   | MINS | | INS  | LEFT | DOWN |  UP  | RGHT | BSLS |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  0   |  1   |  2   |  3   |MO_CFG| |MO_CFG| HOME | PGDN | PGUP | END  | PIPE |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      |      |      |      | |      |      |      |
 *                      |------+------+------| |------+------+------|
 *                      |      |      |      | |      |      |      |
 *                      `--------------------' `--------------------'
 */

    [_FN] = LAYOUT(
 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
 _______, KC_EQL, KC_7, KC_8, KC_9, KC_DOT, KC_PSCR, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DEL,
 _______, KC_PLUS, KC_4, KC_5, KC_6, KC_MINS, KC_INS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSLS,
 _______, KC_0, KC_1, KC_2, KC_3, MO(_CONFIG), MO(_CONFIG), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______
 ),

/* _CONFIG
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |QWERTY|COLEMA|DVORAK|      | |      |QWERTY|COLEMA|DVORAK|      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |      |      |      |      |      |      |
 * `--------------------+------+------+------| |------+------+------+--------------------'
 *                      |      |      |      | |      |      |      |
 *                      |------+------+------| |------+------+------|
 *                      |      |      |      | |      |      |      |
 *                      `--------------------' `--------------------'
 */

    [_CONFIG] = LAYOUT(
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, QWERTY, COLEMAK, DVORAK, _______, _______, QWERTY, COLEMAK, DVORAK, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}

void matrix_init_user(void) {
  if(eeconfig_read_default_layer() == 0) {
    set_single_persistent_default_layer(_QWERTY);
  }
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
