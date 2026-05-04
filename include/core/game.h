#ifndef GAME_H   // si GAME_H no está definido
#define GAME_H   // definilo, y el resto del archivo se procesa

#include "core/scenes/scene.h"

typedef struct Game {
    struct Scene* current_scene;
    int running;
} Game;

#endif // GAME_H