#include <gb/gb.h>

#include "../draw.h"
#include "../input.h"
#include "../load.h"
#include "../npcs.h"
#include "../player.h"
#include "../position.h"
#include "../scene.h"
#include "../scene_manager.h"

#include "../../assets/sprites/backgrounds/maps/general_tileset.h"

enum AllScenes next_scene = NONE;
SceneManager scene_manager;
uint8_t is_transitioning = 0;

void SceneManager_CleanScreen()
{
  DISPLAY_OFF;
  HIDE_BKG;
  HIDE_SPRITES;

  vsync();

  position.y[player] = 0;
  position.y[npc_1] = 0;
  position.y[npc_2] = 0;

  draw_actor(player);
  draw_actor(npc_1);
  draw_actor(npc_2);

  for (uint8_t i = 0; i < 40; i++)
    move_sprite(i, 0, 0);

  vram_next_index = 0;
  vram_extra_start = 27;
}

void SceneManager_Create(Game *game)
{
  scene_manager.game = game;
  scene_manager.change_scene = SceneManager_ChangeScene;
}

void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player)
{
  if (is_transitioning == 1)
    return;

  if (!scene_manager.game)
    return;

  for (uint8_t y = 0; y < 18; y++)
  {
    for (uint8_t x = 0; x < 20; x++)
    {
      set_bkg_tile_xy(x, y, 0);
    }
  }

  DISPLAY_OFF;

  uint8_t is_map = 0;
  if (new_scene > MAP_COUNT_INIT && new_scene < MAP_COUNT_END)
    is_map = 1;

  uint8_t prev_is_map = 0;
  if (scene_manager.game->current_scene > MAP_COUNT_INIT && scene_manager.game->current_scene < MAP_COUNT_END)
    prev_is_map = 1;

  if (is_map == 1 && prev_is_map == 0)
  {
    uint8_t _prev_bank = _current_bank;

    SWITCH_ROM_MBC1(GENERAL_TILESET_BANK);
    set_bkg_data(0, general_tileset_size, general_tileset);
    SWITCH_ROM_MBC1(_prev_bank);
  }

  is_transitioning = 1;
  next_scene = NONE;

  if (scene_manager.game->current_scene != NULL && new_scene != INVENTORY)
  {
    Scene *old_scene = scene_manager.game->current_scene;

    uint8_t _prev_bank_destroy = _current_bank;

    SWITCH_ROM_MBC1(old_scene->bank);

    if (old_scene->destroy != NULL)
      old_scene->destroy(old_scene);

    SWITCH_ROM_MBC1(_prev_bank_destroy);
  }

  SceneManager_CleanScreen();

  DISPLAY_ON;
  SHOW_BKG;
  SHOW_SPRITES;

  prev_scene = current_scene;
  current_scene = new_scene;

  Scene *scene = scene_manager_MapScene(new_scene);

  uint8_t _prev_bank = _current_bank;
  SWITCH_ROM_MBC1(scene->bank);
  scene->init(scene, *player);

  scene_manager.game->current_scene = scene;

  vsync();

  if (_prev_bank != _current_bank)
    SWITCH_ROM_MBC1(_prev_bank);

  keys = 0;
  prev_keys = 0;

  is_transitioning = 0;
}
