// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTRL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LGUI, MO(1), KC_SPC,               KC_ENT,  KC_BSPC,  MO(2)
    ),
    [1] = LAYOUT(
        KC_F11,   KC_F1,     KC_F2,    KC_F3,       KC_F4,       KC_F5,                        KC_F6,  KC_F7,   KC_F8,    KC_F9,    KC_F11,   KC_F12,
        KC_TRNS,  S(KC_1),   S(KC_2),  KC_LBRC,     KC_RBRC,     S(KC_BSLS),                   KC_P7,  KC_P8,   KC_P9,    KC_PPLS,  KC_PMNS,  KC_UP,
        KC_TRNS,  S(KC_4),   S(KC_4),  S(KC_9),     S(KC_0),     S(KC_UNDS),                   KC_P4,  KC_P5,   KC_P6,    KC_PCMM,  KC_PAST,  KC_DOWN,
        KC_TRNS,  S(KC_5),   S(KC_6),  S(KC_LBRC),  S(KC_RBRC),  S(KC_GRV),                    KC_P1,  KC_P2,   KC_P3,    KC_EQL,   KC_LEFT,  KC_RGHT,
                                                         KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,     KC_TRNS
    ),
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
                       'L', 'L', 'L',  'R', 'R', 'R'
    );

const rgblight_segment_t PROGMEM layerc[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_CORAL});
const rgblight_segment_t PROGMEM layer1[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_GREEN});
const rgblight_segment_t PROGMEM layer2[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_BLUE});
const rgblight_segment_t PROGMEM layer3[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_MAGENTA});
const rgblight_segment_t PROGMEM layer4[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_ORANGE});
const rgblight_segment_t PROGMEM layer5[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});
const rgblight_segment_t PROGMEM layer6[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_CYAN});
const rgblight_segment_t PROGMEM layer7[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(layerc, layer1, layer2, layer3, layer4, layer5, layer6, layer7);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
    rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_VAL, RGBLIGHT_DEFAULT_VAL, RGBLIGHT_DEFAULT_VAL);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 7))
        rgblight_sethsv_noeeprom(rgblight_get_val(), rgblight_get_val(), rgblight_get_val());
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    //rgblight_set_layer_state(7, layer_state_cmp(state, 7));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 7))
        rgblight_sethsv_noeeprom(rgblight_get_val(), rgblight_get_val(), rgblight_get_val());
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    //rgblight_set_layer_state(7, layer_state_cmp(state, 7));
    return state;
}

void housekeeping_task_user(void) {
    static uint8_t HUE;
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 7:
            rgblight_sethsv_noeeprom(HUE, 255, rgblight_get_val());
            HUE++;
            break;
    }
}