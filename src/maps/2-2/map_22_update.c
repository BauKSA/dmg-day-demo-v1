#pragma bank 3

#include "engine/animation.h"
#include "engine/draw.h"
#include "engine/flip.h"

#include "core/scenes/scene.h"
#include "core/characters/player.h"

#include "maps/utils/map_data.h"
#include "maps/utils/auto_clean.h"
#include "maps/utils/map_player_movement.h"

#include "maps/2-2/map_22.h"

void Map_22_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();

  update_animation(&animation[player]);
  // update_animation(&animation[npc_1]);

  frame++;
  if (frame >= 120)
  {
    frame = 0;
    if (flipped[npc_1] == 0)
      flipped[npc_1] = 1;
    else
      flipped[npc_1] = 0;

    flip_spr(npc_1, flipped[npc_1]);
  }

  draw_actor(npc_1);
  draw_actor(player);

  Map_Collision(scene);
  Map_22_CheckInput();

  return;
}
