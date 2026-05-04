#pragma bank 4
#include <gb/gb.h>

#include "maps/3-0/map_30.h"
#include "maps/utils/map_data.h"

#include "core/definitions/language.h"

#include "core/characters/npc_lines.h"
#include "core/characters/npc_stats_map.h"

static const DialoguePerRelation dialogue_0_30_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmh...", "estas hojas..."}, {"buen dia", ""}, {"que maravilloso\0", "dia, no?\0"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_0_30_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmph...", "these leaves..."}, {"good morning", ""}, {"what a beautiful", "day, kid"}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_30_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 0)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_30_en;
    }
}