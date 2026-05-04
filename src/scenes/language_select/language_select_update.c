#pragma bank 2

#include "scenes/language_select/language_select.h"
#include "core/scenes/scene.h"

void LanguageSelect_Update(Scene *scene)
{
    LanguageSelect_CheckInput();
}