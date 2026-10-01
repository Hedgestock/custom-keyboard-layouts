/* Copyright 2020 Arthur "Hedgestock" PAMART pamarthur.aito@gmail.com @hedgestock
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
  _1, // base layer
  _2,
  _3,
  _4,
};

 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_1] = LAYOUT_ortho_3x10(
    S(KC_F22), S(KC_F19), S(KC_F16), S(KC_F13), KC_F22, KC_F19, KC_F16, KC_F13, TO(_4), TO(_1),
    S(KC_F23), S(KC_F20), S(KC_F17), S(KC_F14), KC_F23, KC_F20, KC_F17, KC_F14, KC_NO, TO(_2),
    S(KC_F24), S(KC_F21), S(KC_F18), S(KC_F15), KC_F24, KC_F21, KC_F18, KC_F15, KC_NO, TO(_3)

  ),

  [_2] = LAYOUT_ortho_3x10(
    A(KC_F22), A(KC_F19), A(KC_F16), A(KC_F13), C(KC_F22), C(KC_F19), C(KC_F16), C(KC_F13), _______, _______,
    A(KC_F23), A(KC_F20), A(KC_F17), A(KC_F14), C(KC_F23), C(KC_F20), C(KC_F17), C(KC_F14), _______, _______,
    A(KC_F24), A(KC_F21), A(KC_F18), A(KC_F15), C(KC_F24), C(KC_F21), C(KC_F18), C(KC_F15), _______, _______
  ),

  [_3] = LAYOUT_ortho_3x10(
    LCA(KC_F22), LCA(KC_F19), LCA(KC_F16), LCA(KC_F13), LSA(KC_F22), LSA(KC_F19), LSA(KC_F16), LSA(KC_F13), _______, _______,
    LCA(KC_F23), LCA(KC_F20), LCA(KC_F17), LCA(KC_F14), LSA(KC_F23), LSA(KC_F20), LSA(KC_F17), LSA(KC_F14), _______, _______,
    LCA(KC_F24), LCA(KC_F21), LCA(KC_F18), LCA(KC_F15), LSA(KC_F24), LSA(KC_F21), LSA(KC_F18), LSA(KC_F15), _______, _______
  ),

  [_4] = LAYOUT_ortho_3x10(
    MEH(KC_F22), MEH(KC_F19), MEH(KC_F16), MEH(KC_F13), LCS(KC_F22), LCS(KC_F19), LCS(KC_F16), LCS(KC_F13), _______, _______,
    MEH(KC_F23), MEH(KC_F20), MEH(KC_F17), MEH(KC_F14), LCS(KC_F23), LCS(KC_F20), LCS(KC_F17), LCS(KC_F14), _______, _______,
    MEH(KC_F24), MEH(KC_F21), MEH(KC_F18), MEH(KC_F15), LCS(KC_F24), LCS(KC_F21), LCS(KC_F18), LCS(KC_F15), _______, _______
  ),
};



