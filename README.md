# Pokémon Emerald Rush

Pokémon Emerald Rush is Pokémon Emerald with the waiting taken out. Text is instant, battles start and play out several times faster, the Running Shoes work everywhere, and a handful of small annoyances are gone, while the game itself (story, Pokémon, trainers, maps) is the Emerald you know.

It is built on [pokeemerald](https://github.com/pret/pokeemerald), the decompilation of Pokémon Emerald, so every change is written in C and can be switched on or off in one config file.

## Playing it

Download `Emerald Rush.ips` from the `release` folder and apply it with any IPS patcher (for example [Rom Patcher JS](https://www.marcrobledo.com/RomPatcher.js/), Lunar IPS or Floating IPS) to a clean, unmodified **Pokémon Emerald (USA, Europe)** ROM:

`sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

The patch will not work on a ROM that has already been modified. No ROM is included in this repository.

## Features

### Faster battles
* **Trainer battles skip the transition animation** and fade straight into the battle. Wild battles keep their transition at 4x speed.
* **Much faster battle intro:** the scene slides in faster, the party bars show briefly, the first Poké Ball is thrown sooner, and "Wild X appeared!" / "X would like to battle!" continue on their own.
* **2x fast-forward** for everything in battle: logic, animations, HP and EXP bars. Move animations run a further 2x faster.
* **Shorter pauses** after battle messages, and A or B skips the rest of a pause.
* **Faster capture throw**, ball shakes and send-out animations.
* **FAST BATTLES option** in the Options menu: FAST (default) or NORM for vanilla battle speed. Link and recorded battles always play at normal speed.

How much faster, measured in frames:

| | Normal | Emerald Rush |
|---|---|---|
| Wild battle transition | 89 | 28 |
| Trainer battle transition | 150 | 14 |
| Trainer battle, start to first command | 404 | 160 |
| A typical turn | ~270 | ~94 |
| Catching a Pokémon (throw to caught) | 699 | 339 |
| Last menu back to the overworld | 358 | ~122 |

### Everywhere else
* **Instant text** in every message box.
* **Run anywhere:** the Running Shoes work on every map, and you move at running speed underwater.
* **Repel prompt:** when a Repel wears off, the game asks whether to use another of the same kind.
* **Better randomness:** the RNG is seeded from a timer started at boot mixed with the real-time clock, so every playthrough differs.
* **Fast soft reset:** A + B + Start + Select goes straight to the Continue / New Game menu, skipping the copyright screen, intro and title screen.
* **No field move cut-in** when using Cut, Surf, Strength, Rock Smash and so on.
* **No "overwrite save?" prompt** when saving.
* **Trade anytime:** trades are not held back by the National Dex or Champion status.
* **Low-HP beep** plays 3 times and then stops instead of looping forever.

### Options menu
The Options menu now has 9 rows and fills the screen:

| Option | Choices | Default |
|---|---|---|
| POKéMON ANIM (replaces Text Speed) | ON / OFF: the animation a Pokémon does when sent out, and in the summary and Pokédex | OFF |
| BATTLE SCENE | ON / OFF | ON |
| FAST BATTLES | FAST / NORM | FAST |
| BATTLE STYLE | SHIFT / SET | SHIFT |
| SOUND | MONO / STEREO | MONO |
| BUTTON MODE | NORMAL / LR / L=A | NORMAL |
| NAV CALLS | ON / OFF: whether trainers call you on the PokéNav | OFF |
| FRAME | TYPE 1-20 | TYPE 1 |

## Building from source

Set up the build tools as described in [INSTALL.md](INSTALL.md), then run `make`. The output, `pokeemerald.gba`, is the Emerald Rush ROM.

Every feature is a switch in [`include/rush_config.h`](include/rush_config.h). Set a `RUSH_*` option to `FALSE`, or a `B_*` speed option to its vanilla value (noted next to each one), to get the original Emerald behaviour back for that feature. `include/rush_speed.h` holds the NORM (vanilla) values used when FAST BATTLES is set to NORM.

## Credits

* [pret](https://pret.github.io/) for the [pokeemerald](https://github.com/pret/pokeemerald) decompilation this is built on.
* anon822's fast soft reset from the PokéCommunity "Simple Modifications Directory".
* Pokémon is © Nintendo / Creatures Inc. / GAME FREAK inc. This is a fan project, not affiliated with or endorsed by them.
