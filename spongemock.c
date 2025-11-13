#include "spongemock.h"
#include <stdlib.h> // For rand()

// Private variables and functions
static bool spongemock_active = false;

static bool random_bool(void) {
  return rand() & 1;
}


// --- User-facing functions ---
void enable_spongemock(void) {
    spongemock_active = true;
}

void disable_spongemock(void) {
    spongemock_active = false;
}

void toggle_spongemock(void) {
    spongemock_active = !spongemock_active;
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

    // If not active, let all other keys pass through
    if (!spongemock_active) {
        return true;
    } else {  // aPplY left shIfT randOMlY
        if (keycode >= KC_A && keycode <= KC_Z) {
            if (record->event.pressed) {
                if (random_bool()) {
                    register_code(KC_LSFT);
                }
            }
        }
    return true; // Pass the original keycode through
    }
};

void post_process_record_spongemock(uint16_t keycode, keyrecord_t *record) {
    if (!spongemock_active) {
        return;
    }

    // Clean up the shift key
    if (keycode >= KC_A && keycode <= KC_Z) {
        if (record->event.pressed) {
            unregister_code(KC_LSFT);
        }
    }
};
