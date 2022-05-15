#include "main.h"

//AI choose move to perform
void AI_select_move(Card* first_line_down, Card* second_line_down, Card* third_line_down, Card* fourth_line_down, int* line, int* hand_card, int* line_position)
{
    int counter1 = 0;
    for (int i = 0; i < 5; i++)
    {
        if (first_line_down[i].value == 1 || first_line_down[i].value == 0)
        {
            counter1++;
        }
    }
    if (counter1 < 5)
    {
        *line = 1;
    }
    else
    {
        int counter2 = 0;
        for (int i = 0; i < 4; i++)
        {
            if (second_line_down[i].value == 1 || second_line_down[i].value == 0)
            {
                counter2++;
            }
        }
        if (counter2 < 4)
        {
            *line = 2;
        }
        else
        {
            int counter3 = 0;
            for (int i = 0; i < 3; i++)
            {
                if (third_line_down[i].value == 1 || third_line_down[i].value == 0)
                {
                    counter3++;
                }
            }
            if (counter3 < 3)
            {
                *line = 3;
            }
            else
            {
                int counter4 = 0;
                for (int i = 0; i < 2; i++)
                {
                    if (fourth_line_down[i].value == 1 || fourth_line_down[i].value == 0)
                    {
                        counter4++;
                    }
                }
                if (counter4 < 2)
                {
                    *line = 4;
                }
                else
                {
                    *line = 5;
                }
            }
        }
    }
    
    *hand_card = rand() % 5 + 1;
    if (*line == 1)
    {
        if (first_line_down[0].value != 0 && first_line_down[0].value != 1)
        {
            *line_position = 1;
        }
        else if (first_line_down[1].value != 0 && first_line_down[1].value != 1)
        {
            *line_position = 2;
        }
        else if (first_line_down[2].value != 0 && first_line_down[2].value != 1)
        {
            *line_position = 3;
        }
        else if (first_line_down[3].value != 0 && first_line_down[3].value != 1)
        {
            *line_position = 4;
        }
        else if (first_line_down[4].value != 0 && first_line_down[4].value != 1)
        {
            *line_position = 5;
        }
    }
    else if (*line == 2)
    {
        if (second_line_down[0].value != 0 && second_line_down[0].value != 1)
        {
            *line_position = 1;
        }
        else if (second_line_down[1].value != 0 && second_line_down[1].value != 1)
        {
            *line_position = 2;
        }
        else if (second_line_down[2].value != 0 && second_line_down[2].value != 1)
        {
            *line_position = 3;
        }
        else if (second_line_down[3].value != 0 && second_line_down[3].value != 1)
        {
            *line_position = 4;
        }
    }
    else if (*line == 3)
    {
        if (third_line_down[0].value != 0 && third_line_down[0].value != 1)
        {
            *line_position = 1;
        }
        else if (third_line_down[1].value != 0 && third_line_down[1].value != 1)
        {
            *line_position = 2;
        }
        else if (third_line_down[2].value != 0 && third_line_down[2].value != 1)
        {
            *line_position = 3;
        }
    }
    else if (*line == 4)
    {
        if (fourth_line_down[0].value != 0 && fourth_line_down[0].value != 1)
        {
            *line_position = 1;
        }
        else if (fourth_line_down[1].value != 0 && fourth_line_down[1].value != 1)
        {
            *line_position = 2;
        }
    }
    else if (*line == 5)
    {
        *line_position = 1;
    }
}

// select move
void AI_move_by_line(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up,
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down,
    Card* finish_up, Card* finish_down, Deck& deck, vector<Card>& player_one, vector<Card>& player_two, bool* half,
    bool* error, int* line, int* hand_card, int* line_position, string* choose)
{
    if (*choose != "1" && *choose != "0")
    {
        *error = false;
    }
    else
    {
        if (*choose == "1")
        {
            
            if (*line > 5)
            {
                *error = false;
            }
            else
            {
                if (*line == 1)
                {
                    if (*line_position > 5 || *hand_card > 5)
                    {
                        *error = false;
                    }
                    else
                    {
                        AI_move_down_first(half, *hand_card, *line_position, start_down, first_line_down, player_two, error);
                    }
                }
                else if (*line == 2)
                {
                    if (*line_position > 4 || *hand_card > 5)
                    {
                        *error = false;
                    }
                    else
                    {
                        AI_move_down(half, *hand_card, *line_position, first_line_down, second_line_down, player_two, error);
                    }
                }
                else if (*line == 3)
                {
                    if (*line_position > 3 || *hand_card > 5)
                    {
                        *error = false;
                    }
                    else
                    {
                        AI_move_down(half, *hand_card, *line_position, second_line_down, third_line_down, player_two, error);
                    }
                }
                else if (*line == 4)
                {
                    if (*line_position > 2 || *hand_card > 5)
                    {
                        *error = false;
                    }
                    else
                    {
                        AI_move_down(half, *hand_card, *line_position, third_line_down, fourth_line_down, player_two, error);
                    }
                }
                else if (*line == 5)
                {
                    if (*line_position > 1 || *hand_card > 5)
                    {
                        *error = false;
                    }
                    else
                    {
                        AI_move_down(half, *hand_card, *line_position, fourth_line_down, finish_down, player_two, error);
                    }
                }
            }
        }
    }
}

// AI paste card for first line (half down)
void AI_move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two, bool* error)
{
    if (player_two[hand_card - 1].operation == 0)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] & start_down[line_position]))
        {
            if (first_line_down[line_position - 1].value != 0 && first_line_down[line_position - 1].value != 1)
            {
                first_line_down[line_position - 1] = player_two[hand_card - 1];
                player_two.erase(player_two.begin() + (hand_card - 1));
                *half = true;
                *error = true;
            }
            else
            {
                *error = false;
            }
        }
        else
        {
            *error = false;
        }
    }
    else if (player_two[hand_card - 1].operation == 1)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] | start_down[line_position]))
        {
            if (first_line_down[line_position - 1].value != 0 && first_line_down[line_position - 1].value != 1)
            {
                first_line_down[line_position - 1] = player_two[hand_card - 1];
                player_two.erase(player_two.begin() + (hand_card - 1));
                *half = true;
                *error = true;
            }
            else
            {
                *error = false;
            }
        }
        else
        {
            *error = false;
        }
    }
    else if (player_two[hand_card - 1].operation == 2)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] ^ start_down[line_position]))
        {
            if (first_line_down[line_position - 1].value != 0 && first_line_down[line_position - 1].value != 1)
            {
                first_line_down[line_position - 1] = player_two[hand_card - 1];
                player_two.erase(player_two.begin() + (hand_card - 1));
                *half = true;
                *error = true;
            }
            else
            {
                *error = false;
            }
        }
        else
        {
            *error = false;
        }
    }
}

// AI paste card for all other lines (half down)
void AI_move_down(bool* half, int hand_card, int line_position, Card* down, Card* line_down, vector<Card>& player_two, bool* error)
{
    if (player_two[hand_card - 1].operation == 0)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value & down[line_position].value))
        {
            if ((down[line_position - 1].value == 0 || down[line_position - 1].value == 1) && (down[line_position].value == 0 || down[line_position].value == 1))
            {
                if (line_down[line_position - 1].value != 0 && line_down[line_position - 1].value != 1)
                {
                    line_down[line_position - 1] = player_two[hand_card - 1];
                    player_two.erase(player_two.begin() + (hand_card - 1));
                    *half = true;
                    *error = true;
                }
                else
                {
                    *error = false;
                }
            }
            else
            {
                *error = false;
            }

        }
        else
        {
            *error = false;
        }
    }
    else if (player_two[hand_card - 1].operation == 1)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value | down[line_position].value))
        {
            if ((down[line_position - 1].value == 0 || down[line_position - 1].value == 1) && (down[line_position].value == 0 || down[line_position].value == 1))
            {
                if (line_down[line_position - 1].value != 0 && line_down[line_position - 1].value != 1)
                {
                    line_down[line_position - 1] = player_two[hand_card - 1];
                    player_two.erase(player_two.begin() + (hand_card - 1));
                    *half = true;
                    *error = true;
                }
                else
                {
                    *error = false;
                }
            }
            else
            {
                *error = false;
            }

        }
        else
        {
            *error = false;
        }
    }
    else if (player_two[hand_card - 1].operation == 2)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value ^ down[line_position].value))
        {
            if ((down[line_position - 1].value == 0 || down[line_position - 1].value == 1) && (down[line_position].value == 0 || down[line_position].value == 1))
            {
                if (line_down[line_position - 1].value != 0 && line_down[line_position - 1].value != 1)
                {
                    line_down[line_position - 1] = player_two[hand_card - 1];
                    player_two.erase(player_two.begin() + (hand_card - 1));
                    *half = true;
                    *error = true;
                }
                else
                {
                    *error = false;
                }
            }
            else
            {
                *error = false;
            }

        }
        else
        {
            *error = false;
        }
    }
}

// select the chance to discard the card or play the card
void AI_back_or_play(vector<Card>& player, Deck& deck, Deck& new_deck, int* switch_cards, string* choose, bool* half, bool* error)
{
    int random = rand() % 40 + 1;
    if (random % 2 == 0)
    {
        *choose = "1";
    }
    else if (random % 3 == 0)
    {
        *choose = "1";
    }
    else if (random % 5 == 0)
    {
        *choose = "1";
    }
    else if (random % 7 == 0)
    {
        *choose = "1";
    }
    else if (random % 11 == 0)
    {
        *choose = "1";
    }
    else if (random % 13 == 0)
    {
        *choose = "1";
    }
    else if (random % 17 == 0)
    {
        *choose = "1";
    }
    else if (random % 19 == 0)
    {
        *choose = "1";
    }
    else
    {
        *choose = "0";
    }

    if (*choose != "1" && *choose != "0")
    {
        *error = false;
    }
    else
    {
        if (*choose == "0")
        {
            *switch_cards = rand() % 5 + 1;

            if (*switch_cards < 6)
            {
                new_deck.cards.push_back(player[*switch_cards - 1]);
                player.erase(player.begin() + *switch_cards - 1);

                *half = !(*half);
                *error = true;
            }
            else
            {
                *error = false;
            }
        }
    }
}