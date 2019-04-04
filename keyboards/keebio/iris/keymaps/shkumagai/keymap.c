#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS

#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_RST RESET

#define KC_ALTBS LALT_T(KC_BSPACE)      // act as LALT   when held, as BSPACE when tapped
#define KC_CTEND LCTL_T(KC_END)         // act as LCTL   when held, as END    when tapped
#define KC_SFENT LSFT_T(KC_ENTER)       // act as LSHIFT when held, as ENTER  when tapped
#define KC_SFSPC LSFT_T(KC_SPACE)       // act as LSHIFT when held, as SPACE  when tapped

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  // ,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
       ESC ,  1  ,  2  ,  3  ,  4  ,  5  ,                    6  ,  7  ,  8  ,  9  ,  0  ,MINUS,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
       TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,                    Y  ,  U  ,  I  ,  O  ,  P  , BSLS,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
       LCTL,  A  ,  S  ,  D  ,  F  ,  G  ,                    H  ,  J  ,  K  ,  L  , SCLN,QUOTE,
  // |-----+-----+-----+-----+-----+-----+-----.     ,-----|-----+-----+-----+-----+-----+-----|
       LGUI,  Z  ,  X  ,  C  ,  V  ,  B  , HOME,      CTEND,  N  ,  M  ,COMMA, DOT ,SLASH, RALT,
  // `-----+-----+-----+-----+-----+-----+-----+     +-----+-----+-----+-----+-----+-----+-----'
                              ALTBS,LOWER,SFSPC,      SFENT,RAISE, BSPC
  //                         `-----+-----+-----'     `-----+-----+-----'
  ),

  [_LOWER] = LAYOUT_kc(
  // ,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
           , EXLM,  AT , HASH, DLR , PERC,                   CIRC, AMPR, ASTR, LPRN, RPRN,     ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           ,GRAVE,MINUS,EQUAL, BSLS,     ,                       , PGDN, PGUP, LBRC, RBRC,     ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           ,TILDE, UNDS, PLUS, PIPE,     ,                   LEFT, DOWN,  UP ,RIGHT,     ,     ,
  // |-----+-----+-----+-----+-----+-----+-----.     ,-----|-----+-----+-----+-----+-----+-----|
           ,     ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,     ,
  // `-----+-----+-----+-----+-----+-----+-----+     +-----+-----+-----+-----+-----+-----+-----'
                                   ,     ,     ,           ,     ,
  //                         `-----+-----+-----'     `-----+-----+-----'
  ),

  [_RAISE] = LAYOUT_kc(
  // ,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
       F12 ,  F1 ,  F2 ,  F3 ,  F4 ,  F5 ,                    F6 ,  F7 ,  F8 ,  F9 , F10 , F11 ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           , CAPW, CPYW, CAPP, CPYP,     ,                       ,  7  ,  8  ,  9  ,     ,     ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           , MUTE, VOLD, VOLU,     ,     ,                       ,  4  ,  5  ,  6  ,     ,     ,
  // |-----+-----+-----+-----+-----+-----+-----.     ,-----|-----+-----+-----+-----+-----+-----|
           ,     ,     ,     ,     ,     ,     ,           ,  0  ,  1  ,  2  ,  3  ,     ,     ,
  // `-----+-----+-----+-----+-----+-----+-----+     +-----+-----+-----+-----+-----+-----+-----'
                                   ,     ,     ,           ,     ,
  //                         `-----+-----+-----'     `-----+-----+-----'
  ),

  [_ADJUST] = LAYOUT_kc(
  // ,-----+-----+-----+-----+-----+-----.                 ,-----+-----+-----+-----+-----+-----.
           ,     ,     ,     ,     ,     ,                       ,     ,     ,     ,     ,     ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           ,     ,     ,     ,     ,     ,                       ,     ,     ,     ,     ,     ,
  // |-----+-----+-----+-----+-----+-----+                 |-----+-----+-----+-----+-----+-----|
           ,     ,     ,     , RST ,     ,                       ,     ,     ,     ,     ,     ,
  // |-----+-----+-----+-----+-----+-----+-----.     ,-----|-----+-----+-----+-----+-----+-----|
           ,     ,     ,     ,     ,     ,     ,           ,     ,     ,     ,     ,     ,     ,
  // `-----+-----+-----+-----+-----+-----+-----+     +-----+-----+-----+-----+-----+-----+-----'
                                   ,     ,     ,           ,     ,
  //                         `-----+-----+-----'     `-----+-----+-----'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
