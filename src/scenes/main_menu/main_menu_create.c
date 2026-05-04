#pragma bank 2

#include "scenes/main_menu/main_menu.h"
#include "core/scenes/scene.h"

void MainMenu_Create(void)
{
    MainMenu.init = MainMenu_Init;
    MainMenu.update = MainMenu_Update;
    MainMenu.destroy = MainMenu_Destroy;
    MainMenu.bank = 2;
}