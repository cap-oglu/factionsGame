//
// Ahmet Ramazan Çapoğlu 150190080
//

#ifndef ASSIGNMENT3_DWARVES_H
#define ASSIGNMENT3_DWARVES_H
#include <string>
#include <iostream>
#include "Faction.h"

using namespace std;
class Dwarves: public Faction{
public:
    //using Faction::Faction;
    Dwarves(const string &, int, int, int, int);
    void PerformAttack();
    void ReceiveAttack( Faction &, int, int); //faction * mı olcak
    int PurchaseWeapons( int );
    int PurchaseArmors( int );
    void Print();

};
#endif //ASSIGNMENT3_DWARVES_H
