# skeebyv2

A redesigned Corne keymap built around four design principles: thumb-driven layer
activation, consistent home row mods, symbol pairs that live next to each other,
and a "lock this layer" escape hatch on every layer.

---

## Thumb cluster

```
Left  : [MISC/TAB]  [SYM/ESC]  [NAV/SPC]
Right : [NUM/ENT]   [SHIFT]    [BSPC]
```

Each left thumb key **activates a layer while held** and sends its tap character
on a quick press.  The right inner thumb follows the same pattern for NUM.
SHIFT sits next to ENT so one-shot capitalisation and numbers are on adjacent
thumbs.  BSPC is on the outer right thumb.

The right middle thumb is a **tap-dance shift**:

| Action      | Result             |
|-------------|--------------------|
| Tap         | One-shot shift     |
| Double-tap  | Toggle Caps Word   |
| Hold        | Regular shift      |

One-shot shift capitalises the next keypress then turns off automatically.
Caps Word capitalises everything until you press space, enter, or a non-word
character.

---

## Home row mods

Standard GACS/SCAG layout — same fingers, same hand.

```
Left  :  A=GUI   S=Alt   D=Ctrl   F=Shift
Right :  J=Shift K=Ctrl  L=Alt    ;=GUI
```

`TAPPING_TERM` is 250 ms (vs the QMK default of 200 ms) to reduce accidental
modifier triggers during fast typing.  `QUICK_TAP_TERM` is 120 ms so
double-tapping a home-row key still repeats the letter rather than the modifier.

`PERMISSIVE_HOLD` is enabled: the hold action only fires if another key is fully
pressed *and released* while the mod key is held.  This prevents false modifier
triggers when rolling through keys quickly (e.g. typing `sd` fast no longer
risks firing `Alt+D`).

---

## Layer strategy

- **Hold** a thumb key → temporary layer while held.
- **Tap [G]** on any layer → `TG(layer)` — locks the layer on.  Tap [G] again
  to unlock.  G sits at the inner column of the left home row, reachable without
  moving the hand, and is consistent across all layers.
- **Extra-left key (row 1)** on every non-base layer → `TO(BASE)` — immediately
  drops back to BASE regardless of which layers are locked.  This is the
  emergency escape if TG gets stuck.
- All layers keep the full thumb cluster passthrough so layers can be stacked
  (e.g. hold NAV while NUM is locked).

---

## BASE

Standard QWERTY.  `\` lives on the top-right extra column.  `;` is the tap of
the `RGUI` home row key.  `:` is one-shot-shift + `;`.  `|` is
one-shot-shift + `\`.  Both are reachable from base without a dedicated layer.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │  Q  │  W  │  E  │  R  │  T  │         │  Y  │  U  │  I  │  O  │  P  │  \  │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │GUI/A│ALT/S│CTL/D│SFT/F│  G  │         │  H  │SFT/J│CTL/K│ALT/L│GUI/;│  '  │
├─────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  Z  │  X  │  C  │  V  │  B  │         │  N  │  M  │  ,  │  .  │  /  │     │
└─────┴─────┴─────┴──┬──┴──┬──┴──┬──┘         └──┬──┴──┬──┴──┬──┴─────┴─────┴─────┘
                     │MISC/│SYM/ │NAV/   NUM/ │SHFT │BSPC │
                     │ TAB │ ESC │ SPC   ENT  │     │     │
                     └─────┴─────┴────   ─────┴─────┴─────┘
```

---

## NAV  (hold SPC)

Navigation on the right hand, mods on the left.  The home row mirrors vim:
`H J K L` are `← ↓ ↑ →`.  `;` extends rightward to End, matching the vim `$`
feel.

The top row follows the same spatial logic:
- `Y` (above `H`/←) = **Home** — the leftmost extreme above the leftmost arrow
- `P` (above `;`/End) = **PgUp** — the upward extreme above the rightmost arrow
- `M` (below `J`/↓) = **PgDn** — the downward extreme below the down arrow

Cut / Copy / Paste occupy the middle of the top row (`U I O`) so clipboard
operations are available without leaving the nav layer.

```
┌──────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│BASE⎋ │     │     │     │     │     │         │Home │ Cut │Copy │Pste │PgUp │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│TO(B) │ GUI │ Alt │Ctrl │Shft │TG✦  │         │  ←  │  ↓  │  ↑  │  →  │ End │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│      │A-Tab│C-Tab│     │     │     │         │     │PgDn │     │     │     │     │
└──────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(NAV)` at G — tap to lock the layer.  `TO(B)` = `TO(BASE)` emergency exit.

**Alt-Tab / Ctrl-Tab** on the bottom-left row send the full chord in a single
keypress for window and tab switching without leaving the nav layer.

---

## NUM  (hold ENT)

Numpad on the right hand in the standard 7-8-9 / 4-5-6 / 1-2-3 layout.
`0` is on the right hand column and `.` is at the `;` column, mirroring a
physical numpad.

Arithmetic operators live on the **left top row** so the home row keeps its
modifiers — useful when entering numbers alongside keyboard shortcuts.

```
┌──────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│      │  +  │  -  │  *  │  /  │  =  │         │     │  7  │  8  │  9  │  0  │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│TO(B) │ GUI │ Alt │Ctrl │Shft │TG✦  │         │     │  4  │  5  │  6  │  =  │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│      │     │     │     │     │     │         │     │  1  │  2  │  3  │  .  │     │
└──────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(NUM)` at G.  `TO(B)` = `TO(BASE)` emergency exit.

---

## SYM  (hold ESC)

All bracket and delimiter pairs are placed **adjacent** on the right hand so
they can be typed with consecutive fingers rather than a shift chord.

```
Right hand pair layout:
  Top row  :  [  ]   {  }      (index–middle columns, ring–pinky columns)
  Home row :  (  )   <  >      same columns
  Bottom   :  -  _   /  \      shifted right — ring–pinky, pinky–extra

  H = |    Y = ~    ' = :
```

The pairs are shifted toward the right of the right hand so the pinky and ring
finger handle the less-common delimiters (`<>`, `-_`, `/\`) while the stronger
index and middle fingers handle `()` and `[]`.

The left hand uses the original skeeby symbol layout for continuity.  The two
positions that were duplicated on the right hand (`~` at Y, `|` at H) are
replaced with `+` and `=`, which are otherwise only reachable via the NUM layer.

```
┌──────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│      │  {  │  &  │  *  │  (  │  }  │         │  ~  │  [  │  ]  │  {  │  }  │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│TO(B) │  :  │  $  │  %  │  ^  │TG✦  │         │  |  │  (  │  )  │  <  │  >  │  :  │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│      │  +  │  !  │  @  │  #  │  =  │         │     │     │  -  │  _  │  /  │  \  │
└──────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(SYM)` at G.  `TO(B)` = `TO(BASE)` emergency exit.  ESC thumb is
transparent (passes through to BASE).

---

## MISC  (hold TAB)

Function keys on the left in the same numpad pattern as NUM
(F7-F8-F9 / F4-F5-F6 / F1-F2-F3, with F10-F11-F12 on the outer column).
The matching layout means the finger positions transfer directly between layers.

Media controls on the right: previous / play / next on the home row,
rewind / fast-forward / stop / mute on the bottom, RGB controls on the top.

The **Y key** sends `Alt+G` — the Zellij prefix-unlock chord.  It sits isolated
at the far left of the right hand, away from all other controls.

```
┌──────┬─────┬─────┬─────┬─────┬─────┐         ┌─────┬─────┬─────┬─────┬─────┬─────┐
│      │ F12 │ F7  │ F8  │ F9  │PScr │         │ZL🔓 │     │RGB  │RGB→ │RGB+ │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│TO(B) │ F11 │ F4  │ F5  │ F6  │TG✦  │         │ ⏮  │ ⏯  │ ⏭  │ 🔉 │ 🔊 │     │
├──────┼─────┼─────┼─────┼─────┼─────┤         ├─────┼─────┼─────┼─────┼─────┼─────┤
│      │ F10 │ F1  │ F2  │ F3  │Paus │         │ ⏪  │ ⏩  │ ⏹  │mute │RGB← │     │
└──────┴─────┴─────┴─────┴─────┴─────┘         └─────┴─────┴─────┴─────┴─────┴─────┘
```

`✦ TG(MISC)` at G.  `TO(B)` = `TO(BASE)` emergency exit.  TAB thumb is
transparent.  `ZL🔓` = `Alt+G` (Zellij unlock).

---

## Building

```sh
qmk compile -kb crkbd/rev4_1/standard -km skeebyv2
```

Or add to `qmk.json` build targets and run `make`.

---

## Tuning tips

- **Home row mods still misfiring?** Raise `TAPPING_TERM` in `config.h`
  (try 280–320 ms).  `PERMISSIVE_HOLD` is already enabled — it activates the
  hold only when another key is fully pressed and released during the hold,
  which greatly reduces false positives during fast rolling.
- **Mods not triggering reliably?** Lower `TAPPING_TERM` toward 200 ms.
- **One-shot shift expiring too fast?** Raise `ONESHOT_TIMEOUT` (default 3000 ms).
- **Caps Word stopping on `-`?** Add a `caps_word_set_user` callback to
  `keymap.c` to configure which characters count as word characters.
