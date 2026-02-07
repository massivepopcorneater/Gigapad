#include QMK_KEYBOARD_H

/*
Hardware (9-key revision, from your KiCad PCB):

- Key matrix: 3x3
  Rows (diode cathodes): GP0, GP27, GP26
  Cols (switch side):    GP2, GP4, GP3

- Rotary encoder (NOT in the matrix):
  A -> GP29 (A3)
  B -> GP28 (A2)

- OLED (SSD1306 over I2C):
  SDA -> GP6, SCL -> GP7
*/

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index != 0) return true;
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
static void render_oled(void) {
    oled_clear();
    oled_set_cursor(0, 0);
    oled_write_ln(PSTR("Gigapad"), false);
    oled_write_ln(PSTR("9-key + enc"), false);
    oled_write_ln(PSTR("Vol: turn knob"), false);
}

bool oled_task_user(void) {
    render_oled();
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
