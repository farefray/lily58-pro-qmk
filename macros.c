bool is_copied = false;

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

    return true;
}
