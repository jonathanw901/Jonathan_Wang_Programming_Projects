// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <iostream>
#include <bits/stdc++.h>
#include "standardDeck.h"

// Constructor
StandardDeck::StandardDeck()
{
    deck_ = new Card[52]; // container
    numCards_ = 0;    
}

// Destructor
StandardDeck::~StandardDeck()
{
    delete [] deck_;
}

void StandardDeck::printDeck()
{
    for (int i = 0; i < numCards_; i++)
    {
        std::cout << deck_[i].print() << "\n";
    }
    //std::cout << numCards_ << "\n";
}

bool StandardDeck::isEmpty()
{
    if (numCards_ <= 0)
    {
        //std::cout << "Is the deck empty? 1" << "\n";
        return true;
    } else {
        //std::cout << "Is the deck empty? 0" << "\n";
        return false;
    }
}

int StandardDeck::getNumCards()
{
    int i = numCards_;
    //std::cout << "Number of Cards: " + std::to_string(i) << "\n";
    return i;
}

void StandardDeck::displayCard(int i)
{
    std::cout << std::to_string(i) + "th Card: " + deck_[i-1].print() << "\n";
}

void StandardDeck::initializeDeck()
{
    for (int j = 1; j < 5; j++)
    {
        for (int k = 1; k < 14; k++)
        {
	        deck_[numCards_] = Card(j,k);
            numCards_ = numCards_ + 1;
        }
    }
}

void StandardDeck::initializeEmptyDeck()
{
    numCards_ = 0;
}

bool StandardDeck::addCard(Card c)
{
    if (numCards_ < 52){
        deck_[numCards_] = c;
        numCards_ = numCards_ + 1;
        //std::cout << "Can add card" << "\n";
        return true;
    } else {
        //std::cout << "Cannot add card" << "\n";
        return false;
    }
}

bool StandardDeck::mergeDecks(Deck& d, bool b)
{
    if (numCards_ < 52){
        int i;
        if (d.numCards_ < 52-numCards_)
        {
            i = d.numCards_;
        } else {
            i = 52-numCards_;
        }
        for (int j = 0; j < i; j++)
        {
            Card c = d.dealCard();
            addCard(c);
        }
        if (b == true)
        {
            shuffle();
        } else {

        }
        //std::cout << "Can add deck" << "\n";
        return true;
    } else {
        if (b == true)
        {
            shuffle();
        } else {

        }
        //std::cout << "Cannot add deck" << "\n";
        return false;
    }
}

void StandardDeck::shuffle()
{
    // Produces non-deterministic random numbers.
    std::random_device randomDevice;
    // A Mersenne Twister efficient pseudo-random generator.
    std::mt19937 randNum(randomDevice());
    // C++11 Shuffle Method
    std::shuffle(deck_, deck_+numCards_, randNum);
}

Card StandardDeck::dealCard()
{
    //std::cout << "Topmost Card: " + deck_[numCards_-1].print() << "\n";
    Card c =  deck_[numCards_-1];
    //deck_ = Card[numCards_-1];
    numCards_ = numCards_-1;
    return c;
}
