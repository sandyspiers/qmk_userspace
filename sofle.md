# Sofle v2.1 · oneshot

`*` one-shot: tap for the next key, hold as a mod/layer. They stack.
`·` unused. `◉` encoder press. Thumbs are the same on every layer.

## BASE

```
 `    1    2    3    4    5    │    6    7    8    9    0    -
 Tab  q    w    e    r    t    │    y    u    i    o    p    =
 ⎋NAV a    s    d    f    g    │    h    j    k    l    ;    '
 Alt* z    x    c    v    b   ◉│◉   n    m    ,    .    /    SYM*
      GUI  MAC* Ctl* Sft* Spc  │    Ent  Bspc Ctl* Del  FN*
```

- `⎋NAV` tap Esc, hold NAV (permissive hold; the only tap-hold key)
- `Alt*` then a letter sends tmux `M-` keys
- `Ctl*` on both thumbs: use the one opposite the letter

## SYM · mirrored pairs

```
 ·    ·    ·    ·    ·    ·    │    ·    ·    ·    ·    ·    ·
 ·    !    @    #    $    %    │    ^    &    *    ~    `    ·
 ·    \    {    [    (    <    │    >    )    ]    }    |    ·
 ·    ·    _    -    =    +   ◉│◉   ·    ·    ·    ·    ·    SYM
```

- Same bracket per finger on both hands; top row is shifted digits
- `_ - = +` stay reachable while holding SYM
- Tap SYM first for `|` `}` `~` `` ` `` (unreachable while holding)

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
| Left    | Volume up / down | 1 tap play/pause, 2 taps next |
| Right   | Scroll down / up | `Win+Alt+K` mic mute          |

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
