#ifndef MAP_32_H
#define MAP_32_H

#include "engine/entity.h"
#include "core/scenes/scene.h"
#include "core/definitions/mgm_states.h"

void Map_32_Init(Scene *scene, Entity scene_player);
void Map_32_Update(Scene *scene);

extern Scene Map_32;
extern enum MGM_STATE mg_32_tmp;
extern uint8_t tmp_relation32;
extern uint8_t map_32_npc_active;

void Map_32_Create(void);

#endif // !MAP_32_H
