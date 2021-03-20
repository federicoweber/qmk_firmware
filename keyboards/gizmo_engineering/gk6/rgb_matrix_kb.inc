#include "print.h"

RGB_MATRIX_EFFECT(TEST_LEDS_RED)
RGB_MATRIX_EFFECT(TEST_LEDS_GREEN)
RGB_MATRIX_EFFECT(TEST_LEDS_BLUE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool TEST_LEDS_RED(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0x00, 0x00);
  }
  return led_max < DRIVER_LED_TOTAL;
}

static bool TEST_LEDS_GREEN(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0xff, 0x00);
  }
  return led_max < DRIVER_LED_TOTAL;
}

static bool TEST_LEDS_BLUE(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0x00, 0x00, 0xff);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
