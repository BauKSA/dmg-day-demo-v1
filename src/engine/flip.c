#include "engine/flip.h"
#include "engine/position.h"

#include <gb/gb.h>

uint8_t flipped[MAX_ENTITIES] = {0};

void flip_spr(uint8_t id, uint8_t flipped)
{
    uint8_t to_flip = flipped == 0 ? 0 : S_FLIPX;
    uint8_t spr_id = id * 4;

    for (uint8_t i = 0; i < 4; i++)
    {
        set_sprite_prop(spr_id + i, to_flip);
    }

    uint8_t x = position.x[id];
    uint8_t y = position.y[id];
}