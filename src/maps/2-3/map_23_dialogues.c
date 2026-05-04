#pragma bank 3

#include "core/characters/npc_lines.h"
#include "core/definitions/language.h"
#include "core/characters/npc_stats_map.h"
#include "maps/2-3/map_23.h"

const DialoguePerRelation dialogue_00_23_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"que necesitas?", ""}, {"hola", "que buscabas?"}, {"buen dia! que", "andabas buscando?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_00_23_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"hey", ""}, {"hello,", "what do you need?"}, {"yo, kid! what are", "you looking for?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_23_InitDialogues()
{
  if (dialogue_phase[(uint8_t)NPC_DIARIO] == 0)
  {
    if (language == SPANISH)
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_23_es;
    else
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_23_en;
  }
}
