#pragma bank 2

#include "../assets/sprites/backgrounds/main_menu/bkg_MainMenu.h"
#include "core/characters/player.h"
#include "engine/position.h"
#include "core/scenes/scene.h"
#include "scenes/main_menu/main_menu.h"
#include <gb/gb.h>

void MainMenu_Init(Scene *scene, Entity scene_player) {
  set_bkg_data(0, bkg_main_menu_tileset_size, bkg_main_menu_tileset);
  set_bkg_tiles(0, 0, 20, 18, bkg_main_menu_tilemap);
}
