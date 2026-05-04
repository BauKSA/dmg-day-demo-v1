#pragma bank 4

#include "../../../assets/sprites/backgrounds/maps/3-1/map_3-1.h"

#include "engine/draw.h"

#include "core/scenes/all_scenes.h"
#include "core/scenes/scene.h"
#include "core/characters/player.h"

#include "maps/3-1/map_31.h"
#include "maps/3-1/map_31_collision.h"

#include "maps/utils/map_data.h"

void Map_31_Init(Scene *scene, Entity scene_player)
{
  init_player();

  CurrentMapData.npc_count = 1;
  CurrentMapData.collision_map = map_31_collision;

  CurrentMapData.spawner.right = MAP_32;
  CurrentMapData.spawner.left = MAP_30;
  CurrentMapData.spawner.up = NONE;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 0;
  CurrentMapData.event_active = 0;

  set_bkg_tiles(0, 0, 20, 18, map_3_1_tilemap);

  Map_31_InitNPCs();
  Map_31_InitDialogues();

  draw_actor(player);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
