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
// #include "oled.c"

enum custom_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _GAME,
    _FKEYS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_split_3x5_3(
  KC_Q, KC_W,         KC_E,         KC_R,         KC_T,           KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
  KC_A, LSFT_T(KC_S), LCTL_T(KC_D), LALT_T(KC_F), LGUI_T(KC_G),   RGUI_T(KC_H), RALT_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), KC_BSPC,
  KC_Z, KC_X,         KC_C,         KC_V,         KC_B,           KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SFTENT,
                      KC_LGUI,      MO(_LOWER),        KC_LSFT,        KC_SPC,       MO(_RAISE),        KC_TAB
),

[_LOWER] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_LT,   KC_GT, KC_LCBR, KC_RCBR,   KC_DQUO,      KC_QUOT, KC_LBRC, KC_RBRC,  KC_LPRN, KC_RPRN,
  KC_GRV, KC_TILD,  KC_LCTL, KC_LALT, KC_COLN,      KC_SCLN, KC_MINS, KC_EQL, KC_PIPE,  KC_BSLS,
                    KC_LGUI, XXXXXXX, KC_LSFT,      KC_SLSH, KC_BSPC, KC_ESC
),

[_RAISE] = LAYOUT_split_3x5_3(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU,      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL,
  KC_CAPS, KC_TILD, KC_MPLY, KC_VOLD, KC_VOLU,      KC_BRID, KC_PLUS, KC_UNDS, KC_PIPE,  KC_ENT,
                    KC_MUTE, TG(_FKEYS), TG(_GAME),      KC_ENT,  XXXXXXX, KC_DEL
),

[_GAME] = LAYOUT_split_3x5_3(
  KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_T,      KC_F1, KC_F2,  KC_F3,  KC_F4,   KC_F5,
  KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,      KC_G,  KC_H,   KC_J,   KC_K,    KC_L,
  KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,      KC_B,  KC_N,   KC_M,   KC_RCTL, KC_RSFT,
                KC_LGUI, KC_TAB, KC_SPC,      KC_SPC, TG(_GAME), KC_ESC
),

[_FKEYS] = LAYOUT_split_3x5_3(
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
  KC_F11,   KC_F12, KC_F13, XXXXXXX,   KC_G,      RESET, XXXXXXX, KC_F11,  KC_F12, KC_F13,
  KC_LSFT, KC_LCTL,  KC_LALT, KC_LGUI, XXXXXXX,      XXXXXXX, KC_RGUI, KC_RALT, KC_RCTL,  KC_RSFT,
                    KC_LGUI, TG(_FKEYS), KC_LSFT,      KC_SPC, KC_BSPC, KC_ESC
)

};

#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
//   }
//   return rotation;
// }

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _FKEYS:
            oled_write_ln_P(PSTR("FKeys"), false);
            break;
    }
}

static void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}   

bool oled_task_user(void) {
    oled_render_logo();
    oled_render_layer_state();
    return false;
}


#endif // OLED_ENABLE

