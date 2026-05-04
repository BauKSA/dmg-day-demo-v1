#pragma bank 2

#include "scenes/language_select/language_select.h"

void LanguageSelect_Create()
{
    LanguageSelect.init = LanguageSelect_Init;
    LanguageSelect.update = LanguageSelect_Update;
    LanguageSelect.bank = 2;
}