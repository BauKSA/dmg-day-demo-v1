#pragma bank 6

#include "mg_leaves.h"
#include "core/scenes/scene.h"
#include "../../../include/minigames.h"

void Mg_Leaves_Create(void)
{
    Mg_Leaves.init = Mg_Leaves_Init;
    Mg_Leaves.update = Mg_Leaves_Update;
    Mg_Leaves.bank = 6;

    minigame_list[LSMG_LEAVES] = 1;
}