#pragma bank 4

#include "../../../assets/sprites/backgrounds/maps/3-0/map_3-0.h"

#include "engine/draw.h"

#include "core/characters/player.h"
#include "core/characters/npcs.h"
#include "core/characters/npcs.h"
#include "core/characters/npc_stats_map.h"

#include "core/scenes/scene.h"
#include "core/scenes/all_scenes.h"

#include "maps/3-0/map_30.h"
#include "maps/3-0/map_30_collision.h"

#include "maps/utils/map_data.h"

static void map_30_event()
{
  CurrentMapData.event_active = 1;
}

void Map_30_Init(Scene *scene, Entity scene_player)
{
  init_player();
  Map_30_InitNPC();
  Map_30_InitDialogues();

  CurrentMapData.npc_count = 1;
  CurrentMapData.npc[0] = npc_1;
  CurrentMapData.collision_map = map_30_collision;
  CurrentMapData.receive_items = 0;

  CurrentMapData.spawner.right = MAP_31;
  CurrentMapData.spawner.left = NONE;
  CurrentMapData.spawner.up = NONE;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 1;
  CurrentMapData.event_active = 0;
  CurrentMapData.events[0] = map_30_event;

  set_bkg_tiles(0, 0, 20, 18, map_3_0_tilemap);

  draw_actor(player);
  draw_actor(npc_1);

  actual_tile.prev = 0;
  actual_tile.value = 0;

  Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, 0, NONE);
  if (dialogue_phase[(uint8_t)NPC_ESCOBA] < dialogue_phase_count[(uint8_t)NPC_ESCOBA])
  {
    dialogue_phase[(uint8_t)NPC_ESCOBA]++;
    Map_30_InitDialogues();
  }
}