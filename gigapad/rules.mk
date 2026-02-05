# Enable per-key RGB matrix (SK6812/WS2812 style)
RGB_MATRIX_ENABLE = yes
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = no

# We are decoding the encoder through the key matrix, so do NOT enable QMK's encoder feature.
ENCODER_ENABLE = no

# Optional: turn on if you really have the SSD1306 wired and want it
# OLED_ENABLE = yes
