#include <gb/gb.h>

#include "../assets/chars/items.h"

#include "core/definitions/inventory.h"

Slot inventory[MAX_ITEMS];

uint8_t active_item_index = 0;
uint8_t active_item = 0;

uint8_t selected_item_index = 0;
uint8_t last_selected_item_index = 0;