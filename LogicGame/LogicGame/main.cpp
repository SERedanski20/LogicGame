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

    for (int i = 0; i < 100; i++)
    {
        if (half)
        {
            cout << endl << "   Player One:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_one);
            cout << endl << endl;
        }
        else
        {
            cout << endl << "   Player Two:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_two);
            cout << endl;
        }

        print_third_line_up(third_line_up);
        print_second_line_up(second_line_up);
        print_first_line_up(first_line_up);
        print_start_cards(start_up, start_down);
        print_first_line_down(first_line_down);
        print_second_line_down(second_line_down);
        print_third_line_down(third_line_down);

        cout << endl;

        cout << "   (1, 2, 3, 4, 5) Select a line: ";
        cin >> line;

        cout << "   (1, 2, 3, 4, 5, 6, 7) Select a card: ";
        cin >> hand_card;

        if (line == 1)
        {
            cout << "   (1, 2, 3, 4, 5) Select a position: ";
            cin >> line_position;
            cout << endl;
        }
        else if(line == 2)
        {
            cout << "   (1, 2, 3, 4) Select a position: ";
            cin >> line_position;
            cout << endl;
        }
        else if (line == 3)
        {
            cout << "   (1, 2, 3) Select a position: ";
            cin >> line_position;
            cout << endl;
        }
        else if (line == 4)
        {
            cout << "   (1, 2) Select a position: ";
            cin >> line_position;
            cout << endl;
        }
        else
        {
            cout << "   (1) Finish!: ";
            cin >> line_position;
            cout << endl;
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
                move_up_second(&half, hand_card, line_position, second_line_up, third_line_up, player_one);
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
                move_down_second(&half, hand_card, line_position, second_line_down, third_line_down, player_two);
            }
        }
    }
}