#pragma once

// ===== RGB Matrix (12x SK6812 MINI) =====
#define RGB_DI_PIN GP1
#define RGB_MATRIX_LED_COUNT 9

#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180

// ===== Rotary encoder (dedicated pins, not in the key matrix) =====
// From your KiCad PCB: encoder A -> GPIO29 (A3), encoder B -> GPIO28 (A2)
#define ENCODERS_PAD_A { GP29 }
#define ENCODERS_PAD_B { GP28 }

// ===== OLED (SSD1306 over I2C) =====
// From your KiCad PCB: SDA -> GPIO6, SCL -> GPIO7
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7
#define I2C1_CLOCK_SPEED 400000

// Most 0.96\" SSD1306 modules are 128x64; change to OLED_DISPLAY_128X32 if yours is 128x32.
#define OLED_DISPLAY_128X64
