#pragma once

#include QMK_KEYBOARD_H

enum my_lily_layers
{
    _QWERTY = 0,
    _GAME,
    _UTIL,
    _PAGE,
};

enum my_lily_keycodes
{
    QWERTY = SAFE_RANGE,
    GAME
};

// Layers States
void render_layer_state(void)
{
    oled_write_P(PSTR("Layer"), false);

    // Be aware that length of layer captions should be always 5 characters
    switch (get_highest_layer(layer_state))
    {

    case _QWERTY:
        oled_write_P(PSTR("QWERT"), false);
        // autoshift_enable();
        break;
    case _GAME:
        oled_write_P(PSTR("SECON"), false);
        // autoshift_disable();
        break;
    case _UTIL:
        oled_write_P(PSTR("THIRD"), false);
        // autoshift_disable();
        break;
    case _PAGE:
        oled_write_P(PSTR("FOURT"), false);
        // autoshift_disable();
        break;
    default:
        oled_write_P(PSTR("?????"), false);
        break;
    }
}
