#pragma bank 3

#include "maps/2-3/map_23.h"
#include "core/scenes/scene.h"

void Map_23_Create() {
  Map_23.init = Map_23_Init;
  Map_23.update = Map_23_Update;
  Map_23.bank = 3;
}
