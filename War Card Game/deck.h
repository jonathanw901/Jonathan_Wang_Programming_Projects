// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#ifndef DECK_H
#define DECK_H
#include "card.h"

#define DECK_SIZE 52

/**
 * @class Deck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 * 
 */
class Deck
{
	public:
		
		/// Default constructor.
		Deck();
		
		/// Default destructor.
		virtual ~Deck();
		

		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */ 
		virtual bool isEmpty() =0;	

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */ 
		virtual int getNumCards() =0;

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		virtual void displayCard(int i) =0;

		/**
	     * Prints the contents of the Deck. This method should call the 
		 * print() method on each Card.
	    */
		virtual void printDeck() =0;	

		virtual void initializeDeck() =0;

		virtual void initializeEmptyDeck() =0;

		virtual bool addCard(Card c) =0;

		virtual bool mergeDecks(Deck &, bool) =0;

		virtual void shuffle() =0;

		virtual Card dealCard() =0;
		
	public: 
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.

};

#endif