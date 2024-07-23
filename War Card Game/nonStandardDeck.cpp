// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include "nonStandardDeck.h"

// Constructor
NonStandardDeck::NonStandardDeck()
{
    std::ifstream inStream("deck.txt");
    int xCards;
    inStream >> xCards;
    //std::cout << "Constructor: " + std::to_string(xCards) << "\n";
    deck_ = new Card[xCards]; // container
    numCards_ = 0;    
}

// Destructor
NonStandardDeck::~NonStandardDeck()
{
    delete [] deck_;
}

void NonStandardDeck::printDeck()
{
    for (int i = 0; i < numCards_; i++)
    {
        std::cout << deck_[i].print() << "\n";
    }
    //std::cout << numCards_ << "\n";
}

bool NonStandardDeck::isEmpty()
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

int NonStandardDeck::getNumCards()
{
    int i = numCards_;
    //std::cout << "Number of Cards: " + std::to_string(i) << "\n";
    return i;
}

void NonStandardDeck::displayCard(int i)
{
    std::cout << std::to_string(i) + "th Card: " + deck_[i-1].print() << "\n";
}

void NonStandardDeck::initializeDeck()
{
    std::ifstream inStream("deck.txt");
    int xCards;
    inStream >> xCards;
    //std::cout << "Initialize Deck: " + std::to_string(xCards) << "\n";

    for (int i = 0; i < xCards; i++)
    {
        int j;
        int k;
        inStream >> j >> k;
	    deck_[numCards_] = Card(j,k);
        numCards_ = numCards_ + 1;
    }
}

void NonStandardDeck::initializeEmptyDeck()
{
    numCards_ = 0;
}

bool NonStandardDeck::addCard(Card c)
{
    std::ifstream inStream("deck.txt");
    int xCards;
    inStream >> xCards;
    //std::cout << "addCard: " + std::to_string(xCards) << "\n";
    if (numCards_ < xCards){
        deck_[numCards_] = c;
        numCards_ = numCards_ + 1;
        //std::cout << "Can add card" << "\n";
        return true;
    } else {
        //std::cout << "Cannot add card" << "\n";
        return false;
    }
}

bool NonStandardDeck::mergeDecks(Deck& d, bool b)
{
    std::ifstream inStream("deck.txt");
    int xCards;
    inStream >> xCards;
    //std::cout << "mergeDecks: " + std::to_string(xCards) << "\n";
    if (numCards_ < xCards){
        int i;
        if (d.numCards_ < xCards-numCards_)
        {
            i = d.numCards_;
        } else {
            i = xCards-numCards_;
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

void NonStandardDeck::shuffle()
{
    // Produces non-deterministic random numbers.
    std::random_device randomDevice;
    // A Mersenne Twister efficient pseudo-random generator.
    std::mt19937 randNum(randomDevice());
    // C++11 Shuffle Method
    std::shuffle(deck_, deck_+numCards_, randNum);
}

Card NonStandardDeck::dealCard()
{
    //std::cout << "Topmost Card: " + deck_[numCards_-1].print() << "\n";
    Card c =  deck_[numCards_-1];
    //deck_ = Card[numCards_-1];
    numCards_ = numCards_-1;
    return c;
}
