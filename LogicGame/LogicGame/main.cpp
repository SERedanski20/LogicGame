#include "main.h"

int main()
{
    srand(time(NULL));

    Deck deck;

    initialize(deck);
    shuffle(deck);

    vector<Card> player_one;
    vector<Card> player_two;

    deal_cards(deck, player_one, player_two, 7);


    print_hand(player_one);
    cout << endl;
    print_hand(player_two);
    cout << endl;
    print_deck(deck);
}