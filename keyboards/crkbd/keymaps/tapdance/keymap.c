/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


// Tap Dance declarations
enum {
    TD_Q,
    TD_SPACE,
    TD_ESC_CAPS
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LGUI(KC_Q)),
    [TD_SPACE] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, LGUI(KC_SPC)),
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};




// char     key_name = ' ';
// uint16_t last_keycode;
// uint8_t  last_row;
// uint8_t  last_col;

static void oled_render_layer_state(void) {
    // oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("LOWER"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("MEDIA"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

// static const char *depad_str(const char *depad_str, char depad_char) {
//     while (*depad_str == depad_char)
//         ++depad_str;
//     return depad_str;
// }

// static void oled_render_keylog(void) {
//     oled_write_char('0' + last_row, false);
//     oled_write_P(PSTR("x"), false);
//     oled_write_char('0' + last_col, false);
//     oled_write_P(PSTR(", k"), false);
//     const char *last_keycode_str = get_u16_str(last_keycode, ' ');
//     oled_write(depad_str(last_keycode_str, ' '), false);
//     oled_write_P(PSTR(":"), false);
//     oled_write_char(key_name, false);
//     oled_advance_page(true);
// }


static void render_logo(void) {
    static const char PROGMEM kids[] = {
        // 'kids', 32x128px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x70, 0x98, 0x6c, 
        0x14, 0xae, 0x56, 0x2a, 0x96, 0x2a, 0xce, 0xaa, 0xcc, 0xf2, 0x6c, 0xf0, 0x88, 0x60, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0xbe, 0x41, 0x0a, 0x05, 0x50, 0x24, 
        0x49, 0x82, 0x10, 0xa5, 0x5a, 0x0b, 0x16, 0xa9, 0x06, 0xdb, 0xa5, 0x1f, 0xab, 0x8d, 0x20, 0x8a, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x2c, 0x83, 0x10, 0x08, 0x80, 0x09, 0x12, 
        0xa4, 0x59, 0xa2, 0x1d, 0x62, 0x8f, 0x2a, 0x96, 0x23, 0x96, 0x23, 0x9f, 0x62, 0x9f, 0x46, 0x10, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x50, 0xa0, 0x48, 0xb4, 0x40, 0xa8, 
        0x00, 0xaa, 0x04, 0x91, 0x02, 0x08, 0x01, 0x32, 0x24, 0x1a, 0x85, 0x12, 0x21, 0x20, 0xc0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x10, 0x8d, 0x02, 0x45, 0x02, 0x05, 0x00, 0x03, 
        0x04, 0x01, 0x2e, 0xd0, 0x25, 0x4a, 0x90, 0x68, 0x82, 0x20, 0x00, 0x00, 0x08, 0x02, 0x20, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x10, 0x04, 0x02, 0x09, 0x00, 0x04, 0x00, 
        0x08, 0x00, 0x00, 0x02, 0x01, 0x06, 0x09, 0x02, 0x1c, 0x23, 0x58, 0x80, 0x00, 0x80, 0x00, 0x05, 
        0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x01, 0x80, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 
        0x20, 0x80, 0x10, 0x00, 0xa8, 0x00, 0x10, 0x20, 0x70, 0xb8, 0x78, 0x58, 0xbc, 0x69, 0x7a, 0xa4, 
        0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0xf0, 0xe8, 0xa0, 0xf0, 0xe0, 0xa0, 0xc0, 0x60, 0x80, 
        0x40, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x02, 0x00, 0x01, 0x22, 0x00, 
        0xfa, 0x55, 0xea, 0xff, 0xfd, 0xdf, 0xf7, 0xbf, 0xdd, 0xf7, 0xfe, 0x5b, 0xfe, 0xad, 0xfb, 0xde, 
        0xb5, 0x7c, 0xf4, 0xb8, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 
        0xff, 0xff, 0x7f, 0xfa, 0xfb, 0xba, 0x71, 0xf5, 0x7b, 0x7e, 0xfd, 0x6b, 0xf3, 0xc6, 0xe5, 0xce, 
        0xd5, 0xfe, 0xd3, 0x05, 0x52, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x80, 0x00, 
        0xff, 0x55, 0xab, 0xf4, 0x0b, 0x86, 0x43, 0x87, 0x43, 0x06, 0x8e, 0xb5, 0xef, 0x15, 0xfb, 0x4f, 
        0xb5, 0x1f, 0x83, 0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
        0xfd, 0xf7, 0xde, 0x75, 0xcb, 0xbd, 0x53, 0x1a, 0x25, 0x1a, 0x05, 0x0e, 0x41, 0x97, 0x20, 0xcd, 
        0x12, 0xec, 0xa0, 0xec, 0xa0, 0xf8, 0x40, 0xa4, 0x88, 0x00, 0x2a, 0x04, 0x09, 0x00, 0x00, 0x00, 
        0x05, 0x99, 0x23, 0x15, 0x2a, 0x90, 0x2a, 0x54, 0x02, 0x54, 0xa9, 0x12, 0x65, 0x8a, 0x05, 0x70, 
        0x0f, 0xd0, 0xaf, 0xda, 0xe5, 0xfe, 0xf3, 0xff, 0xeb, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x52, 0x05, 0x00, 0x91, 0x04, 0x40, 0x00, 0x0e, 
        0x9d, 0x04, 0xbf, 0x2f, 0xd7, 0x7f, 0xff, 0xb5, 0x7f, 0xb9, 0xdf, 0x3d, 0xdf, 0xbe, 0xdc, 0xf8, 
        0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x04, 0x00, 0x20, 0x04, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x09, 0x3f, 0x2a, 0x5f, 0x3b, 0x57, 0x6b, 0x77, 0x3d, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x40, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(kids, sizeof(kids));
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        // oled_render_keylog();
        oled_render_layer_state();
    } else {
        render_logo();
    }
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270; // layer state
    }
    
    return OLED_ROTATION_270;  // Image
    // return rotation;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    MT(MOD_LSFT,KC_A),    MT(MOD_LCTL,KC_R),    MT(MOD_LALT,KC_S),    MT(MOD_LGUI,KC_T),    KC_G,                         KC_M,    MT(MOD_LGUI | MOD_RGUI,KC_N),    MT(MOD_LALT,KC_E),    MT(MOD_LCTL | MOD_RCTL,KC_I), MT(MOD_LSFT | MOD_RSFT,KC_O), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_ESC_CAPS),    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(1),TD(TD_SPACE),     KC_ENT, MO(2), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_TRNS,  KC_SPC,     KC_ENT,  MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(3),  KC_SPC,     KC_ENT, KC_TRNS, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
