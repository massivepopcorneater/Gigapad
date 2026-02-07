#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
// LED index order should match the physical data chain.
// For the 9‑key revision, there are 9x SK6812 MINI LEDs (LED1..LED9). If your physical
// order differs, only RGB animations' "position" will look odd; the LEDs will still light.
led_config_t g_led_config = {
    // Key matrix -> LED index (NO_LED for positions without a key LED)
    {
        { 0, 1, 2 },
        { 3, 4, 5 },
        { 6, 7, 8 }
    },

    // LED index -> physical position (x, y) for RGB animations (roughly based on PCB coordinates)
    {
        {  0,   0 }, { 76,   0 }, {152,   0 },
        {  0,  76 }, { 76,  76 }, {152,  76 },
        {  0, 152 }, { 76, 152 }, {152, 152 }
    },

    // LED index -> flags (4 = key backlight)
    { 4,4,4,4,4,4,4,4,4 }
};
#endif
