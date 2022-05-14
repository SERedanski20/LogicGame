#include "main.h"

void initialize(Deck& deck)
{
    Card card;

    //create each type of card in the game
    for (int operation = 0; operation < card.num_operation; operation++)
    {
        for (int value = 0; value < card.num_value; value++)
        {
            //set card values
            card.operation = Operator(operation);
            card.value = Value(value);

            if (card.operation == 0 && card.value == 0)
            {
                card.name = 'a';
            }
            else if (card.operation == 0 && card.value == 1)
            {
                card.name = 'A';
            }
            else if (card.operation == 1 && card.value == 0)
            {
                card.name = 'o';
            }
            else if (card.operation == 1 && card.value == 1)
            {
                card.name = 'O';
            }
            else if (card.operation == 2 && card.value == 0)
            {
                card.name = 'x';
            }
            else if (card.operation == 2 && card.value == 1)
            {
                card.name = 'X';
            }

            //create 8 copies of the card and add them to the deck
            for (int i = 0; i < 8; i++)
            {
                deck.cards.push_back(card);
            }
        }
    }
}

void shuffle(Deck& deck)
{
    Deck shuffled;

    while (!deck.cards.empty())
    {
        size_t random_index = rand() % deck.cards.size();
        shuffled.cards.push_back(deck.cards[random_index]);
        deck.cards.erase(deck.cards.begin() + random_index);
    }

    deck = shuffled;
}

void deal_cards(Deck& deck, vector<Card>& player_one, vector<Card>& player_two, int num_cards)
{
    for (int card = 0; card < num_cards; card++)
    {
        player_one.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
        player_two.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
    }
}

void print_card(const Card& card)
{
   // cout << card.name << "   ";

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

void print_deck(const Deck& deck)
{

    for (Card c : deck.cards)
    {
        print_card(c);
    }
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

void start_shuffle(bool* start_up, bool* start_down)
{
    for (int i = 0; i < 6; i++)
    {
        size_t random = rand() % 100;
        if (random % 2 == 0)
        {
            start_up[i] = true;
        }
        else
        {
            start_up[i] = false;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        start_down[i] = !(start_up[i]);
    }
}

void print_start_cards(bool* start_up, bool* start_down)
{
    cout << setw(13);
    for (int i = 0; i < 6; i++)
    {
        cout << start_up[i] << " ";
    }
    cout << endl;

    cout << setw(13);
    for (int i = 0; i < 6; i++)
    {
        cout << start_down[i] << " ";
    }
    cout << endl;
}

void move_up_first(bool* half, int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one)
{
    if (player_one[hand_card - 1].operation == 0)
    {
        if (player_one[hand_card - 1].value == (start_up[line_position - 1] & start_up[line_position]))
        {
            first_line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
        }
        else
        {
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
        }
        else
        {
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
        }
        else
        {
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two)
{
    if (player_two[hand_card - 1].operation == 0)
    {
        if (player_two[hand_card - 1].value == (start_down[line_position - 1] & start_down[line_position]))
        {
            first_line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
        }
        else
        {
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
        }
        else
        {
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
        }
        else
        {
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void print_line_up(Card* line_up, int size, int space)
{
    cout << setw(13 + space) << " ";
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
    cout << setw(13 + space) << " ";
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

void move_up(bool* half, int hand_card, int line_position, Card* up, Card* line_up, vector<Card>& player_one)
{
    if (player_one[hand_card - 1].operation == 0)
    {
        if (player_one[hand_card - 1].value == (up[line_position - 1].value & up[line_position].value))
        {
            line_up[line_position - 1] = player_one[hand_card - 1];
            player_one.erase(player_one.begin() + (line_position - 1));
            *half = false;
        }
        else
        {
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
        }
        else
        {
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
        }
        else
        {
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void move_down(bool* half, int hand_card, int line_position, Card* down, Card* line_down, vector<Card>& player_two)
{
    if (player_two[hand_card - 1].operation == 0)
    {
        if (player_two[hand_card - 1].value == (down[line_position - 1].value & down[line_position].value))
        {
            line_down[line_position - 1] = player_two[hand_card - 1];
            player_two.erase(player_two.begin() + (line_position - 1));
            *half = true;
        }
        else
        {
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
        }
        else
        {
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
        }
        else
        {
            cout << "   ----------------------------------------------" << endl;
            cout << "        You can't place this card here!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
    }
}

void select_move(vector<Card>& player, Deck& deck, int* line, int* hand_card, int* line_position, bool add_card, bool* half)
{
    if (deck.cards.empty() && add_card == true)
    {
        cout << endl;
        cout << "   ----------------------------------------------" << endl;
        cout << "        There are no cards left in the deck!" << endl;
        cout << "   ----------------------------------------------" << endl << endl;
        add_card = false;
    }
    if (add_card)
    {
        player.push_back(deck.cards[0]);
        deck.cards.erase(deck.cards.begin());
        *half = !(*half);
    }
    else
    {
        cout << "   (1, 2, 3, 4, 5) Select a line: ";
        cin >> *line;

        cout << "   (1, 2, 3, 4, 5, 6, 7) Select a card: ";
        cin >> *hand_card;

        if (*line == 1)
        {
            cout << "   (1, 2, 3, 4, 5) Select a position: ";
            cin >> *line_position;
            cout << endl;
        }
        else if (*line == 2)
        {
            cout << "   (1, 2, 3, 4) Select a position: ";
            cin >> *line_position;
            cout << endl;
        }
        else if (*line == 3)
        {
            cout << "   (1, 2, 3) Select a position: ";
            cin >> *line_position;
            cout << endl;
        }
        else if (*line == 4)
        {
            cout << "   (1, 2) Select a position: ";
            cin >> *line_position;
            cout << endl;
        }
        else
        {
            cout << "   (1) Finish!: ";
            cin >> *line_position;
            cout << endl;
        }
    }
}

bool finish(Card* finish_up, Card* finish_down, bool* winner)
{
    if (finish_up[0].value == 0 || finish_up[0].value == 1)
    {
        *winner = true;
        return true;
    }
    else if (finish_down[0].value == 0 || finish_down[0].value == 1)
    {
        *winner = false;
        return true;
    }
}