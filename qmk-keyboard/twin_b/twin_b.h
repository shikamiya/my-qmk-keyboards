/* Copyright 2019 Bearia
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
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
  L00, L01, L02, L03,                     R00, R01, R02, R03, \
  L10, L11, L12, L13,                     R10, R11, R12, R13, \
  L20, L21, L22, L23,                     R20, R21, R22, R23, \
  L30, L31, L32, L33,                     R30, R31, R32, R33  \
  ) \
  { \
    { L00, L01, L02, L03 }, \
    { L10, L11, L12, L13 }, \
    { L20, L21, L22, L23 }, \
    { L30, L31, L32, L33 }, \
    { R03, R02, R01, R00 }, \
    { R13, R12, R11, R10 }, \
    { R23, R22, R21, R20 }, \
    { R33, R32, R31, R30 }  \
  }

#define LAYOUT_kc( \
  L00, L01, L02, L03,           R00, R01, R02, R03, \
  L10, L11, L12, L13,           R10, R11, R12, R13, \
  L20, L21, L22, L23,           R20, R21, R22, R23, \
  L30, L31, L32, L33,           R30, R31, R32, R33  \
  ) \
  LAYOUT( \
    KC_##L00, KC_##L01, KC_##L02, KC_##L03,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, \
    KC_##L10, KC_##L11, KC_##L12, KC_##L13,                     KC_##R10, KC_##R11, KC_##R12, KC_##R13, \
    KC_##L20, KC_##L21, KC_##L22, KC_##L23,                     KC_##R20, KC_##R21, KC_##R22, KC_##R23, \
    KC_##L30, KC_##L31, KC_##L32, KC_##L33,                     KC_##R30, KC_##R31, KC_##R32, KC_##R33, \
  )
