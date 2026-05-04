#include "engine/input.h"
#include "engine/speed.h"

#include "core/utils/action.h"
#include "core/characters/player.h"
#include "core/scenes/scene_manager.h"
#include "core/definitions/can_move.h"
#include "music.h"

Direction current_direction = DIR_NONE;
uint16_t target_pos = 0;

void move_up(Entity e)
{
    if (can_move.up == false)
        return;

    position.fixed_y[e] -= speed[e];
    position.y[e] = position.fixed_y[e] >> 8;

    Walk();
}

void move_down(Entity e)
{
    if (can_move.down == false)
        return;

    position.fixed_y[e] += speed[e];
    position.y[e] = position.fixed_y[e] >> 8;

    Walk();
}

void move_left(Entity e)
{
    if (can_move.left == false)
        return;

    position.fixed_x[e] -= speed[e];
    position.x[e] = position.fixed_x[e] >> 8;

    Walk();
}

void move_right(Entity e)
{
    if (can_move.right == false)
        return;

    position.fixed_x[e] += speed[e];
    position.x[e] = position.fixed_x[e] >> 8;

    Walk();
}