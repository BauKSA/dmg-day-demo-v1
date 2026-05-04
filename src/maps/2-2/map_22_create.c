#pragma bank 3

#include "maps/2-2/map_22.h"
#include "core/scenes/scene.h"

void Map_22_Create(void)
{
    Map_22.init = Map_22_Init;
    Map_22.update = Map_22_Update;
    Map_22.destroy = Map_22_Destroy;
    Map_22.bank = 3;
}