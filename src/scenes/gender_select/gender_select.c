#pragma bank 2

#include "gender_select.h"
#include "../../include/scene.h"

Scene GenderSelect;

void GenderSelect_Create(void)
{
    GenderSelect.init = GenderSelect_Init;
    GenderSelect.update = GenderSelect_Update;
}