#include QMK_KEYBOARD_H

enum my_layers {
  _FIRST_LAYER
//  _SECOND_LAYER
};

// enum my_keycodes {
//  FIRST_LAYER = SAFE_RANGE,
//  SECOND_LAYER
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT( \
	//________________________________________________________________________________________________
                 KC_W,   KC_E,   KC_T, XXXXXXX,        XXXXXXX,  KC_U,   KC_I,      KC_O,\
     	         KC_A,   KC_S,   KC_D, XXXXXXX,        XXXXXXX,  KC_H,   KC_K,   KC_BSPC,\
	    KC_LSFT, KC_Z,   KC_C,   KC_V,                         KC_N,   KC_M,   KC_COMM,  KC_ENT,\
	             KC_1,  TT(1),   KC_2,   KC_3,          KC_4,  KC_5, KC_SPC,      KC_1 \
	),
	/*
	[1] = LAYOUT( \
	//_________________________________________________________________________________________________
	             KC_Q,   KC_E,   KC_R,   KC_Z,   KC_Z,   KC_Z,        KC_Z,   KC_Z,   KC_Z,   KC_U,   KC_I,        KC_O, \
	             KC_A,   KC_F,   KC_G,   KC_Z,   KC_Z,   KC_Z,        KC_Z,   KC_Z,   KC_Z,   KC_J,   KC_P,     KC_BSPC, \
	    KC_LSFT, KC_Z,   KC_X,   KC_V,   KC_Z,   KC_Z,                KC_Z,   KC_Z,   KC_B,   KC_L,   KC_COMM,   KC_ENT, \
	                                  KC_TRNS,   KC_Z,   KC_Z,        KC_Z,   KC_Z,   KC_SPC \
	),
	[2] = LAYOUT( \
	             KC_EQL,  KC_PSLS, KC_PAST, KC_Z, KC_Z, KC_Z,         KC_Z, KC_Z, KC_Z, KC_P7, KC_P8, KC_P9, \
				 KC_BSLS, KC_PMNS, KC_PPLS, KC_Z, KC_Z, KC_Z,         KC_Z, KC_Z, KC_Z, KC_P4, KC_P5, KC_P6, \
		KC_LALT, KC_CIRC, KC_PDOT, KC_GRV,  KC_Z, KC_Z,                     KC_Z, KC_Z, KC_P1, KC_P2, KC_P3, KC_ENT, \
				                         KC_TRNS, KC_Z, KC_Z,         KC_Z, KC_Z, KC_SPC \
	),
	[3] = LAYOUT( \
	             KC_F2,  KC_F4,   KC_F5,  KC_Z,  KC_Z, KC_Z,               KC_Z, KC_Z, KC_Z, KC_PGUP,  KC_INS,   KC_DEL, \
				 KC_F7,  KC_F8,   KC_F9,  KC_Z,  KC_Z, KC_Z,               KC_Z, KC_Z, KC_Z, KC_RCTL,   KC_UP,  KC_LALT, \
	KC_LSFT,    KC_F10, KC_F11,  KC_F12,  KC_Z,  KC_Z,                           KC_Z, KC_Z, KC_LEFT, KC_DOWN,  KC_RGHT, KC_ENT,\
	                                   KC_TRNS,  KC_Z, KC_Z,               KC_Z, KC_Z, KC_SPC\
	)*/
};
