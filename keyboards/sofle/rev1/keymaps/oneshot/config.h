// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// ── Timing ────────────────────────────────────────────────────────────────────
// Tap-holds: Esc/NAV, Space/SYM, home row mods; plus the right encoder tap dance.
#define TAPPING_TERM 200

// A key pressed and released inside a held tap-hold makes it a hold.
#define PERMISSIVE_HOLD

// Opposite-hand rule for home row mods; layer keys are exempt
// (see get_chordal_hold in keymap.c).
#define CHORDAL_HOLD

// Tap-holds pressed within this long of a letter tap instantly.
// Space/SYM uses 100 ms (see get_flow_tap_term in keymap.c).
#define FLOW_TAP_TERM 150

// Space/SYM disables tap-then-hold repeat (see get_quick_tap_term).
#define QUICK_TAP_TERM_PER_KEY

// ── One-shots ─────────────────────────────────────────────────────────────────
// How long a tapped one-shot mod/layer waits for the next key (ms).
// ONESHOT_TAP_TOGGLE is deliberately left undefined: a double tap never locks.
#define ONESHOT_TIMEOUT 3000

// ── RP2040 ────────────────────────────────────────────────────────────────────
// Double-tap the controller's reset button to enter the UF2 bootloader.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
