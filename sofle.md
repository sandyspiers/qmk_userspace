# Sofle v2.1 · oneshot

`*` one-shot: tap for the next key, hold as a mod/layer. They stack.
`·` unused. `◉` encoder press. Thumbs are the same on every layer.

## BASE

```
 `    1    2    3    4    5    │    6    7    8    9    0    -
 Tab  q    w    e    r    t    │    y    u    i    o    p    =
 ⎋NAV a    s    d    f    g    │    h    j    k    l    ;    '
 Ctl* z    x    c    v    b   ◉│◉   n    m    ,    .    /    Ctl*
      GUI  MAC* Alt* Sft* Spc  │    Ent  Bspc SYM* Del  FN*
```

- `⎋NAV` tap Esc, hold NAV (permissive hold; the only tap-hold key)
- `Alt*` then a letter sends tmux `M-` keys
- `Ctl*` in both bottom corners: use the one opposite the letter
- Symbols on the number row come from `Sft*` + digit

## SYM · mirrored pairs

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    \    {    [    (    <    │    >    )    ]    }    |    ·
 ·    ·    _    -    =    +   ◉│◉   ·    ·    ·    ·    ·    ·
```

- Same bracket per finger on both hands
- Shifted digits are not duplicated here: use `Sft*` + number row
- SYM is on a thumb, so every key is reachable while holding it

## NAV · column = direction, row = distance

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    ·    ·    ·    ·    ·    │    Home PgDn PgUp End  ·    ·
 NAV  ·    ·    ·    ·    ·    │    ←    ↓    ↑    →    ·    ·
 ·    ·    ·    ·    ·    ·   ◉│◉   ·    ·    ·    ·    ·    ·
```

- `Sft*` then arrow selects, `Ctl*` then arrow jumps a word

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
`ONESHOT_TIMEOUT 3000`
