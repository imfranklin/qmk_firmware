#include QMK_KEYBOARD_H


enum space65_layers {
    _QWERTY,
    _FUNCTN
};

enum space65_keycodes {
    QWERTY = SAFE_RANGE,
    LOCKER,
    SCRN_CP
};

#define FUNCTN  MO(_FUNCTN)
#define M_MUTE  KC__MUTE
#define M_VOLU  KC__VOLUP
#define M_VOLD  KC__VOLDOWN
#define SCRN_GB SGUI(KC_4)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,---------------------------------------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   \  |   `  | Home |
 * |---------+------+------+------+------+-------------+------+------+------+------+------+------+----------+------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |  Delete  |  End |
 * |------------+------+------+------+------+------+------+------+------+------+------+------+--------------+------|
 * |    Ctrl    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    Return    | PgUp |
 * |----------------+------+------+------+------+------|------+------+------+------+------+----------+------+------|
 * |      Shift     |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Shift  |  Up  | PgDn |
 * |---------+--------+--------+------------------------------------------+--------+--------+----------------------|
 * |   Func  |   Opt  |   Cmd  |                   Space                  |   Cmd  |   Opt  | | Left | Down | Rght |
 * `---------------------------------------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_END,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        FUNCTN,  KC_LALT, KC_LGUI,                   KC_SPC,  KC_SPC,  KC_SPC,           KC_RGUI, KC_RALT,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),
/* Func
 * ,---------------------------------------------------------------------------------------------------------------.
 * | Lock |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |
 * |---------+------+------+------+------+-------------+------+------+------+------+------+------+----------+------|
 * |         |Qwerty|      |      | Reset|      |      |      |      |      |      |      |      |          |      |
 * |------------+------+------+------+------+------+------+------+------+------+------+------+--------------+------|
 * |            |      |      |      |      |      |      |      |      |      |      |      |              | RGBv+|
 * |----------------+------+------+------+------+------|------+------+------+------+------+----------+------+------|
 * |      Mute      | Vol- | Vol+ |ScrnCp|ScrnGb|      |      |      |      |      |      |  RGBtog  | RGBs+| RGBv-|
 * |---------+--------+--------+------------------------------------------+--------+--------+----------------------|
 * |   Ctrl  |   Opt  |   Cmd  |                                          |        |        | | RGBh-| RGBs-| RGBh+|
 * `---------------------------------------------------------------------------------------------------------------'
 */
    [_FUNCTN] = LAYOUT(
        LOCKER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
        _______, QWERTY,  _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          RGB_VAI,
        M_MUTE,  M_MUTE,  M_VOLD,  M_VOLU,  SCRN_CP, SCRN_GB, _______, _______, _______, _______, _______, _______, RGB_TOG,          RGB_SAI, RGB_VAD,
        FUNCTN,  _______, _______,                   _______, _______, _______,          _______, _______,                   RGB_HUD, RGB_SAD, RGB_HUI
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case LOCKER:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_POWER))));
        }
        return false;
        break;
    case SCRN_CP:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI(SS_TAP(X_4)))));
        }
        return false;
        break;
    default:
        break;
    }

    return true;
}

void matrix_init_user(void) {
    /* Nothing, yet. */
}

void matrix_scan_user(void) {
    /* Nothing, yet. */
}

void led_set_user(uint8_t usb_led) {
    /* Nothing, yet. */
}
