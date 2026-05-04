#pragma bank 2

#include "scenes/inventory/inventory_scene.h"

void InventoryScene_Create()
{
    InventoryScene.init = InventoryScene_Init;
    InventoryScene.update = InventoryScene_Update;
    InventoryScene.bank = 2;
}