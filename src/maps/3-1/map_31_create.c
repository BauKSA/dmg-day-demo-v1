#pragma bank 4

#include "maps/3-1/map_31.h"
#include "core/scenes/scene.h"

void Map_31_Create() {
  Map_31.init = Map_31_Init;
  Map_31.update = Map_31_Update;
  Map_31.bank = 4;
}
