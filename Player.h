//
// Created by Raneen Haj Yahya on 22/02/2024.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


//#include <iostream>
#include <stdbool.h>
#include <string>
//#include "utilities.h"
//using namespace std;

class Player {
private:
    char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    static const int DEFAULTmaxHP =100;
    static const int DEFAULTFORCE =5;
public:
/**
     * @brief Construct a new Player object
     * @param name - the name of the player
     * @param maxHP - the max hp of the player (default = 100)
     * @param force - the force of the player(default = 5)
 */
    Player(const char* name,int maxHP=DEFAULTmaxHP,int force=DEFAULTFORCE);

/**
     * @brief Copy constructor of the Player
     * @param player - the player that will be copied
 */
    Player(const Player& other);

/**
     * @brief assignment operator
     * @param other - the other is a player that will be equaled to another player
     * @return Player& - player that we want to make it equal to other
 */
    ~Player();

/**
     * @brief assignment operator
     * @param other - the other is a player that will be equedled to another player
     * @return Player& - player that we want to make it equal to other
 */
    Player &operator=(const Player& other);

/**
     * @brief  print the information about the player
 */
    void printInfo() const;

/**
     * @brief make the player's level up
 */
    void levelUp();

 /**
     * @brief Get the player's Level
     * @return int returns the level
 */
    int getLevel() const;

/**
     * @brief buff the players force by buffForce
     * @param buffForce - the amount of force that will be added to the player
 */
    void buff(int buffForce);

/**
     * @brief heal the player by additional hp
     * @param healdHP - the amount of hp that will be added to player
 */
    void heal(int healdHP);

/**
     * @brief damage player by damageHP
     * @param damageHP - the amount of damage that will be deduced from the player
 */
    void damage(int damageHP);
/**
    * @brief returns if player is knocked out
    * @return true - player is knocked out
    * @return false - player isn't knocked out
 */
    bool isKnockedOut() const;

/**
     * @brief adds coins to the player by getcoins
     * @param getcoins - the amount of gold that will be added to the player
*/
    void addCoins(int getcoins);

/**
     * @brief the player pay amount of money equals to paycoins
     * @param paycoins - the amount of gold that will be deduced from the player
     * @return true - if the player can afford the amount of gold
     * @return false - if the player can not afford the amount of gold
*/
    bool pay(int paycoins);

/**
     * @brief Get the Attack Strength of the player
     * @return int returns the Attack strength of the player
 */
    int getAttackStrength() const;


};

#endif /* Player_h */














