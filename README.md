# qmk_userspace

My QMK keymaps, built against upstream `qmk_firmware` as a
[QMK userspace](https://docs.qmk.fm/newbs_external_userspace).

| Board       | Keymap                                  | Reference            |
|-------------|-----------------------------------------|----------------------|
| Sofle v2.1  | `keyboards/sofle/rev1/keymaps/oneshot/` | [sofle.md](sofle.md) |

## Layout

- **Keymaps** live where QMK expects them:
  `keyboards/<board>/<rev>/keymaps/<name>/` (`keymap.c`, `config.h`, `rules.mk`).
- **Docs** live in the root, one file per board, named after the board
  (`sofle.md`). Each is a quick reference: a diagram per layer plus a few
  notes, sized for a terminal.
- `qmk.json` lists the build targets.

## Viewing the docs

The board docs are written for [glow](https://github.com/charmbracelet/glow)
at width 72:

```sh
glow -w 72 sofle.md        # print
glow -p -w 72 sofle.md     # page (less)
```

The layer diagrams are code blocks, which glow cuts off rather than wraps, so
the pane needs at least 72 columns. As a tmux popup:

```sh
tmux display-popup -E -w 76 -h 90% "glow -p -w 72 ~/files/tools/qmk_userspace/sofle.md"
```

When editing a doc, keep diagram lines within 65 characters and check with
`glow -w 72` that nothing wraps.

## Building

```sh
qmk compile -kb sofle/rev1 -km oneshot  # one board
qmk userspace-compile                   # every target in qmk.json
```

Run these from this directory, or set `qmk config user.overlay_dir="$(realpath .)"`
once to use the userspace from anywhere. Firmware (`*.uf2`) lands in the repo
root and is gitignored.

Every push also builds on GitHub Actions, and the firmware appears under
Releases.

## Adding a board

1. `qmk new-keymap -kb <board> -km <name>`
2. `qmk userspace-add -kb <board> -km <name>`
3. Write `<board>.md` in the root and add it to the table above.

## Upstream

This repo was created from [qmk/qmk_userspace](https://github.com/qmk/qmk_userspace)
(remote `upstream`). The template's tooling (`.devcontainer/`, `.vscode/`,
`.clangd`, `.clang-format`, `Makefile`, the Actions workflow) is kept as-is.
