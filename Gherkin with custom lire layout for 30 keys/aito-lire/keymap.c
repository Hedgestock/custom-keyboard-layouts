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
  SFT_FIRST = SAFE_RANGE,
  MY_DOT,
  MY_COMM,
  MY_SPC,
  MY_LCBR,
  MY_RCBR,
  MY_LPRN,
  MY_RPRN,
  // MY_EURO,
  SFT_LAST,
};

enum modifiers {
  NONE = 0,
  SHFT,
  ALTE,
  CTRL,
  ALGR,
};

struct custom_key
{
  char modifier;
  uint16_t keycode;
  uint16_t shifted_keycode;
  bool is_shifted_keycode_shifted;// use modifier instead
};


struct custom_key shifted_values[SFT_LAST - SFT_FIRST - 1] = {
  {NONE, US_DOT,  US_SLSH,  true},  // MY_DOT
  {NONE, US_COMM, US_1,     true},  // MY_COMM
  {NONE, KC_SPC,  KC_BSPC,  false}, // MY_SPC
  {SHFT, US_LBRC, US_COMM,  true},  // MY_LCBR
  {SHFT, US_LBRC, US_DOT,   true},  // MY_RCBR
  {SHFT, US_9,    US_LBRC,  false}, // MY_LPRN
  {SHFT, US_0,    US_RBRC,  false}, // MY_RPRN
  // {NONE, US_EURO, US_1,     true},  // MY_EURO
};// TODO, add custom modifiers to custom_shift function

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    US_C,         US_P,         US_V,         US_O,         US_W,    US_J,   US_U,         US_D,         US_X,         US_M,
    LSFT_T(US_L), US_I,         LT(NUM,US_R), US_E,         MY_COMM, MY_DOT, US_S,         LT(NUM,US_T), US_A,         RSFT_T(US_N),
    LCTL_T(US_F), LALT_T(US_Y), RALT(US_H),   LWIN_T(US_Q), KC_ENT,  MY_SPC, RWIN_T(US_B), LALT_T(US_G), RALT_T(US_K), LCTL_T(US_Z)
  ),

  [ACC] = LAYOUT_ortho_3x10(
    US_CIRC,         US_HASH,         US_AT,         US_AMPR,         US_PIPE,  KC_PPLS,   KC_P7,         KC_P8,         KC_P9,         KC_PSLS,
    LSFT_T(US_LCBR), US_RCBR,         US_LPRN,       US_RPRN,         US_EURO,  KC_PMNS,   KC_P4,         KC_P5,         KC_P6,         RSFT_T(KC_P0),
    LCTL_T(US_LABK), LALT_T(US_RABK), RALT(US_LBRC), LWIN_T(US_RBRC), KC_PENT,  KC_PEQL,   RWIN_T(KC_P1), LALT_T(KC_P2), RALT_T(KC_P3), LCTL_T(KC_PAST)
  ),

  [NUM] = LAYOUT_ortho_3x10(
    US_CIRC,         US_HASH,         US_AT,         US_AMPR,         US_PIPE,  KC_PPLS,   KC_P7,         KC_P8,         KC_P9,         KC_PSLS,
    LSFT_T(MY_LCBR), MY_RCBR,         MY_LPRN,       MY_RPRN,         US_EURO,  KC_PMNS,   KC_P4,         KC_P5,         KC_P6,         RSFT_T(KC_P0),
    LCTL_T(US_LABK), LALT_T(US_RABK), RALT(US_LBRC), LWIN_T(US_RBRC), KC_PENT,  KC_PEQL,   RWIN_T(KC_P1), LALT_T(KC_P2), RALT_T(KC_P3), LCTL_T(KC_PAST)
  )
};


bool custom_shift(uint16_t keycode, keyrecord_t *record){
  const struct custom_key key = shifted_values[keycode - SFT_FIRST - 1];
  if (record->event.pressed){
    uint16_t shift;
    bool is_shifted = false;
    if (get_mods() & MOD_BIT(KC_LSHIFT)) {
      shift = KC_LSHIFT;
      is_shifted = true;
    } else if (get_mods() & MOD_BIT(KC_RSHIFT)) {
      shift = KC_RSHIFT;
      is_shifted = true;
    }
    if (is_shifted)
    {
      if(key.is_shifted_keycode_shifted){
        register_code(key.shifted_keycode);
      } else {
        unregister_code(shift);
        register_code(key.shifted_keycode);
        register_code(shift);
      }
    } else {
      register_code(key.keycode);
    }
  } else {
    unregister_code(key.shifted_keycode);
    unregister_code(key.keycode);
  }
  return false;
}


// Handling custom shift like that is problematic because of phantom unregistering
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(keycode >= SFT_FIRST && keycode < SFT_LAST) {
    return custom_shift(keycode, record);
  }
  return true;
};
/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case US_COMM:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)){
          unregister_code(KC_LSHIFT);
          register_code(US_SLSH);
          register_code(KC_LSHIFT);
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
*/