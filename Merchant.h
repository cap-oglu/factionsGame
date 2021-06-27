//
// Ahmet Ramazan Çapoğlu 150190080
//

#ifndef ASSIGNMENT3_MERCHANT_H
#define ASSIGNMENT3_MERCHANT_H
#include <string>
#include <iostream>
#include "Faction.h"


using namespace std;
class Merchant{
private:
    Faction * firstFaction;
    Faction * secondFaction;
    Faction * thirdFaction;
    const  int starting_weapon_point;
    const  int starting_armor_point;
    int revenue;
    int weaponPoint;
    int armorPoint;
public:
    Merchant(int, int);

    void AssignFactions(Faction *,Faction *, Faction *);
    bool SellWeapons( const string &, int);
    bool SellArmors(const string &, int);
    void EndTurn();

    //getter and setters
    int GetWeaponPoints() const{return this->weaponPoint;}
    int GetRevenue() const{return this->revenue;}
    int GetArmorPoints() const{return this->armorPoint;}
};

#endif //ASSIGNMENT3_MERCHANT_H


