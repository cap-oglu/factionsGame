//
// Ahmet Ramazan Çapoğlu 150190080
//

#include "Faction.h"

Faction::Faction(const string & name, int number_of_units, int attack_point
                 , int health_point, int unit_regeneration_number) : name(name),
                 number_of_units(number_of_units), attack_point(attack_point),
                 health_point(health_point), unit_regeneration_number(unit_regeneration_number)
{
    this->totalHealth = number_of_units * health_point;
    this->aliveFlag = true;
}

void Faction::AssignEnemies(Faction * firstEnemy, Faction * secondEnemy) {
    //assign enemies of a faction, as this is abstract class it does not
    //have an instance.
    this->firstEnemy = firstEnemy;
    this->secondEnemy = secondEnemy;
}

void Faction::Print() {
    //prints faction's information
   cout << "Faction Name:         " << this->name << endl;

   if(this->aliveFlag)
     cout << "Status:               " << "Alive" << endl;
   else  cout << "Status:               " << "Defeated" << endl;

    cout << "Number of Units:      " << this->number_of_units << endl;
    cout << "Attack Point:         " << this->attack_point << endl;
    cout << "Health Point:         " << this->health_point << endl;
    cout << "Unit Regen Number:    " << this->unit_regeneration_number << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}

void Faction::EndTurn() {
    //this function end turns while controlling if faction is alive
    //or not and regenerate units and updates total health
    if(this->number_of_units < 0) this->number_of_units = 0;
    if(this->number_of_units == 0) {
        this->aliveFlag = false;
        this->totalHealth = number_of_units * health_point;
    }
    else {
        this->number_of_units += this->unit_regeneration_number;
        this->totalHealth = number_of_units * health_point;
    }
}
