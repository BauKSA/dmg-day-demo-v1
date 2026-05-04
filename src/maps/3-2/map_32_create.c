#pragma bank 4

#include "maps/3-2/map_32.h"
#include "core/scenes/scene.h"

void Map_32_Create()
{
  Map_32.init = Map_32_Init;
  Map_32.update = Map_32_Update;
  Map_32.bank = 4;
}
