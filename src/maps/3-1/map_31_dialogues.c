#pragma bank 4

#include "core/definitions/language.h"
#include "core/characters/npc_lines.h"
#include "core/characters/npc_stats_map.h"

#include "maps/3-1/map_31.h"

const DialoguePerRelation dialogue_00_31_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmh...", "that's not my book"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"aw, thank yoooou!", ""}},
};

const DialoguePerRelation dialogue_00_31_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmh... no es el", "libro que te pedi"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"aw, graciaaaas!", "te debo una"}},
};

void Map_31_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_LIBRO] == 0)
    {
        if (language == ENGLISH)
            CurrentNPCDialogues[1] = (DialoguePerRelation *)&dialogue_00_31_en;
        else
            CurrentNPCDialogues[1] = (DialoguePerRelation *)&dialogue_00_31_es;
    }
}