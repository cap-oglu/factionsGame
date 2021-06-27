//
// Ahmet Ramazan Çapoğlu 150190080
//

#include "Elves.h"

Elves::Elves(const string & name, int number_of_units, int attack_point
        , int health_point, int unit_regeneration_number) : Faction(name,
                                                                    number_of_units,
                                                                    attack_point,
                                                                    health_point,
                                                                    unit_regeneration_number)
{
    //this->setTotalHealth(number_of_units * health_point);
    //this->setAliveFlag(true); //it starts as true
}

void Elves::PerformAttack() {
    int attack_to_orcs_if_only = (this->getNumberOfUnits() * 6) / 10;
   // int attack_to_dwarves_if_only = (this->getNumberOfUnits() * 4) / 10;
   int attack_to_dwarves_if_only = this->getNumberOfUnits() - ((this->getNumberOfUnits() * 6) / 10);
    int attack_dwarves_point_inc = (this->getAttackPoint() * 15) / 10;
    if(this->getFirstEnemy_flag() && this->getSecondEnemy_flag()){
        if(this->getFirstEnemy()->getName() == "Orcs") {
            this->getFirstEnemy()->ReceiveAttack(*this, attack_to_orcs_if_only, attack_dwarves_point_inc);
            this->getSecondEnemy()->ReceiveAttack(*this, attack_to_dwarves_if_only, attack_dwarves_point_inc);
        }
        else if(this->getFirstEnemy()->getName() == "Dwarves"){
            this->getFirstEnemy()->ReceiveAttack(*this, attack_to_dwarves_if_only, attack_dwarves_point_inc);
            this->getSecondEnemy()->ReceiveAttack(*this, attack_to_orcs_if_only, attack_dwarves_point_inc);
        }
    }
    else if(this->getFirstEnemy_flag()){
        this->getFirstEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), attack_dwarves_point_inc);
    }
    else if(this->getSecondEnemy_flag()){
        this->getSecondEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), attack_dwarves_point_inc);
    }
   // else{cout << "NO ENEMY" << endl;}

}
void Elves::ReceiveAttack(  Faction & attacker, int attackers_unit_number, int attackers_attack_point) {
    //int attackers_attack_point;
    int total_damage_received;

    if( attacker.getName() == "Orcs"){
        attackers_attack_point =  (5 * attacker.getAttackPoint()) / 4;
        total_damage_received =  attackers_attack_point * attackers_unit_number;
        this->setNumberOfUnits(this->getNumberOfUnits() - (total_damage_received / this->getHealthPoint()));

    }
    else if(attacker.getName() == "Dwarves"){
        attackers_attack_point = (3 * attacker.getAttackPoint() )/ 4;
        //total_damage_received =  attackers_attack_point * attacker.getNumberOfUnits();
        total_damage_received =  attackers_attack_point * attackers_unit_number;
        this->setNumberOfUnits(this->getNumberOfUnits() - (total_damage_received / this->getHealthPoint()));
    }
}

int Elves::PurchaseWeapons(int weaponsToBuy) {
    this->setAttackPoint(this->getAttackPoint() + (2 * weaponsToBuy));
    return 15 * weaponsToBuy;
}
int Elves::PurchaseArmors(int armorsToBuy) {
    this->setHealthPoint(this->getHealthPoint() + 4 * (armorsToBuy));
    return 5 * armorsToBuy;
}

void Elves::Print() {
    cout << "You cannot reach our elegance." << endl;
    Faction::Print(); // böyle yazınca çalışıyo mu acaba direkt olarak ?
}
