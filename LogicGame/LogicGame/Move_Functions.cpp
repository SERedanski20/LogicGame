#include "main.h"

void move_up_first(bool* half, int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one, bool* error)
{
    if (player_one[hand_card - 1].operation == 0)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] & start_up[line_position]))
        {
            first_line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_one[hand_card - 1].operation == 1)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] | start_up[line_position]))
        {
            first_line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }

    }
    else if (player_one[hand_card - 1].operation == 2)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] ^ start_up[line_position]))
        {
            first_line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
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
            first_line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_two[hand_card - 1].operation == 1)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] | start_down[line_position]))
        {
            first_line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_two[hand_card - 1].operation == 2)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] ^ start_down[line_position]))
        {
            first_line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
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
            line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_one[hand_card - 1].operation == 1)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value | up[line_position].value))
        {
            line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    if (player_one[hand_card - 1].operation == 2)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value ^ up[line_position].value))
        {
            line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
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
            line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_two[hand_card - 1].operation == 1)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value | down[line_position].value))
        {
            line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
    else if (player_two[hand_card - 1].operation == 2)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value ^ down[line_position].value))
        {
            line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
            *error = true;
        }
        else
        {
            *error = false;
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_by_line(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up,
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down,
    Card* finish_up, Card* finish_down, Deck& deck, vector<Card>& player_one, vector<Card>& player_two, bool* half,
    bool* error, int* line, int* hand_card, int* line_position, bool* choose)
{
    if (*choose)
    {
        if (*half)
        {
            if (*line == 1)
            {
                move_up_first(half, *hand_card,* line_position, start_up, first_line_up, player_one, error);
            }
            else if (*line == 2)
            {
                move_up(half, *hand_card, *line_position, first_line_up, second_line_up, player_one, error);
            }
            else if (*line == 3)
            {
                move_up(half, *hand_card, *line_position, second_line_up, third_line_up, player_one, error);
            }
            else if (*line == 4)
            {
                move_up(half, *hand_card, *line_position, third_line_up, fourth_line_up, player_one, error);
            }
            else if (*line == 5)
            {
                move_up(half, *hand_card, *line_position, fourth_line_up, finish_up, player_one, error);
            }
        }
        else
        {
            if (*line == 1)
            {
                move_down_first(half, *hand_card, *line_position, start_down, first_line_down, player_two, error);
            }
            else if (*line == 2)
            {
                move_down(half, *hand_card, *line_position, first_line_down, second_line_down, player_two, error);
            }
            else if (*line == 3)
            {
                move_down(half, *hand_card, *line_position, second_line_down, third_line_down, player_two, error);
            }
            else if (*line == 4)
            {
                move_up(half, *hand_card, *line_position, third_line_down, fourth_line_down, player_two, error);
            }
            else if (*line == 5)
            {
                move_up(half, *hand_card, *line_position, fourth_line_down, finish_down, player_two, error);
            }
        }
    }
}