#include "planck.h"
#include "action_layer.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _KEYCMD,
    _ADJUST
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    LOCKER,
    SCRN_CP
};

#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define KEYCMD  MO(_KEYCMD)
#define M_MUTE  KC__MUTE
#define M_VOLU  KC__VOLUP
#define M_VOLD  KC__VOLDOWN
#define CMD_BL  LGUI(KC_LBRC)
#define CMD_BR  LGUI(KC_RBRC)
#define CMD_CBL SGUI(KC_LBRC)
#define CMD_CBR SGUI(KC_RCBR)
#define CMD_S4  SGUI(KC_4)
#define CMD_1   LGUI(KC_1)
#define CMD_2   LGUI(KC_2)
#define CMD_3   LGUI(KC_3)
#define CMD_4   LGUI(KC_4)
#define CMD_5   LGUI(KC_5)
#define CMD_6   LGUI(KC_6)
#define CMD_7   LGUI(KC_7)
#define CMD_8   LGUI(KC_8)
#define CMD_9   LGUI(KC_9)
#define CMD_0   LGUI(KC_0)
#define CMD_Z   LGUI(KC_Z)
#define CMD_X   LGUI(KC_X)
#define CMD_C   LGUI(KC_C)
#define CMD_V   LGUI(KC_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |KeyCMD| Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_ESC,  KEYCMD,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   _  |   +  |   ~  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CMD+Z| CMD+X| CMD+C| CMD+V|      |      |   (  |   )  |   |  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |Pg Dn |Pg Up | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_UNDS, KC_PLUS, KC_TILD,
    _______, CMD_Z,   CMD_X,   CMD_C,   CMD_V,   _______, _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   {  |   }  |   [  |   ]  |   `  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CMD+Z| CMD+X| CMD+C| CMD+V|      |      |   (  |   )  |   |  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,
    _______, CMD_Z,   CMD_X,   CMD_C,   CMD_V,   _______, _______, KC_LPRN, KC_RPRN, KC_PIPE, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Key Commands
 * ,-----------------------------------------------------------------------------------.
 * |      | CMD+1| CMD+2| CMD+3| CMD+4| CMD+5| CMD+6| CMD+7| CMD+8| CMD+9| CMD+0|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |ScrnGb|ScrnCp|      |      | CMD+{| CMD+}| CMD+[| CMD+]|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | CMD+Z| CMD+X| CMD+C| CMD+V|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lock |      |      |      |      |             |      | Mute | Vol- | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_KEYCMD] = LAYOUT_planck_grid(
    _______, CMD_1,   CMD_2,   CMD_3,   CMD_4,   CMD_5,   CMD_6,   CMD_7,   CMD_8,   CMD_9,   CMD_0,   _______,
    _______, _______, _______, CMD_S4,  SCRN_CP, _______, _______, CMD_CBL, CMD_CBR, CMD_BL,  CMD_BR,  _______,
    _______, CMD_Z,   CMD_X,   CMD_C,   CMD_V,   _______, _______, _______, _______, _______, _______, _______,
    LOCKER,  _______, _______, _______, _______, _______, _______, _______, M_MUTE,  M_VOLD,  M_VOLU,  _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty|      |      | Reset|      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QWERTY,  _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE
    float plover_song[][2]    = SONG(PLOVER_SOUND);
    float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    case LOCKER:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_POWER))));
        }
        return false;
    case SCRN_CP:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI(SS_TAP(X_4)))));
        }
        return false;
    }

    return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
