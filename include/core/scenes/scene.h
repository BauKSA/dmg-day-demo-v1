#include "core/game.h"
#include "engine/entity.h"

#ifndef SCENE_H
#define SCENE_H

#define MAX_NPCS_PER_SCENE 3
#define MAX_EVENTS 2

typedef struct Scene Scene;

struct Scene
{
    void (*init)(struct Scene *, Entity player);
    void (*update)(struct Scene *);
    void (*destroy)(struct Scene *);
    uint8_t bank;
};

#endif // SCENE_H