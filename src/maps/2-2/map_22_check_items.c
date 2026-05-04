#pragma bank 3

#include "maps/2-2/map_22.h"
#include "maps/utils/map_data.h"

#include "core/definitions/inventory.h"

void Map_22_CheckItems()
{
    if (active_item == 0)
        return;

    active_item = 0;
    ItemNoUseText();
}