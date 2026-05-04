#include <gb/gb.h>

#include "../assets/chars/items.h"

#include "core/definitions/inventory.h"

void init_inventory()
{
    for (uint8_t i = 0; i < MAX_ITEMS; i++)
        inventory[i].item = ITM_NONE;

    set_bkg_data(ITEMS_TILESET_START, items_tileset_size, items_tileset);
}