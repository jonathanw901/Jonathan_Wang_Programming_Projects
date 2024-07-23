// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang
#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "deck.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class StandardDeck: public Deck
{
	public:
		void initializeDeck();
};

#endif