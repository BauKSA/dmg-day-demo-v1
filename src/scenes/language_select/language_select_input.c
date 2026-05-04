#pragma bank 2

#include "scenes/language_select/language_select.h"
#include "engine/input.h"
#include "core/definitions/language.h"
#include "engine/position.h"
#include "core/characters/npcs.h"
#include "engine/draw.h"
#include "core/characters/player.h"
#include "core/scenes/scene_manager.h"
#include "core/scenes/all_scenes.h"
#include "core/utils/char_to_tile.h"
#include "core/definitions/text_positions.h"
#include "maps/utils/map_data.h"

#include "../assets/chars/chars.h"

#include <gb/gb.h>

void LanguageSelect_CheckInput()
{
    if (!(keys & J_RIGHT) && (prev_keys & J_RIGHT))
    {
        if (language == ENGLISH)
            return;

        Map_Clean();

        char txt[] = "language";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }

        position.x[option_actor] = LANG_ARROW_XB;
        position.fixed_x[option_actor] = position.x[option_actor];

        draw_actor(option_actor);

        language = ENGLISH;
    }

    if (!(keys & J_LEFT) && (prev_keys & J_LEFT))
    {
        if (language == SPANISH)
            return;

        Map_Clean();

        char txt[] = "idioma";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }

        position.x[option_actor] = LANG_ARROW_XA;
        position.fixed_x[option_actor] = position.x[option_actor];

        language = SPANISH;

        draw_actor(option_actor);
    }

    if (!(keys & J_A) && (prev_keys & J_A))
        next_scene = STORY;
}