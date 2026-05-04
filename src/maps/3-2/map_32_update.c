#pragma bank 4

#include "engine/animation.h"
#include "engine/draw.h"

#include "core/scenes/scene.h"
#include "core/characters/npcs.h"
#include "core/characters/npc_stats_map.h"
#include "core/definitions/mgm_states.h"
#include "core/characters/player.h"

#include "maps/utils/map_data.h"
#include "maps/utils/auto_clean.h"
#include "maps/utils/map_player_movement.h"

#include "./map_32.h"

void Map_32_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();

  update_animation(animation);

  draw_actor(player);

  Map_Collision(scene);

  return;
}
