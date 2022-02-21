bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
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
