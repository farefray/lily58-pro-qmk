#pragma once

#include QMK_KEYBOARD_H

enum my_lily_layers
{
    _COLEMAK = 0,
    _QWERTY,
    _GAME,
    _UTIL,
    _PAGE,
};

enum my_lily_keycodes
{
    COLEMAK = SAFE_RANGE,
    QWERTY,
    GAME
};

// Layers States
void render_layer_state(void)
{
    oled_write_P(PSTR("Layer: "), false);

    // Be aware that length of layer captions should be always 5 characters, otherwise the layout will look eerie.
    switch (get_highest_layer(layer_state))
    {
    case _COLEMAK:
        oled_write_P(PSTR("COLEMAK\n"), false);
        autoshift_enable();
        break;
    case _QWERTY:
        oled_write_P(PSTR("QWERTY\n"), false);
        autoshift_enable();
        break;
    case _GAME:
        oled_write_P(PSTR("GAME\n"), false);
        autoshift_disable();
        break;
    case _UTIL:
        oled_write_P(PSTR("UTIL\n"), false);
        autoshift_disable();
        break;
    case _PAGE:
        oled_write_P(PSTR("PAGE\n"), false);
        autoshift_disable();
        break;
    default:
        oled_write_P(PSTR("?????\n"), false);
        break;
    }
}
