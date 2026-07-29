#ifndef _FLIP_H_
#define _FLIP_H_
#include "core/characters/npcs.h"
#include "engine/entity.h"

void flip_spr(uint8_t id, uint8_t flipped);
extern uint8_t flipped[MAX_ENTITIES];

#endif