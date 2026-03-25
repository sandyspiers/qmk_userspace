// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// ── Home row mod timing ───────────────────────────────────────────────────────
// Raised above the 200 ms default to reduce accidental mod triggers during
// normal typing.  Adjust upward if misfires persist, downward for snappier mods.
#define TAPPING_TERM 250

// Allow a quick double-tap of a home-row key to repeat the tap action without
// triggering the hold.  Set to 0 to disable fast re-triggering.
#define QUICK_TAP_TERM 120

// Activate the hold action when another key is fully pressed AND released while
// this key is held.  Prevents false modifier triggers when rolling keys quickly
// (e.g. typing "sd" fast no longer fires Alt+D).
#define PERMISSIVE_HOLD

// ── One-shot mods ─────────────────────────────────────────────────────────────
// How long a one-shot modifier stays active after being tapped (ms).
#define ONESHOT_TIMEOUT 3000

// ── RGB (if enabled) ─────────────────────────────────────────────────────────
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP  10
    #define RGBLIGHT_SAT_STEP  17
    #define RGBLIGHT_VAL_STEP  17
#endif
