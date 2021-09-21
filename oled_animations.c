#include "secondary_oled.c"

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _UTIL, _PAGE, _ADJUST); }

// Oled Rotations
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_270;
}

// Master Oled
void render_status_main(void)
{
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
    render_space();
    render_logo();
    render_space();
}

void render_status_secondary(void)
{
    oled_set_cursor(0, 0);                           // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
    sprintf(wpm_str, "WPM:%03d", get_current_wpm()); // edit the string to change wwhat shows up, edit %03d to change how many digits show up
}

void oled_task_user(void)
{
    // Establishing Sides
    if (is_keyboard_master())
    {
        render_status_main();
    }
    else
    {
        render_status_secondary();
    }
}

// Oled Wakes
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case COLEMAK:
        if (record->event.pressed)
        {
            layer_clear();
            layer_on(_COLEMAK);
        }
        return false;
    case QWERTY:
        if (record->event.pressed)
        {
            layer_clear();
            layer_on(_QWERTY);
        }
        return false;
    case GAME:
        if (record->event.pressed)
        {
            layer_clear();
            layer_on(_GAME);
        }
        return false;
    }

    return true;
}
