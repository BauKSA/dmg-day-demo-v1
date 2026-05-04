#pragma bank 2

#include <gb/gb.h>
#include <stdlib.h>

#include "engine/input.h"
#include "core/definitions/language.h"
#include "core/characters/npcs.h"
#include "core/characters/player.h"
#include "engine/random.h"
#include "core/scenes/scene.h"
#include "core/scenes/scene_manager.h"
#include "scenes/main_menu/main_menu.h"

void MainMenu_CheckInput(void)
{
  if (!(keys & J_START) && (prev_keys & J_START))
  {
    seed = LY_REG;
    seed |= (unsigned int)DIV_REG << 8;

    for (size_t i = 0; i < MAX_NPCS; i++)
    {
      humor_stats[i] = my_rand() % 3;
      relation_stats[i] = 1;
      dialogue_phase[i] = 0;
    }

    next_scene = LANG_SELECT;
  }
}
