#include <gb/gb.h>

#ifndef ACTION_H
#define ACTION_H

#include "engine/entity.h"
#include "engine/position.h"
#include "core/characters/player.h"
#include "engine/animation.h"

extern uint8_t MOVE_SPEED;

typedef enum
{
    DIR_NONE,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

extern Direction current_direction;
extern uint16_t target_pos;

void move_up(Entity e);

void move_down(Entity e);

void move_left(Entity e);

void move_right(Entity e);

#endif // ACTION_H