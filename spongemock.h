#pragma once

#include "quantum.h"

void enable_spongemock(void);
void disable_spongemock(void);
void toggle_spongemock(void);
bool is_spongemock_active(void);

bool process_record_spongemock(uint16_t keycode, keyrecord_t *record);
