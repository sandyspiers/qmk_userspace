// SPDX-License-Identifier: GPL-2.0-or-later
// Sofle v2.1 (ProMicro RP2040). Layer docs: sofle.md in the userspace root.
#include QMK_KEYBOARD_H

// ============================================================
// Layer Definitions
// ============================================================
enum layers {
    BASE,
    SYM,
    NAV,
    FN,
    MACRO,
};

// ============================================================
// Custom Keycodes – floating runners
// Each sends tmux's float sequence: M-f, then the tool's letter.
// ============================================================
enum custom_keycodes {
    FL_LGIT = SAFE_RANGE,
    FL_BTOP,
    FL_YAZI,
    FL_TAIL,
    FL_SHEL,
    FL_KEYS,
    FL_PROJ,
};

// ============================================================
// Tap Dance
// ============================================================
enum tap_dances {
    TD_MEDIA,
};

// Left encoder press: 1 tap = play/pause, 2 taps = next track
tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
};

// ============================================================
// Key Aliases
// ============================================================

// The only tap-hold key on the board: tap = Esc, hold = NAV
#define ESC_NAV LT(NAV, KC_ESC)

// One-shot mods and layers: tap for the next key, hold for several
#define OS_ALT  OSM(MOD_LALT)
#define OS_CTL  OSM(MOD_LCTL)
#define OS_SFT  OSM(MOD_LSFT)
#define OS_SYM  OSL(SYM)
#define OS_FN   OSL(FN)
#define OS_MAC  OSL(MACRO)

// Encoder presses
#define ENC_L   TD(TD_MEDIA)
#define ENC_R   LAG(KC_K)       // Win+Alt+K: Windows 11 mic mute

// Macros
#define SHOT    LSG(KC_S)       // Win+Shift+S: screenshot an area
#define WT_COPY C(S(KC_C))      // Windows Terminal copy
#define WT_PSTE C(S(KC_V))      // Windows Terminal paste

// ============================================================
// Keymap
// ============================================================

/*
 * Layout reference (LAYOUT):
 *
 *   Row 0 (12): `  1  2  3  4  5                    6  7  8  9  0  -
 *   Row 1 (12): ⇥  Q  W  E  R  T                    Y  U  I  O  P  =
 *   Row 2 (12): ⎋  A  S  D  F  G                    H  J  K  L  ;  '
 *   Row 3 (14): ⌥  Z  X  C  V  B  [encL]  [encR]    N  M  ,  .  /  SYM
 *   Thumbs(10): L out → in (5)                      R in → out (5)
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  BASE – QWERTY, no home row mods; one-shot mods on thumbs and corners        │
// │                                                                              │
// │  Left thumb : GUI  MACRO*  Ctrl*  Shift*  Space                              │
// │  Right thumb: Enter  Bspc  Ctrl*  Del  F*                                    │
// └──────────────────────────────────────────────────────────────────────────────┘
[BASE] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    ESC_NAV, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    OS_ALT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ENC_L,     ENC_R,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OS_SYM,
                      KC_LGUI, OS_MAC,  OS_CTL,  OS_SFT,  KC_SPC,    KC_ENT,  KC_BSPC, OS_CTL,  KC_DEL,  OS_FN
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  SYM – mirrored pairs  (tap or hold the right bottom corner)                 │
// │                                                                              │
// │  Home row: \ { [ ( <   > ) ] } |   – same bracket per finger on both hands   │
// │  Top row : shifted number row, one row down                                  │
// │  Bottom  : _ - = +  (reachable while holding SYM)                            │
// └──────────────────────────────────────────────────────────────────────────────┘
[SYM] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, KC_GRV,  XXXXXXX,
    XXXXXXX, KC_BSLS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK,                     KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  NAV – right hand only; column = direction, row = distance  (hold Esc)       │
// │                                                                              │
// │  Top : Home PgDn PgUp End                                                    │
// │  Home: ←    ↓    ↑    →                                                      │
// │  Mods come from the thumbs (Shift* selects, Ctrl* jumps words).              │
// └──────────────────────────────────────────────────────────────────────────────┘
[NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  FN – Fn and Floating  (tap or hold the right outer thumb)                   │
// │                                                                              │
// │  Number row: F-keys under their digits (F11 / F12 on the outer columns)      │
// │  Letters   : floating tmux tools on their initial letter                     │
// │              t tail  y yazi  p project  s shell  g git  k keys  b btop       │
// └──────────────────────────────────────────────────────────────────────────────┘
[FN] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FL_TAIL,                     FL_YAZI, XXXXXXX, XXXXXXX, XXXXXXX, FL_PROJ, XXXXXXX,
    XXXXXXX, XXXXXXX, FL_SHEL, XXXXXXX, XXXXXXX, FL_LGIT,                     XXXXXXX, XXXXXXX, FL_KEYS, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FL_BTOP, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  MACRO – each macro on its mnemonic key  (tap or hold left thumb 2)          │
// │                                                                              │
// │  Caps pos = Caps Word   S = screenshot   C / V = Windows Terminal copy/paste │
// └──────────────────────────────────────────────────────────────────────────────┘
[MACRO] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    CW_TOGG, XXXXXXX, SHOT,    XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, WT_COPY, WT_PSTE, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

};

// ============================================================
// Encoders – same on every layer
// Left: volume down / up.  Right: scroll up / down.
// ============================================================
#define ENC_ALL { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) }

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = ENC_ALL,
    [SYM]  = ENC_ALL,
    [NAV]  = ENC_ALL,
    [FN]   = ENC_ALL,
    [MACRO] = ENC_ALL,
};

// ============================================================
// Per-key tapping
// ============================================================

// Permissive hold on Esc/NAV only
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    return keycode == ESC_NAV;
}

// ============================================================
// Custom keycode handling
// ============================================================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case FL_LGIT: SEND_STRING(SS_LALT("f") "g"); return false;
        case FL_BTOP: SEND_STRING(SS_LALT("f") "b"); return false;
        case FL_YAZI: SEND_STRING(SS_LALT("f") "y"); return false;
        case FL_TAIL: SEND_STRING(SS_LALT("f") "t"); return false;
        case FL_SHEL: SEND_STRING(SS_LALT("f") "s"); return false;
        case FL_KEYS: SEND_STRING(SS_LALT("f") "k"); return false;
        case FL_PROJ: SEND_STRING(SS_LALT("f") "p"); return false;
    }
    return true;
}
