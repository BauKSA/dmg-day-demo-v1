#pragma bank 3

#include "maps/2-2/map_22.h"
#include "maps/utils/map_data.h"
#include "engine/animation.h"
#include "engine/entity.h"
#include "engine/position.h"
#include "engine/render.h"
#include "engine/load.h"
#include "core/definitions/name.h"
#include "core/characters/npcs.h"

#include "../../../assets/sprites/NPCs/martin/martin_npc.h"

void Map_22_InitNPC()
{
    position.x[npc_1] = 38;
    position.y[npc_1] = 75;

    char npc_name[10] = "martin";
    for (size_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_patrol[] = {
        // primer frame
        spr_Martin_down00,
        spr_Martin_down01,
        spr_Martin_down02,
        spr_Martin_down03
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_patrol, 1, DEFAULT_ANIMATION_SPEED, 4);
}