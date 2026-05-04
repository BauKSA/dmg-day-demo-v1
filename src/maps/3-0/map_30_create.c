#pragma bank 4

#include "maps/3-0/map_30.h"
#include "core/scenes/scene.h"

void Map_30_Create()
{
  Map_30.init = Map_30_Init;
  Map_30.update = Map_30_Update;
  Map_30.destroy = Map_30_Destroy;
  Map_30.bank = 4;
}
