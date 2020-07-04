/* Copyright 2019 Stefano Marago'
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


/*
 * The 25% SuperMicro keyboard: a pure - full features - "Alpha 26" keymap on Gherkin, compatible also with 28 and 30 keys layouts
 * See https://github.com/stevexyz/qmk_firmware/blob/master/keyboards/40percentclub/gherkin/keymaps/stevexyz/readme.md for more information
 */


#include QMK_KEYBOARD_H

#include "keymap_us_international.h"

enum combos {
  ESC,
  SCLN,
  DEL,
};

const uint16_t PROGMEM esc_combo[] = {US_C, US_P, COMBO_END};
const uint16_t PROGMEM scln_combo[] = {US_COMM, US_DOT, COMBO_END};
const uint16_t PROGMEM del_combo[] = {US_M, US_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ESC] = COMBO(esc_combo, KC_ESC),
  [SCLN] = COMBO(scln_combo, US_SCLN),
  [DEL] = COMBO(del_combo, KC_DEL)
};

enum layers {
  BASE, // base layer
  ACC, // accentued letters
  NUM, // numbers and other characters
  FUN, // function keys and navigation
};

enum custom_keycodes {
  CK_TRIPLEZERO = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    US_C,         US_P,         US_V,         US_O,         US_W,    US_J,   US_U,         US_D,         US_X,         KC_PSLS,
    LSFT_T(US_L), US_I,         LT(NUM,US_R), US_E,         US_COMM, US_DOT, US_S,         US_T,         US_A,         RSFT_T(US_N),
    LCTL_T(US_F), LALT_T(US_Y), RALT(US_H),   LWIN_T(US_Q), KC_ENT,  KC_SPC, RWIN_T(US_B), LALT_T(US_G), RALT_T(US_K), LCTL_T(US_Z)
  ),

  [NUM] = LAYOUT_ortho_3x10(
    US_C,         US_P,         US_V,       US_O,         US_W,     KC_PPLS,   KC_P7,         KC_P8,         KC_P9,         US_M,
    LSFT_T(US_L), US_I,         US_R,       US_E,         US_COMM,  KC_PMNS,   KC_P4,         KC_P5,         KC_P6,         RSFT_T(KC_P0),
    LCTL_T(US_F), LALT_T(US_Y), RALT(US_H), LWIN_T(US_Q), KC_PENT,  KC_PEQL,   RWIN_T(KC_P1), LALT_T(KC_P2), RALT_T(KC_P3), LCTL_T(KC_PAST)
  )
};


// void matrix_init_user(void) {
//   // eeconfig_init(); // reset keyboard to a standard default state; useful when new releases messup with eeprom values
//   // set num lock on at start (for numonly layer to work)
//   if (!host_keyboard_led_state().num_lock) {
//       tap_code(KC_NUMLOCK);
//   }
// }

// void matrix_scan_user(void) {
// }


// Handling custom shift like that is problematic because of fantom unregistering
// and no real custom shift if the key is not shifted
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case US_COMM:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(US_SLSH);
          return false;
        } else {
        }
      } else {
        unregister_code(US_SLSH);
      }
      break;
    case US_DOT:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(US_1);
          return false;
        } else {
        }
      } else {
        unregister_code(US_1);
      }
      break;
    case KC_SPC:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code(KC_BSPC);
          return false;
        } else {
        }
      } else {
        unregister_code(KC_BSPC);
      }
      break;
  }
  return true;
};

// void keyboard_pre_init_user(void) {
//   // Set our LED pins as output
//   setPinOutput(D5);
//   setPinOutput(B0);
// }

// bool led_update_user(led_t led_state) {
//     writePin(D5, !led_state.num_lock);
//     writePin(B0, !led_state.caps_lock);
//     return false; // prevent keyboard from processing state
// }
