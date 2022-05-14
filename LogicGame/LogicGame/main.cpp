#include "main.h"

int main()
{
    srand(time(NULL));

    Deck deck;

    initialize(deck);
    shuffle(deck);

    vector<Card> player_one;
    vector<Card> player_two;

    deal_cards(deck, player_one, player_two, 4);

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

    Card fourth_line_up[2];
    Card fourth_line_down[2];

    Card finish_up[1];
    Card finish_down[1];

    bool error = true;
    bool choose;
    bool winner;
    bool half = true;
    int line;
    int hand_card;
    int line_position;
    int switch_cards;

    while (!finish(finish_up, finish_down, &winner))
    {
        if (half)
        {
            check_empty(player_one, deck, &error);

            cout << endl << "   Player One:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_one);
            cout << endl << endl;


            print_line_down(finish_up, 1, 4);
            print_line_down(fourth_line_up, 2, 3);
            print_line_up(third_line_up, 3, 2);
            print_line_up(second_line_up, 4, 1);
            print_line_up(first_line_up, 5, 0);
            print_start_cards(start_up, start_down);
            print_line_down(first_line_down, 5, 0);
            print_line_down(second_line_down, 4, 1);
            print_line_down(third_line_down, 3, 2);
            print_line_down(fourth_line_down, 2, 3);
            print_line_down(finish_down, 1, 4);

            cout << endl << endl;

            back_or_play(player_one, deck, &switch_cards, &choose, &half, &error);

            if (choose)
            {
                select_move(&line, &hand_card, &line_position);
            }
        }
        else
        {
            check_empty(player_two, deck, &error);

            cout << endl << "   Player Two:" << endl;
            cout << endl << "   Cards:" << endl;
            print_hand(player_two);
            cout << endl;


            print_line_down(finish_up, 1, 4);
            print_line_down(fourth_line_up, 2, 3);
            print_line_up(third_line_up, 3, 2);
            print_line_up(second_line_up, 4, 1);
            print_line_up(first_line_up, 5, 0);
            print_start_cards(start_up, start_down);
            print_line_down(first_line_down, 5, 0);
            print_line_down(second_line_down, 4, 1);
            print_line_down(third_line_down, 3, 2);
            print_line_down(fourth_line_down, 2, 3);
            print_line_down(finish_down, 1, 4);

            cout << endl << endl;

            back_or_play(player_two, deck, &switch_cards, &choose, &half, &error);

            if (choose)
            {
                select_move(&line, &hand_card, &line_position);
            }
        }

        system("CLS");

        if (choose)
        {
            if (half)
            {
                if (line == 1)
                {
                    move_up_first(&half, hand_card, line_position, start_up, first_line_up, player_one, &error);
                }
                else if (line == 2)
                {
                    move_up(&half, hand_card, line_position, first_line_up, second_line_up, player_one, &error);
                }
                else if (line == 3)
                {
                    move_up(&half, hand_card, line_position, second_line_up, third_line_up, player_one, &error);
                }
                else if (line == 4)
                {
                    move_up(&half, hand_card, line_position, third_line_up, fourth_line_up, player_one, &error);
                }
                else if (line == 5)
                {
                    move_up(&half, hand_card, line_position, fourth_line_up, finish_up, player_one, &error);
                }
            }
            else
            {
                if (line == 1)
                {
                    move_down_first(&half, hand_card, line_position, start_down, first_line_down, player_two, &error);
                }
                else if (line == 2)
                {
                    move_down(&half, hand_card, line_position, first_line_down, second_line_down, player_two, &error);
                }
                else if (line == 3)
                {
                    move_down(&half, hand_card, line_position, second_line_down, third_line_down, player_two, &error);
                }
                else if (line == 4)
                {
                    move_up(&half, hand_card, line_position, third_line_down, fourth_line_down, player_two, &error);
                }
                else if (line == 5)
                {
                    move_up(&half, hand_card, line_position, fourth_line_down, finish_down, player_two, &error);
                }
            }
        }
    }

    system("CLS");

    cout << "Congratulations!" << endl << endl;

    if (winner)
    {
        cout << "Player One Wins!" << endl << endl;
    }
    else
    {
        cout << "Player Two Wins!" << endl << endl;
    }

    print_line_down(finish_up, 1, 4);
    print_line_down(fourth_line_up, 2, 3);
    print_line_up(third_line_up, 3, 2);
    print_line_up(second_line_up, 4, 1);
    print_line_up(first_line_up, 5, 0);
    print_start_cards(start_up, start_down);
    print_line_down(first_line_down, 5, 0);
    print_line_down(second_line_down, 4, 1);
    print_line_down(third_line_down, 3, 2);
    print_line_down(fourth_line_down, 2, 3);
    print_line_down(finish_down, 1, 4);
}