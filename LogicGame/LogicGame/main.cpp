#include "main.h"

int main()
{
    srand(time(NULL));

    Deck deck;         // initialize deck
    Deck new_deck;       // initialize new_deck

    initialize(deck);
    shuffle(deck);

    vector<Card> player_one;       // initialize vector - player one
    vector<Card> player_two;       // initialize vector - player two

    deal_cards(deck, player_one, player_two, 4);

    bool start_up[6];          // initialize start_up boolean array
    bool start_down[6];        // initialize start_down boolean array

    start_shuffle(start_up, start_down);

    Card first_line_up[5];          // initialize Card type array for first line UP
    Card first_line_down[5];        // initialize Card type array for first line DOWN

    Card second_line_up[4];         // initialize Card type array for second line UP
    Card second_line_down[4];       // initialize Card type array for second line DOWN

    Card third_line_up[3];          // initialize Card type array for third line UP
    Card third_line_down[3];        // initialize Card type array for third line DOWN

    Card fourth_line_up[2];         // initialize Card type array for fourth line UP
    Card fourth_line_down[2];       // initialize Card type array for fourth line DOWN

    Card finish_up[1];              // initialize Card type array for final line UP
    Card finish_down[1];            // initialize Card type array for final line DOWN

    string choose;                  // initialize string variables

    bool GM_check = true;           // initialize bool variables
    bool AI;                        
    bool error = true;
    bool winner;
    bool half = true;

    int gamemode;                   // initialize int variables
    int line;
    int hand_card;
    int line_position;
    int switch_cards;

    choose_gamemode(&gamemode, &AI, &GM_check);

    if (GM_check)                   // checks if the gamemode is correctly chosen
    {

        system("CLS");

        while (!finish(finish_up, finish_down, &winner))            // loop while someone wins
        {
            if (half)                                               // checks in which half should do the move
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

                if (choose == "1")                              // checks if the player chose to play or to discard a card
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

                if (AI)                                             // checks if AI plays or Player plays
                {
                    if (choose == "1")                                  // checks if the AI chose to play or to discard a card
                    {
                        AI_select_move(first_line_down, second_line_down, third_line_down, fourth_line_down, &line, &hand_card, &line_position);
                    }
                }
                else
                {
                    if (choose == "1")                                  // checks if the player chose to play or to discard a card
                    {
                        select_move(&line, &hand_card, &line_position);
                    }
                }

                    system("CLS");

                if (AI)                                             // checks if AI plays or Player plays
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