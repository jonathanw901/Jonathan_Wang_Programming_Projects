// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#ifndef NONSTANDARD_DECK_H
#define NONSTANDARD_DECK_H

#include "card.h"
#include "deck.h"

/**
 * @class NonStandardDeck
 *
 * The NonStandardDeck class represents a deck of any size of cards.
 * 
 */
class NonStandardDeck: public Deck
{
	public:
		/// Default constructor.
		NonStandardDeck();
		
		/// Default destructor.
		~NonStandardDeck();

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		bool isEmpty();	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		void printDeck();	

		void initializeDeck();

		void initializeEmptyDeck();

		bool addCard(Card c);

		bool mergeDecks(Deck &, bool);

		void shuffle();

		Card dealCard();
};

#endif