#include QMK_KEYBOARD_H

// ===== Matrix-wired encoder decode =====
// Your encoder is wired into the key matrix on column 4:
//  - row 0, col 4 = encoder A
//  - row 1, col 4 = encoder B
//  - row 2, col 4 = encoder CLICK (mapped in the keymap)
//
// We decode A/B in software and send Volume Up/Down.

#define ENC_COL 4
#define ENC_ROW_A 0
#define ENC_ROW_B 1

// Quadrature lookup table (prev<<2 | cur) -> delta
// If your direction is inverted, swap KC_VOLU and KC_VOLD below.
static const int8_t enc_table[16] = {
    0, -1, +1,  0,
   +1,  0,  0, -1,
   -1,  0,  0, +1,
    0, +1, -1,  0
};

static uint8_t enc_prev = 0;   // previous AB state
static int8_t  enc_accum = 0;  // accumulate transitions until a detent

static inline uint8_t read_enc_ab(void) {
    // matrix_get_row() returns a bitmask of columns for the given row
    const matrix_row_t rA = matrix_get_row(ENC_ROW_A);
    const matrix_row_t rB = matrix_get_row(ENC_ROW_B);

    const uint8_t a = (rA & ((matrix_row_t)1 << ENC_COL)) ? 1 : 0;
    const uint8_t b = (rB & ((matrix_row_t)1 << ENC_COL)) ? 1 : 0;
    return (a << 1) | b;
}

void matrix_scan_user(void) {
    const uint8_t cur = read_enc_ab();
    const uint8_t idx = (enc_prev << 2) | cur;
    const int8_t  delta = enc_table[idx];

    if (delta != 0) {
        enc_accum += delta;
        // Most EC11 encoders produce 4 transitions per detent.
        if (enc_accum >= 4) {
            tap_code(KC_VOLU);
            enc_accum = 0;
        } else if (enc_accum <= -4) {
            tap_code(KC_VOLD);
            enc_accum = 0;
        }
    }

    enc_prev = cur;
}

// ===== Keymap =====
// 3 rows x 5 cols = 15 positions
// Last column is encoder A/B/click. A/B must be KC_NO (decoded above).

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_NO,
        KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_NO,
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PENT
    )
};
