#pragma once

#include <iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

enum Value { FALSE, TRUE };
enum Operator { AND, OR, XOR };
//main strctures (variables)
struct Card {
    Value value;
    Operator operation;
    char name;
    int num_value = 2;
    int num_operation = 3;
};

struct Deck {
    vector<Card>cards;
    int deck_size = 48;
};
//Booleo doc functions
void initialize(Deck& deck);

void shuffle(Deck& deck);

void deal_cards(Deck& deck, vector<Card>& player_one, vector<Card>& player_two, int num_cards);

void print_card(const Card& card);

void print_deck(const Deck& deck);

void print_hand(const vector<Card>& hand);

void start_shuffle(bool* start_up, bool* start_down);

void select_move(vector<Card>& player, Deck& deck, int* line, int* hand_card, int* line_position, bool add_card, bool* half);

void print_start_cards(bool* start_cards, bool* start_down);

void print_first_line_up(Card* first_line_up);
void print_first_line_down(Card* first_line_down);

void print_second_line_up(Card* second_line_up);
void print_second_line_down(Card* second_line_down);

void print_third_line_up(Card* third_line_up);
void print_third_line_down(Card* third_line_down);

void move_up_first(bool* half, int hand_card, int line_position, bool* start_up, Card* first_line_up, vector<Card>& player_one);
void move_down_first(bool* half, int hand_card, int line_position, bool* start_down, Card* first_line_down, vector<Card>& player_two);

void move_up_second(bool* half, int hand_card, int line_position, Card* first_line_up, Card* second_line_up, vector<Card>& player_one);
void move_down_second(bool* half, int hand_card, int line_position, Card* first_line_down, Card* second_line_down, vector<Card>& player_two);

void move_up_third(bool* half, int hand_card, int line_position, Card* second_line_up, Card* third_line_up, vector<Card>& player_one);
void move_down_third(bool* half, int hand_card, int line_position, Card* second_line_down, Card* third_line_down, vector<Card>& player_two);