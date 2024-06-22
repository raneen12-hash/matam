#include <iostream>

/* #include "Player.h"
#include "Card.h"
#include "utilities.h" */

#include "Mtmchkin.h"
using namespace std;




// 4.3.1 constructor
Mtmchkin::Mtmchkin(const char *playerName, const Card *cardsArray, int numOfCards):
    m_player(playerName),
    m_cardsArray(new Card [numOfCards]()),
    m_numberOfCards(numOfCards),
    m_status(GameStatus::MidGame),
    m_cardIndex(0)   
    
    {
    for (int i = 0; i < m_numberOfCards; i++) {
        m_cardsArray[i] = cardsArray[i];
    }


}

// copy constructor

Mtmchkin::Mtmchkin(const Mtmchkin& other) :
     m_player(other.m_player),
     m_numberOfCards(other.m_numberOfCards),
     m_status(other.m_status),
     m_cardIndex(other.m_cardIndex)
{
 
    m_cardsArray = new Card[m_numberOfCards];
    for (int i = 0; i < m_numberOfCards; ++i) {
        m_cardsArray[i] = other.m_cardsArray[i]; 
    }
}

// destructor
Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}

// 4.3.2 play next card

void Mtmchkin::playNextCard(){
        if(m_status==GameStatus::MidGame) {

            m_cardsArray[m_cardIndex].printInfo();
            m_cardsArray[m_cardIndex].applyEncounter(m_player);
            m_player.printInfo();
            if(m_player.getLevel()==10)
            {
                m_status=  GameStatus::Win;
            }
            else if(m_player.isKnockedOut())
            {
                m_status=  GameStatus::Loss;
            }
            m_cardIndex = (m_cardIndex + 1) % m_numberOfCards;
        }
}

// 4.3.2 is game over

bool Mtmchkin::isOver() const
{
    return (m_status!=GameStatus::MidGame);
}

// 4.3.4 game status

GameStatus Mtmchkin::getGameStatus() const{

   return m_status;

}

// assignment operator 

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other)
{
    if (this==&other)
    {
        return *this;
    }
    delete[] m_cardsArray;
    m_cardsArray=new Card[other.m_numberOfCards];
    m_status=other.m_status;
    m_cardIndex=other.m_cardIndex;
    m_player=other.m_player;
    m_numberOfCards=other.m_numberOfCards;
    for(int i=0;i<other.m_numberOfCards; i++)
    {
        m_cardsArray[i]=other.m_cardsArray[i];
    }
    return *this;
}

