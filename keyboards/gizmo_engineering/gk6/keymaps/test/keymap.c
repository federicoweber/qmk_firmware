/* Copyright 2020 Gizmo Engineering
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

enum keycodes {
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL | GUI  |  Alt |Lower |  Back|Space |Space |  Alt |Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_gk6_5x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SLSH, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_ENT,  \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_BSPC, KC_SPC, KC_SPC,  KC_RALT,  RAISE,   KC_LEFT, KC_DOWN, KC_RGHT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |RGB_TG|RGB_HU|RGB_SD|RGB_SI|RGB_VD|RGB_VI|RGB_M |   <  |   >  |   |  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Debug |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_gk6_5x12( \
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______,  _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______, \
  _______, _______,  _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
  _______, RGB_TOG,  RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_MOD, _______, _______, KC_PIPE, KC_BSLS, \
  DEBUG,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | F7   |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS | PSCR |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Home | End  | Ins  | Play |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  <<  |  >>  | Mute | Vol- | Vol+ |      |      |      |      | PgUp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | PgDn |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_gk6_5x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_CLCK, KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_HOME, KC_END,  KC_INS,  KC_MPLY, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______  \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
          } else {
            layer_off(_LOWER);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
          } else {
            layer_off(_RAISE);
          }
          return false;
          break;
      }
    return true;
};


const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, C1_8, C2_8, C3_8},     //0 led1
    {0, C1_7, C2_7, C3_7},     //1 led2
    {0, C1_6, C2_6, C3_6},     //2 led3
    {0, C1_5, C2_5, C3_5},     //3 led4
    {0, C1_4, C2_4, C3_4},     //4 led5
    {0, C1_3, C2_3, C3_3},     //5 led6
    {0, C1_2, C2_2, C4_3},     //6 led7
    {0, C1_1, C3_2, C4_2},     //7 led7bis
    {0, C9_1, C8_1, C7_1},     //8 led8
    {0, C9_2, C8_2, C7_2},     //9 led9
    {0, C9_3, C8_3, C7_3},     //10 led10
    {0, C9_4, C8_4, C7_4},     //11 led11
    {0, C9_5, C8_5, C7_5},     //12 led12
    {0, C9_6, C8_6, C7_6},     //13 led13
    {0, C9_7, C8_7, C6_6},     //14 led14
    {0, C9_8, C7_7, C6_7},     //15 led15
    {0, C1_16, C2_16, C3_16},  //16 led16
    {0, C1_15, C2_15, C3_15},  //17 led17
    {0, C1_14, C2_14, C3_14},  //18 led18
    {0, C1_13, C2_13, C3_13},  //19 led19
    {0, C1_12, C2_12, C3_12},  //20 led20
    {0, C1_11, C2_11, C3_11},  //21 led21
    {0, C1_10, C2_10, C4_11},  //22 led22
    {0, C9_9, C8_9, C7_9},     //23 led23
    {0, C9_10, C8_10, C7_10},  //24 led24
    {0, C9_11, C8_11, C7_11},  //25 led25
    {0, C9_12, C8_12, C7_12},  //26 led26
    {0, C9_13, C8_13, C7_13},  //27 led27
    {0, C9_14, C8_14, C7_14},  //28 led28
    {0, C9_15, C8_15, C6_14},  //29 led29
    {0, C9_16, C7_15, C6_15},  //30 led30
    {1, C1_8, C2_8, C3_8},     //31 led31
    {1, C1_7, C2_7, C3_7},     //32 led32
    {1, C1_6, C2_6, C3_6},     //33 led33
    {1, C1_5, C2_5, C3_5},     //34 led34
    {1, C1_4, C2_4, C3_4},     //35 led35
    {1, C1_3, C2_3, C3_3},     //36 led36
    {1, C1_2, C2_2, C4_3},     //37 led37
    {1, C1_1, C3_2, C4_2},     //38 led37bis
    {1, C9_1, C8_1, C7_1},     //39 led38
    {1, C9_2, C8_2, C7_2},     //40 led39
    {1, C9_3, C8_3, C7_3},     //41 led40
    {1, C9_4, C8_4, C7_4},     //42 led41
    {1, C9_5, C8_5, C7_5},     //43 led42
    {1, C9_6, C8_6, C7_6},     //44 led43
    {1, C9_7, C8_7, C6_6},     //45 led44
    {1, C9_8, C7_7, C6_7},     //46 led45
    {1, C1_16, C2_16, C3_16},  //47 led46
    {1, C1_15, C2_15, C3_15},  //48 led47
    {1, C1_14, C2_14, C3_14},  //49 led48
    {1, C1_13, C2_13, C3_13},  //50 led49
    {1, C1_12, C2_12, C3_12},  //51 led50
    {1, C1_11, C2_11, C3_11},  //52 led51
    {1, C1_10, C2_10, C4_11},  //53 led52
    {1, C1_9, C3_10, C4_10},   //54 led52bis
    {1, C9_9, C8_9, C7_9},     //55 led53
    {1, C9_10, C8_10, C7_10},  //56 led54
    {1, C9_11, C8_11, C7_11},  //57 led55
    {1, C9_12, C8_12, C7_12},  //58 led56
    {1, C9_13, C8_13, C7_13},  //59 led57
    {1, C9_14, C8_14, C7_14},  //60 led58
    {1, C9_15, C8_15, C6_14},  //61 led59
    {1, C9_16, C7_15, C6_15},  //62 led60
};

led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {1, 6, 11, 16, 21, 27, 32, 38, 44, 49, 54, 59},
    {2, 7, 12, 17, 22, 28, 33, 39, 45, 50, 55, 60},
    {3, 8, 13, 18, 23, 29, 34, 40, 46, 51, 56, 61},
    {4, 9, 14, 19, 24, 30, 35, 41, 47, 52, 57, 62},
    {5, 10, 15, 20, 25, 31, 36, 42, 48, 53, 58, 63},
}, {
    // LED Index to Physical Position
    {0, 0},  {20, 0},  {40, 0},  {61, 0},  {81, 0},  {101, 0},  {122, 0},  {142, 0},  {162, 0},  {183, 0},  {203, 0},  {224, 0},
    {0, 13}, {20, 13}, {40, 13}, {61, 13}, {81, 13}, {101, 13}, {122, 13}, {142, 13}, {162, 13}, {183, 13}, {203, 13}, {224, 13},
    {0, 26}, {20, 26}, {40, 26}, {61, 26}, {81, 26}, {101, 26}, {122, 26}, {142, 26}, {162, 26}, {183, 26}, {203, 26}, {224, 26},
    {0, 51}, {20, 51}, {40, 51}, {61, 51}, {81, 51}, {101, 51}, {122, 51}, {142, 51}, {162, 51}, {183, 51}, {203, 51}, {224, 51},
    {0, 64}, {20, 64}, {40, 64}, {61, 64}, {81, 64}, {101, 64}, {122, 64}, {142, 64}, {162, 64}, {183, 64}, {203, 64}, {224, 64},
    {81, 76}, {101, 76}, {122, 76}
}, {
    // LED Index to Flag
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x01, 0x01, 0x01
} };

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
