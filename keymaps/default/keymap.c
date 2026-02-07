#include QMK_KEYBOARD_H

// Default layout for the 9-key revision (3x3) + dedicated rotary encoder.

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index != 0) return true;
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    oled_write_ln(PSTR("Gigapad"), false);
    oled_write_ln(PSTR("Default"), false);
    oled_write_ln(PSTR("Knob: Vol"), false);
    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_P7, KC_P8, KC_P9,
        KC_P4, KC_P5, KC_P6,
        KC_P1, KC_P2, KC_P3
    )
};
