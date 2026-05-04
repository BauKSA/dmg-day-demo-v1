#pragma bank 2

#include "core/characters/player.h"
#include "engine/position.h"
#include "core/scenes/scene.h"
#include "engine/animation.h"
#include "engine/render.h"
#include "engine/draw.h"
#include "core/characters/npcs.h"
#include "core/definitions/language.h"
#include "core/utils/char_to_tile.h"
#include "core/definitions/text_positions.h"

#include "scenes/language_select/language_select.h"

#include "../assets/sprites/backgrounds/language_select/bkg_LanguageSelect.h"
#include "../assets/sprites/backgrounds/language_select/spr_language_arrow.h"
#include "../assets/chars/chars.h"

#include <gb/gb.h>

void LanguageSelect_Init(Scene *scene, Entity scene_player)
{
  set_bkg_data(0, bkg_language_select_tileset_size, bkg_language_select_tileset);
  set_bkg_tiles(0, 0, 20, 18, bkg_language_select_tilemap);

  position.x[option_actor] = LANG_ARROW_XA;
  position.y[option_actor] = LANG_ARROW_Y;

  position.fixed_x[option_actor] = position.x[option_actor];
  position.fixed_y[option_actor] = position.y[option_actor];

  render.tile_start[option_actor] = 0;
  render.tile_count[option_actor] = 1;
  render.vertical[option_actor] = TRUE;

  const unsigned char *arrow_idle[] = {spr_language_arrow0};

  init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                 DEFAULT_ANIMATION_SPEED, 1);

  language = SPANISH;

  char txt[] = "idioma";
  for (uint8_t i = 0; txt[i] != '\0'; i++)
  {
    uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
    set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
  }

  draw_actor(option_actor);
}