#pragma bank 2

#include "inventory_scene.h"

void InventoryScene_Create()
{
    InventoryScene.init = InventoryScene_Init;
    InventoryScene.update = InventoryScene_Update;
    InventoryScene.bank = 2;
}