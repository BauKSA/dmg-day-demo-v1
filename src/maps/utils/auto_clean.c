#include "maps/utils/auto_clean.h"
#include "maps/utils/map_data.h"

uint8_t auto_clean_timer = 0;
uint8_t auto_clean_rate = 250;

void Map_AutoClean()
{
    if (++auto_clean_timer >= auto_clean_rate)
    {
        auto_clean_timer = 0;
        Map_Clean();
    }
}