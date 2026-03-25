# skeebyv2

A redesigned Corne keymap built around four design principles: thumb-driven layer
activation, consistent home row mods, symbol pairs that live next to each other,
and a "lock this layer" escape hatch on every layer.

---

## Thumb cluster

```
Left  : [MISC/TAB]  [SYM/ESC]  [NAV/SPC]
Right : [NUM/ENT]   [BSPC]     [SHIFT]
```

Each left thumb key **activates a layer while held** and sends its tap character
on a quick press.  The right inner thumb follows the same pattern for NUM.
BSPC and SHIFT live on the two outer right thumb keys for easy one-handed access.

The right outer key is a **tap-dance shift**:

| Action      | Result             |
|-------------|--------------------|
| Tap         | One-shot shift     |
| Double-tap  | Toggle Caps Word   |
| Hold        | Regular shift      |

One-shot shift means the next keypress is capitalised, then shift turns off
automatically.  Caps Word capitalises everything until you press space, enter,
or a non-word character.

---

## Home row mods

Standard GACS/SCAG layout — the same fingers, same hand.

```
Left  :  A=GUI   S=Alt   D=Ctrl   F=Shift
Right :  J=Shift K=Ctrl  L=Alt    ;=GUI
```

`TAPPING_TERM` is 250 ms (vs the QMK default of 200 ms) to reduce accidental
modifier triggers during fast typing.  `QUICK_TAP_TERM` is set to 120 ms so
double-tapping a home-row key still repeats the letter instead of the modifier.

---

## Layer strategy

- **Hold** a thumb key → temporary layer while held.
- **Tap [G]** on any layer → `TG(layer)` — locks the layer on.  Tap [G] again
  to return to BASE.  The G key was chosen because it sits at the inner column
  of the left home row, making it reachable without moving the hand.
- All layers keep the full thumb cluster available so you can stack layers
  (e.g. hold NAV while NUM is locked).

---

## BASE

Standard QWERTY.  `\` lives on the top-right extra column.  `;` is the tap of
the `RGUI` home row key.  `:` is one-shot-shift + `;`.  `|` is
one-shot-shift + `\`.  Both are reachable without a dedicated layer.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  Q  │  W  │  E  │  R  │  T  │         │  Y  │  U  │  I  │  O  │  P  │  \  │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │GUI/A│ALT/S│CTL/D│SFT/F│  G  │         │  H  │SFT/J│CTL/K│ALT/L│GUI/;│  '  │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  Z  │  X  │  C  │  V  │  B  │         │  N  │  M  │  ,  │  .  │  /  │     │
└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┘         └──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                     │MISC/│SYM/ │NAV/   NUM/ │BSPC │SHFT │
                     │ TAB │ ESC │ SPC   ENT  │     │     │
                     └─────┴─────┴────   ─────┴─────┴─────┘
```

---

## NAV  (hold SPC)

Navigation on the right hand, mods on the left.  The cluster mirrors vim: H J K L
are ← ↓ ↑ →, with `;` extended to End (the rightmost key on that row, matching
the vim `$` feel).  Home and PgUp sit above the cluster; PgDn sits below.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │         │     │Home │PgUp │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ Alt │Ctrl │Shft │TG✦  │         │  ←  │  ↓  │  ↑  │  →  │ End │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │A-Tab│C-Tab│     │     │     │         │     │PgDn │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(NAV)` at G — tap to lock the nav layer on.

**Alt-Tab / Ctrl-Tab** on the bottom-left row let you switch windows and tabs
without leaving the nav layer.  These send the full chord (modifier + Tab) in a
single keypress.

---

## NUM  (hold ENT)

Numpad on the right hand in the standard 7-8-9 / 4-5-6 / 1-2-3 layout.
`0` and `.` are on the right thumb and the `;` column respectively, mirroring a
physical numpad.

Arithmetic operators live on the **left top row** so the home row can keep its
modifiers — useful when typing numbers with keyboard shortcuts.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  +  │  -  │  *  │  /  │  =  │         │     │  7  │  8  │  9  │  0  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ GUI │ Alt │Ctrl │Shft │TG✦  │         │     │  4  │  5  │  6  │  =  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │         │     │  1  │  2  │  3  │  .  │     │
└─────┴─────┴─────┴─────┴─────┴──┬──┘         └──┬──┴─────┴─────┴─────┴─────┴─────┘
                                  └─ TG✦          └─ [0]
```

`✦ TG(NUM)` at G.  Right inner thumb becomes `0` while NUM is active.

---

## SYM  (hold ESC)

All bracket and delimiter pairs are placed **adjacent** on the right hand so they
can be typed with consecutive fingers rather than a shift chord.

```
Right hand pair layout:
  Top row  :  [  ]   {  }          (index–middle, ring–pinky)
  Home row :  (  )   <  >          same columns
  Bottom   :  -  _   /  \          same columns

  H = |    Y = ~    ' = :
```

The left hand covers the remaining symbols, grouped by category:

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  !  │  @  │  #  │  $  │  %  │         │  ~  │  [  │  ]  │  {  │  }  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  ^  │  &  │  *  │  +  │TG✦  │         │  |  │  (  │  )  │  <  │  >  │  :  │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  `  │  ~  │  ;  │  =  │     │         │  -  │  _  │  /  │  \  │     │     │
└─────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(SYM)` at G.  ESC thumb becomes transparent (passes through to BASE).

---

## MISC  (hold TAB)

Function keys on the left in the same numpad pattern used by the NUM layer
(F7-F8-F9 on top, F4-F5-F6 on home, F1-F2-F3 on bottom, F10-F11-F12 on the
outer column).  This mirrors how the NUM layer is arranged so muscle memory
transfers.

Media controls on the right follow a logical arc: previous / play / next on the
home row, rewind / fast-forward / stop on the bottom, volume on the right column.

The **Y key** on the top-right sends `Alt+G` — the Zellij prefix-unlock chord.
It sits isolated at the top of the right hand, away from all media keys, to
avoid accidental triggers.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F12 │ F7  │ F8  │ F9  │PScr │         │ZL🔓 │     │RGB  │RGB→ │RGB+ │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F11 │ F4  │ F5  │ F6  │TG✦  │         │ ⏮  │ ⏯  │ ⏭  │ 🔉 │ 🔊 │     │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │ F10 │ F1  │ F2  │ F3  │Paus │         │ ⏪  │ ⏩  │ ⏹  │mute │RGB← │     │
└─────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(MISC)` at G.  TAB thumb becomes transparent.  `ZL🔓` = `Alt+G` (Zellij unlock).

---

## Building

```sh
qmk compile -kb crkbd/rev4_1/standard -km skeebyv2
```

Or add to `qmk.json` build targets and run `make`.

---

## Tuning tips

- **Home row mods firing too easily?** Raise `TAPPING_TERM` in `config.h`
  (try 280–320 ms).
- **Mods not firing when rolling keys?** Add `#define PERMISSIVE_HOLD` to
  `config.h` — this activates the hold action if another key is pressed and
  released while the mod key is held.
- **One-shot shift expiring too fast?** Raise `ONESHOT_TIMEOUT` (default 3000 ms).
- **Caps Word stopping on `-`?** Add `caps_word_set_user` to `keymap.c` to
  configure which characters are considered "word" characters.
