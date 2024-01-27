#include QMK_KEYBOARD_H

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

enum layers { _DEFAULT, _LOWER, _RAISE, _ADJUST };

// clang-format off
// layouts can be formatted using "!column -s , -t -o ," on the selection
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
KC_ESC   ,KC_1  ,KC_2  ,KC_3      ,KC_4    ,KC_5   /*,mcu      ,mcu*/      ,KC_6    ,KC_7     ,KC_8      ,KC_9    ,KC_0    ,KC_MINS ,
KC_TAB   ,KC_Q  ,KC_W  ,KC_E      ,KC_R    ,KC_T   /*,mcu      ,mcu*/      ,KC_Y    ,KC_U     ,KC_I      ,KC_O    ,KC_P    ,KC_NUHS ,
KC_LSFT  ,KC_A  ,KC_S  ,KC_D      ,KC_F    ,KC_G   /*,mcu      ,mcu*/      ,KC_H    ,KC_J     ,KC_K      ,KC_L    ,KC_SCLN ,KC_QUOT ,
KC_LCTL  ,KC_Z  ,KC_X  ,KC_C      ,KC_V    ,KC_B     ,KC_LBRC  ,KC_RBRC    ,KC_N    ,KC_M     ,KC_COMM   ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
/*s      ,s     ,s     ,*/KC_LALT ,KC_LGUI ,MO(1)    ,KC_SPC   ,KC_ENT     ,MO(2)   ,KC_BSPC  ,KC_RALT /*,s       ,s       ,s       ,*/
    ),
    [1] = LAYOUT(
_______ ,KC_F1   ,KC_F2   ,KC_F3     ,KC_F4   ,KC_F5   /*,mcu     ,mcu*/   ,KC_F6   ,KC_F7   ,KC_F8     ,KC_F9   ,KC_F10  ,KC_F11  ,
KC_F1   ,KC_F2   ,KC_F3   ,KC_F4     ,KC_F5   ,KC_F6   /*,mcu     ,mcu*/   ,KC_F7   ,KC_F8   ,KC_F9     ,KC_F10  ,KC_F11  ,KC_F12  ,
_______ ,KC_EXLM ,KC_AT   ,KC_HASH   ,KC_DLR  ,KC_PERC /*,mcu     ,mcu*/   ,KC_CIRC ,KC_AMPR ,KC_ASTR   ,KC_LPRN ,KC_RPRN ,KC_PIPE ,
_______ ,KC_NUBS ,_______ ,_______   ,_______ ,_______   ,_______ ,_______ ,XXXXXXX ,KC_UNDS ,KC_PLUS   ,KC_LCBR ,KC_RCBR ,_______ ,
/*s     ,s       ,s       ,*/_______ ,_______ ,_______   ,_______ ,_______ ,MO(3)   ,KC_DEL  ,_______ /*,s       ,s       ,s       ,*/
    ),
    [2] = LAYOUT(
_______ ,_______ ,_______ ,_______   ,_______ ,_______  /*,mcu     ,mcu*/   ,_______ ,_______ ,_______   ,_______  ,_______ ,KC_VOLU ,
KC_GRV  ,KC_1    ,KC_2    ,KC_3      ,KC_4    ,KC_5     /*,mcu     ,mcu*/   ,KC_6    ,KC_7    ,KC_8      ,KC_9     ,KC_MPRV ,KC_VOLD ,
KC_F1   ,KC_F2   ,KC_F3   ,KC_F4     ,KC_F5   ,KC_F6    /*,mcu     ,mcu*/   ,KC_LEFT ,KC_DOWN ,KC_UP     ,KC_RIGHT ,XXXXXXX ,XXXXXXX ,
KC_F7   ,KC_NUBS ,KC_F9   ,KC_F10    ,KC_F11  ,KC_F12     ,_______ ,_______ ,KC_MNXT ,KC_MINS ,KC_EQL    ,KC_LBRC  ,KC_MPLY ,_______ ,
/*s     ,s       ,s       ,*/_______ ,_______ ,MO(3)      ,_______ ,_______ ,_______ ,KC_DEL  ,_______/* ,s        ,s       ,s       ,*/
    ),
    [3] = LAYOUT(
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,XXXXXXX /*,mcu     ,mcu*/   ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,XXXXXXX /*,mcu     ,mcu*/   ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,RGB_HUD ,RGB_SAD ,RGB_VAD ,
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,XXXXXXX /*,mcu     ,mcu*/   ,KC_HOME ,KC_PGDN ,KC_PGUP   ,KC_END  ,XXXXXXX ,XXXXXXX ,
XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,RGB_TOG ,XXXXXXX ,XXXXXXX ,RGB_MOD   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
/*s     ,s       ,s       ,*/_______ ,_______ ,_______   ,_______ ,_______ ,_______ ,_______ ,_______/* ,s       ,s       ,s       ,*/
    )
};
// clang-format on

#ifdef OLED_ENABLE

void render_space_user(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt_user(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[]  = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[]  = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[]  = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[]  = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[]  = {0xc7, 0};
    static const char PROGMEM on_off_2[]  = {0xc8, 0};
    static const char PROGMEM off_on_1[]  = {0xc9, 0};
    static const char PROGMEM off_on_2[]  = {0xca, 0};
    static const char PROGMEM on_on_1[]   = {0xcb, 0};
    static const char PROGMEM on_on_2[]   = {0xcc, 0};

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift_user(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[]  = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[]  = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[]  = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[]  = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[]  = {0xc7, 0};
    static const char PROGMEM on_off_2[]  = {0xc8, 0};
    static const char PROGMEM off_on_1[]  = {0xc9, 0};
    static const char PROGMEM off_on_2[]  = {0xca, 0};
    static const char PROGMEM on_on_1[]   = {0xcb, 0};
    static const char PROGMEM on_on_2[]   = {0xcc, 0};

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_kb_LED_state_user(void) {
    // Host Keyboard LED Status
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock ? PSTR("N ") : PSTR("  "), false);
    oled_write_P(led_usb_state.caps_lock ? PSTR("C ") : PSTR("  "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S ") : PSTR("  "), false);
}
void render_wpm(void) {
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
}

void render_layer_state_user(void) {
    static const char PROGMEM default_layer[] = {0x20, 0x94, 0x95, 0x96, 0x20, 0x20, 0xb4, 0xb5, 0xb6, 0x20, 0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[]   = {0x20, 0x97, 0x98, 0x99, 0x20, 0x20, 0xb7, 0xb8, 0xb9, 0x20, 0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[]   = {0x20, 0x9a, 0x9b, 0x9c, 0x20, 0x20, 0xba, 0xbb, 0xbc, 0x20, 0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[]  = {0x20, 0x9d, 0x9e, 0x9f, 0x20, 0x20, 0xbd, 0xbe, 0xbf, 0x20, 0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LOWER:
            oled_write_P(lower_layer, false);
            break;
        case _RAISE:
            oled_write_P(raise_layer, false);
            break;
        case _ADJUST:
            oled_write_P(adjust_layer, false);
            break;
        default:
            oled_write_P(default_layer, false);
    }
}

bool oled_task_user(void) {
    // Slave does not have any oled
    if (is_keyboard_master()) {
        // Renders the current keyboard state (layers and mods)
        oled_write_P(PSTR("emil "), false);
        render_space_user();
        render_layer_state_user();
        render_space_user();
        render_mod_status_gui_alt_user(get_mods() | get_oneshot_mods());
        render_mod_status_ctrl_shift_user(get_mods() | get_oneshot_mods());
        render_kb_LED_state_user();
        render_wpm();
    }
    return false;
}
#endif
