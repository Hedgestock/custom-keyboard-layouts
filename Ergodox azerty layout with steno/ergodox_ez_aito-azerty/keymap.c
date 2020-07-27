#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_french.h"
#include "keymap_bepo.h"
#include "keymap_steno.h"

#define TXBOLT 3 // TxBolt Steno Virtual Serial

enum my_keycodes {
  XMAS1 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      FR_AMP,         FR_EACU,        FR_DQUO,        FR_APOS,        FR_LPRN,        TT(2),                                          TT(2),          FR_MINS,        FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,        KC_INSERT,
    KC_TAB,         FR_A,           FR_Z,           KC_E,           KC_R,           KC_T,           FR_DLR,                                         FR_ASTR,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           FR_CIRC,
    LSFT_T(KC_CAPSLOCK),FR_Q,       KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           FR_M,           RSFT_T(KC_CAPSLOCK),
    KC_LCTRL,       FR_W,           KC_X,           KC_C,           KC_V,           KC_B,           TT(1),                                          TT(1),          KC_N,           FR_COMM,        FR_SCLN,        FR_COLN,        FR_EXLM,        KC_RCTRL,
    FR_LESS,        KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          KC_LGUI,        KC_RALT,        FR_UGRV,
                                                                                                    KC_HOME,        KC_APPLICATION, TT(3),          KC_END,
                                                                                                                    KC_SPACE,       KC_PGUP,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_ENTER,       KC_PGDOWN,      KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, FR_GRV,         FR_HASH,        FR_LCBR,        FR_RCBR,        FR_PIPE,        FR_EURO,                                        KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_F12,
    KC_TRANSPARENT, FR_LESS,        FR_GRTR,        FR_LPRN,        FR_RPRN,        FR_EQL,                                                                         KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_TRANSPARENT,
    KC_TRANSPARENT, FR_BSLS,        FR_SLSH,        FR_LBRC,        FR_RBRC,        FR_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_COLN,        KC_KP_1,        KC_KP_2,        KC_KP_3,        FR_PERC,        KC_TRANSPARENT,
    KC_LALT,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,                                                                                                       KC_KP_0,        KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT, FR_SUP2,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // put accents and their caps value on the right hand
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT,                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         LCTL(LSFT(KC_ESCAPE)),LED_LEVEL,                                KC_MY_COMPUTER, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(LSFT(KC_S)),                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(FR_Z),     LCTL(KC_Y),                                     KC_CALCULATOR,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    WEBUSB_PAIR,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
/* Keymap 3: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   #  |   #  |   #  |   #  |   #  |           |   #  |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |   H  |   *  |           |   *  |   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  |------|           |------|   R  |   B  |   G  |   S  |   Z  |        |
 * |--------+------+------+------+------+------|LYRSWT|           |BAKSPC|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |LYRSWT|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// TxBolt over Serial
  [3] = LAYOUT_ergodox(
       KC_BSPC, KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5, 
       KC_NO,   KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
       KC_NO,   KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRANSPARENT,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  STN_A,   STN_O,   KC_NO,

       STN_N6,   STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  KC_NO,
       STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  KC_NO,
                 STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  KC_NO,
       KC_BSPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRANSPARENT,KC_NO,
       KC_NO,
       KC_NO,   STN_E,   STN_U
  ),
};

/*
void alt_code(char *code) { 
  SEND_STRING(SS_DOWN(X_LALT));

  for (size_t i = 0; i < strlen(code); i++)
  {
    switch (code[i]) {
      case '0':
        SEND_STRING(SS_TAP  (X_KP_0));
        break;
      case '1':
        SEND_STRING(SS_TAP  (X_KP_1));
        break;
      case '2':
        SEND_STRING(SS_TAP  (X_KP_2));
        break;
      case '3':
        SEND_STRING(SS_TAP  (X_KP_3));
        break;
      case '4':
        SEND_STRING(SS_TAP  (X_KP_4));
        break;
      case '5':
        SEND_STRING(SS_TAP  (X_KP_5));
        break;
      case '6':
        SEND_STRING(SS_TAP  (X_KP_6));
        break;
      case '7':
        SEND_STRING(SS_TAP  (X_KP_7));
        break;
      case '8':
        SEND_STRING(SS_TAP  (X_KP_8));
        break;
      case '9':
        SEND_STRING(SS_TAP  (X_KP_9));
        break;
    }
  }

  SEND_STRING(SS_UP(X_LALT));
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_0198:
      if (record->event.pressed) {
        alt_code("0198");
      }
      break;
  }
  return true;
}
*/

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT); // or STENO_MODE_GEMINI
};

// Runs constantly in the background, in a loop.
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
    return true;    
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    default:
      break;
  }
  return state;
};