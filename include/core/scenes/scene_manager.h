#include "core/scenes/all_scenes.h"
#include "engine/entity.h"
#include "core/game.h"
#include "core/scenes/scene.h"
#include <stdint.h>

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#define GENERAL_TILESET_BANK 1

typedef struct SceneManager
{
  Game *game;
  void (*change_scene)(enum AllScenes new_scene, Entity *player);
} SceneManager;

void SceneManager_CleanScreen();
void SceneManager_Create(Game *game);
void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player);
Scene *scene_manager_MapScene(enum AllScenes scene);

extern SceneManager scene_manager;
extern uint8_t is_transitioning;

extern enum AllScenes next_scene;

#endif // SCENE_MANAGER_H
