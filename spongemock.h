#pragma once

#include "quantum.h"

// public functions

/**
 * @brief Enable spongemock.
 * @return void
 */
void enable_spongemock(void);

/**
 * @brief Disable spongemock.
 * @return void
 */
void disable_spongemock(void);

/**
 * @brief Toggle spongemock.
 * @return void
 */
void toggle_spongemock(void);

/**
 * @brief Check if spongemock is active.
 * @return True if spongemock is active, false otherwise.
 */
bool is_spongemock_active(void);

/**
 * @brief Process a keycode for spongemock.
 * @param keycode The keycode to process.
 * @param record The keyrecord to process.
 * @return True if the keycode should be processed, false otherwise.
 */
bool process_record_spongemock(uint16_t keycode, keyrecord_t *record);
