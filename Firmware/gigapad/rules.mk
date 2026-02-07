# Enable per-key RGB matrix (SK6812/WS2812 style)
RGB_MATRIX_ENABLE = yes
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = no

# Rotary encoder is wired to dedicated GPIOs (NOT through the key matrix)
ENCODER_ENABLE = yes

# OLED (SSD1306 over I2C)
OLED_ENABLE = yes

# RP2040 uses the vendor I2C driver
I2C_DRIVER = vendor
