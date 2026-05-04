#pragma bank 4

#include "../../../assets/sprites/backgrounds/maps/3-2/map_3-2.h"

#include "engine/draw.h"

#include "core/characters/player.h"
#include "core/scenes/scene.h"
#include "core/scenes/all_scenes.h"

#include "maps/3-2/map_32.h"
#include "maps/3-2/map_32_collision.h"

#include "maps/utils/map_data.h"

void Map_32_Init(Scene *scene, Entity scene_player)
{
  init_player();

  CurrentMapData.collision_map = map_32_collision;

  CurrentMapData.spawner.right = NONE;
  CurrentMapData.spawner.left = MAP_31;
  CurrentMapData.spawner.up = MAP_22;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 0;
  CurrentMapData.event_active = 0;

  set_bkg_tiles(0, 0, 20, 18, map_3_2_tilemap);

  draw_actor(player);

  CurrentMapData.npc_count = 0;

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
