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