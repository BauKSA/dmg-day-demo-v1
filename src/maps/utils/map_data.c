#include "maps/utils/map_data.h"

MapData CurrentMapData;
MapVisitCount Map_VisitCount[MAP_COUNT_END - MAP_COUNT_INIT] = {0};

uint8_t empty_humor_icon = 256;
uint8_t empty_relation_icon = 256;