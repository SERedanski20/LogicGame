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
    cout << card.name << "   ";

    cout << "Value = " << card.value << " " << "Operator = ";

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

    for (Card c : hand)
    {
        print_card(c);
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
    for (int i = 0; i < 6; i++)
    {
        cout << start_up[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << start_down[i] << " ";
    }
    cout << endl;
}

void move_up(int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one)
{
    if (player_one[hand_card].operation == 0)
    {
        if (player_one[hand_card].value == (start_up[line_position] & start_up[line_position + 1]))
        {
            first_line_up[line_position] = player_one[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }
    }
    else if (player_one[hand_card].operation == 1)
    {
        if (player_one[hand_card].value == (start_up[line_position] | start_up[line_position + 1]))
        {
            first_line_up[line_position] = player_one[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }

    }
    else if (player_one[hand_card].operation == 2)
    {
        if (player_one[hand_card].value == (start_up[line_position] ^ start_up[line_position + 1]))
        {
            first_line_up[line_position] = player_one[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }
    }
}

void move_down(int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two)
{
    if (player_two[hand_card].operation == 0)
    {
        if (player_two[hand_card].value == (start_down[line_position] & start_down[line_position + 1]))
        {
            first_line_down[line_position] = player_two[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }
    }
    else if (player_two[hand_card].operation == 1)
    {
        if (player_two[hand_card].value == (start_down[line_position] | start_down[line_position + 1]))
        {
            first_line_down[line_position] = player_two[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }
    }
    else if (player_two[hand_card].operation == 2)
    {
        if (player_two[hand_card].value == (start_down[line_position] ^ start_down[line_position + 1]))
        {
            first_line_down[line_position] = player_two[hand_card];
        }
        else
        {
            cout << "You can't place this card here!" << endl;
        }
    }
}

void print_first_line_up(Card* first_line_up)
{
    cout << " ";
    for (int i = 0; i < 5; i++)
    {
        if (first_line_up[i].value == 0 || first_line_up[i].value == 1)
        {
            cout << first_line_up[i].value << " ";
        }
        else
        {
            cout << "- ";
        }
    }
    cout << endl;
}
void print_first_line_down(Card* first_line_down)
{
    cout << " ";
    for (int i = 0; i < 5; i++)
    {
        if (first_line_down[i].value == 0 || first_line_down[i].value == 1)
        {
            cout << first_line_down[i].value << " ";
        }
        else
        {
            cout << "- ";
        }
    }
    cout << endl;
}