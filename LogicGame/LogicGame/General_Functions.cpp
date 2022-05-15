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

            //create 8 copies of the card and add them to the deck
            for (int i = 0; i < 8; i++)
            {
                deck.cards.push_back(card);
            }
        }
    }
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

void select_move(int* line, int* hand_card, int* line_position)
{
    cout << "   (1, 2, 3, 4, 5) Select a line: ";
    cin >> *line;

    cout << "   (1, 2, 3, 4, 5) Select a card: ";
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

void check_empty(vector<Card>& player, Deck& deck, Deck& new_deck, bool* error)
{
    if (deck.cards.empty())
    {
        if (new_deck.cards.empty())
        {
            cout << endl;
            cout << "   ----------------------------------------------" << endl;
            cout << "        There are no cards left in the deck!" << endl;
            cout << "   ----------------------------------------------" << endl << endl;
        }
        else
        {
            Deck clear_deck;
            deck = new_deck;
            shuffle(deck);
            new_deck = clear_deck;
        }
    }
    else
    {

        if (*error)
        {
            player.push_back(deck.cards[0]);
            deck.cards.erase(deck.cards.begin());
        }
    }
}

void back_or_play(vector<Card>& player, Deck& deck, Deck& new_deck, int* switch_cards, string* choose, bool* half, bool* error)
{
    cout << "   (1 - play, 0 - discard) Discard card or play?: ";
    cin >> *choose;

    if (*choose != "1" && *choose != "0")
    {
        cout << "   ---------------------------------------------" << endl;
        cout << "           Error!, invalid move entered." << endl;
        cout << "   ---------------------------------------------" << endl << endl;
        *error = false;
    }
    else
    {
        if (*choose == "0")
        {
            cout << "   (1, 2, 3, 4, 5) Which card do you want to discard?: ";
            cin >> *switch_cards;

            if (*switch_cards < 6)
            {
                new_deck.cards.push_back(player[*switch_cards - 1]);
                player.erase(player.begin() + *switch_cards - 1);

                *half = !(*half);
                *error = true;
            }
            else
            {
                cout << "   ---------------------------------------------" << endl;
                cout << "           Error!, invalid card entered." << endl;
                cout << "   ---------------------------------------------" << endl << endl;
                *error = false;
            }
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
    else
    {
        return false;
    }
}

void choose_gamemode(int* gamemode, bool* AI, bool* GM_check)
{
    cout << "                       Gamemodes" << endl;
    cout << "Player VS Player - 1:      /      Computer VS Player - 2: " << endl;
    cout << "Choose your Gamemode: ";
    cin >> *gamemode;

    if (*gamemode != 1 && *gamemode != 2)
    {
        system("CLS");
        cout << "   ---------------------------------------------" << endl;
        cout << "                 Invalid Gamemode!" << endl;
        cout << "   ---------------------------------------------" << endl << endl << endl;
        *GM_check = false;
    }
    else if (*gamemode == 1)
    {
        *AI = false;
    }
    else
    {
        *AI = true;
    }
}