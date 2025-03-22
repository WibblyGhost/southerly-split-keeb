#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    // RGB_SLD,
    ST_MACRO_0 = SAFE_RANGE,
};

enum tap_dance_codes {
    DANCE_0,
    DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_voyager(
        KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,      
        KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
        MT(MOD_LSFT, KC_MINUS), KC_A,   KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
        KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RALT,   
        KC_LALT,        LT(1,KC_SPACE), MT(MOD_LCTL, KC_ENTER), KC_NO,                                                                  KC_NO,          KC_RSFT,        LT(2,KC_BSPC),  KC_NO
    ),
    [1] = LAYOUT_voyager(
        KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
        KC_NO,          KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        ST_MACRO_0,                                     KC_GRAVE,       KC_TILD,        KC_EQUAL,       KC_PLUS,        KC_COLN,        KC_PIPE,        
        KC_UNDS,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DQUO,        
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_LABK,        KC_RABK,        KC_QUES,        KC_F12,         
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        LCTL(KC_BSPC),  KC_TRNS
    ),
    [2] = LAYOUT_voyager(
        KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_MPRV,        KC_MPLY,        KC_MNXT,                                        LALT(LCTL(LSFT(KC_R))), LCTL(KC_W), KC_NO,      KC_NO,          KC_NO,          KC_NO,          
        KC_NO,          KC_PGUP,        LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), TD(DANCE_0),                                    LCTL(LSFT(KC_K)), KC_F2,        LALT(LSFT(KC_DOWN)),LCTL(KC_DOT), RALT(KC_UP),  LCTL(KC_RBRC),  
        KC_NO,          KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       TD(DANCE_1),                                    LALT(LCTL(KC_T)), LCTL(LSFT(KC_P)), LCTL(KC_E), LCTL(LSFT(KC_O)), RALT(KC_DOWN), LCTL(KC_LBRC),  
        LGUI(KC_L),     KC_NO,          LCTL(LSFT(KC_TAB)), KC_MS_BTN4, LCTL(KC_TAB),   KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_APP, 
        KC_TRNS,        KC_LSFT,        KC_LSFT,        KC_TRNS,                                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB:
            return TAPPING_TERM -50;
        case LT(1,KC_SPACE):
            return TAPPING_TERM -30;
        case MT(MOD_LCTL, KC_ENTER):
            return TAPPING_TERM -70;
        case KC_DELETE:
            return TAPPING_TERM -50;
        case LT(2,KC_BSPC):
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}

// extern rgb_config_t rgb_matrix_config;

// void keyboard_post_init_user(void) {
//     rgb_matrix_enable();
// }

// const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
//     [0] = {
//         {240,255,234}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {240,255,234}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {240,255,234}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234},

//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {240,255,234},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {240,255,234},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}
//     },

//     [1] = {
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {215,104,248}, {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},
//         {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234},

//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},
//         {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},   {0,188,255},
//         {215,104,248}, {215,104,248}, {0,188,255},   {0,188,255},   {0,188,255},   {215,104,248},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}
//     },

//     [2] = {
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234},
//         {215,104,248}, {240,255,234}, {0,188,255},   {0,188,255},   {0,188,255},   {240,255,234},
//         {215,104,248}, {240,255,234}, {0,188,255},   {0,188,255},   {0,188,255},   {240,255,234},
//         {240,255,234}, {215,104,248}, {240,255,234}, {240,255,234}, {240,255,234}, {215,104,248},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234},

//         {240,255,234}, {240,255,234}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}, {0,188,255},   {0,188,255},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}, {0,188,255},   {0,188,255},
//         {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {215,104,248}, {0,188,255},
//         {240,255,234}, {240,255,234}, {240,255,234}, {240,255,234}
//     },
// };

// void set_layer_color(int layer) {
//     for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//         HSV hsv = {
//         .h = pgm_read_byte(&ledmap[layer][i][0]),
//         .s = pgm_read_byte(&ledmap[layer][i][1]),
//         .v = pgm_read_byte(&ledmap[layer][i][2]),
//         };
//         if (!hsv.h && !hsv.s && !hsv.v) {
//             rgb_matrix_set_color( i, 0, 0, 0 );
//         } else {
//             RGB rgb = hsv_to_rgb( hsv );
//             float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//             rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
//         }
//     }
// }

// bool rgb_matrix_indicators_user(void) {
//     // TODO: Replace
//     // if (keyboard_config.disable_layer_led) { return false; }
//     switch (biton32(layer_state)) {
//         case 0:
//             set_layer_color(0);
//             break;
//         case 1:
//             set_layer_color(1);
//             break;
//         case 2:
//             set_layer_color(2);
//             break;
//         default:
//             if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
//             break;
//     }
//     return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // For some reason, the macro was overriding the KC_NO
        case KC_NO:
            if (record->event.pressed) return false;
            break;
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
            }
            break;

        // case RGB_SLD:
        //     if (record->event.pressed) rgblight_mode(1);
        //     return false;
    }
    return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_HOME);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_HOME); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_HOME)); break;
        case DOUBLE_TAP: register_code16(KC_HOME); register_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HOME); register_code16(KC_HOME);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_HOME); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_HOME)); break;
        case DOUBLE_TAP: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_END);
        tap_code16(KC_END);
        tap_code16(KC_END);
    }
    if(state->count > 3) {
        tap_code16(KC_END);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_END); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: register_code16(KC_END); register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_END); register_code16(KC_END);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_END); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_END); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
