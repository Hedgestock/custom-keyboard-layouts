#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keymap_french.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_steno.h"

enum layers {
  AZER = 0,
  AZERSYM,
  AZERFUN,
  LIERCMS,
  LIERACC,
  LIERSYM,
  TXBOLT,
  MHBASE,
  MHFUN,
};

enum my_keycodes {
  XMAS1 = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// azerty layout because I'm french
  [AZER] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      FR_AMP,         FR_EACU,        FR_DQUO,        FR_APOS,        FR_LPRN,        TT(AZERFUN),                                    TT(AZERFUN),    FR_MINS,        FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,        KC_INSERT,
    KC_TAB,         FR_A,           FR_Z,           KC_E,           KC_R,           KC_T,           FR_DLR,                                         FR_ASTR,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           FR_CIRC,
    LSFT_T(KC_CAPSLOCK),FR_Q,       KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           FR_M,           RSFT_T(KC_CAPSLOCK),
    KC_LCTRL,       FR_W,           KC_X,           KC_C,           KC_V,           KC_B,           TT(AZERSYM),                                    TT(AZERSYM),    KC_N,           FR_COMM,        FR_SCLN,        FR_COLN,        FR_EXLM,        KC_RCTRL,
    TO(LIERCMS),    KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          KC_LGUI,        KC_RALT,        FR_UGRV,
                                                                                                    KC_HOME,        KC_APPLICATION, TO(TXBOLT),     KC_END,
                                                                                                                    KC_SPACE,       KC_PGUP,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_ENTER,       KC_PGDOWN,      KC_ENTER,       KC_SPACE
  ),
  [AZERSYM] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, FR_GRV,         FR_HASH,        FR_LCBR,        FR_RCBR,        FR_PIPE,        FR_EURO,                                        FR_COLN,        KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, FR_PERC,
    KC_TRANSPARENT, FR_LESS,        FR_GRTR,        FR_LPRN,        FR_RPRN,        FR_EQL,                                                                         KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_TRANSPARENT,
    KC_TRANSPARENT, FR_BSLS,        FR_SLSH,        FR_LBRC,        FR_RBRC,        FR_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_0,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_SUP2,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT²
  ),
  // put accents and their caps value on the right hand
  [AZERFUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT,                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         LCTL(LSFT(KC_ESCAPE)),LED_LEVEL,                                KC_MY_COMPUTER, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(LSFT(KC_S)),                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(FR_Z),     LCTL(KC_Y),                                     KC_CALCULATOR,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
// lier layout based on canadian multinligual keyboard
  [LIERCMS] = LAYOUT_ergodox_pretty(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          CA_C,           CA_P,           CA_O,           CA_V,           CA_W,           KC_NO,                                          KC_NO,          CA_J,           CA_D,           CA_U,           CA_X,           CA_M,           KC_NO,
    LSFT_T(KC_CAPSLOCK),CA_L,       CA_I,           CA_E,           CA_R,           KC_NO,                                                                          KC_NO,          CA_T,           CA_S,           CA_A,           CA_N,           LSFT_T(KC_CAPSLOCK),
    KC_NO,          CA_F,           LCA_Y,          CA_Q,           CA_H,           KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          CA_G,           CA_B,           CA_K,           CA_Z,           KC_NO,
    TG(LIERCMS),    KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                                                    KC_NO,          KC_NO,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_NO,          KC_NO,          KC_ENTER,       KC_SPACE
  ),
  [LIERACC] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [LIERSYM] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
/* Keymap 6: TxBolt (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   #  |   #  |   #  |   #  |   #  |           |   #  |   #  |   #  |   #  |   #  |   #  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   S  |   T  |   P  |   H  |   *  |           |   *  |   F  |   P  |   L  |   T  |   D  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   S  |   K  |   W  |   R  |------|           |------|   R  |   B  |   G  |   S  |   Z  |        |
 * |--------+------+------+------+------+------|      |           |BAKSPC|------+------+------+------+------+--------|
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
  [TXBOLT] = LAYOUT_ergodox(
       KC_NO,   KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,      STN_N6,   STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  KC_NO,
       KC_NO,   KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,     STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  KC_NO,
       KC_NO,   KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,                         STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_BSPC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,                          TG(TXBOLT), KC_NO,
                                                    KC_NO,                          KC_NO,
                                  STN_A,   STN_O,   KC_NO,                          KC_NO,    STN_E,   STN_U
  ),
//Monster Hunter
  [MHBASE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      FR_AMP,         FR_EACU,        FR_DQUO,        FR_APOS,        FR_LPRN,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         FR_A,           FR_Z,           KC_E,           KC_R,           FR_MINS,        FR_COMM,/*Opens map in monster hunter world*/   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LSFT,        FR_Q,           KC_S,           KC_D,           KC_F,           FR_EGRV,                                                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LCTRL,       FR_W,           KC_X,           KC_C,           KC_V,           FR_UNDS,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    TG(MHBASE),     KC_NO,          KC_NO,          KC_N,           MO(MHFUN),                                                                                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                        /*          ^^^^           */                               KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                        /* Used in menu navigation */                                               KC_NO,          KC_NO,
                                                                                    KC_SPACE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
  [MHFUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_BOLT);
};

// X_MAS here as a global ?

// Runs constantly in the background, in a loop.
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
    return true;
}

int is_layer_on(uint32_t state, enum layers layer)
{
  return (1 << layer) & state;
}

//uint8_t is O to 255
uint32_t layer_state_set_user(uint32_t state)
{
  // uint8_t layer = biton32(state);
  uint8_t dim = 5;
  uint8_t medium = 50;
  uint8_t bright = 255;

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  if (is_layer_on(state, AZERSYM))
  {
    ergodox_right_led_1_set(medium);
    ergodox_right_led_1_on();
  }
  if (is_layer_on(state, AZERFUN))
  {
    ergodox_right_led_2_set(medium);
    ergodox_right_led_2_on();
  }
  if (is_layer_on(state, LIERCMS))
  {
    ergodox_led_all_set(dim);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
  }
  if (is_layer_on(state, LIERACC))
  {
    ergodox_led_all_set(dim);
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
  }
  return state;
};