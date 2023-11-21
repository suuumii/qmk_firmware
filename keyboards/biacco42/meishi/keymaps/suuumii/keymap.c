/* Copyright 2017 Biacco42
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

// Added
enum custom_keycodes { PASS = SAFE_RANGE, NOMI };

// Changed
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                 LALT(KC_ENTER), RCS(KC_M), PASS, NOMI),
};

const uint16_t PROGMEM fn_actions[] = {

};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

// Changed
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PASS:
            if (record->event.pressed) {
                // pressed
                SEND_STRING("hoge");
            } else {
                // released
            }
            break;
        case NOMI:
            if (record->event.pressed) {
                // pressed
                // 今日飲みに行きませんか？（beer)
                SEND_STRING(SS_LALT("`"));
                SEND_STRING("kyou");
                SEND_STRING(" ");
                SEND_STRING("nomini");
                SEND_STRING(" ");
                SEND_STRING("imasenka");
                SEND_STRING(" ");
                SEND_STRING(SS_LALT("`"));
                SEND_STRING("?");
                SEND_STRING(SS_LSFT("9"));
                SEND_STRING("beer");
                SEND_STRING(SS_LSFT("0"));
            } else {
                // released
            }
            break;
    }

    return true;
}

void led_set_user(uint8_t usb_led) {}