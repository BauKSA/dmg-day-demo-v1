#pragma bank 4
#include <gb/gb.h>

#include "maps/3-0/map_30.h"
#include "maps/utils/map_data.h"

#include "core/definitions/language.h"

#include "core/characters/npc_lines.h"
#include "core/characters/npc_stats_map.h"

/**
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 * DIALOGO FASE 0:|||||||||||||||||||||||||||||||||||
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 */
static const DialoguePerRelation dialogue_0_30_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmh,", "estas hojas..."}, {"buen dia", ""}, {"que maravilloso", "dia, no?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_0_30_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmph...", "these leaves..."}, {"good morning", ""}, {"what a beautiful", "day, kid"}},
    {{"", ""}, {"", ""}, {"", ""}}};

/**
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 * DIALOGO FASE 1:|||||||||||||||||||||||||||||||||||
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 */
static const DialoguePerRelation dialogue_1_30_es = {
    {{"ya que estas al", "pedo, ayudame"}, {"me ayudas a barrer", "las hojas?"}, {"me podrias dar una", "mano, por favor?"}},
    {{"podrias ayudarme,", "no?"}, {"no quiero molestar", "me das una mano?"}, {"podrias ayudar a", "tu querida vecina?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_1_30_en = {
    {{"help me, you're", "doing bugger all"}, {"can you help", "me out?"}, {"please, give me", "a hand with this"}},
    {{"since you're free", "help me out"}, {"mind help me", "with this?"}, {"c'mon kid, be a", "hero and help me"}},
    {{"", ""}, {"", ""}, {"", ""}}};

/**
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 * DIALOGO FASE 2:|||||||||||||||||||||||||||||||||||
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 */
static const DialoguePerRelation dialogue_2_30_es = {
    {{"para eso lo hacia", "yo..."}, {"gracias...", ""}, {"gracias. no faltes", "al colegio!"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"gracias. hiciste", "mas que mis nietos"}, {"gracias! saludos", "a tu madre"}, {"me salvaste,", "corazon. gracias!"}}};

static const DialoguePerRelation dialogue_2_30_en = {
    {{"should've just", "done it myself..."}, {"thanks...", ""}, {"thank you. go", "to school, c'mon"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"thank you. i appreciate it"}, {"thank you!", "greet your mother"}, {"saved me,", "sweetheart. thank you!"}}};

/**
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 * DIALOGO FASE 9:|||||||||||||||||||||||||||||||||||
 * ||||||||||||||||||||||||||||||||||||||||||||||||||
 */
static const DialoguePerRelation dialogue_9_30_es = {
    {{"hmpf...", "que antipatico"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_9_30_en = {
    {{"hmpf...", "how rude"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
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

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 1)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_30_en;
    }

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 2)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_30_en;
    }

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 9)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_9_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_9_30_en;
    }
}