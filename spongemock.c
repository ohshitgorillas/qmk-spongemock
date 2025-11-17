#include "spongemock.h"
#include <stdlib.h> // For rand()

// Private variables and functions
static bool spongemock_active = false;

static bool random_bool(void) {
  return rand() & 1;
}

static uint16_t last_keycode = KC_NO;


// --- User-facing functions ---
void enable_spongemock(void) {
    spongemock_active = true;
}

void disable_spongemock(void) {
    spongemock_active = false;
    last_keycode = KC_NO;
}

void toggle_spongemock(void) {
    spongemock_active = !spongemock_active;
    last_keycode = KC_NO;
}

bool is_spongemock_active(void) {
    return spongemock_active;
}


// main functions
bool process_record_spongemock(uint16_t keycode, keyrecord_t *record) {
    // Handle activation/deactivation keycodes first
    switch (keycode) {
        case SPONGEMOCK_TOGGLE:
            if (record->event.pressed) {
                toggle_spongemock();
            }
            return false; // Keycode was handled
        case SPONGEMOCK_ON:
            if (record->event.pressed) {
                enable_spongemock();
            }
            return false; // Keycode was handled
        case SPONGEMOCK_OFF:
            if (record->event.pressed) {
                disable_spongemock();
            }
            return false; // Keycode was handled
    }

    if (!is_spongemock_active()) {  // spongemock is not active
        return true;  // pass the key event
    }

    if (record->event.pressed) {
        if (keycode == KC_SPC) {
            if (last_keycode == KC_SPC) {  // double space exits spongemock mode
                disable_spongemock();
                last_keycode = KC_NO;  // reset last_keycode
                return false; // don't send the second space
            } else {
                last_keycode = KC_SPC;  // set last_keycode to space
                return true; // Let the space through
            }
        } else if (keycode >= KC_A && keycode <= KC_Z) {
            if (random_bool()) {
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
        }
        last_keycode = keycode;  // set last_keycode to the current keycode
    }
    return true;  // pass the key event
};
