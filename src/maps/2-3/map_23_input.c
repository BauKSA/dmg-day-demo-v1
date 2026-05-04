#pragma bank 3

#include <gb/gb.h>

#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/chars/chars.h"

#include "engine/input.h"

#include "core/utils/char_to_tile.h"
#include "core/definitions/language.h"
#include "core/characters/npc_stats_map.h"
#include "core/characters/npcs.h"

#include "maps/utils/map_data.h"
#include "maps/2-3/map_23.h"

void Map_23_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A))
  {
    if (dialogue_phase[(uint8_t)NPC_DIARIO] == 0)
    {
      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_DIARIO, 0, 0, NONE);

      keys = 0;
      prev_keys = 0;
    }
  }
}
