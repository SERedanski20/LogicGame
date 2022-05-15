#pragma once

#include <iostream>
#include<vector>
#include <iterator>
#include<string>
#include<cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

enum Value { FALSE, TRUE };
enum Operator { AND, OR, XOR };
// main structures (variables)
struct Card {
    Value value;
    Operator operation;
    int num_value = 2;
    int num_operation = 3;
};

struct Deck {
    vector<Card>cards;
    int deck_size = 48;
};
// Booleo doc functions

void initialize(Deck& deck); // initialize the deck

void shuffle(Deck& deck); // shuffle the deck

void deal_cards(Deck& deck, vector<Card>& player_one, vector<Card>& player_two, int num_cards); // deal the deck to two vectors by 4

void print_card(const Card& card); // print a card
 
void print_hand(const vector<Card>& hand); // print the cards of player

void print_win(bool* winner); // print the winner

void print_map(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up,
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down, Card* finish_up, Card* finish_down); // print the map

void move_by_line(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up, // do the selected move
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down,
    Card* finish_up, Card* finish_down, Deck& deck, vector<Card>& player_one, vector<Card>& player_two, bool* half,
    bool* error, int* line, int* hand_card, int* line_position, string* choose);

void start_shuffle(bool* start_up, bool* start_down); // shuffle the start cards of the game

void select_move(int* line, int* hand_card, int* line_position); // select where the player wants to move the card

void check_empty(vector<Card>& player, Deck& deck, Deck& new_deck, bool* error); // check if the deck is empty

void back_or_play(vector<Card>& player, Deck& deck, Deck& new_deck, int* switch_cards, string* choose, bool* half, bool* error); // asks the player if he wants to discard a card or
                                                                                                                                 // to move it

void print_start_cards(bool* start_cards, bool* start_down); // print the starting cards of the game

void print_line_up(Card* line_up, int size, int space); // print cards on the next UP line
void print_line_down(Card* line_down, int size, int space); // print cards on the next DOWN line

void move_up_first(bool* half, int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one, bool* error); // move the selected card in the first line UP
void move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two, bool* error); // move the selected card in the first line DOWN

void move_up(bool* half, int hand_card, int line_position, Card* up, Card* line_up, vector<Card>& player_one, bool* error); // move the selected card in the line UP
void move_down(bool* half, int hand_card, int line_position, Card* down, Card* line_down, vector<Card>& player_two, bool* error); // move the selected card in the line DOWN

bool finish(Card* finish_up, Card* finish_down, bool* winner); // checks if the game is finished

void AI_select_move(Card* first_line_down, Card* second_line_down, Card* third_line_down, Card* fourth_line_down, int* line, int* hand_card, int* line_position); // select the move of AI

void AI_move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two, bool* error); // move the selected of AI card in the first line DOWN

void AI_move_down(bool* half, int hand_card, int line_position, Card* down, Card* line_down, vector<Card>& player_two, bool* error); // move the selected of AI card in the line DOWN

void AI_move_by_line(bool* start_up, bool* start_down, Card* first_line_up, Card* first_line_down, Card* second_line_up, // do the selected move of AI
    Card* second_line_down, Card* third_line_up, Card* third_line_down, Card* fourth_line_up, Card* fourth_line_down,
    Card* finish_up, Card* finish_down, Deck& deck, vector<Card>& player_one, vector<Card>& player_two, bool* half,
    bool* error, int* line, int* hand_card, int* line_position, string* choose);

void AI_back_or_play(vector<Card>& player, Deck& deck, Deck& new_deck, int* switch_cards, string* choose, bool* half, bool* error); // AI discards a card or play

void choose_gamemode(int* gamemode, bool* AI, bool* GM_check); // asks the player which gamemode he wants to play