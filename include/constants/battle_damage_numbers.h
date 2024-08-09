#ifndef GUARD_CONSTANTS_BATTLE_DAMAGE_NUMS_H
#define GUARD_CONSTANTS_BATTLE_DAMAGE_NUMS_H

#define DAMAGE_NUMBER_TIME 90 // Number of frames each number stays on-screen for
#define DAMAGE_NUMBER_DELAY 2 // Number of frames in between each number appearing

// the default color for the numbers is white for damage and green for healing.
// if this config is TRUE, damage numbers will be orange for super effective hits and gray for not very effective hits.
#define DN_CONFIG_EFFECTIVENESS_PALETTE TRUE

// if TRUE, the damage numbers are triggered by the hitanimation battle scrcmd, meaning they will only appear when the damage is caused by a direct attack or weather.
// if FALSE, the damage numbers are triggered by the healthbarupdate battle scrcmd, meaning they appear pretty much any time a mon's HP changes (including healing, making a substitute, hitting a substitute, poison, etc)
#define DN_CONFIG_ONLY_ATTACK_DAMAGE FALSE

#endif
