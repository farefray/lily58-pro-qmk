#pragma once

#include QMK_KEYBOARD_H

enum my_lily_layers {
    _COLEMAK = 0,
    _QWERTY,
    _GAME,
    _UTIL,
    _PAGE,
    _ADJUST,
};

enum my_lily_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    GAME
};
