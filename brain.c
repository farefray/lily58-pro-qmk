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

// Slave Oled
uint8_t moon_animation_frame = 0;    // keeps track of current moon frame
uint16_t moon_animation_counter = 0; // counts how many frames to wait before animating moon to next frame
static const char PROGMEM moon_animation[14][8] = {
    // clang-format off
    { 0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, },
    { 0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0x42, 0x00, },
    { 0x3C, 0x7E, 0xFF, 0xFF, 0xFF, 0xC3, 0x00, 0x00, },
    { 0x3C, 0x7E, 0xFF, 0xFF, 0xC3, 0x81, 0x00, 0x00, },
    { 0x3C, 0x7E, 0xFF, 0xC3, 0x81, 0x00, 0x00, 0x00, },
    { 0x3C, 0x7E, 0xC3, 0x81, 0x81, 0x00, 0x00, 0x00, },
    { 0x3C, 0x42, 0x81, 0x81, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, },
    { 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x42, 0x3C, },
    { 0x00, 0x00, 0x00, 0x81, 0x81, 0xC3, 0x7E, 0x3C, },
    { 0x00, 0x00, 0x00, 0x81, 0xC3, 0xFF, 0x7E, 0x3C, },
    { 0x00, 0x00, 0x81, 0xC3, 0xFF, 0xFF, 0x7E, 0x3C, },
    { 0x00, 0x00, 0xC3, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, },
    { 0x00, 0x42, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, },
    // clang-format on
};

static uint8_t increment_counter(uint8_t counter, uint8_t max)
{
    counter++;
    if (counter >= max)
    {
        return 0;
    }
    else
    {
        return counter;
    }
}

static void draw_moon(void)
{
    moon_animation_counter = increment_counter(moon_animation_counter, ANIMATE_MOON_EVERY_N_FRAMES);
    if (moon_animation_counter == 0)
    {
        moon_animation_frame = increment_counter(moon_animation_frame, 14);
        oled_set_cursor(MOON_COLUMN, MOON_LINE);
        oled_write_raw_P(moon_animation[moon_animation_frame], 8);
    }
}

void render_status_secondary(void)
{
    draw_moon();
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
