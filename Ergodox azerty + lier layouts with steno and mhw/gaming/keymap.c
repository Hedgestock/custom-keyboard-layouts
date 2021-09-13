#include "hedgestock.h"
#include "action_layer.h"
#include "keymap_french.h"

enum layers {
  AZER = 0,
  AZERSYM,
  AZERFUN,

  PS2,
  PS2FUN,

  MHBASE,
  MHFUN,
};

enum my_keycodes {
  XMAS = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// azerty layout because I'm french
  [AZER] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      FR_AMP,         FR_EACU,        FR_DQUO,        FR_APOS,        FR_LPRN,        TT(AZERFUN),                                    TT(AZERFUN),    FR_MINS,        FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,        KC_INSERT,
    KC_TAB,         FR_A,           FR_Z,           FR_E,           FR_R,           FR_T,           FR_DLR,                                         FR_ASTR,        FR_Y,           FR_U,           FR_I,           FR_O,           FR_P,           FR_CIRC,
    LSFT_T(KC_CAPSLOCK),FR_Q,       FR_S,           FR_D,           FR_F,           FR_G,                                                                           FR_H,           FR_J,           FR_K,           FR_L,           FR_M,           RSFT_T(KC_CAPSLOCK),
    KC_LCTRL,       FR_W,           FR_X,           FR_C,           FR_V,           FR_B,           TT(AZERSYM),                                    TT(AZERSYM),    FR_N,           FR_COMM,        FR_SCLN,        FR_COLN,        FR_EXLM,        KC_RCTRL,
    TO(PS2),        KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          KC_RGUI,        KC_RALT,        FR_UGRV,
                                                                                                    KC_HOME,        TO(MHBASE),     TO(PS2),     KC_END,
                                                                                                                    KC_SPACE,       KC_PGUP,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_ENTER,       KC_PGDOWN,      KC_ENTER,       KC_SPACE
  ),
  [AZERSYM] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, FR_GRV,         FR_HASH,        FR_LCBR,        FR_RCBR,        FR_PIPE,        FR_EURO,                                        FR_COLN,        KC_KP_MINUS,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, FR_PERC,
    KC_NUMLOCK,     FR_LESS,        FR_GRTR,        FR_LPRN,        FR_RPRN,        FR_EQL,                                                                         KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_NUMLOCK,
    KC_TRANSPARENT, FR_BSLS,        FR_SLSH,        FR_LBRC,        FR_RBRC,        FR_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_0,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_SUP2,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  // rework this layer
  [AZERFUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT,                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         LCTL(LSFT(KC_ESCAPE)),LED_LEVEL,                                KC_MY_COMPUTER, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(LSFT(KC_S)),                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_S),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(FR_Z),     LCTL(KC_Y),                                     KC_CALCULATOR,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, XMAS,           KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  
//PlanetSide 2
  [PS2] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_7,                                           KC_NO,          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_NO,
    KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_KP_PLUS,     KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_NO,
    KC_LCTRL,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_8,                                           KC_NO,          KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_0,        KC_NO,
    KC_LALT,        KC_H,           KC_J,           KC_K,           KC_L,                                                                                                           KC_DOWN,        KC_UP,          KC_RGUI,        KC_RALT,        KC_NO,
                                                                                                    KC_N,           TO(MHBASE),     TG(PS2),        KC_NO,
                                                                                                                    KC_PGUP,        KC_NO,
                                                                                    KC_SPACE,       MO(PS2FUN),     KC_PGDOWN,      KC_NO,          KC_NO,          KC_NO
  ),
  [PS2FUN] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    FR_Y,           FR_U,           FR_I,           FR_O,           FR_P,                                                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

//Monster Hunter
  [MHBASE] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_6,           KC_M,/*Opens map in monster hunter world*/      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_7,                                                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_LCTRL,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_8,           KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_N,           MO(MHFUN),                                                                                                      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                        /*          ^^^^           */                               KC_NO,          TG(MHBASE),     TO(PS2),        KC_NO,
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

// uint8_t is O to 255
// I'd greatly benefit from some self reflection here for calling ergodox_right_led_X_on()
uint32_t layer_state_set_user(uint32_t state)
{
  // uint8_t layer = biton32(state);
  uint8_t dim = 5;
  uint8_t medium = 50;
  // uint8_t bright = 255;

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

  if (is_layer_on(state, PS2))
  { 
    ergodox_right_led_2_set(dim);
    ergodox_right_led_2_on();
  }
  if (is_layer_on(state, PS2FUN))
  {
    ergodox_right_led_1_set(dim);
    ergodox_right_led_1_on();
  }


  if (is_layer_on(state, MHBASE))
  {
    ergodox_right_led_1_set(dim);
    ergodox_right_led_1_on();
  }
  if (is_layer_on(state, MHFUN))
  {
    ergodox_right_led_2_set(dim);
    ergodox_right_led_2_on();
  }
  return state;
};
