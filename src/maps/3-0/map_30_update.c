#pragma bank 4

#include "engine/animation.h"
#include "engine/draw.h"

#include "core/characters/npcs.h"
#include "core/characters/npc_stats_map.h"
#include "core/characters/player.h"
#include "core/scenes/scene.h"

#include "maps/utils/map_data.h"
#include "maps/utils/auto_clean.h"
#include "maps/utils/map_player_movement.h"

#include "maps/3-0/map_30.h"

void Map_30_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();
  Map_30_CheckInput();

  update_animation(animation);
  update_animation(&animation[npc_1]);

  draw_actor(player);
  draw_actor(npc_1);

  Map_Collision(scene);

  if (mg_ended == 1)
  {
    mg_ended = 0;

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, 0, NONE);
  }

  return;
}