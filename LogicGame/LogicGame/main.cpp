#include "main.h"

int main()
{
    srand(time(NULL));

    Deck deck;
    Deck new_deck;

    initialize(deck);
    shuffle(deck);

    vector<Card> player_one;
    vector<Card> player_two;

    deal_cards(deck, player_one, player_two, 4);

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

    string choose;
    int gamemode;
    bool GM_check = true;
    bool AI;
    bool error = true;
    bool winner;
    bool half = true;
    int line;
    int hand_card;
    int line_position;
    int switch_cards;

    choose_gamemode(&gamemode, &AI, &GM_check);

    if (GM_check)
    {

        system("CLS");

        while (!finish(finish_up, finish_down, &winner))
        {
            if (half)
            {

                check_empty(player_one, deck, new_deck, &error);

                cout << endl << "   Player One:" << endl;
                cout << endl << "   Cards:" << endl;
                print_hand(player_one);
                cout << endl << endl;


                print_map(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
                    fourth_line_up, fourth_line_down, finish_up, finish_down);

                cout << endl << endl;

                    back_or_play(player_one, deck, new_deck, &switch_cards, &choose, &half, &error);

                if (choose == "1")
                {
                    select_move(&line, &hand_card, &line_position);
                }

                    system("CLS");

                move_by_line(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
                    fourth_line_up, fourth_line_down, finish_up, finish_down, deck, player_one, player_two, &half, &error, &line, &hand_card, &line_position, &choose);
            }
            else
            {
                check_empty(player_two, deck, new_deck, &error);

                cout << endl << "   Player Two:" << endl;
                cout << endl << "   Cards:" << endl;
                print_hand(player_two);
                cout << endl;


                print_map(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
                    fourth_line_up, fourth_line_down, finish_up, finish_down);

                cout << endl << endl;

                if (AI)
                {
                    AI_back_or_play(player_two, deck, new_deck, &switch_cards, &choose, &half, &error);
                }
                else
                {
                    back_or_play(player_two, deck, new_deck, &switch_cards, &choose, &half, &error);
                }

                if (AI)
                {
                    if (choose == "1")
                    {
                        AI_select_move(first_line_down, second_line_down, third_line_down, fourth_line_down, &line, &hand_card, &line_position);
                    }
                }
                else
                {
                    if (choose == "1")
                    {
                        select_move(&line, &hand_card, &line_position);
                    }
                }

                    system("CLS");

                if (AI)
                {
                    AI_move_by_line(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
                        fourth_line_up, fourth_line_down, finish_up, finish_down, deck, player_one, player_two, &half, &error, &line, &hand_card, &line_position, &choose);
                }
                else
                {
                    move_by_line(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
                        fourth_line_up, fourth_line_down, finish_up, finish_down, deck, player_one, player_two, &half, &error, &line, &hand_card, &line_position, &choose);
                }
            }

        }

        system("CLS");

        print_win(&winner);

        print_map(start_up, start_down, first_line_up, first_line_down, second_line_up, second_line_down, third_line_up, third_line_down,
            fourth_line_up, fourth_line_down, finish_up, finish_down);
    }
}