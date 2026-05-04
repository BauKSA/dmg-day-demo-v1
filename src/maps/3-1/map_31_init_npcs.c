#pragma bank 4

#include "../../../assets/sprites/NPCs/flag/spr_flag.h"

#include "engine/animation.h"
#include "engine/draw.h"
#include "engine/position.h"
#include "engine/render.h"

#include "core/definitions/name.h"
#include "core/characters/npcs.h"

#include "maps/3-1/map_31.h"
#include "maps/utils/map_data.h"

void Map_31_InitNPCs()
{
  position.x[npc_1] = 40;
  position.y[npc_1] = 40;

  char npc_name[10] = "flag";
  for (uint8_t i = 0; i < npc_name[i] != '\0'; i++)
    names[npc_1][i] = npc_name[i];

  position.fixed_x[npc_1] = position.x[npc_1] << 8;
  position.fixed_x[npc_1] = position.y[npc_1] << 8;

  render.tile_start[npc_1] = 0;
  render.tile_count[npc_1] = 4;
  render.vertical[npc_1] = TRUE;

  const unsigned char *npc_sprite[] = {
      // primer frame
      spr_Flag00, spr_Flag01, spr_Flag02, spr_Flag03,

      // segundo frame
      spr_Flag10, spr_Flag11, spr_Flag12, spr_Flag13};

  init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 2,
                 DEFAULT_ANIMATION_SPEED * 2, 4);

  CurrentMapData.npc_count = 1;
  CurrentMapData.npc[0] = npc_1;

  draw_actor(npc_1);
}
