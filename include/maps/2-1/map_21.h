#include <stdlib.h>

#include "engine/entity.h"
#include "core/game.h"
#include "core/characters/npc_lines.h"
#include "maps/utils/map_data.h"

#ifndef MAP_21_H
#define MAP_21_H

void Map_21_Init(Scene *scene, Entity scene_player);
void Map_21_Update(Scene *scene);

extern Scene Map_21;

void Map_21_Create(void);

#endif // MAP_21_H
