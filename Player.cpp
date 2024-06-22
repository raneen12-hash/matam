//#include <iostream>
#include <stdbool.h>
//#include <string>
#include "utilities.h"
#include <cstring>
#include "Player.h"
#ifndef PLAYER_H_
#define PLAYER_H_

//using namespace std;

//constructor

Player::Player(const char *name, int maxHP, int force) {
    /* std::string s = name;
    this->m_name = new char[length+1];
    strcpy(this->m_name,name); */
 //   std::string s = name;
    this->m_name = new char[strlen(name)+1];
    strcpy(this->m_name,name);
    //std::copy(s.begin(), s.end(), this->m_name);
    //cout << "PlayerConstructorPlayerConstructor\n"<<endl;

    
    this ->m_level = 1;
    this ->m_coins = 0;
    if(maxHP<=0)
    {
        this -> m_maxHP = DEFAULTmaxHP;
        this -> m_HP = DEFAULTmaxHP;
    }
    else
    {
        this -> m_maxHP = maxHP;
        this -> m_HP = maxHP;
    }
    if(force>0)
    {
        this -> m_force =force;
    }
    else
    {
        m_force =DEFAULTFORCE ;
    }
}

// copy constructor

 Player::Player(const Player& other) :
    m_level(other.m_level),
    m_force(other.m_force),
    m_maxHP(other.m_maxHP),
    m_HP(other.m_HP),
    m_coins(other.m_coins)
    {
        int length = strlen(other.m_name);
        m_name = new char[length+1];
        strcpy(this->m_name,other.m_name);

    }

//destructor

Player::~Player(){
   delete[] m_name;
}

//assignment constructor

Player &Player::operator=(const Player& other){
    if(this == &other){
        return *this;
    }
    delete[] m_name;
    int length = strlen(other.m_name);
    m_name = new char[length+1];
    strcpy(m_name,other.m_name);
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP = other.m_HP;
    m_coins = other.m_coins;
   
    return *this;
}

// 4.1.3 print player info

void Player :: printInfo() const{
    printPlayerInfo(m_name,m_level,m_force,m_HP,m_coins);
}

// 4.1.4 level up

void Player::levelUp(){
    m_level = (m_level == 10) ? m_level : m_level+1; 
}

// 4.1.5 get level 

int Player :: getLevel() const{
    return m_level;
}

// 4.1.6 buff

void Player::buff(int buffForce){
 if(buffForce>=0) {
     m_force += buffForce;
 }
}

// 4.1.7 heal

void Player :: heal(int healHP){
   if(healHP > 0)
   {
       if(m_HP+healHP> m_maxHP)
       {
           m_HP=m_maxHP;
       }
       else
       {
           m_HP= m_HP+healHP;
       }
   }
}

// 4.1.8 damage

void Player::damage(int damageHP){
  if(damageHP>0){
    m_HP -= damageHP;
    if(m_HP < 0){
        m_HP = 0;
    }
  }
}

// 4.1.9 check hp (knocked out)

bool Player :: isKnockedOut () const {
    if(m_HP == 0)
    {
       return true ;
    }
    return false;
}

// 4.1.10

void Player::addCoins(int getcoins){
    if(getcoins >=0 ){
        m_coins += getcoins;
    }
}

// 4.1.11 

bool Player::pay (int paycoins){
    if(paycoins>=0)
    {
        if(paycoins <= m_coins)
        {
            m_coins -= paycoins;
            return true;
        }}
        else
        {
            return true ;
        }

    return false;
}

// 4.1.12

int Player::getAttackStrength() const{
    //int level = Player::getLevel();
    //int force = Player::force;
    return (m_force + m_level);
}


#endif