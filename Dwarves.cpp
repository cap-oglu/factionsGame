//
// Ahmet Ramazan Çapoğlu 150190080
//

#include "Dwarves.h"
Dwarves::Dwarves(const string & name, int number_of_units, int attack_point
        , int health_point, int unit_regeneration_number) : Faction(name,
                                                                    number_of_units,
                                                                    attack_point,
                                                                    health_point,
                                                                    unit_regeneration_number)
{
    //this->setTotalHealth(number_of_units * health_point);
    //this->setAliveFlag(true); //it starts as true
}

void Dwarves::PerformAttack() {
    //this works in a similar way with orcs's performAttack() except for
    //some small changes
    int attack_to_both = this->getNumberOfUnits() / 2 ;

    if(this->getFirstEnemy_flag() && this->getSecondEnemy_flag()){

            this->getFirstEnemy()->ReceiveAttack(*this, attack_to_both, this->getAttackPoint());
            this->getSecondEnemy()->ReceiveAttack(*this, attack_to_both, this->getAttackPoint());

    }
    else if(this->getFirstEnemy_flag()){
        this->getFirstEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), this->getAttackPoint());
    }
    else if(this->getSecondEnemy_flag()){
        this->getSecondEnemy()->ReceiveAttack(*this,this->getNumberOfUnits(), this->getAttackPoint());
    }
    //else{cout << "NO ENEMY" << endl;}

}

void Dwarves::ReceiveAttack(  Faction & attacker, int attackers_unit_number, int attackers_attack_point) {
    //this works in a similar way with orcs's receiveAttack() except for
    //some small changes
    //int attackers_attack_point;
    int total_damage_received;


        //attackers_attack_point = attacker.getAttackPoint();
        //attackers_attack_point = attacker.getAttackPoint();
        total_damage_received =  attackers_attack_point * attackers_unit_number;
        this->setNumberOfUnits(this->getNumberOfUnits() - (total_damage_received / this->getHealthPoint()));
}

int Dwarves::PurchaseWeapons(int weaponsToBuy) {
    this->setAttackPoint(this->getAttackPoint() +  weaponsToBuy);
    return 10 * weaponsToBuy;
}
int Dwarves::PurchaseArmors(int armorsToBuy) {
    this->setHealthPoint(this->getHealthPoint() + 2 * (armorsToBuy));
    return 3 * armorsToBuy;
}

void Dwarves::Print() {
    cout << "Taste the power of our axes!" << endl;
    Faction::Print(); // böyle yazınca çalışıyo mu acaba direkt olarak ?
}
