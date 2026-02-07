#pragma once

// ===== RGB Matrix (12x SK6812 MINI) =====
#define RGB_DI_PIN GP0
#define RGB_MATRIX_LED_COUNT 12

#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180

// OLED is wired on the PCB to GP6 (SDA) and GP7 (SCL).
// Enable OLED in rules.mk if you want to use it.
