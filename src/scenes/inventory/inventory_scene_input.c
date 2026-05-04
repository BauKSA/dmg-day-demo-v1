#pragma bank 2

#include "scenes/inventory/inventory_scene.h"
#include "engine/input.h"
#include "core/definitions/language.h"
#include "core/definitions/inventory.h"
#include "engine/position.h"
#include "core/characters/npcs.h"
#include "engine/draw.h"
#include "core/characters/player.h"
#include "core/characters/npcs.h"
#include "core/scenes/scene_manager.h"
#include "core/scenes/all_scenes.h"
#include "core/utils/char_to_tile.h"
#include "core/definitions/text_positions.h"
#include "maps/utils/map_data.h"

#include "../assets/chars/chars.h"

#include <gb/gb.h>

void InventoryScene_CheckInput()
{
    if (!(keys & J_SELECT) && (prev_keys & J_SELECT))
        next_scene = prev_scene;

    if (!(keys & J_LEFT) && (prev_keys & J_LEFT))
    {
        if (selected_item_index == 0)
            return;

        selected_item_index--;
        position.x[option_actor] -= 24;
    }

    if (!(keys & J_RIGHT) && (prev_keys & J_RIGHT))
    {
        if (selected_item_index == MAX_ITEMS - 1)
            return;

        selected_item_index++;
        position.x[option_actor] += 24;
    }

    if ((keys & J_A) && !(prev_keys & J_A))
    {
        active_item_index = selected_item_index;
        active_item = 1;

        next_scene = prev_scene;
    }

    return;
}