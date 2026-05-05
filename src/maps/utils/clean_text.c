#include "core/definitions/text_positions.h"
#include "maps/utils/map_data.h"
#include <gb/gb.h>

void Map_Clean()
{
  CurrentMapData.event_active = 0;
  uint8_t empty_tile = 255;

  for (size_t i = TEXT_START_X; i <= TEXT_END_X; i++)
  {
    set_bkg_tile_xy(i, TEXT_START_Y, empty_tile);
    set_bkg_tile_xy(i, TEXT_START_Y + 1, empty_tile);
  }

  for (size_t i = NAME_START_X; i < NAME_END_X; i++)
  {
    set_bkg_tiles(i, NAME_START_Y, 1, 1, &empty_tile);
  }

  set_bkg_tiles(HUMOR_ICON_X, ICON_Y, 1, 1, &empty_humor_icon);
  set_bkg_tiles(RELATION_ICON_X, ICON_Y, 1, 1, &empty_relation_icon);
}
