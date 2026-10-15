// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// ── Timing ────────────────────────────────────────────────────────────────────
// Only Esc/NAV and the right encoder tap dance depend on this.
#define TAPPING_TERM 200

// Permissive hold for Esc/NAV only (see get_permissive_hold in keymap.c):
// holding it while tapping j is NAV, a quick Esc→j roll stays Esc.
#define PERMISSIVE_HOLD_PER_KEY

// ── One-shots ─────────────────────────────────────────────────────────────────
// How long a tapped one-shot mod/layer waits for the next key (ms).
// ONESHOT_TAP_TOGGLE is deliberately left undefined: a double tap never locks.
#define ONESHOT_TIMEOUT 3000

// ── RP2040 ────────────────────────────────────────────────────────────────────
// Double-tap the controller's reset button to enter the UF2 bootloader.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
