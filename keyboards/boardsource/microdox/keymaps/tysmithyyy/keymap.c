/*
Copyright 2020 Cole Smith <cole@boadsource.xyz>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "oled.c"
#include <stdio.h>

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _GAME,
    _FKEYS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAME TG(_GAME)
#define FKEYS TG(_FKEYS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q, KC_W,         KC_E,         KC_R,         KC_T,           KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
  KC_A, LSFT_T(KC_S), LCTL_T(KC_D), LALT_T(KC_F), LGUI_T(KC_G),   RGUI_T(KC_H), RALT_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), KC_BSPC,
  KC_Z, KC_X,         KC_C,         KC_V,         KC_B,           KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SFTENT,
                      KC_LGUI,      LOWER,        KC_LSFT,        KC_SPC,       RAISE,        KC_TAB
),

[_LOWER] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_LT,   KC_GT, KC_LCBR, KC_RCBR,   KC_DQUO,      KC_QUOT, KC_LBRC, KC_RBRC,  KC_LPRN, KC_RPRN,
  KC_GRV, KC_TILD,  KC_LCTL, KC_LALT, KC_COLN,      KC_SCLN, KC_MINS, KC_EQL, KC_PIPE,  KC_BSLS,
                    KC_LGUI, XXXXXXX, KC_LSFT,      KC_SPC, KC_BSPC, KC_ESC
),

[_RAISE] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU,      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL,
  KC_CAPS, KC_TILD, KC_MPLY, KC_VOLD, KC_VOLU,      KC_BRID, KC_PLUS, KC_UNDS, KC_PIPE,  KC_ENT,
                    KC_MUTE, FKEYS, GAME,      KC_ENT,  XXXXXXX, KC_DEL
),

[_GAME] = LAYOUT_split_3x5_3(
  KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_T,      KC_F1, KC_F2,  KC_F3,  KC_F4,   KC_F5,
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,      KC_G,  KC_H,   KC_J,   KC_K,    KC_L,
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,      KC_B,  KC_N,   KC_M,   KC_RCTL, KC_RSFT,
                KC_LGUI, KC_TAB, KC_SPC,      KC_SPC, GAME, KC_ESC
),

[_FKEYS] = LAYOUT_split_3x5_3(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
  KC_F11,   KC_F12, KC_F13, XXXXXXX,   KC_G,      XXXXXXX, XXXXXXX, KC_F11,  KC_F12, KC_F13,
  KC_LSFT, KC_LCTL,  KC_LALT, KC_LGUI, XXXXXXX,      XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,  KC_RSFT,
                    KC_LGUI, FKEYS, KC_LSFT,      KC_SPC, KC_BSPC, KC_ESC
)

};

