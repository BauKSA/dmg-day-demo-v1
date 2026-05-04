#pragma bank 2

#include "scenes/gender_select/gender_select.h"
#include "core/scenes/scene.h"

Scene GenderSelect;

void GenderSelect_Create(void)
{
    GenderSelect.init = GenderSelect_Init;
    GenderSelect.update = GenderSelect_Update;
}