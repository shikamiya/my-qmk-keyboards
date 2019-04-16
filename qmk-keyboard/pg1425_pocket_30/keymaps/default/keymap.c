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

enum layers {
  _TEST,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _TEST
 * ,-----------------------------------------.
 * |  A   |  B   |  C   |  D   |  E   |  F   |
 * |------+------+------+------+------+------|
 * |  G   |  H   |  I   |  J   |  K   |  L   |
 * |------+------+------+------+------+------|
 * |  M   |  N   |  O   |  P   |  Q   |  R   |
 * |------+------+------+------+------+------|
 * |  S   |  T   |  U   |  V   |  W   |  X   |
 * |------+------+------+--------------------'
 * |  Y   |  Z   |MO(_FN|
 * |------+------+------|
 * | LALT | LCTL | LSFT |
 * `--------------------'
 */



    [_TEST] = LAYOUT(
 KC_A, KC_B, KC_C, KC_D, KC_E, KC_F,
 KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,
 KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,
 KC_S, KC_T, KC_U, KC_V, KC_W, KC_X,
 KC_Y, KC_Z, MO(_FN),
 KC_LALT, KC_LCTL, KC_LSFT
 ),

/* _FN
 * ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   | DOT  |
 * |------+------+------+------+------+------|
 * |  6   |  7   |  8   |  9   |  0   | COMM |
 * |------+------+------+--------------------'
 * | SCLN | MINS |      |
 * |------+------+------|
 * |      |      |      |
 * `--------------------'
 */



    [_FN] = LAYOUT(
 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
 KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
 KC_1, KC_2, KC_3, KC_4, KC_5, KC_DOT,
 KC_6, KC_7, KC_8, KC_9, KC_0, KC_COMM,
 KC_SCLN, KC_MINS, _______,
 _______, _______, _______
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
