// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang
#include <iostream>
#include <string>
#include "standardDeck.h"

void StandardDeck::initializeDeck()
{
    //deck_ = new Card [52]; //container
    //numCards_ = 0;
    //deck_ = new Card [DECK_SIZE];

    for (int j = 1; j < 5; j++)
    {
        for (int k = 1; k < 14; k++)
        {
	        deck_[numCards_] = Card(j,k);
            numCards_ = numCards_ + 1;
        }
    }
}