#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
// LED index order MUST match the physical data chain.
// From your PCB netlist: GPIO0 -> LED4 -> LED3 -> LED2 -> LED1 -> LED5 -> LED6 -> LED7 -> LED8 -> LED11 -> LED12 -> LED10 -> LED9
led_config_t g_led_config = {
    // Key matrix -> LED index (NO_LED for positions without a key LED)
    {
        {  2,  1,  0,  7, NO_LED },
        {  5,  6,  8,  9, NO_LED },
        { 10, 11,  4,  3, NO_LED }
    },

    // LED index -> physical position (x, y) for RGB animations (roughly based on PCB coordinates)
    {
        {  0,   0 }, {  0,  76 }, {  0, 152 }, {  0, 226 },
        { 76, 226 }, { 77, 152 }, { 76,  76 }, { 76,   0 },
        {152,   0 }, {152,  76 }, {152, 152 }, {152, 226 }
    },

    // LED index -> flags (4 = key backlight)
    { 4,4,4,4, 4,4,4,4, 4,4,4,4 }
};
#endif
