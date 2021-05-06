#include "print.h"

RGB_MATRIX_EFFECT(TEST_LEDS_MATRIX)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

int active_led = 0;
int led_color = 0;
int led_matrix[] = {
    0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55,
    1, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56,
    2, 7, 12, 17, 22, 27, 32, 37, 42, 47, 52, 57,
    3, 8, 13, 18, 23, 28, 33, 38, 43, 48, 53, 58,
    4, 9, 14, 19, 24, 29, 34, 39, 44, 49, 54, 59
};

static void set_led_color(int i) {
    switch (led_color) {
        case 0:
        rgb_matrix_set_color(i, RGB_RED);
        break;
        case 1:
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
        case 2:
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
    }
}

static void advance_matrix(effect_params_t* params) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (i == led_matrix[active_led]) {
            set_led_color(led_matrix[active_led]);
        }else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }

    active_led ++;
    if (active_led >= DRIVER_LED_TOTAL) {
        led_color ++;
        active_led = 0;
    }

    if (led_color >= 3) {
        led_color = 0;
    }
}

static bool TEST_LEDS_MATRIX(effect_params_t* params) {
    if (!params->init) {
        if (scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16)) % 20 == 0) {
            advance_matrix(params);
        }
        return false;
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0, 0, 0);
    }

    return led_max < DRIVER_LED_TOTAL;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
