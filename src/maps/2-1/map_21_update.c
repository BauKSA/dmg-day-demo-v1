#pragma bank 3

#include "engine/animation.h"
#include "engine/draw.h"
#include "core/scenes/scene.h"
#include "core/characters/player.h"

#include "maps/utils/map_data.h"
#include "maps/utils/auto_clean.h"
#include "maps/utils/map_player_movement.h"

#include "maps/2-1/map_21.h"

void Map_21_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();

  update_animation(animation);
  draw_actor(player);

  Map_Collision(scene);

  return;
}
