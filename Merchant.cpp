//
// Ahmet Ramazan Çapoğlu 150190080
//

#include "Merchant.h"

Merchant::Merchant(int weaponPoint, int armorPoint) : starting_armor_point(10),
                               starting_weapon_point(10),
                               weaponPoint(weaponPoint),
                               armorPoint(armorPoint)
{
    this->revenue = 0;
}

void Merchant::AssignFactions(Faction * firstFaction, Faction * secondFaction, Faction * thirdFaction) {
    //method for assigning factions to merchant
    this->firstFaction = firstFaction;
    this->secondFaction = secondFaction;
    this->thirdFaction = thirdFaction;
}

bool Merchant::SellWeapons(const string & name, int weaponPoints) {
    //method to sell weapons, this method have some controls
    if(this->firstFaction->getName() == name){
        if(!this->firstFaction->getAliveFlag()){
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        if( weaponPoints > this->weaponPoint){
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }

        this->revenue += this->firstFaction->PurchaseWeapons(weaponPoints);
        this->weaponPoint = this->weaponPoint - weaponPoints;
        cout << "Weapons sold!" << endl;

        return true;
    }
    else if(this->secondFaction->getName() == name){
        if(!this->secondFaction->getAliveFlag()){
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        if( weaponPoints > this->weaponPoint){
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }

        this->revenue += this->secondFaction->PurchaseWeapons(weaponPoints);
        this->weaponPoint = this->weaponPoint - weaponPoints;
        cout << "Weapons sold!" << endl;
        return true;
    }
    else if(this->thirdFaction->getName() == name){
        if(!this->thirdFaction->getAliveFlag()){
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        if( weaponPoints > this->weaponPoint){
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }

        this->revenue += this->thirdFaction->PurchaseWeapons(weaponPoints);
        this->weaponPoint = this->weaponPoint - weaponPoints;
        cout << "Weapons sold!" << endl;
        return true;
    }

}

bool Merchant::SellArmors(const string & name, int armorPoints) {
    //method to sell armors, this method have some controls
    if(this->firstFaction->getName() == name){
        if(!this->firstFaction->getAliveFlag()){
            cout << "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        if( armorPoints > this->armorPoint){
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }

        this->revenue += this->firstFaction->PurchaseArmors(armorPoints);
        this->armorPoint = this->armorPoint - armorPoints;
        cout << "Armors sold!" << endl;

        return true;
    }
    else if(this->secondFaction->getName() == name){
        if(!this->secondFaction->getAliveFlag()){
            cout << "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        if( armorPoints > this->armorPoint){
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }

        this->revenue += this->secondFaction->PurchaseArmors(armorPoints);
        this->armorPoint = this->armorPoint - armorPoints;
        cout << "Armors sold!" << endl;
        return true;
    }
    else if(this->thirdFaction->getName() == name){
        if(!this->thirdFaction->getAliveFlag()){
            cout << "The faction you want to sell armors is dead!" << endl;
            return false;
        }
        if( armorPoints > this->armorPoint){
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }

        this->revenue += this->thirdFaction->PurchaseArmors(armorPoints);
        this->armorPoint = this->armorPoint - armorPoints;
        cout << "Armors sold!" << endl;
        return true;
    }

}

void Merchant::EndTurn() {
    //ends turns while updating armor and weapon point by constants.
    this->armorPoint = this->starting_armor_point;
    this->weaponPoint = this->starting_weapon_point;
}


