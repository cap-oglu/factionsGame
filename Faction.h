//
// Ahmet Ramazan Çapoğlu 150190080
//

#ifndef ASSIGNMENT3_FACTION_H
#define ASSIGNMENT3_FACTION_H

#include <string>
#include <iostream>
using namespace std;

class Faction{
private:
    string name;
    Faction * firstEnemy;
    Faction * secondEnemy;
    int number_of_units;
    int attack_point;
    int health_point;
    int unit_regeneration_number;
    int totalHealth;
    bool aliveFlag;
public:
    Faction(const string &, int, int, int, int);
    /*virtual ~Faction(){
        delete firstEnemy;
        delete secondEnemy;
    }*/
    void AssignEnemies(Faction *, Faction *);
    virtual void PerformAttack() = 0; //pure virtual function, void?
    virtual void ReceiveAttack(Faction &, int, int) = 0;
    virtual int PurchaseWeapons(int) = 0;
    virtual int PurchaseArmors(int) = 0;
    virtual void Print();
    void EndTurn();

    bool IsAlive() const {return this->aliveFlag; } // same function with getAliveFlag()

    //getter and setters

    int getTotalHealth() const{ return this->totalHealth;}
    void setTotalHealth(int  totalHealth) { this->totalHealth = totalHealth;}
    bool getAliveFlag() const {return this->aliveFlag;}
    void setAliveFlag(bool  aliveFlag) { this->aliveFlag = aliveFlag;}
    bool getFirstEnemy_flag() const{return this->firstEnemy->aliveFlag;}
    Faction * getFirstEnemy() const{return this->firstEnemy;}
    Faction * getSecondEnemy() const{return this->secondEnemy;}
    bool getSecondEnemy_flag() const{return this->secondEnemy->aliveFlag;}
    int getAttackPoint() const{ return this->attack_point;}
    void setAttackPoint(int attackPoint){this->attack_point = attackPoint;}
    int getHealthPoint() const{ return this->health_point;}
    void setHealthPoint(int healthPoint){this->health_point = healthPoint;}
    int getNumberOfUnits() const{ return this->number_of_units;}
    void setNumberOfUnits(int  numberOfUnits) { this->number_of_units = numberOfUnits;}
    string getName() const{ return this->name;}





};





















#endif //ASSIGNMENT3_FACTION_H


