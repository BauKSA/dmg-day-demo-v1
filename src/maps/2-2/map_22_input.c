#pragma bank 3

#include <gb/gb.h>

#include "engine/input.h"
#include "core/characters/npc_stats_map.h"
#include "core/characters/npcs.h"
#include "maps/2-2/map_22.h"

void Map_22_CheckInput() {
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A)) {
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_MARTIN, 0, 0, NONE);
    temp_relation = 2;
  }
}
