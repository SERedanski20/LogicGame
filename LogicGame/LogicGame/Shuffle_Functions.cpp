#include "main.h"

void shuffle(Deck& deck)
{
    Deck shuffled;

    while (!deck.cards.empty())
    {
        size_t random_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[random_index]);
        deck.cards.erase(deck.cards.begin() + random_index);
    }

    deck = shuffled;
}

void start_shuffle(bool* start_up, bool* start_down)
{
    for (int i = 0; i < 6; i++)
    {
        size_t random = rand() % 100;
        if (random % 2 == 0)
        {
            start_up[i] = true;
        }
        else
        {
            start_up[i] = false;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        start_down[i] = !(start_up[i]);
    }
}