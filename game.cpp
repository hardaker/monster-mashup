#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Monster {
 protected:
   string name;
   int hp;
   int max_damage;
   bool dead;

 public:
   Monster(string name, int max_hp, int max_damage) {
       this->name = name;
       this->hp = (rand()%max_hp);
       this->max_damage = max_damage;
       this->dead = false;
   }

   string get_name() { return name; };
   int get_hp() { return hp; }
   bool is_dead() { return dead; }

   virtual bool take_damage(int damage) {
       // actually apply the damage
       this->hp -= damage;

       // oh no, did I die?
       if (this->hp <= 0) {
           dead = true;
       }
       return dead;
   }

   virtual void print_attack(Monster *defender, int damage) {
       std::cout << "The " << name << " attacks the "
                 << defender->get_name() << " dealing "
                 << damage << " damage" << std::endl;
   }

   virtual bool attacks(Monster *defender) {
       // create a random damage amount
       int damage = rand() % this->max_damage + 1;
       bool they_died = defender->take_damage(damage);

       // print what happens
       print_attack(defender, damage);
       if (they_died) {
	       std::cout << "   The " << name << " killed the "
	                 << defender->get_name() << "!!!" << std::endl;
       } else {
	       std::cout << "   The " << defender->get_name() << " has "
	                 << defender->get_hp() << " hit-points left"
	                 << std::endl;
	       
       }
       return they_died;
   }

};

class Robot : public Monster {
 public:
   Robot() : Monster("Robot", 100, 5) {
   }
};

class Unicorn : public Monster {
 public:
   Unicorn() : Monster("Unicorn", 30, 20) {
   }

   virtual void print_attack(Monster *defender, int damage) {
       std::cout << "The " << name << " attacks the "
                 << defender->get_name() << " with death-rainbows and deals "
                 << damage << " pink heart damage" << std::endl;
   }

};

Monster *create_random_monster() {
    int number_of_animal_types = 2;

    int random_number = rand() % number_of_animal_types;

    if (random_number == 0) {
        return new Unicorn();
    } else if (random_number == 1) {
        return new Robot();
    } else {
        std::cerr << "This should never happen!!!" << std::endl;
        exit(1);
    }
}

main() {
    srand(time(NULL));

    vector<Monster *> monsters;
    vector<Monster*>::iterator iter;

    monsters.push_back(create_random_monster());
    monsters.push_back(create_random_monster());

    // keep running the simulation until one wins (or they all die)
    while(monsters.size() > 1) {
        // loop through all monsters
        // have them each attack another random monster
        for(iter = monsters.begin(); iter != monsters.end(); iter++) {
            Monster *attacker = *iter;
            Monster *defender = monsters[rand() % monsters.size()];
            
            attacker->attacks(defender);
        }
        
        // find dead things
        bool restart = false;
        do {
            restart = false;

            for(iter = monsters.begin(); iter != monsters.end(); iter++) {
                Monster *monster = *iter;
            
                // If it's dead, remove it
                if (monster->is_dead()) {
                    std::cout << "The " << monster->get_name()
                              << " died!" << std::endl;
                    monsters.erase(iter);
                    
                    // because we removed something from the middle of
                    // the list, it's no longer safe to continue
                    // iteration.  Restart instead to see if other
                    // monsters died too.
                    restart = true;
                    break;
                }
            }
        } while (restart);
        
        std::cout << std::endl;
    }

    if (monsters.size() == 1) {
        // print the winner
        std::cout << "The " << monsters[0]->get_name()
                  << " wins the battle!" << std::endl;
    } else {
        std::cout << "There was no winner; mass death occurred" << std::endl;
    }
}
