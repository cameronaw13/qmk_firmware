#include QMK_KEYBOARD_H

#define _____ KC_NO
#define vvvvv KC_TRNS

enum {
    MNG_LYR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Qwerty Layer
    [0] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_ESC,   TD(MNG_LYR),
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,            KC_RBRC,  KC_BSLS,
        TT(2),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            _____,    KC_ENT,
        KC_LSFT,  _____,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    KC_RSFT,  _____,
        KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,                       KC_BSPC,            KC_RALT,  TT(2),    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_APP
    ),
    // Base Colemak-DH Layer
    [1] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_ESC,   TD(MNG_LYR),
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,            KC_RBRC,  KC_BSLS,
        TT(2),    KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            _____,    KC_ENT,
        KC_LSFT,  _____,    KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    KC_RSFT,  _____,
        KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,                       KC_BSPC,            KC_RALT,  TT(2),    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_APP
    ),
    // Function Layer
    [2] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PAUS,  KC_SCRL,
        KC_NUM,   KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_PSLS,  KC_BTN3,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_MPLY,  KC_MPRV,            KC_MNXT,  _____,
        vvvvv,    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_PAST,  _____,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  KC_WH_U,            _____,    KC_INS,
        vvvvv,    _____,    KC_P1,    KC_P2,    KC_P3,    KC_P0,    KC_PCMM,  _____,    _____,    KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_PGUP,  vvvvv,    _____,
        vvvvv,    vvvvv,    vvvvv,              KC_ENT,                       KC_DEL,             vvvvv,    vvvvv,    KC_HOME,  KC_PGDN,  KC_END,   vvvvv
    ),
    // Extra Layer
    [3] = LAYOUT_60_ansi_split_bs_rshift_space(
        RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,  RGB_M_R,  RGB_M_SN, RGB_M_X,  RGB_M_TW, _____,    _____,    _____,    TG(3),
        _____,    RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  RGB_M_B,  RGB_M_SW, RGB_M_K,  RGB_M_G,  _____,    _____,              _____,    _____,
        _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,              _____,    _____,
        _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,    _____,
        _____,    _____,    _____,              _____,                        _____,              _____,    _____,    _____,    _____,    _____,    _____
    )
};

void manage_layer(tap_dance_state_t *state, void *user_data) {
    // One tap for Scroll Lock, two to change default layout, three to enable the extra layer
    switch(state->count) {
        case 1:
            tap_code(KC_PSCR);
            break;
        case 2:
            if(layer_state_is(0)) {
                layer_move(1);
            } else {
                layer_move(0);
            }
            break;
        case 3:
            layer_on(3);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [MNG_LYR] = ACTION_TAP_DANCE_FN(manage_layer)
};

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
