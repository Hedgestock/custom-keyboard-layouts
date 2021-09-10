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


#include "hedgestock.h"

enum layers {
  BASE, // base layer
};

 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ortho_3x10(
    SEND_STRING(SS_TAP(KC_A)),            CA_P,         CA_O,         CA_V,         CA_W,    CA_J,    CA_D,         CA_U,         CA_X,         CA_M,
    CA_L,            CA_I,         CA_E,         CA_R,         CS_DOT,  CS_COMM, CA_T,         CA_S,         CA_A,         CA_N,
    CA_F,            CA_Y,         CA_Q,         CA_H,         KC_ENT,  CS_SPC,  CA_G,         CA_B,         CA_K,         CA_Z
  ),
};

