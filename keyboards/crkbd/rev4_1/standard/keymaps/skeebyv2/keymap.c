#include QMK_KEYBOARD_H

// ============================================================
// Layer Definitions
// ============================================================
enum layers {
    BASE,
    NAV,
    NUM,
    SYM,
    MISC,
};

// ============================================================
// Tap Dance
// ============================================================
enum tap_dances {
    TD_SHIFT_CAPS,
};

// Single tap  → one-shot shift
// Double tap  → toggle Caps Word
// Hold        → regular shift (for shift+click, held combos, etc.)
void td_shift_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            register_mods(MOD_BIT(KC_LSFT));
        } else {
            add_oneshot_mods(MOD_BIT(KC_LSFT));
        }
    } else if (state->count >= 2) {
        caps_word_toggle();
    }
}

void td_shift_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && state->pressed) {
        unregister_mods(MOD_BIT(KC_LSFT));
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_shift_finished, td_shift_reset),
};

// ============================================================
// Key Aliases
// ============================================================

// Thumb layer activators (hold = layer, tap = key)
#define LT_NAV  LT(NAV,  KC_SPC)
#define LT_NUM  LT(NUM,  KC_ENT)
#define LT_SYM  LT(SYM,  KC_ESC)
#define LT_MISC LT(MISC, KC_TAB)

// Home row mods – left hand (GACS order, outer to inner)
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)

// Home row mods – right hand (SCAG order, inner to outer)
#define HM_J    RSFT_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

// Tap-dance shift key
#define TD_SFT  TD(TD_SHIFT_CAPS)

// Zellij unlock (Alt+G)
#define ZL_UNLK LALT(KC_G)

// Alt-Tab / Ctrl-Tab for quick window / tab switching
#define AT_TAB  LALT(KC_TAB)
#define CT_TAB  LCTL(KC_TAB)

// Angle brackets (< >) — define safely in case not in this QMK version
#ifndef KC_LABK
#    define KC_LABK S(KC_COMM)
#endif
#ifndef KC_RABK
#    define KC_RABK S(KC_DOT)
#endif

// ============================================================
// Keymap
// ============================================================

/*
 * Layout reference (LAYOUT_split_3x6_3_ex2):
 *
 *   Row 0 (14): [exL] Q  W  E  R  T  [exML][exMR] Y  U  I  O  P  [exR]
 *   Row 1 (14): [exL] A  S  D  F  G  [exML][exMR] H  J  K  L  ;  [exR]
 *   Row 2 (12): [exL] Z  X  C  V  B                N  M  ,  .  /  [exR]
 *   Thumbs (6): [L-out] [L-mid] [L-in]   [R-in] [R-mid] [R-out]
 *
 * Thumb cluster:
 *   Left : [MISC/TAB]  [SYM/ESC]  [NAV/SPC]
 *   Right: [NUM/ENT]   [SHIFT/CAPSWORD]  [BSPC]
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  BASE – QWERTY with home row mods                                            │
// │                                                                              │
// │  esc/sym ┘  spc/nav ┘   ent/num ┘  shift ┘ (tap=1shot, dtap=caps)  bspc ┘  │
// │  tab/misc ┘                                                                  │
// └──────────────────────────────────────────────────────────────────────────────┘
[BASE] = LAYOUT_split_3x6_3_ex2(
  //╭──────┬──────┬──────┬──────┬──────┬──────╮ ╭──────╮╭──────╮ ╭──────┬──────┬──────┬──────┬──────┬──────╮
    KC_NO,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,   KC_NO,  KC_NO,   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_BSLS,
  //├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┤├──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    KC_NO,  HM_A,  HM_S,  HM_D,  HM_F,  KC_G,   KC_NO,  KC_NO,   KC_H,  HM_J,  HM_K,  HM_L,  HM_SCLN, KC_QUOT,
  //├──────┼──────┼──────┼──────┼──────┼──────┤ ╰──────╯╰──────╯ ├──────┼──────┼──────┼──────┼──────┼──────┤
    KC_NO,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                     KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_NO,
  //╰──────┴──────┴──────┴──────┼──────┼──────┼──────╮ ╭──────┼──────┼──────┼──────┴──────┴──────┴──────╯
                                LT_MISC, LT_SYM, LT_NAV,  LT_NUM, TD_SFT, KC_BSPC
  //                            ╰──────┴──────┴──────╯ ╰──────┴──────┴──────╯
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  NAV – Vim navigation on right hand  (activate: hold SPC)                   │
// │                                                                              │
// │  Right home row: [H]=←  [J]=↓  [K]=↑  [L]=→  [;]=End                      │
// │  Right top row:  [Y]=Home  [U]=Cut  [I]=Copy  [O]=Paste  [P]=PgUp           │
// │    Home/End flank the ←/End extremes; PgUp sits above End                   │
// │  Right bottom:   [M]=PgDn  (below ↓)                                        │
// │  Left home row:  mods  |  [G]=TG(NAV) to lock/unlock                        │
// │  Left bottom:    [Z]=Alt-Tab  [X]=Ctrl-Tab                                  │
// │  [exL row1] = TO(BASE) — emergency escape from any locked layer             │
// └──────────────────────────────────────────────────────────────────────────────┘
[NAV] = LAYOUT_split_3x6_3_ex2(
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_HOME, KC_CUT,  KC_COPY, KC_PSTE, KC_PGUP, KC_NO,
    TO(BASE), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, TG(NAV), KC_NO, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  KC_NO,
    KC_NO,    AT_TAB,  CT_TAB,  KC_NO,   KC_NO,   KC_NO,                    KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                LT_MISC, LT_SYM, KC_TRNS,  LT_NUM, TD_SFT, KC_BSPC
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  NUM – Numpad on right, arithmetic on left top row  (activate: hold ENT)    │
// │                                                                              │
// │  Right:   7 8 9 / 4 5 6 / 1 2 3 / 0 .  (standard numpad layout)            │
// │  Left top row:  + - * / =                                                   │
// │  Left home row: mods                                                         │
// │  [G] = TG(NUM) — tap to lock/unlock this layer                              │
// └──────────────────────────────────────────────────────────────────────────────┘
[NUM] = LAYOUT_split_3x6_3_ex2(
    KC_NO,    KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL,  KC_NO,  KC_NO,   KC_NO,  KC_7,   KC_8,   KC_9,    KC_0,    KC_NO,
    TO(BASE), KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, TG(NUM), KC_NO,  KC_NO,   KC_NO,  KC_4,   KC_5,   KC_6,    KC_EQL,  KC_NO,
    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,  KC_1,   KC_2,   KC_3,    KC_DOT,  KC_NO,
                              LT_MISC, LT_SYM, LT_NAV,   KC_TRNS, TD_SFT, KC_BSPC
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  SYM – Symbol pairs on right, remaining symbols on left  (activate: hold ESC)│
// │                                                                              │
// │  Right hand – adjacent pairs:                                               │
// │    [U][I] = [ ]   [O][P] = { }                                             │
// │    [J][K] = ( )   [L][;] = < >                                             │
// │    [,][.] = - _   [/][exR] = / \   (pairs shifted right)                  │
// │    [H] = |   [Y] = ~   ['] = :                                             │
// │  Left hand: original skeeby sym layout; ~ and | replaced with + and =      │
// │    since both are duplicated on the right hand (Y=~ H=|) and + = are        │
// │    otherwise only reachable via NUM. G = TG(SYM) to lock layer.             │
// └──────────────────────────────────────────────────────────────────────────────┘
[SYM] = LAYOUT_split_3x6_3_ex2(
    KC_NO,    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,  KC_NO,  KC_NO,   KC_TILD, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_NO,
    TO(BASE), KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, TG(SYM),  KC_NO,  KC_NO,   KC_PIPE, KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_COLN,
    KC_NO,    KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,                     KC_NO,   KC_NO,   KC_MINS, KC_UNDS, KC_SLSH, KC_BSLS,
                              LT_MISC, KC_TRNS, LT_NAV,   LT_NUM, TD_SFT, KC_BSPC
),

// ┌──────────────────────────────────────────────────────────────────────────────┐
// │  MISC – Function keys on left, media + system on right  (activate: hold TAB) │
// │                                                                              │
// │  Left:  F1–F12 in numpad layout (F7-F8-F9 / F4-F5-F6 / F1-F2-F3, F10-F12) │
// │  Right: media controls + RGB + Zellij unlock on [Y]                         │
// │  [G] = TG(MISC) — tap to lock/unlock this layer                            │
// └──────────────────────────────────────────────────────────────────────────────┘
[MISC] = LAYOUT_split_3x6_3_ex2(
    KC_NO,    KC_F12,  KC_F7,  KC_F8,  KC_F9,  KC_PSCR,   KC_NO,  KC_NO,   ZL_UNLK, KC_NO,   RM_TOGG, RM_NEXT, RM_VALU, KC_NO,
    TO(BASE), KC_F11,  KC_F4,  KC_F5,  KC_F6,  TG(MISC),  KC_NO,  KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_NO,
    KC_NO,    KC_F10,  KC_F1,  KC_F2,  KC_F3,  KC_PAUS,                     KC_MRWD, KC_MFFD, KC_MSTP, KC_MUTE, RM_PREV, KC_NO,
                              KC_TRNS, LT_SYM, LT_NAV,   LT_NUM, TD_SFT, KC_BSPC
),

};
