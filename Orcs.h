//
// Ahmet Ramazan Çapoğlu 150190080
//

#ifndef ASSIGNMENT3_ORCS_H
#define ASSIGNMENT3_ORCS_H
#include <string>
#include <iostream>
#include "Faction.h"

using namespace std;


class Orcs : public Faction{
public:
   // using Faction::Faction; //böyle bir constructor var mı acaba?
    Orcs(const string &, int, int, int, int);
    void PerformAttack();
    void ReceiveAttack( Faction &, int, int); //faction * mı olcak
    int PurchaseWeapons( int );
    int PurchaseArmors( int );
    void Print();
};

#endif //ASSIGNMENT3_ORCS_H
