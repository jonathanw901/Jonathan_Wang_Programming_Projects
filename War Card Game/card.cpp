// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// Default Constructor
Card::Card()
{
    suitVal_ = 0;
    faceVal_ = 0;
}

// Non-default Constructor
Card::Card(int s, int f)
{
    suitVal_ = s;
    faceVal_ = f;
}

// Destructor
Card::~Card()
{
}

// Setters

void Card::setSuit(int s){
    suitVal_ = s;
}

void Card::setFace(int f){
    faceVal_ = f;
}

void Card::initialize(int s, int f){
    suitVal_ = s;
    faceVal_ = f;
}

// Accessor Methods or Getters

std::string Card::getSuit()
{
    return SUIT[suitVal_];
}

std::string Card::getFace()
{
    return FACE[faceVal_];
}

std::string Card::print()
{
    return (FACE[faceVal_] + " of " + SUIT[suitVal_]);
}

