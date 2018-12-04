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

#define KC_LOWR LOWER
#define KC_RASE RAISE

#define KC_RST RESET
#define KC_RTOG RGB_TOG
#define KC_RFWD RGB_MOD
#define KC_RREW RGB_RMOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD
#define KC_BTOG BL_TOGG
#define KC_BLVL BL_STEP
#define KC_BRTG BL_BRTG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----+               |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                 Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----+               |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                 H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,RALT,      RCTL, N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/     \----+----+----+-+--+----+----+----'
                       LGUI,LOWR,ENT ,          SPC ,RASE,LALT
  //                  `----+----+----'         `----+----+----+
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     ESC ,EXLM, AT ,HASH,DLR ,PERC,                CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
     GRV , 1  , 2  , 3  , 4  , 5  ,                 6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                LEFT,DOWN, UP ,RGHT,EQL ,    ,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,RALT,      RCTL,    ,    ,    ,    ,MINS,    ,
  //`----+----+----+--+-+----+----+----/     \----+----+----+-+--+----+----+----'
                           ,    ,ENT ,          SPC ,    ,
  //                  `----+----+----'         `----+----+----+
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                 F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,                CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,MUTE,VOLD,VOLU,PGUP,HOME,                    ,    ,    ,LBRC,RBRC,    ,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         ,    ,    ,    ,PGDN,END ,    ,          ,    ,    ,    ,LCBR,RCBR,    ,
  //`----+----+----+--+-+----+----+----/     \----+----+----+-+--+----+----+----,
                           ,    ,    ,              ,    ,
  //                  `----+----+----'         `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.               ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
     RTOG,RFWD,RHUI,RSAI,RVAI,    ,                    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|               |----+----+----+----+----+----|
         ,RREW,RHUD,RSAD,RVAD,    ,                    ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.     ,----|----+----+----+----+----+----|
         ,RST ,    ,    ,    ,    ,    ,          ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/     \----+----+----+-+--+----+----+----,
                           ,    ,    ,              ,    ,
  //                  `----+----+----,         `----+----+----,
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
