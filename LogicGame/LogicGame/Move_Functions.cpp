#include "main.h"

void move_up_first(bool* half, int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one, bool* error)
{
    if (player_one[hand_card - 1].operation == 0)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] & start_up[line_position]))
        {
            if (first_line_up[line_position - 1].value != 0 && first_line_up[line_position - 1].value != 1)
            {
                first_line_up[line_position - 1] = player_one[hand_card - 1];
                player_one.erase(player_one.begin() + (hand_card - 1));
                *half = false;
                *error = true;
            }
            else
            {
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_one[hand_card - 1].operation == 1)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] | start_up[line_position]))
        {
            if (first_line_up[line_position - 1].value != 0 && first_line_up[line_position - 1].value != 1)
            {
                first_line_up[line_position - 1] = player_one[hand_card - 1];
                player_one.erase(player_one.begin() + (hand_card - 1));
                *half = false;
                *error = true;
            }
            else
            {
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }

    }
    else if (player_one[hand_card - 1].operation == 2)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] ^ start_up[line_position]))
        {
            if (first_line_up[line_position - 1].value != 0 && first_line_up[line_position - 1].value != 1)
            {
                first_line_up[line_position - 1] = player_one[hand_card - 1];
                player_one.erase(player_one.begin() + (hand_card - 1));
                *half = false;
                *error = true;
            }
            else
            {
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two, bool* error)
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
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
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
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
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
                cout << "   ---------------------------------------------" << endl;
                cout << "           There is already a card hare!" << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_up(bool* half, int hand_card, int line_position, Card* up, Card* line_up, vector<Card>& player_one, bool* error)
{
    if (player_one[hand_card - 1].operation == 0)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value & up[line_position].value))
        {
            if ((up[line_position - 1].value == 0 || up[line_position - 1].value == 1) && (up[line_position].value == 0 || up[line_position].value == 1))
            {
                if (line_up[line_position - 1].value != 0 && line_up[line_position - 1].value != 1)
                {
                    line_up[line_position - 1] = player_one[hand_card - 1];
                    player_one.erase(player_one.begin() + (hand_card - 1));
                    *half = false;
                    *error = true;
                }
                else
                {
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;
            }
            
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_one[hand_card - 1].operation == 1)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value | up[line_position].value))
        {
            if ((up[line_position - 1].value == 0 || up[line_position - 1].value == 1) && (up[line_position].value == 0 || up[line_position].value == 1))
            {
                if (line_up[line_position - 1].value != 0 && line_up[line_position - 1].value != 1)
                {
                    line_up[line_position - 1] = player_one[hand_card - 1];
                    player_one.erase(player_one.begin() + (hand_card - 1));
                    *half = false;
                    *error = true;
                }
                else
                {
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;
            }

        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    if (player_one[hand_card - 1].operation == 2)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value ^ up[line_position].value))
        {
            if ((up[line_position - 1].value == 0 || up[line_position - 1].value == 1) && (up[line_position].value == 0 || up[line_position].value == 1))
            {
                if (line_up[line_position - 1].value != 0 && line_up[line_position - 1].value != 1)
                {
                    line_up[line_position - 1] = player_one[hand_card - 1];
                    player_one.erase(player_one.begin() + (hand_card - 1));
                    *half = false;
                    *error = true;
                }
                else
                {
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;
            }
            
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_down(bool* half, int hand_card, int line_position, Card* down, Card* line_down, vector<Card>& player_two, bool* error)
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
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;
            }
            
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
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
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;
            }
            
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
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
                    cout << "   ---------------------------------------------" << endl;
                    cout << "           There is already a card hare!" << endl;
                    cout << "   ---------------------------------------------" << endl << endl;
                    *error = false;
                }
            }
            else
            {
                *error = false;
                cout << "   ----------------------------------------------" << endl;
                cout << "           You can't place this card here!" << endl;
                cout << "   ----------------------------------------------" << endl << endl;;
            }
            
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "           You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;;
        }
    }
}

void move_by_line(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up,
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down,
    Card* finish_up, Card* finish_down, Deck& deck, vector<Card>& player_one, vector<Card>& player_two, bool* half,
    bool* error, int* line, int* hand_card, int* line_position, string* choose)
{

    if (*choose != "1" && *choose != "0")
    {
        cout << "   ---------------------------------------------" << endl;
        cout << "           Error!, invalid move entered." << endl;
        cout << "   ---------------------------------------------" << endl << endl;
        *error = false;
    }
    else
    {
        if (*choose == "1")
        {
            if (*half)
            {
                if (*line > 5)
                {
                    cout << "   -------------------------------------------" << endl;
                    cout << "          Error!, invalid line entered." << endl;
                    cout << "   -------------------------------------------" << endl << endl;
                    *error = false;
                }
                else
                {
                    if (*line == 1)
                    {
                        if (*line_position > 5 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_up_first(half, *hand_card, *line_position, start_up, first_line_up, player_one, error);
                        }
                    }
                    else if (*line == 2)
                    {
                        if (*line_position > 4 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_up(half, *hand_card, *line_position, first_line_up, second_line_up, player_one, error);
                        }
                    }
                    else if (*line == 3)
                    {
                        if (*line_position > 3 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_up(half, *hand_card, *line_position, second_line_up, third_line_up, player_one, error);
                        }
                    }
                    else if (*line == 4)
                    {
                        if (*line_position > 2 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_up(half, *hand_card, *line_position, third_line_up, fourth_line_up, player_one, error);
                        }
                    }
                    else if (*line == 5)
                    {
                        if (*line_position > 1 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_up(half, *hand_card, *line_position, fourth_line_up, finish_up, player_one, error);
                        }
                    }
                }
            }
            else
            {
                if (*line > 5)
                {
                    cout << "   -----------------------------------------------" << endl;
                    cout << "      Error!, invalid position or card entered." << endl;
                    cout << "   -----------------------------------------------" << endl << endl;
                    *error = false;
                }
                else
                {
                    if (*line == 1)
                    {
                        if (*line_position > 5 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_down_first(half, *hand_card, *line_position, start_down, first_line_down, player_two, error);
                        }
                    }
                    else if (*line == 2)
                    {
                        if (*line_position > 4 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_down(half, *hand_card, *line_position, first_line_down, second_line_down, player_two, error);
                        }
                    }
                    else if (*line == 3)
                    {
                        if (*line_position > 3 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_down(half, *hand_card, *line_position, second_line_down, third_line_down, player_two, error);
                        }
                    }
                    else if (*line == 4)
                    {
                        if (*line_position > 2 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_down(half, *hand_card, *line_position, third_line_down, fourth_line_down, player_two, error);
                        }
                    }
                    else if (*line == 5)
                    {
                        if (*line_position > 1 || *hand_card > 5)
                        {
                            cout << "   -----------------------------------------------" << endl;
                            cout << "      Error!, invalid position or card entered." << endl;
                            cout << "   -----------------------------------------------" << endl << endl;
                            *error = false;
                        }
                        else
                        {
                            move_down(half, *hand_card, *line_position, fourth_line_down, finish_down, player_two, error);
                        }
                    }
                }
            }
        }
    }
}