/* Copyright (C) 2018, Wes Hardaker.  All rights reserved.  Use is
 * subject to GPL-3 license terms specified in the LICENSE file
 */ 

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Monster {
 protected:
   string m_name;
   int    m_hp;
   int    m_max_damage;
   bool   m_dead;

 public:
   Monster(string name, int max_hp, int max_damage) {
       // Initialize class variables
       m_name       = name;
       m_hp         = (rand()%max_hp); // % is the "mod" operator
       m_max_damage = max_damage;
       m_dead       = false;
   }

   // data accessors
   string get_name() { return m_name; };
   int    get_hp()   { return m_hp; }
   bool   is_dead()  { return m_dead; }

   virtual bool take_damage(int damage) {
       // actually apply the damage
       m_hp -= damage;

       // oh no, did I die?
       if (m_hp <= 0) {
           m_dead = true;
       }
       return m_dead;
   }

   virtual void print_attack(Monster *defender, int damage) {
       cout << "The " << m_name << " attacks the "
            << defender->get_name() << " dealing "
            << damage << " damage" << endl;
   }

   virtual bool attacks(Monster *defender) {
       // create a random damage amount
       int damage = rand() % m_max_damage + 1;

       // Apply the damage
       bool they_died = defender->take_damage(damage);

       // print what happened
       print_attack(defender, damage);
       if (they_died) {
	       cout << "   The " << m_name << " killed the "
	            << defender->get_name() << "!!!" << endl;
       } else {
	       cout << "   The " << defender->get_name() << " has "
	            << defender->get_hp() << " hit-points left"
	            << endl;
	       
       }
       return they_died;
   }

};

class Robot : public Monster {
 public:
   // A Robot is a Monster with up to 100 hp and up to 5 damage
   Robot() : Monster("Robot", 100, 5) {
   }
};

class Unicorn : public Monster {
 public:
   // A Unicorn is a Monster with up to 30 hp and up to 20 damage
   Unicorn() : Monster("Unicorn", 30, 20) {
   }

   virtual void print_attack(Monster *defender, int damage) {
       cout << "The " << m_name << " attacks the "
            << defender->get_name() << " with death-rainbows and deals "
            << damage << " pink heart damage" << endl;
   }

};

Monster *create_random_monster() {
    // Creates a random monster and returns a pointer to it.

    // The number of classes we have to create from
    int number_of_animal_types = 2;

    // returns a number from 0 to (number_of_animal_types-1)
    int random_number = rand() % number_of_animal_types;

    if (random_number == 0) {
        return new Unicorn();
    } else if (random_number == 1) {
        return new Robot();
    } else {
        cerr << "This should never happen!!!" << endl;
        exit(1);
    }
}

main() {
    srand(time(NULL));

    // Define a list of monster pointers
    vector<Monster *> monsters;
    vector<Monster*>::iterator iter;

    // Load the list with new monsters
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

            // loop through each monster in the current list
            for(iter = monsters.begin(); iter != monsters.end(); iter++) {
                Monster *monster = *iter;
            
                // If it's dead, remove it
                if (monster->is_dead()) {
                    cout << "The " << monster->get_name()
                         << " died!" << endl;
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
        
        cout << endl;
    }

    if (monsters.size() == 1) {
        // Only one monster is left!  It wins!
        cout << "The " << monsters[0]->get_name()
             << " wins the battle!" << endl;
    } else {
        // The last battle resulted in all-death
        cout << "There was no winner; mass death occurred" << endl;
    }
}
