/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

/* Layers mirror the Preonic "forfudan" keymap:
 *   NAV (Preonic layer 1) <- hold Esc, or hold the left space
 *   ADJ (Preonic layer 2) <- hold the right space while NAV is active
 *   NUM (Preonic layer 3) <- hold Tab
 *
 * Bootloader / flashing: hold left space, hold right space, then press the
 * bottom-right arrow. Identical to the Preonic.
 */
enum layers{
    MAC_BASE,
    WIN_BASE,
    NAV,
    ADJ,
    NUM,
    MAC_FN1,
    WIN_FN1,
    FN2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_GRV,            KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT(NUM,KC_TAB),    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        LT(NAV,KC_ESC),    KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,
        KC_LCTL,          KC_LOPTN,  KC_LCMMD,          LT(NAV,KC_SPC),   MO(MAC_FN1), MO(FN2),       KC_SPC,            KC_RCMMD,           KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_GRV,            KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        LT(NUM,KC_TAB),    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        LT(NAV,KC_ESC),    KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,
        KC_LCTL,           KC_LWIN,  KC_LALT,           LT(NAV,KC_SPC),   MO(WIN_FN1), MO(FN2),       KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    /* Symbols / navigation -- Preonic layer 1 */
    [NAV] = LAYOUT_69_ansi(
        KC_TILD,        KC_EXLM,    KC_AT,  KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     _______,  _______,  _______,          _______,
        KC_GRV,         KC_LCBR,  KC_RCBR,  KC_PLUS, KC_UNDS, KC_PIPE, KC_BSLS,  KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,     _______,  _______,  _______,          _______,
        _______,   LSFT(KC_ENT),   KC_ENT,  KC_BSPC,  KC_DEL,   KC_NO,           KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,     KC_BSPC,  KC_QUOT,  _______,          _______,
        _______,           KC_NO,  KC_QUOT, KC_DQUO,   KC_NO,   KC_NO,   KC_NO,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END,     KC_DEL,   _______,          KC_VOLU,
        _______,         _______,  _______,           _______,          _______, _______,     LT(ADJ,KC_SPC),            _______,           KC_VOLD, KC_MUTE, _______),

    /* Function / system -- Preonic layer 2 */
    [ADJ] = LAYOUT_69_ansi(
        KC_NO,             KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    _______,          _______,
        KC_NO,             KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_PWR,   KC_NO,    KC_NO,            _______,
        KC_CAPS,          KC_F11,   KC_F12,    KC_NO,   KC_NO,   KC_NO,             KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_PSCR,  KC_SLEP,  _______,          _______,
        KC_NO,           RGB_VAD,  RGB_VAI, RGB_RMOD, RGB_MOD, RGB_TOG,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_INS,   KC_WAKE,          KC_BRIU,
        _______,         _______,  _______,           _______,          _______, _______,          _______,              _______,           KC_BRID,   KC_NO, QK_BOOT),

    /* Numpad -- Preonic layer 3 */
    [NUM] = LAYOUT_69_ansi(
        KC_NO,             KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    _______,          _______,
        _______,           KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,  KC_NUM,    KC_P7,   KC_P8,   KC_P9,  KC_PMNS,   _______,  _______,  _______,          _______,
        _______,           KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,           KC_PSLS,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,   KC_NO,    _______,          _______,
        _______,           KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_PAST,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,   KC_PENT,          KC_PENT,
        _______,         _______,  _______,           _______,          _______, _______,          _______,              _______,             KC_P0, KC_PDOT, KC_PENT),

    [MAC_FN1] = LAYOUT_69_ansi(
        KC_GRV,            KC_BRID,  KC_BRIU,  KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______,           BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, _______, _______, KC_INS,   KC_PGUP,  _______,  _______,          _______,
        RGB_TOG,           RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, KC_SNAP,  KC_PGDN,  KC_END,   _______,          _______,
        _______,                     RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______,           _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,           KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______,          BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  _______,  _______,          _______,
        RGB_TOG,          RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, KC_PSCR,  KC_PGDN,  KC_END,   _______,          _______,
        _______,                    RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______,          _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD,          KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______,          _______,  _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,          _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,                    _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______,          _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [NAV]      = { ENCODER_CCW_CW(_______, _______)},
    [ADJ]      = { ENCODER_CCW_CW(_______, _______)},
    [NUM]      = { ENCODER_CCW_CW(_______, _______)},
    [MAC_FN1]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN1]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]      = { ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE
