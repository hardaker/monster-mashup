#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class Monster {
 protected:
   string name;
   int hp;
   bool dead;

 public:
   Monster(string name, int hp) {
       this->name = name;
       this->hp = hp;
       this->dead = false;
   }

   string get_name() { return name; };

   virtual int attacks() {
       // create a random damage amount
       int damage = rand() % 10;

       // print what happens
       std::cout << "The " << name << " attacks dealing "
                 << damage << " damage" << std::endl;
       return damage;
   }

   virtual void defends(int damage) {
       // print what happens
       std::cout << "You attack the " << name << " dealing " <<
           damage << " damage" << std::endl;

       // actually apply the damage
       this->hp -= damage;

       // oh no, did I die?
       if (this->hp <= 0) {
           std::cout << "   ARGGGGG...  it's dead!  You win!" << endl;
           dead = true;
       }
   }

   bool is_dead() {
       return dead;
   }
};

class Unicorn : public Monster {
 public:
   Unicorn() : Monster("Unicorn", 10) {
   }

   virtual int attacks() {
       int damage = rand() % 10;
       std::cout << "The " << get_name() << " attacks dealing "
                 << damage << " sparkly rainbow damage points" << std::endl;
       return damage;
   }

};

class Robot : public Monster {
 public:
   Robot() : Monster("Robot", 10) {
   }

   virtual void defends(int damage) {
       // print what happens
       std::cout << "You attack the " << name << "'s metal hulk dealing " <<
           damage << " damage" << std::endl;

       // actually apply the damage
       this->hp -= damage;

       // oh no, did I die?
       if (this->hp <= 0) {
           std::cout << "   ARGGGGG...  it's disfunctional!  You win!" << endl;
           dead = true;
       }
   }

};

main() {
    srand(time(NULL));

    Monster *m = new Robot();
    while (! m->is_dead()) {
        m->attacks();
        m->defends(5);
    }
}
