#include "main.h"

void print_card(const Card& card)
{
    cout << " " << card.value << "  ";

    if (card.operation == 0)
    {
        cout << "AND";
    }
    else if (card.operation == 1)
    {
        cout << "OR";
    }
    else if (card.operation == 2)
    {
        cout << "XOR";
    }

    cout << endl;
}

void print_hand(const vector<Card>& hand)
{
    int counter = 1;

    for (Card c : hand)
    {
        cout << "   " << counter << ":";
        print_card(c);
        counter++;
    }
}

void print_start_cards(bool* start_up, bool* start_down)
{
    cout << setw(13);
    cout << "Line 0:   ";
    for (int i = 0; i < 6; i++)
    {
        cout << start_up[i] << " ";
    }
    cout << endl;

    cout << setw(13);
    cout << "Line 0:   ";
    for (int i = 0; i < 6; i++)
    {
        cout << start_down[i] << " ";
    }
    cout << endl;
}

void print_line_up(Card* line_up, int size, int space)
{
    cout << "   Line " << space + 1 << ":   ";
    cout << setw(1 + space) << " ";
    for (int i = 0; i < size; i++)
    {
        if (line_up[i].value == 0 || line_up[i].value == 1)
        {
            cout << line_up[i].value << " ";
        }
        else
        {
            cout << "- ";
        }
    }
    cout << endl;
}

void print_line_down(Card* line_down, int size, int space)
{
    cout << "   Line " << space + 1 << ":   ";
    cout << setw(1 + space) << " ";
    for (int i = 0; i < size; i++)
    {
        if (line_down[i].value == 0 || line_down[i].value == 1)
        {
            cout << line_down[i].value << " ";
        }
        else
        {
            cout << "- ";
        }
    }
    cout << endl;
}

void print_map(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up,
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down, Card* finish_up, Card* finish_down)
{
    cout << setw(23) << "player_one" << endl << endl;
    print_line_up(finish_up, 1, 4);
    print_line_up(fourth_line_up, 2, 3);
    print_line_up(third_line_up, 3, 2);
    print_line_up(second_line_up, 4, 1);
    print_line_up(first_line_up, 5, 0);
    print_start_cards(start_up, start_down);
    print_line_down(first_line_down, 5, 0);
    print_line_down(second_line_down, 4, 1);
    print_line_down(third_line_down, 3, 2);
    print_line_down(fourth_line_down, 2, 3);
    print_line_down(finish_down, 1, 4);
    cout << endl << setw(23) << "player_two";
}

void print_win(bool* winner)
{
    cout << "   ---------------------------------------------" << endl;
    cout << "                Congratulations!" << endl;
    cout << "   ---------------------------------------------" << endl << endl << endl;

    if (*winner)
    {
        cout << "            Player One Wins!" << endl;
        cout << "           -----------------" << endl << endl;
    }
    else
    {
        cout << "            Player Two Wins!" << endl;
        cout << "           -----------------" << endl << endl;
    }
}