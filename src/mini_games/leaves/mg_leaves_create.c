#pragma bank 6

#include "core/scenes/scene.h"
#include "core/definitions/mgm_states.h"

#include "mini_games/leaves/mg_leaves.h"
#include "mini_games/mini_games.h"

void Mg_Leaves_Create(void)
{
    Mg_Leaves.init = Mg_Leaves_Init;
    Mg_Leaves.update = Mg_Leaves_Update;
    Mg_Leaves.bank = 6;

    MGM_states.mg_leaves = MGM_ACTIVE;
}