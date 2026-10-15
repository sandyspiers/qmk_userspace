# Sofle v2.1 · oneshot

`*` one-shot: tap for the next key, hold as a mod/layer. They stack.
`a/b` tap-hold: tap a, hold b. `·` unused. `◉` encoder press. Thumbs are the same on every layer.

## BASE

```
 `    1    2    3    4    5    │    6    7    8    9    0    -
 Tab  q    w    e    r    t    │    y    u    i    o    p    =
 ⎋/NV a    s    d    f    g    │    h    j    k    l    ;    '
          Alt  Ctl                        Ctl  Alt
 Ctl* z    x    c    v    b   ◉│◉   n    m    ,    .    /    \
      GUI  SYM* MAC* Sft* ␣/SY │    Ent  Bspc FN*  Del  ·
```

- Home row mods: hold `s` Alt, `d` Ctrl, `k` Ctrl, `l` Alt
- Hold the mod on the hand opposite the letter (Chordal Hold): `k`+`c`
  is Ctrl+C, `s`+`f` is tmux `M-f`; same-hand rolls stay letters
- `⎋/NV` tap Esc, hold NAV. `␣/SY` tap Space, hold SYM
- Typing fast makes tap-holds tap (Flow Tap: 150 ms, 100 ms for Space)
- `SYM*` one-shot for a single symbol mid-word, no timing involved
- `Ctl*` one-shot fallback for sequences like tmux `C-a`
- Symbols on the number row come from `Sft*` + digit

## SYM · mirrored pairs

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    {    [    (    <    │    >    )    ]    }    |    ·
 ·    ·    _    -    =    +   ◉│◉   ·    ·    ·    ·    ·    ·
```

- Same bracket per finger on both hands
- Shifted digits are not duplicated here: use `Sft*` + number row
- Hold Space, or tap `SYM*` for one symbol; `\` is the right corner

## NAV · column = direction, row = distance

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    ·    ·    ·    │    Home PgDn PgUp End  ·    ·
 NAV  ·    Alt  Ctl  Sft  ·    │    ←    ↓    ↑    →    ·    ·
 ·    ·    ·    ·    ·    ·   ◉│◉   ·    ·    ·    ·    ·    ·
```

- Left home row is plain Alt / Ctrl / Shift while holding NAV:
  `f` + arrow selects, `d` + arrow jumps a word, both for word select

## FN · F-keys and floating tools

```
 F11  F1   F2   F3   F4   F5   │    F6   F7   F8   F9   F10  F12
 ·    ·    ·    ·    ·    tail │    yazi ·    ·    ·    proj ·
 ·    ·    sh   ·    ·    git  │    ·    ·    keys ·    ·    ·
 ·    ·    ·    ·    ·    btop◉│◉   ·    ·    ·    ·    ·    ·
```

- Tools send tmux `M-f` + letter: `t` fzf-tail, `y` yazi, `p` project
  picker, `s` shell, `g` lazygit, `k` this cheat sheet, `b` btop

## MACRO · mnemonic keys

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 CapW ·    Shot ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    Copy Pste ·   ◉│◉   ·    ·    ·    ·    ·    ·
```

| Key  | Does                   | Sends         |
|------|------------------------|---------------|
| CapW | Caps Word              | `CW_TOGG`     |
| Shot | Screenshot an area     | `Win+Shift+S` |
| Copy | Windows Terminal copy  | `C-S-c`       |
| Pste | Windows Terminal paste | `C-S-v`       |

## Encoders · every layer

| Encoder | Turn (cw / ccw)  | Press                         |
|---------|------------------|-------------------------------|
| Left    | Scroll down / up | `Win+Alt+K` mic mute          |
| Right   | Volume up / down | 1 tap play/pause, 2 taps next |

## Build and flash

```sh
qmk compile -kb sofle/rev1 -km oneshot
```

1. Double-tap the PCB reset button (near TRRS), or hold the half's
   outer top key while plugging in.
2. Copy `sofle_rev1_oneshot.uf2` to the `RPI-RP2` drive.
3. Repeat for the other half. USB cable goes in the **left** half.

Keymap: `keyboards/sofle/rev1/keymaps/oneshot/` · ProMicro RP2040
(`rp2040_ce`) · no OLED, no RGB · `TAPPING_TERM 200` ·
`FLOW_TAP_TERM 150` · Permissive + Chordal Hold · `ONESHOT_TIMEOUT 3000`
