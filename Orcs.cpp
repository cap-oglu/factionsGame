//
// Ahmet Ramazan Çapoğlu 150190080
//

#include "Orcs.h"

Orcs::Orcs(const string & name, int number_of_units, int attack_point
        , int health_point, int unit_regeneration_number) : Faction(name,
                                                                    number_of_units,
                                                                    attack_point,
                                                                    health_point,
                                                                    unit_regeneration_number)
{
            //this->setTotalHealth(number_of_units * health_point);
            //this->setAliveFlag(true); //it starts as true
}



void Orcs::PerformAttack() {
    //if both enemies alive divide units to attack elves and dwarves.
    int attack_to_elves_if_only = (this->getNumberOfUnits() * 7) / 10; //if both enemies alive divide units to attack elves
    //int attack_to_dwarves_if_only = (this->getNumberOfUnits() * 3) / 10;
    int attack_to_dwarves_if_only = this->getNumberOfUnits() - ((this->getNumberOfUnits() * 7) / 10);

    //control of alive status of enemies
    if(this->getFirstEnemy_flag() && this->getSecondEnemy_flag()){
        if(this->getFirstEnemy()->getName() == "Elves") {
            this->getFirstEnemy()->ReceiveAttack(*this, attack_to_elves_if_only, this->getAttackPoint());
            this->getSecondEnemy()->ReceiveAttack(*this, attack_to_dwarves_if_only, this->getAttackPoint());
        }
        else if(this->getFirstEnemy()->getName() == "Dwarves"){
            this->getFirstEnemy()->ReceiveAttack(*this, attack_to_dwarves_if_only, this->getAttackPoint());
            this->getSecondEnemy()->ReceiveAttack(*this, attack_to_elves_if_only, this->getAttackPoint());
        }
    }
    else if(this->getFirstEnemy_flag()){
        this->getFirstEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), this->getAttackPoint());
    }
    else if(this->getSecondEnemy_flag()){
        this->getSecondEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), this->getAttackPoint());
    }
    //else{cout << "NO ENEMY" << endl;}

}

void Orcs::ReceiveAttack(  Faction & attacker, int attackers_unit_number, int attackers_attack_point) {
    //int attackers_attack_point;
    int total_damage_received;

    if( attacker.getName() == "Elves"){
        //if attackers are elves reduce attack point of them by %25
       attackers_attack_point =  (3 * attacker.getAttackPoint()) / 4;
       total_damage_received =  attackers_attack_point * attackers_unit_number;
       this->setNumberOfUnits(this->getNumberOfUnits() - (total_damage_received / this->getHealthPoint()));

    }
    else if(attacker.getName() == "Dwarves"){
        //if attackers are dwarves reduce attack point of them by %20
        attackers_attack_point = (4 * attacker.getAttackPoint() )/ 5;
        total_damage_received =  attackers_attack_point * attackers_unit_number;
        this->setNumberOfUnits(this->getNumberOfUnits() - (total_damage_received / this->getHealthPoint()));
    }
}

int Orcs::PurchaseWeapons(int weaponsToBuy) {
    //this method buys weapons and set attack point and returns total amount given for buying them
    this->setAttackPoint(this->getAttackPoint() + (2 * weaponsToBuy));
    return 20 * weaponsToBuy;
}
int Orcs::PurchaseArmors(int armorsToBuy) {
    //this method buys armors and set health point and returns total amount given for buying them
    this->setHealthPoint(this->getHealthPoint() + 3 * (armorsToBuy));
    return armorsToBuy;
}

void Orcs::Print() {
    cout << "Stop running, you'll only die tired!" << endl;
    Faction::Print(); // böyle yazınca çalışıyo mu acaba direkt olarak ?
}