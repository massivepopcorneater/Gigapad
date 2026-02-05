#include QMK_KEYBOARD_H

/*
Matrix wiring (from your KiCad PCB):
- Rows (anodes):  GP26, GP29, GP28  => rows 0,1,2
- Cols (cathodes): GP3, GP4, GP2, GP1, GP27 => cols 0..4
- Encoder is wired THROUGH the matrix on column GP27:
    row0,col4 = encoder A pulse
    row1,col4 = encoder B pulse
    row2,col4 = encoder click (this one is a normal key press)
This file decodes (row0,col4) and (row1,col4) as a quadrature encoder and sends volume up/down.
*/

#define ENC_ROW_A 0
#define ENC_ROW_B 1
#define ENC_COL   4  // GP27

static uint8_t enc_prev = 0;
static int8_t  enc_accum = 0;

// Quadrature transition table (prev<<2 | curr) -> delta
// If your direction is flipped, swap KC_VOLU / KC_VOLD below.
static const int8_t enc_table[16] = {
     0, -1, +1,  0,
    +1,  0,  0, -1,
    -1,  0,  0, +1,
     0, +1, -1,  0
};

static void matrix_encoder_scan(void) {
    matrix_row_t ra = matrix_get_row(ENC_ROW_A);
    matrix_row_t rb = matrix_get_row(ENC_ROW_B);

    uint8_t a = (ra & (1u << ENC_COL)) ? 1u : 0u;
    uint8_t b = (rb & (1u << ENC_COL)) ? 1u : 0u;
    uint8_t curr = (a << 1) | b;

    uint8_t idx = (enc_prev << 2) | curr;
    int8_t delta = enc_table[idx];
    if (delta) {
        enc_accum += delta;

        // Most EC11-style encoders generate 4 state changes per detent.
        if (enc_accum >= 4) {
            tap_code(KC_VOLU);
            enc_accum = 0;
        } else if (enc_accum <= -4) {
            tap_code(KC_VOLD);
            enc_accum = 0;
        }
    }
    enc_prev = curr;
}

void matrix_scan_user(void) {
    matrix_encoder_scan();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_NO,   // row 0, col 4 = encoder A (decoded in matrix_scan_user)
        KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_NO,   // row 1, col 4 = encoder B (decoded in matrix_scan_user)
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PENT  // row 2, col 4 = encoder click
    )
};
