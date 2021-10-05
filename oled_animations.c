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
