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

    bool start_up[6];
    bool start_down[6];

    start_shuffle(start_up, start_down);

    cout << endl << endl << endl;

    print_start_cards(start_up, start_down);

    Card first_line_up[5];
    Card first_line_down[5];

    bool half;
    int hand_card;
    int line_position;

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Choose a half:";
        cin >> half;
        cout << "Choose a card:";
        cin >> hand_card;
        cout << "Choose a position";
        cin >> line_position;
        cout << endl;

        if (half)
        {
            move_up(hand_card, line_position, start_up, first_line_up, player_one);
        }
        else
        {
            move_down(hand_card, line_position, start_down, first_line_down, player_two);
        }

        cout << endl;

        print_first_line_up(first_line_up);
        print_start_cards(start_up, start_down);
        print_first_line_down(first_line_down);

        cout << endl << endl << endl << endl << endl; 

    }
}