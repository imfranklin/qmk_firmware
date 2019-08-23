#include QMK_KEYBOARD_H


enum pearl_layers {
    _QWERTY,
    _SPACE,
    _SHIFT,
    _MENUS,
    _FUNCT,
    _ADJUST
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    MENUS,
    FUNCT,
    LOCKER,
    SCRN_CP
};

#define SPACE   LT(_SPACE, KC_SPACE)
#define SHIFT   MO(_SHIFT)
#define M_MUTE  KC__MUTE
#define M_VOLU  KC__VOLUP
#define M_VOLD  KC__VOLDOWN
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
#define CMD_S4  SGUI(KC_4)
#define CMD_BL  LGUI(KC_LBRC)
#define CMD_BR  LGUI(KC_RBRC)
#define CMD_CBL SGUI(KC_LBRC)
#define CMD_CBR SGUI(KC_RCBR)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,------------------------------------------------------------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   -  | Bksp |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |   Ctrl  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   Enter  |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |    Shift   |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Fn1  |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |  Opt |   Cmd  |                   Space                  |   Fn2  |  Fn3 |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_spacebar(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SHIFT,
        KC_LALT, KC_LGUI, SPACE,   MENUS,   FUNCT
    ),
/* Space
 * ,------------------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   `  |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |         |   !  |   @  |   #  |   $  |   %  |   &  |   *  |   [  |   ]  |   '  |          |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |            |      |      |      |      |      |      |      |      |   =  |   \  |       |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |      |        |                                          |        |      |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_SPACE] = LAYOUT_spacebar(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, KC_GRV,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL,  KC_BSLS, _______,
        _______, _______, _______, _______, _______
    ),
/* Shift
 * ,------------------------------------------------------------------------------------------.
 * |   `  |   '  |   "  |   (  |   )  |      |      |      |      |  Up  |      |      |  Esc |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |         |   [  |   ]  |   {  |   }  |   \  |      |      | Left | Right|   |  |          |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |            | Home | PgDn | PgUp |  End |      |      |      | Down |   =  |   '  |       |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |      |        |                                          |        |      |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_SHIFT] = LAYOUT_spacebar(
        KC_GRV,  KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_UP,   _______, _______, KC_ESC,
        _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, _______, _______, KC_LEFT, KC_RGHT, KC_PIPE, _______,
        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, KC_DOWN, KC_EQL,  KC_QUOT, _______,
        _______, _______, _______, _______, _______
    ),
/* Menu
 * ,------------------------------------------------------------------------------------------.
 * |  Esc | Cmd+1| Cmd+2| Cmd+3| Cmd+4| Cmd+5| Cmd+6| Cmd+7| Cmd+8| Cmd+9| Cmd+0|      |      |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |         | CMD+[| CMD+]| CMD+{| CMD+}|      |      |      |      |      |      |          |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |            |      |      |ScrnCp|ScrnGb|      |      |      |      |      |      |       |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |      |        |                                          |        |      |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_MENUS] = LAYOUT_spacebar(
        KC_ESC,  CMD_1,   CMD_2,   CMD_3,   CMD_4,   CMD_5,   CMD_6,   CMD_7,   CMD_8,   CMD_9,   CMD_0,   _______, _______,
        _______, CMD_BL,  CMD_BR,  CMD_CBL, CMD_CBR, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, SCRN_CP, CMD_S4,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ),
/* Function
 * ,------------------------------------------------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      | Lock |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |         |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |          |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |            |  F9  |  F10 |  F11 |  F12 |      |      | Mute | Vol- | Vol+ |      |       |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |      |        |                                          |        |      |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_FUNCT] = LAYOUT_spacebar(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, LOCKER,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, M_MUTE,  M_VOLD,  M_VOLU,  _______, _______,
        _______, _______, _______, _______, _______
    ),
/* Adjust
 * ,------------------------------------------------------------------------------------------.
 * |      |Qwerty|      |      | Reset|      |      |      |      |      |      |      |      |
 * |---------+------+------+------+------+-------------+------+------+------+------+----------|
 * |         |      |      |      |      |      |      |      |      |      |      |          |
 * |------------+------+------+------+------+------|------+------+------+------+------+-------|
 * |            |      |      |      |      |      |      |      |      |      |      |       |
 * |-------+------+--------+------------------------------------------+--------+--------------|
 * |       |      |        |                                          |        |      |       |
 * `------------------------------------------------------------------------------------------'
 */
    [_ADJUST] = LAYOUT_spacebar(
        _______, QWERTY,  _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        BL_TOGG, BL_STEP, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
        _______, _______, _______, _______, _______
    ),
};

/*
 *
 * @TODO: disable CONSOLE_ENABLE, NKRO_ENABLE, SLEEP_LED_ENABLE
 *
 * N.B. Temporarily only lights during ADJUST layer usage due to dead LED
 *
 * PD0: Num lock
 * PD1: Caps lock
 * PD6: Scroll lock
 *
 * @TODO: check for rgblight_config.enable or backlight_config.enable before
 * lighting up layer indicators?
 */
/*
uint32_t layer_state_set_kb(uint32_t state) {
    PORTD &= ~(1 << PD0);
    PORTD &= ~(1 << PD1);
    PORTD &= ~(1 << PD6);

    if (state & (1 << _SHIFT)) {
        PORTD |= (1 << PD0);
        PORTD |= (1 << PD6);
    }

    if (state & (1 << _SPACE)) {
        PORTD |= (1 << PD0);
    }

    if (state & (1 << _MENUS)) {
        PORTD |= (1 << PD1);
    }

    if (state & (1 << _FUNCT)) {
        PORTD |= (1 << PD6);
    }

    if (state & (1 << _ADJUST)) {
        PORTD |= (1 << PD0);
        PORTD |= (1 << PD1);
        PORTD |= (1 << PD6);
    }

    return state;
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case MENUS:
        if (record->event.pressed) {
            layer_on(_MENUS);
            update_tri_layer(_MENUS, _FUNCT, _ADJUST);
        } else {
            layer_off(_MENUS);
            update_tri_layer(_MENUS, _FUNCT, _ADJUST);
        }
        return false;
        break;
    case FUNCT:
        if (record->event.pressed) {
            layer_on(_FUNCT);
            update_tri_layer(_MENUS, _FUNCT, _ADJUST);
        } else {
            layer_off(_FUNCT);
            update_tri_layer(_MENUS, _FUNCT, _ADJUST);
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
