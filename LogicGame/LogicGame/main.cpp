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

    //print_deck(deck);

    bool start_up[6];
    bool start_down[6];

    start_shuffle(start_up, start_down);

    Card first_line_up[5];
    Card first_line_down[5];

    Card second_line_up[4];
    Card second_line_down[4];

    Card third_line_up[3];
    Card third_line_down[3];

    bool half = true;
    int line;
    int hand_card;
    int line_position;
    bool add_card = false;

    for (int i = 0; i < 100; i++)
    {
        if (half)
        {
            cout << endl << "   Player One:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_one);
            cout << endl << endl;

            print_third_line_up(third_line_up);
            print_second_line_up(second_line_up);
            print_first_line_up(first_line_up);
            print_start_cards(start_up, start_down);
            print_first_line_down(first_line_down);
            print_second_line_down(second_line_down);
            print_third_line_down(third_line_down);

            cout << endl;

            if (!deck.cards.empty())
            {
                cout << "   (1 - Yes, 0 - No) Do you want new card?: ";
                cin >> add_card;
            }

            select_move(player_one, deck, &line, &hand_card, &line_position, add_card, &half);
        }
        else
        {
            cout << endl << "   Player Two:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_two);
            cout << endl;

            print_third_line_up(third_line_up);
            print_second_line_up(second_line_up);
            print_first_line_up(first_line_up);
            print_start_cards(start_up, start_down);
            print_first_line_down(first_line_down);
            print_second_line_down(second_line_down);
            print_third_line_down(third_line_down);

            cout << endl;

            if (!deck.cards.empty())
            {
                cout << "   (1 - Yes, 0 - No) Do you want new card?: ";
                cin >> add_card;
            }

            select_move(player_two, deck, &line, &hand_card, &line_position, add_card, &half);
        }

        system("CLS");

        if (half)
        {
            if (line == 1)
            {
                move_up_first(&half, hand_card, line_position, start_up, first_line_up, player_one);
            }
            else if (line == 2)
            {
                move_up_second(&half, hand_card, line_position, first_line_up, second_line_up, player_one);
            }
            else if (line == 3)
            {
                move_up_third(&half, hand_card, line_position, second_line_up, third_line_up, player_one);
            }
        }
        else
        {
            if (line == 1)
            {
                move_down_first(&half, hand_card, line_position, start_down, first_line_down, player_two);
            }
            else if (line == 2)
            {
                move_down_second(&half, hand_card, line_position, first_line_down, second_line_down, player_two);
            }
            else if (line == 3)
            {
                move_down_third(&half, hand_card, line_position, second_line_down, third_line_down, player_two);
            }
        }
    }
}