#pragma bank 4

#include <gb/gb.h>

#include "engine/input.h"

#include "core/characters/npc_stats_map.h"
#include "core/characters/npcs.h"
#include "core/scenes/all_scenes.h"

#include "maps/utils/map_data.h"
#include "maps/3-0/map_30.h"

void Map_30_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  uint8_t has_mini_game = 0;
  enum AllScenes mini_game = NONE;

  if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 1)
  {
    has_mini_game = 1;
    mini_game = MG_LEAVES;
  }

  if (!(keys & J_A) && (prev_keys & J_A))
  {
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, has_mini_game, mini_game);
    if (dialogue_phase[(uint8_t)NPC_ESCOBA] < dialogue_phase_count[(uint8_t)NPC_ESCOBA])
    {
      dialogue_phase[(uint8_t)NPC_ESCOBA]++;
    }

    if (has_mini_game == 1)
    {
      Map_Clean();
      Map_30_InitDialogues();
      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, 0, NONE);
    }
  }
}