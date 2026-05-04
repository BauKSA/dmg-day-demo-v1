#pragma bank 3

#include "maps/2-3/map_23.h"

#include "engine/animation.h"
#include "engine/draw.h"
#include "core/characters/npcs.h"
#include "core/scenes/scene.h"
#include "core/characters/player.h"

#include "maps/utils/auto_clean.h"
#include "maps/utils/map_data.h"
#include "maps/utils/map_player_movement.h"

void Map_23_Update(Scene *scene) {
  Map_AutoClean();

  Map_PlayerMovement();

  update_animation(animation);
  draw_actor(player);
  draw_actor(npc_1);

  Map_Collision(scene);
  Map_23_CheckInput();

  return;
}
