#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  ST_MACRO_0,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_0,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho(
    TD(DANCE_0),    KC_1,           KC_2,           KC_3,           KC_4,                    KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_DELETE,      
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                    KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,            KC_MINUS,       
    KC_UNDS,        KC_A,           KC_S,           KC_D,           KC_F,                    KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,           KC_QUOTE,       
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,                    KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_ALT,   
                                    KC_LEFT_ALT,          LT(1,KC_SPACE), MT(MOD_LCTL, KC_ENTER),  KC_NO,                              KC_NO, KC_RIGHT_SHIFT, LT(2,KC_BSPC),  KC_NO
  ),
  [1] = LAYOUT_ortho(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,                                LALT(LCTL(LSFT(KC_R))),LCTL(KC_W),     KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    LALT(KC_TAB),   KC_PAGE_UP,     LCTL(KC_LEFT),      KC_UP,          LCTL(KC_RIGHT),     TD(DANCE_1),                                    LCTL(LSFT(KC_K)),KC_F2,          LALT(LSFT(KC_DOWN)),LCTL(KC_DOT),   RALT(KC_UP),    LCTL(KC_RBRC),  
    KC_NO,          KC_PGDN,        KC_LEFT,            KC_DOWN,        KC_RIGHT,           TD(DANCE_2),                                    LALT(LCTL(KC_T)),LCTL(LSFT(KC_P)),LCTL(KC_E),     LCTL(LSFT(KC_O)),RALT(KC_DOWN),  LCTL(KC_LBRC),  
    LGUI(KC_L),     KC_NO,          LCTL(LSFT(KC_TAB)), KC_NO,          LCTL(KC_TAB),       KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                    KC_NO,              KC_TRANSPARENT, KC_TRANSPARENT,     KC_NO,                      KC_NO, KC_TRANSPARENT, LCTL(KC_BSPC),  KC_NO
  ),
  [2] = LAYOUT_ortho(
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    TD(DANCE_3),    KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        ST_MACRO_0,                                    KC_EQUAL,       KC_PIPE,        KC_BSLS,        KC_ASTR,        KC_PLUS,        KC_F12,         
    KC_EQUAL,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                       KC_CIRC,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_COLN,        KC_DQUO,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                         KC_NO,          KC_NO,          KC_LABK,        KC_RABK,        KC_QUES,        KC_NO,          
                                    KC_NO,          LCTL(KC_SPACE), KC_TRANSPARENT, KC_NO,                         KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,  KC_NO
  ),
  [3] = LAYOUT_ortho(
    TO(0),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                         KC_BSPC,        KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_PAGE_UP,     KC_NO,          KC_UP,          KC_NO,          KC_NO,                                         KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_NO,          KC_NO,          
    KC_NO,          KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,                                         KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                         KC_1,           KC_2,           KC_3,           KC_DOT,         KC_NO,          KC_NO,          
                                    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                         KC_NO, KC_0,           KC_TRANSPARENT,  KC_NO
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

static tap dance_state[1];

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
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: layer_move(3); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, LCTL(KC_HOME)),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, LCTL(KC_END)),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_GRAVE, KC_TILD),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
