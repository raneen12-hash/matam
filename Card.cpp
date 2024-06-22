#include <stdbool.h>
#include <string>
#include <iostream>
#include "utilities.h"
//#include "Player.h"

using namespace std;

#include "Card.h"
#ifndef CARD_H_
#define CARD_H_

// 4.2.1 constructor

Card::Card(CardType type, const CardStats& stats)
    {

        m_effect = type;
        m_stats.buff = stats.buff;
        m_stats.heal = stats.heal;
        m_stats.force = stats.force;
        m_stats.cost = stats.cost;
        m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
        m_stats.loot = stats.loot;
    //cout << "CARDConstructorCARDConstructor\n" << endl;
    }



// 4.2.2 apply encounter

void Card::applyEncounter(Player& player) const{
    if(m_effect == CardType :: Battle){
        if(player.getAttackStrength()>=m_stats.force)
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
            }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);
            }
        }
    else   if(m_effect == CardType :: Buff){
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
else if(m_effect == CardType :: Heal)
   {
       if(player.pay(m_stats.cost))
       {
           player.heal(m_stats.heal);
       }
   }
 else if(m_effect == CardType :: Treasure)
   {
     player.addCoins(m_stats.loot);
   }
}

// 4.2.3 print card

void Card::printInfo() const{

    if(this->m_effect == CardType::Battle){
        printBattleCardInfo(m_stats);
    }
    else if(this->m_effect == CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    else if(this->m_effect == CardType::Heal){
        printHealCardInfo(m_stats);
    }
    else{
        printTreasureCardInfo(m_stats);
    }
}

#endif







