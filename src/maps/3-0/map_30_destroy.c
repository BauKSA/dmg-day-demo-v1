#pragma bank 4

#include "maps/3-0/map_30.h"
#include "maps/utils/map_data.h"

#include "core/characters/npcs.h"
#include "core/characters/npc_stats_map.h"

void Map_30_Destroy(Scene *scene)
{
    if (Map_VisitCount[MAP_30 - MAP_COUNT_INIT] == 1)
    {
        if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 0)
        {
            relation_stats[(uint8_t)NPC_ESCOBA] = 0;
        }
        else
        {
            relation_stats[(uint8_t)NPC_ESCOBA] = 2;
        }
    }
}