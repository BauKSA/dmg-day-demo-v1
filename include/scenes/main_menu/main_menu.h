#ifndef _MAINMENU_
#define _MAINMENU_

#include <stdlib.h>

#include "engine/entity.h"
#include "core/game.h"

void MainMenu_Init(Scene *scene, Entity scene_player);
void MainMenu_Update(Scene *scene);
void MainMenu_Destroy(Scene *scene);

void MainMenu_InitRandomStats();

extern Scene MainMenu;

void MainMenu_Create(void);
void MainMenu_CheckInput(void);

extern uint16_t timer;
extern uint8_t rate;
extern uint8_t show_text;

#endif //_MAINMENU_
