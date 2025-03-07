#include QMK_KEYBOARD_H
#include "version.h"


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;


enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho(
        KC_ESCAPE,                KC_1,           KC_2,                   KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,      
        KC_TAB,                   KC_Q,           KC_W,                   KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
        MT(MOD_LSFT, KC_MINUS),   KC_A,           KC_S,                   KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
        KC_LEFT_GUI,              KC_Z,           KC_X,                   KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RALT,   
        KC_LALT,                  LT(2,KC_SPACE), MT(MOD_LCTL, KC_ENTER), KC_NO,                                                                          KC_NO,          KC_RSFT,        LT(1,KC_BSPC),  KC_NO
    ),
    [1] = LAYOUT_ortho(
        KC_MUTE,                  KC_VOLD,        KC_VOLU,                KC_MPRV,        KC_MPLY,        KC_MNXT,                                        LALT(LCTL(LSFT(KC_R))), LCTL(KC_W),         KC_NO,                  KC_NO,              KC_NO,          KC_NO,          
        LALT(KC_TAB),             KC_PAGE_UP,     LCTL(KC_LEFT),          KC_UP,          LCTL(KC_RIGHT), TD(DANCE_0),                                    LCTL(LSFT(KC_K)),       KC_F2,              LALT(LSFT(KC_DOWN)),    LCTL(KC_DOT),       RALT(KC_UP),    LCTL(KC_RBRC),  
        KC_NO,                    KC_PGDN,        KC_LEFT,                KC_DOWN,        KC_RIGHT,       TD(DANCE_1),                                    LALT(LCTL(KC_T)),       LCTL(LSFT(KC_P)),   LCTL(KC_E),             LCTL(LSFT(KC_O)),   RALT(KC_DOWN),  LCTL(KC_LBRC),  
        LGUI(KC_L),               KC_NO,          LCTL(LSFT(KC_TAB)),     KC_NO,          LCTL(KC_TAB),   KC_NO,                                          KC_NO,                  KC_NO,              KC_NO,                  KC_NO,              KC_NO,          KC_NO,          
        KC_TRNS,                  KC_TRNS,        KC_TRNS,                KC_TRNS,                                                                        KC_TRNS,                KC_TRNS,            KC_TRNS,                KC_TRNS
    ),
    [2] = LAYOUT_ortho(
        KC_GRAVE,                 KC_F1,          KC_F2,                  KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
        KC_TILD,                  KC_LCBR,        KC_RCBR,                KC_LBRC,        KC_RBRC,        KC_NO,                                          KC_EQUAL,       KC_PIPE,        KC_BSLS,        KC_ASTR,        KC_PLUS,        KC_F12,         
        KC_EQUAL,                 KC_EXLM,        KC_AT,                  KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_COLN,        KC_DQUO,        
        KC_NO,                    KC_NO,          KC_NO,                  KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_LABK,        KC_RABK,        KC_QUES,        KC_NO,          
        KC_TRNS,                  KC_TRNS,        KC_TRNS,                KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    )
};


// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_TAB:
//             return TAPPING_TERM -50;
//         case LT(2,KC_SPACE):
//             return TAPPING_TERM -30;
//         case MT(MOD_LCTL, KC_ENTER):
//             return TAPPING_TERM -70;
//         case KC_DELETE:
//             return TAPPING_TERM -50;
//         case LT(1,KC_BSPC):
//             return TAPPING_TERM + 30;
//         default:
//             return TAPPING_TERM;
//     }
// }

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}


void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);

        tap_hold->held = 0;
    }
}


#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, LCTL(KC_HOME)),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, LCTL(KC_END)),
};


/*
 * RGB Matrix
 */


extern rgb_config_t rgb_matrix_config;


void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    // [0] = {
    //     {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {0,255,0},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {0,255,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0} 
    // },
    // [1] = {
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
    //     {0,255,0}, {0,255,0}, {0,0,255},   {0,0,255},   {0,0,255},   {0,255,0},
    //     {255,0,0}, {0,255,0}, {0,0,255},   {0,0,255},   {0,0,255},   {0,255,0},
    //     {0,255,0}, {255,0,0}, {0,255,0}, {255,0,0}, {0,255,0}, {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
    //     {0,255,0}, {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255},   {0,0,255},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255},   {0,0,255},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}
    // },
    // [2] = {
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},
    //     {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
    //     {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
    //     {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {255,0,0},
    //     {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},   {0,0,255},
    //     {255,0,0}, {255,0,0}, {0,0,255},   {0,0,255},   {0,0,255},   {255,0,0},
    //     {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}
    // }
    [0] = {
        {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
        // {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {0,255,0},
        // {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        // {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        // {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {0,255,0},
        // {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0} 
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} 
    },
    [1] = {
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        {0,255,0}, {0,255,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,0},
        {255,0,0}, {0,255,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,0},
        {0,255,0}, {255,0,0}, {0,255,0}, {255,0,0}, {0,255,0}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
        {0,255,0}, {0,255,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}, {0,0,255},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}, {0,0,255}, {0,0,255},
        {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}
    },
    [2] = {
        {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0},
        
        {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0}, {255,0,0},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {255,0,0},
        {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255},
        {255,0,0}, {255,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {255,0,0},
        {0,255,0}, {0,255,0}, {0,255,0}, {0,255,0}
    }
};


void set_layer_color(int layer, uint8_t led_min, uint8_t led_max) {
//    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//        rgb_t rgb = {
//            .r = pgm_read_byte(&ledmap[layer][i][0]),
//            .g = pgm_read_byte(&ledmap[layer][i][1]),
//            .b = pgm_read_byte(&ledmap[layer][i][2]),
//        };
//        if (!rgb.r && !rgb.g && !rgb.b) {
//            rgb_matrix_set_color( i, 0, 0, 0 );
//        } else {
//            rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
//        }
//    }
}


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0, led_min, led_max);
            break;
        case 1:
            set_layer_color(1, led_min, led_max);
            break;
        case 2:
            set_layer_color(2, led_min, led_max);
            break;
        default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

