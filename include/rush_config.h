#ifndef GUARD_RUSH_CONFIG_H
#define GUARD_RUSH_CONFIG_H

// Emerald Rush configuration.
//
// The RUSH_* options are Emerald Rush's general features. The B_* options under
// BATTLE SPEED are the battle intro and battle speed-ups. Set a TRUE option to FALSE, or a speed option to its
// "vanilla" value, to get the original Emerald behaviour back for that feature.

// ---------------------------------------------------------------------------
// GENERAL
// ---------------------------------------------------------------------------
#define RUSH_INSTANT_TEXT               TRUE  // Text prints instantly everywhere.
#define RUSH_RNG_FIX                    TRUE  // RNG is seeded from a timer started at boot mixed with the RTC, so every playthrough differs.
#define RUSH_RUN_INDOORS                TRUE  // Running Shoes work on every map (tiles that block running, like tall grass, still do).
#define RUSH_FAST_UNDERWATER            TRUE  // Move at running speed while diving.
#define RUSH_NO_SAVE_OVERWRITE_PROMPT   TRUE  // Skip "There is already a saved file. Is it okay to overwrite it?".
#define RUSH_REPEL_PROMPT               TRUE  // When a Repel wears off, ask to use another of the same kind if you have one.
#define RUSH_NO_MATCH_CALLS             TRUE  // (Only used when RUSH_NAV_CALLS_OPTION is FALSE) trainers never call you.
#define RUSH_NAV_CALLS_OPTION           TRUE  // Options menu gets "NAV CALLS" ON/OFF: whether trainers call you on the PokéNav (Match Call).
                                              // Defaults to OFF. FALSE = calls always off.
                                              // With this on the options list has 9 rows, so the "OPTION" title box is dropped to fit.
#define RUSH_FAST_SOFT_RESET            TRUE  // Soft reset (A+B+Start+Select) skips the copyright screen, intro and title and goes
                                              // straight to the CONTINUE / NEW GAME menu.
#define RUSH_SKIP_FIELD_MOVE_CUTIN      TRUE  // Skip the Pokémon cut-in when using Cut, Surf, Strength, Rock Smash, etc. in the overworld.
#define RUSH_TRADE_ANYTIME              TRUE  // Trades aren't restricted by National Dex or Champion status.
#define RUSH_MON_ANIM_OPTION            TRUE  // Options menu gets "POKéMON ANIM" ON/OFF in place of TEXT SPEED (text is instant anyway).
                                              // Controls the animation a Pokémon does when sent out (and in the summary/Pokédex).
                                              // Defaults to OFF. FALSE = animations always on, Text Speed row is back.
#define RUSH_FAST_BATTLES_OPTION        TRUE  // Options menu gets "FAST BATTLES" NORM/FAST. FAST (default) = every B_* speed-up below,
                                              // NORM = vanilla Emerald battle speed. FALSE = always FAST, no menu row.
// The low-HP beep only looping 3 times is an edit to sound/songs/se_low_health.s, not a switch here.

// ---------------------------------------------------------------------------
// BATTLE SPEED (these are the FAST BATTLES = FAST values; NORM uses vanilla,
// see include/rush_speed.h)
// ---------------------------------------------------------------------------
// Battle intro
#define B_TRANSITION_SPEED          4     // Battle transition (the screen wipe from the overworld) runs this many steps per frame. 1 = vanilla.
#define B_TRANSITION_FLASHES        1     // White flashes before the transition starts. 3 = vanilla.
#define B_INTRO_WINDOW_SPEED        8     // Speed the black bars open at the start of a battle. 1 = vanilla. Must divide 32 evenly (1, 2, 4, 8).
#define B_INTRO_SLIDE_SPEED         8     // Pixels per frame the battle scene, trainers and wild Pokémon slide in. 2 = vanilla.
                                          // Must divide 240 and 96 evenly (2, 3, 4, 6, 8, 12).
#define B_PARTY_SUMMARY_FRAMES      16    // Frames the party Poké Ball bars stay on screen. 92 = vanilla.
#define B_SENDOUT_SPEED             2     // Speed of the trainer throwing out the first Poké Ball (slide-out, delay, ball arc). 1 = vanilla.
#define B_INTRO_MSG_NO_BUTTON       TRUE  // "Wild X appeared!" / "X would like to battle!" continue on their own after a short pause
                                          // ({PAUSE 60}, halved by B_BATTLE_SPEED 2, in src/battle_message.c) instead of waiting for A.

// In battle
#define B_BATTLE_SPEED              2     // Fast-forward: all battle logic, animations and bars run this many times per frame
                                          // (sound and screen fades play at normal speed). 1 = off. Not used in link/recorded battles.
#define B_MOVE_ANIM_SPEED           2     // Attack/status animations (Battle Scene ON) run this many times faster, on top of B_BATTLE_SPEED.
                                          // 1 = just the B_BATTLE_SPEED fast-forward.
#define B_MON_ANIM_SPEED            3     // With POKéMON ANIM on: the send-out animation (and its start delay) runs this many times faster
                                          // in battle, on top of B_BATTLE_SPEED. 1 = vanilla.
#define B_BALL_ANIM_SPEED           2     // Extra speed for the capture throw, the waits between shakes, and the pause before
                                          // the ball breaks open. On top of B_BATTLE_SPEED. 1 = vanilla.
#define B_MSG_WAIT_SPEED            3     // Pauses after battle messages count down this many frames per frame. 1 = vanilla.
#define B_MSG_WAIT_SKIP_WITH_AB     TRUE  // Pressing A or B cuts the pause after a battle message short (not in link/recorded battles).
#define B_PAUSE_SPEED               4     // Speed of battle script "pause" commands. 1 = vanilla.
#define B_HP_BAR_SPEED              3     // HP bar moves at least this many pixels per frame (the bar is 48 pixels). 0 = vanilla (1 HP per frame).
#define B_EXP_BAR_SPEED             4     // EXP bar fills this many pixels per frame (the bar is 64 pixels). 1 = vanilla.
#define B_SKIP_CRY_WAIT             TRUE  // Don't wait for a Pokémon's cry to finish after it's sent out (single-player battles).
#define B_HEALTHBOX_SLIDE_SPEED     2     // Multiplier for how fast healthboxes slide in. 1 = vanilla.
#define B_HIT_BLINK_FRAMES          16    // How long a Pokémon blinks after taking a hit. 32 = vanilla.
#define B_END_FADE_DELTA            8     // Fade-out at the end of a battle: brightness steps per frame (31 total). 2 = vanilla.
#define B_SCRIPT_COMMANDS_PER_FRAME 16    // Battle script commands that can run back to back in one frame. Vanilla runs 1 per frame,
                                          // which adds ~25 frames of dead time to every attack. Not used in link/recorded battles.

#endif // GUARD_RUSH_CONFIG_H
