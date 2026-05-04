#include <gb/gb.h>

#include "core/scenes/all_scenes.h"
#include "core/scenes/scene.h"

// All scenes include

// MENU
#include "scenes/language_select/language_select.h"
#include "scenes/gender_select/gender_select.h"
#include "scenes/inventory/inventory_scene.h"
#include "scenes/main_menu/main_menu.h"
#include "scenes/story/story.h"

// MAPAS
#include "maps/2-1/map_21.h"
#include "maps/2-2/map_22.h"
#include "maps/2-3/map_23.h"

#include "maps/3-0/map_30.h"
#include "maps/3-1/map_31.h"
#include "maps/3-2/map_32.h"

// MINI JUEGOS
#include "mini_games/leaves/mg_leaves.h"

#define MAP_0_BANK 1
#define MAP_1_BANK 2
#define MAP_2_BANK 3
#define MAP_3_BANK 4
#define MENU_BANK 5
#define INVENTORY_BANK 2
#define MG_BANK 6

Scene *scene_manager_MapScene(enum AllScenes scene)
{
  uint8_t _prev_bank = _current_bank;

  vsync();

  switch (scene)
  {
  case MENU:
    SWITCH_ROM_MBC1(MENU_BANK);
    MainMenu_Create();
    return &MainMenu;
    SWITCH_ROM_MBC1(_prev_bank);
  case LANG_SELECT:
    SWITCH_ROM_MBC1(MENU_BANK);
    LanguageSelect_Create();
    return &LanguageSelect;
    SWITCH_ROM_MBC1(_prev_bank);
  case GENDER_SELECT:
    SWITCH_ROM_MBC1(MENU_BANK);
    GenderSelect_Create();
    return &GenderSelect;
    SWITCH_ROM_MBC1(_prev_bank);
  case INVENTORY:
    SWITCH_ROM_MBC1(INVENTORY_BANK);
    InventoryScene_Create();
    return &InventoryScene;
    SWITCH_ROM_MBC1(_prev_bank);
  case STORY:
    SWITCH_ROM_MBC1(MENU_BANK);
    Story_Create();
    return &Story;
    SWITCH_ROM_MBC1(_prev_bank);

    // MAPAS
  case MAP_21:
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_21_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_21;
  case MAP_22:
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_22_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_22;
  case MAP_23:
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_23_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_23;

  case MAP_30:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_30_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_30;

  case MAP_31:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_31_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_31;

  case MAP_32:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_32_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_32;

  // MINI JUEGOS
  case MG_LEAVES:
    SWITCH_ROM_MBC1(MG_BANK);
    Mg_Leaves_Create();
    return &Mg_Leaves;
  default:
    return NULL;
  }
}
