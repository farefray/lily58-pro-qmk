bool is_copied = false;
bool is_gui_pressed = false;

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
    case COPY_MACRO:
        if (record->event.pressed)
        {
            if (!is_copied)
            {
                is_copied = true;
                tap_code16(LCTL(KC_C));
            }
            else
            {
                tap_code16(LCTL(KC_V));
                is_copied = false;
            }
        }
        return false;
    }

    // hack for windows layer switching together with language
    if (keycode == KC_LGUI) {
        if (record->event.pressed)
            is_gui_pressed = true;
        else
            is_gui_pressed = false;
    }
    
    if (keycode == KC_SPC) {
        if (record->event.pressed) {
            if (is_gui_pressed == true ) {
                layer_invert(_QWERTY);
            }
        }
    }

    return true;
}
