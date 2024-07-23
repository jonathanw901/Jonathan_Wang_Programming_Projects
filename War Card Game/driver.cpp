// Driver Program
//
// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// Jonathan Wang

#include <iostream>
#include <string>

#include "standardDeck.h"
#include "nonStandardDeck.h"

int main()
{
    // decks for standardDeck
    StandardDeck deckToUse;
    StandardDeck p1Deck;
    StandardDeck p2Deck;
    StandardDeck pileDeck;
    
    // declare placeholder variables
    int p1Score = 0;
    int p1Wins = 0;
    double p1AvgScore = 0;
    int p2Score = 0;
    int p2Wins = 0;
    double p2AvgScore = 0;
    bool p1Grabs = true;
    
    // 50 rounds
    for (int i = 0; i < 50; i++)
    {
        p1Grabs = true;
        // initiate decks
        p1Deck.initializeEmptyDeck();
        p2Deck.initializeEmptyDeck();
        pileDeck.initializeEmptyDeck();
        deckToUse.initializeDeck();
        deckToUse.shuffle();
        // deal cards
        int halfCards;
        if (deckToUse.getNumCards() % 2 == 0)
        {
            halfCards = deckToUse.getNumCards()/2;
        } else {
            halfCards = (deckToUse.getNumCards()+1)/2;
        }
        int otherHalfCards = deckToUse.getNumCards() - halfCards;
        for (int j = 0; j < halfCards; j++)
        {
            Card c = deckToUse.dealCard();
            p1Deck.addCard(c);
        }
        for (int j = 0; j < otherHalfCards; j++)
        {
            Card c = deckToUse.dealCard();
            p2Deck.addCard(c);
        }

        // play until one player has no cards
        while (p1Deck.getNumCards() > 0 && p2Deck.getNumCards() > 0)
        {
            // player 1 puts a card down
            while (p1Grabs == true && p1Deck.getNumCards() > 0 && p2Deck.getNumCards() > 0)
            {
                if (p1Deck.getNumCards() > 0 && p2Deck.getNumCards() > 0){
                    Card toCheck1;
                    Card c1 = p1Deck.dealCard();
                    if (pileDeck.getNumCards() > 0)
                    {
                        toCheck1 = pileDeck.dealCard();
                        pileDeck.addCard(toCheck1);
                    }
                    pileDeck.addCard(c1);
                    // decide if player needs to grab cards
                    if (pileDeck.getNumCards() > 1)
                    {
                        if (c1.getFace() == toCheck1.getFace())
                        {
                            p1Deck.mergeDecks(pileDeck, true);
                            p1Grabs = true;
                        } else {
                            p1Grabs = false;
                        }
                    } else {
                        p1Grabs = false;
                    }
                }   
            }
            
            // player 2 puts a card down
            while (p1Grabs == false && p1Deck.getNumCards() > 0 && p2Deck.getNumCards() > 0)
            {
                if (p1Deck.getNumCards() > 0 && p2Deck.getNumCards() > 0){
                    Card toCheck2;
                    Card c2 = p2Deck.dealCard();
                    if (pileDeck.getNumCards() > 0)
                    {
                        toCheck2 = pileDeck.dealCard();
                        pileDeck.addCard(toCheck2);
                    }
                    pileDeck.addCard(c2);
                    // decide if player needs to grab cards
                    if (pileDeck.getNumCards() > 1)
                    {
                        if (c2.getFace() == toCheck2.getFace())
                        {
                            p2Deck.mergeDecks(pileDeck, true);
                            p1Grabs = false;
                        } else {
                            p1Grabs = true;
                        }
                    } else {
                        p1Grabs = true;
                    }
                }   
            }
        }

        // player who has no cards loses and other player wins and gains score
        if (p1Deck.getNumCards() == 0){
            p2Score = p2Score + p2Deck.getNumCards();
            p2Wins = p2Wins + 1;
        } 
        if (p2Deck.getNumCards() == 0){
            p1Score = p1Score + p1Deck.getNumCards();
            p1Wins = p1Wins + 1; 
        }
    }

    // calculate average score
    p1AvgScore = double(p1Score)/50;
    p2AvgScore = double(p2Score)/50;

    // statements
    std::cout << "StandardDeck results" << "\n";
    if (p1Wins > p2Wins)
    {
        std::cout << "Player 1 was the champion with " + std::to_string(p1Wins) + " victories versus Player 2." << "\n";
    } else if (p2Wins > p1Wins) {
        std::cout << "Player 2 was the champion with " + std::to_string(p2Wins) + " victories versus Player 1." << "\n";
    } else {
        std::cout << "Both players tied with " + std::to_string(p1Wins) + " victories." << "\n";
    }
    std::cout << "Player 1 Average Score: " + std::to_string(p1AvgScore)<< "\n";
    std::cout << "Player 2 Average Score: " + std::to_string(p2AvgScore)<< "\n";

    // decks for NonStandardDeck
    NonStandardDeck dToUse;
    NonStandardDeck p1D;
    NonStandardDeck p2D;
    NonStandardDeck pileD;
    
    // placeholder variables
    p1Score = 0;
    p1Wins = 0;
    p1AvgScore = 0;
    p2Score = 0;
    p2Wins = 0;
    p2AvgScore = 0;
    p1Grabs = true;
    
    // 50 rounds
    for (int i = 0; i < 50; i++)
    {
        p1Grabs = true;
        // initialize decks
        p1D.initializeEmptyDeck();
        p2D.initializeEmptyDeck();
        pileD.initializeEmptyDeck();
        dToUse.initializeDeck();
        dToUse.shuffle();
        // deal cards
        int halfCards;
        if (dToUse.getNumCards() % 2 == 0)
        {
            halfCards = dToUse.getNumCards()/2;
        } else {
            halfCards = (dToUse.getNumCards()+1)/2;
        }
        int otherHalfCards = dToUse.getNumCards() - halfCards;
        for (int j = 0; j < halfCards; j++)
        {
            Card c = dToUse.dealCard();
            p1D.addCard(c);
        }
        for (int j = 0; j < otherHalfCards; j++)
        {
            Card c = dToUse.dealCard();
            p2D.addCard(c);
        }

        // play until one player has no cards
        while (p1D.getNumCards() > 0 && p2D.getNumCards() > 0)
        {
            // player 1 puts down a card
            while (p1Grabs == true && p1D.getNumCards() > 0 && p2D.getNumCards() > 0)
            {
                if (p1D.getNumCards() > 0 && p2D.getNumCards() > 0){
                    Card toCheck1;
                    Card c1 = p1D.dealCard();
                    if(pileD.getNumCards() > 0)
                    {
                        toCheck1 = pileD.dealCard();
                        pileD.addCard(toCheck1);
                    }
                    pileD.addCard(c1);
                    // decide if player grabs cards
                    if(pileD.getNumCards() > 1)
                    {
                        if (c1.getFace() == toCheck1.getFace())
                        {
                            p1D.mergeDecks(pileD, true);
                            p1Grabs = true;
                        } else {
                            p1Grabs = false;
                        }
                    } else {
                        p1Grabs = false;
                    }
                }   
            }
            
            // player 2 puts down a card
            while (p1Grabs == false && p1D.getNumCards() > 0 && p2D.getNumCards() > 0)
            {
                if (p1D.getNumCards() > 0 && p2D.getNumCards() > 0){
                    Card toCheck2;
                    Card c2 = p2D.dealCard();
                    if(pileD.getNumCards() > 0)
                    {
                        toCheck2 = pileD.dealCard();
                        pileD.addCard(toCheck2);
                    }
                    pileD.addCard(c2);
                    // decide if player grabs a card
                    if(pileD.getNumCards() > 1)
                    {
                        if (c2.getFace() == toCheck2.getFace())
                        {
                            p2D.mergeDecks(pileD, true);
                            p1Grabs = false;
                        } else {
                            p1Grabs = true;
                        }
                    } else {
                        p1Grabs = true;
                    }
                }   
            }
        }

        // player with no cards loses and other player wins and gains score
        if (p1D.getNumCards() == 0){
            p2Score = p2Score + p2D.getNumCards();
            p2Wins = p2Wins + 1;
        } 
        if (p2D.getNumCards() == 0){
            p1Score = p1Score + p1D.getNumCards();
            p1Wins = p1Wins + 1; 
        }

    }

    // calculate average scores
    p1AvgScore = double(p1Score)/50;
    p2AvgScore = double(p2Score)/50;

    // statements
    std::cout << "NonStandardDeck results" << "\n";
    if (p1Wins > p2Wins)
    {
        std::cout << "Player 1 was the champion with " + std::to_string(p1Wins) + " victories versus Player 2." << "\n";
    } else if (p2Wins > p1Wins) {
        std::cout << "Player 2 was the champion with " + std::to_string(p2Wins) + " victories versus Player 1." << "\n";
    } else {
        std::cout << "Both players tied with " + std::to_string(p1Wins) + " victories." << "\n";
    }
    std::cout << "Player 1 Average Score: " + std::to_string(p1AvgScore)<< "\n";
    std::cout << "Player 2 Average Score: " + std::to_string(p2AvgScore)<< "\n";

	return 0;
}
