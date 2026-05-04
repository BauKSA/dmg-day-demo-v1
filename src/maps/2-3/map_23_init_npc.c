#pragma bank 3

#include "../../../assets/sprites/NPCs/viejo_diario/spr_ViejoDiario.h"

#include "engine/animation.h"
#include "core/definitions/name.h"
#include "core/characters/npcs.h"
#include "engine/position.h"
#include "engine/render.h"

#include "maps/utils/map_data.h"
#include "maps/2-3/map_23.h"

void Map_23_InitNPC()
{
  position.x[npc_1] = 96;
  position.y[npc_1] = 76;

  char npc_name[10] = "diariero";
  for (uint8_t i = 0; i < npc_name[i] != '\0'; i++)
    names[npc_1][i] = npc_name[i];

  position.fixed_x[npc_1] = position.x[npc_1] << 8;
  position.fixed_x[npc_1] = position.y[npc_1] << 8;

  render.tile_start[npc_1] = 0;
  render.tile_count[npc_1] = 4;
  render.vertical[npc_1] = TRUE;

  const unsigned char *npc_sprite[] = {// primer frame
                                       spr_ViejoDiario00, spr_ViejoDiario01,
                                       spr_ViejoDiario02, spr_ViejoDiario03};

  init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                 DEFAULT_ANIMATION_SPEED, 4);
}
