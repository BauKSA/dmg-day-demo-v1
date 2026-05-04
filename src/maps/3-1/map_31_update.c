#pragma bank 4

#include "engine/animation.h"
#include "engine/draw.h"

#include "core/characters/npcs.h"
#include "core/characters/player.h"
#include "core/scenes/scene.h"

#include "maps/utils/map_data.h"
#include "maps/utils/auto_clean.h"
#include "maps/utils/map_player_movement.h"

#include "maps/3-1/map_31.h"

void Map_31_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();

  update_animation(animation);
  update_animation(&animation[npc_1]);

  draw_actor(player);
  draw_actor(npc_1);

  Map_Collision(scene);

  return;
}